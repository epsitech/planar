/**
  * \file QryPlnrCliAAMCalcEnv.cpp
  * job handler for job QryPlnrCliAAMCalcEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCliAAMCalcEnv.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCliAAMCalcEnv_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCliAAMCalcEnv
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCliAAMCalcEnv::QryPlnrCliAAMCalcEnv(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLIAAMCALCENV, jrefSup, ixPlnrVLocale) {
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

QryPlnrCliAAMCalcEnv::~QryPlnrCliAAMCalcEnv() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCliAAMCalcEnv::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrCliAAMCalcEnv::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefCli = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLI, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRCLIAAMCALCENV_X2, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqcliaamcalcenv->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMCalcEnv.ref)";
	sqlstr += " FROM TblPlnrAMCalcEnv";
	sqlstr += " WHERE TblPlnrAMCalcEnv.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
	refresh_filtSQL(sqlstr, preX2, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQCliAAMCalcEnv(jref, jnum, ref, x2SrefKKey, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMCalcEnv.ref, TblPlnrAMCalcEnv.x2SrefKKey, TblPlnrAMCalcEnv.Val";
	sqlstr += " FROM TblPlnrAMCalcEnv";
	sqlstr += " WHERE TblPlnrAMCalcEnv.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
	refresh_filtSQL(sqlstr, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQCliAAMCalcEnv SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrCliAAMCalcEnv::refresh_filtSQL(
			string& sqlstr
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMCalcEnv.x2SrefKKey = '" + preX2 + "'";
	};
};

void QryPlnrCliAAMCalcEnv::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrCliAAMCalcEnv::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCliAAMCalcEnv* rec = NULL;

	dbsplnr->tblplnrqcliaamcalcenv->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX2SrefKKey = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMCALCENVKEY, rec->x2SrefKKey, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCliAAMCalcEnv", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCliAAMCalcEnv::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCliAAMCalcEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCliAAMCalcEnv::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCliAAMCalcEnv* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCliAAMCalcEnv::handleRequest(
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

bool QryPlnrCliAAMCalcEnv::handleRefresh(
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

bool QryPlnrCliAAMCalcEnv::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCliAAMCalcEnv* rec = NULL;

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

void QryPlnrCliAAMCalcEnv::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	};
};

bool QryPlnrCliAAMCalcEnv::handleCallPlnrStubChg(
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


