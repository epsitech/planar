/**
  * \file CrdPlnrTpo.cpp
  * job handler for job CrdPlnrTpo (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "CrdPlnrTpo.h"

// IP blksInclude --- BEGIN
#include "CrdPlnrTpo_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "CrdPlnrTpo_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class CrdPlnrTpo
 ******************************************************************************/

CrdPlnrTpo::CrdPlnrTpo(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
			, const ubigint ref
		) : JobPlnr(xchg, VecPlnrVJob::CRDPLNRTPO, jrefSup, ixPlnrVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgusecase = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

	// initialize according to ref
	changeRef(dbsplnr, jref, ref, false);

	pnlrec = new PnlPlnrTpoRec(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnlheadbar = new PnlPlnrTpoHeadbar(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnllist = new PnlPlnrTpoList(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	changeStage(dbsplnr, VecVSge::IDLE);

	xchg->addClstn(VecPlnrVCall::CALLPLNRDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

CrdPlnrTpo::~CrdPlnrTpo() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* CrdPlnrTpo::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdPlnrTpo::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdPlnrTpo/" + VecPlnrVLocale::getSref(ixPlnrVLocale);
	continf.MtxCrdTpo = StubPlnr::getStubTpoStd(dbsplnr, xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref), ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsplnr);
	statshr.MitCrdUcsAvail = evalMitCrdUcsAvail(dbsplnr);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdPlnrTpo::changeRef(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixPlnrVAccess;
	xchg->triggerIxRefToIxCall(dbsplnr, VecPlnrVCall::CALLPLNRACCESS, jref, VecPlnrVMaintable::TBLPLNRMTAPEOUT, ref, ixPlnrVAccess);

	if (ixPlnrVAccess != VecPlnrVAccess::NONE) {
		xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXACC, jref, ixPlnrVAccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsplnr, VecPlnrVCall::CALLPLNRLOG, jref, VecPlnrVPreset::VOID, 0, "CrdPlnrTpo", ref);
		xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref, ref);

		refresh(dbsplnr, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));

		if (pnllist) pnllist->updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFTPO, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFTPO, jrefTrig, notif);
	};
};

void CrdPlnrTpo::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- INSERT
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void CrdPlnrTpo::changeStage(
			DbsPlnr* dbsplnr
			, uint _ixVSge
			, DpchEngPlnr** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsplnr); break;
			case VecVSge::ALRPLNRABT: leaveSgeAlrplnrabt(dbsplnr); break;
			case VecVSge::CLOSE: leaveSgeClose(dbsplnr); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh --- INSERT

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsplnr); break;
			case VecVSge::ALRPLNRABT: _ixVSge = enterSgeAlrplnrabt(dbsplnr); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsplnr); break;
		};
	};
};
// IP changeStage --- END

uint CrdPlnrTpo::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdPlnrTpo::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint CrdPlnrTpo::enterSgeAlrplnrabt(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::ALRPLNRABT;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrplnrabt --- BEGIN
	xchg->submitDpch(AlrPlnr::prepareAlrAbt(jref, ixPlnrVLocale, feedFMcbAlert));
// IP enterSgeAlrplnrabt --- END
	return retval;
};

void CrdPlnrTpo::leaveSgeAlrplnrabt(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeAlrplnrabt --- INSERT
};

uint CrdPlnrTpo::enterSgeClose(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDCLOSE, jref, VecPlnrVCard::CRDPLNRTPO);
	return retval;
};

void CrdPlnrTpo::leaveSgeClose(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeClose --- INSERT
};

string CrdPlnrTpo::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
// IP getSquawk --- END
	return retval;
};

void CrdPlnrTpo::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUCSCLICK) {
					handleDpchAppDoMitCrdUcsClick(dbsplnr, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRALERT) {
			handleDpchAppPlnrAlert(dbsplnr, (DpchAppPlnrAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdPlnrTpo::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdPlnrTpo::handleDpchAppDoClose(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	changeStage(dbsplnr, VecVSge::CLOSE);
};

void CrdPlnrTpo::handleDpchAppDoMitAppAbtClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsplnr, VecVSge::ALRPLNRABT, dpcheng);
// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdPlnrTpo::handleDpchAppDoMitCrdUcsClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	if (!dlgusecase) {
		dlgusecase = new DlgPlnrTpoUsecase(xchg, dbsplnr, jref, ixPlnrVLocale);
		statshr.jrefDlgusecase = dlgusecase->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdPlnrTpo::handleDpchAppPlnrAlert(
			DbsPlnr* dbsplnr
			, DpchAppPlnrAlert* dpchappplnralert
			, DpchEngPlnr** dpcheng
		) {
	if (ixVSge == VecVSge::ALRPLNRABT) {
		changeStage(dbsplnr, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
};

void CrdPlnrTpo::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDLGCLOSE) {
		call->abort = handleCallPlnrDlgClose(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTATCHG) {
		call->abort = handleCallPlnrStatChg(dbsplnr, call->jref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRREFPRESET) {
		call->abort = handleCallPlnrRefPreSet(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdPlnrTpo::handleCallPlnrDlgClose(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgusecase) {
		delete dlgusecase;
		dlgusecase = NULL;
		statshr.jrefDlgusecase = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

bool CrdPlnrTpo::handleCallPlnrStatChg(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixPlnrVExpstate == VecPlnrVExpstate::REGD) && (pnlrec->statshr.ixPlnrVExpstate == VecPlnrVExpstate::REGD)) pnllist->minimize(dbsplnr, true);
	return retval;
};

bool CrdPlnrTpo::handleCallPlnrRefPreSet(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecPlnrVPreset::PREPLNRREFTPO) {
		changeRef(dbsplnr, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsplnr, true);
	};

	return retval;
};


