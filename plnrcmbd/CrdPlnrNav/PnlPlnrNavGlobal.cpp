/**
  * \file PnlPlnrNavGlobal.cpp
  * job handler for job PnlPlnrNavGlobal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavGlobal.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavGlobal_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavGlobal_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavGlobal
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavGlobal::PnlPlnrNavGlobal(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVGLOBAL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstCtp.tag = "FeedFLstCtp";
	feedFLstDtp.tag = "FeedFLstDtp";
	feedFLstMat.tag = "FeedFLstMat";

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshDtp(dbsplnr, moditems);
	refreshCtp(dbsplnr, moditems);
	refreshMat(dbsplnr, moditems);
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRDTP, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRCTP, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRMAT, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
};

PnlPlnrNavGlobal::~PnlPlnrNavGlobal() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavGlobal::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCtp, &feedFLstDtp, &feedFLstMat, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrNavGlobal::refreshLstDtp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDtpAvail = evalLstDtpAvail(dbsplnr);
	statshr.ButDtpViewActive = evalButDtpViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavGlobal::refreshDtp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDtp = 0;

	// feedFLstDtp
	feedFLstDtp.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRDTP, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDtp.appendRefTitles(rec->ref, StubPlnr::getStubDtpStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDTP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDtp(dbsplnr, moditems);
};

void PnlPlnrNavGlobal::refreshLstCtp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCtpAvail = evalLstCtpAvail(dbsplnr);
	statshr.ButCtpViewActive = evalButCtpViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavGlobal::refreshCtp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCtp = 0;

	// feedFLstCtp
	feedFLstCtp.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRCTP, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstCtp.appendRefTitles(rec->ref, StubPlnr::getStubCtpStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCTP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCtp(dbsplnr, moditems);
};

void PnlPlnrNavGlobal::refreshLstMat(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstMatAvail = evalLstMatAvail(dbsplnr);
	statshr.ButMatViewActive = evalButMatViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavGlobal::refreshMat(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstMat = 0;

	// feedFLstMat
	feedFLstMat.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRMAT, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstMat.appendRefTitles(rec->ref, StubPlnr::getStubMatStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTMAT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstMat(dbsplnr, moditems);
};

void PnlPlnrNavGlobal::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlPlnrNavGlobal::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	refreshLstDtp(dbsplnr, moditems);
	refreshLstCtp(dbsplnr, moditems);
	refreshLstMat(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavGlobal::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRINIT) {
			handleDpchAppPlnrInit(dbsplnr, (DpchAppPlnrInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDTPVIEWCLICK) {
					handleDpchAppDoButDtpViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDTPNEWCRDCLICK) {
					handleDpchAppDoButDtpNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTPVIEWCLICK) {
					handleDpchAppDoButCtpViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTPNEWCRDCLICK) {
					handleDpchAppDoButCtpNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMATVIEWCLICK) {
					handleDpchAppDoButMatViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMATNEWCRDCLICK) {
					handleDpchAppDoButMatNewcrdClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavGlobal::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavGlobal::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTDTP)) {
		contiac.numFLstDtp = _contiac->numFLstDtp;
		refreshLstDtp(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCTP)) {
		contiac.numFLstCtp = _contiac->numFLstCtp;
		refreshLstCtp(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTMAT)) {
		contiac.numFLstMat = _contiac->numFLstMat;
		refreshLstMat(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavGlobal::handleDpchAppDoButDtpViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDtpAvail && statshr.ButDtpViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstDtp.getRefByNum(contiac.numFLstDtp), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrDtp", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDtp");
	};
};

void PnlPlnrNavGlobal::handleDpchAppDoButDtpNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDtp");
};

void PnlPlnrNavGlobal::handleDpchAppDoButCtpViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCtpAvail && statshr.ButCtpViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstCtp.getRefByNum(contiac.numFLstCtp), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrCtp", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCtp");
	};
};

void PnlPlnrNavGlobal::handleDpchAppDoButCtpNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrCtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCtp");
};

void PnlPlnrNavGlobal::handleDpchAppDoButMatViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstMatAvail && statshr.ButMatViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstMat.getRefByNum(contiac.numFLstMat), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrMat", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrMat");
	};
};

void PnlPlnrNavGlobal::handleDpchAppDoButMatNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrMat", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrMat");
};

void PnlPlnrNavGlobal::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallPlnrHusrRunvMod_crdUsrEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlPlnrNavGlobal::handleCallPlnrHusrRunvMod_crdUsrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVCard::CRDPLNRDTP) {
		refreshDtp(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRCTP) {
		refreshCtp(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRMAT) {
		refreshMat(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


