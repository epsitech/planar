/**
  * \file QryPlnrDsnHk1NLayer.cpp
  * job handler for job QryPlnrDsnHk1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDsnHk1NLayer.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDsnHk1NLayer_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDsnHk1NLayer
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDsnHk1NLayer::QryPlnrDsnHk1NLayer(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDSNHK1NLAYER, jrefSup, ixPlnrVLocale) {
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

QryPlnrDsnHk1NLayer::~QryPlnrDsnHk1NLayer() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDsnHk1NLayer::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDsnHk1NLayer::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	bool qmd1Avail = evalQmd1Avail();

	ubigint preRefDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref);
	ubigint preRefModdsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRLYRMOD_HKTHKUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdsnhk1nlayer->removeRstByJref(jref);

	if (qmd1Avail) {
		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMLayer.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefDsn) + "";
		sqlstr += " AND TblPlnrMLayer.x1RefPlnrMDesign = 0";
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
	};

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	if (qmd1Avail) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMLayer.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		sqlstr += " ORDER BY hkNum ASC";
		sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefDsn) + "";
		sqlstr += " AND TblPlnrMLayer.x1RefPlnrMDesign = 0";
		sqlstr += " ORDER BY hkNum ASC";
		sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQDsnHk1NLayer SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRLYRMOD_HKTHKUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMLayerHkTbl::DSN, preRefDsn, Clstn::VecVJactype::LOCK);
};

void QryPlnrDsnHk1NLayer::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQDsnHk1NLayer(jref, jnum, ref, hkNum)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMLayer.ref, TblPlnrMLayer.hkNum";
};

bool QryPlnrDsnHk1NLayer::evalQmd1Avail() {
	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

void QryPlnrDsnHk1NLayer::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDsnHk1NLayer* rec = NULL;

	dbsplnr->tblplnrqdsnhk1nlayer->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubLyrStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDsnHk1NLayer", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDsnHk1NLayer::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDsnHk1NLayer* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDsnHk1NLayer::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDsnHk1NLayer* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDsnHk1NLayer::handleRequest(
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

bool QryPlnrDsnHk1NLayer::handleRefresh(
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

bool QryPlnrDsnHk1NLayer::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDsnHk1NLayer* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << "\thkNum";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << "\t" << rec->hkNum;
		cout << endl;
	};
	return retval;
};

void QryPlnrDsnHk1NLayer::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRMOD_HKTHKUEQ) {
		call->abort = handleCallPlnrLyrMod_hktHkuEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryPlnrDsnHk1NLayer::handleCallPlnrStubChg(
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

bool QryPlnrDsnHk1NLayer::handleCallPlnrLyrMod_hktHkuEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixPlnrVQrystate != VecPlnrVQrystate::OOD) {
		ixPlnrVQrystate = VecPlnrVQrystate::OOD;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};


