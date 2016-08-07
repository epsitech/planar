/**
  * \file QryPlnrSruMNStack.cpp
  * job handler for job QryPlnrSruMNStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrSruMNStack.h"

// IP blksInclude --- BEGIN
#include "QryPlnrSruMNStack_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrSruMNStack
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrSruMNStack::QryPlnrSruMNStack(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRSRUMNSTACK, jrefSup, ixPlnrVLocale) {
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

QryPlnrSruMNStack::~QryPlnrSruMNStack() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrSruMNStack::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrSruMNStack::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefSru = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSRU, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRSTKRSRUMOD_SRUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqsrumnstack->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMStackMStructure.ref)";
	sqlstr += " FROM TblPlnrRMStackMStructure, TblPlnrMStack";
	sqlstr += " WHERE TblPlnrRMStackMStructure.refPlnrMStack = TblPlnrMStack.ref";
	sqlstr += " AND TblPlnrRMStackMStructure.refPlnrMStructure = " + to_string(preRefSru) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQSruMNStack(jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMStack.ref, TblPlnrRMStackMStructure.ref, TblPlnrRMStackMStructure.fromSrefPlnrMLayer, TblPlnrRMStackMStructure.toSrefPlnrMLayer";
	sqlstr += " FROM TblPlnrRMStackMStructure, TblPlnrMStack";
	sqlstr += " WHERE TblPlnrRMStackMStructure.refPlnrMStack = TblPlnrMStack.ref";
	sqlstr += " AND TblPlnrRMStackMStructure.refPlnrMStructure = " + to_string(preRefSru) + "";
	sqlstr += " ORDER BY TblPlnrMStack.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQSruMNStack SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRSTKRSRUMOD_SRUEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSru, Clstn::VecVJactype::LOCK);
};

void QryPlnrSruMNStack::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQSruMNStack* rec = NULL;

	dbsplnr->tblplnrqsrumnstack->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubStkStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrSruMNStack", "fetch");
	};

	refreshJnum();
};

uint QryPlnrSruMNStack::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQSruMNStack* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrSruMNStack::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQSruMNStack* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrSruMNStack::handleRequest(
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

bool QryPlnrSruMNStack::handleRefresh(
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

bool QryPlnrSruMNStack::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQSruMNStack* rec = NULL;

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

void QryPlnrSruMNStack::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKRSRUMOD_SRUEQ) {
		call->abort = handleCallPlnrStkRsruMod_sruEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrSruMNStack::handleCallPlnrStubChg(
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

bool QryPlnrSruMNStack::handleCallPlnrStkRsruMod_sruEq(
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


