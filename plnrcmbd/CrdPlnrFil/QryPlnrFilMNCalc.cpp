/**
  * \file QryPlnrFilMNCalc.cpp
  * job handler for job QryPlnrFilMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrFilMNCalc.h"

// IP blksInclude --- BEGIN
#include "QryPlnrFilMNCalc_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrFilMNCalc
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrFilMNCalc::QryPlnrFilMNCalc(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRFILMNCALC, jrefSup, ixPlnrVLocale) {
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

QryPlnrFilMNCalc::~QryPlnrFilMNCalc() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrFilMNCalc::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrFilMNCalc::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefFil = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFFIL, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALRFILMOD_FILEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqfilmncalc->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrRMCalcMFile.ref)";
	sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMCalc";
	sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMCalc = TblPlnrMCalc.ref";
	sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMFile = " + to_string(preRefFil) + "";
	sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = 0";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQFilMNCalc(jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMCalc.ref, TblPlnrRMCalcMFile.ref, TblPlnrRMCalcMFile.x1RefPlnrMCalcitem, TblPlnrRMCalcMFile.ixVIo";
	sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMCalc";
	sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMCalc = TblPlnrMCalc.ref";
	sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMFile = " + to_string(preRefFil) + "";
	sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = 0";
	sqlstr += " ORDER BY TblPlnrMCalc.Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQFilMNCalc SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALRFILMOD_FILEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefFil, Clstn::VecVJactype::LOCK);
};

void QryPlnrFilMNCalc::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQFilMNCalc* rec = NULL;

	dbsplnr->tblplnrqfilmncalc->loadRstByJref(jref, false, rst);
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
			rec->stubX1RefPlnrMCalcitem = StubPlnr::getStubCliStd(dbsplnr, rec->x1RefPlnrMCalcitem, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVIo = VecPlnrVRMCalcMFileIo::getSref(rec->ixVIo);
			rec->titIxVIo = VecPlnrVRMCalcMFileIo::getTitle(rec->ixVIo, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrFilMNCalc", "fetch");
	};

	refreshJnum();
};

uint QryPlnrFilMNCalc::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQFilMNCalc* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrFilMNCalc::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQFilMNCalc* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrFilMNCalc::handleRequest(
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

bool QryPlnrFilMNCalc::handleRefresh(
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

bool QryPlnrFilMNCalc::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQFilMNCalc* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1RefPlnrMCalcitem";
	cout << "\tstubX1RefPlnrMCalcitem";
	cout << "\tixVIo";
	cout << "\tsrefIxVIo";
	cout << "\ttitIxVIo";
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
		cout << "\t" << rec->x1RefPlnrMCalcitem;
		cout << "\t" << rec->stubX1RefPlnrMCalcitem;
		cout << "\t" << rec->ixVIo;
		cout << "\t" << rec->srefIxVIo;
		cout << "\t" << rec->titIxVIo;
		cout << endl;
	};
	return retval;
};

void QryPlnrFilMNCalc::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALRFILMOD_FILEQ) {
		call->abort = handleCallPlnrCalRfilMod_filEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrFilMNCalc::handleCallPlnrStubChg(
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

bool QryPlnrFilMNCalc::handleCallPlnrCalRfilMod_filEq(
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


