/**
  * \file PnlPlnrNavLayout.cpp
  * job handler for job PnlPlnrNavLayout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavLayout.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavLayout_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavLayout_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavLayout
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavLayout::PnlPlnrNavLayout(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVLAYOUT, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstAri.tag = "FeedFLstAri";
	feedFLstArr.tag = "FeedFLstArr";
	feedFLstRtc.tag = "FeedFLstRtc";
	feedFLstTpo.tag = "FeedFLstTpo";

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshTpo(dbsplnr, moditems);
	refreshArr(dbsplnr, moditems);
	refreshAri(dbsplnr, moditems);
	refreshRtc(dbsplnr, moditems);
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRTPO, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRARR, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRARI, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRRTC, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
};

PnlPlnrNavLayout::~PnlPlnrNavLayout() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavLayout::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstAri, &feedFLstArr, &feedFLstRtc, &feedFLstTpo, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrNavLayout::refreshLstTpo(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTpoAvail = evalLstTpoAvail(dbsplnr);
	statshr.ButTpoViewActive = evalButTpoViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavLayout::refreshTpo(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTpo = 0;

	// feedFLstTpo
	feedFLstTpo.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRTPO, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstTpo.appendRefTitles(rec->ref, StubPlnr::getStubTpoStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTPO);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTpo(dbsplnr, moditems);
};

void PnlPlnrNavLayout::refreshLstArr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstArrAvail = evalLstArrAvail(dbsplnr);
	statshr.ButArrViewActive = evalButArrViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavLayout::refreshArr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstArr = 0;

	// feedFLstArr
	feedFLstArr.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRARR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstArr.appendRefTitles(rec->ref, StubPlnr::getStubArrStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTARR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstArr(dbsplnr, moditems);
};

void PnlPlnrNavLayout::refreshLstAri(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstAriAvail = evalLstAriAvail(dbsplnr);
	statshr.ButAriViewActive = evalButAriViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavLayout::refreshAri(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstAri = 0;

	// feedFLstAri
	feedFLstAri.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRARI, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstAri.appendRefTitles(rec->ref, StubPlnr::getStubAriStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTARI);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstAri(dbsplnr, moditems);
};

void PnlPlnrNavLayout::refreshLstRtc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRtcAvail = evalLstRtcAvail(dbsplnr);
	statshr.ButRtcViewActive = evalButRtcViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavLayout::refreshRtc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstRtc = 0;

	// feedFLstRtc
	feedFLstRtc.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRRTC, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstRtc.appendRefTitles(rec->ref, StubPlnr::getStubRtcStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTRTC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstRtc(dbsplnr, moditems);
};

void PnlPlnrNavLayout::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlPlnrNavLayout::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	refreshLstTpo(dbsplnr, moditems);
	refreshLstArr(dbsplnr, moditems);
	refreshLstAri(dbsplnr, moditems);
	refreshLstRtc(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavLayout::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTTPOVIEWCLICK) {
					handleDpchAppDoButTpoViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTPONEWCRDCLICK) {
					handleDpchAppDoButTpoNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARRVIEWCLICK) {
					handleDpchAppDoButArrViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARIVIEWCLICK) {
					handleDpchAppDoButAriViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRTCVIEWCLICK) {
					handleDpchAppDoButRtcViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavLayout::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavLayout::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTTPO)) {
		contiac.numFLstTpo = _contiac->numFLstTpo;
		refreshLstTpo(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTARR)) {
		contiac.numFLstArr = _contiac->numFLstArr;
		refreshLstArr(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTARI)) {
		contiac.numFLstAri = _contiac->numFLstAri;
		refreshLstAri(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTRTC)) {
		contiac.numFLstRtc = _contiac->numFLstRtc;
		refreshLstRtc(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavLayout::handleDpchAppDoButTpoViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTpoAvail && statshr.ButTpoViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstTpo.getRefByNum(contiac.numFLstTpo), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrTpo", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrTpo");
	};
};

void PnlPlnrNavLayout::handleDpchAppDoButTpoNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrTpo", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrTpo");
};

void PnlPlnrNavLayout::handleDpchAppDoButArrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstArrAvail && statshr.ButArrViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstArr.getRefByNum(contiac.numFLstArr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrArr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrArr");
	};
};

void PnlPlnrNavLayout::handleDpchAppDoButAriViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstAriAvail && statshr.ButAriViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstAri.getRefByNum(contiac.numFLstAri), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrAri", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrAri");
	};
};

void PnlPlnrNavLayout::handleDpchAppDoButRtcViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRtcAvail && statshr.ButRtcViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstRtc.getRefByNum(contiac.numFLstRtc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrRtc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrRtc");
	};
};

void PnlPlnrNavLayout::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallPlnrHusrRunvMod_crdUsrEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlPlnrNavLayout::handleCallPlnrHusrRunvMod_crdUsrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVCard::CRDPLNRTPO) {
		refreshTpo(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRARR) {
		refreshArr(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRARI) {
		refreshAri(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRRTC) {
		refreshRtc(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


