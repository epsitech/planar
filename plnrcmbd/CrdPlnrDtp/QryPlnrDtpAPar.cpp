/**
  * \file QryPlnrDtpAPar.cpp
  * job handler for job QryPlnrDtpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDtpAPar.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDtpAPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDtpAPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDtpAPar::QryPlnrDtpAPar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDTPAPAR, jrefSup, ixPlnrVLocale) {
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

QryPlnrDtpAPar::~QryPlnrDtpAPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDtpAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDtpAPar::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefDtp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref);
	ubigint preX1 = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDTPAPAR_X1, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRDTPAPAR_X2, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdtpapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMDevicePar.ref)";
	sqlstr += " FROM TblPlnrAMDevicePar";
	sqlstr += " WHERE TblPlnrAMDevicePar.refPlnrMDevice = " + to_string(preRefDtp) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQDtpAPar(jref, jnum, ref, x2SrefKKey, refPlnrMFile, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMDevicePar.ref, TblPlnrAMDevicePar.x2SrefKKey, TblPlnrAMDevicePar.refPlnrMFile, TblPlnrAMDevicePar.Val";
	sqlstr += " FROM TblPlnrAMDevicePar";
	sqlstr += " WHERE TblPlnrAMDevicePar.refPlnrMDevice = " + to_string(preRefDtp) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDtpAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefDtp, Clstn::VecVJactype::LOCK);
};

void QryPlnrDtpAPar::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMDevicePar.x1RefPlnrMDesign = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMDevicePar.x2SrefKKey = '" + preX2 + "'";
	};
};

void QryPlnrDtpAPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDtpAPar::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDtpAPar* rec = NULL;

	dbsplnr->tblplnrqdtpapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX2SrefKKey = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMDEVICEPARKEY, rec->x2SrefKKey, ixPlnrVLocale);
			rec->stubRefPlnrMFile = StubPlnr::getStubFilStd(dbsplnr, rec->refPlnrMFile, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDtpAPar", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDtpAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDtpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDtpAPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDtpAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDtpAPar::handleRequest(
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

bool QryPlnrDtpAPar::handleRefresh(
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

bool QryPlnrDtpAPar::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDtpAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx2SrefKKey";
	cout << "\ttitX2SrefKKey";
	cout << "\trefPlnrMFile";
	cout << "\tstubRefPlnrMFile";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x2SrefKKey;
		cout << "\t" << rec->titX2SrefKKey;
		cout << "\t" << rec->refPlnrMFile;
		cout << "\t" << rec->stubRefPlnrMFile;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrDtpAPar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ) {
		call->abort = handleCallPlnrDevAparMod_devEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDtpAPar::handleCallPlnrStubChg(
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

bool QryPlnrDtpAPar::handleCallPlnrDevAparMod_devEq(
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


