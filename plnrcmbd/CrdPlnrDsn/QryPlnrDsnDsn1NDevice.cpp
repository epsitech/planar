/**
  * \file QryPlnrDsnDsn1NDevice.cpp
  * job handler for job QryPlnrDsnDsn1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDsnDsn1NDevice.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDsnDsn1NDevice_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDsnDsn1NDevice
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDsnDsn1NDevice::QryPlnrDsnDsn1NDevice(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDSNDSN1NDEVICE, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixPlnrVQrystate = VecPlnrVQrystate::OOD;

// IP constructor.cust2 --- INSERT

	refresh(dbsplnr);

	xchg->addClstn(VecPlnrVCall::CALLPLNRSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrDsnDsn1NDevice::~QryPlnrDsnDsn1NDevice() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDsnDsn1NDevice::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDsnDsn1NDevice::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDEVMOD_DSNEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdsndsn1ndevice->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMDevice.ref)";
	sqlstr += " FROM TblPlnrMDevice";
	sqlstr += " WHERE TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQDsnDsn1NDevice(jref, jnum, ref, dsnNum)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDevice.ref, TblPlnrMDevice.dsnNum";
	sqlstr += " FROM TblPlnrMDevice";
	sqlstr += " WHERE TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
	sqlstr += " ORDER BY dsnNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDsnDsn1NDevice SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRDEVMOD_DSNEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefDsn, Clstn::VecVJactype::LOCK);
};

void QryPlnrDsnDsn1NDevice::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDsnDsn1NDevice* rec = NULL;

	dbsplnr->tblplnrqdsndsn1ndevice->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubDevStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDsnDsn1NDevice", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDsnDsn1NDevice::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDsnDsn1NDevice* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDsnDsn1NDevice::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDsnDsn1NDevice* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDsnDsn1NDevice::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\trefresh" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd.compare("refresh") == 0) {
			req->retain = handleRefresh(dbsplnr);

		} else if (req->cmd.compare("show") == 0) {
			req->retain = handleShow(dbsplnr);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
	};
};

bool QryPlnrDsnDsn1NDevice::handleRefresh(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	refresh(dbsplnr);
	return retval;
};

bool QryPlnrDsnDsn1NDevice::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDsnDsn1NDevice* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << "\tdsnNum";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << "\t" << rec->dsnNum;
		cout << endl;
	};
	return retval;
};

void QryPlnrDsnDsn1NDevice::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVMOD_DSNEQ) {
		call->abort = handleCallPlnrDevMod_dsnEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDsnDsn1NDevice::handleCallPlnrStubChg(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixPlnrVQrystate == VecPlnrVQrystate::UTD) {
		ixPlnrVQrystate = VecPlnrVQrystate::SLM;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};

bool QryPlnrDsnDsn1NDevice::handleCallPlnrDevMod_dsnEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixPlnrVQrystate != VecPlnrVQrystate::OOD) {
		ixPlnrVQrystate = VecPlnrVQrystate::OOD;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};


