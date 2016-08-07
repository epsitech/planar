/**
  * \file JobPlnrTpoExamples.cpp
  * job handler for job JobPlnrTpoExamples (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "JobPlnrTpoExamples.h"

// IP blksInclude --- BEGIN
#include "JobPlnrTpoExamples_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class JobPlnrTpoExamples
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
JobPlnrTpoExamples::JobPlnrTpoExamples(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::JOBPLNRTPOEXAMPLES, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

// IP constructor.spec1 --- INSERT

// IP constructor.cust2 --- IBEGIN
	Plnr::getRefsDtp(dbsplnr, refsDtp);
// IP constructor.cust2 --- IEND

// IP constructor.spec2 --- INSERT

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

JobPlnrTpoExamples::~JobPlnrTpoExamples() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT

// IP changeStage --- BEGIN
// IP changeStage.hdr --- BEGIN
void JobPlnrTpoExamples::changeStage(
			DbsPlnr* dbsplnr
			, uint _ixVSge
		) {
// IP changeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsplnr); break;
			case VecVSge::CREIDLE: leaveSgeCreidle(dbsplnr); break;
			case VecVSge::CREATE: leaveSgeCreate(dbsplnr); break;
			case VecVSge::EXPAND1: leaveSgeExpand1(dbsplnr); break;
			case VecVSge::EXPAND2: leaveSgeExpand2(dbsplnr); break;
			case VecVSge::PLOT: leaveSgePlot(dbsplnr); break;
			case VecVSge::DONE: leaveSgeDone(dbsplnr); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP changeStage.refresh --- IEND

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsplnr); break;
			case VecVSge::CREIDLE: _ixVSge = enterSgeCreidle(dbsplnr); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbsplnr); break;
			case VecVSge::EXPAND1: _ixVSge = enterSgeExpand1(dbsplnr); break;
			case VecVSge::EXPAND2: _ixVSge = enterSgeExpand2(dbsplnr); break;
			case VecVSge::PLOT: _ixVSge = enterSgePlot(dbsplnr); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsplnr); break;
		};
	};
};
// IP changeStage --- END

uint JobPlnrTpoExamples::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
// IP enterSgeIdle --- IEND
	return retval;
};

void JobPlnrTpoExamples::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint JobPlnrTpoExamples::enterSgeCreidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSge = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeCreidle --- INSERT
	return retval;
};

void JobPlnrTpoExamples::leaveSgeCreidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreidle --- INSERT
};

uint JobPlnrTpoExamples::enterSgeCreate(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::EXPAND1;
// IP enterSgeCreate --- IBEGIN
	ubigint refPrj;

	refPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	PlnrMStack* stk = NULL;

	ListPlnrMLayer lyrs;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	PlnrMTapeout* tpo = NULL;
	PlnrJMTapeoutState* tpj = NULL;

	// --- photpos

	// -- create root design
	refDsnPhotpos = dbsplnr->tblplnrmdesign->insertNewRec(NULL, 0, 0, VecPlnrVMDesignBasetype::TRLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 
				0, 0, 0, "photpos", 1, 0, "Photonic test structures, positive tone");

	// - xy (devices)
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 1, 0, 0, "incpl", VecPlnrVMDeviceAligntype::ABS, "vs", "", "", "",
				-25.0, -25.0, 120.0, "", refsDtp, "gratcpl", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "prd", "0.6");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "fill", "0.2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "20");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 2, 0, 0, "intap", VecPlnrVMDeviceAligntype::RDEV, "vstaw", "incpl.vea0", "vstae", "incpl.vwa0",
				0.0, 0.0, 0.0, "", refsDtp, "wgtap", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstart", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstop", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 3, 0, 0, "bend1", VecPlnrVMDeviceAligntype::RDEV, "vsw", "intap.vstow", "vse", "intap.vstoe",
				0.0, 0.0, 0.0, "", refsDtp, "wgbend", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "0.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "90.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 4, 0, 0, "indircpl", VecPlnrVMDeviceAligntype::RDEV, "vwg2ss", "bend1.vnw", "vwg2sn", "bend1.vne",
				0.0, 0.0, 0.0, "", refsDtp, "dircoup", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "wg2", "true");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew1", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew2", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "cpllen", "10.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "dist", "0.5");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 5, 0, 0, "bend2", VecPlnrVMDeviceAligntype::RDEV, "vnw", "indircpl.vwg1nn", "vne", "indircpl.vwg1ns",
				0.0, 0.0, 0.0, "", refsDtp, "wgbend", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "180.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "270.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 6, 0, 0, "discres", VecPlnrVMDeviceAligntype::RDEV, "vwg2sw", "bend2.vse", "vwg2se", "bend2.vsw",
				0.0, 0.0, 0.0, "", refsDtp, "discres", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "wg1", "false");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "wg2", "true");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "disc", "true");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "dist", "0.3");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 7, 0, 0, "bend3", VecPlnrVMDeviceAligntype::RDEV, "vne", "discres.vwg2nw", "vnw", "discres.vwg2ne",
				0.0, 0.0, 0.0, "", refsDtp, "wgbend", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "90.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "180.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 8, 0, 0, "outdircpl", VecPlnrVMDeviceAligntype::RDEV, "vwg1ss", "bend3.vsw", "vwg1sn", "bend3.vse",
				0.0, 0.0, 0.0, "", refsDtp, "dircoup", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "wg2", "true");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew1", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew2", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "cpllen", "10.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "dist", "0.5");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 9, 0, 0, "outtap1", VecPlnrVMDeviceAligntype::RDEV, "vstae", "outdircpl.vwg1nn", "vstaw", "outdircpl.vwg1ns",
				0.0, 0.0, 0.0, "", refsDtp, "wgtap", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstart", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstop", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 10, 0, 0, "outcpl1", VecPlnrVMDeviceAligntype::RDEV, "vwa0", "outtap1.vstow", "vea0", "outtap1.vstoe",
				0.0, 0.0, 0.0, "", refsDtp, "gratcpl", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "prd", "0.6");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "fill", "0.2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "20");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 11, 0, 0, "outtap2", VecPlnrVMDeviceAligntype::RDEV, "vstaw", "outdircpl.vwg2nn", "vstae", "outdircpl.vwg2ns",
				0.0, 0.0, 0.0, "", refsDtp, "wgtap", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstart", "0.38");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstop", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 12, 0, 0, "outcpl2", VecPlnrVMDeviceAligntype::RDEV, "vwa0", "outtap2.vstow", "vea0", "outtap2.vstoe",
				0.0, 0.0, 0.0, "", refsDtp, "gratcpl", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "prd", "0.6");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "fill", "0.2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "20");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 13, 0, 0, "bend4", VecPlnrVMDeviceAligntype::RDEV, "vsw", "indircpl.vwg2nn", "vse", "indircpl.vwg2ns",
				0.0, 0.0, 0.0, "", refsDtp, "wgbend", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "270.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "360.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 14, 0, 0, "wg1", VecPlnrVMDeviceAligntype::RDEV, "vsw", "bend4.vnw", "vse", "bend4.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 15, 0, 0, "wg2", VecPlnrVMDeviceAligntype::RDEV, "vsw", "wg1.vnw", "vse", "wg1.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 16, 0, 0, "bend5", VecPlnrVMDeviceAligntype::RDEV, "vsw", "wg2.vnw", "vse", "wg2.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wgbend", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "0.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "90.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.38");

	// - xy complementary
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 17, 0, 0, "mrknw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 18, 0, 0, "mrkne", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 19, 0, 0, "mrksw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 20, 0, 0, "mrkse", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 21, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Photonic (pos)");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 22, 0, 0, "annotn", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Planar");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 23, 0, 0, "annotw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 0.0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Test");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotpos, 24, 0, 0, "annote", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 0.0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "v0.1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	// - z (layers)
	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, refDsnPhotpos, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "");
	dbsplnr->tblplnrmstack->insertRec(stk);

	Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "phot", "0.0", "0", lyrs);
	Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 2, 0, VecPlnrVMLayerTtype::ZERO, "grat", "0.0", "0", lyrs);

	delete stk;

	// - xy vs. z
	Plnr::addLyrsru(dbsplnr, "phot", "incpl", "wg", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "incpl", "grat", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "intap", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "bend1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "indircpl", "wg1", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "indircpl", "wg2", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "bend2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "discres", "wg", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "discres", "disc", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "bend3", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outdircpl", "wg1", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outdircpl", "wg2", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outtap1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outcpl1", "wg", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "outcpl1", "grat", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outtap2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "outcpl2", "wg", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "outcpl2", "grat", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "bend4", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "wg1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "wg2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "bend5", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "mrknw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "mrknw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "mrkne", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "mrkne", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "mrksw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "mrksw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "mrkse", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "grat", "mrkse", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "annots", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "annotn", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "annotw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "phot", "annote", "all", lyrs, devs);

	// - tape-out
	refTpoPhotpos = dbsplnr->tblplnrmtapeout->insertNewRec(&tpo, 0, 0, VecPlnrVMTapeoutBasetype::BTCH, "Photonic test structures, positive tone", 1, 0, 0, 0, false, "");

	tpj = new PlnrJMTapeoutState(0, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpo->refJState = tpj->ref;
	tpo->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	delete tpj;

	dbsplnr->tblplnrrmprojectmtapeout->insertNewRec(NULL, refPrj, tpo->ref);

	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, tpo->ref, refDsnPhotpos, lyrs.nodes[0]->ref, "phot", 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, tpo->ref, refDsnPhotpos, lyrs.nodes[1]->ref, "grat", 0.0, 0.0);

	delete tpo;

	lyrs.clear();
	devs.clear();

	// --- photneg

	// -- create root design
	refDsnPhotneg = dbsplnr->tblplnrmdesign->insertNewRec(NULL, 0, 0, VecPlnrVMDesignBasetype::TRLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 
				0, 0, 0, "photneg", 1, 0, "Photonic test structures, negative tone");

	// - xy (devices)
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 1, 0, 0, "race", VecPlnrVMDeviceAligntype::ABS, "vwg1nc", "", "", "",
				0.0, 10.0, 0.0, "", refsDtp, "rtresneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "wg2", "false");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "cpllen", "10.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "dist", "0.3");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 2, 0, 0, "bend1", VecPlnrVMDeviceAligntype::RDEV, "vsw", "race.vwg1nw", "vse", "race.vwg1ne",
				0.0, 0.0, 0.0, "", refsDtp, "wgbendneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "0.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "90.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 3, 0, 0, "wg1", VecPlnrVMDeviceAligntype::RDEV, "vsw", "bend1.vnw", "vse", "bend1.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wgneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "32.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 4, 0, 0, "tap1", VecPlnrVMDeviceAligntype::RDEV, "vstaw", "wg1.vnw", "vstae", "wg1.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wgtapneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "10.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstart", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstop", "0.16");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "rectbox", "true");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 5, 0, 0, "wg2", VecPlnrVMDeviceAligntype::RDEV, "vsw", "tap1.vstow", "vse", "tap1.vstoe",
				0.0, 0.0, 0.0, "", refsDtp, "wgneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.16");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.17");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 6, 0, 0, "bend2", VecPlnrVMDeviceAligntype::RDEV, "vse", "race.vwg1sw", "vsw", "race.vwg1se",
				0.0, 0.0, 0.0, "", refsDtp, "wgbendneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "180.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "270.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "3.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 7, 0, 0, "wg3", VecPlnrVMDeviceAligntype::RDEV, "vne", "bend2.vnw", "vnw", "bend2.vne",
				0.0, 0.0, 0.0, "", refsDtp, "wgneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "32.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 8, 0, 0, "tap2", VecPlnrVMDeviceAligntype::RDEV, "vstaw", "wg3.vse", "vstae", "wg3.vsw",
				0.0, 0.0, 0.0, "", refsDtp, "wgtapneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "10.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstart", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "tapstop", "0.16");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "rectbox", "true");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 9, 0, 0, "wg4", VecPlnrVMDeviceAligntype::RDEV, "vne", "tap2.vstow", "vnw", "tap2.vstoe",
				0.0, 0.0, 0.0, "", refsDtp, "wgneg", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "0.16");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "clr", "2.17");

	// - xy complementary
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 10, 0, 0, "mrknw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 11, 0, 0, "mrkne", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 12, 0, 0, "mrksw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 13, 0, 0, "mrkse", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 14, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Photonic (neg)");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 15, 0, 0, "annotn", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Planar");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 16, 0, 0, "annotw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, -20.0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Test");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhotneg, 17, 0, 0, "annote", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 20.0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "v0.1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	// - z (layers)
	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, refDsnPhotneg, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "");
	dbsplnr->tblplnrmstack->insertRec(stk);

	Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "all", "0.0", "0", lyrs);

	delete stk;

	// - xy vs. z
	Plnr::addLyrsru(dbsplnr, "all", "race", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "bend1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "wg1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "tap1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "wg2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "bend2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "wg3", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "tap2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "wg4", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrknw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkne", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrksw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkse", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annots", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotn", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annote", "all", lyrs, devs);

	// - tape-out
	refTpoPhotneg = dbsplnr->tblplnrmtapeout->insertNewRec(&tpo, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "Photonic test structures, negative tone", 1, 0, 0, 0, false, "");

	tpj = new PlnrJMTapeoutState(0, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpo->refJState = tpj->ref;
	tpo->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	delete tpj;

	dbsplnr->tblplnrrmprojectmtapeout->insertNewRec(NULL, refPrj, tpo->ref);

	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, tpo->ref, refDsnPhotneg, lyrs.nodes[0]->ref, "all", 0.0, 0.0);

	delete tpo;

	lyrs.clear();
	devs.clear();

	// --- phc

	// -- create root design
	refDsnPhc = dbsplnr->tblplnrmdesign->insertNewRec(NULL, 0, 0, VecPlnrVMDesignBasetype::TRLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 
				0, 0, 0, "phc", 1, 0, "Photonic crystal test structures");

	// - xy (devices)
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 1, 0, 0, "phc1", VecPlnrVMDeviceAligntype::ABS, "vm0_n0_0", "", "", "",
				0.0, -25.0, 0.0, "", refsDtp, "phctrig", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "0.6");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "a", "2.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", "15");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "31");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 2, devs.nodes[devs.nodes.size()-1]->ref, 1, "phc1ld", VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "ptrcav", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstart", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstop", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstart", "-15");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstop", "15");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 3, devs.nodes[devs.nodes.size()-2]->ref, 2, "phc1l5_1", VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "ptrcav", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstart", "2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstop", "2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstart", "-10");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstop", "-6");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 4, devs.nodes[devs.nodes.size()-3]->ref, 3, "phc1l5_2", VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "ptrcav", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstart", "-2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstop", "-2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstart", "6");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstop", "10");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 4, 0, 0, "phc2", VecPlnrVMDeviceAligntype::ABS, "vm0_n0_0", "", "", "",
				0.0, 25.0, 0.0, "", refsDtp, "phctrig", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "a", "1.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", "25");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "25");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 5, devs.nodes[devs.nodes.size()-1]->ref, 1, "phc2cav", VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "ptrcav", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstart", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstop", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstart", "-1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstop", "1");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 6, devs.nodes[devs.nodes.size()-2]->ref, 2, "phc2cavfr", VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "ptrcavfr", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstart", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "mstop", "0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstart", "-1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "nstop", "1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "rstart", "0.2");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "rstep", "0.05");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "rN", "6");

	// - xy complementary
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 10, 0, 0, "mrknw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 11, 0, 0, "mrkne", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 12, 0, 0, "mrksw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 13, 0, 0, "mrkse", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 14, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Planar");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 15, 0, 0, "annotn", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 45.0, 180.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Photonic");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 16, 0, 0, "annotw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 0, 270.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Crystals");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnPhc, 17, 0, 0, "annote", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Trigonal");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	// - z (layers)
	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, refDsnPhc, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "");
	dbsplnr->tblplnrmstack->insertRec(stk);

	Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "all", "0.0", "0", lyrs);

	delete stk;

	// - xy vs. z
	Plnr::addLyrsru(dbsplnr, "all", "phc1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "phc2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrknw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkne", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrksw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkse", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annots", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotn", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annote", "all", lyrs, devs);

	// - tape-out
	refTpoPhc = dbsplnr->tblplnrmtapeout->insertNewRec(&tpo, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "Photonic crystal test structures", 1, 0, 0, 0, false, "");

	tpj = new PlnrJMTapeoutState(0, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpo->refJState = tpj->ref;
	tpo->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	delete tpj;

	dbsplnr->tblplnrrmprojectmtapeout->insertNewRec(NULL, refPrj, tpo->ref);

	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, tpo->ref, refDsnPhc, lyrs.nodes[0]->ref, "all", 0.0, 0.0);

	delete tpo;

	lyrs.clear();
	devs.clear();

	// --- var

	// -- create root design
	refDsnVar = dbsplnr->tblplnrmdesign->insertNewRec(NULL, 0, 0, VecPlnrVMDesignBasetype::TRLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 
				0, 0, 0, "var", 1, 0, "Various test structures");

	// - xy (devices)
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 1, 0, 0, "cross1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "cross", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "80.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "narrw", "1.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 2, 0, 0, "cross2", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-25.0, -25.0, -5.0, "", refsDtp, "cross", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "30.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "narrw", "0.5");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 3, 0, 0, "vdp1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				25.0, -25.0, 15.0, "", refsDtp, "vanderpauw", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "crsl", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "crsw", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "30.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 4, 0, 0, "txt1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				15.0, 15.0, 60.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "text*");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "4.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 5, 0, 0, "txt2", VecPlnrVMDeviceAligntype::RDEV, "vc5_47", "txt1.vc5_5", "vc5_5", "txt1.vc5_47",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "text*");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "4.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 6, 0, 0, "vdp2", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-25.0, 25.0, 0.0, "", refsDtp, "vanderpauw", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "crsl", "5.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "crsw", "0.5");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "30.0");

	// - xy complementary
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 10, 0, 0, "mrknw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 11, 0, 0, "mrkne", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 12, 0, 0, "mrksw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 13, 0, 0, "mrkse", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, -45.0, 0.0, "", refsDtp, "marker", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "10.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 14, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "various");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 15, 0, 0, "annotn", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 45.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Planar");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 16, 0, 0, "annotw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-45.0, 0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "Test");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsnVar, 17, 0, 0, "annote", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				45.0, 0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "v0.1");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "5.0");

	// - z (layers)
	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, refDsnVar, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "");
	dbsplnr->tblplnrmstack->insertRec(stk);

	Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "all", "0.0", "0", lyrs);

	delete stk;

	// - xy vs. z
	Plnr::addLyrsru(dbsplnr, "all", "cross1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "cross2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "vdp1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "txt1", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "txt2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "vdp2", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrknw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkne", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrksw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "mrkse", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annots", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotn", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annotw", "all", lyrs, devs);
	Plnr::addLyrsru(dbsplnr, "all", "annote", "all", lyrs, devs);

	// - tape-out
	refTpoVar = dbsplnr->tblplnrmtapeout->insertNewRec(&tpo, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "Various test structures", 1, 0, 0, 0, false, "");

	tpj = new PlnrJMTapeoutState(0, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpo->refJState = tpj->ref;
	tpo->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	delete tpj;

	dbsplnr->tblplnrrmprojectmtapeout->insertNewRec(NULL, refPrj, tpo->ref);

	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, tpo->ref, refDsnVar, lyrs.nodes[0]->ref, "all", 0.0, 0.0);

	delete tpo;

	lyrs.clear();
	devs.clear();

	retval = VecVSge::EXPAND1;

// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void JobPlnrTpoExamples::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint JobPlnrTpoExamples::enterSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND1;
	nextIxVSge = VecVSge::EXPAND2;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand1 --- IBEGIN
	// expand devices/stacks
	vector<DpchInvPlnr*> dpchinvs;

	PlnrExp_blks::getInvs(dbsplnr, refsDtp, refDsnPhotpos, dpchinvs);
	PlnrExp_blks::getInvs(dbsplnr, refsDtp, refDsnPhotneg, dpchinvs);
	PlnrExp_blks::getInvs(dbsplnr, refsDtp, refDsnPhc, dpchinvs);
	PlnrExp_blks::getInvs(dbsplnr, refsDtp, refDsnVar, dpchinvs);

	addInvs(dpchinvs);
// IP enterSgeExpand1 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrTpoExamples::leaveSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand1 --- INSERT
};

uint JobPlnrTpoExamples::enterSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND2;
	nextIxVSge = VecVSge::PLOT;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand2 --- IBEGIN
	// expand designs
	vector<DpchInvPlnr*> dpchinvs;

	dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refDsnPhotpos));
	dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refDsnPhotneg));
	dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refDsnPhc));
	dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refDsnVar));

	addInvs(dpchinvs);
// IP enterSgeExpand2 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrTpoExamples::leaveSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand2 --- INSERT
};

uint JobPlnrTpoExamples::enterSgePlot(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PLOT;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgePlot --- IBEGIN
	string s;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	vector<ubigint> refsSru;
	vector<ubigint> refsSubdev;

	vector<string> filenames;

	vector<DpchInvPlnr*> dpchinvs;

	vector<uint> orefs;

	// --- dtp
	dbsplnr->tblplnrmdevice->loadRstBySQL("SELECT * FROM TblPlnrMDevice WHERE supRefPlnrMDevice = 0 AND tplRefPlnrMDevice = 0 ORDER BY sref ASC", false, devs);

	for (unsigned int i=0;i<devs.nodes.size();i++) {
		dev = devs.nodes[i];

		// load structure refs
		dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV) + " AND hkUref = " + to_string(dev->ref), false, refsSru);

		// load eventual sub-device refs
		dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(dev->ref) + " ORDER BY supNum ASC", false, refsSubdev);

		dpchinvs.push_back(new DpchInvPlnrPlotDevsvg(0, 0, 750, 0, 0, dev->ref, refsSru, refsSubdev, false, true, true, 1000));
		filenames.push_back("dtp/" + dev->sref + "_vtxgds.xml");

		dpchinvs.push_back(new DpchInvPlnrPlotDevsvg(0, 0, 750, 0, 0, dev->ref, refsSru, refsSubdev, true, false, false, 1000));
		filenames.push_back("dtp/" + dev->sref + "_fces.xml");
	};

	// --- photpos
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhotpos, {}, false, false, true, true, true, 1000));
	filenames.push_back("photpos_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhotpos, {}, false, true, false, false, true, 1000));
	filenames.push_back("photpos_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.05, refTpoPhotpos));
	filenames.push_back("photpos.cif"); // won't work as it is a BTCH tape-out

	// --- photneg
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhotneg, {}, false, false, true, true, true, 1000));
	filenames.push_back("photneg_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhotneg, {}, false, true, false, false, true, 1000));
	filenames.push_back("photneg_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.05, refTpoPhotneg));
	filenames.push_back("photneg.cif");

	// --- phc
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhc, {}, false, false, true, true, true, 1000));
	filenames.push_back("phc_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnPhc, {}, false, true, false, false, true, 1000));
	filenames.push_back("phc_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.05, refTpoPhc));
	filenames.push_back("phc.cif");

	// --- var
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnVar, {}, false, false, true, true, true, 1000));
	filenames.push_back("var_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refDsnVar, {}, false, true, false, false, true, 1000));
	filenames.push_back("var_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.5, refTpoVar));
	filenames.push_back("var.cif");

	// --- pass to op processors
	addInvs(dpchinvs);

	// prepare collection of plot files in folder	with dtp subfolder
	plotfolder = Tmp::newfolder(xchg->tmppath);

	s = xchg->tmppath + "/" + plotfolder + "/dtp";
#ifdef _WIN32
	mkdir(s.c_str());
#else
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	for (unsigned int i=0;i<dpchinvs.size();i++) plots[dpchinvs[i]->oref] = filenames[i];
// IP enterSgePlot --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void JobPlnrTpoExamples::leaveSgePlot(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgePlot --- IBEGIN
	// .tgz result (plot) folder
	string s;
	s = "tar -czvf " + xchg->tmppath + "/" + plotfolder + ".tgz -C " + xchg->tmppath + "/" + plotfolder + " .";

	system(s.c_str());
// IP leaveSgePlot --- IEND
};

uint JobPlnrTpoExamples::enterSgeDone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
// IP enterSgeDone --- IEND
	return retval;
};

void JobPlnrTpoExamples::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string JobPlnrTpoExamples::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::CREATE) || (ixVSge == VecVSge::EXPAND1) || (ixVSge == VecVSge::EXPAND2) || (ixVSge == VecVSge::PLOT) ) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			if (ixVSge == VecVSge::CREATE) retval = "creating designs";
			else if (ixVSge == VecVSge::EXPAND1) retval = "expanding devices and stacks (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::EXPAND2) retval = "expanding designs (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::PLOT) retval = "generating plots (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- END
	return retval;
};

void JobPlnrTpoExamples::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\trun" << endl;
		} else if (req->cmd.compare("run") == 0) {
			req->retain = handleRun(dbsplnr);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
// IP handleRequest.ret --- RBEGIN
	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::RET) {
		if (ixVSge == VecVSge::PLOT) {
cout << "returning with oref=" << req->dpchret->oref << ", srefIxPlnrVDpch='" << VecPlnrVDpch::getSref(req->dpchret->ixPlnrVDpch) << "'" << endl;
			auto it = plots.find(req->dpchret->oref);
			if (it != plots.end()) {
				string s = "mv " + xchg->tmppath + "/";

				if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDEVSVG) {
					s += ((DpchRetPlnrPlotDevsvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNXYSVG) {
					s += ((DpchRetPlnrPlotDsnxysvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTTPOTXT) {
					s += ((DpchRetPlnrPlotTpotxt*) (req->dpchret))->ciffile;
				};

				s += " " + xchg->tmppath + "/" + plotfolder + "/" + it->second;
cout << "executing '" << s << "'" << endl;
				system(s.c_str());
			};
		};

		opNdone++;

		if (opNdone == opN) {
			clearOps();

			opNdone = 0;
			opN = 0;

			changeStage(dbsplnr, nextIxVSge);
		};
// IP handleRequest.ret --- REND
// IP handleRequest.timer --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::TIMER) {
		handleTimer(dbsplnr, req->sref);
// IP handleRequest.timer --- END
	};
};

bool JobPlnrTpoExamples::handleRun(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
// IP handleRun --- IBEGIN
	changeStage(dbsplnr, VecVSge::CREIDLE);
// IP handleRun --- IEND
	return retval;
};

void JobPlnrTpoExamples::handleTimer(
			DbsPlnr* dbsplnr
			, const string& sref
		) {
	if (ixVSge == VecVSge::CREIDLE) {
		changeStage(dbsplnr, nextIxVSge);
	} else if ((ixVSge == VecVSge::EXPAND1) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.expand1.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.expand1.mon --- IEND
	} else if ((ixVSge == VecVSge::EXPAND2) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.expand2.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.expand2.mon --- IEND
	} else if ((ixVSge == VecVSge::PLOT) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.plot.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.plot.mon --- IEND
	};
};


