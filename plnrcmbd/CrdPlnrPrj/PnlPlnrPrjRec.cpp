/**
  * \file PnlPlnrPrjRec.cpp
  * job handler for job PnlPlnrPrjRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrPrjRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrPrjRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrPrjRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrPrjRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrPrjRec::PnlPlnrPrjRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRPRJREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnl1ncalc = NULL;
	pnl1ndesign = NULL;
	pnlmntapeout = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFPRJ, jref);
};

PnlPlnrPrjRec::~PnlPlnrPrjRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrPrjRec::getNewDpchEng(
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

void PnlPlnrPrjRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubPrjStd(dbsplnr, recPrj.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recPrj.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1ncalc) {delete pnl1ncalc; pnl1ncalc = NULL;};
		if (pnl1ndesign) {delete pnl1ndesign; pnl1ndesign = NULL;};
		if (pnlmntapeout) {delete pnlmntapeout; pnlmntapeout = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrPrjDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1ncalc) pnl1ncalc = new PnlPlnrPrj1NCalc(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1ndesign) pnl1ndesign = new PnlPlnrPrj1NDesign(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmntapeout) pnlmntapeout = new PnlPlnrPrjMNTapeout(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NCalc = ((pnl1ncalc) ? pnl1ncalc->jref : 0);
	statshr.jref1NDesign = ((pnl1ndesign) ? pnl1ndesign->jref : 0);
	statshr.jrefMNTapeout = ((pnlmntapeout) ? pnlmntapeout->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrPrjRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFPRJ) {
		PlnrMProject* _recPrj = NULL;

		recPrj.ref = 0;

		if (dbsplnr->tblplnrmproject->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref), &_recPrj)) {
			recPrj = *_recPrj;

			delete _recPrj;
		};

		if (recPrj.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1ncalc) pnl1ncalc->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1ndesign) pnl1ndesign->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmntapeout) pnlmntapeout->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrPrjRec::minimize(
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

void PnlPlnrPrjRec::regularize(
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

void PnlPlnrPrjRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJRECDO) {
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

void PnlPlnrPrjRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrPrjRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrPrjRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrPrjRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRPRJUPD_REFEQ) {
		call->abort = handleCallPlnrPrjUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrPrjRec::handleCallPlnrPrjUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrPrjUpd_refEq --- INSERT
	return retval;
};


