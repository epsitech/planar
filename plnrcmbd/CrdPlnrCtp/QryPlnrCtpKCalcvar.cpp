/**
  * \file QryPlnrCtpKCalcvar.cpp
  * job handler for job QryPlnrCtpKCalcvar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCtpKCalcvar.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCtpKCalcvar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCtpKCalcvar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCtpKCalcvar::QryPlnrCtpKCalcvar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCTPKCALCVAR, jrefSup, ixPlnrVLocale) {
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

QryPlnrCtpKCalcvar::~QryPlnrCtpKCalcvar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCtpKCalcvar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrCtpKCalcvar::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefCtp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCTP, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqctpkcalcvar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAVKeylistKey.ref)";
	sqlstr += " FROM TblPlnrAVKeylistKey";
	sqlstr += " WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKCALCVAR);
	sqlstr += " AND x1IxPlnrVMaintable = " + to_string(VecPlnrVMaintable::TBLPLNRMCALC);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQCtpKCalcvar(jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAVKeylistKey.ref, TblPlnrAVKeylistKey.klsNum, TblPlnrAVKeylistKey.Fixed, TblPlnrAVKeylistKey.sref, TblPlnrAVKeylistKey.Avail, TblPlnrAVKeylistKey.Implied, TblPlnrAVKeylistKey.refJ, TblPlnrAVKeylistKey.Title, TblPlnrAVKeylistKey.Comment";
	sqlstr += " FROM TblPlnrAVKeylistKey";
	sqlstr += " WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKCALCVAR);
	sqlstr += " AND x1IxPlnrVMaintable = " + to_string(VecPlnrVMaintable::TBLPLNRMCALC);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	sqlstr += " ORDER BY TblPlnrAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQCtpKCalcvar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefSrefClstn(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMaintable::TBLPLNRMCALC, preRefCtp, VecPlnrVKeylist::getSref(VecPlnrVKeylist::KLSTPLNRKCALCVAR), Clstn::VecVJactype::LOCK);
};

void QryPlnrCtpKCalcvar::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCtpKCalcvar* rec = NULL;

	dbsplnr->tblplnrqctpkcalcvar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			if (rec->Fixed) rec->yesnoFixed = VecPlnrVTag::getTitle(VecPlnrVTag::YES, ixPlnrVLocale); else rec->yesnoFixed = VecPlnrVTag::getTitle(VecPlnrVTag::NO, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCtpKCalcvar", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCtpKCalcvar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCtpKCalcvar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCtpKCalcvar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCtpKCalcvar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCtpKCalcvar::handleRequest(
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

bool QryPlnrCtpKCalcvar::handleRefresh(
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

bool QryPlnrCtpKCalcvar::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCtpKCalcvar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tklsNum";
	cout << "\tFixed";
	cout << "\tyesnoFixed";
	cout << "\tsref";
	cout << "\tAvail";
	cout << "\tImplied";
	cout << "\trefJ";
	cout << "\tTitle";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->klsNum;
		cout << "\t" << rec->Fixed;
		cout << "\t" << rec->yesnoFixed;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Avail;
		cout << "\t" << rec->Implied;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryPlnrCtpKCalcvar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallPlnrKlsAkeyMod_klsMtbUrfEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool QryPlnrCtpKCalcvar::handleCallPlnrStubChg(
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

bool QryPlnrCtpKCalcvar::handleCallPlnrKlsAkeyMod_klsMtbUrfEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;

	if (ixPlnrVQrystate != VecPlnrVQrystate::OOD) {
		ixPlnrVQrystate = VecPlnrVQrystate::OOD;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};


