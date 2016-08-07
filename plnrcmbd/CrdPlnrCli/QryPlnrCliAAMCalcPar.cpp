/**
  * \file QryPlnrCliAAMCalcPar.cpp
  * job handler for job QryPlnrCliAAMCalcPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCliAAMCalcPar.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCliAAMCalcPar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCliAAMCalcPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCliAAMCalcPar::QryPlnrCliAAMCalcPar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLIAAMCALCPAR, jrefSup, ixPlnrVLocale) {
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

QryPlnrCliAAMCalcPar::~QryPlnrCliAAMCalcPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCliAAMCalcPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrCliAAMCalcPar::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefCli = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLI, jref);
	string preX2 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRCLIAAMCALCPAR_X2, jref);
	string preX3 = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRCLIAAMCALCPAR_X3, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqcliaamcalcpar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAMCalcPar.ref)";
	sqlstr += " FROM TblPlnrAMCalcPar";
	sqlstr += " WHERE TblPlnrAMCalcPar.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
	refresh_filtSQL(sqlstr, preX2, preX3, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQCliAAMCalcPar(jref, jnum, ref, x2SrefKCat, x3SrefKProp, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAMCalcPar.ref, TblPlnrAMCalcPar.x2SrefKCat, TblPlnrAMCalcPar.x3SrefKProp, TblPlnrAMCalcPar.Val";
	sqlstr += " FROM TblPlnrAMCalcPar";
	sqlstr += " WHERE TblPlnrAMCalcPar.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
	refresh_filtSQL(sqlstr, preX2, preX3, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQCliAAMCalcPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrCliAAMCalcPar::refresh_filtSQL(
			string& sqlstr
			, const string& preX2
			, const string& preX3
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX2.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMCalcPar.x2SrefKCat = '" + preX2 + "'";
	};

	if (preX3.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrAMCalcPar.x3SrefKProp = '" + preX3 + "'";
	};
};

void QryPlnrCliAAMCalcPar::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrCliAAMCalcPar::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCliAAMCalcPar* rec = NULL;

	dbsplnr->tblplnrqcliaamcalcpar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX2SrefKCat = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMCALCPARCAT, rec->x2SrefKCat, ixPlnrVLocale);
			rec->titX3SrefKProp = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKAMCALCPARPROP, rec->x3SrefKProp, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCliAAMCalcPar", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCliAAMCalcPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCliAAMCalcPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCliAAMCalcPar::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCliAAMCalcPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCliAAMCalcPar::handleRequest(
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

bool QryPlnrCliAAMCalcPar::handleRefresh(
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

bool QryPlnrCliAAMCalcPar::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCliAAMCalcPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx2SrefKCat";
	cout << "\ttitX2SrefKCat";
	cout << "\tx3SrefKProp";
	cout << "\ttitX3SrefKProp";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x2SrefKCat;
		cout << "\t" << rec->titX2SrefKCat;
		cout << "\t" << rec->x3SrefKProp;
		cout << "\t" << rec->titX3SrefKProp;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryPlnrCliAAMCalcPar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	};
};

bool QryPlnrCliAAMCalcPar::handleCallPlnrStubChg(
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


