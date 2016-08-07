/**
  * \file PnlPlnrNavPre.cpp
  * job handler for job PnlPlnrNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavPre.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavPre_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavPre_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavPre
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavPre::PnlPlnrNavPre(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVPRE, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

};

PnlPlnrNavPre::~PnlPlnrNavPre() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavPre::getNewDpchEng(
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

void PnlPlnrNavPre::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtDsn = StubPlnr::getStubDsnStd(dbsplnr, xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref), ixPlnrVLocale);
	continf.TxtPrj = StubPlnr::getStubPrjStd(dbsplnr, xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref), ixPlnrVLocale);

	// statshr
	statshr.TxtDsnAvail = evalTxtDsnAvail(dbsplnr);
	statshr.TxtPrjAvail = evalTxtPrjAvail(dbsplnr);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavPre::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavPre::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVPREDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDSNREMOVECLICK) {
					handleDpchAppDoButDsnRemoveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJREMOVECLICK) {
					handleDpchAppDoButPrjRemoveClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavPre::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavPre::handleDpchAppDoButDsnRemoveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFDSN, 0);

	refresh(dbsplnr, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavPre::handleDpchAppDoButPrjRemoveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFPRJ, 0);

	refresh(dbsplnr, moditems);

	*dpcheng = getNewDpchEng(moditems);
};


