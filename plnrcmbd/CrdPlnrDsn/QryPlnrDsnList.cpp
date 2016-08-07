/**
  * \file QryPlnrDsnList.cpp
  * job handler for job QryPlnrDsnList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDsnList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDsnList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDsnList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDsnList::QryPlnrDsnList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDSNLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRDSNMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrDsnList::~QryPlnrDsnList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDsnList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDSNUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRDSNUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrDsnList::refresh(
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
	uint preTyp = xchg->getIxPreset(VecPlnrVPreset::PREPLNRDSNLIST_TYP, jref);
	uint preDim = xchg->getIxPreset(VecPlnrVPreset::PREPLNRDSNLIST_DIM, jref);
	uint preRet = xchg->getIxPreset(VecPlnrVPreset::PREPLNRDSNLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDSNLIST_REU, jref);
	ubigint prePrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDSNLIST_PRJ, jref);
	uint preMty = xchg->getIxPreset(VecPlnrVPreset::PREPLNRDSNLIST_MTY, jref);
	ubigint preMod = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDSNLIST_MOD, jref);
	ubigint preDrv = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDSNLIST_DRV, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdsnlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFPRJ) {
		sqlstr = "SELECT COUNT(TblPlnrMDesign.ref)";
		sqlstr += " FROM TblPlnrMDesign";
		sqlstr += " WHERE TblPlnrMDesign.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTyp, preDim, preRet, preReu, prePrj, preMty, preMod, preDrv, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMDesign.ref)";
		sqlstr += " FROM TblPlnrMDesign";
		refresh_filtSQL(sqlstr, preTyp, preDim, preRet, preReu, prePrj, preMty, preMod, preDrv, true);
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
		sqlstr += " FROM TblPlnrMDesign";
		sqlstr += " WHERE TblPlnrMDesign.refPlnrMProject = " + to_string(preRefPrj) + "";
		refresh_filtSQL(sqlstr, preTyp, preDim, preRet, preReu, prePrj, preMty, preMod, preDrv, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMDesign";
		refresh_filtSQL(sqlstr, preTyp, preDim, preRet, preReu, prePrj, preMty, preMod, preDrv, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQDsnList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrDsnList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQDsnList(jref, jnum, ref, Title, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Major, Sub)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDesign.ref, TblPlnrMDesign.Title, TblPlnrMDesign.ixVBasetype, TblPlnrMDesign.ixVDim, TblPlnrMDesign.refIxVTbl, TblPlnrMDesign.refUref, TblPlnrMDesign.refPlnrMProject, TblPlnrMDesign.ixWModtype, TblPlnrMDesign.modRefPlnrMDesign, TblPlnrMDesign.drvRefPlnrMDesign, TblPlnrMDesign.Major, TblPlnrMDesign.Sub";
};

void QryPlnrDsnList::refresh_filtSQL(
			string& sqlstr
			, const uint preTyp
			, const uint preDim
			, const uint preRet
			, const ubigint preReu
			, const ubigint prePrj
			, const uint preMty
			, const ubigint preMod
			, const ubigint preDrv
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTyp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preDim != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.ixVDim = " + to_string(preDim) + "";
	};

	if (preRet != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.refUref = " + to_string(preReu) + "";
	};

	if (prePrj != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.refPlnrMProject = " + to_string(prePrj) + "";
	};

	if (preMty != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "(TblPlnrMDesign.ixWModtype & " + to_string(preMty) + ") <> 0";
	};

	if (preMod != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.modRefPlnrMDesign = " + to_string(preMod) + "";
	};

	if (preDrv != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDesign.drvRefPlnrMDesign = " + to_string(preDrv) + "";
	};
};

void QryPlnrDsnList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDsnList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblPlnrMDesign.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::DIM) sqlstr += " ORDER BY TblPlnrMDesign.ixVDim ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblPlnrMDesign.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblPlnrMDesign.refUref ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblPlnrMDesign.refPlnrMProject ASC";
	else if (preIxOrd == VecVOrd::MTY) sqlstr += " ORDER BY TblPlnrMDesign.ixWModtype ASC";
	else if (preIxOrd == VecVOrd::MOD) sqlstr += " ORDER BY TblPlnrMDesign.modRefPlnrMDesign ASC";
	else if (preIxOrd == VecVOrd::DRV) sqlstr += " ORDER BY TblPlnrMDesign.drvRefPlnrMDesign ASC";
};

void QryPlnrDsnList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDsnList* rec = NULL;

	dbsplnr->tblplnrqdsnlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecPlnrVMDesignBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecPlnrVMDesignBasetype::getTitle(rec->ixVBasetype, ixPlnrVLocale);
			rec->srefIxVDim = VecPlnrVMDesignDim::getSref(rec->ixVDim);
			rec->titIxVDim = VecPlnrVMDesignDim::getTitle(rec->ixVDim, ixPlnrVLocale);
			rec->srefRefIxVTbl = VecPlnrVMDesignRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecPlnrVMDesignRefTbl::getTitle(rec->refIxVTbl, ixPlnrVLocale);
			rec->stubRefUref = "-";
			rec->stubRefPlnrMProject = StubPlnr::getStubPrjStd(dbsplnr, rec->refPlnrMProject, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefsIxWModtype = VecPlnrWMDesignModtype::getSrefs(rec->ixWModtype);
			rec->stubModRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->modRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubDrvRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->drvRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDsnList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDsnList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDsnList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDsnList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDsnList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDsnList::handleRequest(
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

bool QryPlnrDsnList::handleRefresh(
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

bool QryPlnrDsnList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDsnList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tixVDim";
	cout << "\tsrefIxVDim";
	cout << "\ttitIxVDim";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\trefPlnrMProject";
	cout << "\tstubRefPlnrMProject";
	cout << "\tixWModtype";
	cout << "\tsrefsIxWModtype";
	cout << "\ttitsIxWModtype";
	cout << "\tmodRefPlnrMDesign";
	cout << "\tstubModRefPlnrMDesign";
	cout << "\tdrvRefPlnrMDesign";
	cout << "\tstubDrvRefPlnrMDesign";
	cout << "\tMajor";
	cout << "\tSub";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->ixVDim;
		cout << "\t" << rec->srefIxVDim;
		cout << "\t" << rec->titIxVDim;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->refPlnrMProject;
		cout << "\t" << rec->stubRefPlnrMProject;
		cout << "\t" << rec->ixWModtype;
		cout << "\t" << rec->srefsIxWModtype;
		cout << "\t" << rec->titsIxWModtype;
		cout << "\t" << rec->modRefPlnrMDesign;
		cout << "\t" << rec->stubModRefPlnrMDesign;
		cout << "\t" << rec->drvRefPlnrMDesign;
		cout << "\t" << rec->stubDrvRefPlnrMDesign;
		cout << "\t" << rec->Major;
		cout << "\t" << rec->Sub;
		cout << endl;
	};
	return retval;
};

void QryPlnrDsnList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSNMOD) {
		call->abort = handleCallPlnrDsnMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSNUPD_REFEQ) {
		call->abort = handleCallPlnrDsnUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDsnList::handleCallPlnrStubChg(
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

bool QryPlnrDsnList::handleCallPlnrDsnMod(
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

bool QryPlnrDsnList::handleCallPlnrDsnUpd_refEq(
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


