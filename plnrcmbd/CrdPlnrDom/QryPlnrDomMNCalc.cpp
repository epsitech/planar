/**
  * \file QryPlnrDomMNCalc.cpp
  * job handler for job QryPlnrDomMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDomMNCalc.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDomMNCalc_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDomMNCalc
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDomMNCalc::QryPlnrDomMNCalc(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDOMMNCALC, jrefSup, ixPlnrVLocale) {
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

QryPlnrDomMNCalc::~QryPlnrDomMNCalc() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDomMNCalc::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDomMNCalc::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefDom = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDOM, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALRDOMMOD_DOMEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdommncalc->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMCalcMDomain.ref)";
	sqlstr += " FROM TblPlnrRMCalcMDomain, TblPlnrMCalc";
	sqlstr += " WHERE TblPlnrRMCalcMDomain.refPlnrMCalc = TblPlnrMCalc.ref";
	sqlstr += " AND TblPlnrRMCalcMDomain.refPlnrMDomain = " + to_string(preRefDom) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQDomMNCalc(jref, jnum, mref, ref, srefPlnrKCalcdomprp)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMCalc.ref, TblPlnrRMCalcMDomain.ref, TblPlnrRMCalcMDomain.srefPlnrKCalcdomprp";
	sqlstr += " FROM TblPlnrRMCalcMDomain, TblPlnrMCalc";
	sqlstr += " WHERE TblPlnrRMCalcMDomain.refPlnrMCalc = TblPlnrMCalc.ref";
	sqlstr += " AND TblPlnrRMCalcMDomain.refPlnrMDomain = " + to_string(preRefDom) + "";
	sqlstr += " ORDER BY TblPlnrMCalc.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDomMNCalc SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALRDOMMOD_DOMEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefDom, Clstn::VecVJactype::LOCK);
};

void QryPlnrDomMNCalc::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDomMNCalc* rec = NULL;

	dbsplnr->tblplnrqdommncalc->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubCalStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefPlnrKCalcdomprp = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKCALCDOMPRP, rec->srefPlnrKCalcdomprp, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDomMNCalc", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDomMNCalc::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDomMNCalc* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDomMNCalc::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDomMNCalc* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDomMNCalc::handleRequest(
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

bool QryPlnrDomMNCalc::handleRefresh(
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

bool QryPlnrDomMNCalc::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDomMNCalc* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tsrefPlnrKCalcdomprp";
	cout << "\ttitSrefPlnrKCalcdomprp";
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
		cout << "\t" << rec->srefPlnrKCalcdomprp;
		cout << "\t" << rec->titSrefPlnrKCalcdomprp;
		cout << endl;
	};
	return retval;
};

void QryPlnrDomMNCalc::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALRDOMMOD_DOMEQ) {
		call->abort = handleCallPlnrCalRdomMod_domEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDomMNCalc::handleCallPlnrStubChg(
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

bool QryPlnrDomMNCalc::handleCallPlnrCalRdomMod_domEq(
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


