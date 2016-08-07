/**
  * \file QryPlnrSruList.cpp
  * job handler for job QryPlnrSruList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrSruList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrSruList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrSruList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrSruList::QryPlnrSruList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRSRULIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRSRUMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrSruList::~QryPlnrSruList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrSruList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRSRUUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRSRUUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrSruList::refresh(
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
	ubigint preRefDtp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref);
	ubigint preRefDvc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref);
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRSRULIST_SRF, jref);
	uint preHkt = xchg->getIxPreset(VecPlnrVPreset::PREPLNRSRULIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecPlnrVPreset::PREPLNRSRULIST_HKU, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqsrulist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFDTP) {
		sqlstr = "SELECT COUNT(TblPlnrMStructure.ref)";
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDtp) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDVC) {
		sqlstr = "SELECT COUNT(TblPlnrMStructure.ref)";
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDvc) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		sqlstr = "SELECT COUNT(TblPlnrMStructure.ref)";
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DSN);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblPlnrMStructure.ref)";
		sqlstr += " FROM TblPlnrMStructure, TblPlnrMDevice";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = TblPlnrMDevice.ref";
		sqlstr += " AND TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMStructure.ref)";
		sqlstr += " FROM TblPlnrMStructure";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, true);
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

	if (preIxPre == VecPlnrVPreset::PREPLNRREFDTP) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDtp) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDVC) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDvc) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMStructure";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DSN);
		sqlstr += " AND TblPlnrMStructure.hkUref = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMStructure, TblPlnrMDevice";
		sqlstr += " WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV);
		sqlstr += " AND TblPlnrMStructure.hkUref = TblPlnrMDevice.ref";
		sqlstr += " AND TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMStructure";
		refresh_filtSQL(sqlstr, preSrf, preHkt, preHku, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQSruList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrSruList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQSruList(jref, jnum, ref, sref, hkIxVTbl, hkUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMStructure.ref, TblPlnrMStructure.sref, TblPlnrMStructure.hkIxVTbl, TblPlnrMStructure.hkUref";
};

void QryPlnrSruList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preHkt
			, const ubigint preHku
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMStructure.sref = '" + preSrf + "'";
	};

	if (preHkt != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMStructure.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMStructure.hkUref = " + to_string(preHku) + "";
	};
};

void QryPlnrSruList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrSruList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMStructure.sref ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblPlnrMStructure.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblPlnrMStructure.hkUref ASC";
};

void QryPlnrSruList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQSruList* rec = NULL;

	dbsplnr->tblplnrqsrulist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefHkIxVTbl = VecPlnrVMStructureHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecPlnrVMStructureHkTbl::getTitle(rec->hkIxVTbl, ixPlnrVLocale);
			if (rec->hkIxVTbl == VecPlnrVMStructureHkTbl::DSN) {
				rec->stubHkUref = StubPlnr::getStubDsnStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecPlnrVMStructureHkTbl::DEV) {
				rec->stubHkUref = StubPlnr::getStubDevStd(dbsplnr, rec->hkUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrSruList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrSruList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQSruList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrSruList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQSruList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrSruList::handleRequest(
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

bool QryPlnrSruList::handleRefresh(
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

bool QryPlnrSruList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQSruList* rec = NULL;

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
		cout << endl;
	};
	return retval;
};

void QryPlnrSruList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSRUMOD) {
		call->abort = handleCallPlnrSruMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSRUUPD_REFEQ) {
		call->abort = handleCallPlnrSruUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrSruList::handleCallPlnrStubChg(
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

bool QryPlnrSruList::handleCallPlnrSruMod(
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

bool QryPlnrSruList::handleCallPlnrSruUpd_refEq(
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


