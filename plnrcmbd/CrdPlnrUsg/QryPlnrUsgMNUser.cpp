/**
  * \file QryPlnrUsgMNUser.cpp
  * job handler for job QryPlnrUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrUsgMNUser.h"

// IP blksInclude --- BEGIN
#include "QryPlnrUsgMNUser_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrUsgMNUser
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrUsgMNUser::QryPlnrUsgMNUser(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRUSGMNUSER, jrefSup, ixPlnrVLocale) {
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

QryPlnrUsgMNUser::~QryPlnrUsgMNUser() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrUsgMNUser::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSG, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRUSRRUSGMOD_USGEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqusgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMUserMUsergroup.ref)";
	sqlstr += " FROM TblPlnrRMUserMUsergroup, TblPlnrMUser";
	sqlstr += " WHERE TblPlnrRMUserMUsergroup.refPlnrMUser = TblPlnrMUser.ref";
	sqlstr += " AND TblPlnrRMUserMUsergroup.refPlnrMUsergroup = " + to_string(preRefUsg) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQUsgMNUser(jref, jnum, mref, ref, ixPlnrVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMUser.ref, TblPlnrRMUserMUsergroup.ref, TblPlnrRMUserMUsergroup.ixPlnrVUserlevel";
	sqlstr += " FROM TblPlnrRMUserMUsergroup, TblPlnrMUser";
	sqlstr += " WHERE TblPlnrRMUserMUsergroup.refPlnrMUser = TblPlnrMUser.ref";
	sqlstr += " AND TblPlnrRMUserMUsergroup.refPlnrMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblPlnrMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryPlnrUsgMNUser::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQUsgMNUser* rec = NULL;

	dbsplnr->tblplnrqusgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubUsrStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxPlnrVUserlevel = VecPlnrVUserlevel::getSref(rec->ixPlnrVUserlevel);
			rec->titIxPlnrVUserlevel = VecPlnrVUserlevel::getTitle(rec->ixPlnrVUserlevel, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryPlnrUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrUsgMNUser::handleRequest(
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

bool QryPlnrUsgMNUser::handleRefresh(
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

bool QryPlnrUsgMNUser::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixPlnrVUserlevel";
	cout << "\tsrefIxPlnrVUserlevel";
	cout << "\ttitIxPlnrVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixPlnrVUserlevel;
		cout << "\t" << rec->srefIxPlnrVUserlevel;
		cout << "\t" << rec->titIxPlnrVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryPlnrUsgMNUser::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRRUSGMOD_USGEQ) {
		call->abort = handleCallPlnrUsrRusgMod_usgEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrUsgMNUser::handleCallPlnrStubChg(
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

bool QryPlnrUsgMNUser::handleCallPlnrUsrRusgMod_usgEq(
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


