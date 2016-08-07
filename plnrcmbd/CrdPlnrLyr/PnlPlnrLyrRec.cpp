/**
  * \file PnlPlnrLyrRec.cpp
  * job handler for job PnlPlnrLyrRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrLyrRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrLyrRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrLyrRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrLyrRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrLyrRec::PnlPlnrLyrRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRLYRREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnl1nblock = NULL;
	pnl1nreticle = NULL;
	pnlmnstructure = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFLYR, jref);
};

PnlPlnrLyrRec::~PnlPlnrLyrRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrLyrRec::getNewDpchEng(
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

void PnlPlnrLyrRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubLyrStd(dbsplnr, recLyr.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recLyr.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.pnl1nblockAvail = evalPnl1nblockAvail(dbsplnr);
	statshr.pnl1nreticleAvail = evalPnl1nreticleAvail(dbsplnr);
	statshr.pnlmnstructureAvail = evalPnlmnstructureAvail(dbsplnr);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nblock) {delete pnl1nblock; pnl1nblock = NULL;};
		if (pnl1nreticle) {delete pnl1nreticle; pnl1nreticle = NULL;};
		if (pnlmnstructure) {delete pnlmnstructure; pnlmnstructure = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrLyrDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nblock) pnl1nblock = new PnlPlnrLyr1NBlock(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nreticle) pnl1nreticle = new PnlPlnrLyr1NReticle(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnstructure) pnlmnstructure = new PnlPlnrLyrMNStructure(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NBlock = ((pnl1nblock) ? pnl1nblock->jref : 0);
	statshr.jref1NReticle = ((pnl1nreticle) ? pnl1nreticle->jref : 0);
	statshr.jrefMNStructure = ((pnlmnstructure) ? pnlmnstructure->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrLyrRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFLYR) {
		PlnrMLayer* _recLyr = NULL;

		recLyr.ref = 0;

		if (dbsplnr->tblplnrmlayer->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFLYR, jref), &_recLyr)) {
			recLyr = *_recLyr;

			delete _recLyr;
		};

		if (recLyr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nblock) pnl1nblock->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nreticle) pnl1nreticle->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnstructure) pnlmnstructure->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrLyrRec::minimize(
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

void PnlPlnrLyrRec::regularize(
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

void PnlPlnrLyrRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRRECDO) {
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

void PnlPlnrLyrRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrLyrRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrLyrRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrLyrRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRUPD_REFEQ) {
		call->abort = handleCallPlnrLyrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrLyrRec::handleCallPlnrLyrUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrLyrUpd_refEq --- INSERT
	return retval;
};


