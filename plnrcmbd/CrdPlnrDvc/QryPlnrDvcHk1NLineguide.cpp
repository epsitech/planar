/**
  * \file QryPlnrDvcHk1NLineguide.cpp
  * job handler for job QryPlnrDvcHk1NLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrDvcHk1NLineguide.h"

// IP blksInclude --- BEGIN
#include "QryPlnrDvcHk1NLineguide_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrDvcHk1NLineguide
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrDvcHk1NLineguide::QryPlnrDvcHk1NLineguide(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRDVCHK1NLINEGUIDE, jrefSup, ixPlnrVLocale) {
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

QryPlnrDvcHk1NLineguide::~QryPlnrDvcHk1NLineguide() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrDvcHk1NLineguide::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrDvcHk1NLineguide::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> refsList;
	vector<ubigint> refsPool;

	ListPlnrDevOMDeviceMLineguide ddevOlgds;
	PlnrDevOMDeviceMLineguide* ddevOlgd;

	bool qmd1Avail = evalQmd1Avail();

	ubigint preRefDvc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref);
	ubigint preRefModdsn = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref);
	vector<ubigint> preRefsSubdev = xchg->getRefsPreset(VecPlnrVPreset::PREPLNRREFSSUBDEV, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRLGDMOD_HKTHKUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqdvchk1nlineguide->removeRstByJref(jref);

	if (qmd1Avail) {
		sqlstr = "SELECT ref FROM TblPlnrMLineguide";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMLineguide.hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV);
		sqlstr += " AND TblPlnrMLineguide.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMLineguide.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMLineguide";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMLineguide.hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV);
		sqlstr += " AND TblPlnrMLineguide.hkUref = " + to_string(preRefModdsn) + "";
		sqlstr += " AND TblPlnrMLineguide.x1RefPlnrMDesign = " + to_string(preRefModdsn) + "";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);

	} else {
		sqlstr = "SELECT ref FROM TblPlnrMLineguide";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::INI);
		sqlstr += " AND TblPlnrMLineguide.hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV);
		sqlstr += " AND TblPlnrMLineguide.hkUref = " + to_string(preRefDvc) + "";
		sqlstr += " AND TblPlnrMLineguide.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, false, refsList);
		refsPool.resize(refsList.size(), 0);

		sqlstr = "SELECT ref FROM TblPlnrMLineguide";
		sqlstr += " WHERE hkIxPlnrVLat = " + to_string(VecPlnrVLat::DLO);
		sqlstr += " AND TblPlnrMLineguide.hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV);
		sqlstr += " AND TblPlnrMLineguide.hkUref = " + to_string(preRefDvc) + "";
		sqlstr += " AND TblPlnrMLineguide.x1RefPlnrMDesign = 0";
		dbsplnr->loadRefsBySQL(sqlstr, true, refsPool);
		refsList.resize(refsPool.size(), 0);
	};

	for (unsigned int i=0;i<preRefsSubdev.size();i++) {
		sqlstr = "SELECT * FROM TblPlnrDevOMDeviceMLineguide";
		sqlstr += " WHERE refPlnrMDevice = " + to_string(preRefDvc) + "";
		sqlstr += " AND x1RefPlnrMDevice = " + to_string(preRefsSubdev[i]) + "";
		dbsplnr->tblplnrdevomdevicemlineguide->loadRstBySQL(sqlstr, true, ddevOlgds);
	};

	for (unsigned int i=0;i<ddevOlgds.nodes.size();i++) {
		ddevOlgd = ddevOlgds.nodes[i];
		Lop::apply(ddevOlgd->ixPlnrVLop, refsList, refsPool, ddevOlgd->pr1RefM);
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] != 0) {
			dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, i+1, refsList[i]);
			statshr.ntot++;
		};
	};

	sqlstr = "INSERT INTO TblPlnrQDvcHk1NLineguide(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMLineguide.ref";
	sqlstr += " FROM TblPlnrMLineguide, TblPlnrQSelect";
	sqlstr += " WHERE TblPlnrQSelect.jref = " + to_string(jref);
	sqlstr += " AND TblPlnrMLineguide.ref = TblPlnrQSelect.ref";
	sqlstr += " ORDER BY sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQDvcHk1NLineguide SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRLGDMOD_HKTHKUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMLineguideHkTbl::DEV, preRefDvc, Clstn::VecVJactype::LOCK);
};

bool QryPlnrDvcHk1NLineguide::evalQmd1Avail() {
	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMODDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

void QryPlnrDvcHk1NLineguide::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQDvcHk1NLineguide* rec = NULL;

	dbsplnr->tblplnrqdvchk1nlineguide->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubLgdStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrDvcHk1NLineguide", "fetch");
	};

	refreshJnum();
};

uint QryPlnrDvcHk1NLineguide::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQDvcHk1NLineguide* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrDvcHk1NLineguide::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQDvcHk1NLineguide* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrDvcHk1NLineguide::handleRequest(
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

bool QryPlnrDvcHk1NLineguide::handleRefresh(
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

bool QryPlnrDvcHk1NLineguide::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQDvcHk1NLineguide* rec = NULL;

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

void QryPlnrDvcHk1NLineguide::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLGDMOD_HKTHKUEQ) {
		call->abort = handleCallPlnrLgdMod_hktHkuEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryPlnrDvcHk1NLineguide::handleCallPlnrStubChg(
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

bool QryPlnrDvcHk1NLineguide::handleCallPlnrLgdMod_hktHkuEq(
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


