/**
  * \file QryPlnrPrsList.cpp
  * job handler for job QryPlnrPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrPrsList.h"

// IP blksInclude --- BEGIN
#include "QryPlnrPrsList_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrPrsList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrPrsList::QryPlnrPrsList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRPRSLIST, jrefSup, ixPlnrVLocale) {
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

	xchg->addClstn(VecPlnrVCall::CALLPLNRPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrPrsList::~QryPlnrPrsList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRPRSUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryPlnrPrsList::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preJrefSess = xchg->getRefPreset(VecPlnrVPreset::PREPLNRJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);
	string preLnm = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRPRSLIST_LNM, jref);
	ubigint preGrp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRPRSLIST_OWN, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMPerson.ref)";
	sqlstr += " FROM TblPlnrMPerson, TblPlnrQSelect";
	sqlstr += " WHERE TblPlnrQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblPlnrMPerson.grp = TblPlnrQSelect.ref";
	refresh_filtSQL(sqlstr, preLnm, preGrp, preOwn, false);
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQPrsList(jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, Tel, Eml)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMPerson.ref, TblPlnrMPerson.Title, TblPlnrMPerson.Firstname, TblPlnrMPerson.Lastname, TblPlnrMPerson.grp, TblPlnrMPerson.own, TblPlnrMPerson.ixVSex, TblPlnrMPerson.Tel, TblPlnrMPerson.Eml";
	sqlstr += " FROM TblPlnrMPerson, TblPlnrQSelect";
	sqlstr += " WHERE TblPlnrQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblPlnrMPerson.grp = TblPlnrQSelect.ref";
	refresh_filtSQL(sqlstr, preLnm, preGrp, preOwn, false);
	refresh_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

};

void QryPlnrPrsList::refresh_filtSQL(
			string& sqlstr
			, const string& preLnm
			, const ubigint preGrp
			, const ubigint preOwn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preLnm.length() > 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMPerson.Lastname LIKE '" + preLnm + "'";
	};

	if (preGrp != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		refresh_filtSQL_append(sqlstr, first);
		sqlstr += "TblPlnrMPerson.own = " + to_string(preOwn) + "";
	};
};

void QryPlnrPrsList::refresh_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryPlnrPrsList::refresh_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblPlnrMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblPlnrMPerson.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblPlnrMPerson.own ASC";
};

void QryPlnrPrsList::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQPrsList* rec = NULL;

	dbsplnr->tblplnrqprslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubPlnr::getStubGrp(dbsplnr, rec->grp, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubPlnr::getStubOwn(dbsplnr, rec->own, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVSex = VecPlnrVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecPlnrVMPersonSex::getTitle(rec->ixVSex, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrPrsList", "fetch");
	};

	refreshJnum();
};

uint QryPlnrPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrPrsList::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrPrsList::handleRequest(
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

bool QryPlnrPrsList::handleRefresh(
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

bool QryPlnrPrsList::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\tTel";
	cout << "\tEml";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->Tel;
		cout << "\t" << rec->Eml;
		cout << endl;
	};
	return retval;
};

void QryPlnrPrsList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSMOD) {
		call->abort = handleCallPlnrPrsMod(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSUPD_REFEQ) {
		call->abort = handleCallPlnrPrsUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrPrsList::handleCallPlnrStubChg(
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

bool QryPlnrPrsList::handleCallPlnrPrsMod(
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

bool QryPlnrPrsList::handleCallPlnrPrsUpd_refEq(
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


