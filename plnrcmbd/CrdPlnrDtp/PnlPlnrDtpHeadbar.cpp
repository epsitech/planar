/**
  * \file PnlPlnrDtpHeadbar.cpp
  * job handler for job PnlPlnrDtpHeadbar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDtpHeadbar.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDtpHeadbar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class PnlPlnrDtpHeadbar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDtpHeadbar::PnlPlnrDtpHeadbar(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDTPHEADBAR, jrefSup, ixPlnrVLocale) {
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

PnlPlnrDtpHeadbar::~PnlPlnrDtpHeadbar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDtpHeadbar::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, items);
	};

	return dpcheng;
};

void PnlPlnrDtpHeadbar::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
};

void PnlPlnrDtpHeadbar::handleRequest(
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

		};
	};
};

void PnlPlnrDtpHeadbar::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};


