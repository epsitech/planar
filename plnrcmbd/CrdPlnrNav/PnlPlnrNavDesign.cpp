/**
  * \file PnlPlnrNavDesign.cpp
  * job handler for job PnlPlnrNavDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrNavDesign.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrNavDesign_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrNavDesign_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrNavDesign
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrNavDesign::PnlPlnrNavDesign(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRNAVDESIGN, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstDgd.tag = "FeedFLstDgd";
	feedFLstDom.tag = "FeedFLstDom";
	feedFLstDsn.tag = "FeedFLstDsn";
	feedFLstDvc.tag = "FeedFLstDvc";
	feedFLstLyr.tag = "FeedFLstLyr";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstSru.tag = "FeedFLstSru";
	feedFLstStk.tag = "FeedFLstStk";

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrj(dbsplnr, moditems);
	refreshDsn(dbsplnr, moditems);
	refreshDom(dbsplnr, moditems);
	refreshDgd(dbsplnr, moditems);
	refreshDvc(dbsplnr, moditems);
	refreshSru(dbsplnr, moditems);
	refreshStk(dbsplnr, moditems);
	refreshLyr(dbsplnr, moditems);
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRPRJ, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRDSN, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRDOM, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRDGD, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRDVC, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRSRU, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRSTK, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecPlnrVCard::CRDPLNRLYR, xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), Clstn::VecVJactype::LOCK);
};

PnlPlnrNavDesign::~PnlPlnrNavDesign() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrNavDesign::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstDgd, &feedFLstDom, &feedFLstDsn, &feedFLstDvc, &feedFLstLyr, &feedFLstPrj, &feedFLstSru, &feedFLstStk, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrNavDesign::refreshLstPrj(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrjAvail = evalLstPrjAvail(dbsplnr);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshPrj(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrj = 0;

	// feedFLstPrj
	feedFLstPrj.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRPRJ, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrj.appendRefTitles(rec->ref, StubPlnr::getStubPrjStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrj(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstDsn(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDsnAvail = evalLstDsnAvail(dbsplnr);
	statshr.ButDsnViewActive = evalButDsnViewActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshDsn(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDsn = 0;

	// feedFLstDsn
	feedFLstDsn.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRDSN, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDsn.appendRefTitles(rec->ref, StubPlnr::getStubDsnStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDSN);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDsn(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstDom(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDomAvail = evalLstDomAvail(dbsplnr);
	statshr.ButDomViewActive = evalButDomViewActive(dbsplnr);
	statshr.ButDomNewcrdActive = evalButDomNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshDom(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDom = 0;

	// feedFLstDom
	feedFLstDom.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRDOM, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDom.appendRefTitles(rec->ref, StubPlnr::getStubDomStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDOM);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDom(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstDgd(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDgdAvail = evalLstDgdAvail(dbsplnr);
	statshr.ButDgdViewActive = evalButDgdViewActive(dbsplnr);
	statshr.ButDgdNewcrdActive = evalButDgdNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshDgd(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDgd = 0;

	// feedFLstDgd
	feedFLstDgd.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRDGD, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDgd.appendRefTitles(rec->ref, StubPlnr::getStubDgdStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDGD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDgd(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstDvc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDvcAvail = evalLstDvcAvail(dbsplnr);
	statshr.ButDvcViewActive = evalButDvcViewActive(dbsplnr);
	statshr.ButDvcNewcrdActive = evalButDvcNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshDvc(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDvc = 0;

	// feedFLstDvc
	feedFLstDvc.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRDVC, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDvc.appendRefTitles(rec->ref, StubPlnr::getStubDvcStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDVC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDvc(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstSru(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSruAvail = evalLstSruAvail(dbsplnr);
	statshr.ButSruViewActive = evalButSruViewActive(dbsplnr);
	statshr.ButSruNewcrdActive = evalButSruNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshSru(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSru = 0;

	// feedFLstSru
	feedFLstSru.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRSRU, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstSru.appendRefTitles(rec->ref, StubPlnr::getStubSruStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSRU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSru(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstStk(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstStkAvail = evalLstStkAvail(dbsplnr);
	statshr.ButStkViewActive = evalButStkViewActive(dbsplnr);
	statshr.ButStkNewcrdActive = evalButStkNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshStk(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstStk = 0;

	// feedFLstStk
	feedFLstStk.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRSTK, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstStk.appendRefTitles(rec->ref, StubPlnr::getStubStkStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSTK);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstStk(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refreshLstLyr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstLyrAvail = evalLstLyrAvail(dbsplnr);
	statshr.ButLyrViewActive = evalButLyrViewActive(dbsplnr);
	statshr.ButLyrNewcrdActive = evalButLyrNewcrdActive(dbsplnr);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrNavDesign::refreshLyr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListPlnrHistRMUserUniversal rst;
	PlnrHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstLyr = 0;

	// feedFLstLyr
	feedFLstLyr.clear();

	dbsplnr->tblplnrhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref), VecPlnrVCard::CRDPLNRLYR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstLyr.appendRefTitles(rec->ref, StubPlnr::getStubLyrStd(dbsplnr, rec->unvUref, ixPlnrVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTLYR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstLyr(dbsplnr, moditems);
};

void PnlPlnrNavDesign::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlPlnrNavDesign::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsplnr, moditems);

	refreshLstPrj(dbsplnr, moditems);
	refreshLstDsn(dbsplnr, moditems);
	refreshLstDom(dbsplnr, moditems);
	refreshLstDgd(dbsplnr, moditems);
	refreshLstDvc(dbsplnr, moditems);
	refreshLstSru(dbsplnr, moditems);
	refreshLstStk(dbsplnr, moditems);
	refreshLstLyr(dbsplnr, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlPlnrNavDesign::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJNEWCRDCLICK) {
					handleDpchAppDoButPrjNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNVIEWCLICK) {
					handleDpchAppDoButDsnViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDSNNEWCRDCLICK) {
					handleDpchAppDoButDsnNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDOMVIEWCLICK) {
					handleDpchAppDoButDomViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDOMNEWCRDCLICK) {
					handleDpchAppDoButDomNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDGDVIEWCLICK) {
					handleDpchAppDoButDgdViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDGDNEWCRDCLICK) {
					handleDpchAppDoButDgdNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDVCVIEWCLICK) {
					handleDpchAppDoButDvcViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDVCNEWCRDCLICK) {
					handleDpchAppDoButDvcNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSRUVIEWCLICK) {
					handleDpchAppDoButSruViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSRUNEWCRDCLICK) {
					handleDpchAppDoButSruNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTKVIEWCLICK) {
					handleDpchAppDoButStkViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTKNEWCRDCLICK) {
					handleDpchAppDoButStkNewcrdClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLYRVIEWCLICK) {
					handleDpchAppDoButLyrViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLYRNEWCRDCLICK) {
					handleDpchAppDoButLyrNewcrdClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrNavDesign::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrNavDesign::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTPRJ)) {
		contiac.numFLstPrj = _contiac->numFLstPrj;
		if (dbsplnr->tblplnrhistrmuseruniversal->loadUnuByRef(feedFLstPrj.getRefByNum(contiac.numFLstPrj), ref)) xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFPRJ, ref);
		refreshLstPrj(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDSN)) {
		contiac.numFLstDsn = _contiac->numFLstDsn;
		if (dbsplnr->tblplnrhistrmuseruniversal->loadUnuByRef(feedFLstDsn.getRefByNum(contiac.numFLstDsn), ref)) xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFDSN, ref);
		refreshLstDsn(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDOM)) {
		contiac.numFLstDom = _contiac->numFLstDom;
		refreshLstDom(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDGD)) {
		contiac.numFLstDgd = _contiac->numFLstDgd;
		refreshLstDgd(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDVC)) {
		contiac.numFLstDvc = _contiac->numFLstDvc;
		refreshLstDvc(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSRU)) {
		contiac.numFLstSru = _contiac->numFLstSru;
		refreshLstSru(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSTK)) {
		contiac.numFLstStk = _contiac->numFLstStk;
		refreshLstStk(dbsplnr, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTLYR)) {
		contiac.numFLstLyr = _contiac->numFLstLyr;
		refreshLstLyr(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrNavDesign::handleDpchAppDoButPrjViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrjAvail && statshr.ButPrjViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstPrj.getRefByNum(contiac.numFLstPrj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrPrj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrj");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButPrjNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrPrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrPrj");
};

void PnlPlnrNavDesign::handleDpchAppDoButDsnViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDsnAvail && statshr.ButDsnViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstDsn.getRefByNum(contiac.numFLstDsn), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrDsn", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDsn");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDsnNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDsn", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDsn");
};

void PnlPlnrNavDesign::handleDpchAppDoButDomViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDomAvail && statshr.ButDomViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstDom.getRefByNum(contiac.numFLstDom), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrDom", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDom");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDomNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButDomNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDom", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDom");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDgdViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDgdAvail && statshr.ButDgdViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstDgd.getRefByNum(contiac.numFLstDgd), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrDgd", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDgd");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDgdNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButDgdNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDgd", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDgd");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDvcViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDvcAvail && statshr.ButDvcViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstDvc.getRefByNum(contiac.numFLstDvc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrDvc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDvc");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButDvcNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButDvcNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrDvc", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrDvc");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButSruViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSruAvail && statshr.ButSruViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstSru.getRefByNum(contiac.numFLstSru), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrSru", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrSru");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButSruNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSruNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrSru", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrSru");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButStkViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstStkAvail && statshr.ButStkViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstStk.getRefByNum(contiac.numFLstStk), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrStk", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrStk");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButStkNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButStkNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrStk", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrStk");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButLyrViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	PlnrHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstLyrAvail && statshr.ButLyrViewActive) {
		if (dbsplnr->tblplnrhistrmuseruniversal->loadRecByRef(feedFLstLyr.getRefByNum(contiac.numFLstLyr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, husrRunv->ixPlnrVPreset, husrRunv->preUref, "CrdPlnrLyr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrLyr");
	};
};

void PnlPlnrNavDesign::handleDpchAppDoButLyrNewcrdClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButLyrNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsplnr, VecPlnrVCall::CALLPLNRCRDOPEN, jref, 0, 0, "CrdPlnrLyr", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngPlnrConfirm(false, 0, "");
		else *dpcheng = new DpchEngPlnrConfirm(true, jrefNew, "CrdPlnrLyr");
	};
};

void PnlPlnrNavDesign::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallPlnrHusrRunvMod_crdUsrEq(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlPlnrNavDesign::handleCallPlnrHusrRunvMod_crdUsrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecPlnrVCard::CRDPLNRPRJ) {
		refreshPrj(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRDSN) {
		refreshDsn(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRDOM) {
		refreshDom(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRDGD) {
		refreshDgd(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRDVC) {
		refreshDvc(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRSRU) {
		refreshSru(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRSTK) {
		refreshStk(dbsplnr, moditems);
	} else if (ixInv == VecPlnrVCard::CRDPLNRLYR) {
		refreshLyr(dbsplnr, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


