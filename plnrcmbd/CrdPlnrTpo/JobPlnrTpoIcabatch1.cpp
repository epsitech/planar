/**
  * \file JobPlnrTpoIcabatch1.cpp
  * job handler for job JobPlnrTpoIcabatch1 (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "JobPlnrTpoIcabatch1.h"

// IP blksInclude --- BEGIN
#include "JobPlnrTpoIcabatch1_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class JobPlnrTpoIcabatch1
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
JobPlnrTpoIcabatch1::JobPlnrTpoIcabatch1(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::JOBPLNRTPOICABATCH1, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

// IP constructor.spec1 --- INSERT

// IP constructor.cust2 --- IBEGIN
	// TODO: replace '/*/2.2*/' by '/2.2' and '/*/3.3*/' by '/3.3'
	Plnr::getRefsDtp(dbsplnr, refsDtp);
// IP constructor.cust2 --- IEND

// IP constructor.spec2 --- INSERT

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

JobPlnrTpoIcabatch1::~JobPlnrTpoIcabatch1() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
PlnrMDesign* JobPlnrTpoIcabatch1::createDsn(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMProject
			, const string& Title
			, const string& Comment
			, ubigint& refStk
			, ubigint& refLyrMesa
			, ubigint& refLyrGrat
			, ubigint& refLyrBotmet
			, ubigint& refLyrIns
			, ubigint& refLyrTopmet
			, ubigint& refLyrBump
			, ListPlnrMDesign& dsns
		) {
	PlnrMDesign* dsn = NULL;
	PlnrMStack* stk = NULL;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPlnrMProject, 0, 0, 0, Title, 1, 0, Comment);
	dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, dsn->ref, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "0");
	dbsplnr->tblplnrmstack->insertRec(stk);
	refStk = stk->ref;

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "mesa", "0.0", "0", lyrs);
	refLyrMesa = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 2, 0, VecPlnrVMLayerTtype::ZERO, "grat", "0.0", "0", lyrs);
	refLyrGrat = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 3, 0, VecPlnrVMLayerTtype::ZERO, "botmet", "0.0", "0", lyrs);
	refLyrBotmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 4, 0, VecPlnrVMLayerTtype::ZERO, "ins", "0.0", "0", lyrs);
	refLyrIns = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 5, 0, VecPlnrVMLayerTtype::ZERO, "topmet", "0.0", "0", lyrs);
	refLyrTopmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 6, 0, VecPlnrVMLayerTtype::ZERO, "bump", "0.0", "0", lyrs);
	refLyrBump = lyr->ref;

	delete stk;

	return dsn;
};

PlnrMDevice* JobPlnrTpoIcabatch1::createDetsng(
			DbsPlnr* dbsplnr
			, const double rast
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const double x
			, const double y
			, const double size
			, const bool ext
			, const bool vgrat
			, const double gratprd
			, const double gratfill
			, const double extsize
			, const double extofsx
			, const double extofsy
			, const double bumpofsx
			, const double bumpofsy
			, ListPlnrMDevice& devs
		) {
	PlnrMDevice* dev = NULL;

	const bool metgrat = false;
	const bool mis = false;
	const bool schky = false;
	const bool hgrat = true;
	const double mesaclr = 2.0;
	const double botw = 4.0;
	bool ringbot;
	const double metclr = 6.0;
	bool ohmline;
	bool ohmring;
	const double olp = 2.0;
	bool sideopn;
	double opnsize;
	bool topfill;
	const double bumpd = 50.0;

	ringbot = (size > rast);
	ohmline = (size == rast);
	ohmring = (size > rast);
	sideopn = (size >= rast);
	opnsize = 2.0;
	topfill = (!ext || (size < rast));
	if (!topfill) opnsize = 6.0;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum, 0, 0, sref, VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x, y, 0.0, "", refsDtp, "photdet", devs);

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", size);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ext", ext);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "metgrat", metgrat);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "mis", mis);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "schky", schky);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "hgrat", hgrat);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "vgrat", vgrat);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratprd", gratprd);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratfill", gratfill);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "mesaclr", mesaclr);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "botw", botw);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sbot", ringbot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ebot", ringbot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "nbot", ringbot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "wbot", ringbot);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "metclr", metclr);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmline", ohmline);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmring", ohmring);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "olp", olp);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sideopn", sideopn);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "opnsize", opnsize);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "topfill", topfill);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extsize", extsize);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsx", extofsx);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsy", extofsy);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", bumpd);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsx", bumpofsx);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsy", bumpofsy);

	return dev;
};

PlnrMDevice* JobPlnrTpoIcabatch1::createDetarr(
			DbsPlnr* dbsplnr
			, const double rast
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const double gratprd
			, const double gratfill
			, const bool sbot
			, const bool ebot
			, const bool nbot
			, const bool wbot
			, ListPlnrMDevice& devs
		) {
	PlnrMDevice* dev = NULL;

	const double size = rast;
	const bool ext = false;
	const bool metgrat = false;
	const bool mis = false;
	const bool schky = false;
	const bool hgrat = true;
	const bool vgrat = true;
	const double mesaclr = 2.0;
	const double botw = 4.0;
	const double metclr = 4.0;
	const bool ohmline = true;
	const bool ohmring = false;
	const double olp = 2.0;
	const bool sideopn = true;
	const double opnsize = 2.0;
	const bool topfill = true;
	const double extsize = 0.0;
	const double extofsx = 0.0;
	const double extofsy = 0.0;
	const double bumpd = 50.0;
	const double bumpofsx = 0.0;
	const double bumpofsy = 0.0;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum, 0, 0, sref, VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "photdet", devs);

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", size);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ext", ext);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "metgrat", metgrat);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "mis", mis);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "schky", schky);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "hgrat", hgrat);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "vgrat", vgrat);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratprd", gratprd);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratfill", gratfill);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "mesaclr", mesaclr);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "botw", botw);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sbot", sbot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ebot", ebot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "nbot", nbot);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "wbot", wbot);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "metclr", metclr);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmline", ohmline);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmring", ohmring);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "olp", olp);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sideopn", sideopn);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "opnsize", opnsize);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "topfill", topfill);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extsize", extsize);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsx", extofsx);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsy", extofsy);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", bumpd);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsx", bumpofsx);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsy", bumpofsy);

	return dev;
};

PlnrMDevice* JobPlnrTpoIcabatch1::createPad(
			DbsPlnr* dbsplnr
			, const double rast
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const double x
			, const double y
			, const double bumpofsx
			, const double bumpofsy
			, ListPlnrMDevice& devs
		) {
	PlnrMDevice* dev = NULL;

	const double size = rast;
	const double clr = 5.0;
	const double olp = 2.0;
	const double bumpd = 50.0;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum, 0, 0, sref, VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x, y, 0.0, "", refsDtp, "pad", devs);

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", size);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "clr", clr);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "olp", olp);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", bumpd);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsx", bumpofsx);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsy", bumpofsy);

	return dev;
};

void JobPlnrTpoIcabatch1::addAnnot(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMLayer1
			, const ubigint refPlnrMLayer2
			, const ubigint refPlnrMLayer3
			, const ubigint refPlnrMLayer4
			, const ubigint refPlnrMLayer5
			, const ubigint refPlnrMLayer6
			, const ubigint refPlnrMDevice
			, const string& srefPlnrMStructure
		) {
	if (refPlnrMLayer1 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer1, refPlnrMDevice, srefPlnrMStructure);
	if (refPlnrMLayer2 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer2, refPlnrMDevice, srefPlnrMStructure);
	if (refPlnrMLayer3 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer3, refPlnrMDevice, srefPlnrMStructure);
	if (refPlnrMLayer4 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer4, refPlnrMDevice, srefPlnrMStructure);
	if (refPlnrMLayer5 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer5, refPlnrMDevice, srefPlnrMStructure);
	if (refPlnrMLayer6 != 0) Plnr::addLyrsru(dbsplnr, refPlnrMLayer6, refPlnrMDevice, srefPlnrMStructure);
};

