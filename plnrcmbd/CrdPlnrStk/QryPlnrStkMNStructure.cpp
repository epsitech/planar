/**
  * \file QryPlnrStkMNStructure.cpp
  * job handler for job QryPlnrStkMNStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrStkMNStructure.h"

// IP blksInclude --- BEGIN
#include "QryPlnrStkMNStructure_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrStkMNStructure
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrStkMNStructure::QryPlnrStkMNStructure(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRSTKMNSTRUCTURE, jrefSup, ixPlnrVLocale) {
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

QryPlnrStkMNStructure::~QryPlnrStkMNStructure() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrStkMNStructure::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrStkMNStructure::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefStk = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRSTKRSRUMOD_STKEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqstkmnstructure->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMStackMStructure.ref)";
	sqlstr += " FROM TblPlnrRMStackMStructure, TblPlnrMStructure";
	sqlstr += " WHERE TblPlnrRMStackMStructure.refPlnrMStructure = TblPlnrMStructure.ref";
	sqlstr += " AND TblPlnrRMStackMStructure.refPlnrMStack = " + to_string(preRefStk) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQStkMNStructure(jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMStructure.ref, TblPlnrRMStackMStructure.ref, TblPlnrRMStackMStructure.fromSrefPlnrMLayer, TblPlnrRMStackMStructure.toSrefPlnrMLayer";
	sqlstr += " FROM TblPlnrRMStackMStructure, TblPlnrMStructure";
	sqlstr += " WHERE TblPlnrRMStackMStructure.refPlnrMStructure = TblPlnrMStructure.ref";
	sqlstr += " AND TblPlnrRMStackMStructure.refPlnrMStack = " + to_string(preRefStk) + "";
	sqlstr += " ORDER BY TblPlnrMStructure.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQStkMNStructure SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRSTKRSRUMOD_STKEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefStk, Clstn::VecVJactype::LOCK);
};

void QryPlnrStkMNStructure::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQStkMNStructure* rec = NULL;

	dbsplnr->tblplnrqstkmnstructure->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubSruStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrStkMNStructure", "fetch");
	};

	refreshJnum();
};

uint QryPlnrStkMNStructure::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQStkMNStructure* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrStkMNStructure::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQStkMNStructure* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrStkMNStructure::handleRequest(
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

bool QryPlnrStkMNStructure::handleRefresh(
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

bool QryPlnrStkMNStructure::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQStkMNStructure* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tfromSrefPlnrMLayer";
	cout << "\ttoSrefPlnrMLayer";
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
		cout << "\t" << rec->fromSrefPlnrMLayer;
		cout << "\t" << rec->toSrefPlnrMLayer;
		cout << endl;
	};
	return retval;
};

void QryPlnrStkMNStructure::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKRSRUMOD_STKEQ) {
		call->abort = handleCallPlnrStkRsruMod_stkEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrStkMNStructure::handleCallPlnrStubChg(
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

bool QryPlnrStkMNStructure::handleCallPlnrStkRsruMod_stkEq(
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


