/**
  * \file QryPlnrUsrAAccess.cpp
  * job handler for job QryPlnrUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrUsrAAccess.h"

// IP blksInclude --- BEGIN
#include "QryPlnrUsrAAccess_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrUsrAAccess
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrUsrAAccess::QryPlnrUsrAAccess(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRUSRAACCESS, jrefSup, ixPlnrVLocale) {
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

QryPlnrUsrAAccess::~QryPlnrUsrAAccess() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrUsrAAccess::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecPlnrVPreset::PREPLNRUSRAACCESS_X1, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRUSRAACCMOD_USREQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMUserAccess.ref)";
	sqlstr += " FROM TblPlnrAMUserAccess";
	sqlstr += " WHERE TblPlnrAMUserAccess.refPlnrMUser = " + to_string(preRefUsr) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQUsrAAccess(jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMUserAccess.ref, TblPlnrAMUserAccess.x1IxPlnrVCard, TblPlnrAMUserAccess.ixPlnrWUiaccess";
	sqlstr += " FROM TblPlnrAMUserAccess";
	sqlstr += " WHERE TblPlnrAMUserAccess.refPlnrMUser = " + to_string(preRefUsr) + "";
	refresh_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryPlnrUsrAAccess::refresh_filtSQL(
			string& sqlstr
			, const uint preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMUserAccess.x1IxPlnrVCard = " + to_string(preX1) + "";
	};
};

void QryPlnrUsrAAccess::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrUsrAAccess::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQUsrAAccess* rec = NULL;

	dbsplnr->tblplnrqusraaccess->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryPlnrUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryPlnrUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrUsrAAccess::handleRequest(
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

bool QryPlnrUsrAAccess::handleRefresh(
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

bool QryPlnrUsrAAccess::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQUsrAAccess* rec = NULL;

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

void QryPlnrUsrAAccess::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRAACCMOD_USREQ) {
		call->abort = handleCallPlnrUsrAaccMod_usrEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrUsrAAccess::handleCallPlnrStubChg(
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

bool QryPlnrUsrAAccess::handleCallPlnrUsrAaccMod_usrEq(
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


