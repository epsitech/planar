/**
  * \file QryPlnrClcList.cpp
  * job handler for job QryPlnrClcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrClcList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrClcList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrClcList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrClcList::QryPlnrClcList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLCLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRCALMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrClcList::~QryPlnrClcList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrClcList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrClcList::refresh(
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
	ubigint preRefPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);
	string preTit = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRCLCLIST_TIT, jref);
	ubigint prePrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLCLIST_PRJ, jref);
	uint preDim = xchg->getIxPreset(VecPlnrVPreset::PREPLNRCLCLIST_DIM, jref);
	ubigint preTpl = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLCLIST_TPL, jref);
	ubigint preSup = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLCLIST_SUP, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRCLCLIST_DSN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqclclist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFPRJ) {
		sqlstr = "SELECT COUNT(TblPlnrMCalc.ref)";
		sqlstr += " FROM TblPlnrMCalc";
		sqlstr += " WHERE tplRefPlnrMCalc <> 0";
		sqlstr += " AND TblPlnrMCalc.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMCalc.ref)";
		sqlstr += " FROM TblPlnrMCalc";
		sqlstr += " WHERE tplRefPlnrMCalc <> 0";
		refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
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

	if (preIxPre == VecPlnrVPreset::PREPLNRREFPRJ) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMCalc";
		sqlstr += " WHERE tplRefPlnrMCalc <> 0";
		sqlstr += " AND TblPlnrMCalc.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMCalc";
		sqlstr += " WHERE tplRefPlnrMCalc <> 0";
		refresh_filtSQL(sqlstr, preTit, prePrj, preDim, preTpl, preSup, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQClcList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrClcList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQClcList(jref, jnum, ref, Title, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMCalc.ref, TblPlnrMCalc.Title, TblPlnrMCalc.refPlnrMProject, TblPlnrMCalc.ixVDim, TblPlnrMCalc.tplRefPlnrMCalc, TblPlnrMCalc.supRefPlnrMCalc, TblPlnrMCalc.refPlnrMDesign";
};

void QryPlnrClcList::refresh_filtSQL(
			string& sqlstr
			, const string& preTit
			, const ubigint prePrj
			, const uint preDim
			, const ubigint preTpl
			, const ubigint preSup
			, const ubigint preDsn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTit.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.Title LIKE '" + preTit + "'";
	};

	if (prePrj != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.refPlnrMProject = " + to_string(prePrj) + "";
	};

	if (preDim != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.ixVDim = " + to_string(preDim) + "";
	};

	if (preTpl != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.tplRefPlnrMCalc = " + to_string(preTpl) + "";
	};

	if (preSup != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.supRefPlnrMCalc = " + to_string(preSup) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMCalc.refPlnrMDesign = " + to_string(preDsn) + "";
	};
};

void QryPlnrClcList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrClcList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblPlnrMCalc.Title ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblPlnrMCalc.refPlnrMProject ASC";
	else if (preIxOrd == VecVOrd::DIM) sqlstr += " ORDER BY TblPlnrMCalc.ixVDim ASC";
	else if (preIxOrd == VecVOrd::TPL) sqlstr += " ORDER BY TblPlnrMCalc.tplRefPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblPlnrMCalc.supRefPlnrMCalc ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMCalc.refPlnrMDesign ASC";
};

void QryPlnrClcList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQClcList* rec = NULL;

	dbsplnr->tblplnrqclclist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefPlnrMProject = StubPlnr::getStubPrjStd(dbsplnr, rec->refPlnrMProject, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVDim = VecPlnrVMCalcDim::getSref(rec->ixVDim);
			rec->titIxVDim = VecPlnrVMCalcDim::getTitle(rec->ixVDim, ixPlnrVLocale);
			rec->stubTplRefPlnrMCalc = StubPlnr::getStubCalStd(dbsplnr, rec->tplRefPlnrMCalc, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefPlnrMCalc = StubPlnr::getStubCalStd(dbsplnr, rec->supRefPlnrMCalc, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrClcList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrClcList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQClcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrClcList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQClcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrClcList::handleRequest(
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

bool QryPlnrClcList::handleRefresh(
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

bool QryPlnrClcList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQClcList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\trefPlnrMProject";
	cout << "\tstubRefPlnrMProject";
	cout << "\tixVDim";
	cout << "\tsrefIxVDim";
	cout << "\ttitIxVDim";
	cout << "\ttplRefPlnrMCalc";
	cout << "\tstubTplRefPlnrMCalc";
	cout << "\tsupRefPlnrMCalc";
	cout << "\tstubSupRefPlnrMCalc";
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
		cout << "\t" << rec->refPlnrMProject;
		cout << "\t" << rec->stubRefPlnrMProject;
		cout << "\t" << rec->ixVDim;
		cout << "\t" << rec->srefIxVDim;
		cout << "\t" << rec->titIxVDim;
		cout << "\t" << rec->tplRefPlnrMCalc;
		cout << "\t" << rec->stubTplRefPlnrMCalc;
		cout << "\t" << rec->supRefPlnrMCalc;
		cout << "\t" << rec->stubSupRefPlnrMCalc;
		cout << "\t" << rec->refPlnrMDesign;
		cout << "\t" << rec->stubRefPlnrMDesign;
		cout << endl;
	};
	return retval;
};

void QryPlnrClcList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALMOD) {
		call->abort = handleCallPlnrCalMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALUPD_REFEQ) {
		call->abort = handleCallPlnrCalUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrClcList::handleCallPlnrStubChg(
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

bool QryPlnrClcList::handleCallPlnrCalMod(
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

bool QryPlnrClcList::handleCallPlnrCalUpd_refEq(
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


