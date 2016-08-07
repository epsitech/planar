/**
  * \file PnlPlnrRtcDetail.cpp
  * job handler for job PnlPlnrRtcDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrRtcDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrRtcDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrRtcDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrRtcDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrRtcDetail::PnlPlnrRtcDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRRTCDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupHkt.tag = "FeedFPupHkt";
	VecPlnrVMReticleHkTbl::fillFeed(ixPlnrVLocale, feedFPupHkt);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFRTC, jref);
};

PnlPlnrRtcDetail::~PnlPlnrRtcDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrRtcDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupHkt, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrRtcDetail::refreshRecRtc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMReticle* _recRtc = NULL;

	if (dbsplnr->tblplnrmreticle->loadRecByRef(recRtc.ref, &_recRtc)) {
		recRtc = *_recRtc;
		delete _recRtc;
	} else recRtc = PlnrMReticle();

	dirty = false;

	continf.TxtSrf = recRtc.sref;
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recRtc.hkIxVTbl);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recRtc.refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtLyr = StubPlnr::getStubLyrStd(dbsplnr, recRtc.refPlnrMLayer, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfX0 = to_string(recRtc.x0);
	contiac.TxfY0 = to_string(recRtc.y0);
	contiac.TxfPhi = to_string(recRtc.phi);

	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	statshr.ButLyrViewAvail = evalButLyrViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrRtcDetail::refresh(
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

void PnlPlnrRtcDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFRTC) {
		recRtc.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFRTC, jref);
		refreshRecRtc(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrRtcDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLYRVIEWCLICK) {
					handleDpchAppDoButLyrViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrRtcDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrRtcDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFX0, ContIac::TXFY0, ContIac::TXFPHI})) {
		if (has(diffitems, ContIac::TXFX0)) contiac.TxfX0 = _contiac->TxfX0;
		if (has(diffitems, ContIac::TXFY0)) contiac.TxfY0 = _contiac->TxfY0;
		if (has(diffitems, ContIac::TXFPHI)) contiac.TxfPhi = _contiac->TxfPhi;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrRtcDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrRtcDetail::handleDpchAppDoButHkuViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButHkuViewClick --- INSERT
};

void PnlPlnrRtcDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrRtcDetail::handleDpchAppDoButLyrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButLyrViewClick --- INSERT
};

void PnlPlnrRtcDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRRTCUPD_REFEQ) {
		call->abort = handleCallPlnrRtcUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrRtcDetail::handleCallPlnrRtcUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrRtcUpd_refEq --- INSERT
	return retval;
};


