/**
  * \file QryPlnrFilList.cpp
  * job handler for job QryPlnrFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrFilList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrFilList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrFilList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrFilList::QryPlnrFilList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRFILLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRFILMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrFilList::~QryPlnrFilList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrFilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRFILUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRFILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrFilList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	string preFnm = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRFILLIST_FNM, jref);
	uint preRet = xchg->getIxPreset(VecPlnrVPreset::PREPLNRFILLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecPlnrVPreset::PREPLNRFILLIST_REU, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqfillist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMFile.ref)";
	sqlstr += " FROM TblPlnrMFile";
	refresh_filtSQL(sqlstr, preFnm, preRet, preReu, true);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQFilList(jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMFile.ref, TblPlnrMFile.Filename, TblPlnrMFile.refIxVTbl, TblPlnrMFile.refUref, TblPlnrMFile.osrefKContent, TblPlnrMFile.srefKMimetype, TblPlnrMFile.Size";
	sqlstr += " FROM TblPlnrMFile";
	refresh_filtSQL(sqlstr, preFnm, preRet, preReu, true);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQFilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrFilList::refresh_filtSQL(
			string& sqlstr
			, const string& preFnm
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preFnm.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMFile.Filename LIKE '" + preFnm + "'";
	};

	if (preRet != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMFile.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMFile.refUref = " + to_string(preReu) + "";
	};
};

void QryPlnrFilList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrFilList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::FNM) sqlstr += " ORDER BY TblPlnrMFile.Filename ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblPlnrMFile.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblPlnrMFile.refUref ASC";
};

void QryPlnrFilList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQFilList* rec = NULL;

	dbsplnr->tblplnrqfillist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefRefIxVTbl = VecPlnrVMFileRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecPlnrVMFileRefTbl::getTitle(rec->refIxVTbl, ixPlnrVLocale);
			if (rec->refIxVTbl == VecPlnrVMFileRefTbl::CAL) {
				rec->stubRefUref = StubPlnr::getStubCalStd(dbsplnr, rec->refUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecPlnrVMFileRefTbl::MAT) {
				rec->stubRefUref = StubPlnr::getStubMatStd(dbsplnr, rec->refUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecPlnrVMFileRefTbl::CLI) {
				rec->stubRefUref = StubPlnr::getStubCliStd(dbsplnr, rec->refUref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->titOsrefKContent = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKMFILECONTENT, rec->osrefKContent, ixPlnrVLocale);
			rec->titSrefKMimetype = dbsplnr->getKlstTitleBySref(VecPlnrVKeylist::KLSTPLNRKMFILEMIMETYPE, rec->srefKMimetype, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrFilList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrFilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQFilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrFilList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQFilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrFilList::handleRequest(
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

bool QryPlnrFilList::handleRefresh(
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

bool QryPlnrFilList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQFilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tFilename";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tosrefKContent";
	cout << "\ttitOsrefKContent";
	cout << "\tsrefKMimetype";
	cout << "\ttitSrefKMimetype";
	cout << "\tSize";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Filename;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->osrefKContent;
		cout << "\t" << rec->titOsrefKContent;
		cout << "\t" << rec->srefKMimetype;
		cout << "\t" << rec->titSrefKMimetype;
		cout << "\t" << rec->Size;
		cout << endl;
	};
	return retval;
};

void QryPlnrFilList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILMOD) {
		call->abort = handleCallPlnrFilMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILUPD_REFEQ) {
		call->abort = handleCallPlnrFilUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrFilList::handleCallPlnrStubChg(
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

bool QryPlnrFilList::handleCallPlnrFilMod(
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

bool QryPlnrFilList::handleCallPlnrFilUpd_refEq(
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


