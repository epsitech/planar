/**
  * \file CrdPlnrNav.cpp
  * job handler for job CrdPlnrNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "CrdPlnrNav.h"

// IP blksInclude --- BEGIN
#include "CrdPlnrNav_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "CrdPlnrNav_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class CrdPlnrNav
 ******************************************************************************/

CrdPlnrNav::CrdPlnrNav(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::CRDPLNRNAV, jrefSup, ixPlnrVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgloaini = NULL;
	pnlheadbar = NULL;
	pnlpre = NULL;
	pnladmin = NULL;
	pnlglobal = NULL;
	pnldesign = NULL;
	pnlcalc = NULL;
	pnllayout = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

	set<uint> moditems;
	refresh(dbsplnr, moditems);

	pnlheadbar = new PnlPlnrNavHeadbar(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnlpre = new PnlPlnrNavPre(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnladmin = new PnlPlnrNavAdmin(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnlglobal = new PnlPlnrNavGlobal(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnldesign = new PnlPlnrNavDesign(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnlcalc = new PnlPlnrNavCalc(xchg, dbsplnr, jref, ixPlnrVLocale);
	pnllayout = new PnlPlnrNavLayout(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefGlobal = pnlglobal->jref;
	statshr.jrefDesign = pnldesign->jref;
	statshr.jrefCalc = pnlcalc->jref;
	statshr.jrefLayout = pnllayout->jref;

	changeStage(dbsplnr, VecVSge::IDLE);

	xchg->addClstn(VecPlnrVCall::CALLPLNRDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

CrdPlnrNav::~CrdPlnrNav() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* CrdPlnrNav::getNewDpchEng(
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

void CrdPlnrNav::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdPlnrNav/" + VecPlnrVLocale::getSref(ixPlnrVLocale);

	s = StubPlnr::getStubSesMenu(dbsplnr, xchg->getRefPreset(VecPlnrVPreset::PREPLNRSESS, jref), ixPlnrVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbsplnr);
	statshr.pnladminAvail = evalPnladminAvail(dbsplnr);
	statshr.pnlglobalAvail = evalPnlglobalAvail(dbsplnr);
	statshr.pnldesignAvail = evalPnldesignAvail(dbsplnr);
	statshr.pnlcalcAvail = evalPnlcalcAvail(dbsplnr);
	statshr.pnllayoutAvail = evalPnllayoutAvail(dbsplnr);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsplnr);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbsplnr);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbsplnr);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbsplnr);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbsplnr);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbsplnr);
	statshr.MitCrdDtpAvail = evalMitCrdDtpAvail(dbsplnr);
	statshr.MitCrdCtpAvail = evalMitCrdCtpAvail(dbsplnr);
	statshr.MitCrdMatAvail = evalMitCrdMatAvail(dbsplnr);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbsplnr);
	statshr.MitCrdPrjAvail = evalMitCrdPrjAvail(dbsplnr);
	statshr.MitCrdDsnAvail = evalMitCrdDsnAvail(dbsplnr);
	statshr.MitCrdDomAvail = evalMitCrdDomAvail(dbsplnr);
	statshr.MitCrdDomActive = evalMitCrdDomActive(dbsplnr);
	statshr.MitCrdDgdAvail = evalMitCrdDgdAvail(dbsplnr);
	statshr.MitCrdDgdActive = evalMitCrdDgdActive(dbsplnr);
	statshr.MitCrdDvcAvail = evalMitCrdDvcAvail(dbsplnr);
	statshr.MitCrdDvcActive = evalMitCrdDvcActive(dbsplnr);
	statshr.MitCrdSruAvail = evalMitCrdSruAvail(dbsplnr);
	statshr.MitCrdSruActive = evalMitCrdSruActive(dbsplnr);
	statshr.MitCrdStkAvail = evalMitCrdStkAvail(dbsplnr);
	statshr.MitCrdStkActive = evalMitCrdStkActive(dbsplnr);
	statshr.MitCrdLyrAvail = evalMitCrdLyrAvail(dbsplnr);
	statshr.MitCrdLyrActive = evalMitCrdLyrActive(dbsplnr);
	statshr.MspCrd4Avail = evalMspCrd4Avail(dbsplnr);
	statshr.MitCrdClcAvail = evalMitCrdClcAvail(dbsplnr);
	statshr.MitCrdClcActive = evalMitCrdClcActive(dbsplnr);
	statshr.MitCrdCliAvail = evalMitCrdCliAvail(dbsplnr);
	statshr.MitCrdCliActive = evalMitCrdCliActive(dbsplnr);
	statshr.MspCrd5Avail = evalMspCrd5Avail(dbsplnr);
	statshr.MitCrdTpoAvail = evalMitCrdTpoAvail(dbsplnr);
	statshr.MspApp2Avail = evalMspApp2Avail(dbsplnr);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbsplnr);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdPlnrNav::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
	if (pnlglobal) pnlglobal->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
	if (pnldesign) pnldesign->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
	if (pnlcalc) pnlcalc->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
	if (pnllayout) pnllayout->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
// IP updatePreset --- END
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void CrdPlnrNav::changeStage(
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

uint CrdPlnrNav::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdPlnrNav::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint CrdPlnrNav::enterSgeAlrplnrabt(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::ALRPLNRABT;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrplnrabt --- BEGIN
	xchg->submitDpch(AlrPlnr::prepareAlrAbt(jref, ixPlnrVLocale, feedFMcbAlert));
// IP enterSgeAlrplnrabt --- END
	return retval;
};

void CrdPlnrNav::leaveSgeAlrplnrabt(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeAlrplnrabt --- INSERT
};

uint CrdPlnrNav::enterSgeClose(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDCLOSE, jref, VecPlnrVCard::CRDPLNRNAV);
	return retval;
};

void CrdPlnrNav::leaveSgeClose(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeClose --- INSERT
};

string CrdPlnrNav::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
// IP getSquawk --- END
	return retval;
};

