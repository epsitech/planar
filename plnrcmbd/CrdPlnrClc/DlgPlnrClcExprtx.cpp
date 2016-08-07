/**
  * \file DlgPlnrClcExprtx.cpp
  * job handler for job DlgPlnrClcExprtx (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "DlgPlnrClcExprtx.h"

// IP blksInclude --- BEGIN
#include "DlgPlnrClcExprtx_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class DlgPlnrClcExprtx
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgPlnrClcExprtx::DlgPlnrClcExprtx(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::DLGPLNRCLCEXPRTX, jrefSup, ixPlnrVLocale) {
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

// IP constructor.spec3 --- INSERT
};

DlgPlnrClcExprtx::~DlgPlnrClcExprtx() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* DlgPlnrClcExprtx::getNewDpchEng(
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

void DlgPlnrClcExprtx::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {

// IP refresh --- BEGIN
// IP refresh --- END
};

void DlgPlnrClcExprtx::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCEXPRTXDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgPlnrClcExprtx::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgPlnrClcExprtx::handleDpchAppDoButDneClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDneClick --- INSERT
};


