/**
  * \file PnlPlnrPrjDetail.cpp
  * job handler for job PnlPlnrPrjDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrPrjDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrPrjDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrPrjDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrPrjDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrPrjDetail::PnlPlnrPrjDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRPRJDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecPlnrVMProjectState::fillFeed(ixPlnrVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFPRJ, jref);
};

PnlPlnrPrjDetail::~PnlPlnrPrjDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrPrjDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFPupJ, &feedFPupSte, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrPrjDetail::refreshJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ListPlnrJMProjectState prjJstes;
	PlnrJMProjectState* prjJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsplnr->tblplnrjmprojectstate->loadRstByPrj(recPrj.ref, false, prjJstes);

	for (unsigned int i=0;i<prjJstes.nodes.size();i++) {
		prjJste = prjJstes.nodes[i];

		s = "";
		if (prjJste->x1Start != 0) {
			s = Ftm::date(prjJste->x1Start) + " -";
			if ((i+2) < prjJstes.nodes.size()) if (prjJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::date(prjJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecPlnrVTag::getTitle(VecPlnrVTag::ALWAYS, ixPlnrVLocale) + ")";
		feedFPupJ.appendRefTitles(prjJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPrjJste(dbsplnr, moditems);

};

void PnlPlnrPrjDetail::refreshRecPrj(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	PlnrMProject* _recPrj = NULL;

	if (dbsplnr->tblplnrmproject->loadRecByRef(recPrj.ref, &_recPrj)) {
		recPrj = *_recPrj;
		delete _recPrj;
	} else recPrj = PlnrMProject();

	dirty = false;

	recPrjJste.ref = recPrj.refJState;
	xchg->removeClstns(VecPlnrVCall::CALLPLNRPRJJSTEMOD_PRJEQ, jref);
	if (recPrj.ref != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRPRJJSTEMOD_PRJEQ, jref, Clstn::VecVJobmask::ALL, 0, recPrj.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recPrj.Title;
	contiac.TxfCmt = recPrj.Comment;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsplnr, moditems);

};

void PnlPlnrPrjDetail::refreshRecPrjJste(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	PlnrJMProjectState* _recPrjJste = NULL;

	if (dbsplnr->tblplnrjmprojectstate->loadRecByRef(recPrjJste.ref, &_recPrjJste)) {
		recPrjJste = *_recPrjJste;
		delete _recPrjJste;
	} else recPrjJste = PlnrJMProjectState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPrjJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recPrjJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrPrjDetail::refresh(
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

void PnlPlnrPrjDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFPRJ) {
		recPrj.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);
		refreshRecPrj(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrPrjDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJDETAILDO) {
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

void PnlPlnrPrjDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrPrjDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::NUMFPUPSTE, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPrjJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPrjJste(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrPrjDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrPrjDetail::handleDpchAppDoButJEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlPlnrPrjDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRPRJUPD_REFEQ) {
		call->abort = handleCallPlnrPrjUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRJJSTEMOD_PRJEQ) {
		call->abort = handleCallPlnrPrjJsteMod_prjEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrPrjDetail::handleCallPlnrPrjUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrPrjUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrPrjDetail::handleCallPlnrPrjJsteMod_prjEq(
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


