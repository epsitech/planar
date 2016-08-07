/**
  * \file PnlPlnrDvcRec.cpp
  * job handler for job PnlPlnrDvcRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDvcRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDvcRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDvcRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDvcRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDvcRec::PnlPlnrDvcRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDVCREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnlpre = NULL;
	pnldetail = NULL;
	pnlview = NULL;
	pnlapar = NULL;
	pnlsup1ndevice = NULL;
	pnlhk1nstructure = NULL;
	pnlhk1nvertex = NULL;
	pnlhk1nlineguide = NULL;
	pnlhk1narcguide = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDVC, jref);
};

PnlPlnrDvcRec::~PnlPlnrDvcRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDvcRec::getNewDpchEng(
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

void PnlPlnrDvcRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubDvcStd(dbsplnr, recDev.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recDev.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlview) {delete pnlview; pnlview = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlsup1ndevice) {delete pnlsup1ndevice; pnlsup1ndevice = NULL;};
		if (pnlhk1nstructure) {delete pnlhk1nstructure; pnlhk1nstructure = NULL;};
		if (pnlhk1nvertex) {delete pnlhk1nvertex; pnlhk1nvertex = NULL;};
		if (pnlhk1nlineguide) {delete pnlhk1nlineguide; pnlhk1nlineguide = NULL;};
		if (pnlhk1narcguide) {delete pnlhk1narcguide; pnlhk1narcguide = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlPlnrDvcPre(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldetail) pnldetail = new PnlPlnrDvcDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlview) pnlview = new PnlPlnrDvcView(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlapar) pnlapar = new PnlPlnrDvcAPar(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlsup1ndevice) pnlsup1ndevice = new PnlPlnrDvcSup1NDevice(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nstructure) pnlhk1nstructure = new PnlPlnrDvcHk1NStructure(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nvertex) pnlhk1nvertex = new PnlPlnrDvcHk1NVertex(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlineguide) pnlhk1nlineguide = new PnlPlnrDvcHk1NLineguide(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1narcguide) pnlhk1narcguide = new PnlPlnrDvcHk1NArcguide(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefView = ((pnlview) ? pnlview->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefSup1NDevice = ((pnlsup1ndevice) ? pnlsup1ndevice->jref : 0);
	statshr.jrefHk1NStructure = ((pnlhk1nstructure) ? pnlhk1nstructure->jref : 0);
	statshr.jrefHk1NVertex = ((pnlhk1nvertex) ? pnlhk1nvertex->jref : 0);
	statshr.jrefHk1NLineguide = ((pnlhk1nlineguide) ? pnlhk1nlineguide->jref : 0);
	statshr.jrefHk1NArcguide = ((pnlhk1narcguide) ? pnlhk1narcguide->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDvcRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDVC) {
		PlnrMDevice* _recDev = NULL;

		recDev.ref = 0;

		if (dbsplnr->tblplnrmdevice->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref), &_recDev)) {
			recDev = *_recDev;

			delete _recDev;
		};

		if (recDev.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlview) pnlview->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlsup1ndevice) pnlsup1ndevice->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nstructure) pnlhk1nstructure->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nvertex) pnlhk1nvertex->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlineguide) pnlhk1nlineguide->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1narcguide) pnlhk1narcguide->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDvcRec::minimize(
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

void PnlPlnrDvcRec::regularize(
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

void PnlPlnrDvcRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCRECDO) {
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

void PnlPlnrDvcRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDvcRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrDvcRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrDvcRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVUPD_REFEQ) {
		call->abort = handleCallPlnrDevUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDvcRec::handleCallPlnrDevUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDevUpd_refEq --- INSERT
	return retval;
};


