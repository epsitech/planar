/**
  * \file PnlPlnrPrsDetail.cpp
  * job handler for job PnlPlnrPrsDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrPrsDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrPrsDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrPrsDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrPrsDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrPrsDetail::PnlPlnrPrsDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRPRSDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstDrv.tag = "FeedFLstDrv";
	VecPlnrWMPersonDerivate::fillFeed(ixPlnrVLocale, feedFLstDrv);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
	VecPlnrVMPersonSex::fillFeed(ixPlnrVLocale, feedFPupSex);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFPRS, jref);
};

PnlPlnrPrsDetail::~PnlPlnrPrsDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJ, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrPrsDetail::refreshJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ListPlnrJMPersonLastname prsJlnms;
	PlnrJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsplnr->tblplnrjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i=0;i<prsJlnms.nodes.size();i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecPlnrVTag::getTitle(VecPlnrVTag::ALWAYS, ixPlnrVLocale) + ")";
		feedFPupJ.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPrsJlnm(dbsplnr, moditems);

};

void PnlPlnrPrsDetail::refreshTxtDrv(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstDrv.size();i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecPlnrWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlPlnrPrsDetail::refreshRecPrs(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	PlnrMPerson* _recPrs = NULL;

	if (dbsplnr->tblplnrmperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = PlnrMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	xchg->removeClstns(VecPlnrVCall::CALLPLNRPRSJLNMMOD_PRSEQ, jref);
	if (recPrs.ref != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, recPrs.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecPlnrWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.Tel;
	contiac.TxfEml = recPrs.Eml;
	contiac.TxfSal = recPrs.Salutation;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsplnr, moditems);
	refreshTxtDrv(dbsplnr, moditems);

};

void PnlPlnrPrsDetail::refreshRecPrsJlnm(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	PlnrJMPersonLastname* _recPrsJlnm = NULL;

	if (dbsplnr->tblplnrjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = PlnrJMPersonLastname();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.ButJEditAvail = evalButJEditAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrPrsDetail::refresh(
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

void PnlPlnrPrsDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRS, jref);
		refreshRecPrs(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrPrsDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrPrsDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPrsJlnm.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPrsJlnm(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbsplnr, moditems);
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrPrsDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrPrsDetail::handleDpchAppDoButJEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlPlnrPrsDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSUPD_REFEQ) {
		call->abort = handleCallPlnrPrsUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallPlnrPrsJlnmMod_prsEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrPrsDetail::handleCallPlnrPrsUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrPrsUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrPrsDetail::handleCallPlnrPrsJlnmMod_prsEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbsplnr, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


