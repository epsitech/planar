/**
  * \file QryPlnrRtcList.cpp
  * job handler for job QryPlnrRtcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrRtcList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrRtcList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrRtcList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrRtcList::QryPlnrRtcList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRRTCLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRRTCMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrRtcList::~QryPlnrRtcList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrRtcList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRRTCUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRRTCUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrRtcList::refresh(
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
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRRTCLIST_SRF, jref);
	uint preHkt = xchg->getIxPreset(VecPlnrVPreset::PREPLNRRTCLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecPlnrVPreset::PREPLNRRTCLIST_HKU, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRRTCLIST_DSN, jref);
	ubigint preLyr = xchg->getRefPreset(VecPlnrVPreset::PREPLNRRTCLIST_LYR, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqrtclist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFTPO) {
		sqlstr = "SELECT COUNT(TblPlnrMReticle.ref)";
		sqlstr += " FROM TblPlnrMReticle";
		sqlstr += " WHERE TblPlnrMReticle.hkIxVTbl = " + to_string(VecPlnrVMReticleHkTbl::TPO);
		sqlstr += " AND TblPlnrMReticle.hkUref = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblPlnrMReticle.ref)";
		sqlstr += " FROM TblPlnrMReticle, TblPlnrMArray";
		sqlstr += " WHERE TblPlnrMReticle.hkIxVTbl = " + to_string(VecPlnrVMReticleHkTbl::ARR);
		sqlstr += " AND TblPlnrMReticle.hkUref = TblPlnrMArray.ref";
		sqlstr += " AND TblPlnrMArray.refPlnrMTapeout = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMReticle.ref)";
		sqlstr += " FROM TblPlnrMReticle";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, true);
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
		sqlstr += " FROM TblPlnrMReticle";
		sqlstr += " WHERE TblPlnrMReticle.hkIxVTbl = " + to_string(VecPlnrVMReticleHkTbl::TPO);
		sqlstr += " AND TblPlnrMReticle.hkUref = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMReticle, TblPlnrMArray";
		sqlstr += " WHERE TblPlnrMReticle.hkIxVTbl = " + to_string(VecPlnrVMReticleHkTbl::ARR);
		sqlstr += " AND TblPlnrMReticle.hkUref = TblPlnrMArray.ref";
		sqlstr += " AND TblPlnrMArray.refPlnrMTapeout = " + to_string(preRefTpo) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMReticle";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, preDsn, preLyr, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQRtcList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrRtcList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQRtcList(jref, jnum, ref, sref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMReticle.ref, TblPlnrMReticle.sref, TblPlnrMReticle.hkIxVTbl, TblPlnrMReticle.hkUref, TblPlnrMReticle.refPlnrMDesign, TblPlnrMReticle.refPlnrMLayer";
};

void QryPlnrRtcList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preHkt
			, const ubigint preHku
			, const ubigint preDsn
			, const ubigint preLyr
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMReticle.sref = '" + preSrf + "'";
	};

	if (preHkt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMReticle.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMReticle.hkUref = " + to_string(preHku) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMReticle.refPlnrMDesign = " + to_string(preDsn) + "";
	};

	if (preLyr != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMReticle.refPlnrMLayer = " + to_string(preLyr) + "";
	};
};

void QryPlnrRtcList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrRtcList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMReticle.sref ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblPlnrMReticle.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblPlnrMReticle.hkUref ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMReticle.refPlnrMDesign ASC";
	else if (preIxOrd == VecVOrd::LYR) sqlstr += " ORDER BY TblPlnrMReticle.refPlnrMLayer ASC";
};

void QryPlnrRtcList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQRtcList* rec = NULL;

	dbsplnr->tblplnrqrtclist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefHkIxVTbl = VecPlnrVMReticleHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecPlnrVMReticleHkTbl::getTitle(rec->hkIxVTbl, ixPlnrVLocale);
			if (rec->hkIxVTbl == VecPlnrVMReticleHkTbl::TPO) {
				rec->stubHkUref = StubPlnr::getStubTpoStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecPlnrVMReticleHkTbl::ARR) {
				rec->stubHkUref = StubPlnr::getStubArrStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
			rec->stubRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefPlnrMLayer = StubPlnr::getStubLyrStd(dbsplnr, rec->refPlnrMLayer, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrRtcList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrRtcList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQRtcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrRtcList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQRtcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrRtcList::handleRequest(
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

bool QryPlnrRtcList::handleRefresh(
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

bool QryPlnrRtcList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQRtcList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << "\trefPlnrMDesign";
	cout << "\tstubRefPlnrMDesign";
	cout << "\trefPlnrMLayer";
	cout << "\tstubRefPlnrMLayer";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << "\t" << rec->refPlnrMDesign;
		cout << "\t" << rec->stubRefPlnrMDesign;
		cout << "\t" << rec->refPlnrMLayer;
		cout << "\t" << rec->stubRefPlnrMLayer;
		cout << endl;
	};
	return retval;
};

void QryPlnrRtcList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRRTCMOD) {
		call->abort = handleCallPlnrRtcMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRRTCUPD_REFEQ) {
		call->abort = handleCallPlnrRtcUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrRtcList::handleCallPlnrStubChg(
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

bool QryPlnrRtcList::handleCallPlnrRtcMod(
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

bool QryPlnrRtcList::handleCallPlnrRtcUpd_refEq(
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


