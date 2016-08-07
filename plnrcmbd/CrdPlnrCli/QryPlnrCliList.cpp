/**
  * \file QryPlnrCliList.cpp
  * job handler for job QryPlnrCliList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCliList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCliList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCliList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCliList::QryPlnrCliList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLILIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRCLIMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrCliList::~QryPlnrCliList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCliList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCLIUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRCLIUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrCliList::refresh(
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
	ubigint preRefClc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref);
	ubigint preRefPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);
	string preTit = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRCLILIST_TIT, jref);
	ubigint preCal = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLILIST_CAL, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLILIST_DSN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqclilist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFCLC) {
		sqlstr = "SELECT COUNT(TblPlnrMCalcitem.ref)";
		sqlstr += " FROM TblPlnrMCalcitem";
		sqlstr += " WHERE TblPlnrMCalcitem.calRefPlnrMCalc = " + to_string(preRefClc) + "";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFPRJ) {
		sqlstr = "SELECT COUNT(TblPlnrMCalcitem.ref)";
		sqlstr += " FROM TblPlnrMCalcitem, TblPlnrMCalc";
		sqlstr += " WHERE TblPlnrMCalcitem.calRefPlnrMCalc = TblPlnrMCalc.ref";
		sqlstr += " AND TblPlnrMCalc.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMCalcitem.ref)";
		sqlstr += " FROM TblPlnrMCalcitem";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, true);
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

	if (preIxPre == VecPlnrVPreset::PREPLNRREFCLC) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMCalcitem";
		sqlstr += " WHERE TblPlnrMCalcitem.calRefPlnrMCalc = " + to_string(preRefClc) + "";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFPRJ) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMCalcitem, TblPlnrMCalc";
		sqlstr += " WHERE TblPlnrMCalcitem.calRefPlnrMCalc = TblPlnrMCalc.ref";
		sqlstr += " AND TblPlnrMCalc.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMCalcitem";
		refresh_filtSQL(sqlstr, preTit, preCal, preDsn, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQCliList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrCliList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQCliList(jref, jnum, ref, Title, calRefPlnrMCalc, refPlnrMDesign)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMCalcitem.ref, TblPlnrMCalcitem.Title, TblPlnrMCalcitem.calRefPlnrMCalc, TblPlnrMCalcitem.refPlnrMDesign";
};

void QryPlnrCliList::refresh_filtSQL(
			string& sqlstr
			, const string& preTit
			, const ubigint preCal
			, const ubigint preDsn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalcitem.Title LIKE '" + preTit + "'";
	};

	if (preCal != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalcitem.calRefPlnrMCalc = " + to_string(preCal) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalcitem.refPlnrMDesign = " + to_string(preDsn) + "";
	};
};

void QryPlnrCliList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrCliList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblPlnrMCalcitem.Title ASC";
	else if (preIxOrd == VecVOrd::CAL) sqlstr += " ORDER BY TblPlnrMCalcitem.calRefPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMCalcitem.refPlnrMDesign ASC";
};

void QryPlnrCliList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCliList* rec = NULL;

	dbsplnr->tblplnrqclilist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubCalRefPlnrMCalc = StubPlnr::getStubCalStd(dbsplnr, rec->calRefPlnrMCalc, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCliList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCliList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCliList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCliList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCliList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCliList::handleRequest(
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

bool QryPlnrCliList::handleRefresh(
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

bool QryPlnrCliList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCliList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tcalRefPlnrMCalc";
	cout << "\tstubCalRefPlnrMCalc";
	cout << "\trefPlnrMDesign";
	cout << "\tstubRefPlnrMDesign";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->calRefPlnrMCalc;
		cout << "\t" << rec->stubCalRefPlnrMCalc;
		cout << "\t" << rec->refPlnrMDesign;
		cout << "\t" << rec->stubRefPlnrMDesign;
		cout << endl;
	};
	return retval;
};

void QryPlnrCliList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCLIMOD) {
		call->abort = handleCallPlnrCliMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCLIUPD_REFEQ) {
		call->abort = handleCallPlnrCliUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrCliList::handleCallPlnrStubChg(
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

bool QryPlnrCliList::handleCallPlnrCliMod(
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

bool QryPlnrCliList::handleCallPlnrCliUpd_refEq(
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


