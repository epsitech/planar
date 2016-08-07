/**
  * \file QryPlnrDomList.cpp
  * job handler for job QryPlnrDomList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDomList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDomList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDomList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDomList::QryPlnrDomList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDOMLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRDOMMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrDomList::~QryPlnrDomList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDomList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRDOMUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRDOMUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrDomList::refresh(
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
	string preSrf = xchg->getSrefPreset(VecPlnrVPreset::PREPLNRDOMLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecPlnrVPreset::PREPLNRDOMLIST_TYP, jref);
	ubigint preDsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRDOMLIST_DSN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdomlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecPlnrVPreset::PREPLNRREFDSN) {
		sqlstr = "SELECT COUNT(TblPlnrMDomain.ref)";
		sqlstr += " FROM TblPlnrMDomain";
		sqlstr += " WHERE TblPlnrMDomain.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preDsn, false);
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblPlnrMDomain.ref)";
		sqlstr += " FROM TblPlnrMDomain";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preDsn, true);
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
		sqlstr += " FROM TblPlnrMDomain";
		sqlstr += " WHERE TblPlnrMDomain.dsnRefPlnrMDesign = " + to_string(preRefDsn) + "";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preDsn, false);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrMDomain";
		refresh_filtSQL(sqlstr, preSrf, preTyp, preDsn, true);
		refresh_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQDomList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrDomList::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQDomList(jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMDomain.ref, TblPlnrMDomain.sref, TblPlnrMDomain.ixVBasetype, TblPlnrMDomain.dsnRefPlnrMDesign";
};

void QryPlnrDomList::refresh_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preDsn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDomain.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDomain.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preDsn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMDomain.dsnRefPlnrMDesign = " + to_string(preDsn) + "";
	};
};

void QryPlnrDomList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrDomList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblPlnrMDomain.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblPlnrMDomain.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::DSN) sqlstr += " ORDER BY TblPlnrMDomain.dsnRefPlnrMDesign ASC";
};

void QryPlnrDomList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDomList* rec = NULL;

	dbsplnr->tblplnrqdomlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecPlnrVMDomainBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecPlnrVMDomainBasetype::getTitle(rec->ixVBasetype, ixPlnrVLocale);
			rec->stubDsnRefPlnrMDesign = StubPlnr::getStubDsnStd(dbsplnr, rec->dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDomList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDomList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDomList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDomList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDomList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDomList::handleRequest(
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

bool QryPlnrDomList::handleRefresh(
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

bool QryPlnrDomList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDomList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tdsnRefPlnrMDesign";
	cout << "\tstubDsnRefPlnrMDesign";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->dsnRefPlnrMDesign;
		cout << "\t" << rec->stubDsnRefPlnrMDesign;
		cout << endl;
	};
	return retval;
};

void QryPlnrDomList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDOMMOD) {
		call->abort = handleCallPlnrDomMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDOMUPD_REFEQ) {
		call->abort = handleCallPlnrDomUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrDomList::handleCallPlnrStubChg(
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

bool QryPlnrDomList::handleCallPlnrDomMod(
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

bool QryPlnrDomList::handleCallPlnrDomUpd_refEq(
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


