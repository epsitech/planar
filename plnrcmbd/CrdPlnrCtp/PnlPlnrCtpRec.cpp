/**
  * \file PnlPlnrCtpRec.cpp
  * job handler for job PnlPlnrCtpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrCtpRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrCtpRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrCtpRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrCtpRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrCtpRec::PnlPlnrCtpRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRCTPREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlkenvkey = NULL;
	pnlkparcat = NULL;
	pnlkparprop = NULL;
	pnlkcalcdomprp = NULL;
	pnlkcalcvar = NULL;
	pnlaenv = NULL;
	pnlapar = NULL;
	pnlsup1ncalc = NULL;
	pnlref1nfile = NULL;
	pnltpl1ncalc = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFCTP, jref);
};

PnlPlnrCtpRec::~PnlPlnrCtpRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrCtpRec::getNewDpchEng(
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

void PnlPlnrCtpRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubCtpStd(dbsplnr, recCal.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCal.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkenvkey) {delete pnlkenvkey; pnlkenvkey = NULL;};
		if (pnlkparcat) {delete pnlkparcat; pnlkparcat = NULL;};
		if (pnlkparprop) {delete pnlkparprop; pnlkparprop = NULL;};
		if (pnlkcalcdomprp) {delete pnlkcalcdomprp; pnlkcalcdomprp = NULL;};
		if (pnlkcalcvar) {delete pnlkcalcvar; pnlkcalcvar = NULL;};
		if (pnlaenv) {delete pnlaenv; pnlaenv = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlsup1ncalc) {delete pnlsup1ncalc; pnlsup1ncalc = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnltpl1ncalc) {delete pnltpl1ncalc; pnltpl1ncalc = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrCtpDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkenvkey) pnlkenvkey = new PnlPlnrCtpKEnvKey(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkparcat) pnlkparcat = new PnlPlnrCtpKParCat(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkparprop) pnlkparprop = new PnlPlnrCtpKParProp(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkcalcdomprp) pnlkcalcdomprp = new PnlPlnrCtpKCalcdomprp(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkcalcvar) pnlkcalcvar = new PnlPlnrCtpKCalcvar(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlaenv) pnlaenv = new PnlPlnrCtpAEnv(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlapar) pnlapar = new PnlPlnrCtpAPar(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlsup1ncalc) pnlsup1ncalc = new PnlPlnrCtpSup1NCalc(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlPlnrCtpRef1NFile(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnltpl1ncalc) pnltpl1ncalc = new PnlPlnrCtpTpl1NCalc(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKEnvKey = ((pnlkenvkey) ? pnlkenvkey->jref : 0);
	statshr.jrefKParCat = ((pnlkparcat) ? pnlkparcat->jref : 0);
	statshr.jrefKParProp = ((pnlkparprop) ? pnlkparprop->jref : 0);
	statshr.jrefKCalcdomprp = ((pnlkcalcdomprp) ? pnlkcalcdomprp->jref : 0);
	statshr.jrefKCalcvar = ((pnlkcalcvar) ? pnlkcalcvar->jref : 0);
	statshr.jrefAEnv = ((pnlaenv) ? pnlaenv->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefSup1NCalc = ((pnlsup1ncalc) ? pnlsup1ncalc->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefTpl1NCalc = ((pnltpl1ncalc) ? pnltpl1ncalc->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrCtpRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCTP) {
		PlnrMCalc* _recCal = NULL;

		recCal.ref = 0;

		if (dbsplnr->tblplnrmcalc->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCTP, jref), &_recCal)) {
			recCal = *_recCal;

			delete _recCal;
		};

		if (recCal.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkenvkey) pnlkenvkey->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkparcat) pnlkparcat->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkparprop) pnlkparprop->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkcalcdomprp) pnlkcalcdomprp->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkcalcvar) pnlkcalcvar->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlaenv) pnlaenv->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlsup1ncalc) pnlsup1ncalc->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnltpl1ncalc) pnltpl1ncalc->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrCtpRec::minimize(
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

void PnlPlnrCtpRec::regularize(
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

void PnlPlnrCtpRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPRECDO) {
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

void PnlPlnrCtpRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrCtpRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrCtpRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrCtpRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRCALUPD_REFEQ) {
		call->abort = handleCallPlnrCalUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrCtpRec::handleCallPlnrCalUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrCalUpd_refEq --- INSERT
	return retval;
};


