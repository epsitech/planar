/**
  * \file QryPlnrClcMNDomain.cpp
  * job handler for job QryPlnrClcMNDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrClcMNDomain.h"

// IP blksInclude --- BEGIN
#include "QryPlnrClcMNDomain_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrClcMNDomain
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrClcMNDomain::QryPlnrClcMNDomain(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLCMNDOMAIN, jrefSup, ixPlnrVLocale) {
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

QryPlnrClcMNDomain::~QryPlnrClcMNDomain() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrClcMNDomain::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrClcMNDomain::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefClc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALRDOMMOD_CALEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqclcmndomain->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMCalcMDomain.ref)";
	sqlstr += " FROM TblPlnrRMCalcMDomain, TblPlnrMDomain";
	sqlstr += " WHERE TblPlnrRMCalcMDomain.refPlnrMDomain = TblPlnrMDomain.ref";
	sqlstr += " AND TblPlnrRMCalcMDomain.refPlnrMCalc = " + to_string(preRefClc) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQClcMNDomain(jref, jnum, mref, ref, srefPlnrKCalcdomprp)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDomain.ref, TblPlnrRMCalcMDomain.ref, TblPlnrRMCalcMDomain.srefPlnrKCalcdomprp";
	sqlstr += " FROM TblPlnrRMCalcMDomain, TblPlnrMDomain";
	sqlstr += " WHERE TblPlnrRMCalcMDomain.refPlnrMDomain = TblPlnrMDomain.ref";
	sqlstr += " AND TblPlnrRMCalcMDomain.refPlnrMCalc = " + to_string(preRefClc) + "";
	sqlstr += " ORDER BY TblPlnrMDomain.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQClcMNDomain SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALRDOMMOD_CALEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefClc, Clstn::VecVJactype::LOCK);
};

void QryPlnrClcMNDomain::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQClcMNDomain* rec = NULL;

	dbsplnr->tblplnrqclcmndomain->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubDomStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefPlnrKCalcdomprp = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKCALCDOMPRP, rec->srefPlnrKCalcdomprp, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrClcMNDomain", "fetch");
	};

	refreshJnum();
};

uint QryPlnrClcMNDomain::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQClcMNDomain* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrClcMNDomain::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQClcMNDomain* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrClcMNDomain::handleRequest(
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

bool QryPlnrClcMNDomain::handleRefresh(
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

bool QryPlnrClcMNDomain::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQClcMNDomain* rec = NULL;

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

void QryPlnrClcMNDomain::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALRDOMMOD_CALEQ) {
		call->abort = handleCallPlnrCalRdomMod_calEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrClcMNDomain::handleCallPlnrStubChg(
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

bool QryPlnrClcMNDomain::handleCallPlnrCalRdomMod_calEq(
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


