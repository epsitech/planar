/**
  * \file QryPlnrMatList.cpp
  * job handler for job QryPlnrMatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrMatList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrMatList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrMatList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrMatList::QryPlnrMatList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRMATLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRMATMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrMatList::~QryPlnrMatList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrMatList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRMATUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRMATUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrMatList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRMATLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRMATLIST_TIT, jref);
	uint preTyp = xchg->getIxPreset(VecPlnrVPreset::PREPLNRMATLIST_TYP, jref);
	ubigint preCal = xchg->getRefPreset(VecPlnrVPreset::PREPLNRMATLIST_CAL, jref);
	ubigint preSup = xchg->getRefPreset(VecPlnrVPreset::PREPLNRMATLIST_SUP, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqmatlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMMaterial.ref)";
	sqlstr += " FROM TblPlnrMMaterial";
	refresh_filtSQL(sqlstr, preSrf, preTit, preTyp, preCal, preSup, true);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQMatList(jref, jnum, ref, sref, Title, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMMaterial.ref, TblPlnrMMaterial.sref, TblPlnrMMaterial.Title, TblPlnrMMaterial.ixVBasetype, TblPlnrMMaterial.refPlnrMCalc, TblPlnrMMaterial.modRefPlnrMMaterial";
	sqlstr += " FROM TblPlnrMMaterial";
	refresh_filtSQL(sqlstr, preSrf, preTit, preTyp, preCal, preSup, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQMatList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrMatList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const uint preTyp
			, const ubigint preCal
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMMaterial.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMMaterial.Title LIKE '" + preTit + "'";
	};

	if (preTyp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMMaterial.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preCal != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMMaterial.refPlnrMCalc = " + to_string(preCal) + "";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMMaterial.modRefPlnrMMaterial = " + to_string(preSup) + "";
	};
};

void QryPlnrMatList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrMatList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMMaterial.sref ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblPlnrMMaterial.Title ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblPlnrMMaterial.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::CAL) sqlstr += " ORDER BY TblPlnrMMaterial.refPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblPlnrMMaterial.modRefPlnrMMaterial ASC";
};

void QryPlnrMatList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQMatList* rec = NULL;

	dbsplnr->tblplnrqmatlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecPlnrVMMaterialBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecPlnrVMMaterialBasetype::getTitle(rec->ixVBasetype, ixPlnrVLocale);
			rec->stubRefPlnrMCalc = StubPlnr::getStubCalStd(dbsplnr, rec->refPlnrMCalc, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubModRefPlnrMMaterial = StubPlnr::getStubMatStd(dbsplnr, rec->modRefPlnrMMaterial, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrMatList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrMatList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQMatList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrMatList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQMatList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrMatList::handleRequest(
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

bool QryPlnrMatList::handleRefresh(
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

bool QryPlnrMatList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQMatList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefPlnrMCalc";
	cout << "\tstubRefPlnrMCalc";
	cout << "\tmodRefPlnrMMaterial";
	cout << "\tstubModRefPlnrMMaterial";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refPlnrMCalc;
		cout << "\t" << rec->stubRefPlnrMCalc;
		cout << "\t" << rec->modRefPlnrMMaterial;
		cout << "\t" << rec->stubModRefPlnrMMaterial;
		cout << endl;
	};
	return retval;
};

void QryPlnrMatList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRMATMOD) {
		call->abort = handleCallPlnrMatMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRMATUPD_REFEQ) {
		call->abort = handleCallPlnrMatUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrMatList::handleCallPlnrStubChg(
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

bool QryPlnrMatList::handleCallPlnrMatMod(
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

bool QryPlnrMatList::handleCallPlnrMatUpd_refEq(
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


