/**
  * \file PnlPlnrAriDetail.cpp
  * job handler for job PnlPlnrAriDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrAriDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrAriDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrAriDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrAriDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrAriDetail::PnlPlnrAriDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRARIDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFARI, jref);
};

PnlPlnrAriDetail::~PnlPlnrAriDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrAriDetail::getNewDpchEng(
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

void PnlPlnrAriDetail::refreshRecAri(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMArrayitem* _recAri = NULL;

	if (dbsplnr->tblplnrmarrayitem->loadRecByRef(recAri.ref, &_recAri)) {
		recAri = *_recAri;
		delete _recAri;
	} else recAri = PlnrMArrayitem();

	dirty = false;

	contiac.TxfI = to_string(recAri.i);
	contiac.TxfJ = to_string(recAri.j);
	contiac.TxfK = to_string(recAri.k);
	contiac.TxfL = to_string(recAri.l);
	contiac.TxfM = to_string(recAri.m);
	contiac.TxfN = to_string(recAri.n);
	continf.TxtArr = StubPlnr::getStubArrStd(dbsplnr, recAri.refPlnrMArray, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, recAri.refPlnrMDesign, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfDx = to_string(recAri.dx);
	contiac.TxfDy = to_string(recAri.dy);

	statshr.ButArrViewAvail = evalButArrViewAvail(dbsplnr);
	statshr.ButDsnViewAvail = evalButDsnViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrAriDetail::refresh(
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

void PnlPlnrAriDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARI) {
		recAri.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref);
		refreshRecAri(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrAriDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARRVIEWCLICK) {
					handleDpchAppDoButArrViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrAriDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrAriDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFI, ContIac::TXFJ, ContIac::TXFK, ContIac::TXFL, ContIac::TXFM, ContIac::TXFN, ContIac::TXFDX, ContIac::TXFDY})) {
		if (has(diffitems, ContIac::TXFI)) contiac.TxfI = _contiac->TxfI;
		if (has(diffitems, ContIac::TXFJ)) contiac.TxfJ = _contiac->TxfJ;
		if (has(diffitems, ContIac::TXFK)) contiac.TxfK = _contiac->TxfK;
		if (has(diffitems, ContIac::TXFL)) contiac.TxfL = _contiac->TxfL;
		if (has(diffitems, ContIac::TXFM)) contiac.TxfM = _contiac->TxfM;
		if (has(diffitems, ContIac::TXFN)) contiac.TxfN = _contiac->TxfN;
		if (has(diffitems, ContIac::TXFDX)) contiac.TxfDx = _contiac->TxfDx;
		if (has(diffitems, ContIac::TXFDY)) contiac.TxfDy = _contiac->TxfDy;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrAriDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrAriDetail::handleDpchAppDoButArrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButArrViewClick --- INSERT
};

void PnlPlnrAriDetail::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDsnViewClick --- INSERT
};

void PnlPlnrAriDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRARIUPD_REFEQ) {
		call->abort = handleCallPlnrAriUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrAriDetail::handleCallPlnrAriUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrAriUpd_refEq --- INSERT
	return retval;
};


