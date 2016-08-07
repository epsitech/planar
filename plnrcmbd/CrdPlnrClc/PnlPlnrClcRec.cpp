/**
  * \file PnlPlnrClcRec.cpp
  * job handler for job PnlPlnrClcRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrClcRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrClcRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrClcRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrClcRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrClcRec::PnlPlnrClcRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRCLCREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnlpre = NULL;
	pnldetail = NULL;
	pnlview = NULL;
	pnlaenv = NULL;
	pnlapar = NULL;
	pnlcal1ncalcitem = NULL;
	pnl1nmaterial = NULL;
	pnlsup1ncalc = NULL;
	pnlref1nfile = NULL;
	pnlmnfile = NULL;
	pnlmndomain = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFCLC, jref);
};

PnlPlnrClcRec::~PnlPlnrClcRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrClcRec::getNewDpchEng(
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

void PnlPlnrClcRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubClcStd(dbsplnr, recCal.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCal.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlview) {delete pnlview; pnlview = NULL;};
		if (pnlaenv) {delete pnlaenv; pnlaenv = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlcal1ncalcitem) {delete pnlcal1ncalcitem; pnlcal1ncalcitem = NULL;};
		if (pnl1nmaterial) {delete pnl1nmaterial; pnl1nmaterial = NULL;};
		if (pnlsup1ncalc) {delete pnlsup1ncalc; pnlsup1ncalc = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmnfile) {delete pnlmnfile; pnlmnfile = NULL;};
		if (pnlmndomain) {delete pnlmndomain; pnlmndomain = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlPlnrClcPre(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldetail) pnldetail = new PnlPlnrClcDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlview) pnlview = new PnlPlnrClcView(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlaenv) pnlaenv = new PnlPlnrClcAEnv(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlapar) pnlapar = new PnlPlnrClcAPar(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlcal1ncalcitem) pnlcal1ncalcitem = new PnlPlnrClcCal1NCalcitem(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nmaterial) pnl1nmaterial = new PnlPlnrClc1NMaterial(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlsup1ncalc) pnlsup1ncalc = new PnlPlnrClcSup1NCalc(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlPlnrClcRef1NFile(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnfile) pnlmnfile = new PnlPlnrClcMNFile(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmndomain) pnlmndomain = new PnlPlnrClcMNDomain(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefView = ((pnlview) ? pnlview->jref : 0);
	statshr.jrefAEnv = ((pnlaenv) ? pnlaenv->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefCal1NCalcitem = ((pnlcal1ncalcitem) ? pnlcal1ncalcitem->jref : 0);
	statshr.jref1NMaterial = ((pnl1nmaterial) ? pnl1nmaterial->jref : 0);
	statshr.jrefSup1NCalc = ((pnlsup1ncalc) ? pnlsup1ncalc->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNFile = ((pnlmnfile) ? pnlmnfile->jref : 0);
	statshr.jrefMNDomain = ((pnlmndomain) ? pnlmndomain->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrClcRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCLC) {
		PlnrMCalc* _recCal = NULL;

		recCal.ref = 0;

		if (dbsplnr->tblplnrmcalc->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref), &_recCal)) {
			recCal = *_recCal;

			delete _recCal;
		};

		if (recCal.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlview) pnlview->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlaenv) pnlaenv->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlcal1ncalcitem) pnlcal1ncalcitem->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nmaterial) pnl1nmaterial->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlsup1ncalc) pnlsup1ncalc->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnfile) pnlmnfile->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmndomain) pnlmndomain->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrClcRec::minimize(
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

void PnlPlnrClcRec::regularize(
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

void PnlPlnrClcRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCRECDO) {
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

void PnlPlnrClcRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrClcRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrClcRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrClcRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRCALUPD_REFEQ) {
		call->abort = handleCallPlnrCalUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrClcRec::handleCallPlnrCalUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrCalUpd_refEq --- INSERT
	return retval;
};


