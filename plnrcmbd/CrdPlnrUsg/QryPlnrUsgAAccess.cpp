/**
  * \file QryPlnrUsgAAccess.cpp
  * job handler for job QryPlnrUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrUsgAAccess.h"

// IP blksInclude --- BEGIN
#include "QryPlnrUsgAAccess_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrUsgAAccess
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrUsgAAccess::QryPlnrUsgAAccess(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRUSGAACCESS, jrefSup, ixPlnrVLocale) {
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

QryPlnrUsgAAccess::~QryPlnrUsgAAccess() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrUsgAAccess::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecPlnrVPreset::PREPLNRUSGAACCESS_X1, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRUSGAACCMOD_USGEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMUsergroupAccess.ref)";
	sqlstr += " FROM TblPlnrAMUsergroupAccess";
	sqlstr += " WHERE TblPlnrAMUsergroupAccess.refPlnrMUsergroup = " + to_string(preRefUsg) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQUsgAAccess(jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMUsergroupAccess.ref, TblPlnrAMUsergroupAccess.x1IxPlnrVCard, TblPlnrAMUsergroupAccess.ixPlnrWUiaccess";
	sqlstr += " FROM TblPlnrAMUsergroupAccess";
	sqlstr += " WHERE TblPlnrAMUsergroupAccess.refPlnrMUsergroup = " + to_string(preRefUsg) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryPlnrUsgAAccess::refresh_filtSQL(
			string& sqlstr
			, const uint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMUsergroupAccess.x1IxPlnrVCard = " + to_string(preX1) + "";
	};
};

void QryPlnrUsgAAccess::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrUsgAAccess::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQUsgAAccess* rec = NULL;

	dbsplnr->tblplnrqusgaaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxPlnrVCard = VecPlnrVCard::getSref(rec->x1IxPlnrVCard);
			rec->titX1IxPlnrVCard = VecPlnrVCard::getTitle(rec->x1IxPlnrVCard, ixPlnrVLocale);
			rec->srefsIxPlnrWUiaccess = VecPlnrWUiaccess::getSrefs(rec->ixPlnrWUiaccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryPlnrUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQUsgAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrUsgAAccess::handleRequest(
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

bool QryPlnrUsgAAccess::handleRefresh(
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

bool QryPlnrUsgAAccess::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQUsgAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxPlnrVCard";
	cout << "\tsrefX1IxPlnrVCard";
	cout << "\ttitX1IxPlnrVCard";
	cout << "\tixPlnrWUiaccess";
	cout << "\tsrefsIxPlnrWUiaccess";
	cout << "\ttitsIxPlnrWUiaccess";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxPlnrVCard;
		cout << "\t" << rec->srefX1IxPlnrVCard;
		cout << "\t" << rec->titX1IxPlnrVCard;
		cout << "\t" << rec->ixPlnrWUiaccess;
		cout << "\t" << rec->srefsIxPlnrWUiaccess;
		cout << "\t" << rec->titsIxPlnrWUiaccess;
		cout << endl;
	};
	return retval;
};

void QryPlnrUsgAAccess::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSGAACCMOD_USGEQ) {
		call->abort = handleCallPlnrUsgAaccMod_usgEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrUsgAAccess::handleCallPlnrStubChg(
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

bool QryPlnrUsgAAccess::handleCallPlnrUsgAaccMod_usgEq(
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


