/**
  * \file PnlPlnrArrDetail.cpp
  * job handler for job PnlPlnrArrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrArrDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrArrDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrArrDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrArrDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrArrDetail::PnlPlnrArrDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRARRDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFARR, jref);
};

PnlPlnrArrDetail::~PnlPlnrArrDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrArrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrArrDetail::refreshRecArr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMArray* _recArr = NULL;

	if (dbsplnr->tblplnrmarray->loadRecByRef(recArr.ref, &_recArr)) {
		recArr = *_recArr;
		delete _recArr;
	} else recArr = PlnrMArray();

	dirty = false;

	continf.TxtSrf = recArr.sref;
	continf.TxtTpo = StubPlnr::getStubTpoStd(dbsplnr, recArr.refPlnrMTapeout, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recArr.refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfI = to_string(recArr.I);
	contiac.TxfJ = to_string(recArr.J);
	contiac.TxfDi = to_string(recArr.di);
	contiac.TxfDj = to_string(recArr.dj);
	contiac.TxfK = to_string(recArr.K);
	contiac.TxfL = to_string(recArr.L);
	contiac.TxfDk = to_string(recArr.dk);
	contiac.TxfDl = to_string(recArr.dl);
	contiac.TxfM = to_string(recArr.M);
	contiac.TxfN = to_string(recArr.N);
	contiac.TxfDm = to_string(recArr.dm);
	contiac.TxfDn = to_string(recArr.dn);

	statshr.ButTpoViewAvail = evalButTpoViewAvail(dbsplnr);
	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrArrDetail::refresh(
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

void PnlPlnrArrDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARR) {
		recArr.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARR, jref);
		refreshRecArr(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrArrDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTPOVIEWCLICK) {
					handleDpchAppDoButTpoViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrArrDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrArrDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFI, ContIac::TXFJ, ContIac::TXFDI, ContIac::TXFDJ, ContIac::TXFK, ContIac::TXFL, ContIac::TXFDK, ContIac::TXFDL, ContIac::TXFM, ContIac::TXFN, ContIac::TXFDM, ContIac::TXFDN})) {
		if (has(diffitems, ContIac::TXFI)) contiac.TxfI = _contiac->TxfI;
		if (has(diffitems, ContIac::TXFJ)) contiac.TxfJ = _contiac->TxfJ;
		if (has(diffitems, ContIac::TXFDI)) contiac.TxfDi = _contiac->TxfDi;
		if (has(diffitems, ContIac::TXFDJ)) contiac.TxfDj = _contiac->TxfDj;
		if (has(diffitems, ContIac::TXFK)) contiac.TxfK = _contiac->TxfK;
		if (has(diffitems, ContIac::TXFL)) contiac.TxfL = _contiac->TxfL;
		if (has(diffitems, ContIac::TXFDK)) contiac.TxfDk = _contiac->TxfDk;
		if (has(diffitems, ContIac::TXFDL)) contiac.TxfDl = _contiac->TxfDl;
		if (has(diffitems, ContIac::TXFM)) contiac.TxfM = _contiac->TxfM;
		if (has(diffitems, ContIac::TXFN)) contiac.TxfN = _contiac->TxfN;
		if (has(diffitems, ContIac::TXFDM)) contiac.TxfDm = _contiac->TxfDm;
		if (has(diffitems, ContIac::TXFDN)) contiac.TxfDn = _contiac->TxfDn;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrArrDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrArrDetail::handleDpchAppDoButTpoViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButTpoViewClick --- INSERT
};

void PnlPlnrArrDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrArrDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRARRUPD_REFEQ) {
		call->abort = handleCallPlnrArrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrArrDetail::handleCallPlnrArrUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrArrUpd_refEq --- INSERT
	return retval;
};


