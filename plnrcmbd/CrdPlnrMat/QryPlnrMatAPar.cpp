/**
  * \file QryPlnrMatAPar.cpp
  * job handler for job QryPlnrMatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrMatAPar.h"

// IP blksInclude --- BEGIN
#include "QryPlnrMatAPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrMatAPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrMatAPar::QryPlnrMatAPar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRMATAPAR, jrefSup, ixPlnrVLocale) {
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

QryPlnrMatAPar::~QryPlnrMatAPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrMatAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrMatAPar::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefMat = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMAT, jref);
	ubigint preX1 = xchg->getRefPreset(VecPlnrVPreset::PREPLNRMATAPAR_X1, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRMATAPAR_X2, jref);
	string preX3 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRMATAPAR_X3, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRMATAPARMOD_MATEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqmatapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMMaterialPar.ref)";
	sqlstr += " FROM TblPlnrAMMaterialPar";
	sqlstr += " WHERE TblPlnrAMMaterialPar.refPlnrMMaterial = " + to_string(preRefMat) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, preX3, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQMatAPar(jref, jnum, ref, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMMaterialPar.ref, TblPlnrAMMaterialPar.x1RefPlnrMDesign, TblPlnrAMMaterialPar.x2SrefKCat, TblPlnrAMMaterialPar.x3SrefKProp, TblPlnrAMMaterialPar.refPlnrMFile, TblPlnrAMMaterialPar.Val, TblPlnrAMMaterialPar.Comment";
	sqlstr += " FROM TblPlnrAMMaterialPar";
	sqlstr += " WHERE TblPlnrAMMaterialPar.refPlnrMMaterial = " + to_string(preRefMat) + "";
	refresh_filtSQL(sqlstr, preX1, preX2, preX3, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQMatAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRMATAPARMOD_MATEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefMat, Clstn::VecVJactype::LOCK);
};

void QryPlnrMatAPar::refresh_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const string& preX2
			, const string& preX3
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMMaterialPar.x1RefPlnrMDesign = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMMaterialPar.x2SrefKCat = '" + preX2 + "'";
	};

	if (preX3.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMMaterialPar.x3SrefKProp = '" + preX3 + "'";
	};
};

void QryPlnrMatAPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrMatAPar::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQMatAPar* rec = NULL;

	dbsplnr->tblplnrqmatapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->x1RefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titX2SrefKCat = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMMATERIALPARCAT, rec->x2SrefKCat, ixPlnrVLocale);
			rec->titX3SrefKProp = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMMATERIALPARPROP, rec->x3SrefKProp, ixPlnrVLocale);
			rec->stubRefPlnrMFile = StubPlnr::getStubFilStd(dbsplnr, rec->refPlnrMFile, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrMatAPar", "fetch");
	};

	refreshJnum();
};

uint QryPlnrMatAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQMatAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrMatAPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQMatAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrMatAPar::handleRequest(
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

bool QryPlnrMatAPar::handleRefresh(
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

bool QryPlnrMatAPar::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQMatAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefPlnrMDesign";
	cout << "\tstubX1RefPlnrMDesign";
	cout << "\tx2SrefKCat";
	cout << "\ttitX2SrefKCat";
	cout << "\tx3SrefKProp";
	cout << "\ttitX3SrefKProp";
	cout << "\trefPlnrMFile";
	cout << "\tstubRefPlnrMFile";
	cout << "\tVal";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefPlnrMDesign;
		cout << "\t" << rec->stubX1RefPlnrMDesign;
		cout << "\t" << rec->x2SrefKCat;
		cout << "\t" << rec->titX2SrefKCat;
		cout << "\t" << rec->x3SrefKProp;
		cout << "\t" << rec->titX3SrefKProp;
		cout << "\t" << rec->refPlnrMFile;
		cout << "\t" << rec->stubRefPlnrMFile;
		cout << "\t" << rec->Val;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryPlnrMatAPar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRMATAPARMOD_MATEQ) {
		call->abort = handleCallPlnrMatAparMod_matEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrMatAPar::handleCallPlnrStubChg(
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

bool QryPlnrMatAPar::handleCallPlnrMatAparMod_matEq(
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


