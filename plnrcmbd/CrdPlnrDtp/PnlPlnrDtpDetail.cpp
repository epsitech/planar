/**
  * \file PnlPlnrDtpDetail.cpp
  * job handler for job PnlPlnrDtpDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDtpDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDtpDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDtpDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDtpDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDtpDetail::PnlPlnrDtpDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDTPDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupAty.tag = "FeedFPupAty";
	VecPlnrVMDeviceAligntype::fillFeed(ixPlnrVLocale, feedFPupAty);
	feedFPupMty.tag = "FeedFPupMty";
	VecPlnrVMDeviceModtype::fillFeed(ixPlnrVLocale, feedFPupMty);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDTP, jref);
};

PnlPlnrDtpDetail::~PnlPlnrDtpDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDtpDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAty, &feedFPupMty, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrDtpDetail::refreshTxtAv1(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtAv1 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfAv1 + "'", refVtx);

	continf.TxtAv1 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfAv1Valid = (refVtx != 0);
// IP refreshTxtAv1 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDtpDetail::refreshTxtPv1(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtPv1 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfPv1 + "'", refVtx);

	continf.TxtPv1 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfPv1Valid = (refVtx != 0);
// IP refreshTxtPv1 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDtpDetail::refreshTxtAv2(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtAv2 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfAv2 + "'", refVtx);

	continf.TxtAv2 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfAv2Valid = (refVtx != 0);
// IP refreshTxtAv2 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDtpDetail::refreshTxtPv2(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtPv2 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfPv2 + "'", refVtx);

	continf.TxtPv2 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfPv2Valid = (refVtx != 0);
// IP refreshTxtPv2 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDtpDetail::refreshRecDev(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMDevice* _recDev = NULL;

	if (dbsplnr->tblplnrmdevice->loadRecByRef(recDev.ref, &_recDev)) {
		recDev = *_recDev;
		delete _recDev;
	} else recDev = PlnrMDevice();

	dirty = false;

	continf.TxtSrf = recDev.sref;
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recDev.dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSup = StubPlnr::getStubDevStd(dbsplnr, recDev.supRefPlnrMDevice, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTpl = StubPlnr::getStubDevStd(dbsplnr, recDev.tplRefPlnrMDevice, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupMty = feedFPupMty.getNumByIx(recDev.ixVModtype);
	contiac.numFPupAty = feedFPupAty.getNumByIx(recDev.ixVAligntype);
	contiac.TxfAv1 = recDev.av1SrefPlnrMVertex;
	contiac.TxfPv1 = recDev.pav1SrefPlnrMVertex;
	contiac.TxfAv2 = recDev.av2SrefPlnrMVertex;
	contiac.TxfPv2 = recDev.pav2SrefPlnrMVertex;
	contiac.TxfX = to_string(recDev.x);
	contiac.TxfY = to_string(recDev.y);
	contiac.TxfPhi = to_string(recDev.phi);
	contiac.TxfCmt = recDev.Comment;

	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtAv1(dbsplnr, moditems);
	refreshTxtPv1(dbsplnr, moditems);
	refreshTxtAv2(dbsplnr, moditems);
	refreshTxtPv2(dbsplnr, moditems);

};

void PnlPlnrDtpDetail::refreshRecDevJmod(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMDeviceModtype* _recDevJmod = NULL;

	if (dbsplnr->tblplnrjmdevicemodtype->loadRecByRef(recDevJmod.ref, &_recDevJmod)) {
		recDevJmod = *_recDevJmod;
		delete _recDevJmod;
	} else recDevJmod = PlnrJMDeviceModtype();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDtpDetail::refresh(
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

void PnlPlnrDtpDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDTP) {
		recDev.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref);
		refreshRecDev(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDtpDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrDtpDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDtpDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPMTY, ContIac::NUMFPUPATY, ContIac::TXFX, ContIac::TXFY, ContIac::TXFPHI, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPMTY)) contiac.numFPupMty = _contiac->numFPupMty;
		if (has(diffitems, ContIac::NUMFPUPATY)) contiac.numFPupAty = _contiac->numFPupAty;
		if (has(diffitems, ContIac::TXFX)) contiac.TxfX = _contiac->TxfX;
		if (has(diffitems, ContIac::TXFY)) contiac.TxfY = _contiac->TxfY;
		if (has(diffitems, ContIac::TXFPHI)) contiac.TxfPhi = _contiac->TxfPhi;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFAV1)) {
		contiac.TxfAv1 = _contiac->TxfAv1;
		refreshTxtAv1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFPV1)) {
		contiac.TxfPv1 = _contiac->TxfPv1;
		refreshTxtPv1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAV2)) {
		contiac.TxfAv2 = _contiac->TxfAv2;
		refreshTxtAv2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFPV2)) {
		contiac.TxfPv2 = _contiac->TxfPv2;
		refreshTxtPv2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrDtpDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrDtpDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrDtpDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVUPD_REFEQ) {
		call->abort = handleCallPlnrDevUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVJMODMOD_DEVEQ) {
		call->abort = handleCallPlnrDevJmodMod_devEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDtpDetail::handleCallPlnrDevUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDevUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrDtpDetail::handleCallPlnrDevJmodMod_devEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDevJmodMod_devEq --- INSERT
	return retval;
};