PlnrMDesign* JobPlnrTpoIcabatch1::createPodsn(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMProject
			, const string& Title
			, const string& Comment
			, ubigint& refStk
			, ubigint& refLyrBotmet
			, ubigint& refLyrIns
			, ubigint& refLyrTopmet
			, ubigint& refLyrBump
			, ubigint& refLyrVoid
			, ListPlnrMDesign& dsns
		) {
	PlnrMDesign* dsn = NULL;
	PlnrMStack* stk = NULL;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPlnrMProject, 0, 0, 0, Title, 1, 0, Comment);
	dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, dsn->ref, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "0");
	dbsplnr->tblplnrmstack->insertRec(stk);
	refStk = stk->ref;

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "botmet", "0.0", "0", lyrs);
	refLyrBotmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 2, 0, VecPlnrVMLayerTtype::ZERO, "ins", "0.0", "0", lyrs);
	refLyrIns = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 3, 0, VecPlnrVMLayerTtype::ZERO, "topmet", "0.0", "0", lyrs);
	refLyrTopmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 4, 0, VecPlnrVMLayerTtype::ZERO, "bump", "0.0", "0", lyrs);
	refLyrBump = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 5, 0, VecPlnrVMLayerTtype::ZERO, "void", "0.0", "0", lyrs);
	refLyrVoid = lyr->ref;

	delete stk;

	return dsn;
};
// IP cust --- IEND
// IP spec --- INSERT

// IP changeStage --- BEGIN
// IP changeStage.hdr --- BEGIN
void JobPlnrTpoIcabatch1::changeStage(
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

uint JobPlnrTpoIcabatch1::enterSgeIdle(
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

void JobPlnrTpoIcabatch1::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint JobPlnrTpoIcabatch1::enterSgeCreidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSge = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeCreidle --- INSERT
	return retval;
};

void JobPlnrTpoIcabatch1::leaveSgeCreidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreidle --- INSERT
};

