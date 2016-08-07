/**
  * \file PnlPlnrDomDetail.cpp
  * job handler for job PnlPlnrDomDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDomDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDomDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDomDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDomDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDomDetail::PnlPlnrDomDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDOMDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMDomainBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDOM, jref);
};

PnlPlnrDomDetail::~PnlPlnrDomDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDomDetail::getNewDpchEng(
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

void PnlPlnrDomDetail::refreshTxtFlr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtFlr --- BEGIN
	ubigint refLvl = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLevel WHERE sref = '" + contiac.TxfFlr + "'", refLvl);

	continf.TxtFlr = StubPlnr::getStubLvlStd(dbsplnr, refLvl, ixPlnrVLocale);

	statshr.TxfFlrValid = (refLvl != 0);
// IP refreshTxtFlr --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtCei(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtCei --- BEGIN
	ubigint refLvl = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLevel WHERE sref = '" + contiac.TxfCei + "'", refLvl);

	continf.TxtCei = StubPlnr::getStubLvlStd(dbsplnr, refLvl, ixPlnrVLocale);

	statshr.TxfCeiValid = (refLvl != 0);
// IP refreshTxtCei --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtVx1(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtVx1 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfVx1 + "'", refVtx);

	continf.TxtVx1 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfVx1Valid = (refVtx != 0);
// IP refreshTxtVx1 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtLg1(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtLg1 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfLg1 + "'", refLgd);

	continf.TxtLg1 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfLg1Valid = (refLgd != 0);
// IP refreshTxtLg1 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtVx2(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtVx2 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfVx2 + "'", refVtx);

	continf.TxtVx2 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfVx2Valid = (refVtx != 0);
// IP refreshTxtVx2 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtLg2(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtLg2 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfLg2 + "'", refLgd);

	continf.TxtLg2 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfLg2Valid = (refLgd != 0);
// IP refreshTxtLg2 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtVx3(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtVx3 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfVx3 + "'", refVtx);

	continf.TxtVx3 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfVx3Valid = (refVtx != 0);
// IP refreshTxtVx3 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtLg3(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtLg3 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfLg3 + "'", refLgd);

	continf.TxtLg3 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfLg3Valid = (refLgd != 0);
// IP refreshTxtLg3 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtVx4(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtVx4 --- BEGIN
	ubigint refVtx = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE sref = '" + contiac.TxfVx4 + "'", refVtx);

	continf.TxtVx4 = StubPlnr::getStubVtxStd(dbsplnr, refVtx, ixPlnrVLocale);

	statshr.TxfVx4Valid = (refVtx != 0);
// IP refreshTxtVx4 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshTxtLg4(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtLg4 --- BEGIN
	ubigint refLgd = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE sref = '" + contiac.TxfLg4 + "'", refLgd);

	continf.TxtLg4 = StubPlnr::getStubLgdStd(dbsplnr, refLgd, ixPlnrVLocale);

	statshr.TxfLg4Valid = (refLgd != 0);
// IP refreshTxtLg4 --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrDomDetail::refreshRecDom(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMDomain* _recDom = NULL;

	if (dbsplnr->tblplnrmdomain->loadRecByRef(recDom.ref, &_recDom)) {
		recDom = *_recDom;
		delete _recDom;
	} else recDom = PlnrMDomain();

	dirty = false;

	continf.TxtSrf = recDom.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recDom.ixVBasetype);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recDom.dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfFlr = recDom.flrSrefPlnrMLevel;
	contiac.TxfCei = recDom.ceilSrefPlnrMLevel;
	contiac.TxfVx1 = recDom.vtx1SrefPlnrMVertex;
	contiac.TxfLg1 = recDom.lgd1SrefPlnrMLineguide;
	contiac.TxfVx2 = recDom.vtx2SrefPlnrMVertex;
	contiac.TxfLg2 = recDom.lgd2SrefPlnrMLineguide;
	contiac.TxfVx3 = recDom.vtx3SrefPlnrMVertex;
	contiac.TxfLg3 = recDom.lgd3SrefPlnrMLineguide;
	contiac.TxfVx4 = recDom.vtx4SrefPlnrMVertex;
	contiac.TxfLg4 = recDom.lgd4SrefPlnrMLineguide;
	contiac.TxfDx = recDom.dx;
	contiac.TxfDy = recDom.dy;
	contiac.TxfDxy = recDom.dxy;
	contiac.TxfDz = recDom.dz;

	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtFlr(dbsplnr, moditems);
	refreshTxtCei(dbsplnr, moditems);
	refreshTxtVx1(dbsplnr, moditems);
	refreshTxtLg1(dbsplnr, moditems);
	refreshTxtVx2(dbsplnr, moditems);
	refreshTxtLg2(dbsplnr, moditems);
	refreshTxtVx3(dbsplnr, moditems);
	refreshTxtLg3(dbsplnr, moditems);
	refreshTxtVx4(dbsplnr, moditems);
	refreshTxtLg4(dbsplnr, moditems);

};

void PnlPlnrDomDetail::refreshRecDomJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMDomain* _recDomJ = NULL;

	if (dbsplnr->tblplnrjmdomain->loadRecByRef(recDomJ.ref, &_recDomJ)) {
		recDomJ = *_recDomJ;
		delete _recDomJ;
	} else recDomJ = PlnrJMDomain();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDomDetail::refresh(
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

void PnlPlnrDomDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDOM) {
		recDom.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDOM, jref);
		refreshRecDom(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDomDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDO) {
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

void PnlPlnrDomDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDomDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFDX, ContIac::TXFDY, ContIac::TXFDXY, ContIac::TXFDZ})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFDX)) contiac.TxfDx = _contiac->TxfDx;
		if (has(diffitems, ContIac::TXFDY)) contiac.TxfDy = _contiac->TxfDy;
		if (has(diffitems, ContIac::TXFDXY)) contiac.TxfDxy = _contiac->TxfDxy;
		if (has(diffitems, ContIac::TXFDZ)) contiac.TxfDz = _contiac->TxfDz;
	};

	if (has(diffitems, ContIac::TXFFLR)) {
		contiac.TxfFlr = _contiac->TxfFlr;
		refreshTxtFlr(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFCEI)) {
		contiac.TxfCei = _contiac->TxfCei;
		refreshTxtCei(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFVX1)) {
		contiac.TxfVx1 = _contiac->TxfVx1;
		refreshTxtVx1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFLG1)) {
		contiac.TxfLg1 = _contiac->TxfLg1;
		refreshTxtLg1(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFVX2)) {
		contiac.TxfVx2 = _contiac->TxfVx2;
		refreshTxtVx2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFLG2)) {
		contiac.TxfLg2 = _contiac->TxfLg2;
		refreshTxtLg2(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFVX3)) {
		contiac.TxfVx3 = _contiac->TxfVx3;
		refreshTxtVx3(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFLG3)) {
		contiac.TxfLg3 = _contiac->TxfLg3;
		refreshTxtLg3(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFVX4)) {
		contiac.TxfVx4 = _contiac->TxfVx4;
		refreshTxtVx4(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFLG4)) {
		contiac.TxfLg4 = _contiac->TxfLg4;
		refreshTxtLg4(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrDomDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrDomDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrDomDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDOMUPD_REFEQ) {
		call->abort = handleCallPlnrDomUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDOMJMOD_DOMEQ) {
		call->abort = handleCallPlnrDomJMod_domEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDomDetail::handleCallPlnrDomUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDomUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrDomDetail::handleCallPlnrDomJMod_domEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDomJMod_domEq --- INSERT
	return retval;
};


