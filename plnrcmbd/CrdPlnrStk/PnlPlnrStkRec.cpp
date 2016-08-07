/**
  * \file PnlPlnrStkRec.cpp
  * job handler for job PnlPlnrStkRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrStkRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrStkRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrStkRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrStkRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrStkRec::PnlPlnrStkRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRSTKREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnlpre = NULL;
	pnldetail = NULL;
	pnlview = NULL;
	pnlhk1nlevel = NULL;
	pnlhk1nlayer = NULL;
	pnlmnstructure = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFSTK, jref);
};

PnlPlnrStkRec::~PnlPlnrStkRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrStkRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrStkRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubStkStd(dbsplnr, recStk.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recStk.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.pnlmnstructureAvail = evalPnlmnstructureAvail(dbsplnr);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlview) {delete pnlview; pnlview = NULL;};
		if (pnlhk1nlevel) {delete pnlhk1nlevel; pnlhk1nlevel = NULL;};
		if (pnlhk1nlayer) {delete pnlhk1nlayer; pnlhk1nlayer = NULL;};
		if (pnlmnstructure) {delete pnlmnstructure; pnlmnstructure = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlPlnrStkPre(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldetail) pnldetail = new PnlPlnrStkDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlview) pnlview = new PnlPlnrStkView(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlevel) pnlhk1nlevel = new PnlPlnrStkHk1NLevel(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlayer) pnlhk1nlayer = new PnlPlnrStkHk1NLayer(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnstructure) pnlmnstructure = new PnlPlnrStkMNStructure(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefView = ((pnlview) ? pnlview->jref : 0);
	statshr.jrefHk1NLevel = ((pnlhk1nlevel) ? pnlhk1nlevel->jref : 0);
	statshr.jrefHk1NLayer = ((pnlhk1nlayer) ? pnlhk1nlayer->jref : 0);
	statshr.jrefMNStructure = ((pnlmnstructure) ? pnlmnstructure->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrStkRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSTK) {
		PlnrMStack* _recStk = NULL;

		recStk.ref = 0;

		if (dbsplnr->tblplnrmstack->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref), &_recStk)) {
			recStk = *_recStk;

			delete _recStk;
		};

		if (recStk.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlview) pnlview->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlevel) pnlhk1nlevel->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlayer) pnlhk1nlayer->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnstructure) pnlmnstructure->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrStkRec::minimize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::MIND) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsplnr, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrStkRec::regularize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::REGD) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsplnr, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrStkRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrStkRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrStkRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrStkRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrStkRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKUPD_REFEQ) {
		call->abort = handleCallPlnrStkUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrStkRec::handleCallPlnrStkUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrStkUpd_refEq --- INSERT
	return retval;
};


