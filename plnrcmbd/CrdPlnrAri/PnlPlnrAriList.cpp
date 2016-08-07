/**
  * \file PnlPlnrAriList.cpp
  * job handler for job PnlPlnrAriList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrAriList.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrAriList_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrAriList_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrAriList
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrAriList::PnlPlnrAriList(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRARILIST, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::MNR, "ong", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::MNR, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::OOD, "red", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::OOD, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::SLM, "yel", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::SLM, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::UTD, "grn", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::UTD, ixPlnrVLocale));
	feedFTos.tag = "FeedFTos";
	QryPlnrAriList::VecVOrd::fillFeed(feedFTos);

	qry = NULL;

// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref, xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref, QryPlnrAriList::VecVOrd::I);

	muteRefresh = false;

	qry = new QryPlnrAriList(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	statshr.ixPlnrVExpstate = ((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref)) ? VecPlnrVExpstate::MIND : VecPlnrVExpstate::REGD);
	refresh(dbsplnr, moditems);

	xchg->addClstn(VecPlnrVCall::CALLPLNRSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

};

PnlPlnrAriList::~PnlPlnrAriList() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrAriList::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFCsiQst, &feedFTos, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlPlnrAriList::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixPlnrVQrystate);

	uint ixPre = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXPRE, jref);
	if ((ixPre != 0) && (ixPre != VecPlnrVPreset::VOID)) {
		continf.TxtFor = VecPlnrVPreset::getTitle(ixPre, ixPlnrVLocale);

		if (ixPre == VecPlnrVPreset::PREPLNRREFTPO) continf.TxtPre = StubPlnr::getStubTpoStd(dbsplnr, xchg->getRefPreset(ixPre, jref), ixPlnrVLocale, Stub::VecVNonetype::FULL);

	} else {
		continf.TxtFor = "";
	};

	// contiac
	contiac.numFTos = xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void PnlPlnrAriList::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARI) {
		xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref, xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref));
		qry->refreshJnum();
		refresh(dbsplnr, moditems);

		insert(moditems, DpchEngData::STGIACQRY);

		if ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrAriList::minimize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::MIND) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrAriList::regularize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::REGD) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrAriList::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARILISTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsplnr, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsplnr, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARILISTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILTERCLICK) {
					handleDpchAppDoButFilterClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrAriList::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrAriList::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFTOS)) {
		if ((_contiac->numFTos >= QryPlnrAriList::VecVOrd::I) && (_contiac->numFTos <= QryPlnrAriList::VecVOrd::DSN)) {
			xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXORD, jref, _contiac->numFTos);

			qry->refresh(dbsplnr);
			refresh(dbsplnr, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrAriList::handleDpchAppDataStgiac(
			DbsPlnr* dbsplnr
			, StgIac* _stgiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrAriList::handleDpchAppDataStgiacqry(
			DbsPlnr* dbsplnr
			, QryPlnrAriList::StgIac* _stgiacqry
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryPlnrAriList::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryPlnrAriList::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->refresh(dbsplnr);
			refresh(dbsplnr, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryPlnrAriList::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);
			xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFARI, refSelNew);
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrAriList::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrAriList::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrAriList::handleDpchAppDoButNewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlPlnrAriList::handleDpchAppDoButDeleteClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlPlnrAriList::handleDpchAppDoButFilterClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButFilterClick --- INSERT
};

void PnlPlnrAriList::handleDpchAppDoButRefreshClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->refresh(dbsplnr, false);
	refresh(dbsplnr, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrAriList::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTATCHG) {
		call->abort = handleCallPlnrStatChg(dbsplnr, call->jref);
	};
};

bool PnlPlnrAriList::handleCallPlnrStatChg(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;
// IP handleCallPlnrStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbsplnr, moditems);
			if (qry->ixPlnrVQrystate == VecPlnrVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

// IP handleCallPlnrStatChg --- END
	return retval;
};


