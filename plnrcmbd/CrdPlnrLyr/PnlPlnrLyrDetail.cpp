/**
  * \file PnlPlnrLyrDetail.cpp
  * job handler for job PnlPlnrLyrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrLyrDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrLyrDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrLyrDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrLyrDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrLyrDetail::PnlPlnrLyrDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRLYRDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupHkt.tag = "FeedFPupHkt";
	VecPlnrVMLayerHkTbl::fillFeed(ixPlnrVLocale, feedFPupHkt);
	feedFPupTty.tag = "FeedFPupTty";
	VecPlnrVMLayerTtype::fillFeed(ixPlnrVLocale, feedFPupTty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMLayerBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFLYR, jref);
};

PnlPlnrLyrDetail::~PnlPlnrLyrDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrLyrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupHkt, &feedFPupTty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrLyrDetail::refreshRecLyr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMLayer* _recLyr = NULL;

	if (dbsplnr->tblplnrmlayer->loadRecByRef(recLyr.ref, &_recLyr)) {
		recLyr = *_recLyr;
		delete _recLyr;
	} else recLyr = PlnrMLayer();

	dirty = false;

	continf.TxtSrf = recLyr.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recLyr.ixVBasetype);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recLyr.hkIxVTbl);
	continf.TxtMat = StubPlnr::getStubMatStd(dbsplnr, recLyr.refPlnrMMaterial, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupTty = feedFPupTty.getNumByIx(recLyr.ixVTtype);
	continf.TxtFlr = StubPlnr::getStubLvlStd(dbsplnr, recLyr.flrRefPlnrMLevel, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCtr = StubPlnr::getStubLvlStd(dbsplnr, recLyr.ctrRefPlnrMLevel, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCei = StubPlnr::getStubLvlStd(dbsplnr, recLyr.ceilRefPlnrMLevel, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfT = recLyr.t;
	contiac.TxfMl = recLyr.ML;

	statshr.ButMatViewAvail = evalButMatViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrLyrDetail::refreshRecLyrJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMLayer* _recLyrJ = NULL;

	if (dbsplnr->tblplnrjmlayer->loadRecByRef(recLyrJ.ref, &_recLyrJ)) {
		recLyrJ = *_recLyrJ;
		delete _recLyrJ;
	} else recLyrJ = PlnrJMLayer();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrLyrDetail::refreshRecLyrJmat(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMLayerMaterial* _recLyrJmat = NULL;

	if (dbsplnr->tblplnrjmlayermaterial->loadRecByRef(recLyrJmat.ref, &_recLyrJmat)) {
		recLyrJmat = *_recLyrJmat;
		delete _recLyrJmat;
	} else recLyrJmat = PlnrJMLayerMaterial();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrLyrDetail::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbsplnr);
	statshr.ButSaveActive = evalButSaveActive(dbsplnr);
// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrLyrDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFLYR) {
		recLyr.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFLYR, jref);
		refreshRecLyr(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrLyrDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMATVIEWCLICK) {
					handleDpchAppDoButMatViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrLyrDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrLyrDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::NUMFPUPTTY, ContIac::TXFT, ContIac::TXFML})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPTTY)) contiac.numFPupTty = _contiac->numFPupTty;
		if (has(diffitems, ContIac::TXFT)) contiac.TxfT = _contiac->TxfT;
		if (has(diffitems, ContIac::TXFML)) contiac.TxfMl = _contiac->TxfMl;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrLyrDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrLyrDetail::handleDpchAppDoButHkuViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButHkuViewClick --- INSERT
};

void PnlPlnrLyrDetail::handleDpchAppDoButMatViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButMatViewClick --- INSERT
};

void PnlPlnrLyrDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRUPD_REFEQ) {
		call->abort = handleCallPlnrLyrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRJMOD_LYREQ) {
		call->abort = handleCallPlnrLyrJMod_lyrEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRJMATMOD_LYREQ) {
		call->abort = handleCallPlnrLyrJmatMod_lyrEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrLyrDetail::handleCallPlnrLyrUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrLyrUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrLyrDetail::handleCallPlnrLyrJMod_lyrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrLyrJMod_lyrEq --- INSERT
	return retval;
};

bool PnlPlnrLyrDetail::handleCallPlnrLyrJmatMod_lyrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrLyrJmatMod_lyrEq --- INSERT
	return retval;
};


