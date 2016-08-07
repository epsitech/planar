/**
  * \file QryPlnrCtpKParProp.cpp
  * job handler for job QryPlnrCtpKParProp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrCtpKParProp.h"

// IP blksInclude --- BEGIN
#include "QryPlnrCtpKParProp_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrCtpKParProp
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrCtpKParProp::QryPlnrCtpKParProp(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCTPKPARPROP, jrefSup, ixPlnrVLocale) {
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

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

QryPlnrCtpKParProp::~QryPlnrCtpKParProp() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrCtpKParProp::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrCtpKParProp::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefCtp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCTP, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqctpkparprop->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrAVKeylistKey.ref)";
	sqlstr += " FROM TblPlnrAVKeylistKey";
	sqlstr += " WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKAMCALCPARPROP);
	sqlstr += " AND x1IxPlnrVMaintable = " + to_string(VecPlnrVMaintable::TBLPLNRMCALC);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQCtpKParProp(jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrAVKeylistKey.ref, TblPlnrAVKeylistKey.klsNum, TblPlnrAVKeylistKey.sref, TblPlnrAVKeylistKey.Avail, TblPlnrAVKeylistKey.refJ, TblPlnrAVKeylistKey.Title, TblPlnrAVKeylistKey.Comment";
	sqlstr += " FROM TblPlnrAVKeylistKey";
	sqlstr += " WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKAMCALCPARPROP);
	sqlstr += " AND x1IxPlnrVMaintable = " + to_string(VecPlnrVMaintable::TBLPLNRMCALC);
	sqlstr += " AND x1Uref = " + to_string(preRefCtp) + "";
	sqlstr += " ORDER BY TblPlnrAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQCtpKParProp SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefSrefClstn(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMaintable::TBLPLNRMCALC, preRefCtp, VecPlnrVKeylist::getSref(VecPlnrVKeylist::KLSTPLNRKAMCALCPARPROP), Clstn::VecVJactype::LOCK);
};

void QryPlnrCtpKParProp::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQCtpKParProp* rec = NULL;

	dbsplnr->tblplnrqctpkparprop->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrCtpKParProp", "fetch");
	};

	refreshJnum();
};

uint QryPlnrCtpKParProp::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQCtpKParProp* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrCtpKParProp::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQCtpKParProp* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrCtpKParProp::handleRequest(
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

bool QryPlnrCtpKParProp::handleRefresh(
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

bool QryPlnrCtpKParProp::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQCtpKParProp* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tklsNum";
	cout << "\tsref";
	cout << "\tAvail";
	cout << "\trefJ";
	cout << "\tTitle";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->klsNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Avail;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryPlnrCtpKParProp::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallPlnrKlsAkeyMod_klsMtbUrfEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool QryPlnrCtpKParProp::handleCallPlnrStubChg(
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

bool QryPlnrCtpKParProp::handleCallPlnrKlsAkeyMod_klsMtbUrfEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;

	if (ixPlnrVQrystate != VecPlnrVQrystate::OOD) {
		ixPlnrVQrystate = VecPlnrVQrystate::OOD;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};

