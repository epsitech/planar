/**
  * \file QryPlnrDtpList.cpp
  * job handler for job QryPlnrDtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDtpList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDtpList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDtpList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDtpList::QryPlnrDtpList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDTPLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRDEVMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrDtpList::~QryPlnrDtpList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDtpList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrDtpList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRDTPLIST_SRF, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDTPLIST_DSN, jref);
	ubigint preSup = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDTPLIST_SUP, jref);
	ubigint preTpl = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDTPLIST_TPL, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdtplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMDevice.ref)";
	sqlstr += " FROM TblPlnrMDevice";
	sqlstr += " WHERE tplRefPlnrMDevice = 0";
	refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQDtpList(jref, jnum, ref, sref, supRefPlnrMDevice, ixVAligntype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDevice.ref, TblPlnrMDevice.sref, TblPlnrMDevice.supRefPlnrMDevice, TblPlnrMDevice.ixVAligntype";
	sqlstr += " FROM TblPlnrMDevice";
	sqlstr += " WHERE tplRefPlnrMDevice = 0";
	refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDtpList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrDtpList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preDsn
			, const ubigint preSup
			, const ubigint preTpl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDevice.sref = '" + preSrf + "'";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preDsn) + "";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDevice.supRefPlnrMDevice = " + to_string(preSup) + "";
	};

	if (preTpl != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDevice.tplRefPlnrMDevice = " + to_string(preTpl) + "";
	};
};

void QryPlnrDtpList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDtpList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMDevice.sref ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMDevice.dsnRefPlnrMDesign ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblPlnrMDevice.supRefPlnrMDevice ASC";
	else if (preIxOrd == VecVOrd::TPL) sqlstr += " ORDER BY TblPlnrMDevice.tplRefPlnrMDevice ASC";
};

void QryPlnrDtpList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDtpList* rec = NULL;

	dbsplnr->tblplnrqdtplist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSupRefPlnrMDevice = StubPlnr::getStubDevStd(dbsplnr, rec->supRefPlnrMDevice, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDtpList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDtpList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDtpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDtpList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDtpList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDtpList::handleRequest(
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

bool QryPlnrDtpList::handleRefresh(
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

bool QryPlnrDtpList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDtpList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tsupRefPlnrMDevice";
	cout << "\tstubSupRefPlnrMDevice";
	cout << "\tixVAligntype";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->supRefPlnrMDevice;
		cout << "\t" << rec->stubSupRefPlnrMDevice;
		cout << "\t" << rec->ixVAligntype;
		cout << endl;
	};
	return retval;
};

void QryPlnrDtpList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVMOD) {
		call->abort = handleCallPlnrDevMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVUPD_REFEQ) {
		call->abort = handleCallPlnrDevUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDtpList::handleCallPlnrStubChg(
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

bool QryPlnrDtpList::handleCallPlnrDevMod(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixPlnrVQrystate == VecPlnrVQrystate::UTD) || (ixPlnrVQrystate == VecPlnrVQrystate::SLM)) {
		ixPlnrVQrystate = VecPlnrVQrystate::MNR;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};

bool QryPlnrDtpList::handleCallPlnrDevUpd_refEq(
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


