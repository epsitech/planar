/**
  * \file QryPlnrCtpList.cpp
  * job handler for job QryPlnrCtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCtpList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCtpList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCtpList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCtpList::QryPlnrCtpList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCTPLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRCALMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrCtpList::~QryPlnrCtpList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCtpList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrCtpList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	string preTit = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRCTPLIST_TIT, jref);
	ubigint prePrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCTPLIST_PRJ, jref);
	uint preDim = xchg->getIxPreset(VecPlnrVPreset::PREPLNRCTPLIST_DIM, jref);
	ubigint preTpl = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCTPLIST_TPL, jref);
	ubigint preSup = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCTPLIST_SUP, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCTPLIST_DSN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqctplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMCalc.ref)";
	sqlstr += " FROM TblPlnrMCalc";
	sqlstr += " WHERE tplRefPlnrMCalc = 0";
	refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQCtpList(jref, jnum, ref, Title, ixVDim, supRefPlnrMCalc)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMCalc.ref, TblPlnrMCalc.Title, TblPlnrMCalc.ixVDim, TblPlnrMCalc.supRefPlnrMCalc";
	sqlstr += " FROM TblPlnrMCalc";
	sqlstr += " WHERE tplRefPlnrMCalc = 0";
	refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQCtpList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrCtpList::refresh_filtSQL(
			string& sqlstr
			, const string& preTit
			, const ubigint prePrj
			, const uint preDim
			, const ubigint preTpl
			, const ubigint preSup
			, const ubigint preDsn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.Title LIKE '" + preTit + "'";
	};

	if (prePrj != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.refPlnrMProject = " + to_string(prePrj) + "";
	};

	if (preDim != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.ixVDim = " + to_string(preDim) + "";
	};

	if (preTpl != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.tplRefPlnrMCalc = " + to_string(preTpl) + "";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.supRefPlnrMCalc = " + to_string(preSup) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.refPlnrMDesign = " + to_string(preDsn) + "";
	};
};

void QryPlnrCtpList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrCtpList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblPlnrMCalc.Title ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblPlnrMCalc.refPlnrMProject ASC";
	else if (preIxOrd == VecVOrd::DIM) sqlstr += " ORDER BY TblPlnrMCalc.ixVDim ASC";
	else if (preIxOrd == VecVOrd::TPL) sqlstr += " ORDER BY TblPlnrMCalc.tplRefPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblPlnrMCalc.supRefPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMCalc.refPlnrMDesign ASC";
};

void QryPlnrCtpList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCtpList* rec = NULL;

	dbsplnr->tblplnrqctplist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVDim = VecPlnrVMCalcDim::getSref(rec->ixVDim);
			rec->titIxVDim = VecPlnrVMCalcDim::getTitle(rec->ixVDim, ixPlnrVLocale);
			rec->stubSupRefPlnrMCalc = StubPlnr::getStubCalStd(dbsplnr, rec->supRefPlnrMCalc, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCtpList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCtpList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCtpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCtpList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCtpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCtpList::handleRequest(
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

bool QryPlnrCtpList::handleRefresh(
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

bool QryPlnrCtpList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCtpList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tixVDim";
	cout << "\tsrefIxVDim";
	cout << "\ttitIxVDim";
	cout << "\tsupRefPlnrMCalc";
	cout << "\tstubSupRefPlnrMCalc";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixVDim;
		cout << "\t" << rec->srefIxVDim;
		cout << "\t" << rec->titIxVDim;
		cout << "\t" << rec->supRefPlnrMCalc;
		cout << "\t" << rec->stubSupRefPlnrMCalc;
		cout << endl;
	};
	return retval;
};

void QryPlnrCtpList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALMOD) {
		call->abort = handleCallPlnrCalMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALUPD_REFEQ) {
		call->abort = handleCallPlnrCalUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrCtpList::handleCallPlnrStubChg(
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

bool QryPlnrCtpList::handleCallPlnrCalMod(
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

bool QryPlnrCtpList::handleCallPlnrCalUpd_refEq(
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


