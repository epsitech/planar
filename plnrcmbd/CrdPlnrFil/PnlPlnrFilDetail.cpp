/**
  * \file PnlPlnrFilDetail.cpp
  * job handler for job PnlPlnrFilDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrFilDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrFilDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrFilDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrFilDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrFilDetail::PnlPlnrFilDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRFILDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	dbsplnr->fillFeedFromKlst(VecPlnrVKeylist::KLSTPLNRKMFILECONTENT, ixPlnrVLocale, feedFPupCnt);
	feedFPupMim.tag = "FeedFPupMim";
	dbsplnr->fillFeedFromKlst(VecPlnrVKeylist::KLSTPLNRKMFILEMIMETYPE, ixPlnrVLocale, feedFPupMim);
	feedFPupRet.tag = "FeedFPupRet";
	VecPlnrVMFileRefTbl::fillFeed(ixPlnrVLocale, feedFPupRet);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecPlnrVCall::CALLPLNRFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVKeylist::KLSTPLNRKMFILECONTENT, Clstn::VecVJactype::LOCK);
	xchg->addIxClstn(VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVKeylist::KLSTPLNRKMFILEMIMETYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFFIL, jref);
};

PnlPlnrFilDetail::~PnlPlnrFilDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrFilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupCnt, &feedFPupMim, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrFilDetail::refreshLstClu(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.ButCluViewActive = evalButCluViewActive(dbsplnr);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbsplnr);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrFilDetail::refreshClu(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recFil.refPlnrCFile != 0) dbsplnr->tblplnrmfile->loadRefsByClu(recFil.refPlnrCFile, false, refs);

	first = true;
	for (unsigned int i=0;i<refs.size();i++) {
		if (refs[i] != recFil.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubPlnr::getStubFilStd(dbsplnr, refs[i], ixPlnrVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubPlnr::getStubFilStd(dbsplnr, refs[i], ixPlnrVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbsplnr, moditems);
};

void PnlPlnrFilDetail::refreshPupCnt(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupCnt = 0;

	for (unsigned int i=0;i<feedFPupCnt.size();i++) {
		if (feedFPupCnt.getSrefByNum(i+1) == contiac.TxfCnt) {
			contiac.numFPupCnt = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfCntValid = (contiac.numFPupCnt != 0);
	statshr.ButCntEditAvail = evalButCntEditAvail(dbsplnr);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrFilDetail::refreshTxfCnt(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfCnt = feedFPupCnt.getSrefByNum(contiac.numFPupCnt);

	// statshr
	statshr.TxfCntValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrFilDetail::refreshCnt(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	// feedFPupCnt
	dbsplnr->fillFeedFromKlst(VecPlnrVKeylist::KLSTPLNRKMFILECONTENT, ixPlnrVLocale, feedFPupCnt);

	insert(moditems, DpchEngData::FEEDFPUPCNT);

	refreshPupCnt(dbsplnr, moditems);
};

void PnlPlnrFilDetail::refreshPupMim(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupMim = 0;

	for (unsigned int i=0;i<feedFPupMim.size();i++) {
		if (feedFPupMim.getSrefByNum(i+1) == contiac.TxfMim) {
			contiac.numFPupMim = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfMimValid = (contiac.numFPupMim != 0);
	statshr.ButMimEditAvail = evalButMimEditAvail(dbsplnr);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrFilDetail::refreshTxfMim(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfMim = feedFPupMim.getSrefByNum(contiac.numFPupMim);

	// statshr
	statshr.TxfMimValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrFilDetail::refreshMim(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	// feedFPupMim
	dbsplnr->fillFeedFromKlst(VecPlnrVKeylist::KLSTPLNRKMFILEMIMETYPE, ixPlnrVLocale, feedFPupMim);

	insert(moditems, DpchEngData::FEEDFPUPMIM);

	refreshPupMim(dbsplnr, moditems);
};

void PnlPlnrFilDetail::refreshRecFil(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMFile* _recFil = NULL;

	if (dbsplnr->tblplnrmfile->loadRecByRef(recFil.ref, &_recFil)) {
		recFil = *_recFil;
		delete _recFil;
	} else recFil = PlnrMFile();

	dirty = false;

	xchg->removeClstns(VecPlnrVCall::CALLPLNRFILMOD_CLUEQ, jref);
	if (recFil.refPlnrCFile != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRFILMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, recFil.refPlnrCFile, Clstn::VecVJactype::LOCK);

	contiac.TxfFnm = recFil.Filename;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recFil.refIxVTbl);
	contiac.TxfCnt = recFil.osrefKContent;
	contiac.TxfAcv = Ftm::stamp(recFil.Archived);
	contiac.TxfAnm = recFil.Archivename;
	contiac.TxfMim = recFil.srefKMimetype;
	contiac.TxfSiz = to_string(recFil.Size);
	contiac.TxfCmt = recFil.Comment;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbsplnr, moditems);
	refreshPupCnt(dbsplnr, moditems);
	refreshPupMim(dbsplnr, moditems);

};

void PnlPlnrFilDetail::refresh(
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

void PnlPlnrFilDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFFIL) {
		recFil.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFFIL, jref);
		refreshRecFil(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrFilDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNTEDITCLICK) {
					handleDpchAppDoButCntEditClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMIMEDITCLICK) {
					handleDpchAppDoButMimEditClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrFilDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrFilDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFNM, ContIac::TXFACV, ContIac::TXFANM, ContIac::TXFSIZ, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::TXFACV)) contiac.TxfAcv = _contiac->TxfAcv;
		if (has(diffitems, ContIac::TXFANM)) contiac.TxfAnm = _contiac->TxfAnm;
		if (has(diffitems, ContIac::TXFSIZ)) contiac.TxfSiz = _contiac->TxfSiz;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFCNT)) {
		contiac.TxfCnt = _contiac->TxfCnt;
		refreshPupCnt(dbsplnr, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPCNT)) {
		contiac.numFPupCnt = _contiac->numFPupCnt;
		refreshTxfCnt(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::TXFMIM)) {
		contiac.TxfMim = _contiac->TxfMim;
		refreshPupMim(dbsplnr, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPMIM)) {
		contiac.numFPupMim = _contiac->numFPupMim;
		refreshTxfMim(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrFilDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButCluViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButCluClusterClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButCluUnclusterClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButReuViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButReuViewClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButCntEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButCntEditClick --- INSERT
};

void PnlPlnrFilDetail::handleDpchAppDoButMimEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButMimEditClick --- INSERT
};

void PnlPlnrFilDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRFIL_CLUEQ) {
		call->abort = handleCallPlnrFil_cluEq(dbsplnr, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILUPD_REFEQ) {
		call->abort = handleCallPlnrFilUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallPlnrKlsAkeyMod_klsEq(dbsplnr, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILMOD_CLUEQ) {
		call->abort = handleCallPlnrFilMod_cluEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrFilDetail::handleCallPlnrFil_cluEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrFil_cluEq --- BEGIN
		if (recFil.ref != 0) boolvalRet = (recFil.refPlnrCFile == refInv);
// IP handleCallPlnrFil_cluEq --- END
	return retval;
};

bool PnlPlnrFilDetail::handleCallPlnrFilUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrFilUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrFilDetail::handleCallPlnrKlsAkeyMod_klsEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVKeylist::KLSTPLNRKMFILECONTENT) {
		refreshCnt(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVKeylist::KLSTPLNRKMFILEMIMETYPE) {
		refreshMim(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlPlnrFilDetail::handleCallPlnrFilMod_cluEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbsplnr, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


