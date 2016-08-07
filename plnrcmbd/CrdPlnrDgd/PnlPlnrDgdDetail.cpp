/**
  * \file PnlPlnrDgdDetail.cpp
  * job handler for job PnlPlnrDgdDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDgdDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDgdDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDgdDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDgdDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDgdDetail::PnlPlnrDgdDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDGDDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMDomaingdBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDGD, jref);
};

PnlPlnrDgdDetail::~PnlPlnrDgdDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDgdDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrDgdDetail::refreshTxtLvl(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtLvl --- BEGIN
	ubigint refLvl = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLevel WHERE sref = '" + contiac.TxfLvl + "'", refLvl);

	continf.TxtLvl = StubPlnr::getStubLvlStd(dbsplnr, refLvl, ixPlnrVLocale);

	statshr.TxfLvlValid = (refLvl != 0);
// IP refreshTxtLvl --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDgdDetail::refreshTxtAv1(
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

void PnlPlnrDgdDetail::refreshTxtAv2(
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

void PnlPlnrDgdDetail::refreshTxtAl1(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtAl1 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfAl1 + "'", refLgd);

	continf.TxtAl1 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfAl1Valid = (refLgd != 0);
// IP refreshTxtAl1 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDgdDetail::refreshTxtAl2(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtAl2 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfAl2 + "'", refLgd);

	continf.TxtAl2 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfAl2Valid = (refLgd != 0);
// IP refreshTxtAl2 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDgdDetail::refreshTxtAgd(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtAgd --- BEGIN
	ubigint refAgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMArcguide WHERE sref = '" + contiac.TxfAgd + "'", refAgd);

	continf.TxtAgd = StubPlnr::getStubAgdStd(dbsplnr, refAgd, ixPlnrVLocale);

	statshr.TxfAgdValid = (refAgd != 0);
// IP refreshTxtAgd --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDgdDetail::refreshRecDgd(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMDomaingd* _recDgd = NULL;

	if (dbsplnr->tblplnrmdomaingd->loadRecByRef(recDgd.ref, &_recDgd)) {
		recDgd = *_recDgd;
		delete _recDgd;
	} else recDgd = PlnrMDomaingd();

	dirty = false;

	continf.TxtSrf = recDgd.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recDgd.ixVBasetype);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recDgd.dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfLvl = recDgd.srefPlnrMLevel;
	contiac.TxfAv1 = recDgd.av1SrefPlnrMVertex;
	contiac.TxfAv2 = recDgd.av2SrefPlnrMVertex;
	contiac.TxfAl1 = recDgd.al1SrefPlnrMLineguide;
	contiac.TxfAl2 = recDgd.al2SrefPlnrMLineguide;
	contiac.TxfAgd = recDgd.srefPlnrMArcguide;
	contiac.TxfD = recDgd.d;
	contiac.TxfDph = recDgd.dphi;

	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtLvl(dbsplnr, moditems);
	refreshTxtAv1(dbsplnr, moditems);
	refreshTxtAv2(dbsplnr, moditems);
	refreshTxtAl1(dbsplnr, moditems);
	refreshTxtAl2(dbsplnr, moditems);
	refreshTxtAgd(dbsplnr, moditems);

};

void PnlPlnrDgdDetail::refreshRecDgdJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMDomaingd* _recDgdJ = NULL;

	if (dbsplnr->tblplnrjmdomaingd->loadRecByRef(recDgdJ.ref, &_recDgdJ)) {
		recDgdJ = *_recDgdJ;
		delete _recDgdJ;
	} else recDgdJ = PlnrJMDomaingd();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDgdDetail::refresh(
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

void PnlPlnrDgdDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDGD) {
		recDgd.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDGD, jref);
		refreshRecDgd(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDgdDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDO) {
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

void PnlPlnrDgdDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDgdDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFD, ContIac::TXFDPH})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFD)) contiac.TxfD = _contiac->TxfD;
		if (has(diffitems, ContIac::TXFDPH)) contiac.TxfDph = _contiac->TxfDph;
	};

	if (has(diffitems, ContIac::TXFLVL)) {
		contiac.TxfLvl = _contiac->TxfLvl;
		refreshTxtLvl(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAV1)) {
		contiac.TxfAv1 = _contiac->TxfAv1;
		refreshTxtAv1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAV2)) {
		contiac.TxfAv2 = _contiac->TxfAv2;
		refreshTxtAv2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAL1)) {
		contiac.TxfAl1 = _contiac->TxfAl1;
		refreshTxtAl1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAL2)) {
		contiac.TxfAl2 = _contiac->TxfAl2;
		refreshTxtAl2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFAGD)) {
		contiac.TxfAgd = _contiac->TxfAgd;
		refreshTxtAgd(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrDgdDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrDgdDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrDgdDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDGDUPD_REFEQ) {
		call->abort = handleCallPlnrDgdUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDGDJMOD_DGDEQ) {
		call->abort = handleCallPlnrDgdJMod_dgdEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDgdDetail::handleCallPlnrDgdUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDgdUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrDgdDetail::handleCallPlnrDgdJMod_dgdEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDgdJMod_dgdEq --- INSERT
	return retval;
};


