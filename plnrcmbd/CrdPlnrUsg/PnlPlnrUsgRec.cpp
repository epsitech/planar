/**
  * \file PnlPlnrUsgRec.cpp
  * job handler for job PnlPlnrUsgRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrUsgRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrUsgRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrUsgRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrUsgRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrUsgRec::PnlPlnrUsgRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRUSGREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlaaccess = NULL;
	pnlmnuser = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFUSG, jref);
};

PnlPlnrUsgRec::~PnlPlnrUsgRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrUsgRec::getNewDpchEng(
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

void PnlPlnrUsgRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubUsgStd(dbsplnr, recUsg.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUsg.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaaccess) {delete pnlaaccess; pnlaaccess = NULL;};
		if (pnlmnuser) {delete pnlmnuser; pnlmnuser = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlPlnrUsgDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlaaccess) pnlaaccess = new PnlPlnrUsgAAccess(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmnuser) pnlmnuser = new PnlPlnrUsgMNUser(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAAccess = ((pnlaaccess) ? pnlaaccess->jref : 0);
	statshr.jrefMNUser = ((pnlmnuser) ? pnlmnuser->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrUsgRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFUSG) {
		PlnrMUsergroup* _recUsg = NULL;

		recUsg.ref = 0;

		if (dbsplnr->tblplnrmusergroup->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSG, jref), &_recUsg)) {
			recUsg = *_recUsg;

			delete _recUsg;
		};

		if (recUsg.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlaaccess) pnlaaccess->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmnuser) pnlmnuser->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrUsgRec::minimize(
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

void PnlPlnrUsgRec::regularize(
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

void PnlPlnrUsgRec::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGRECDO) {
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

void PnlPlnrUsgRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrUsgRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrUsgRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrUsgRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRUSGUPD_REFEQ) {
		call->abort = handleCallPlnrUsgUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrUsgRec::handleCallPlnrUsgUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrUsgUpd_refEq --- INSERT
	return retval;
};


