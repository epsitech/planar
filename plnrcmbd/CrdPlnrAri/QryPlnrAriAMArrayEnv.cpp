/**
  * \file QryPlnrAriAMArrayEnv.cpp
  * job handler for job QryPlnrAriAMArrayEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrAriAMArrayEnv.h"

// IP blksInclude --- BEGIN
#include "QryPlnrAriAMArrayEnv_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrAriAMArrayEnv
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrAriAMArrayEnv::QryPlnrAriAMArrayEnv(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRARIAMARRAYENV, jrefSup, ixPlnrVLocale) {
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

QryPlnrAriAMArrayEnv::~QryPlnrAriAMArrayEnv() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrAriAMArrayEnv::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrAriAMArrayEnv::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefAri = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRARIAMARRAYENV_X2, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqariamarrayenv->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMArrayEnv.ref)";
	sqlstr += " FROM TblPlnrAMArrayEnv";
	sqlstr += " WHERE TblPlnrAMArrayEnv.x1RefPlnrMArrayitem = " + to_string(preRefAri) + "";
	refresh_filtSQL(sqlstr, preX2, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQAriAMArrayEnv(jref, jnum, ref, x2SrefKKey, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMArrayEnv.ref, TblPlnrAMArrayEnv.x2SrefKKey, TblPlnrAMArrayEnv.Val";
	sqlstr += " FROM TblPlnrAMArrayEnv";
	sqlstr += " WHERE TblPlnrAMArrayEnv.x1RefPlnrMArrayitem = " + to_string(preRefAri) + "";
	refresh_filtSQL(sqlstr, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQAriAMArrayEnv SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrAriAMArrayEnv::refresh_filtSQL(
			string& sqlstr
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMArrayEnv.x2SrefKKey = '" + preX2 + "'";
	};
};

void QryPlnrAriAMArrayEnv::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrAriAMArrayEnv::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQAriAMArrayEnv* rec = NULL;

	dbsplnr->tblplnrqariamarrayenv->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX2SrefKKey = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMARRAYENVKEY, rec->x2SrefKKey, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrAriAMArrayEnv", "fetch");
	};

	refreshJnum();
};

uint QryPlnrAriAMArrayEnv::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQAriAMArrayEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrAriAMArrayEnv::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQAriAMArrayEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrAriAMArrayEnv::handleRequest(
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

bool QryPlnrAriAMArrayEnv::handleRefresh(
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

bool QryPlnrAriAMArrayEnv::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQAriAMArrayEnv* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx2SrefKKey";
	cout << "\ttitX2SrefKKey";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x2SrefKKey;
		cout << "\t" << rec->titX2SrefKKey;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrAriAMArrayEnv::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	};
};

bool QryPlnrAriAMArrayEnv::handleCallPlnrStubChg(
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


