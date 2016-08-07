/**
  * \file PnlPlnrDsnDetail.cpp
  * job handler for job PnlPlnrDsnDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDsnDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDsnDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDsnDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDsnDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDsnDetail::PnlPlnrDsnDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDSNDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstMty.tag = "FeedFLstMty";
	VecPlnrWMDesignModtype::fillFeed(ixPlnrVLocale, feedFLstMty);
	feedFPupDim.tag = "FeedFPupDim";
	VecPlnrVMDesignDim::fillFeed(ixPlnrVLocale, feedFPupDim);
	feedFPupRet.tag = "FeedFPupRet";
	VecPlnrVMDesignRefTbl::fillFeed(ixPlnrVLocale, feedFPupRet);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMDesignBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_MODEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDSN, jref);
};

PnlPlnrDsnDetail::~PnlPlnrDsnDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDsnDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstMty, &feedFPupDim, &feedFPupRet, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrDsnDetail::refreshTxtMty(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstMty.size();i++) ix |= feedFLstMty.getIxByNum(contiac.numsFLstMty[i]);
	continf.TxtMty = VecPlnrWMDesignModtype::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlPlnrDsnDetail::refreshRecDsn(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	PlnrMDesign* _recDsn = NULL;

	if (dbsplnr->tblplnrmdesign->loadRecByRef(recDsn.ref, &_recDsn)) {
		recDsn = *_recDsn;
		delete _recDsn;
	} else recDsn = PlnrMDesign();

	dirty = false;

	contiac.TxfTit = recDsn.Title;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recDsn.ixVBasetype);
	contiac.numFPupDim = feedFPupDim.getNumByIx(recDsn.ixVDim);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recDsn.refIxVTbl);
	continf.TxtPrj = StubPlnr::getStubPrjStd(dbsplnr, recDsn.refPlnrMProject, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstMty.clear();
	VecPlnrWMDesignModtype::getIcs(recDsn.ixWModtype, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstMty.push_back(feedFLstMty.getNumByIx(*it));
	continf.TxtMod = StubPlnr::getStubDsnStd(dbsplnr, recDsn.modRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtDrv = StubPlnr::getStubDsnStd(dbsplnr, recDsn.drvRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMaj = to_string(recDsn.Major);
	contiac.TxfSub = to_string(recDsn.Sub);
	contiac.TxfCmt = recDsn.Comment;

	statshr.ButPrjViewAvail = evalButPrjViewAvail(dbsplnr);
	statshr.ButModViewAvail = evalButModViewAvail(dbsplnr);
	statshr.ButDrvViewAvail = evalButDrvViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtMty(dbsplnr, moditems);

};

void PnlPlnrDsnDetail::refresh(
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

void PnlPlnrDsnDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDSN) {
		recDsn.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref);
		refreshRecDsn(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDsnDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMODVIEWCLICK) {
					handleDpchAppDoButModViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDRVVIEWCLICK) {
					handleDpchAppDoButDrvViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrDsnDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDsnDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::NUMFPUPTYP, ContIac::NUMFPUPDIM, ContIac::TXFMAJ, ContIac::TXFSUB, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPDIM)) contiac.numFPupDim = _contiac->numFPupDim;
		if (has(diffitems, ContIac::TXFMAJ)) contiac.TxfMaj = _contiac->TxfMaj;
		if (has(diffitems, ContIac::TXFSUB)) contiac.TxfSub = _contiac->TxfSub;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMSFLSTMTY)) {
		contiac.numsFLstMty = _contiac->numsFLstMty;
		refreshTxtMty(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrDsnDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrDsnDetail::handleDpchAppDoButReuViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButReuViewClick --- INSERT
};

void PnlPlnrDsnDetail::handleDpchAppDoButPrjViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButPrjViewClick --- INSERT
};

void PnlPlnrDsnDetail::handleDpchAppDoButModViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButModViewClick --- INSERT
};

void PnlPlnrDsnDetail::handleDpchAppDoButDrvViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDrvViewClick --- INSERT
};

void PnlPlnrDsnDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_DIMEQ) {
		call->abort = handleCallPlnrDsn_dimEq(dbsplnr, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_MODEQ) {
		call->abort = handleCallPlnrDsn_modEq(dbsplnr, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_TYPEQ) {
		call->abort = handleCallPlnrDsn_typEq(dbsplnr, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSNUPD_REFEQ) {
		call->abort = handleCallPlnrDsnUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDsnDetail::handleCallPlnrDsn_dimEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_dimEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.ixVDim == ixInv);
// IP handleCallPlnrDsn_dimEq --- END
	return retval;
};

bool PnlPlnrDsnDetail::handleCallPlnrDsn_modEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_modEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.modRefPlnrMDesign == refInv);
// IP handleCallPlnrDsn_modEq --- END
	return retval;
};

bool PnlPlnrDsnDetail::handleCallPlnrDsn_typEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_typEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.ixVBasetype == ixInv);
// IP handleCallPlnrDsn_typEq --- END
	return retval;
};

bool PnlPlnrDsnDetail::handleCallPlnrDsnUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDsnUpd_refEq --- INSERT
	return retval;
};


