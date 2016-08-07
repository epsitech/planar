/**
  * \file PnlPlnrTpoRec.cpp
  * job handler for job PnlPlnrTpoRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrTpoRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrTpoRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrTpoRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrTpoRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrTpoRec::PnlPlnrTpoRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRTPOREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlfloorplan = NULL;
	pnl1narray = NULL;
	pnlhk1nreticle = NULL;
	pnlmnproject = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFTPO, jref);
};

PnlPlnrTpoRec::~PnlPlnrTpoRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrTpoRec::getNewDpchEng(
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

void PnlPlnrTpoRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubTpoStd(dbsplnr, recTpo.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recTpo.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlfloorplan) {delete pnlfloorplan; pnlfloorplan = NULL;};
		if (pnl1narray) {delete pnl1narray; pnl1narray = NULL;};
		if (pnlhk1nreticle) {delete pnlhk1nreticle; pnlhk1nreticle = NULL;};
		if (pnlmnproject) {delete pnlmnproject; pnlmnproject = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrTpoDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlfloorplan) pnlfloorplan = new PnlPlnrTpoFloorplan(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1narray) pnl1narray = new PnlPlnrTpo1NArray(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nreticle) pnlhk1nreticle = new PnlPlnrTpoHk1NReticle(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnproject) pnlmnproject = new PnlPlnrTpoMNProject(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefFloorplan = ((pnlfloorplan) ? pnlfloorplan->jref : 0);
	statshr.jref1NArray = ((pnl1narray) ? pnl1narray->jref : 0);
	statshr.jrefHk1NReticle = ((pnlhk1nreticle) ? pnlhk1nreticle->jref : 0);
	statshr.jrefMNProject = ((pnlmnproject) ? pnlmnproject->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrTpoRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFTPO) {
		PlnrMTapeout* _recTpo = NULL;

		recTpo.ref = 0;

		if (dbsplnr->tblplnrmtapeout->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref), &_recTpo)) {
			recTpo = *_recTpo;

			delete _recTpo;
		};

		if (recTpo.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlfloorplan) pnlfloorplan->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1narray) pnl1narray->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nreticle) pnlhk1nreticle->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnproject) pnlmnproject->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrTpoRec::minimize(
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

void PnlPlnrTpoRec::regularize(
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

void PnlPlnrTpoRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPORECDO) {
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

void PnlPlnrTpoRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrTpoRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrTpoRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrTpoRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRTPOUPD_REFEQ) {
		call->abort = handleCallPlnrTpoUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrTpoRec::handleCallPlnrTpoUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrTpoUpd_refEq --- INSERT
	return retval;
};


