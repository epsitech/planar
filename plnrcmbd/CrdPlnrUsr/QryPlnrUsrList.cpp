/**
  * \file QryPlnrUsrList.cpp
  * job handler for job QryPlnrUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrUsrList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrUsrList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrUsrList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrUsrList::QryPlnrUsrList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRUSRLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrUsrList::~QryPlnrUsrList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRUSRUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrUsrList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	ubigint prePrs = xchg->getRefPreset(VecPlnrVPreset::PREPLNRUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecPlnrVPreset::PREPLNRUSRLIST_USG, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMUser.ref)";
	sqlstr += " FROM TblPlnrMUser";
	refresh_filtSQL(sqlstr, prePrs, preSrf, preUsg, true);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQUsrList(jref, jnum, ref, refPlnrMPerson, sref, refPlnrMUsergroup, ixVState, ixPlnrVLocale, ixPlnrVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMUser.ref, TblPlnrMUser.refPlnrMPerson, TblPlnrMUser.sref, TblPlnrMUser.refPlnrMUsergroup, TblPlnrMUser.ixVState, TblPlnrMUser.ixPlnrVLocale, TblPlnrMUser.ixPlnrVUserlevel";
	sqlstr += " FROM TblPlnrMUser";
	refresh_filtSQL(sqlstr, prePrs, preSrf, preUsg, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrUsrList::refresh_filtSQL(
			string& sqlstr
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrs != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMUser.refPlnrMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMUser.refPlnrMUsergroup = " + to_string(preUsg) + "";
	};
};

void QryPlnrUsrList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrUsrList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblPlnrMUser.refPlnrMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMUser.sref ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblPlnrMUser.refPlnrMUsergroup ASC";
};

void QryPlnrUsrList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQUsrList* rec = NULL;

	dbsplnr->tblplnrqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefPlnrMPerson = StubPlnr::getStubPrsStd(dbsplnr, rec->refPlnrMPerson, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefPlnrMUsergroup = StubPlnr::getStubUsgStd(dbsplnr, rec->refPlnrMUsergroup, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecPlnrVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecPlnrVMUserState::getTitle(rec->ixVState, ixPlnrVLocale);
			rec->srefIxPlnrVLocale = VecPlnrVLocale::getSref(rec->ixPlnrVLocale);
			rec->titIxPlnrVLocale = VecPlnrVLocale::getTitle(rec->ixPlnrVLocale, ixPlnrVLocale);
			rec->srefIxPlnrVUserlevel = VecPlnrVUserlevel::getSref(rec->ixPlnrVUserlevel);
			rec->titIxPlnrVUserlevel = VecPlnrVUserlevel::getTitle(rec->ixPlnrVUserlevel, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrUsrList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrUsrList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrUsrList::handleRequest(
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

bool QryPlnrUsrList::handleRefresh(
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

bool QryPlnrUsrList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefPlnrMPerson";
	cout << "\tstubRefPlnrMPerson";
	cout << "\tsref";
	cout << "\trefPlnrMUsergroup";
	cout << "\tstubRefPlnrMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixPlnrVLocale";
	cout << "\tsrefIxPlnrVLocale";
	cout << "\ttitIxPlnrVLocale";
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
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refPlnrMPerson;
		cout << "\t" << rec->stubRefPlnrMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refPlnrMUsergroup;
		cout << "\t" << rec->stubRefPlnrMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixPlnrVLocale;
		cout << "\t" << rec->srefIxPlnrVLocale;
		cout << "\t" << rec->titIxPlnrVLocale;
		cout << "\t" << rec->ixPlnrVUserlevel;
		cout << "\t" << rec->srefIxPlnrVUserlevel;
		cout << "\t" << rec->titIxPlnrVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryPlnrUsrList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRMOD) {
		call->abort = handleCallPlnrUsrMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRUPD_REFEQ) {
		call->abort = handleCallPlnrUsrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrUsrList::handleCallPlnrStubChg(
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

bool QryPlnrUsrList::handleCallPlnrUsrMod(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixPlnrVQrystate == VecPlnrVQrystate::UTD) || (ixPlnrVQrystate == VecPlnrVQrystate::SLM)) {
		ixPlnrVQrystate = VecPlnrVQrystate::MNR;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};

bool QryPlnrUsrList::handleCallPlnrUsrUpd_refEq(
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


