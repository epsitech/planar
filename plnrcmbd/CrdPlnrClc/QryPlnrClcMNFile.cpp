/**
  * \file QryPlnrClcMNFile.cpp
  * job handler for job QryPlnrClcMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrClcMNFile.h"

// IP blksInclude --- BEGIN
#include "QryPlnrClcMNFile_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrClcMNFile
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrClcMNFile::QryPlnrClcMNFile(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRCLCMNFILE, jrefSup, ixPlnrVLocale) {
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

QryPlnrClcMNFile::~QryPlnrClcMNFile() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrClcMNFile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrClcMNFile::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	bool qmd1Avail = evalQmd1Avail();

	ubigint preRefClc = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref);
	ubigint preRefCli = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLI, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRCALRFILMOD_CALEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqclcmnfile->removeRstByJref(jref);

	if (qmd1Avail) {
		sqlstr = "SELECT COUNT(TblPlnrRMCalcMFile.ref)";
		sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMFile";
		sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMFile = TblPlnrMFile.ref";
		sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMCalc = " + to_string(preRefCli) + "";
		sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	} else {
		sqlstr = "SELECT COUNT(TblPlnrRMCalcMFile.ref)";
		sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMFile";
		sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMFile = TblPlnrMFile.ref";
		sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMCalc = " + to_string(preRefClc) + "";
		sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = 0";
		dbsplnr->loadUbigintBySQL(sqlstr, cnt);
	};

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	if (qmd1Avail) {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMFile";
		sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMFile = TblPlnrMFile.ref";
		sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMCalc = " + to_string(preRefCli) + "";
		sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = " + to_string(preRefCli) + "";
		sqlstr += " ORDER BY TblPlnrMFile.Filename ASC";
		sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
		dbsplnr->executeQuery(sqlstr);

	} else {
		refresh_baseSQL(sqlstr);
		sqlstr += " FROM TblPlnrRMCalcMFile, TblPlnrMFile";
		sqlstr += " WHERE TblPlnrRMCalcMFile.refPlnrMFile = TblPlnrMFile.ref";
		sqlstr += " AND TblPlnrRMCalcMFile.refPlnrMCalc = " + to_string(preRefClc) + "";
		sqlstr += " AND TblPlnrRMCalcMFile.x1RefPlnrMCalcitem = 0";
		sqlstr += " ORDER BY TblPlnrMFile.Filename ASC";
		sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
		dbsplnr->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblPlnrQClcMNFile SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addRefClstn(VecPlnrVCall::CALLPLNRCALRFILMOD_CALEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefClc, Clstn::VecVJactype::LOCK);
};

void QryPlnrClcMNFile::refresh_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblPlnrQClcMNFile(jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMFile.ref, TblPlnrRMCalcMFile.ref, TblPlnrRMCalcMFile.x1RefPlnrMCalcitem, TblPlnrRMCalcMFile.ixVIo";
};

bool QryPlnrClcMNFile::evalQmd1Avail() {
	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

void QryPlnrClcMNFile::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQClcMNFile* rec = NULL;

	dbsplnr->tblplnrqclcmnfile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubPlnr::getStubFilStd(dbsplnr, rec->mref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubX1RefPlnrMCalcitem = StubPlnr::getStubCliStd(dbsplnr, rec->x1RefPlnrMCalcitem, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVIo = VecPlnrVRMCalcMFileIo::getSref(rec->ixVIo);
			rec->titIxVIo = VecPlnrVRMCalcMFileIo::getTitle(rec->ixVIo, ixPlnrVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrClcMNFile", "fetch");
	};

	refreshJnum();
};

uint QryPlnrClcMNFile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQClcMNFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrClcMNFile::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQClcMNFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrClcMNFile::handleRequest(
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

bool QryPlnrClcMNFile::handleRefresh(
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

bool QryPlnrClcMNFile::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQClcMNFile* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1RefPlnrMCalcitem";
	cout << "\tstubX1RefPlnrMCalcitem";
	cout << "\tixVIo";
	cout << "\tsrefIxVIo";
	cout << "\ttitIxVIo";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefPlnrMCalcitem;
		cout << "\t" << rec->stubX1RefPlnrMCalcitem;
		cout << "\t" << rec->ixVIo;
		cout << "\t" << rec->srefIxVIo;
		cout << "\t" << rec->titIxVIo;
		cout << endl;
	};
	return retval;
};

void QryPlnrClcMNFile::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALRFILMOD_CALEQ) {
		call->abort = handleCallPlnrCalRfilMod_calEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool QryPlnrClcMNFile::handleCallPlnrStubChg(
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

bool QryPlnrClcMNFile::handleCallPlnrCalRfilMod_calEq(
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


