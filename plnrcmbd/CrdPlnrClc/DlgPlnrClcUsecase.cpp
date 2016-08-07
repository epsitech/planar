/**
  * \file DlgPlnrClcUsecase.cpp
  * job handler for job DlgPlnrClcUsecase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "DlgPlnrClcUsecase.h"

// IP blksInclude --- BEGIN
#include "DlgPlnrClcUsecase_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgPlnrClcUsecase_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgPlnrClcUsecase
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgPlnrClcUsecase::DlgPlnrClcUsecase(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::DLGPLNRCLCUSECASE, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixPlnrVLocale, feedFDse);
	feedFPrpPupUcs.tag = "FeedFPrpPupUcs";
	VecVUcs::fillFeed(feedFPrpPupUcs);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	jobdisptest = NULL;
	jobqcdslab = NULL;

// IP constructor.cust1 --- IBEGIN
	ixVUcs = VecVUcs::DISPTEST;
	valid = false;
// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::PRP;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsplnr, moditems);

	xchg->addClstn(VecPlnrVCall::CALLPLNRSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgPlnrClcUsecase::~DlgPlnrClcUsecase() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* DlgPlnrClcUsecase::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacprp, &continf, &continfcal, &feedFDse, &feedFPrpPupUcs, &feedFSge, &statshr, &statshrcal, &statshrprp, &statshrrfi, items);
	};

	return dpcheng;
};

void DlgPlnrClcUsecase::refreshPrp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIacPrp oldContiacprp(contiacprp);
	StatShrPrp oldStatshrprp(statshrprp);

// IP refreshPrp --- BEGIN
	// contiacprp

	// statshrprp
	statshrprp.ButCreActive = evalPrpButCreActive(dbsplnr);

// IP refreshPrp --- END
	if (contiacprp.diff(&oldContiacprp).size() != 0) insert(moditems, DpchEngData::CONTIACPRP);
	if (statshrprp.diff(&oldStatshrprp).size() != 0) insert(moditems, DpchEngData::STATSHRPRP);
};

void DlgPlnrClcUsecase::refreshCal(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInfCal oldContinfcal(continfcal);
	StatShrCal oldStatshrcal(statshrcal);

// IP refreshCal --- RBEGIN
	// continfcal
	continfcal.TxtPrg = getSquawk(dbsplnr);

	// statshrcal
	statshrcal.ButRunActive = evalCalButRunActive(dbsplnr);
	statshrcal.ButStoActive = evalCalButStoActive(dbsplnr);

// IP refreshCal --- REND
	if (continfcal.diff(&oldContinfcal).size() != 0) insert(moditems, DpchEngData::CONTINFCAL);
	if (statshrcal.diff(&oldStatshrcal).size() != 0) insert(moditems, DpchEngData::STATSHRCAL);
};

void DlgPlnrClcUsecase::refreshRfi(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShrRfi oldStatshrrfi(statshrrfi);

// IP refreshRfi --- BEGIN
	// statshrrfi
	statshrrfi.DldActive = evalRfiDldActive(dbsplnr);

// IP refreshRfi --- END
	if (statshrrfi.diff(&oldStatshrrfi).size() != 0) insert(moditems, DpchEngData::STATSHRRFI);
};

void DlgPlnrClcUsecase::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsplnr);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPrp(dbsplnr, moditems);
	refreshCal(dbsplnr, moditems);
	refreshRfi(dbsplnr, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgPlnrClcUsecase::changeStage(
			DbsPlnr* dbsplnr
			, uint _ixVSge
			, DpchEngPlnr** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsplnr); break;
			case VecVSge::CREATE: leaveSgeCreate(dbsplnr); break;
			case VecVSge::CREDONE: leaveSgeCredone(dbsplnr); break;
			case VecVSge::RUN: leaveSgeRun(dbsplnr); break;
			case VecVSge::DONE: leaveSgeDone(dbsplnr); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh --- IBEGIN
		set<uint> moditems;
		refresh(dbsplnr, moditems);
		
		if (dpcheng) {
			if (*dpcheng) delete *dpcheng;
			*dpcheng = getNewDpchEng(moditems);
		} else xchg->submitDpch(getNewDpchEng(moditems));
// IP changeStage.refresh --- IEND

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsplnr); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbsplnr); break;
			case VecVSge::CREDONE: _ixVSge = enterSgeCredone(dbsplnr); break;
			case VecVSge::RUN: _ixVSge = enterSgeRun(dbsplnr); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsplnr); break;
		};
	};
};
// IP changeStage --- END

uint DlgPlnrClcUsecase::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgPlnrClcUsecase::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgPlnrClcUsecase::enterSgeCreate(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::CREDONE;
// IP enterSgeCreate --- IBEGIN

	PlnrMProject prj;

	prj.grp = xchg->getRefPreset(VecPlnrVPreset::PREPLNRGRP, jref);
	prj.own = xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref);
	prj.Title = "";

	for (unsigned int i=1;true;i++) {
		if (i == 1) prj.Title = contiacprp.TxfPti;
		else prj.Title = contiacprp.TxfPti + " (" + to_string(i) + ")";

		if (!dbsplnr->tblplnrmproject->loadRefByTit(prj.Title, prj.ref)) break;
	};

	prj.ref = 0;
	dbsplnr->tblplnrmproject->insertRec(&prj);

	xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRREFPRJ, prj.ref);

// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgPlnrClcUsecase::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint DlgPlnrClcUsecase::enterSgeCredone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREDONE;
	nextIxVSge = retval;
// IP enterSgeCredone --- INSERT
	return retval;
};

void DlgPlnrClcUsecase::leaveSgeCredone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCredone --- INSERT
};

uint DlgPlnrClcUsecase::enterSgeRun(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = VecVSge::RUN;
// IP enterSgeRun --- IBEGIN

	if (ixVUcs == VecVUcs::DISPTEST) {
		if (!jobdisptest) jobdisptest = new JobPlnrClcDisptest(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobdisptest->handleRun(dbsplnr); // changes to VecVSge::PRPIDLE after initialization
	}	else if (ixVUcs == VecVUcs::QCDSLAB) {
		if (!jobqcdslab) jobqcdslab = new JobPlnrClcQcdslab(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobqcdslab->handleRun(dbsplnr); // changes to VecVSge::PRPIDLE after initialization
	};

// IP enterSgeRun --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgPlnrClcUsecase::leaveSgeRun(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeRun --- INSERT
};

uint DlgPlnrClcUsecase::enterSgeDone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgPlnrClcUsecase::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- IBEGIN
	if (jobdisptest) {
		delete jobdisptest;
		jobdisptest = NULL;
	} else if (jobqcdslab) {
		delete jobqcdslab;
		jobqcdslab = NULL;
	};
// IP leaveSgeDone --- IEND
};

string DlgPlnrClcUsecase::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- RBEGIN

	if ( (ixVSge == VecVSge::CREDONE) || (ixVSge == VecVSge::RUN) ) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "project created";
			else if (ixVSge == VecVSge::RUN) {
				retval = "running " + VecVUcs::getTitle(ixVUcs) + ": ";

				if ((ixVUcs == VecVUcs::DISPTEST) && jobdisptest) retval += jobdisptest->getSquawk(dbsplnr);
				else if ((ixVUcs == VecVUcs::QCDSLAB) && jobqcdslab) retval += jobqcdslab->getSquawk(dbsplnr);
			};
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};

// IP getSquawk --- REND
	return retval;
};

void DlgPlnrClcUsecase::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACPRP)) {
				handleDpchAppDataContiacprp(dbsplnr, &(dpchappdata->contiacprp), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsplnr, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoCal != 0) {
				if (dpchappdo->ixVDoCal == VecVDoCal::BUTRUNCLICK) {
					handleDpchAppDoCalButRunClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDoCal == VecVDoCal::BUTSTOCLICK) {
					handleDpchAppDoCalButStoClick(dbsplnr, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoPrp != 0) {
				if (dpchappdo->ixVDoPrp == VecVDoPrp::BUTCRECLICK) {
					handleDpchAppDoPrpButCreClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
// IP handleRequest.download --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsplnr);
// IP handleRequest.download --- END
	};
};

void DlgPlnrClcUsecase::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgPlnrClcUsecase::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::PRP) && (_contiac->numFDse <= VecVDit::RFI)) ixVDit = _contiac->numFDse;
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgPlnrClcUsecase::handleDpchAppDataContiacprp(
			DbsPlnr* dbsplnr
			, ContIacPrp* _contiacprp
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacprp->diff(&contiacprp);
// IP handleDpchAppDataContiacprp --- IBEGIN

	// validate TxfPti
	valid = (_contiacprp->TxfPti.length() >= 3);

	if (valid) contiacprp.TxfPti = _contiacprp->TxfPti;
	else contiacprp.TxfPti = "";

	if (valid) {
		// validate numFPupUcs
		valid = ((_contiacprp->numFPupUcs >= VecVUcs::DISPTEST) && (_contiacprp->numFPupUcs <= VecVUcs::QCDSLAB));
		
		if (valid) {
			contiacprp.numFPupUcs = _contiacprp->numFPupUcs;
			ixVUcs = contiacprp.numFPupUcs;
		};
	};

	refresh(dbsplnr, moditems);

// IP handleDpchAppDataContiacprp --- IEND
	insert(moditems, DpchEngData::CONTIACPRP);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgPlnrClcUsecase::handleDpchAppDoButDneClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRDLGCLOSE, jref);
// IP handleDpchAppDoButDneClick --- IEND
};

void DlgPlnrClcUsecase::handleDpchAppDoCalButRunClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoCalButRunClick --- BEGIN
	if (statshrcal.ButRunActive) {
		if (ixVSge == VecVSge::CREDONE) {
			changeStage(dbsplnr, VecVSge::RUN, dpcheng);
		};
	};
// IP handleDpchAppDoCalButRunClick --- END
};

void DlgPlnrClcUsecase::handleDpchAppDoCalButStoClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoCalButStoClick --- INSERT
};

void DlgPlnrClcUsecase::handleDpchAppDoPrpButCreClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoPrpButCreClick --- BEGIN
	if (statshrprp.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsplnr, VecVSge::CREATE, dpcheng);
		};
	};
// IP handleDpchAppDoPrpButCreClick --- END
};

string DlgPlnrClcUsecase::handleDownload(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP handleDownload --- IBEGIN

	if ((ixVUcs == VecVUcs::DISPTEST) && jobdisptest) retval = xchg->tmppath + "/" + jobdisptest->plotfolder + ".tgz";
	else if ((ixVUcs == VecVUcs::QCDSLAB) && jobqcdslab) retval = xchg->tmppath + "/" + jobqcdslab->plotfolder + ".tgz";

// IP handleDownload --- IEND
	return retval;
};

void DlgPlnrClcUsecase::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTATCHG) {
		call->abort = handleCallPlnrStatChg(dbsplnr, call->jref);
	};
};

bool DlgPlnrClcUsecase::handleCallPlnrStatChg(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;
// IP handleCallPlnrStatChg --- IBEGIN

	set<uint> moditems;
	bool done = false;

	if (ixVSge == VecVSge::RUN) {
		if ((ixVUcs == VecVUcs::DISPTEST) && jobdisptest) {
			if (jobdisptest->ixVSge == JobPlnrClcDisptest::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		} else if ((ixVUcs == VecVUcs::QCDSLAB) && jobqcdslab) {
			if (jobqcdslab->ixVSge == JobPlnrClcQcdslab::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		};
	};

	if (!done) {
		refresh(dbsplnr, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};

// IP handleCallPlnrStatChg --- IEND
	return retval;
};


