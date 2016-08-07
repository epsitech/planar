/**
  * \file PnlPlnrNavAdmin.cpp
  * job handler for job PnlPlnrNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavAdmin.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavAdmin_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavAdmin_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavAdmin
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavAdmin::PnlPlnrNavAdmin(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVADMIN, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstFil.tag = "FeedFLstFil";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbsplnr, moditems);
	refreshUsr(dbsplnr, moditems);
	refreshPrs(dbsplnr, moditems);
	refreshFil(dbsplnr, moditems);
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRUSG, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRUSR, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRPRS, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRFIL, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
};

PnlPlnrNavAdmin::~PnlPlnrNavAdmin() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFil, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrNavAdmin::refreshLstUsg(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbsplnr);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavAdmin::refreshUsg(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRUSG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubPlnr::getStubUsgStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbsplnr, moditems);
};

void PnlPlnrNavAdmin::refreshLstUsr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbsplnr);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavAdmin::refreshUsr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRUSR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubPlnr::getStubUsrStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbsplnr, moditems);
};

void PnlPlnrNavAdmin::refreshLstPrs(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbsplnr);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavAdmin::refreshPrs(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRPRS, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubPlnr::getStubPrsStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbsplnr, moditems);
};

void PnlPlnrNavAdmin::refreshLstFil(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbsplnr);
	statshr.ButFilViewActive = evalButFilViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavAdmin::refreshFil(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRFIL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubPlnr::getStubFilStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbsplnr, moditems);
};

void PnlPlnrNavAdmin::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlPlnrNavAdmin::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	refreshLstUsg(dbsplnr, moditems);
	refreshLstUsr(dbsplnr, moditems);
	refreshLstPrs(dbsplnr, moditems);
	refreshLstFil(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavAdmin::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavAdmin::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsg");
	};
};

void PnlPlnrNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsg");
};

void PnlPlnrNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsr");
	};
};

void PnlPlnrNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrUsr");
};

void PnlPlnrNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrs");
	};
};

void PnlPlnrNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrs");
};

void PnlPlnrNavAdmin::handleDpchAppDoButFilViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrFil");
	};
};

void PnlPlnrNavAdmin::handleDpchAppDoButFilNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrFil");
};

void PnlPlnrNavAdmin::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallPlnrHusrRunvMod_crdUsrEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlPlnrNavAdmin::handleCallPlnrHusrRunvMod_crdUsrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVCard::CRDPLNRUSG) {
		refreshUsg(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRUSR) {
		refreshUsr(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRPRS) {
		refreshPrs(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRFIL) {
		refreshFil(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


