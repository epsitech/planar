/**
  * \file PnlPlnrCliAAMCalcPar.cpp
  * job handler for job PnlPlnrCliAAMCalcPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrCliAAMCalcPar.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrCliAAMCalcPar_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrCliAAMCalcPar_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrCliAAMCalcPar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrCliAAMCalcPar::PnlPlnrCliAAMCalcPar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRCLIAAMCALCPAR, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::MNR, "ong", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::MNR, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::OOD, "red", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::OOD, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::SLM, "yel", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::SLM, ixPlnrVLocale));
	feedFCsiQst.appendIxSrefTitles(VecPlnrVQrystate::UTD, "grn", VecPlnrVQrystate::getTitle(VecPlnrVQrystate::UTD, ixPlnrVLocale));

	qry = NULL;

// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref, 0);

	muteRefresh = false;

	qry = new QryPlnrCliAAMCalcPar(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsplnr, moditems);

	xchg->addClstn(VecPlnrVCall::CALLPLNRSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

};

PnlPlnrCliAAMCalcPar::~PnlPlnrCliAAMCalcPar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrCliAAMCalcPar::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlPlnrCliAAMCalcPar::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixPlnrVQrystate);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlPlnrCliAAMCalcPar::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCLI) {
		xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->refresh(dbsplnr);
		refresh(dbsplnr, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
// IP updatePreset --- END
};

void PnlPlnrCliAAMCalcPar::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsplnr, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsplnr, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDUPLICATECLICK) {
					handleDpchAppDoButDuplicateClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrCliAAMCalcPar::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrCliAAMCalcPar::handleDpchAppDataStgiac(
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

void PnlPlnrCliAAMCalcPar::handleDpchAppDataStgiacqry(
			DbsPlnr* dbsplnr
			, QryPlnrCliAAMCalcPar::StgIac* _stgiacqry
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryPlnrCliAAMCalcPar::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryPlnrCliAAMCalcPar::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->refresh(dbsplnr);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryPlnrCliAAMCalcPar::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

			xchg->addRefPreset(VecPlnrVPreset::PREPLNRREFSEL, jref, refSelNew);
			qry->refreshJnum();
		};

		refresh(dbsplnr, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrCliAAMCalcPar::handleDpchAppDoButNewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlPlnrCliAAMCalcPar::handleDpchAppDoButDuplicateClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDuplicateClick --- INSERT
};

void PnlPlnrCliAAMCalcPar::handleDpchAppDoButDeleteClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlPlnrCliAAMCalcPar::handleDpchAppDoButRefreshClick(
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

void PnlPlnrCliAAMCalcPar::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTATCHG) {
		call->abort = handleCallPlnrStatChg(dbsplnr, call->jref);
	};
};

bool PnlPlnrCliAAMCalcPar::handleCallPlnrStatChg(
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


