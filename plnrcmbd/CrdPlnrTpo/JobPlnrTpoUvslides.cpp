/**
  * \file JobPlnrTpoUvslides.cpp
  * job handler for job JobPlnrTpoUvslides (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "JobPlnrTpoUvslides.h"

// IP blksInclude --- BEGIN
#include "JobPlnrTpoUvslides_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class JobPlnrTpoUvslides
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
JobPlnrTpoUvslides::JobPlnrTpoUvslides(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::JOBPLNRTPOUVSLIDES, jrefSup, ixPlnrVLocale) {
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

JobPlnrTpoUvslides::~JobPlnrTpoUvslides() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
PlnrMDesign* JobPlnrTpoUvslides::createDsn(
			DbsPlnr* dbsplnr
			, const ubigint refPrj
			, const string& Title
			, const string& Comment
			, const string& annots
			, const string& annotw
			, ubigint& refLyrstruct
			, ubigint& refLyrannot
		) {
	PlnrMDesign* dsn = NULL;
	
	PlnrMStack* stk = NULL;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	// design, stack and layers
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 0, 
				0, 0, Title, 1, 0, Comment);
	dbsplnr->tblplnrmdesign->insertRec(dsn);

	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, dsn->ref, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "0");
	dbsplnr->tblplnrmstack->insertRec(stk);

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "struct", "0.0", "0", lyrs);
	refLyrstruct = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 2, 0, VecPlnrVMLayerTtype::ZERO, "annot", "0.0", "0", lyrs);
	refLyrannot = lyr->ref;

	delete stk;

	// corners and annotation
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 1, 0, 0, "cornersw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-5000.0, -5000.0, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "1000.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "100.0");

	Plnr::addLyrsru(dbsplnr, "annot", "cornersw", "all", lyrs, devs);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 2, 0, 0, "cornerse", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				5000.0, -5000.0, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "1000.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "100.0");

	Plnr::addLyrsru(dbsplnr, "annot", "cornerse", "all", lyrs, devs);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 3, 0, 0, "cornerne", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				5000.0, 5000.0, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "1000.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "100.0");

	Plnr::addLyrsru(dbsplnr, "annot", "cornerne", "all", lyrs, devs);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 4, 0, 0, "cornernw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-5000.0, 5000.0, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "1000.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "100.0");

	Plnr::addLyrsru(dbsplnr, "annot", "cornernw", "all", lyrs, devs);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 5, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -4200.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", annots);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "1000.0");

	Plnr::addLyrsru(dbsplnr, "annot", "annots", "all", lyrs, devs);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 6, 0, 0, "annotw", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-4200.0, 0.0, 90.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", annotw);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "1000.0");

	Plnr::addLyrsru(dbsplnr, "annot", "annotw", "all", lyrs, devs);

	return dsn;
};
// IP cust --- IEND
// IP spec --- INSERT

// IP changeStage --- BEGIN
// IP changeStage.hdr --- BEGIN
void JobPlnrTpoUvslides::changeStage(
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

uint JobPlnrTpoUvslides::enterSgeIdle(
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

void JobPlnrTpoUvslides::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint JobPlnrTpoUvslides::enterSgeCreidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSge = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeCreidle --- INSERT
	return retval;
};

void JobPlnrTpoUvslides::leaveSgeCreidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreidle --- INSERT
};

uint JobPlnrTpoUvslides::enterSgeCreate(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::EXPAND1;
// IP enterSgeCreate --- IBEGIN
	string s, s2;

	ubigint refFile;

	ubigint refPrj;

	int dim;
	string Title;
	string text;

	ListPlnrMDesign dsns;
	PlnrMDesign* dsn = NULL;

	PlnrMStack* stk = NULL;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	vector<ubigint> refLyrstructs;
	ubigint refLyrstruct;
	vector<ubigint> refLyrannots;
	ubigint refLyrannot;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	PlnrMTapeout* tpo = NULL;
	PlnrJMTapeoutState* tpj = NULL;
	PlnrRMProjectMTapeout* prt = NULL;

	ListPlnrMReticle rtcs;
	PlnrMReticle* rtc = NULL;

	double x, y;

	refPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	// --- create designs

	// -- create grayscale designs using 'gray' and 'wg' templates
	// gray0(opaque) - gray0_2 - gray0_4 - gray0_6(inv) - gray0_8(inv) - gray1(transparent)
	for (unsigned int i=0;i<6;i++) {
		// design title
		Title = "gray";
		if (i != 5) Title += "0_" + to_string(i*2);
		else Title += "1";

		// design comment ex.: "gray field open=20%"
		s = "gray field open=" + to_string(i*20) + "\%";

		// south annotation ex.: "OPN20%"
		s2 = "opn" + to_string(i*20) + "\%";

		// west annotation: "A20UM"

		dsn = createDsn(dbsplnr, refPrj, Title, s, s2, "a20um", refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		// slide content
		devs.clear();
		if (i == 0) {
			// do nothing

		} else if (i == 5) {
			// add wg
			dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "area", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
						500.0, 500.0, 0.0, "", refsDtp, "wg", devs);
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "l", "8000.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", "8000.0");

			Plnr::addLyrsru(dbsplnr, refLyrstruct, "area", "all", devs);

		} else {
			// add gray
			dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "area", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
						500.0, 500.0, 0.0, "", refsDtp, "gray", devs);
			switch (i) {
				case 1: Plnr::changeDpa(dbsplnr, dev->ref, 0, "p", "0.2"); break;
				case 2: Plnr::changeDpa(dbsplnr, dev->ref, 0, "p", "0.4"); break;
				case 3: Plnr::changeDpa(dbsplnr, dev->ref, 0, "p", "0.6"); break;
				case 4: Plnr::changeDpa(dbsplnr, dev->ref, 0, "p", "0.8"); break;
			};
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "pix", "20.0");
//			Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", "400");
//			Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "400");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", "32");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "32");
///
			if ((i == 1) || (i == 2)) {
				Plnr::changeDpa(dbsplnr, dev->ref, 0, "invsq", "false");
			} else {
				Plnr::changeDpa(dbsplnr, dev->ref, 0, "invsq", "true");
			};

			Plnr::addLyrsru(dbsplnr, refLyrstruct, "area", "all", devs);
		};
	};

	// -- create iris (pinhole) designs using 'phcsqneg' template
	// iris50 - iris100 - iris200 - iris500 - iris1000 - iris2000
	for (unsigned int i=0;i<6;i++) {
		switch (i) {
			case 0: dim = 50; break;
			case 1: dim = 100; break;
			case 2: dim = 200; break;
			case 3: dim = 500; break;
			case 4: dim = 1000; break;
			case 5: dim = 2000; break;
		};

		// design title
		Title = "iris" + to_string(dim);

		// design comment ex.: "iris d=100um"
		s = "iris d=" + to_string(dim) + "um";

		// south/west annotation ex.: "D100U"
		s2 = "d" + to_string(dim) + "u";

		dsn = createDsn(dbsplnr, refPrj, Title, s, s2, s2, refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		// slide content
		devs.clear();

		// add phcsqneg
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "disc", VecPlnrVMDeviceAligntype::ABS, "vm0_n0_0", "", "", "",
					500.0, 500.0, 0.0, "", refsDtp, "phcsqneg", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", to_string(((double) dim)/2.0));
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "a", "8000.0");
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", "1");
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", "1");
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "sqhole", "false");

		Plnr::addLyrsru(dbsplnr, refLyrstruct, "disc", "all", devs);
	};

	// -- create image designs using 'image' template
	// alicia - charlize - emj - nyc - surire - taylor
	for (unsigned int i=0;i<6;i++) {
		// design title
		switch (i) {
			case 0: Title = "alicia"; break;
			case 1: Title = "charlize"; break;
			case 2: Title = "emj"; break;
			case 3: Title = "nyc"; break;
			case 4: Title = "surire"; break;
			case 5: Title = "taylor"; break;
		};

		// design comment ex.: "Charlize Theron grayscale image"
		s = "";
		switch (i) {
			case 0: s = "Alicia Keys"; break;
			case 1: s = "Charlize Theron"; break;
			case 2: s = "Eiger Moench Jungfrau"; break;
			case 3: s = "New York City"; break;
			case 4: s = "Salar Surire"; break;
			case 5: s = "Taylor Cole"; break;
		};
		s += " grayscale image";

		// south annotation ex.: "CHARLIZE"

		// west annotation: "PX20U CD2U"

		dsn = createDsn(dbsplnr, refPrj, Title, s, Title, "px20u CD2u", refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		devs.clear();

		// slide content
		if (dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE Filename = '" + Title + "32.png'", refFile)) {
			// add image
			dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "img", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
						500.0, 500.0, 0.0, "", refsDtp, "image", devs);

			Plnr::changeDpaReffile(dbsplnr, dev->ref, 0, "src", refFile);
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "pix", "20.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "cd", "2.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "inv", "true");

			Plnr::addLyrsru(dbsplnr, refLyrstruct, "img", "all", devs);
		};
	};

	// -- create grid designs using 'gray' template
	// grid4 - grid8 - grid16 - grid32 - grid64 - grid128
	for (unsigned int i=0;i<6;i++) {
		switch (i) {
			case 0: dim = 4; break;
			case 1: dim = 8; break;
			case 2: dim = 16; break;
			case 3: dim = 32; break;
			case 4: dim = 64; break;
			case 5: dim = 128; break;
		};

		// design title
		Title = "grid" + to_string(dim);

		// design comment ex.: "regular grid of 9 lines"
		s = "regular grid of " + to_string(dim+1) + " lines";

		// south/west annotation ex.: "9LN"
		s2 = to_string(dim+1) + "ln";

		dsn = createDsn(dbsplnr, refPrj, Title, s, s2, s2, refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		// slide content
		devs.clear();

		// add gray
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "grid", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
					500.0, 500.0, 0.0, "", refsDtp, "gray", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "p", "0.25");
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "pix", to_string(8000.0/((double) dim)));
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "M", to_string(dim));
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "N", to_string(dim));
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "invsq", "false");

		Plnr::addLyrsru(dbsplnr, refLyrstruct, "grid", "all", devs);
	};

	// -- create circle designs using 'wgbend' template
	// circ2 - circ4 - circ8 - circ16 - circ32 - circ64
	for (unsigned int i=0;i<6;i++) {
		switch (i) {
			case 0: dim = 2; break;
			case 1: dim = 4; break;
			case 2: dim = 8; break;
			case 3: dim = 16; break;
			case 4: dim = 32; break;
			case 5: dim = 64; break;
		};

		// design title
		Title = "circ" + to_string(dim);

		// design comment ex.: "set of 4 concentric circles"
		s = "set of " + to_string(dim) + " concentric circles";

		// south/west annotation ex.: "4CRC"
		s2 = to_string(dim) + "crc";

		dsn = createDsn(dbsplnr, refPrj, Title, s, s2, s2, refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		// slide content
		devs.clear();

		// add wgbend's
		for (int j=0;j<dim;j++) {
			s = "circ" + to_string(j) + "_a";
			dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 6+1+(2*j), 0, 0, s, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
						500.0, 500.0, 0.0, "", refsDtp, "wgbend", devs);
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "0.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "180.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", to_string(((double) j)*4000.0/((double) dim) + 3000.0/((double) dim)));
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", to_string(2000.0/dim));

			Plnr::addLyrsru(dbsplnr, refLyrstruct, s, "all", devs);

			s = "circ" + to_string(j) + "_b";
			dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 6+1+(2*j+1), 0, 0, s, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
						500.0, 500.0, 0.0, "", refsDtp, "wgbend", devs);
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistart", "180.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "phistop", "360.0");
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", to_string(((double) j)*4000.0/((double) dim) + 3000.0/((double) dim)));
			Plnr::changeDpa(dbsplnr, dev->ref, 0, "ridgew", to_string(2000.0/((double) dim)));

			Plnr::addLyrsru(dbsplnr, refLyrstruct, s, "all", devs);
		};
	};

	// -- create pie pattern designs using 'pie' template
	// pie8 - pie16 - pie32 - pie64 - pie128 - pie256
	for (unsigned int i=0;i<6;i++) {
		switch (i) {
			case 0: dim = 8; break;
			case 1: dim = 16; break;
			case 2: dim = 32; break;
			case 3: dim = 64; break;
			case 4: dim = 128; break;
			case 5: dim = 256; break;
		};

		// design title
		Title = "pie" + to_string(dim);

		// design comment ex.: "pie test pattern 16 slices"
		s = "pie test pattern " + to_string(dim) + " slices";

		// south annotation ex.: "16SLC"
		s2 = to_string(dim) + "slc";

		// west annotation: "CD2U"

		dsn = createDsn(dbsplnr, refPrj, Title, s, s2, "CD2u", refLyrstruct, refLyrannot);
		dsns.nodes.push_back(dsn);
		refLyrstructs.push_back(refLyrstruct);
		refLyrannots.push_back(refLyrannot);

		// slide content
		devs.clear();

		// add pie
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "pie", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
					500.0, 500.0, 0.0, "", refsDtp, "pie", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "r", "4000.0");
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "slcN", to_string(dim));
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cd", "2.0");

		Plnr::addLyrsru(dbsplnr, refLyrstruct, "pie", "all", devs);
	};

	// -- create mask annotation design
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 0, 
				0, 0, "maskannot", 1, 0, "Mask annotation");
	dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, dsn->ref, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "0");
	dbsplnr->tblplnrmstack->insertRec(stk);

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "annot", "0.0", "0", lyrs);

	delete stk;

	devs.clear();

	// - top annotation
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 1, 0, 0, "annotn", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 31500.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "UV camera test slides - LTF-UniNE Jan 2012");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "1500.0");

	// - bottom annotation
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 1, 0, 0, "annots", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, -31500.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "grid=1cm, size=8mm");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "h", "1500.0");

	Plnr::addLyrsru(dbsplnr, lyr->ref, "annotn", "all", devs);
	Plnr::addLyrsru(dbsplnr, lyr->ref, "annots", "all", devs);

	// --- set up tape-out
	tpo = new PlnrMTapeout(0, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "UV camera test slides - LTF-UniNE Jan 2012", 1, 0, 0, 0, false, "");
	dbsplnr->tblplnrmtapeout->insertRec(tpo);

	tpj = new PlnrJMTapeoutState(0, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpo->refJState = tpj->ref;
	tpo->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	delete tpj;

	prt = new PlnrRMProjectMTapeout(0, refPrj, tpo->ref);
	dbsplnr->tblplnrrmprojectmtapeout->insertRec(prt);
	delete prt;

	// --- set up reticles
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpo->ref, dsn->ref, lyr->ref, "maskannot_annot", 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	for (unsigned int i=0;i<6;i++) {
		y = -25000.0 + ((double) i)*10000.0;

		for (unsigned int j=0;j<6;j++) {
			x = -25000.0 + ((double) j)*10000.0;

			dsn = dsns.nodes[i*6+j];
			refLyrstruct = refLyrstructs[i*6+j];
			refLyrannot = refLyrannots[i*6+j];

			rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpo->ref, dsn->ref, refLyrstruct, dsn->Title + "_struct", x, y);
			dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

			rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpo->ref, dsn->ref, refLyrannot, dsn->Title + "_annot", x, y);
			dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
		};
	};

	// --- prepare for expansion and plot generation by op's
	refsDsn.resize(0);
	for (unsigned int i=0;i<dsns.nodes.size();i++) refsDsn.push_back(dsns.nodes[i]->ref);

	refTpo = tpo->ref;

	retval = VecVSge::EXPAND1;

	// --- clean up
	delete tpo;
// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void JobPlnrTpoUvslides::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint JobPlnrTpoUvslides::enterSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND1;
	nextIxVSge = VecVSge::EXPAND2;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand1 --- IBEGIN
	// expand devices/stacks
	vector<DpchInvPlnr*> dpchinvs;

	for (unsigned int i=0;i<refsDsn.size();i++) PlnrExp_blks::getInvs(dbsplnr, refsDtp, refsDsn[i], dpchinvs);

	addInvs(dpchinvs);
// IP enterSgeExpand1 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrTpoUvslides::leaveSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand1 --- INSERT
};

uint JobPlnrTpoUvslides::enterSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND2;
	nextIxVSge = VecVSge::PLOT;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand2 --- IBEGIN
	// expand designs
	vector<DpchInvPlnr*> dpchinvs;

	for (unsigned int i=0;i<refsDsn.size();i++) dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refsDsn[i]));

	addInvs(dpchinvs);
// IP enterSgeExpand2 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrTpoUvslides::leaveSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand2 --- INSERT
};

uint JobPlnrTpoUvslides::enterSgePlot(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PLOT;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgePlot --- IBEGIN
	// generate output files
	string s;

	vector<DpchInvPlnr*> dpchinvs;

	for (unsigned int i=0;i<refsDsn.size();i++) {
		dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[i], {}, false, true, false, false, true, 1000));
	};

	dpchinvs.push_back(new DpchInvPlnrPlotTposvg(0, 0, 750, refTpo, 1000));
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 2.0, refTpo));

	// --- pass to op processors
	addInvs(dpchinvs);

	// prepare collection of plot files in one folder	
	plotfolder = Tmp::newfolder(xchg->tmppath);

	for (unsigned int i=0;i<dpchinvs.size();i++) {
		if (i < refsDsn.size()) {
			dbsplnr->loadStringBySQL("SELECT Title FROM TblPlnrMDesign WHERE ref = " + to_string(refsDsn[i]), s);
			plots[dpchinvs[i]->oref] = s + ".xml";

		} else {
			if ((i - refsDsn.size()) == 0) {
				plots[dpchinvs[i]->oref] = "floorplan.xml";
			} else if ((i - refsDsn.size()) == 1) {
				plots[dpchinvs[i]->oref] = "mask.cif";
			};
		};
	};
// IP enterSgePlot --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void JobPlnrTpoUvslides::leaveSgePlot(
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

uint JobPlnrTpoUvslides::enterSgeDone(
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

void JobPlnrTpoUvslides::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string JobPlnrTpoUvslides::getSquawk(
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

void JobPlnrTpoUvslides::handleRequest(
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
			auto it = plots.find(req->dpchret->oref);
			if (it != plots.end()) {
				string s = "mv " + xchg->tmppath + "/";

				if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNXYSVG) {
					s += ((DpchRetPlnrPlotDsnxysvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTTPOSVG) {
					s += ((DpchRetPlnrPlotTposvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTTPOTXT) {
					s += ((DpchRetPlnrPlotTpotxt*) (req->dpchret))->ciffile;
				};

				s += " " + xchg->tmppath + "/" + plotfolder + "/" + it->second;
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

bool JobPlnrTpoUvslides::handleRun(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
// IP handleRun --- IBEGIN
	changeStage(dbsplnr, VecVSge::CREIDLE);
// IP handleRun --- IEND
	return retval;
};

void JobPlnrTpoUvslides::handleTimer(
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


