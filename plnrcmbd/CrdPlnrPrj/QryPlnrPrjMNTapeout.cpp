/**
  * \file QryPlnrPrjMNTapeout.cpp
  * job handler for job QryPlnrPrjMNTapeout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrPrjMNTapeout.h"

// IP blksInclude --- BEGIN
#include "QryPlnrPrjMNTapeout_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrPrjMNTapeout
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrPrjMNTapeout::QryPlnrPrjMNTapeout(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRPRJMNTAPEOUT, jrefSup, ixPlnrVLocale) {
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

QryPlnrPrjMNTapeout::~QryPlnrPrjMNTapeout() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrPrjMNTapeout::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrPrjMNTapeout::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRPRJRTPOMOD_PRJEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqprjmntapeout->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMProjectMTapeout.ref)";
	sqlstr += " FROM TblPlnrRMProjectMTapeout, TblPlnrMTapeout";
	sqlstr += " WHERE TblPlnrRMProjectMTapeout.refPlnrMTapeout = TblPlnrMTapeout.ref";
	sqlstr += " AND TblPlnrRMProjectMTapeout.refPlnrMProject = " + to_string(preRefPrj) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQPrjMNTapeout(jref, jnum, mref, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMTapeout.ref, TblPlnrRMProjectMTapeout.ref";
	sqlstr += " FROM TblPlnrRMProjectMTapeout, TblPlnrMTapeout";
	sqlstr += " WHERE TblPlnrRMProjectMTapeout.refPlnrMTapeout = TblPlnrMTapeout.ref";
	sqlstr += " AND TblPlnrRMProjectMTapeout.refPlnrMProject = " + to_string(preRefPrj) + "";
	sqlstr += " ORDER BY TblPlnrMTapeout.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQPrjMNTapeout SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRPRJRTPOMOD_PRJEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefPrj, Clstn::VecVJactype::LOCK);
};

void QryPlnrPrjMNTapeout::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQPrjMNTapeout* rec = NULL;

	dbsplnr->tblplnrqprjmntapeout->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubTpoStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrPrjMNTapeout", "fetch");
	};

	refreshJnum();
};

uint QryPlnrPrjMNTapeout::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQPrjMNTapeout* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrPrjMNTapeout::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQPrjMNTapeout* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrPrjMNTapeout::handleRequest(
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

bool QryPlnrPrjMNTapeout::handleRefresh(
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

bool QryPlnrPrjMNTapeout::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQPrjMNTapeout* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
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
		cout << endl;
	};
	return retval;
};

void QryPlnrPrjMNTapeout::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRJRTPOMOD_PRJEQ) {
		call->abort = handleCallPlnrPrjRtpoMod_prjEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrPrjMNTapeout::handleCallPlnrStubChg(
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

bool QryPlnrPrjMNTapeout::handleCallPlnrPrjRtpoMod_prjEq(
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


