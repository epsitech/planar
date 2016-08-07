/**
  * \file QryPlnrArrAEnv.cpp
  * job handler for job QryPlnrArrAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrArrAEnv.h"

// IP blksInclude --- BEGIN
#include "QryPlnrArrAEnv_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrArrAEnv
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrArrAEnv::QryPlnrArrAEnv(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRARRAENV, jrefSup, ixPlnrVLocale) {
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

QryPlnrArrAEnv::~QryPlnrArrAEnv() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrArrAEnv::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrArrAEnv::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefArr = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARR, jref);
	ubigint preX1 = xchg->getRefPreset(VecPlnrVPreset::PREPLNRARRAENV_X1, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRARRAENV_X2, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRARRAENVMOD_ARREQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqarraenv->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMArrayEnv.ref)";
	sqlstr += " FROM TblPlnrAMArrayEnv";
	sqlstr += " WHERE TblPlnrAMArrayEnv.refPlnrMArray = " + to_string(preRefArr) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQArrAEnv(jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMArrayEnv.ref, TblPlnrAMArrayEnv.x1RefPlnrMArrayitem, TblPlnrAMArrayEnv.x2SrefKKey, TblPlnrAMArrayEnv.Val";
	sqlstr += " FROM TblPlnrAMArrayEnv";
	sqlstr += " WHERE TblPlnrAMArrayEnv.refPlnrMArray = " + to_string(preRefArr) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQArrAEnv SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRARRAENVMOD_ARREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefArr, Clstn::VecVJactype::LOCK);
};

void QryPlnrArrAEnv::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMArrayEnv.x1RefPlnrMArrayitem = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMArrayEnv.x2SrefKKey = '" + preX2 + "'";
	};
};

void QryPlnrArrAEnv::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrArrAEnv::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQArrAEnv* rec = NULL;

	dbsplnr->tblplnrqarraenv->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX2SrefKKey = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMARRAYENVKEY, rec->x2SrefKKey, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrArrAEnv", "fetch");
	};

	refreshJnum();
};

uint QryPlnrArrAEnv::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQArrAEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrArrAEnv::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQArrAEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrArrAEnv::handleRequest(
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

bool QryPlnrArrAEnv::handleRefresh(
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

bool QryPlnrArrAEnv::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQArrAEnv* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefPlnrMArrayitem";
	cout << "\tx2SrefKKey";
	cout << "\ttitX2SrefKKey";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefPlnrMArrayitem;
		cout << "\t" << rec->x2SrefKKey;
		cout << "\t" << rec->titX2SrefKKey;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrArrAEnv::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRARRAENVMOD_ARREQ) {
		call->abort = handleCallPlnrArrAenvMod_arrEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrArrAEnv::handleCallPlnrStubChg(
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

bool QryPlnrArrAEnv::handleCallPlnrArrAenvMod_arrEq(
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


