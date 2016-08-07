/**
  * \file PnlPlnrTpoDetail.cpp
  * job handler for job PnlPlnrTpoDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrTpoDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrTpoDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrTpoDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrTpoDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrTpoDetail::PnlPlnrTpoDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRTPODETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecPlnrVMTapeoutState::fillFeed(ixPlnrVLocale, feedFPupSte);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecPlnrVMTapeoutBasetype::fillFeed(ixPlnrVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFTPO, jref);
};

PnlPlnrTpoDetail::~PnlPlnrTpoDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrTpoDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFPupJ, &feedFPupSte, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrTpoDetail::refreshJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ListPlnrJMTapeoutState tpoJstes;
	PlnrJMTapeoutState* tpoJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsplnr->tblplnrjmtapeoutstate->loadRstByTpo(recTpo.ref, false, tpoJstes);

	for (unsigned int i=0;i<tpoJstes.nodes.size();i++) {
		tpoJste = tpoJstes.nodes[i];

		s = "";
		if (tpoJste->x1Start != 0) {
			s = Ftm::date(tpoJste->x1Start) + " -";
			if ((i+2) < tpoJstes.nodes.size()) if (tpoJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::date(tpoJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecPlnrVTag::getTitle(VecPlnrVTag::ALWAYS, ixPlnrVLocale) + ")";
		feedFPupJ.appendRefTitles(tpoJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecTpoJste(dbsplnr, moditems);

};

void PnlPlnrTpoDetail::refreshRecTpo(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	PlnrMTapeout* _recTpo = NULL;

	if (dbsplnr->tblplnrmtapeout->loadRecByRef(recTpo.ref, &_recTpo)) {
		recTpo = *_recTpo;
		delete _recTpo;
	} else recTpo = PlnrMTapeout();

	dirty = false;

	recTpoJste.ref = recTpo.refJState;
	xchg->removeClstns(VecPlnrVCall::CALLPLNRTPOJSTEMOD_TPOEQ, jref);
	if (recTpo.ref != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRTPOJSTEMOD_TPOEQ, jref, Clstn::VecVJobmask::ALL, 0, recTpo.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recTpo.Title;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recTpo.ixVBasetype);
	contiac.TxfMaj = to_string(recTpo.Major);
	contiac.TxfSub = to_string(recTpo.Sub);
	contiac.ChkFli = recTpo.Hflip;
	contiac.TxfCmt = recTpo.Comment;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsplnr, moditems);

};

void PnlPlnrTpoDetail::refreshRecTpoJste(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	PlnrJMTapeoutState* _recTpoJste = NULL;

	if (dbsplnr->tblplnrjmtapeoutstate->loadRecByRef(recTpoJste.ref, &_recTpoJste)) {
		recTpoJste = *_recTpoJste;
		delete _recTpoJste;
	} else recTpoJste = PlnrJMTapeoutState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recTpoJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recTpoJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrTpoDetail::refresh(
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

void PnlPlnrTpoDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFTPO) {
		recTpo.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref);
		refreshRecTpo(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrTpoDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODETAILDO) {
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

void PnlPlnrTpoDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrTpoDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::NUMFPUPTYP, ContIac::TXFMAJ, ContIac::TXFSUB, ContIac::NUMFPUPSTE, ContIac::CHKFLI, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFMAJ)) contiac.TxfMaj = _contiac->TxfMaj;
		if (has(diffitems, ContIac::TXFSUB)) contiac.TxfSub = _contiac->TxfSub;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::CHKFLI)) contiac.ChkFli = _contiac->ChkFli;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recTpoJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecTpoJste(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrTpoDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrTpoDetail::handleDpchAppDoButJEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlPlnrTpoDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRTPOUPD_REFEQ) {
		call->abort = handleCallPlnrTpoUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRTPOJSTEMOD_TPOEQ) {
		call->abort = handleCallPlnrTpoJsteMod_tpoEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrTpoDetail::handleCallPlnrTpoUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrTpoUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrTpoDetail::handleCallPlnrTpoJsteMod_tpoEq(
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


