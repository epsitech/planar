/**
  * \file QryPlnrAriList.cpp
  * job handler for job QryPlnrAriList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrAriList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrAriList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrAriList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrAriList::QryPlnrAriList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRARILIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRARIMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrAriList::~QryPlnrAriList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrAriList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRARIUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRARIUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrAriList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	ubigint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	ubigint preRefTpo = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref);
	int preI = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_I, jref);
	int preJ = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_J, jref);
	int preK = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_K, jref);
	int preL = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_L, jref);
	int preM = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_M, jref);
	int preN = xchg->getIntvalPreset(VecPlnrVPreset::PREPLNRARILIST_N, jref);
	ubigint preArr = xchg->getRefPreset(VecPlnrVPreset::PREPLNRARILIST_ARR, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRARILIST_DSN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqarilist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFTPO) {
		sqlstr = "SELECT COUNT(TblPlnrMArrayitem.ref)";
		sqlstr += " FROM TblPlnrMArrayitem, TblPlnrMArray";
		sqlstr += " WHERE TblPlnrMArrayitem.refPlnrMArray = TblPlnrMArray.ref";
		sqlstr += " AND TblPlnrMArray.refPlnrMTapeout = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preI, preJ, preK, preL, preM, preN, preArr, preDsn, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMArrayitem.ref)";
		sqlstr += " FROM TblPlnrMArrayitem";
		refresh_filtSQL(sqlstr, preI, preJ, preK, preL, preM, preN, preArr, preDsn, true);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i=0;i<cnts.size();i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecPlnrVPreset::PREPLNRREFTPO) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMArrayitem, TblPlnrMArray";
		sqlstr += " WHERE TblPlnrMArrayitem.refPlnrMArray = TblPlnrMArray.ref";
		sqlstr += " AND TblPlnrMArray.refPlnrMTapeout = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preI, preJ, preK, preL, preM, preN, preArr, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMArrayitem";
		refresh_filtSQL(sqlstr, preI, preJ, preK, preL, preM, preN, preArr, preDsn, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQAriList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrAriList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQAriList(jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, refPlnrMDesign, dx, dy)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMArrayitem.ref, TblPlnrMArrayitem.i, TblPlnrMArrayitem.j, TblPlnrMArrayitem.k, TblPlnrMArrayitem.l, TblPlnrMArrayitem.m, TblPlnrMArrayitem.n, TblPlnrMArrayitem.refPlnrMArray, TblPlnrMArrayitem.refPlnrMDesign, TblPlnrMArrayitem.dx, TblPlnrMArrayitem.dy";
};

void QryPlnrAriList::refresh_filtSQL(
			string& sqlstr
			, const int preI
			, const int preJ
			, const int preK
			, const int preL
			, const int preM
			, const int preN
			, const ubigint preArr
			, const ubigint preDsn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preI != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.i = " + to_string(preI) + "";
	};

	if (preJ != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.j = " + to_string(preJ) + "";
	};

	if (preK != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.k = " + to_string(preK) + "";
	};

	if (preL != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.l = " + to_string(preL) + "";
	};

	if (preM != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.m = " + to_string(preM) + "";
	};

	if (preN != numeric_limits<int>::min()) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.n = " + to_string(preN) + "";
	};

	if (preArr != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.refPlnrMArray = " + to_string(preArr) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMArrayitem.refPlnrMDesign = " + to_string(preDsn) + "";
	};
};

void QryPlnrAriList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrAriList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::I) sqlstr += " ORDER BY TblPlnrMArrayitem.i ASC";
	else if (preIxOrd == VecVOrd::J) sqlstr += " ORDER BY TblPlnrMArrayitem.j ASC";
	else if (preIxOrd == VecVOrd::K) sqlstr += " ORDER BY TblPlnrMArrayitem.k ASC";
	else if (preIxOrd == VecVOrd::L) sqlstr += " ORDER BY TblPlnrMArrayitem.l ASC";
	else if (preIxOrd == VecVOrd::M) sqlstr += " ORDER BY TblPlnrMArrayitem.m ASC";
	else if (preIxOrd == VecVOrd::N) sqlstr += " ORDER BY TblPlnrMArrayitem.n ASC";
	else if (preIxOrd == VecVOrd::ARR) sqlstr += " ORDER BY TblPlnrMArrayitem.refPlnrMArray ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMArrayitem.refPlnrMDesign ASC";
};

void QryPlnrAriList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQAriList* rec = NULL;

	dbsplnr->tblplnrqarilist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefPlnrMArray = StubPlnr::getStubArrStd(dbsplnr, rec->refPlnrMArray, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrAriList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrAriList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQAriList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrAriList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQAriList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrAriList::handleRequest(
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

bool QryPlnrAriList::handleRefresh(
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

bool QryPlnrAriList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQAriList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\ti";
	cout << "\tj";
	cout << "\tk";
	cout << "\tl";
	cout << "\tm";
	cout << "\tn";
	cout << "\trefPlnrMArray";
	cout << "\tstubRefPlnrMArray";
	cout << "\trefPlnrMDesign";
	cout << "\tstubRefPlnrMDesign";
	cout << "\tdx";
	cout << "\tdy";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->i;
		cout << "\t" << rec->j;
		cout << "\t" << rec->k;
		cout << "\t" << rec->l;
		cout << "\t" << rec->m;
		cout << "\t" << rec->n;
		cout << "\t" << rec->refPlnrMArray;
		cout << "\t" << rec->stubRefPlnrMArray;
		cout << "\t" << rec->refPlnrMDesign;
		cout << "\t" << rec->stubRefPlnrMDesign;
		cout << "\t" << rec->dx;
		cout << "\t" << rec->dy;
		cout << endl;
	};
	return retval;
};

void QryPlnrAriList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRARIMOD) {
		call->abort = handleCallPlnrAriMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRARIUPD_REFEQ) {
		call->abort = handleCallPlnrAriUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrAriList::handleCallPlnrStubChg(
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

bool QryPlnrAriList::handleCallPlnrAriMod(
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

bool QryPlnrAriList::handleCallPlnrAriUpd_refEq(
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


