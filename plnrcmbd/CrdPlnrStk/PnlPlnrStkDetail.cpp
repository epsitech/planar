/**
  * \file PnlPlnrStkDetail.cpp
  * job handler for job PnlPlnrStkDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrStkDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrStkDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrStkDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrStkDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrStkDetail::PnlPlnrStkDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRSTKDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstLyr.tag = "FeedFLstLyr";
	feedFPupCal.tag = "FeedFPupCal";
	VecPlnrVMStackCeilAligntype::fillFeed(ixPlnrVLocale, feedFPupCal);
	feedFPupFal.tag = "FeedFPupFal";
	VecPlnrVMStackFlrAligntype::fillFeed(ixPlnrVLocale, feedFPupFal);
	feedFPupMty.tag = "FeedFPupMty";
	VecPlnrVMStackModtype::fillFeed(ixPlnrVLocale, feedFPupMty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMStackBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFSTK, jref);
};

PnlPlnrStkDetail::~PnlPlnrStkDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrStkDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstLyr, &feedFPupCal, &feedFPupFal, &feedFPupMty, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrStkDetail::refreshTxtFlr(
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

void PnlPlnrStkDetail::refreshTxtCil(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refreshTxtCil --- BEGIN
	ubigint refLvl = 0;

	dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLevel WHERE sref = '" + contiac.TxfCil + "'", refLvl);

	continf.TxtCil = StubPlnr::getStubLvlStd(dbsplnr, refLvl, ixPlnrVLocale);

	statshr.TxfCilValid = (refLvl != 0);
// IP refreshTxtCil --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrStkDetail::refreshLstLyr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.ButLyrViewAvail = evalButLyrViewAvail(dbsplnr);
	statshr.ButLyrViewActive = evalButLyrViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrStkDetail::refreshLyr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstLyr = 0;

	// feedFLstLyr
	feedFLstLyr.clear();

	StrMod::stringToVector(contiac.TxfLyr, ss);

// IP refreshLyr.validate --- INSERT

	// statshr
	statshr.TxfLyrValid = (ss.size() == feedFLstLyr.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrStkDetail::refreshRecStk(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMStack* _recStk = NULL;

	if (dbsplnr->tblplnrmstack->loadRecByRef(recStk.ref, &_recStk)) {
		recStk = *_recStk;
		delete _recStk;
	} else recStk = PlnrMStack();

	dirty = false;

	continf.TxtSrf = recStk.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recStk.ixVBasetype);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recStk.dsnRefPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupMty = feedFPupMty.getNumByIx(recStk.ixVModtype);
	contiac.numFPupFal = feedFPupFal.getNumByIx(recStk.ixVFlrAligntype);
	contiac.TxfFlr = recStk.flrSrefPlnrMLevel;
	contiac.TxfZfl = to_string(recStk.zFlr);
	contiac.numFPupCal = feedFPupCal.getNumByIx(recStk.ixVCeilAligntype);
	contiac.TxfCil = recStk.ceilSrefPlnrMLevel;
	contiac.TxfZci = to_string(recStk.zCeil);
	contiac.TxfN = recStk.N;

	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtFlr(dbsplnr, moditems);
	refreshTxtCil(dbsplnr, moditems);
	refreshLyr(dbsplnr, moditems);

};

void PnlPlnrStkDetail::refreshRecStkJn(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMStackN* _recStkJn = NULL;

	if (dbsplnr->tblplnrjmstackn->loadRecByRef(recStkJn.ref, &_recStkJn)) {
		recStkJn = *_recStkJn;
		delete _recStkJn;
	} else recStkJn = PlnrJMStackN();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrStkDetail::refreshRecStkJmod(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMStackModtype* _recStkJmod = NULL;

	if (dbsplnr->tblplnrjmstackmodtype->loadRecByRef(recStkJmod.ref, &_recStkJmod)) {
		recStkJmod = *_recStkJmod;
		delete _recStkJmod;
	} else recStkJmod = PlnrJMStackModtype();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrStkDetail::refresh(
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

void PnlPlnrStkDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSTK) {
		recStk.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref);
		refreshRecStk(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrStkDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLYRVIEWCLICK) {
					handleDpchAppDoButLyrViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrStkDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrStkDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::NUMFPUPMTY, ContIac::NUMFPUPFAL, ContIac::TXFZFL, ContIac::NUMFPUPCAL, ContIac::TXFZCI, ContIac::TXFN})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::NUMFPUPMTY)) contiac.numFPupMty = _contiac->numFPupMty;
		if (has(diffitems, ContIac::NUMFPUPFAL)) contiac.numFPupFal = _contiac->numFPupFal;
		if (has(diffitems, ContIac::TXFZFL)) contiac.TxfZfl = _contiac->TxfZfl;
		if (has(diffitems, ContIac::NUMFPUPCAL)) contiac.numFPupCal = _contiac->numFPupCal;
		if (has(diffitems, ContIac::TXFZCI)) contiac.TxfZci = _contiac->TxfZci;
		if (has(diffitems, ContIac::TXFN)) contiac.TxfN = _contiac->TxfN;
	};

	if (has(diffitems, ContIac::TXFFLR)) {
		contiac.TxfFlr = _contiac->TxfFlr;
		refreshTxtFlr(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFCIL)) {
		contiac.TxfCil = _contiac->TxfCil;
		refreshTxtCil(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFLYR)) {
		contiac.TxfLyr = _contiac->TxfLyr;
		refreshLyr(dbsplnr, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTLYR)) {
		contiac.numFLstLyr = _contiac->numFLstLyr;
		refreshLstLyr(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrStkDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrStkDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrStkDetail::handleDpchAppDoButLyrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButLyrViewClick --- INSERT
};

void PnlPlnrStkDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKUPD_REFEQ) {
		call->abort = handleCallPlnrStkUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKJNMOD_STKEQ) {
		call->abort = handleCallPlnrStkJnMod_stkEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKJMODMOD_STKEQ) {
		call->abort = handleCallPlnrStkJmodMod_stkEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrStkDetail::handleCallPlnrStkUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrStkUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrStkDetail::handleCallPlnrStkJnMod_stkEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrStkJnMod_stkEq --- INSERT
	return retval;
};

bool PnlPlnrStkDetail::handleCallPlnrStkJmodMod_stkEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrStkJmodMod_stkEq --- INSERT
	return retval;
};


