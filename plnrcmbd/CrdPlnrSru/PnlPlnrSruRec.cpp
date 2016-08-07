/**
  * \file PnlPlnrSruRec.cpp
  * job handler for job PnlPlnrSruRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrSruRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrSruRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrSruRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrSruRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrSruRec::PnlPlnrSruRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRSRUREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnl1nblock = NULL;
	pnlsru1nface = NULL;
	pnlmnlayer = NULL;
	pnlmnstack = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFSRU, jref);
};

PnlPlnrSruRec::~PnlPlnrSruRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrSruRec::getNewDpchEng(
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

void PnlPlnrSruRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubSruStd(dbsplnr, recSru.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSru.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.pnl1nblockAvail = evalPnl1nblockAvail(dbsplnr);
	statshr.pnlmnlayerAvail = evalPnlmnlayerAvail(dbsplnr);
	statshr.pnlmnstackAvail = evalPnlmnstackAvail(dbsplnr);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nblock) {delete pnl1nblock; pnl1nblock = NULL;};
		if (pnlsru1nface) {delete pnlsru1nface; pnlsru1nface = NULL;};
		if (pnlmnlayer) {delete pnlmnlayer; pnlmnlayer = NULL;};
		if (pnlmnstack) {delete pnlmnstack; pnlmnstack = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrSruDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nblock) pnl1nblock = new PnlPlnrSru1NBlock(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlsru1nface) pnlsru1nface = new PnlPlnrSruSru1NFace(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnlayer) pnlmnlayer = new PnlPlnrSruMNLayer(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnstack) pnlmnstack = new PnlPlnrSruMNStack(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NBlock = ((pnl1nblock) ? pnl1nblock->jref : 0);
	statshr.jrefSru1NFace = ((pnlsru1nface) ? pnlsru1nface->jref : 0);
	statshr.jrefMNLayer = ((pnlmnlayer) ? pnlmnlayer->jref : 0);
	statshr.jrefMNStack = ((pnlmnstack) ? pnlmnstack->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrSruRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSRU) {
		PlnrMStructure* _recSru = NULL;

		recSru.ref = 0;

		if (dbsplnr->tblplnrmstructure->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSRU, jref), &_recSru)) {
			recSru = *_recSru;

			delete _recSru;
		};

		if (recSru.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nblock) pnl1nblock->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlsru1nface) pnlsru1nface->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnlayer) pnlmnlayer->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnstack) pnlmnstack->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrSruRec::minimize(
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

void PnlPlnrSruRec::regularize(
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

void PnlPlnrSruRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRURECDO) {
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

void PnlPlnrSruRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrSruRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrSruRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrSruRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSRUUPD_REFEQ) {
		call->abort = handleCallPlnrSruUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrSruRec::handleCallPlnrSruUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrSruUpd_refEq --- INSERT
	return retval;
};


