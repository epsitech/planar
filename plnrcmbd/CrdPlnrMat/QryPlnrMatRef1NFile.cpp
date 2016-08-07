/**
  * \file QryPlnrMatRef1NFile.cpp
  * job handler for job QryPlnrMatRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "QryPlnrMatRef1NFile.h"

// IP blksInclude --- BEGIN
#include "QryPlnrMatRef1NFile_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class QryPlnrMatRef1NFile
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
QryPlnrMatRef1NFile::QryPlnrMatRef1NFile(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::QRYPLNRMATREF1NFILE, jrefSup, ixPlnrVLocale) {
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

QryPlnrMatRef1NFile::~QryPlnrMatRef1NFile() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryPlnrMatRef1NFile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryPlnrMatRef1NFile::refresh(
			DbsPlnr* dbsplnr
			, const bool call
		) {
	string sqlstr;

	ubigint cnt;

	ubigint preRefMat = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMAT, jref);

	xchg->removeClstns(VecPlnrVCall::CALLPLNRFILMOD_RETREUEQ, jref);

	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	dbsplnr->tblplnrqmatref1nfile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblPlnrMFile.ref)";
	sqlstr += " FROM TblPlnrMFile";
	sqlstr += " WHERE TblPlnrMFile.refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::MAT);
	sqlstr += " AND TblPlnrMFile.refUref = " + to_string(preRefMat) + "";
	dbsplnr->loadUbigintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblPlnrQMatRef1NFile(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblPlnrMFile.ref";
	sqlstr += " FROM TblPlnrMFile";
	sqlstr += " WHERE TblPlnrMFile.refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::MAT);
	sqlstr += " AND TblPlnrMFile.refUref = " + to_string(preRefMat) + "";
	sqlstr += " ORDER BY Filename ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsplnr->executeQuery(sqlstr);

	sqlstr = "UPDATE TblPlnrQMatRef1NFile SET jnum = qref WHERE jref = " + to_string(jref);
	dbsplnr->executeQuery(sqlstr);

	ixPlnrVQrystate = VecPlnrVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsplnr);

	if (call) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRFILMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVMFileRefTbl::MAT, preRefMat, Clstn::VecVJactype::LOCK);
};

void QryPlnrMatRef1NFile::fetch(
			DbsPlnr* dbsplnr
		) {
	string sqlstr;

	StmgrPlnr* stmgr = NULL;
	Stcch* stcch = NULL;

	PlnrQMatRef1NFile* rec = NULL;

	dbsplnr->tblplnrqmatref1nfile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubPlnr::getStubFilStd(dbsplnr, rec->ref, ixPlnrVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryPlnrMatRef1NFile", "fetch");
	};

	refreshJnum();
};

uint QryPlnrMatRef1NFile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	PlnrQMatRef1NFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryPlnrMatRef1NFile::getRefByJnum(
			const uint jnum
		) {
	ubigint retval = 0;

	PlnrQMatRef1NFile* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->jnum == jnum) {
			retval = rec->ref;
			break;
		};
	};

	return retval;
};

void QryPlnrMatRef1NFile::handleRequest(
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

bool QryPlnrMatRef1NFile::handleRefresh(
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

bool QryPlnrMatRef1NFile::handleShow(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	PlnrQMatRef1NFile* rec = NULL;

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

void QryPlnrMatRef1NFile::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTUBCHG) {
		call->abort = handleCallPlnrStubChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILMOD_RETREUEQ) {
		call->abort = handleCallPlnrFilMod_retReuEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool QryPlnrMatRef1NFile::handleCallPlnrStubChg(
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

bool QryPlnrMatRef1NFile::handleCallPlnrFilMod_retReuEq(
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


