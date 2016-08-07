/**
  * \file QryPlnrDvcList.cpp
  * job handler for job QryPlnrDvcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDvcList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDvcList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDvcList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDvcList::QryPlnrDvcList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDVCLIST, jrefSup, ixPlnrVLocale) {
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

QryPlnrDvcList::~QryPlnrDvcList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDvcList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrDvcList::refresh(
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
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRDVCLIST_SRF, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDVCLIST_DSN, jref);
	ubigint preSup = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDVCLIST_SUP, jref);
	ubigint preTpl = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDVCLIST_TPL, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdvclist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		sqlstr = "SELECT COUNT(TblPlnrMDevice.ref)";
		sqlstr += " FROM TblPlnrMDevice";
		sqlstr += " WHERE tplRefPlnrMDevice <> 0";
		sqlstr += " AND TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMDevice.ref)";
		sqlstr += " FROM TblPlnrMDevice";
		sqlstr += " WHERE tplRefPlnrMDevice <> 0";
		refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
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

	if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMDevice";
		sqlstr += " WHERE tplRefPlnrMDevice <> 0";
		sqlstr += " AND TblPlnrMDevice.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMDevice";
		sqlstr += " WHERE tplRefPlnrMDevice <> 0";
		refresh_filtSQL(sqlstr, preSrf, preDsn, preSup, preTpl, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQDvcList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrDvcList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQDvcList(jref, jnum, ref, sref, dsnRefPlnrMDesign, supRefPlnrMDevice, tplRefPlnrMDevice, ixVModtype, ixVAligntype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDevice.ref, TblPlnrMDevice.sref, TblPlnrMDevice.dsnRefPlnrMDesign, TblPlnrMDevice.supRefPlnrMDevice, TblPlnrMDevice.tplRefPlnrMDevice, TblPlnrMDevice.ixVModtype, TblPlnrMDevice.ixVAligntype";
};

void QryPlnrDvcList::refresh_filtSQL(
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

void QryPlnrDvcList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDvcList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMDevice.sref ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMDevice.dsnRefPlnrMDesign ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblPlnrMDevice.supRefPlnrMDevice ASC";
	else if (preIxOrd == VecVOrd::TPL) sqlstr += " ORDER BY TblPlnrMDevice.tplRefPlnrMDevice ASC";
};

void QryPlnrDvcList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDvcList* rec = NULL;

	dbsplnr->tblplnrqdvclist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubDsnRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefPlnrMDevice = StubPlnr::getStubDevStd(dbsplnr, rec->supRefPlnrMDevice, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubTplRefPlnrMDevice = StubPlnr::getStubDevStd(dbsplnr, rec->tplRefPlnrMDevice, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVModtype = VecPlnrVMDeviceModtype::getSref(rec->ixVModtype);
			rec->titIxVModtype = VecPlnrVMDeviceModtype::getTitle(rec->ixVModtype, ixPlnrVLocale);
			rec->srefIxVAligntype = VecPlnrVMDeviceAligntype::getSref(rec->ixVAligntype);
			rec->titIxVAligntype = VecPlnrVMDeviceAligntype::getTitle(rec->ixVAligntype, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDvcList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDvcList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDvcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDvcList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDvcList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDvcList::handleRequest(
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

bool QryPlnrDvcList::handleRefresh(
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

bool QryPlnrDvcList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDvcList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tdsnRefPlnrMDesign";
	cout << "\tstubDsnRefPlnrMDesign";
	cout << "\tsupRefPlnrMDevice";
	cout << "\tstubSupRefPlnrMDevice";
	cout << "\ttplRefPlnrMDevice";
	cout << "\tstubTplRefPlnrMDevice";
	cout << "\tixVModtype";
	cout << "\tsrefIxVModtype";
	cout << "\ttitIxVModtype";
	cout << "\tixVAligntype";
	cout << "\tsrefIxVAligntype";
	cout << "\ttitIxVAligntype";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->dsnRefPlnrMDesign;
		cout << "\t" << rec->stubDsnRefPlnrMDesign;
		cout << "\t" << rec->supRefPlnrMDevice;
		cout << "\t" << rec->stubSupRefPlnrMDevice;
		cout << "\t" << rec->tplRefPlnrMDevice;
		cout << "\t" << rec->stubTplRefPlnrMDevice;
		cout << "\t" << rec->ixVModtype;
		cout << "\t" << rec->srefIxVModtype;
		cout << "\t" << rec->titIxVModtype;
		cout << "\t" << rec->ixVAligntype;
		cout << "\t" << rec->srefIxVAligntype;
		cout << "\t" << rec->titIxVAligntype;
		cout << endl;
	};
	return retval;
};

void QryPlnrDvcList::handleCall(
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

bool QryPlnrDvcList::handleCallPlnrStubChg(
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

bool QryPlnrDvcList::handleCallPlnrDevMod(
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

bool QryPlnrDvcList::handleCallPlnrDevUpd_refEq(
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