void CrdPlnrNav::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDTPCLICK) {
					handleDpchAppDoMitCrdDtpClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCTPCLICK) {
					handleDpchAppDoMitCrdCtpClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMATCLICK) {
					handleDpchAppDoMitCrdMatClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRJCLICK) {
					handleDpchAppDoMitCrdPrjClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDSNCLICK) {
					handleDpchAppDoMitCrdDsnClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDOMCLICK) {
					handleDpchAppDoMitCrdDomClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDGDCLICK) {
					handleDpchAppDoMitCrdDgdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDVCCLICK) {
					handleDpchAppDoMitCrdDvcClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSRUCLICK) {
					handleDpchAppDoMitCrdSruClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSTKCLICK) {
					handleDpchAppDoMitCrdStkClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLYRCLICK) {
					handleDpchAppDoMitCrdLyrClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCLCCLICK) {
					handleDpchAppDoMitCrdClcClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCLICLICK) {
					handleDpchAppDoMitCrdCliClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTPOCLICK) {
					handleDpchAppDoMitCrdTpoClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbsplnr, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRALERT) {
			handleDpchAppPlnrAlert(dbsplnr, (DpchAppPlnrAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdPlnrNav::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdPlnrNav::handleDpchAppDoClose(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	changeStage(dbsplnr, VecVSge::CLOSE);
};

void CrdPlnrNav::handleDpchAppDoMitAppAbtClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsplnr, VecVSge::ALRPLNRABT, dpcheng);
// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdPlnrNav::handleDpchAppDoMitSesTrmClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	changeStage(dbsplnr, VecVSge::CLOSE);
};

void CrdPlnrNav::handleDpchAppDoMitCrdUsgClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsg");
};

void CrdPlnrNav::handleDpchAppDoMitCrdUsrClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsr");
};

void CrdPlnrNav::handleDpchAppDoMitCrdPrsClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrs");
};

void CrdPlnrNav::handleDpchAppDoMitCrdFilClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrFil");
};

void CrdPlnrNav::handleDpchAppDoMitCrdDtpClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDtp");
};

void CrdPlnrNav::handleDpchAppDoMitCrdCtpClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrCtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCtp");
};

void CrdPlnrNav::handleDpchAppDoMitCrdMatClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrMat", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrMat");
};

void CrdPlnrNav::handleDpchAppDoMitCrdPrjClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrPrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrj");
};

void CrdPlnrNav::handleDpchAppDoMitCrdDsnClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDsn", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDsn");
};

void CrdPlnrNav::handleDpchAppDoMitCrdDomClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDom", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDom");
};

void CrdPlnrNav::handleDpchAppDoMitCrdDgdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDgd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDgd");
};

void CrdPlnrNav::handleDpchAppDoMitCrdDvcClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDvc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDvc");
};

void CrdPlnrNav::handleDpchAppDoMitCrdSruClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrSru", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrSru");
};

void CrdPlnrNav::handleDpchAppDoMitCrdStkClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrStk", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrStk");
};

void CrdPlnrNav::handleDpchAppDoMitCrdLyrClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrLyr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrLyr");
};

void CrdPlnrNav::handleDpchAppDoMitCrdClcClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrClc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrClc");
};

void CrdPlnrNav::handleDpchAppDoMitCrdCliClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrCli", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrCli");
};

void CrdPlnrNav::handleDpchAppDoMitCrdTpoClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrTpo", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrTpo");
};

void CrdPlnrNav::handleDpchAppDoMitAppLoiClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgPlnrNavLoaini(xchg, dbsplnr, jref, ixPlnrVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdPlnrNav::handleDpchAppPlnrAlert(
			DbsPlnr* dbsplnr
			, DpchAppPlnrAlert* dpchappplnralert
			, DpchEngPlnr** dpcheng
		) {
	if (ixVSge == VecVSge::ALRPLNRABT) {
		changeStage(dbsplnr, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
};

void CrdPlnrNav::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDLGCLOSE) {
		call->abort = handleCallPlnrDlgClose(dbsplnr, call->jref);
	};
};

bool CrdPlnrNav::handleCallPlnrDlgClose(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};


