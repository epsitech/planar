/**
  * \file QryPlnrLyrList.cpp
  * job handler for job QryPlnrLyrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrLyrList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrLyrList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrLyrList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrLyrList::QryPlnrLyrList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRLYRLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRLYRMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrLyrList::~QryPlnrLyrList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrLyrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRLYRUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRLYRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrLyrList::refresh(
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
	ubigint preRefDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref);
	ubigint preRefStk = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref);
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRLYRLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecPlnrVPreset::PREPLNRLYRLIST_TYP, jref);
	uint preHkt = xchg->getIxPreset(VecPlnrVPreset::PREPLNRLYRLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecPlnrVPreset::PREPLNRLYRLIST_HKU, jref);
	ubigint preMat = xchg->getRefPreset(VecPlnrVPreset::PREPLNRLYRLIST_MAT, jref);
	uint preTty = xchg->getIxPreset(VecPlnrVPreset::PREPLNRLYRLIST_TTY, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqlyrlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFSTK) {
		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefStk) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer, TblPlnrMStack";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK);
		sqlstr += " AND TblPlnrMLayer.hkUref = TblPlnrMStack.ref";
		sqlstr += " AND TblPlnrMStack.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMLayer.ref)";
		sqlstr += " FROM TblPlnrMLayer";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, true);
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

	if (preIxPre == VecPlnrVPreset::PREPLNRREFSTK) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefStk) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN);
		sqlstr += " AND TblPlnrMLayer.hkUref = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer, TblPlnrMStack";
		sqlstr += " WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK);
		sqlstr += " AND TblPlnrMLayer.hkUref = TblPlnrMStack.ref";
		sqlstr += " AND TblPlnrMStack.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMLayer";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preMat, preTty, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQLyrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrLyrList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQLyrList(jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, refPlnrMMaterial, ixVTtype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMLayer.ref, TblPlnrMLayer.sref, TblPlnrMLayer.x1RefPlnrMDesign, TblPlnrMLayer.ixVBasetype, TblPlnrMLayer.hkIxVTbl, TblPlnrMLayer.hkUref, TblPlnrMLayer.refPlnrMMaterial, TblPlnrMLayer.ixVTtype";
};

void QryPlnrLyrList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const uint preHkt
			, const ubigint preHku
			, const ubigint preMat
			, const uint preTty
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preHkt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.hkUref = " + to_string(preHku) + "";
	};

	if (preMat != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.refPlnrMMaterial = " + to_string(preMat) + "";
	};

	if (preTty != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMLayer.ixVTtype = " + to_string(preTty) + "";
	};
};

void QryPlnrLyrList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrLyrList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMLayer.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblPlnrMLayer.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblPlnrMLayer.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblPlnrMLayer.hkUref ASC";
	else if (preIxOrd == VecVOrd::MAT) sqlstr += " ORDER BY TblPlnrMLayer.refPlnrMMaterial ASC";
	else if (preIxOrd == VecVOrd::TTY) sqlstr += " ORDER BY TblPlnrMLayer.ixVTtype ASC";
};

void QryPlnrLyrList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQLyrList* rec = NULL;

	dbsplnr->tblplnrqlyrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecPlnrVMLayerBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecPlnrVMLayerBasetype::getTitle(rec->ixVBasetype, ixPlnrVLocale);
			rec->srefHkIxVTbl = VecPlnrVMLayerHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecPlnrVMLayerHkTbl::getTitle(rec->hkIxVTbl, ixPlnrVLocale);
			if (rec->hkIxVTbl == VecPlnrVMLayerHkTbl::DSN) {
				rec->stubHkUref = StubPlnr::getStubDsnStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecPlnrVMLayerHkTbl::STK) {
				rec->stubHkUref = StubPlnr::getStubStkStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
			rec->stubRefPlnrMMaterial = StubPlnr::getStubMatStd(dbsplnr, rec->refPlnrMMaterial, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVTtype = VecPlnrVMLayerTtype::getSref(rec->ixVTtype);
			rec->titIxVTtype = VecPlnrVMLayerTtype::getTitle(rec->ixVTtype, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrLyrList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrLyrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQLyrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrLyrList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQLyrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrLyrList::handleRequest(
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

bool QryPlnrLyrList::handleRefresh(
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

bool QryPlnrLyrList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQLyrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tx1RefPlnrMDesign";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << "\trefPlnrMMaterial";
	cout << "\tstubRefPlnrMMaterial";
	cout << "\tixVTtype";
	cout << "\tsrefIxVTtype";
	cout << "\ttitIxVTtype";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->x1RefPlnrMDesign;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << "\t" << rec->refPlnrMMaterial;
		cout << "\t" << rec->stubRefPlnrMMaterial;
		cout << "\t" << rec->ixVTtype;
		cout << "\t" << rec->srefIxVTtype;
		cout << "\t" << rec->titIxVTtype;
		cout << endl;
	};
	return retval;
};

void QryPlnrLyrList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRMOD) {
		call->abort = handleCallPlnrLyrMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRUPD_REFEQ) {
		call->abort = handleCallPlnrLyrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrLyrList::handleCallPlnrStubChg(
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

bool QryPlnrLyrList::handleCallPlnrLyrMod(
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

bool QryPlnrLyrList::handleCallPlnrLyrUpd_refEq(
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


