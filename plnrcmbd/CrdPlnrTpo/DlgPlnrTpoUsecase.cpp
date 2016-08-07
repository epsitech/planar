/**
  * \file DlgPlnrTpoUsecase.cpp
  * job handler for job DlgPlnrTpoUsecase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "DlgPlnrTpoUsecase.h"

// IP blksInclude --- BEGIN
#include "DlgPlnrTpoUsecase_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgPlnrTpoUsecase_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgPlnrTpoUsecase
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgPlnrTpoUsecase::DlgPlnrTpoUsecase(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::DLGPLNRTPOUSECASE, jrefSup, ixPlnrVLocale) {
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

	jobexamples = NULL;
	jobicabatch1 = NULL;
	jobicabatch2 = NULL;
	jobicabatch3 = NULL;
	jobuvslides = NULL;

// IP constructor.cust1 --- IBEGIN
	ixVUcs = VecVUcs::EXAMPLES;
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

DlgPlnrTpoUsecase::~DlgPlnrTpoUsecase() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* DlgPlnrTpoUsecase::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacprp, &continf, &continfgen, &feedFDse, &feedFPrpPupUcs, &feedFSge, &statshr, &statshrcfi, &statshrgen, &statshrprp, items);
	};

	return dpcheng;
};

void DlgPlnrTpoUsecase::refreshPrp(
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

void DlgPlnrTpoUsecase::refreshGen(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInfGen oldContinfgen(continfgen);
	StatShrGen oldStatshrgen(statshrgen);

// IP refreshGen --- RBEGIN
	// continfgen
	continfgen.TxtPrg = getSquawk(dbsplnr);

	// statshrgen
	statshrgen.ButRunActive = evalGenButRunActive(dbsplnr);
	statshrgen.ButStoActive = evalGenButStoActive(dbsplnr);

// IP refreshGen --- REND
	if (continfgen.diff(&oldContinfgen).size() != 0) insert(moditems, DpchEngData::CONTINFGEN);
	if (statshrgen.diff(&oldStatshrgen).size() != 0) insert(moditems, DpchEngData::STATSHRGEN);
};

void DlgPlnrTpoUsecase::refreshCfi(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShrCfi oldStatshrcfi(statshrcfi);

// IP refreshCfi --- BEGIN
	// statshrcfi
	statshrcfi.DldActive = evalCfiDldActive(dbsplnr);

// IP refreshCfi --- END
	if (statshrcfi.diff(&oldStatshrcfi).size() != 0) insert(moditems, DpchEngData::STATSHRCFI);
};

void DlgPlnrTpoUsecase::refresh(
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
	refreshGen(dbsplnr, moditems);
	refreshCfi(dbsplnr, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgPlnrTpoUsecase::changeStage(
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

uint DlgPlnrTpoUsecase::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgPlnrTpoUsecase::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgPlnrTpoUsecase::enterSgeCreate(
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

void DlgPlnrTpoUsecase::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint DlgPlnrTpoUsecase::enterSgeCredone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREDONE;
	nextIxVSge = retval;
// IP enterSgeCredone --- INSERT
	return retval;
};

void DlgPlnrTpoUsecase::leaveSgeCredone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCredone --- INSERT
};

uint DlgPlnrTpoUsecase::enterSgeRun(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = VecVSge::RUN;
// IP enterSgeRun --- IBEGIN

	if (ixVUcs == VecVUcs::EXAMPLES) {
		if (!jobexamples) jobexamples = new JobPlnrTpoExamples(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobexamples->changeStage(dbsplnr, JobPlnrTpoExamples::VecVSge::CREIDLE);
	} else if (ixVUcs == VecVUcs::ICABATCH1) {
		if (!jobicabatch1) jobicabatch1 = new JobPlnrTpoIcabatch1(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobicabatch1->changeStage(dbsplnr, JobPlnrTpoIcabatch1::VecVSge::CREIDLE);
	} else if (ixVUcs == VecVUcs::ICABATCH2) {
		if (!jobicabatch2) jobicabatch2 = new JobPlnrTpoIcabatch2(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobicabatch2->changeStage(dbsplnr, JobPlnrTpoIcabatch2::VecVSge::CREIDLE);
	} else if (ixVUcs == VecVUcs::ICABATCH3) {
		if (!jobicabatch3) jobicabatch3 = new JobPlnrTpoIcabatch3(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobicabatch3->changeStage(dbsplnr, JobPlnrTpoIcabatch3::VecVSge::CREIDLE);
	} else if (ixVUcs == VecVUcs::UVSLIDES) {
		if (!jobuvslides) jobuvslides = new JobPlnrTpoUvslides(xchg, dbsplnr, jref, ixPlnrVLocale);
		jobuvslides->changeStage(dbsplnr, JobPlnrTpoUvslides::VecVSge::CREIDLE);
	};

// IP enterSgeRun --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgPlnrTpoUsecase::leaveSgeRun(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeRun --- INSERT
};

uint DlgPlnrTpoUsecase::enterSgeDone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgPlnrTpoUsecase::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- IBEGIN
	if (jobexamples) {
		delete jobexamples;
		jobexamples = NULL;
	} else if (jobicabatch1) {
		delete jobicabatch1;
		jobicabatch1 = NULL;
	} else if (jobicabatch2) {
		delete jobicabatch2;
		jobicabatch2 = NULL;
	} else if (jobicabatch3) {
		delete jobicabatch3;
		jobicabatch3 = NULL;
	} else if (jobuvslides) {
		delete jobuvslides;
		jobuvslides = NULL;
	};
// IP leaveSgeDone --- IEND
};

string DlgPlnrTpoUsecase::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- RBEGIN

	if ( (ixVSge == VecVSge::CREDONE) || (ixVSge == VecVSge::RUN) ) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "project created";
			else if (ixVSge == VecVSge::RUN) {
				retval = "generating " + VecVUcs::getTitle(ixVUcs) + ": ";

				if ((ixVUcs == VecVUcs::EXAMPLES) && jobexamples) retval += jobexamples->getSquawk(dbsplnr);
				else if ((ixVUcs == VecVUcs::ICABATCH1) && jobicabatch1) retval += jobicabatch1->getSquawk(dbsplnr);
				else if ((ixVUcs == VecVUcs::ICABATCH2) && jobicabatch2) retval += jobicabatch2->getSquawk(dbsplnr);
				else if ((ixVUcs == VecVUcs::ICABATCH3) && jobicabatch3) retval += jobicabatch3->getSquawk(dbsplnr);
				else if ((ixVUcs == VecVUcs::UVSLIDES) && jobuvslides) retval += jobuvslides->getSquawk(dbsplnr);
			};
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};

// IP getSquawk --- REND
	return retval;
};

void DlgPlnrTpoUsecase::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACPRP)) {
				handleDpchAppDataContiacprp(dbsplnr, &(dpchappdata->contiacprp), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsplnr, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoGen != 0) {
				if (dpchappdo->ixVDoGen == VecVDoGen::BUTRUNCLICK) {
					handleDpchAppDoGenButRunClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDoGen == VecVDoGen::BUTSTOCLICK) {
					handleDpchAppDoGenButStoClick(dbsplnr, &(req->dpcheng));
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

void DlgPlnrTpoUsecase::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgPlnrTpoUsecase::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::PRP) && (_contiac->numFDse <= VecVDit::CFI)) ixVDit = _contiac->numFDse;
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgPlnrTpoUsecase::handleDpchAppDataContiacprp(
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
		valid = ((_contiacprp->numFPupUcs >= VecVUcs::EXAMPLES) && (_contiacprp->numFPupUcs <= VecVUcs::UVSLIDES));
		
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

void DlgPlnrTpoUsecase::handleDpchAppDoButDneClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRDLGCLOSE, jref);
// IP handleDpchAppDoButDneClick --- IEND
};

void DlgPlnrTpoUsecase::handleDpchAppDoGenButRunClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoGenButRunClick --- BEGIN
	if (statshrgen.ButRunActive) {
		if (ixVSge == VecVSge::CREDONE) {
			changeStage(dbsplnr, VecVSge::RUN, dpcheng);
		};
	};
// IP handleDpchAppDoGenButRunClick --- END
};

void DlgPlnrTpoUsecase::handleDpchAppDoGenButStoClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoGenButStoClick --- INSERT
};

void DlgPlnrTpoUsecase::handleDpchAppDoPrpButCreClick(
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

string DlgPlnrTpoUsecase::handleDownload(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP handleDownload --- IBEGIN

	if ((ixVUcs == VecVUcs::EXAMPLES) && jobexamples) retval = xchg->tmppath + "/" + jobexamples->plotfolder + ".tgz";
	else if ((ixVUcs == VecVUcs::ICABATCH1) && jobicabatch1) retval = xchg->tmppath + "/" + jobicabatch1->plotfolder + ".tgz";
	else if ((ixVUcs == VecVUcs::ICABATCH2) && jobicabatch2) retval = xchg->tmppath + "/" + jobicabatch2->plotfolder + ".tgz";
//	else if ((ixVUcs == VecVUcs::ICABATCH3) && jobicabatch3) retval = xchg->tmppath + "/" + jobicabatch3->plotfolder + ".tgz";
	else if ((ixVUcs == VecVUcs::UVSLIDES) && jobuvslides) retval = xchg->tmppath + "/" + jobuvslides->plotfolder + ".tgz";

// IP handleDownload --- IEND
	return retval;
};

void DlgPlnrTpoUsecase::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRSTATCHG) {
		call->abort = handleCallPlnrStatChg(dbsplnr, call->jref);
	};
};

bool DlgPlnrTpoUsecase::handleCallPlnrStatChg(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;
// IP handleCallPlnrStatChg --- IBEGIN

	set<uint> moditems;
	bool done = false;

	if (ixVSge == VecVSge::RUN) {
		if ((ixVUcs == VecVUcs::EXAMPLES) && jobexamples) {
			if (jobexamples->ixVSge == JobPlnrTpoExamples::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		} else if ((ixVUcs == VecVUcs::ICABATCH1) && jobicabatch1) {
			if (jobicabatch1->ixVSge == JobPlnrTpoIcabatch1::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		} else if ((ixVUcs == VecVUcs::ICABATCH2) && jobicabatch2) {
			if (jobicabatch2->ixVSge == JobPlnrTpoIcabatch2::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		} else if ((ixVUcs == VecVUcs::ICABATCH3) && jobicabatch3) {
			if (jobicabatch3->ixVSge == JobPlnrTpoIcabatch3::VecVSge::DONE) {
				done = true;
				changeStage(dbsplnr, VecVSge::DONE);
			};
		} else if ((ixVUcs == VecVUcs::UVSLIDES) && jobuvslides) {
			if (jobuvslides->ixVSge == JobPlnrTpoUvslides::VecVSge::DONE) {
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


