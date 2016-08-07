/**
  * \file QryPlnrPrsADetail.cpp
  * job handler for job QryPlnrPrsADetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrPrsADetail.h"

// IP blksInclude --- BEGIN
#include "QryPlnrPrsADetail_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrPrsADetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrPrsADetail::QryPlnrPrsADetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRPRSADETAIL, jrefSup, ixPlnrVLocale) {
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

QryPlnrPrsADetail::~QryPlnrPrsADetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrPrsADetail::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrPrsADetail::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefPrs = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRS, jref);
	string preX1 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRPRSADETAIL_X1, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRPRSADETMOD_PRSEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqprsadetail->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMPersonDetail.ref)";
	sqlstr += " FROM TblPlnrAMPersonDetail";
	sqlstr += " WHERE TblPlnrAMPersonDetail.refPlnrMPerson = " + to_string(preRefPrs) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQPrsADetail(jref, jnum, ref, x1SrefKType, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMPersonDetail.ref, TblPlnrAMPersonDetail.x1SrefKType, TblPlnrAMPersonDetail.Val";
	sqlstr += " FROM TblPlnrAMPersonDetail";
	sqlstr += " WHERE TblPlnrAMPersonDetail.refPlnrMPerson = " + to_string(preRefPrs) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQPrsADetail SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRPRSADETMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefPrs, Clstn::VecVJactype::LOCK);
};

void QryPlnrPrsADetail::refresh_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMPersonDetail.x1SrefKType = '" + preX1 + "'";
	};
};

void QryPlnrPrsADetail::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrPrsADetail::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQPrsADetail* rec = NULL;

	dbsplnr->tblplnrqprsadetail->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKType = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMPERSONDETAILTYPE, rec->x1SrefKType, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrPrsADetail", "fetch");
	};

	refreshJnum();
};

uint QryPlnrPrsADetail::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQPrsADetail* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrPrsADetail::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQPrsADetail* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrPrsADetail::handleRequest(
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

bool QryPlnrPrsADetail::handleRefresh(
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

bool QryPlnrPrsADetail::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQPrsADetail* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1SrefKType";
	cout << "\ttitX1SrefKType";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1SrefKType;
		cout << "\t" << rec->titX1SrefKType;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrPrsADetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSADETMOD_PRSEQ) {
		call->abort = handleCallPlnrPrsAdetMod_prsEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrPrsADetail::handleCallPlnrStubChg(
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

bool QryPlnrPrsADetail::handleCallPlnrPrsAdetMod_prsEq(
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


