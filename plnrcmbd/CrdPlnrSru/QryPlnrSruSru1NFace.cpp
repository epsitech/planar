/**
  * \file QryPlnrSruSru1NFace.cpp
  * job handler for job QryPlnrSruSru1NFace (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrSruSru1NFace.h"

// IP blksInclude --- BEGIN
#include "QryPlnrSruSru1NFace_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrSruSru1NFace
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrSruSru1NFace::QryPlnrSruSru1NFace(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRSRUSRU1NFACE, jrefSup, ixPlnrVLocale) {
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

QryPlnrSruSru1NFace::~QryPlnrSruSru1NFace() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrSruSru1NFace::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrSruSru1NFace::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> refsList;
	vector<ubigint> refsPool;

	ListPlnrOMStructureMFace sruOfces;
	PlnrOMStructureMFace* sruOfce;

	bool qmd1Avail = evalQmd1Avail();

	ubigint preRefSru = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSRU, jref);
	ubigint preRefModdsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref);
	vector<ubigint> preRefsSubdev = xchg->getRefsPreset(VecPlnrVPreset::PREPLNRREFSSUBDEV, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRFCEMOD_SRUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqsrusru1nface->removeRstByJref(jref);

	if (qmd1Avail) {
		sqlstr = "SELECT ref FROM TblPlnrMFace";
		sqlstr += " WHERE sruIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMFace.sruRefPlnrMStructure = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMFace.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMFace";
		sqlstr += " WHERE sruIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMFace.sruRefPlnrMStructure = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMFace.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);

	} else {
		sqlstr = "SELECT ref FROM TblPlnrMFace";
		sqlstr += " WHERE sruIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMFace.sruRefPlnrMStructure = " + to_string(preRefSru) + "";
		sqlstr += " AND TblPlnrMFace.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMFace";
		sqlstr += " WHERE sruIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMFace.sruRefPlnrMStructure = " + to_string(preRefSru) + "";
		sqlstr += " AND TblPlnrMFace.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);
	};

	for (unsigned int i=0;i<preRefsSubdev.size();i++) {
		sqlstr = "SELECT * FROM TblPlnrOMStructureMFace";
		sqlstr += " WHERE refPlnrMStructure = " + to_string(preRefSru) + "";
		sqlstr += " AND x1RefPlnrMDevice = " + to_string(preRefsSubdev[i]) + "";
		dbsplnr->tblplnromstructuremface->loadRstBySQL(sqlstr, true, sruOfces);
	};

	for (unsigned int i=0;i<sruOfces.nodes.size();i++) {
		sruOfce = sruOfces.nodes[i];
		Lop::apply(sruOfce->ixPlnrVLop, refsList, refsPool, sruOfce->pr1RefM);
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] != 0) {
			dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, i+1, refsList[i]);
			statshr.ntot++;
		};
	};

	sqlstr = "INSERT INTO TblPlnrQSruSru1NFace(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMFace.ref";
	sqlstr += " FROM TblPlnrMFace, TblPlnrQSelect";
	sqlstr += " WHERE TblPlnrQSelect.jref = " + to_string(jref);
	sqlstr += " AND TblPlnrMFace.ref = TblPlnrQSelect.ref";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQSruSru1NFace SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRFCEMOD_SRUEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSru, Clstn::VecVJactype::LOCK);
};

bool QryPlnrSruSru1NFace::evalQmd1Avail() {
	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

void QryPlnrSruSru1NFace::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQSruSru1NFace* rec = NULL;

	dbsplnr->tblplnrqsrusru1nface->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubFceStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrSruSru1NFace", "fetch");
	};

	refreshJnum();
};

uint QryPlnrSruSru1NFace::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQSruSru1NFace* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrSruSru1NFace::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQSruSru1NFace* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrSruSru1NFace::handleRequest(
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

bool QryPlnrSruSru1NFace::handleRefresh(
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

bool QryPlnrSruSru1NFace::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQSruSru1NFace* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryPlnrSruSru1NFace::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFCEMOD_SRUEQ) {
		call->abort = handleCallPlnrFceMod_sruEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrSruSru1NFace::handleCallPlnrStubChg(
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

bool QryPlnrSruSru1NFace::handleCallPlnrFceMod_sruEq(
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