uint JobPlnrTpoIcabatch1::enterSgeCreate(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::EXPAND1;
// IP enterSgeCreate --- IBEGIN
	ostringstream str, str2;

	ubigint refPrj;

	ListPlnrMDesign dsns;
	PlnrMDesign* dsn = NULL;

	PlnrMStack* stk = NULL;
	ubigint refStk;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	ubigint refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump;

	ubigint refLyrPos, refLyrNeg, refLyrNeg2;

	ubigint refLyrVoid, refLyrGbl;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;
	unsigned devcnt, subdevcnt;

	ubigint refDevPio;

	PlnrMTapeout* tpoPos = NULL;
	PlnrMTapeout* tpoNeg = NULL;
	PlnrMTapeout* tpoNeg2 = NULL;
	PlnrMTapeout* tpoPinout = NULL;
	PlnrJMTapeoutState* tpj = NULL;
	PlnrRMProjectMTapeout* prt = NULL;

	ListPlnrMArray arrs;
	PlnrMArray* arr = NULL;

	ListPlnrMArrayitem aris;

	ListPlnrMReticle rtcs;
	PlnrMReticle* rtc = NULL;

	refPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	// general variables
	const double rast = 75.0;
	const double arrrast = 32.0*rast+50.0;

	const double linemin = 0.35;
	const double sqmin = 0.4;

	string cellstop = "AF32";

	// - specific variables for detsng / posng
	// detsng only - southwest corner cell of detector area
	string crefsSw1 = "C13;I13;M6;M2;C9;F9;J5;J2;C6;G6;G4;G2;E3;E2;A3;B3;O16;N14;N12;N11";
	string crefsSw2 = "AA13;U13;Q6;Q2;AB9;Y9;U5;U2;AC6;Y6;Y4;Y2;AB3;AB2;AF3;AE3;R16;S14;S12;S11";
	string crefsSw3 = "AA17;U17;Q24;Q28;AB22;Y22;U26;U29;AC26;Y26;Y28;Y30;AB30;AB31;AF30;AE30;R17;S19;S21;S22";
	string crefsSw4 = "C17;I17;M24;M28;C22;F22;J26;J29;C26;G26;G28;G30;E30;E31;A30;B30;O17;N19;N21;N22";

	// detsng only - northeast corner cell of detector area
	string crefsNe1 = "F16;L16;P9;P5;E11;H11;L7;L4;D7;H7;H5;H3;E3;E2;A3;B3;O16;N14;N12;N11";
	string crefsNe2 = "AD16;X16;T9;T5;AD11;AA11;W7;W4;AD7;Z7;Z5;Z3;AB3;AB2;AF3;AE3;R16;S14;S12;S11";
	string crefsNe3 = "AD20;X20;T27;T31;AD24;AA24;W28;W31;AD27;Z27;Z29;Z31;AB30;AB31;AF30;AE30;R17;S19;S21;S22";
	string crefsNe4 = "F20;L20;P27;P31;E24;H24;L28;L31;D27;H27;H29;H31;E30;E31;A30;B30;O17;N19;N21;N22";

	// same for detsng and posng - contact cell for detector
	string crefsPad1 = "A15;G15;O8;O4;A11;I11;K7;K4;A7;F7;G5;G3;C3;C2;A3;B3;N15;O15;O13;O10";
	string crefsPad2 = "AF15;Z15;R8;R4;AF11;X11;V7;V4;AF7;AA7;Z5;Z3;AD3;AD2;AF3;AE3;S15;R15;R13;R10";
	string crefsPad3 = "AF18;Z18;R25;R29;AF22;X22;V26;V29;AF26;AA26;Z28;Z30;AD30;AD31;AF30;AE30;S18;R18;R20;R23";
	string crefsPad4 = "A18;G18;O25;O29;A22;I22;K26;K29;A26;F26;G28;G30;C30;C31;A30;B30;N18;O18;O20;O23";

	// detsng only - southwest corner cell of detector contact pad
	string crefsPadsw1 = "A14;G14;O8;O4;A10;I10;K7;K4;A6;E6;G5;G3;C3;C1;A3;B3;M15;O14;O12;O10";
	string crefsPadsw2 = "AE14;Y14;R8;R4;AE10;W10;V7;V4;AE6;AA6;Z5;Z3;AC3;AC1;AF3;AE3;S15;Q14;Q12;Q10";
	string crefsPadsw3 = "AE18;Y18;R25;R29;AE22;W22;V26;V29;AE26;AA26;Z28;Z30;AC29;AC31;AF30;AE30;S17;Q18;Q20;Q22";
	string crefsPadsw4 = "A18;G18;O25;O29;A22;I22;K26;K29;A26;E26;G28;G30;C29;C31;A30;B30;M17;O18;O20;O22";

	// detsng only - northeast corner cell of detector contact pad
	string crefsPadne1 = "B15;H15;O8;O4;B11;J11;K7;K4;B7;F7;G5;G3;D4;D2;A3;B3;N16;P15;P13;P11";
	string crefsPadne2 = "AF15;Z15;R8;R4;AF11;X11;V7;V4;AF7;AB7;Z5;Z3;AD4;AD2;AF3;AE3;T16;R15;R13;R11";
	string crefsPadne3 = "AF19;Z19;R25;R29;AF23;X23;V26;V29;AF27;AB27;Z28;Z30;AD30;AD32;AF30;AE30;T18;R19;R21;R23";
	string crefsPadne4 = "B19;H19;O25;O29;B23;J23;K26;K29;B27;F27;G28;G30;D30;D32;A30;B30;N18;P19;P21;P23";

	// detsng only - size of detector != 0.0 for size not defined by sw and ne cells
	double sizes1[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 30.0, 30.0};
	double sizes2[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 30.0, 30.0};
	double sizes3[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 30.0, 30.0};
	double sizes4[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 30.0, 30.0};

	// detsng only - detector extended contact
	bool exts1[] = {true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, true, true};
	bool exts2[] = {true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, true, true};
	bool exts3[] = {true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, true, true};
	bool exts4[] = {true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, true, true};

	// posng only - wire bond pads for pins (detector pins only)
	int wbs1[] = {2, 4, 6, 8, 57, 59, 61, 63};
	int wbs2[] = {18, 20, 22, 24, 9, 11, 13, 15};
	int wbs3[] = {34, 36, 38, 40, 25, 27, 29, 31};
	int wbs4[] = {50, 52, 54, 56, 41, 43, 45, 47};

	// posng only - final cells corresponding to those wire bond pads (detector pins only) CHANGE DONE
	string crefsPin1 = "C3;G6;K10;O13;O15;J11;F7;B3";
	string crefsPin2 = "AE3;AA7;W11;R15;R13;V10;Z6;AD3";
	string crefsPin3 = "AD30;Z27;V23;R20;R18;W22;AA26;AE30";
	string crefsPin4 = "B30;F26;J22;O18;O20;K23;G27;C30";

	// no keepoff for detector pins

	// posng - detector openings correspond to crefsPad1..4

	// posng only - wire bond pads for pins (ground pins only)
	int wbgs1[] = {1, 3, 5, 7, 58, 60, 62, 64};
	int wbgs2[] = {17, 19, 21, 23, 10, 12, 14, 16};
	int wbgs3[] = {33, 35, 37, 39, 26, 28, 30, 32};
	int wbgs4[] = {49, 51, 53, 55, 42, 44, 46, 48};

	// posng only - final cells corresponding to those wire bond pads (ground pins only)
	string crefsPing1 = "A1;E5;I9;M13;M13;I9;E5;A1";
	string crefsPing2 = "AF1;AB5;X9;T13;T13;X9;AB5;AF1";
	string crefsPing3 = "AF32;AB28;X24;T20;T20;X24;AB28;AF32";
	string crefsPing4 = "A32;E28;I24;M20;M20;I24;E28;A32";

	// posng only - keep off corresponding to ground pins
	bool kogs1[] = {true, true, true, true, false, false, false, false};
	bool kogs2[] = {false, false, false, false, true, true, true, true};
	bool kogs3[] = {true, true, true, true, false, false, false, false};
	bool kogs4[] = {false, false, false, false, true, true, true, true};

	// same for detsng and posng - ground openings
	string crefsPadg1 = "A1;A5;E5;E1;A9;I9;I1;A13;M13;M1";
	string crefsPadg2 = "AF1;AF5;AB5;AB1;AF9;X9;X1;AF13;T13;T1";
	string crefsPadg3 = "AF32;AF28;AB28;AB32;AF24;X24;X32;AF20;T20;T32";
	string crefsPadg4 = "A32;A28;E28;E32;A24;I24;I32;A20;M20;M32";

	// detsng only - southwest corner cell of ground pads DO DONE
	string crefsPadgsw1 = "A1;A4;E4;E1;A8;I8;I1;A12;M13;M1";
	string crefsPadgsw2 = "AE1;AE4;AA4;AB1;AE8;W8;X1;AE12;T13;T1";
	string crefsPadgsw3 = "AE31;AE28;AA28;AB32;AE24;W24;X32;AE20;T20;T32";
	string crefsPadgsw4 = "A31;A28;E28;E32;A24;I24;I32;A20;M20;M32";

	// detsng only - northeast corner cell of ground pads DO DONE
	string crefsPadgne1 = "B2;B5;F5;E1;B9;J9;I1;B13;M13;M1";
	string crefsPadgne2 = "AF2;AF5;AB5;AB1;AF9;X9;X1;AF13;T13;T1";
	string crefsPadgne3 = "AF32;AF29;AB29;AB32;AF25;X25;X32;AF21;T20;T32";
	string crefsPadgne4 = "B32;B29;F29;E32;B25;J25;I32;B21;M20;M32";

	// - specific variables for detarr / poarr

	// same for detarr and poarr - contact cell for detector
	string crefsApad1 = "C16;E16;G16;I16;K16;M16;O16;A16;A14;A12;A10;A8;A6;A4;A2";
	string crefsApad2 = "R15;T13;V11;X9;Z7;AB5;AD3;AE1;AE3;AC5;AA7;Y9;W11;U13;S15";
	string crefsApad3 = "AF17;AF19;AF21;AF23;AF25;AF27;AF29;AF31;AD17;AB17;Z17;X17;V17;T17;R17";
	string crefsApad4 = "O18;M20;K22;I24;G26;E28;C30;B32;B30;D28;F26;H24;J22;L20;N18";

	// poarr only - wire bond pads for pins (detector pins only)
	int awbs1[] = {2, 3, 4, 5, 6, 7, 8, 57, 58, 59, 60, 61, 62, 63, 64};
	int awbs2[] = {9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24};
	int awbs3[] = {25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40};
	int awbs4[] = {41, 42, 43, 44, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56};

	// poarr only - final cells and detector openings correspond to crefsApad1..4

	// poarr only - wire bond pads for pins (ground pins only)
	int awbgs[] = {1, 17, 33, 49};

	// same for detarr and poarr - ground openings
	string crefsApadg = "A1;AF1;AF32;A32";

	// poarr only - final cells and openings correspond to crefsApadg (ground pins only)

	// - specific variables for detsng
	vector<string> crefsSw;
	vector<string> crefsNe;
	vector<string> crefsPad;
	vector<string> crefsPadsw;
	vector<string> crefsPadne;
	vector<string> crefsPadg;

	double xofs, yofs;
	double x, y;
	double size;
	bool ext;
	double extsize, extofsx, extofsy;
	double bumpofsx, bumpofsy;

	// - specific variables for posng / poarr
	vector<string> crefsPin;
	vector<string> crefsPing;

	const double framew = 100.0;
	const double porast = 32.0*rast + 2.0*framew + 4.0*rast + 2.0*framew; // should amount to 3.3mm (200um scribe lanes in addition)

	// - specific variables for poarr
	vector<string> crefsApad;

	// --- set up tape-outs
	refTpoPos = dbsplnr->tblplnrmtapeout->insertNewRec(&tpoPos, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "single QCD dark faces - ICARUS Aug 2012", 1, 0, 0, 0, true, "");

	tpj = new PlnrJMTapeoutState(0, tpoPos->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpoPos->refJState = tpj->ref;
	tpoPos->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpoPos);

	delete tpj;

	prt = new PlnrRMProjectMTapeout(0, refPrj, tpoPos->ref);
	dbsplnr->tblplnrrmprojectmtapeout->insertRec(prt);
	delete prt;

	refTpoNeg = dbsplnr->tblplnrmtapeout->insertNewRec(&tpoNeg, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "single QCD bright faces - ICARUS Aug 2012", 1, 0, 0, 0, true, "");

	tpj = new PlnrJMTapeoutState(0, tpoNeg->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpoNeg->refJState = tpj->ref;
	tpoNeg->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpoNeg);

	delete tpj;

	prt = new PlnrRMProjectMTapeout(0, refPrj, tpoNeg->ref);
	dbsplnr->tblplnrrmprojectmtapeout->insertRec(prt);
	delete prt;

	refTpoNeg2 = dbsplnr->tblplnrmtapeout->insertNewRec(&tpoNeg2, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "single QCD bright faces 2 - ICARUS Aug 2012", 1, 0, 0, 0, true, "");

	tpj = new PlnrJMTapeoutState(0, tpoNeg2->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpoNeg2->refJState = tpj->ref;
	tpoNeg2->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpoNeg2);

	delete tpj;

	prt = new PlnrRMProjectMTapeout(0, refPrj, tpoNeg2->ref);
	dbsplnr->tblplnrrmprojectmtapeout->insertRec(prt);
	delete prt;

	refTpoPinout = dbsplnr->tblplnrmtapeout->insertNewRec(&tpoPinout, 0, 0, VecPlnrVMTapeoutBasetype::PLN, "single QCD carrier dark faces - ICARUS Aug 2012", 1, 0, 0, 0, true, "");

	tpj = new PlnrJMTapeoutState(0, tpoPinout->ref, 0, VecPlnrVMTapeoutState::DSN);
	dbsplnr->tblplnrjmtapeoutstate->insertRec(tpj);

	tpoPinout->refJState = tpj->ref;
	tpoPinout->ixVState = tpj->ixVState;
	dbsplnr->tblplnrmtapeout->updateRec(tpoPinout);

	delete tpj;

	prt = new PlnrRMProjectMTapeout(0, refPrj, tpoPinout->ref);
	dbsplnr->tblplnrrmprojectmtapeout->insertRec(prt);
	delete prt;

	// --- create designs as well as arrays/reticles

	Plnr::cellstopToXyofs(rast, cellstop, xofs, yofs);

	// -- dsns.nodes[0]: design containing layout with 80 individual QCD's
	dsn = createDsn(dbsplnr, refPrj, "detsng", "4x20 single QCD", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod1", 1, 0, "4x20 single QCD - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod2", 1, 0, "4x20 single QCD - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod3", 1, 0, "4x20 single QCD - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod4", 1, 0, "4x20 single QCD - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod5", 1, 0, "4x20 single QCD - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[0]->ref, 0, "detsng_mod6", 1, 0, "4x20 single QCD - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[0];

	devcnt = 0;

	// - sw quarter
	StrMod::stringToVector(crefsSw1, crefsSw);
	StrMod::stringToVector(crefsNe1, crefsNe);
	StrMod::stringToVector(crefsPadsw1, crefsPadsw);
	StrMod::stringToVector(crefsPadne1, crefsPadne);
	StrMod::stringToVector(crefsPad1, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsSw[i], crefsNe[i], x, y, size, size);
		if (sizes1[i] != 0.0) size = sizes1[i];

		ext = exts1[i];

		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], extofsx, extofsy, extsize, extsize);
		extofsx = extofsx - x;
		extofsy = extofsy - y;

		Plnr::crefToXy(rast, xofs, yofs, crefsPad[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "I." << (i+1);
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;

		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratprd", 4.0/*/3.3*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "mis", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "metgrat", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "schky", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "sideopn", false);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratprd", 3.4/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratfill", linemin/(3.4/*/2.2*/));
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratprd", 2.3/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratfill", linemin/(2.3/*/2.2*/));
	};

	StrMod::stringToVector(crefsPadg1, crefsPadg);
	StrMod::stringToVector(crefsPadgsw1, crefsPadsw);
	StrMod::stringToVector(crefsPadgne1, crefsPadne);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], x, y, size, size);

		Plnr::crefToXy(rast, xofs, yofs, crefsPadg[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "Ig" << (i+1);
		dev = createPad(dbsplnr, size, dsn->ref, devcnt+1, str.str(), -x, y, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
	};

	// - se quarter
	StrMod::stringToVector(crefsSw2, crefsSw);
	StrMod::stringToVector(crefsNe2, crefsNe);
	StrMod::stringToVector(crefsPadsw2, crefsPadsw);
	StrMod::stringToVector(crefsPadne2, crefsPadne);
	StrMod::stringToVector(crefsPad2, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsSw[i], crefsNe[i], x, y, size, size);
		if (sizes2[i] != 0.0) size = sizes2[i];

		ext = exts2[i];

		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], extofsx, extofsy, extsize, extsize);
		extofsx = extofsx - x;
		extofsy = extofsy - y;

		Plnr::crefToXy(rast, xofs, yofs, crefsPad[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "II." << (i+1);
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ 9.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;

		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratprd", 4.4/*/3.3*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratfill", 1.0-sqmin/(4.4/*/3.3*/));
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "mis", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "metgrat", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "schky", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "sideopn", false);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratprd", 3.9/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratfill", linemin/(3.9/*/2.2*/));
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratprd", 2.7/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));
	};

	StrMod::stringToVector(crefsPadg2, crefsPadg);
	StrMod::stringToVector(crefsPadgsw2, crefsPadsw);
	StrMod::stringToVector(crefsPadgne2, crefsPadne);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], x, y, size, size);

		Plnr::crefToXy(rast, xofs, yofs, crefsPadg[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "IIg" << (i+1);
		dev = createPad(dbsplnr, size, dsn->ref, devcnt+1, str.str(), -x, y, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
	};

	// - ne quarter
	StrMod::stringToVector(crefsSw3, crefsSw);
	StrMod::stringToVector(crefsNe3, crefsNe);
	StrMod::stringToVector(crefsPadsw3, crefsPadsw);
	StrMod::stringToVector(crefsPadne3, crefsPadne);
	StrMod::stringToVector(crefsPad3, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsSw[i], crefsNe[i], x, y, size, size);
		if (sizes3[i] != 0.0) size = sizes3[i];

		ext = exts3[i];

		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], extofsx, extofsy, extsize, extsize);
		extofsx = extofsx - x;
		extofsy = extofsy - y;

		Plnr::crefToXy(rast, xofs, yofs, crefsPad[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "III." << (i+1);
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ 10.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;

		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratprd", 5.8/*/3.3*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratfill", 1.0-sqmin/(5.8/*/3.3*/));
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "mis", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "metgrat", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "schky", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "sideopn", false);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratprd", 4.4/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratprd", 3.1/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratfill", linemin/(3.1/*/2.2*/));
	};

	StrMod::stringToVector(crefsPadg3, crefsPadg);
	StrMod::stringToVector(crefsPadgsw3, crefsPadsw);
	StrMod::stringToVector(crefsPadgne3, crefsPadne);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], x, y, size, size);

		Plnr::crefToXy(rast, xofs, yofs, crefsPadg[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "IIIg" << (i+1);
		dev = createPad(dbsplnr, size, dsn->ref, devcnt+1, str.str(), -x, y, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
	};

	// - nw quarter
	StrMod::stringToVector(crefsSw4, crefsSw);
	StrMod::stringToVector(crefsNe4, crefsNe);
	StrMod::stringToVector(crefsPadsw4, crefsPadsw);
	StrMod::stringToVector(crefsPadne4, crefsPadne);
	StrMod::stringToVector(crefsPad4, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsSw[i], crefsNe[i], x, y, size, size);
		if (sizes4[i] != 0.0) size = sizes4[i];

		ext = exts4[i];

		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], extofsx, extofsy, extsize, extsize);
		extofsx = extofsx - x;
		extofsy = extofsy - y;

		Plnr::crefToXy(rast, xofs, yofs, crefsPad[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "IV." << (i+1);
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ false, /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0/2.0, extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;

		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratprd", 4.0/*/3.3*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+1]->ref, "gratfill", 1.0-linemin/(4.0/*/3.3*/));
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "mis", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+2]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "metgrat", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+3]->ref, "sideopn", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "schky", true);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "hgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "vgrat", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmline", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "ohmring", false);
		Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[0+4]->ref, "sideopn", false);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratprd", 4.4/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratprd", 2.7/*/2.2*/);
		Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[0+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));
	};

	StrMod::stringToVector(crefsPadg4, crefsPadg);
	StrMod::stringToVector(crefsPadgsw4, crefsPadsw);
	StrMod::stringToVector(crefsPadgne4, crefsPadne);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		Plnr::crefsToXyspan(rast, xofs, yofs, crefsPadsw[i], crefsPadne[i], x, y, size, size);

		Plnr::crefToXy(rast, xofs, yofs, crefsPadg[i], bumpofsx, bumpofsy);
		bumpofsx = bumpofsx - x;
		bumpofsy = bumpofsy - y;

		str.str(""); str << "IVg" << (i+1);
		dev = createPad(dbsplnr, size, dsn->ref, devcnt+1, str.str(), -x, y, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
	};

	// - corners
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornersw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*arrrast, -0.5*arrrast, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerse", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*arrrast, -0.5*arrrast, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerne", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*arrrast, 0.5*arrrast, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornernw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*arrrast, 0.5*arrrast, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");
	devcnt++;

	// - corner pad annotations
	Plnr::crefToXy(rast, xofs, yofs, "D5", x, y);
	x -= 0.5*rast;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-x, y, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.5*rast);

	addAnnot(dbsplnr, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "D28", x, y);
	x -= 0.5*rast;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-x, y, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.5*rast);

	addAnnot(dbsplnr, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AC28", x, y);
	x += 0.5*rast;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-x, y, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.5*rast);

	addAnnot(dbsplnr, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AC5", x, y);
	x += 0.5*rast;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				-x, y, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.5*rast);

	addAnnot(dbsplnr, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dev->ref, "all");
	devcnt++;

	// -- dsns.nodes[0]: generate array and reticles
	// generally use tapeout-array-reticle ; tapeout-reticle is generated from this

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detsng", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", 0.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[0+5]->ref, "detsng_mod5", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+5]->ref, refLyrGrat, "grat", 0.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[0+6]->ref, "detsng_mod6", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+6]->ref, refLyrGrat, "grat", -35000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detsng", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);

	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", 0.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", 0.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[0+1]->ref, "detsng_mod1", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+1]->ref, refLyrGrat, "grat", -35000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[0+2]->ref, "detsng_mod2", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+2]->ref, refLyrIns, "ins", -35000.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[0+3]->ref, "detsng_mod3", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+3]->ref, refLyrBotmet, "botmet", 0.0, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[0+4]->ref, "detsng_mod4", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+4]->ref, refLyrBotmet, "botmet", 0.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[0+4]->ref, refLyrIns, "ins", -35000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[7]: single QCD for array without botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrc", "single QCD for array - central", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod1", 1, 0, "single QCD for array - central - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod2", 1, 0, "single QCD for array - central - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod3", 1, 0, "single QCD for array - central - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod4", 1, 0, "single QCD for array - central - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod5", 1, 0, "single QCD for array - central - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[7]->ref, 0, "detarrc_mod6", 1, 0, "single QCD for array - central - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[7];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdc", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[7+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[7+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrc", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[7+5]->ref, "detarrc_mod5", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+5]->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[7+6]->ref, "detarrc_mod6", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrc", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[7+1]->ref, "detarrc_mod1", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[7+2]->ref, "detarrc_mod2", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[7+3]->ref, "detarrc_mod3", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+3]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[7+4]->ref, "detarrc_mod4", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+4]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[7+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[14]: single QCD for array with S botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrs", "single QCD for array - south", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod1", 1, 0, "single QCD for array - south - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod2", 1, 0, "single QCD for array - south - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod3", 1, 0, "single QCD for array - south - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod4", 1, 0, "single QCD for array - south - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod5", 1, 0, "single QCD for array - south - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[14]->ref, 0, "detarrs_mod6", 1, 0, "single QCD for array - south - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[14];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcds", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ false, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[14+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[14+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrs", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[14+5]->ref, "detarrs_mod5", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+5]->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[14+6]->ref, "detarrs_mod6", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrs", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[14+1]->ref, "detarrs_mod1", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[14+2]->ref, "detarrs_mod2", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[14+3]->ref, "detarrs_mod3", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+3]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[14+4]->ref, "detarrs_mod4", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+4]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[14+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[21]: single QCD for array with E botmet
	dsn = createDsn(dbsplnr, refPrj, "detarre", "single QCD for array - east", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod1", 1, 0, "single QCD for array - east - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod2", 1, 0, "single QCD for array - east - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod3", 1, 0, "single QCD for array - east - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod4", 1, 0, "single QCD for array - east - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod5", 1, 0, "single QCD for array - east - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[21]->ref, 0, "detarre_mod6", 1, 0, "single QCD for array - east - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[21];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcde", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ true, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[21+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[21+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarre", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[21+5]->ref, "detarre_mod5", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+5]->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[21+6]->ref, "detarre_mod6", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarre", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[21+1]->ref, "detarre_mod1", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[21+2]->ref, "detarre_mod2", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[21+3]->ref, "detarre_mod3", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+3]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[21+4]->ref, "detarre_mod4", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+4]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[21+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[28]: single QCD for array with N botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrn", "single QCD for array - north", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod1", 1, 0, "single QCD for array - north - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod2", 1, 0, "single QCD for array - north - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod3", 1, 0, "single QCD for array - north - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod4", 1, 0, "single QCD for array - north - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod5", 1, 0, "single QCD for array - north - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[28]->ref, 0, "detarrn_mod6", 1, 0, "single QCD for array - north - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[28];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdn", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ true, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[28+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[28+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrn", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[28+5]->ref, "detarrn_mod5", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+5]->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[28+6]->ref, "detarrn_mod6", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrn", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[28+1]->ref, "detarrn_mod1", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[28+2]->ref, "detarrn_mod2", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[28+3]->ref, "detarrn_mod3", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+3]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[28+4]->ref, "detarrn_mod4", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+4]->ref, refLyrBotmet, "botmet", arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[28+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 14.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[35]: single QCD for array with W botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrw", "single QCD for array - west", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod1", 1, 0, "single QCD for array - west - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod2", 1, 0, "single QCD for array - west - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod3", 1, 0, "single QCD for array - west - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod4", 1, 0, "single QCD for array - west - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod5", 1, 0, "single QCD for array - west - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[35]->ref, 0, "detarrw_mod6", 1, 0, "single QCD for array - west - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[35];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdw", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ false, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[35+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[35+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrw", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[35+5]->ref, "detarrw_mod5", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+5]->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[35+6]->ref, "detarrw_mod6", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrw", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[35+1]->ref, "detarrw_mod1", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[35+2]->ref, "detarrw_mod2", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[35+3]->ref, "detarrw_mod3", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+3]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -35000.0 - 14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[35+4]->ref, "detarrw_mod4", 14, 7, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+4]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[35+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -14.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[42]: single QCD for array with SE botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrse", "single QCD for array - southeast", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod1", 1, 0, "single QCD for array - southeast - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod2", 1, 0, "single QCD for array - southeast - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod3", 1, 0, "single QCD for array - southeast - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod4", 1, 0, "single QCD for array - southeast - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod5", 1, 0, "single QCD for array - southeast - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[42]->ref, 0, "detarrse_mod6", 1, 0, "single QCD for array - southeast - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[42];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdse", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ true, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[42+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[42+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrse", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrse2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrse3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+5]->ref, "detarrse_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+5]->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+5]->ref, "detarrse2_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+5]->ref, refLyrGrat, "grat", arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+5]->ref, "detarrse3_mod5", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+5]->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+6]->ref, "detarrse_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+6]->ref, "detarrse2_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[42+6]->ref, "detarrse3_mod6", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrse", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrse2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrse3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[42+1]->ref, "detarrse_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[42+1]->ref, "detarrse2_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[42+1]->ref, "detarrse3_mod1", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+2]->ref, "detarrse_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+2]->ref, "detarrse2_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+2]->ref, refLyrIns, "ins", -35000.0 + arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+2]->ref, "detarrse3_mod2", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+3]->ref, "detarrse_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+3]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+3]->ref, "detarrse2_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+3]->ref, refLyrBotmet, "botmet", arrrast + 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+3]->ref, "detarrse3_mod3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+3]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+4]->ref, "detarrse_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+4]->ref, "detarrse2_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrBotmet, "botmet", arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrIns, "ins", -35000.0 + arrrast + 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[42+4]->ref, "detarrse3_mod4", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[42+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[49]: single QCD for array with NE botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrne", "single QCD for array - northeast", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod1", 1, 0, "single QCD for array - northeast - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod2", 1, 0, "single QCD for array - northeast - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod3", 1, 0, "single QCD for array - northeast - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod4", 1, 0, "single QCD for array - northeast - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod5", 1, 0, "single QCD for array - northeast - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[49]->ref, 0, "detarrne_mod6", 1, 0, "single QCD for array - northeast - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[49];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdne", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ true, /*nbot*/ true, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[49+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[49+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrne", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrne2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrne3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+5]->ref, "detarrne_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+5]->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+5]->ref, "detarrne2_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+5]->ref, refLyrGrat, "grat", arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+5]->ref, "detarrne3_mod5", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+5]->ref, refLyrGrat, "grat", arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+6]->ref, "detarrne_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+6]->ref, "detarrne2_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[49+6]->ref, "detarrne3_mod6", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrne", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrne2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrne3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[49+1]->ref, "detarrne_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[49+1]->ref, "detarrne2_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[49+1]->ref, "detarrne3_mod1", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+2]->ref, "detarrne_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+2]->ref, "detarrne2_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+2]->ref, refLyrIns, "ins", -35000.0 + arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+2]->ref, "detarrne3_mod2", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+3]->ref, "detarrne_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+3]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+3]->ref, "detarrne2_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+3]->ref, refLyrBotmet, "botmet", arrrast + 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+3]->ref, "detarrne3_mod3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+3]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+4]->ref, "detarrne_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+4]->ref, "detarrne2_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrBotmet, "botmet", arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrIns, "ins", -35000.0 + arrrast + 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[49+4]->ref, "detarrne3_mod4", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrBotmet, "botmet", arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[49+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 12.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[56]: single QCD for array with NW botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrnw", "single QCD for array - northwest", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod1", 1, 0, "single QCD for array - northwest - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod2", 1, 0, "single QCD for array - northwest - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod3", 1, 0, "single QCD for array - northwest - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod4", 1, 0, "single QCD for array - northwest - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod5", 1, 0, "single QCD for array - northwest - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[56]->ref, 0, "detarrnw_mod6", 1, 0, "single QCD for array - northwest - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[56];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdnw", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ true, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[56+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[56+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrnw", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrnw2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrnw3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+5]->ref, "detarrnw_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+5]->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+5]->ref, "detarrnw2_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+5]->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+5]->ref, "detarrnw3_mod5", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+5]->ref, refLyrGrat, "grat", arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+6]->ref, "detarrnw_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+6]->ref, "detarrnw2_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[56+6]->ref, "detarrnw3_mod6", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrnw", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrnw2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrnw3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[56+1]->ref, "detarrnw_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[56+1]->ref, "detarrnw2_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[56+1]->ref, "detarrnw3_mod1", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+2]->ref, "detarrnw_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+2]->ref, "detarrnw2_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+2]->ref, "detarrnw3_mod2", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+3]->ref, "detarrnw_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+3]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+3]->ref, "detarrnw2_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+3]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -35000.0 - 12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+3]->ref, "detarrnw3_mod3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+3]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -35000.0 + 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+4]->ref, "detarrnw_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+4]->ref, "detarrnw2_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -12.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[56+4]->ref, "detarrnw3_mod4", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[56+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[63]: single QCD for array with SW botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrsw", "single QCD for array - southwest", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod1", 1, 0, "single QCD for array - southwest - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod2", 1, 0, "single QCD for array - southwest - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod3", 1, 0, "single QCD for array - southwest - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod4", 1, 0, "single QCD for array - southwest - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod5", 1, 0, "single QCD for array - southwest - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[63]->ref, 0, "detarrsw_mod6", 1, 0, "single QCD for array - southwest - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[63];

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdsw", /*gratprd*/ 8.5/*/3.3*/, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ false, /*nbot*/ false, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+1]->ref, "gratprd", 4.0/*/3.3*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+1]->ref, "gratfill", 1.0-sqmin/(4.0/*/3.3*/));
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "mis", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+2]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+3]->ref, "metgrat", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+3]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+3]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+3]->ref, "sideopn", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "schky", true);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "hgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "vgrat", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "ohmline", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "ohmring", false);
	Plnr::addBoolDpa(dbsplnr, dev->ref, dsns.nodes[63+4]->ref, "sideopn", false);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+5]->ref, "gratprd", 4.4/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+5]->ref, "gratfill", linemin/(4.4/*/2.2*/));
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+6]->ref, "gratprd", 2.7/*/2.2*/);
	Plnr::addDoubleDpa(dbsplnr, dev->ref, dsns.nodes[63+6]->ref, "gratfill", linemin/(2.7/*/2.2*/));

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrsw", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrsw2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrsw3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0+arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+5]->ref, "detarrsw_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+5]->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+5]->ref, "detarrsw2_mod5", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+5]->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+5]->ref, "detarrsw3_mod5", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+5]->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+6]->ref, "detarrsw_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+6]->ref, "detarrsw2_mod6", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoPos->ref, dsns.nodes[63+6]->ref, "detarrsw3_mod6", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+6]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrsw", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrsw2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrsw3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[63+1]->ref, "detarrsw_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[63+1]->ref, "detarrsw2_mod1", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg->ref, dsns.nodes[63+1]->ref, "detarrsw3_mod1", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+1]->ref, refLyrGrat, "grat", -35000.0 + arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+2]->ref, "detarrsw_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+2]->ref, "detarrsw2_mod2", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+2]->ref, "detarrsw3_mod2", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+2]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+3]->ref, "detarrsw_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+3]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+3]->ref, "detarrsw2_mod3", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+3]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -35000.0 - 11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+3]->ref, "detarrsw3_mod3", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+3]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -35000.0 - 15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+4]->ref, "detarrsw_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+4]->ref, "detarrsw2_mod4", 14, 7, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrBotmet, "botmet", arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 15.5*rast, -11.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	arr = new PlnrMArray(0, tpoNeg2->ref, dsns.nodes[63+4]->ref, "detarrsw3_mod4", 14, 7, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrBotmet, "botmet", arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsns.nodes[63+4]->ref, refLyrIns, "ins", -35000.0 + arrrast - 11.5*rast, -15.5*rast); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[70]: ground pads and alignment markers for array
	dsn = createDsn(dbsplnr, refPrj, "detarrfixed", "fixed items for QCD array", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	// - ground pads
	Plnr::crefToXy(rast, xofs, yofs, "A1", x, y);

	dev = createPad(dbsplnr, rast, dsn->ref, 1, "gA1", -x, y, 0.0, 0.0, devs);
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::crefToXy(rast, xofs, yofs, "A32", x, y);

	dev = createPad(dbsplnr, rast, dsn->ref, 2, "gA32", -x, y, 0.0, 0.0, devs);
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::crefToXy(rast, xofs, yofs, "AF32", x, y);

	dev = createPad(dbsplnr, rast, dsn->ref, 3, "gAF32", -x, y, 0.0, 0.0, devs);
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	Plnr::crefToXy(rast, xofs, yofs, "AF1", x, y);

	dev = createPad(dbsplnr, rast, dsn->ref, 4, "gAF1", -x, y, 0.0, 0.0, devs);
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "met");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - corners
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 5, 0, 0, "cornersw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*arrrast, -0.5*arrrast, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 6, 0, 0, "cornerse", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*arrrast, -0.5*arrrast, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "cornerne", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*arrrast, 0.5*arrrast, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 8, 0, 0, "cornernw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*arrrast, 0.5*arrrast, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, 0, refLyrGrat, refLyrBotmet, refLyrIns, 0, refLyrBump, dev->ref, "neg");
	addAnnot(dbsplnr, refLyrMesa, 0, 0, 0, refLyrTopmet, 0, dev->ref, "all");

	// -- dsns.nodes[70]: generate array and reticles

	// - for tpoPos
	arr = new PlnrMArray(0, tpoPos->ref, dsn->ref, "detarrfixed", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrMesa, "mesa", -35000.0 + arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat_mod5", arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat_mod6", -35000.0 + arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg
	arr = new PlnrMArray(0, tpoNeg->ref, dsn->ref, "detarrfixed", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -35000.0 + arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat", arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrGrat, "grat_mod1", -35000.0 + arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// - for tpoNeg2
	arr = new PlnrMArray(0, tpoNeg2->ref, dsn->ref, "detarrfixed", 14, 7, arrrast, 2.0*arrrast); dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins_mod2", -35000.0 + arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet_mod3", arrrast, -35000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet_mod4", arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins_mod4", -35000.0 + arrrast, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	Plnr::createAris(dbsplnr, arr, aris); Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[71]: mask annotation (by layer, plus global extra)
	dsn = createDsn(dbsplnr, refPrj, "maskannot", "mask annotation", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod1", 1, 0, "mask annotation - mod 1"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod2", 1, 0, "mask annotation - mod 2"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod3", 1, 0, "mask annotation - mod 3"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod4", 1, 0, "mask annotation - mod 4"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod5", 1, 0, "mask annotation - mod 5"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO, dsns.nodes[71]->ref, 0, "maskannot_mod6", 1, 0, "mask annotation - mod 6"); dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	dsn = dsns.nodes[71];

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 1, 0, 0, "annotmesa", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "B mesa p.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 2, 0, 0, "annotgrat", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A grating 8.5um/*/3.3*/ p.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "all");

	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+1]->ref, "text", "A1 grating 4.0um/*/3.3*/ p.r.");
	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+5]->ref, "text", "A5 grating 3.9um/*/2.2*/ p.r.");
	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+6]->ref, "text", "A6 grating 2.3um/*/2.2*/ p.r.");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 3, 0, 0, "annotbotmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "C bot. met. n.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "all");

	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+3]->ref, "text", "C3 bot. met. met. grat. n.r.");
	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+4]->ref, "text", "C4 bot. met. Schottky n.r.");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 4, 0, 0, "annotins", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "D ins. p.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "all");

	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+2]->ref, "text", "D2 ins. MIS p.r.");
	Plnr::addDpa(dbsplnr, dev->ref, dsns.nodes[71+4]->ref, "text", "D4 ins. Schottky p.r.");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 5, 0, 0, "annottopmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "E top met. n.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 6, 0, 0, "annotbump", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "stud-bumps");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 7, 0, 0, "annotpos", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "pos - single QCD dark faces - ICARUS Aug 2012");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, refStk, 7, 0, VecPlnrVMLayerTtype::ZERO, "pos", "0.0", "0", lyrs);
	refLyrPos = lyr->ref;

	Plnr::addLyrsru(dbsplnr, refLyrPos, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 8, 0, 0, "annotneg", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "neg - single QCD bright faces - ICARUS Aug 2012");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, refStk, 8, 0, VecPlnrVMLayerTtype::ZERO, "neg", "0.0", "0", lyrs);
	refLyrNeg = lyr->ref;
	
	Plnr::addLyrsru(dbsplnr, refLyrNeg, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 9, 0, 0, "annotneg2", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "neg2 - single QCD bright faces 2 - ICARUS Aug 2012");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, refStk, 9, 0, VecPlnrVMLayerTtype::ZERO, "neg2", "0.0", "0", lyrs);
	refLyrNeg2 = lyr->ref;
	
	Plnr::addLyrsru(dbsplnr, refLyrNeg2, dev->ref, "all");

	// - for tpopos
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPos->ref, dsn->ref, refLyrMesa, "annotpos_mesa", -0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPos->ref, dsn->ref, refLyrTopmet, "annotpos_topmet", 0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPos->ref, dsns.nodes[71+5]->ref, refLyrGrat, "annotpos_grat_mod5", 0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPos->ref, dsns.nodes[71+6]->ref, refLyrGrat, "annotpos_grat_mod6", -0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPos->ref, dsn->ref, refLyrPos, "annotpos_gbl", -37000.0, 0.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	// - for tponeg
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg->ref, dsn->ref, refLyrBotmet, "annotneg_botmet", -0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg->ref, dsn->ref, refLyrIns, "annotneg_ins", 0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg->ref, dsn->ref, refLyrGrat, "annotneg_grat", 0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg->ref, dsns.nodes[71+1]->ref, refLyrGrat, "annotpos_grat_mod1", -0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg->ref, dsn->ref, refLyrNeg, "annotneg_gbl", -37000.0, 0.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	// - for tponeg2
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg2->ref, dsns.nodes[71+2]->ref, refLyrIns, "annotneg2_ins_mod2", -0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg2->ref, dsns.nodes[71+3]->ref, refLyrBotmet, "annotneg2_botmet_mod3", 0.5*(35000.0+arrrast), -37000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg2->ref, dsns.nodes[71+4]->ref, refLyrBotmet, "annotneg2_botmet_mod4", 0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg2->ref, dsns.nodes[71+4]->ref, refLyrIns, "annotpos2_ins_mod4", -0.5*(35000.0+arrrast), 34000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoNeg2->ref, dsn->ref, refLyrNeg2, "annotneg2_gbl", -37000.0, 0.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	// -- dsns.nodes[78]: carrier with pinout for single QCDs
	dsn = createPodsn(dbsplnr, refPrj, "posng", "single QCD pinout", refStk, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, dsns);

	devcnt = 0;

	// - pinout device
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "pinout", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "pinout", devs);
	refDevPio = dev->ref;
	subdevcnt = 0;

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "rast", rast);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "cellstop", cellstop);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ratio", "2");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "framew", framew);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "padfill", false);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", 50.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "wbclr", 10.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "wbolp", 5.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "cellclr", 5.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "cellolp", 2.0);

	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");
	devcnt++;

	// sw detector pins
	StrMod::stringToVector(crefsPin1, crefsPin);

	for (unsigned int i=0;i<crefsPin.size();i++) {
		str.str(""); str << "p" << wbs1[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbs1[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPin[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;
	};

	// sw detector pads
	StrMod::stringToVector(crefsPad1, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		str.str(""); str << "I." << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPad[i]);
		devcnt++;
		subdevcnt++;
	};

	// se detector pins
	StrMod::stringToVector(crefsPin2, crefsPin);

	for (unsigned int i=0;i<crefsPin.size();i++) {
		str.str(""); str << "p" << wbs2[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbs2[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPin[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;
	};

	// se detector pads
	StrMod::stringToVector(crefsPad2, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		str.str(""); str << "II." << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPad[i]);
		devcnt++;
		subdevcnt++;
	};

	// ne detector pins
	StrMod::stringToVector(crefsPin3, crefsPin);

	for (unsigned int i=0;i<crefsPin.size();i++) {
		str.str(""); str << "p" << wbs3[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbs3[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPin[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;
	};

	// ne detector pads
	StrMod::stringToVector(crefsPad3, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		str.str(""); str << "III." << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPad[i]);
		devcnt++;
		subdevcnt++;
	};

	// nw detector pins
	StrMod::stringToVector(crefsPin4, crefsPin);

	for (unsigned int i=0;i<crefsPin.size();i++) {
		str.str(""); str << "p" << wbs4[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbs4[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPin[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;
	};

	// nw detector pads
	StrMod::stringToVector(crefsPad4, crefsPad);

	for (unsigned int i=0;i<crefsPad.size();i++) {
		str.str(""); str << "IV." << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPad[i]);
		devcnt++;
		subdevcnt++;
	};

	// sw ground pins
	StrMod::stringToVector(crefsPing1, crefsPing);

	for (unsigned int i=0;i<crefsPing.size();i++) {
		str.str(""); str << "p" << wbgs1[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbgs1[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPing[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", kogs1[i]);
		devcnt++;
		subdevcnt++;
	};

	// sw ground pads
	StrMod::stringToVector(crefsPadg1, crefsPadg);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		str.str(""); str << "Ig" << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPadg[i]);
		devcnt++;
		subdevcnt++;
	};

	// se ground pins
	StrMod::stringToVector(crefsPing2, crefsPing);

	for (unsigned int i=0;i<crefsPing.size();i++) {
		str.str(""); str << "p" << wbgs2[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbgs2[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPing[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", kogs2[i]);
		devcnt++;
		subdevcnt++;
	};

	// se ground pads
	StrMod::stringToVector(crefsPadg2, crefsPadg);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		str.str(""); str << "IIg" << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPadg[i]);
		devcnt++;
		subdevcnt++;
	};

	// ne ground pins
	StrMod::stringToVector(crefsPing3, crefsPing);

	for (unsigned int i=0;i<crefsPing.size();i++) {
		str.str(""); str << "p" << wbgs3[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbgs3[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPing[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", kogs3[i]);
		devcnt++;
		subdevcnt++;
	};

	// ne ground pads
	StrMod::stringToVector(crefsPadg3, crefsPadg);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		str.str(""); str << "IIIg" << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPadg[i]);
		devcnt++;
		subdevcnt++;
	};

	// nw ground pins
	StrMod::stringToVector(crefsPing4, crefsPing);

	for (unsigned int i=0;i<crefsPing.size();i++) {
		str.str(""); str << "p" << wbgs4[i];

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", wbgs4[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPing[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", kogs4[i]);
		devcnt++;
		subdevcnt++;
	};

	// nw ground pads
	StrMod::stringToVector(crefsPadg4, crefsPadg);

	for (unsigned int i=0;i<crefsPadg.size();i++) {
		str.str(""); str << "IVg" << (i+1);

		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsPadg[i]);
		devcnt++;
		subdevcnt++;
	};

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "void", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "void");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.2*porast);

	Plnr::addLyrsru(dbsplnr, refLyrVoid, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornersw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*porast, -0.5*porast, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerse", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*porast, -0.5*porast, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerne", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*porast, 0.5*porast, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornernw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*porast, 0.5*porast, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "A1", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x-(0.5*rast+framew+rast), y-(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AF1", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x+(0.5*rast+framew+rast), y-(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AF32", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x+(0.5*rast+framew+rast), y+(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "A32", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x-(0.5*rast+framew+rast), y+(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	// - for tpoPinout
	arr = new PlnrMArray(0, tpoPinout->ref, dsn->ref, "posng", 13, 7, porast+200.0, 2.0*(porast+200.0));
	dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);

	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -42000.0, -42000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", 42000.0, -42000.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", 42000.0, 42000.0, 180.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrVoid, "void", -42000.0, 42000.0, 270.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	Plnr::createAris(dbsplnr, arr, aris);
	Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[79]: carrier with pinout for QCD arrays
	dsn = createPodsn(dbsplnr, refPrj, "poarr", "QCD array pinout", refStk, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, dsns);

	devcnt = 0;

	// - pinout device
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "pinout", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "pinout", devs);
	refDevPio = dev->ref;
	subdevcnt = 0;

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "rast", rast);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "cellstop", cellstop);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "ratio", "2");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "framew", framew);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "padfill", true);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", 50.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "wbclr", 10.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "wbolp", 5.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "cellclr", 5.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "cellolp", 2.0);

	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");
	devcnt++;

	// sw detector pins and pads
	StrMod::stringToVector(crefsApad1, crefsApad);

	for (unsigned int i=0;i<crefsApad.size();i++) {
		str.str(""); str << "p" << awbs1[i];
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", awbs1[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;

		str << "pad";
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		devcnt++;
		subdevcnt++;
	};

	// se detector pins and pads
	StrMod::stringToVector(crefsApad2, crefsApad);

	for (unsigned int i=0;i<crefsApad.size();i++) {
		str.str(""); str << "p" << awbs2[i];
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", awbs2[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;

		str << "pad";
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		devcnt++;
		subdevcnt++;
	};

	// ne detector pins and pads
	StrMod::stringToVector(crefsApad3, crefsApad);

	for (unsigned int i=0;i<crefsApad.size();i++) {
		str.str(""); str << "p" << awbs3[i];
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", awbs3[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;

		str << "pad";
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		devcnt++;
		subdevcnt++;
	};

	// nw detector pins and pads
	StrMod::stringToVector(crefsApad4, crefsApad);

	for (unsigned int i=0;i<crefsApad.size();i++) {
		str.str(""); str << "p" << awbs4[i];
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", awbs4[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;

		str << "pad";
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		devcnt++;
		subdevcnt++;
	};

	// ground pins and pads
	StrMod::stringToVector(crefsApadg, crefsApad);

	for (unsigned int i=0;i<crefsApad.size();i++) {
		str.str(""); str << "p" << awbgs[i];
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopin", devs);
		Plnr::changeIntDpa(dbsplnr, dev->ref, 0, "wb", awbgs[i]);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "keepoff", false);
		devcnt++;
		subdevcnt++;

		str << "pad";
		dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, refDevPio, subdevcnt+1, str.str(), VecPlnrVMDeviceAligntype::ABS, "", "", "", "",
					0.0, 0.0, 0.0, "", refsDtp, "piopad", devs);
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "cell", crefsApad[i]);
		devcnt++;
		subdevcnt++;
	};

	// - annotation devices
	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "void", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "void");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 0.2*porast);

	Plnr::addLyrsru(dbsplnr, refLyrVoid, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornersw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*porast, -0.5*porast, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerse", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*porast, -0.5*porast, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornerne", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				0.5*porast, 0.5*porast, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "cornernw", VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				-0.5*porast, 0.5*porast, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", "200.0");
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "w", "10.0");

	addAnnot(dbsplnr, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, refLyrVoid, 0, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "A1", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x-(0.5*rast+framew+rast), y-(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AF1", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF1", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x+(0.5*rast+framew+rast), y-(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF1");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "AF32", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotAF32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x+(0.5*rast+framew+rast), y+(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "AF32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	Plnr::crefToXy(rast, xofs, yofs, "A32", x, y);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, devcnt+1, 0, 0, "annotA32", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				x-(0.5*rast+framew+rast), y+(0.5*rast+framew+rast), 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A32");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", rast);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");
	devcnt++;

	// - for tpoPinout
	arr = new PlnrMArray(0, tpoPinout->ref, dsn->ref, "poarr", 13, 6, porast+200.0, 2.0*(porast+200.0));
	dbsplnr->tblplnrmarray->insertRec(arr); arrs.nodes.push_back(arr);

	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrBotmet, "botmet", -42000.0+porast+200.0, -42000.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrIns, "ins", 42000.0, -42000.0+porast+200.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrTopmet, "topmet", 42000.0-(porast+200.0), 42000.0, 180.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::ARR, arr->ref, dsn->ref, refLyrVoid, "void", -42000.0, 42000.0-(porast+200.0), 270.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	Plnr::createAris(dbsplnr, arr, aris);
	Plnr::createArrrtcs(dbsplnr, arr->ref);

	// -- dsns.nodes[80]: carrier mask annotation (by layer, plus global extra)
	dsn = new PlnrMDesign(0, 0, 0, VecPlnrVMDesignBasetype::VRTLYR, VecPlnrVMDesignDim::XY, VecPlnrVMDesignRefTbl::VOID, 0, refPrj, 0, 0, 0, "poannot", 1, 0, "pinout wafer annotation");
	dbsplnr->tblplnrmdesign->insertRec(dsn); dsns.nodes.push_back(dsn);

	stk = new PlnrMStack(0, VecPlnrVMStackBasetype::LITHO, dsn->ref, 1, "all", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::VOID, "", 0.0, "", "0");
	dbsplnr->tblplnrmstack->insertRec(stk);
	refStk = stk->ref;

	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 1, 0, VecPlnrVMLayerTtype::ZERO, "botmet", "0.0", "0", lyrs);
	refLyrBotmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 2, 0, VecPlnrVMLayerTtype::ZERO, "ins", "0.0", "0", lyrs);
	refLyrIns = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 3, 0, VecPlnrVMLayerTtype::ZERO, "topmet", "0.0", "0", lyrs);
	refLyrTopmet = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 4, 0, VecPlnrVMLayerTtype::ZERO, "bump", "0.0", "0", lyrs);
	refLyrBump = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 5, 0, VecPlnrVMLayerTtype::ZERO, "void", "0.0", "0", lyrs);
	refLyrVoid = lyr->ref;
	lyr = Plnr::addLayer(dbsplnr, VecPlnrVMLayerBasetype::LITHO, stk->ref, 6, 0, VecPlnrVMLayerTtype::ZERO, "gbl", "0.0", "0", lyrs);
	refLyrGbl = lyr->ref;

	delete stk;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 1, 0, 0, "annotbotmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "A bot. met. n.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 2, 0, 0, "annotins", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "B ins. n.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 3, 0, 0, "annottopmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "C top met. n.r.");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 4, 0, 0, "annotvoid", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "X void");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrVoid, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, 5, 0, 0, "annotpos", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, 0.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "pinout - single QCD carrier dark faces - ICARUS Aug 2012");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);

	Plnr::addLyrsru(dbsplnr, refLyrGbl, dev->ref, "all");

	// - for tpoPinout
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPinout->ref, dsn->ref, refLyrBotmet, "annotcarr_botmet", -0.5*45000.0, -45000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPinout->ref, dsn->ref, refLyrIns, "annotcarr_ins", 0.5*45000.0, -45000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPinout->ref, dsn->ref, refLyrTopmet, "annotcarr_topmet", 0.5*45000.0, 45000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPinout->ref, dsn->ref, refLyrVoid, "annotcarr_void", -0.5*45000.0, 45000.0, 0.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
	rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, tpoPinout->ref, dsn->ref, refLyrGbl, "annotcarr_gbl", -45000.0, 0.0, 90.0); dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);

	// --- prepare for expansion and plot generation by op's
	refsDsn.resize(0);
	for (unsigned int i=0 ; i<dsns.nodes.size() ; i++) refsDsn.push_back(dsns.nodes[i]->ref);

	// --- clean up
	delete tpoPos;
	delete tpoNeg;
	delete tpoNeg2;
	delete tpoPinout;

	retval = VecVSge::EXPAND1;

// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void JobPlnrTpoIcabatch1::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint JobPlnrTpoIcabatch1::enterSgeExpand1(
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

void JobPlnrTpoIcabatch1::leaveSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand1 --- INSERT
};

uint JobPlnrTpoIcabatch1::enterSgeExpand2(
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

void JobPlnrTpoIcabatch1::leaveSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand2 --- INSERT
};

uint JobPlnrTpoIcabatch1::enterSgePlot(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PLOT;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgePlot --- IBEGIN
	vector<DpchInvPlnr*> dpchinvs;

	vector<string> filenames;

	// refsDsn[0]: single detector design
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[0], {}, false, false, true, true, true, 5000));
	filenames.push_back("detsng_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[0], {}, false, true, false, false, true, 5000));
	filenames.push_back("detsng_fces.xml");

	// single detector design modifications
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[0+2], {}, false, true, false, false, true, 5000));
	filenames.push_back("detsng_mod2.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[0+3], {}, false, true, false, false, true, 5000));
	filenames.push_back("detsng_mod3.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[0+4], {}, false, true, false, false, true, 5000));
	filenames.push_back("detsng_mod4.xml");

	// refsDsn[63]: NW for array
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[63], {}, false, false, true, true, true, 1000));
	filenames.push_back("detarr_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[63], {}, false, true, false, false, true, 1000));
	filenames.push_back("detarr_fces.xml");

	// NW for array design modifications
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[63+2], {}, false, true, false, false, true, 1000));
	filenames.push_back("detarr_mod2.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[63+3], {}, false, true, false, false, true, 1000));
	filenames.push_back("detarr_mod3.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[63+4], {}, false, true, false, false, true, 1000));
	filenames.push_back("detarr_mod4.xml");

	// refsDsn[78]: single detector carrier
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[78], {}, false, false, true, true, true, 5000));
	filenames.push_back("posng_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[78], {}, false, true, false, false, true, 5000));
	filenames.push_back("posng_fces.xml");

	// refsDsn[79]: detector array carrier
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[79], {}, false, false, true, true, true, 5000));
	filenames.push_back("poarr_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 5000, refsDsn[79], {}, false, true, false, false, true, 5000));
	filenames.push_back("poarr_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoPos));
	filenames.push_back("pos.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoNeg));
	filenames.push_back("neg.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoNeg2));
	filenames.push_back("neg2.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoPinout));
	filenames.push_back("pinout.cif");

	// --- pass to op processors
	addInvs(dpchinvs);

	// prepare collection of plot files in one folder	
	plotfolder = Tmp::newfolder(xchg->tmppath);

	for (unsigned int i=0;i<dpchinvs.size();i++) plots[dpchinvs[i]->oref] = filenames[i];
// IP enterSgePlot --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void JobPlnrTpoIcabatch1::leaveSgePlot(
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

uint JobPlnrTpoIcabatch1::enterSgeDone(
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

void JobPlnrTpoIcabatch1::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string JobPlnrTpoIcabatch1::getSquawk(
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

void JobPlnrTpoIcabatch1::handleRequest(
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

bool JobPlnrTpoIcabatch1::handleRun(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
// IP handleRun --- IBEGIN
	changeStage(dbsplnr, VecVSge::CREIDLE);
// IP handleRun --- IEND
	return retval;
};

void JobPlnrTpoIcabatch1::handleTimer(
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


