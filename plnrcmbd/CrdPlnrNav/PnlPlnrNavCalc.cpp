/**
  * \file PnlPlnrNavCalc.cpp
  * job handler for job PnlPlnrNavCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavCalc.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavCalc_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavCalc_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavCalc
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavCalc::PnlPlnrNavCalc(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVCALC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstClc.tag = "FeedFLstClc";
	feedFLstCli.tag = "FeedFLstCli";

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshClc(dbsplnr, moditems);
	refreshCli(dbsplnr, moditems);
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRCLC, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRCLI, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
};

PnlPlnrNavCalc::~PnlPlnrNavCalc() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavCalc::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstClc, &feedFLstCli, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrNavCalc::refreshLstClc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstClcAvail = evalLstClcAvail(dbsplnr);
	statshr.ButClcViewActive = evalButClcViewActive(dbsplnr);
	statshr.ButClcNewcrdActive = evalButClcNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavCalc::refreshClc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstClc = 0;

	// feedFLstClc
	feedFLstClc.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRCLC, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstClc.appendRefTitles(rec->ref, StubPlnr::getStubClcStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCLC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstClc(dbsplnr, moditems);
};

void PnlPlnrNavCalc::refreshLstCli(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCliAvail = evalLstCliAvail(dbsplnr);
	statshr.ButCliViewActive = evalButCliViewActive(dbsplnr);
	statshr.ButCliNewcrdActive = evalButCliNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavCalc::refreshCli(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCli = 0;

	// feedFLstCli
	feedFLstCli.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRCLI, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstCli.appendRefTitles(rec->ref, StubPlnr::getStubCliStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCLI);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCli(dbsplnr, moditems);
};

void PnlPlnrNavCalc::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlPlnrNavCalc::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	refreshLstClc(dbsplnr, moditems);
	refreshLstCli(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavCalc::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVCALCDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVCALCDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCLCVIEWCLICK) {
					handleDpchAppDoButClcViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLCNEWCRDCLICK) {
					handleDpchAppDoButClcNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLIVIEWCLICK) {
					handleDpchAppDoButCliViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLINEWCRDCLICK) {
					handleDpchAppDoButCliNewcrdClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavCalc::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavCalc::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTCLC)) {
		contiac.numFLstClc = _contiac->numFLstClc;
		refreshLstClc(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCLI)) {
		contiac.numFLstCli = _contiac->numFLstCli;
		refreshLstCli(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavCalc::handleDpchAppDoButClcViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstClcAvail && statshr.ButClcViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstClc.getRefByNum(contiac.numFLstClc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrClc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrClc");
	};
};

void PnlPlnrNavCalc::handleDpchAppDoButClcNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButClcNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrClc", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrClc");
	};
};

void PnlPlnrNavCalc::handleDpchAppDoButCliViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCliAvail && statshr.ButCliViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstCli.getRefByNum(contiac.numFLstCli), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrCli", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCli");
	};
};

void PnlPlnrNavCalc::handleDpchAppDoButCliNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButCliNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrCli", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCli");
	};
};

void PnlPlnrNavCalc::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallPlnrHusrRunvMod_crdUsrEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlPlnrNavCalc::handleCallPlnrHusrRunvMod_crdUsrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVCard::CRDPLNRCLC) {
		refreshClc(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRCLI) {
		refreshCli(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


