/**
  * \file QryPlnrDvcAPar.cpp
  * job handler for job QryPlnrDvcAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDvcAPar.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDvcAPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDvcAPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDvcAPar::QryPlnrDvcAPar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDVCAPAR, jrefSup, ixPlnrVLocale) {
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

QryPlnrDvcAPar::~QryPlnrDvcAPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDvcAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDvcAPar::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefDvc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref);
	ubigint preX1 = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDVCAPAR_X1, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRDVCAPAR_X2, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdvcapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMDevicePar.ref)";
	sqlstr += " FROM TblPlnrAMDevicePar";
	sqlstr += " WHERE TblPlnrAMDevicePar.refPlnrMDevice = " + to_string(preRefDvc) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQDvcAPar(jref, jnum, ref, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMDevicePar.ref, TblPlnrAMDevicePar.x1RefPlnrMDesign, TblPlnrAMDevicePar.x2SrefKKey, TblPlnrAMDevicePar.refPlnrMFile, TblPlnrAMDevicePar.Val";
	sqlstr += " FROM TblPlnrAMDevicePar";
	sqlstr += " WHERE TblPlnrAMDevicePar.refPlnrMDevice = " + to_string(preRefDvc) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDvcAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefDvc, Clstn::VecVJactype::LOCK);
};

void QryPlnrDvcAPar::refresh_filtSQL(
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

void QryPlnrDvcAPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDvcAPar::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDvcAPar* rec = NULL;

	dbsplnr->tblplnrqdvcapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->x1RefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titX2SrefKKey = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMDEVICEPARKEY, rec->x2SrefKKey, ixPlnrVLocale);
			rec->stubRefPlnrMFile = StubPlnr::getStubFilStd(dbsplnr, rec->refPlnrMFile, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDvcAPar", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDvcAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDvcAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDvcAPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDvcAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDvcAPar::handleRequest(
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

bool QryPlnrDvcAPar::handleRefresh(
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

bool QryPlnrDvcAPar::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDvcAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefPlnrMDesign";
	cout << "\tstubX1RefPlnrMDesign";
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
		cout << "\t" << rec->x1RefPlnrMDesign;
		cout << "\t" << rec->stubX1RefPlnrMDesign;
		cout << "\t" << rec->x2SrefKKey;
		cout << "\t" << rec->titX2SrefKKey;
		cout << "\t" << rec->refPlnrMFile;
		cout << "\t" << rec->stubRefPlnrMFile;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrDvcAPar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVAPARMOD_DEVEQ) {
		call->abort = handleCallPlnrDevAparMod_devEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDvcAPar::handleCallPlnrStubChg(
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

bool QryPlnrDvcAPar::handleCallPlnrDevAparMod_devEq(
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


