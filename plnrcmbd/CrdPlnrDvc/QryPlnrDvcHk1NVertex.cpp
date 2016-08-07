/**
  * \file QryPlnrDvcHk1NVertex.cpp
  * job handler for job QryPlnrDvcHk1NVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDvcHk1NVertex.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDvcHk1NVertex_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDvcHk1NVertex
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDvcHk1NVertex::QryPlnrDvcHk1NVertex(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDVCHK1NVERTEX, jrefSup, ixPlnrVLocale) {
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

QryPlnrDvcHk1NVertex::~QryPlnrDvcHk1NVertex() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDvcHk1NVertex::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDvcHk1NVertex::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> refsList;
	vector<ubigint> refsPool;

	ListPlnrDevOMDeviceMVertex ddevOvtxs;
	PlnrDevOMDeviceMVertex* ddevOvtx;

	bool qmd1Avail = evalQmd1Avail();

	ubigint preRefDvc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref);
	ubigint preRefModdsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref);
	vector<ubigint> preRefsSubdev = xchg->getRefsPreset(VecPlnrVPreset::PREPLNRREFSSUBDEV, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRVTXMOD_HKTHKUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdvchk1nvertex->removeRstByJref(jref);

	if (qmd1Avail) {
		sqlstr = "SELECT ref FROM TblPlnrMVertex";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMVertex.hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV);
		sqlstr += " AND TblPlnrMVertex.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMVertex.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMVertex";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMVertex.hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV);
		sqlstr += " AND TblPlnrMVertex.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMVertex.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);

	} else {
		sqlstr = "SELECT ref FROM TblPlnrMVertex";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMVertex.hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV);
		sqlstr += " AND TblPlnrMVertex.hkUref = " + to_string(preRefDvc) + "";
		sqlstr += " AND TblPlnrMVertex.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMVertex";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMVertex.hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV);
		sqlstr += " AND TblPlnrMVertex.hkUref = " + to_string(preRefDvc) + "";
		sqlstr += " AND TblPlnrMVertex.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);
	};

	for (unsigned int i=0;i<preRefsSubdev.size();i++) {
		sqlstr = "SELECT * FROM TblPlnrDevOMDeviceMVertex";
		sqlstr += " WHERE refPlnrMDevice = " + to_string(preRefDvc) + "";
		sqlstr += " AND x1RefPlnrMDevice = " + to_string(preRefsSubdev[i]) + "";
		dbsplnr->tblplnrdevomdevicemvertex->loadRstBySQL(sqlstr, true, ddevOvtxs);
	};

	for (unsigned int i=0;i<ddevOvtxs.nodes.size();i++) {
		ddevOvtx = ddevOvtxs.nodes[i];
		Lop::apply(ddevOvtx->ixPlnrVLop, refsList, refsPool, ddevOvtx->pr1RefM);
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] != 0) {
			dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, i+1, refsList[i]);
			statshr.ntot++;
		};
	};

	sqlstr = "INSERT INTO TblPlnrQDvcHk1NVertex(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMVertex.ref";
	sqlstr += " FROM TblPlnrMVertex, TblPlnrQSelect";
	sqlstr += " WHERE TblPlnrQSelect.jref = " + to_string(jref);
	sqlstr += " AND TblPlnrMVertex.ref = TblPlnrQSelect.ref";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDvcHk1NVertex SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRVTXMOD_HKTHKUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMVertexHkTbl::DEV, preRefDvc, Clstn::VecVJactype::LOCK);
};

bool QryPlnrDvcHk1NVertex::evalQmd1Avail() {
	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

void QryPlnrDvcHk1NVertex::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDvcHk1NVertex* rec = NULL;

	dbsplnr->tblplnrqdvchk1nvertex->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubVtxStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDvcHk1NVertex", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDvcHk1NVertex::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDvcHk1NVertex* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDvcHk1NVertex::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDvcHk1NVertex* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDvcHk1NVertex::handleRequest(
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

bool QryPlnrDvcHk1NVertex::handleRefresh(
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

bool QryPlnrDvcHk1NVertex::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDvcHk1NVertex* rec = NULL;

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

void QryPlnrDvcHk1NVertex::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRVTXMOD_HKTHKUEQ) {
		call->abort = handleCallPlnrVtxMod_hktHkuEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryPlnrDvcHk1NVertex::handleCallPlnrStubChg(
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

bool QryPlnrDvcHk1NVertex::handleCallPlnrVtxMod_hktHkuEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixPlnrVQrystate != VecPlnrVQrystate::OOD) {
		ixPlnrVQrystate = VecPlnrVQrystate::OOD;
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
	};

	return retval;
};


