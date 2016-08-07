/**
  * \file PnlPlnrDtpRec.cpp
  * job handler for job PnlPlnrDtpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDtpRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDtpRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDtpRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDtpRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDtpRec::PnlPlnrDtpRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDTPREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnlpre = NULL;
	pnldetail = NULL;
	pnlview = NULL;
	pnlkparkey = NULL;
	pnlapar = NULL;
	pnlsup1ndevice = NULL;
	pnlhk1nstructure = NULL;
	pnltpl1ndevice = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDTP, jref);
};

PnlPlnrDtpRec::~PnlPlnrDtpRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDtpRec::getNewDpchEng(
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

void PnlPlnrDtpRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubDtpStd(dbsplnr, recDev.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recDev.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlview) {delete pnlview; pnlview = NULL;};
		if (pnlkparkey) {delete pnlkparkey; pnlkparkey = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlsup1ndevice) {delete pnlsup1ndevice; pnlsup1ndevice = NULL;};
		if (pnlhk1nstructure) {delete pnlhk1nstructure; pnlhk1nstructure = NULL;};
		if (pnltpl1ndevice) {delete pnltpl1ndevice; pnltpl1ndevice = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlPlnrDtpPre(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldetail) pnldetail = new PnlPlnrDtpDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlview) pnlview = new PnlPlnrDtpView(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlkparkey) pnlkparkey = new PnlPlnrDtpKParKey(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlapar) pnlapar = new PnlPlnrDtpAPar(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlsup1ndevice) pnlsup1ndevice = new PnlPlnrDtpSup1NDevice(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nstructure) pnlhk1nstructure = new PnlPlnrDtpHk1NStructure(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnltpl1ndevice) pnltpl1ndevice = new PnlPlnrDtpTpl1NDevice(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefView = ((pnlview) ? pnlview->jref : 0);
	statshr.jrefKParKey = ((pnlkparkey) ? pnlkparkey->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefSup1NDevice = ((pnlsup1ndevice) ? pnlsup1ndevice->jref : 0);
	statshr.jrefHk1NStructure = ((pnlhk1nstructure) ? pnlhk1nstructure->jref : 0);
	statshr.jrefTpl1NDevice = ((pnltpl1ndevice) ? pnltpl1ndevice->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDtpRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDTP) {
		PlnrMDevice* _recDev = NULL;

		recDev.ref = 0;

		if (dbsplnr->tblplnrmdevice->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref), &_recDev)) {
			recDev = *_recDev;

			delete _recDev;
		};

		if (recDev.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlview) pnlview->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlkparkey) pnlkparkey->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlsup1ndevice) pnlsup1ndevice->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nstructure) pnlhk1nstructure->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnltpl1ndevice) pnltpl1ndevice->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDtpRec::minimize(
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

void PnlPlnrDtpRec::regularize(
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

void PnlPlnrDtpRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPRECDO) {
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

void PnlPlnrDtpRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDtpRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrDtpRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrDtpRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVUPD_REFEQ) {
		call->abort = handleCallPlnrDevUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDtpRec::handleCallPlnrDevUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDevUpd_refEq --- INSERT
	return retval;
};


