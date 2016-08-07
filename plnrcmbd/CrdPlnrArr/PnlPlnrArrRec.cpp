/**
  * \file PnlPlnrArrRec.cpp
  * job handler for job PnlPlnrArrRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrArrRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrArrRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrArrRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrArrRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrArrRec::PnlPlnrArrRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRARRREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlkenvkey = NULL;
	pnlaenv = NULL;
	pnl1narrayitem = NULL;
	pnlhk1nreticle = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFARR, jref);
};

PnlPlnrArrRec::~PnlPlnrArrRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrArrRec::getNewDpchEng(
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

void PnlPlnrArrRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubArrStd(dbsplnr, recArr.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recArr.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkenvkey) {delete pnlkenvkey; pnlkenvkey = NULL;};
		if (pnlaenv) {delete pnlaenv; pnlaenv = NULL;};
		if (pnl1narrayitem) {delete pnl1narrayitem; pnl1narrayitem = NULL;};
		if (pnlhk1nreticle) {delete pnlhk1nreticle; pnlhk1nreticle = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrArrDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkenvkey) pnlkenvkey = new PnlPlnrArrKEnvKey(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlaenv) pnlaenv = new PnlPlnrArrAEnv(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1narrayitem) pnl1narrayitem = new PnlPlnrArr1NArrayitem(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nreticle) pnlhk1nreticle = new PnlPlnrArrHk1NReticle(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKEnvKey = ((pnlkenvkey) ? pnlkenvkey->jref : 0);
	statshr.jrefAEnv = ((pnlaenv) ? pnlaenv->jref : 0);
	statshr.jref1NArrayitem = ((pnl1narrayitem) ? pnl1narrayitem->jref : 0);
	statshr.jrefHk1NReticle = ((pnlhk1nreticle) ? pnlhk1nreticle->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrArrRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARR) {
		PlnrMArray* _recArr = NULL;

		recArr.ref = 0;

		if (dbsplnr->tblplnrmarray->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARR, jref), &_recArr)) {
			recArr = *_recArr;

			delete _recArr;
		};

		if (recArr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkenvkey) pnlkenvkey->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlaenv) pnlaenv->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1narrayitem) pnl1narrayitem->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nreticle) pnlhk1nreticle->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrArrRec::minimize(
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

void PnlPlnrArrRec::regularize(
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

void PnlPlnrArrRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRRECDO) {
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

void PnlPlnrArrRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrArrRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrArrRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrArrRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRARRUPD_REFEQ) {
		call->abort = handleCallPlnrArrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrArrRec::handleCallPlnrArrUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrArrUpd_refEq --- INSERT
	return retval;
};


