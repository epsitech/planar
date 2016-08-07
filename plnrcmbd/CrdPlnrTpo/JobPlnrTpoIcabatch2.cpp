/**
  * \file JobPlnrTpoIcabatch2.cpp
  * job handler for job JobPlnrTpoIcabatch2 (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "JobPlnrTpoIcabatch2.h"

// IP blksInclude --- BEGIN
#include "JobPlnrTpoIcabatch2_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class JobPlnrTpoIcabatch2
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
JobPlnrTpoIcabatch2::JobPlnrTpoIcabatch2(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::JOBPLNRTPOICABATCH2, jrefSup, ixPlnrVLocale) {
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

JobPlnrTpoIcabatch2::~JobPlnrTpoIcabatch2() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
PlnrMTapeout* JobPlnrTpoIcabatch2::createTpo(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMProject
			, const string& Title
			, const bool Hflip
		) {
	PlnrMTapeout* tpo = NULL;
	ubigint refTpj;

	dbsplnr->tblplnrmtapeout->insertNewRec(&tpo, 0, 0, VecPlnrVMTapeoutBasetype::PLN, Title, 1, 0, 0, VecPlnrVMTapeoutState::DSN, Hflip, "");

	refTpj = dbsplnr->tblplnrjmtapeoutstate->insertNewRec(NULL, tpo->ref, 0, VecPlnrVMTapeoutState::DSN);
	tpo->refJState = refTpj;
	dbsplnr->tblplnrmtapeout->updateRec(tpo);

	dbsplnr->tblplnrrmprojectmtapeout->insertNewRec(NULL, refPlnrMProject, tpo->ref);

	return tpo;
};

PlnrMDesign* JobPlnrTpoIcabatch2::createDsn(
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

PlnrMDevice* JobPlnrTpoIcabatch2::createDetsng(
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
	const double mesaclr = 3.0;
	const double botw = 4.0;
	bool ringbot;
	const double metclr = 3.0;
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

PlnrMDevice* JobPlnrTpoIcabatch2::createDetarr(
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
	const double mesaclr = 3.0;
	const double botw = 4.0;
	const double metclr = 3.0;
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

PlnrMDevice* JobPlnrTpoIcabatch2::createPad(
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

void JobPlnrTpoIcabatch2::addAnnot(
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

void JobPlnrTpoIcabatch2::addMarker(
			DbsPlnr* dbsplnr
			, const string& type
			, const bool sq
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string& sref
			, const double x
			, const double y
			, const ubigint refLyrMesa
			, const ubigint refLyrTopmet
			, const ubigint refLyrBotmet
			, const ubigint refLyrIns
			, const ubigint refLyrGrat
		) {
	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum+1, 0, 0, "cornsw_" + sref, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				x, y, 180.0, "", refsDtp, "corner", devs);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", 30.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "w", 3.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sq", false);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "alnclr", 1.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "sprclr", 4.0);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum+2, 0, 0, "cornse_" + sref, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				x, y, 270.0, "", refsDtp, "corner", devs);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", 30.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "w", 3.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sq", false);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "alnclr", 1.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "sprclr", 4.0);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum+3, 0, 0, "cornne_" + sref, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				x, y, 0.0, "", refsDtp, "corner", devs);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", 30.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "w", 3.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sq", sq);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "alnclr", 1.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "sprclr", 4.0);

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsnRefPlnrMDesign, dsnNum+4, 0, 0, "cornnw_" + sref, VecPlnrVMDeviceAligntype::ABS, "v0", "", "", "",
				x, y, 90.0, "", refsDtp, "corner", devs);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", 30.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "w", 3.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sq", false);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "alnclr", 1.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "sprclr", 4.0);

	if (type.compare("grat") == 0) {
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "neg");
		};

	} else if (type.compare("mesa") == 0) {
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "neg");
			Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "alnneg");
		};

	} else if (type.compare("botmet") == 0) {
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "neg");
			Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "alnpos");
		};

	} else if (type.compare("ins") == 0) {
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "neg");
			Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "alnneg");
		};

	} else if (type.compare("topmet") == 0) {
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "neg");
			Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "sprpos");
			Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "alnneg");
		};
	};
};

void JobPlnrTpoIcabatch2::createMask(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string& sref
			, const ubigint refPlnrMLayer
			, const double x0
			, const double y0
			, const usmallint I
			, const usmallint J
			, const double di
			, const double dj
			, const usmallint K
			, const usmallint L
			, const double dk
			, const double dl
			, const usmallint M
			, const usmallint N
			, const double dm
			, const double dn
		) {
	PlnrMArray* arr = NULL;
	ListPlnrMArrayitem aris;

	dbsplnr->tblplnrmarray->insertNewRec(&arr, refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::ARR, arr->ref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0);

	Plnr::createAris(dbsplnr, arr, aris);
	Plnr::createArrrtcs(dbsplnr, arr->ref);

	delete arr;
};
// IP cust --- IEND
// IP spec --- INSERT

// IP changeStage --- BEGIN
// IP changeStage.hdr --- BEGIN
void JobPlnrTpoIcabatch2::changeStage(
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

uint JobPlnrTpoIcabatch2::enterSgeIdle(
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

void JobPlnrTpoIcabatch2::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint JobPlnrTpoIcabatch2::enterSgeCreidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSge = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeCreidle --- INSERT
	return retval;
};

void JobPlnrTpoIcabatch2::leaveSgeCreidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreidle --- INSERT
};

uint JobPlnrTpoIcabatch2::enterSgeCreate(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::EXPAND1;
// IP enterSgeCreate --- IBEGIN
	ostringstream str, str2;

	ubigint refPrj;

	ListPlnrMDesign dsns;
	PlnrMDesign* dsn = NULL;

	ubigint refStk;

	ListPlnrMLayer lyrs;

	ubigint refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;
	unsigned int devcnt;

	PlnrMTapeout* tpoGratNeg = NULL;
	PlnrMTapeout* tpoMesaPos = NULL;
	PlnrMTapeout* tpoBotmetNeg = NULL;
	PlnrMTapeout* tpoInsNeg = NULL;
	PlnrMTapeout* tpoTopmetPos = NULL;

	refPrj = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	// general variables
	const double rast = 75.0;
	const double arrrast = 32.0*rast+50.0;

	string cellstop = "AF32";

	const unsigned int Nrep = 4;
	double ofs = -0.5*(((double) Nrep) * arrrast) + 0.5*arrrast;

	const double lam = 8.2;

	string type;

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

	// same for detsng and posng - ground openings
	string crefsPadg1 = "A1;A5;E5;E1;A9;I9;I1;A13;M13;M1";
	string crefsPadg2 = "AF1;AF5;AB5;AB1;AF9;X9;X1;AF13;T13;T1";
	string crefsPadg3 = "AF32;AF28;AB28;AB32;AF24;X24;X32;AF20;T20;T32";
	string crefsPadg4 = "A32;A28;E28;E32;A24;I24;I32;A20;M20;M32";

	// detsng only - southwest corner cell of ground pads
	string crefsPadgsw1 = "A1;A4;E4;E1;A8;I8;I1;A12;M13;M1";
	string crefsPadgsw2 = "AE1;AE4;AA4;AB1;AE8;W8;X1;AE12;T13;T1";
	string crefsPadgsw3 = "AE31;AE28;AA28;AB32;AE24;W24;X32;AE20;T20;T32";
	string crefsPadgsw4 = "A31;A28;E28;E32;A24;I24;I32;A20;M20;M32";

	// detsng only - northeast corner cell of ground pads
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

	// same for detarr and poarr - ground openings
	string crefsApadg = "A1;AF1;AF32;A32";

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

	// --- set up tape-outs
	tpoGratNeg = createTpo(dbsplnr, refPrj, "ICARUS Aug2013 - grating - bright faces", false); refTpoGratNeg = tpoGratNeg->ref;
	tpoMesaPos = createTpo(dbsplnr, refPrj, "ICARUS Aug2013 - mesa - dark faces", false); refTpoMesaPos = tpoMesaPos->ref;
	tpoBotmetNeg = createTpo(dbsplnr, refPrj, "ICARUS Aug2013 - bottom metal - bright faces", false); refTpoBotmetNeg = tpoBotmetNeg->ref;
	tpoInsNeg = createTpo(dbsplnr, refPrj, "ICARUS Aug2013 - insulation - bright faces", false); refTpoInsNeg = tpoInsNeg->ref;
	tpoTopmetPos = createTpo(dbsplnr, refPrj, "ICARUS Aug2013 - top metal - dark faces", false); refTpoTopmetPos = tpoTopmetPos->ref;

	// --- create designs as well as arrays/reticles
	Plnr::cellstopToXyofs(rast, cellstop, xofs, yofs);

	// -- dsns.nodes[0]: design containing layout with 80 individual QCD's
	dsn = createDsn(dbsplnr, refPrj, "detsng", "4x20 single QCD", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

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
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
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
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ (lam-0.1)/3.1, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
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
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ true, /*gratprd*/ (lam+0.1)/3.1, /*gratfill*/ 1.0-sqrt(0.5), extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
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
		dev = createDetsng(dbsplnr, rast, dsn->ref, devcnt+1, str.str(), -x, y, size, ext, /*vgrat*/ false, /*gratprd*/ lam/3.1, /*gratfill*/ 1.0/2.0, extsize, -extofsx, extofsy, -bumpofsx, bumpofsy, devs);
		Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
		Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
		Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
		Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
		Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
		Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

		devcnt++;
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

	// -- dsns.nodes[0]: generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detsng-mesa", refLyrMesa, ofs, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detsng-topmet", refLyrTopmet, ofs, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detsng-botmet", refLyrBotmet, ofs, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detsng-ins", refLyrIns, ofs, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detsng-grat", refLyrGrat, ofs, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);

	// -- dsns.nodes[1]: single QCD for array without botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrc", "single QCD for array - central", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdc", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrc-mesa", refLyrMesa, ofs + arrrast - 14.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrc-topmet", refLyrTopmet, ofs + arrrast - 14.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrc-botmet", refLyrBotmet, ofs + arrrast - 14.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrc-ins", refLyrIns, ofs + arrrast - 14.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrc-grat", refLyrGrat, ofs + arrrast - 14.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 2, rast, rast);

	// -- dsns.nodes[2]: single QCD for array with S botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrs", "single QCD for array - south", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcds", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ false, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrs-mesa", refLyrMesa, ofs + arrrast - 14.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrs-topmet", refLyrTopmet, ofs + arrrast - 14.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrs-botmet", refLyrBotmet, ofs + arrrast - 14.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrs-ins", refLyrIns, ofs + arrrast - 14.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrs-grat", refLyrGrat, ofs + arrrast - 14.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);

	// -- dsns.nodes[3]: single QCD for array with E botmet
	dsn = createDsn(dbsplnr, refPrj, "detarre", "single QCD for array - east", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcde", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ true, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarre-mesa", refLyrMesa, ofs + arrrast - 12.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarre-topmet", refLyrTopmet, ofs + arrrast - 12.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarre-botmet", refLyrBotmet, ofs + arrrast - 12.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarre-ins", refLyrIns, ofs + arrrast - 12.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarre-grat", refLyrGrat, ofs + arrrast - 12.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);

	// -- dsns.nodes[4]: single QCD for array with N botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrn", "single QCD for array - north", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdn", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ true, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrn-mesa", refLyrMesa, ofs + arrrast - 14.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrn-topmet", refLyrTopmet, ofs + arrrast - 14.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrn-botmet", refLyrBotmet, ofs + arrrast - 14.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrn-ins", refLyrIns, ofs + arrrast - 14.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrn-grat", refLyrGrat, ofs + arrrast - 14.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 1, 2, rast, rast);

	// -- dsns.nodes[5]: single QCD for array with W botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrw", "single QCD for array - west", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdw", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ false, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrw-mesa", refLyrMesa, ofs + arrrast - 15.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrw-topmet", refLyrTopmet, ofs + arrrast - 15.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrw-botmet", refLyrBotmet, ofs + arrrast - 15.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrw-ins", refLyrIns, ofs + arrrast - 15.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrw-grat", refLyrGrat, ofs + arrrast - 15.5*rast, ofs - 14.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 8, 8, 4.0*rast, 4.0*rast, 2, 1, rast, rast);

	// -- dsns.nodes[6]: single QCD for array with SE botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrse", "single QCD for array - southeast", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdse", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ true, /*nbot*/ false, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrse-mesa", refLyrMesa, ofs + arrrast - 12.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrse-topmet", refLyrTopmet, ofs + arrrast - 12.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrse-botmet", refLyrBotmet, ofs + arrrast - 12.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrse-ins", refLyrIns, ofs + arrrast - 12.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrse-grat", refLyrGrat, ofs + arrrast - 12.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrse2-mesa", refLyrMesa, ofs + arrrast + 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrse2-topmet", refLyrTopmet, ofs + arrrast + 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrse2-botmet", refLyrBotmet, ofs + arrrast + 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrse2-ins", refLyrIns, ofs + arrrast + 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrse2-grat", refLyrGrat, ofs + arrrast + 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrse3-mesa", refLyrMesa, ofs + arrrast - 12.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrse3-topmet", refLyrTopmet, ofs + arrrast - 12.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrse3-botmet", refLyrBotmet, ofs + arrrast - 12.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrse3-ins", refLyrIns, ofs + arrrast - 12.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrse3-grat", refLyrGrat, ofs + arrrast - 12.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);

	// -- dsns.nodes[7]: single QCD for array with NE botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrne", "single QCD for array - northeast", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdne", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ true, /*nbot*/ true, /*wbot*/ false, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrne-mesa", refLyrMesa, ofs + arrrast - 12.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrne-topmet", refLyrTopmet, ofs + arrrast - 12.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrne-botmet", refLyrBotmet, ofs + arrrast - 12.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrne-ins", refLyrIns, ofs + arrrast - 12.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrne-grat", refLyrGrat, ofs + arrrast - 12.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrne2-mesa", refLyrMesa, ofs + arrrast + 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrne2-topmet", refLyrTopmet, ofs + arrrast + 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrne2-botmet", refLyrBotmet, ofs + arrrast + 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrne2-ins", refLyrIns, ofs + arrrast + 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrne2-grat", refLyrGrat, ofs + arrrast + 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrne3-mesa", refLyrMesa, ofs + arrrast - 12.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrne3-topmet", refLyrTopmet, ofs + arrrast - 12.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrne3-botmet", refLyrBotmet, ofs + arrrast - 12.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrne3-ins", refLyrIns, ofs + arrrast - 12.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrne3-grat", refLyrGrat, ofs + arrrast - 12.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);

	// -- dsns.nodes[8]: single QCD for array with NW botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrnw", "single QCD for array - northwest", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdnw", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ false, /*ebot*/ false, /*nbot*/ true, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrnw-mesa", refLyrMesa, ofs + arrrast - 11.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrnw-topmet", refLyrTopmet, ofs + arrrast - 11.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrnw-botmet", refLyrBotmet, ofs + arrrast - 11.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrnw-ins", refLyrIns, ofs + arrrast - 11.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrnw-grat", refLyrGrat, ofs + arrrast - 11.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrnw2-mesa", refLyrMesa, ofs + arrrast - 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrnw2-topmet", refLyrTopmet, ofs + arrrast - 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrnw2-botmet", refLyrBotmet, ofs + arrrast - 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrnw2-ins", refLyrIns, ofs + arrrast - 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrnw2-grat", refLyrGrat, ofs + arrrast - 15.5*rast, ofs - 12.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrnw3-mesa", refLyrMesa, ofs + arrrast - 11.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrnw3-topmet", refLyrTopmet, ofs + arrrast - 11.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrnw3-botmet", refLyrBotmet, ofs + arrrast - 11.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrnw3-ins", refLyrIns, ofs + arrrast - 11.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrnw3-grat", refLyrGrat, ofs + arrrast - 11.5*rast, ofs + 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);

	// -- dsns.nodes[9]: single QCD for array with SW botmet
	dsn = createDsn(dbsplnr, refPrj, "detarrsw", "single QCD for array - southwest", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	dev = createDetarr(dbsplnr, rast, dsn->ref, 1, "qcdsw", /*gratprd*/ lam/3.1, /*gratfill*/ 1.0-sqrt(0.5), /*sbot*/ true, /*ebot*/ false, /*nbot*/ false, /*wbot*/ true, devs);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "mesa");
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "grat");
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "botmet");
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "ins");
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "topmet");
	Plnr::addLyrsru(dbsplnr, refLyrBump, dev->ref, "bump");

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrsw-mesa", refLyrMesa, ofs + arrrast - 11.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrsw-topmet", refLyrTopmet, ofs + arrrast - 11.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrsw-botmet", refLyrBotmet, ofs + arrrast - 11.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrsw-ins", refLyrIns, ofs + arrrast - 11.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrsw-grat", refLyrGrat, ofs + arrrast - 11.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 7, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrsw2-mesa", refLyrMesa, ofs + arrrast - 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrsw2-topmet", refLyrTopmet, ofs + arrrast - 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrsw2-botmet", refLyrBotmet, ofs + arrrast - 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrsw2-ins", refLyrIns, ofs + arrrast - 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrsw2-grat", refLyrGrat, ofs + arrrast - 15.5*rast, ofs - 11.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 7, 1, 4.0*rast, 4.0*rast);

	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrsw3-mesa", refLyrMesa, ofs + arrrast - 11.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrsw3-topmet", refLyrTopmet, ofs + arrrast - 11.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrsw3-botmet", refLyrBotmet, ofs + arrrast - 11.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrsw3-ins", refLyrIns, ofs + arrrast - 11.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrsw3-grat", refLyrGrat, ofs + arrrast - 11.5*rast, ofs - 15.5*rast, Nrep, Nrep/2, arrrast, 2.0*arrrast, 1, 7, 4.0*rast, 4.0*rast);

	// -- dsns.nodes[10]: ground pads and alignment markers for array
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

	// - generate arrays and reticles
	createMask(dbsplnr, refTpoMesaPos, dsn->ref, "detarrfixed-mesa", refLyrMesa, ofs + arrrast, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoTopmetPos, dsn->ref, "detarrfixed-topmet", refLyrTopmet, ofs + arrrast, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoBotmetNeg, dsn->ref, "detarrfixed-botmet", refLyrBotmet, ofs + arrrast, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoInsNeg, dsn->ref, "detarrfixed-ins", refLyrIns, ofs + arrrast, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);
	createMask(dbsplnr, refTpoGratNeg, dsn->ref, "detarrfixed-grat", refLyrGrat, ofs + arrrast, ofs, Nrep, Nrep/2, arrrast, 2.0*arrrast);

	// -- dsns.nodes[11]: mask annotation and alignment markers
	ofs -= 0.5*arrrast; // sw corner instead of center

	dsn = createDsn(dbsplnr, refPrj, "maskannot", "mask annotation", refStk, refLyrMesa, refLyrGrat, refLyrBotmet, refLyrIns, refLyrTopmet, refLyrBump, dsns);

	devcnt = 0;

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, ++devcnt, 0, 0, "annotmesa", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, ofs-1200.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "mesa p.r. wr-");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);
	Plnr::addLyrsru(dbsplnr, refLyrMesa, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, ++devcnt, 0, 0, "annottopmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, ofs-1200.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "top met. n.r. wr-");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);
	Plnr::addLyrsru(dbsplnr, refLyrTopmet, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, ++devcnt, 0, 0, "annotbotmet", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, ofs-1200.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "bot. met. n.r. wr+");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);
	Plnr::addLyrsru(dbsplnr, refLyrBotmet, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, ++devcnt, 0, 0, "annotins", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, ofs-1200.0, 0.0, "", refsDtp, "dottext", devs);
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", "ins. p.r. wr+");
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);
	Plnr::addLyrsru(dbsplnr, refLyrIns, dev->ref, "all");

	dev = Plnr::addDeviceFromTpl(dbsplnr, dsn->ref, ++devcnt, 0, 0, "annotgrat", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "",
				0.0, ofs-1200.0, 0.0, "", refsDtp, "dottext", devs);
	str.str(""); str << "grat. " << lam << "/3.1 p.r. wr+";
	Plnr::changeDpa(dbsplnr, dev->ref, 0, "text", str.str());
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "h", 1000.0);
	Plnr::addLyrsru(dbsplnr, refLyrGrat, dev->ref, "all");

	// - alignment markers
	for (unsigned int i=0;i<=Nrep;i++) {
		for (unsigned int j=0;j<=Nrep;j++) {
			if (((i+j)%5) == 0) {
				type = "grat";
			} else if (((i+j)%5) == 1) {
				type = "mesa";
			} else if (((i+j)%5) == 2) {
				type = "botmet";
			} else if (((i+j)%5) == 3) {
				type = "ins";
			} else if (((i+j)%5) == 4) {
				type = "topmet";
			};

			str.str(""); str << "i" << i << "j" << j;

			xofs = ofs + ((double) j)*arrrast;
			yofs = ofs + ((double) i)*arrrast;

			addMarker(dbsplnr, type, false, dsn->ref, devcnt, str.str(), xofs, yofs, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat);

			devcnt += 4;
		};
	};

	addMarker(dbsplnr, "grat", true, dsn->ref, devcnt, "grat1", ofs+100.0, ofs-100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "mesa", true, dsn->ref, devcnt, "mesa1", ofs+200.0, ofs-100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "botmet", true, dsn->ref, devcnt, "botmet1", ofs+300.0, ofs-100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "ins", true, dsn->ref, devcnt, "ins1", ofs+400.0, ofs-100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "topmet", true, dsn->ref, devcnt, "topmet1", ofs+500.0, ofs-100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;

	addMarker(dbsplnr, "grat", true, dsn->ref, devcnt, "grat2", -ofs-500.0, -ofs+100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "mesa", true, dsn->ref, devcnt, "mesa2", -ofs-400.0, -ofs+100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "botmet", true, dsn->ref, devcnt, "botmet2", -ofs-300.0, -ofs+100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "ins", true, dsn->ref, devcnt, "ins2", -ofs-200.0, -ofs+100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;
	addMarker(dbsplnr, "topmet", true, dsn->ref, devcnt, "topmet2", -ofs-100.0, -ofs+100.0, refLyrMesa, refLyrTopmet, refLyrBotmet, refLyrIns, refLyrGrat); devcnt += 4;

	// - add as single reticles
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, refTpoGratNeg, dsn->ref, refLyrGrat, "annot", 0.0, 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, refTpoMesaPos, dsn->ref, refLyrMesa, "annot", 0.0, 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, refTpoBotmetNeg, dsn->ref, refLyrBotmet, "annot", 0.0, 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, refTpoInsNeg, dsn->ref, refLyrIns, "annot", 0.0, 0.0, 0.0);
	dbsplnr->tblplnrmreticle->insertNewRec(NULL, VecPlnrVMReticleHkTbl::TPO, refTpoTopmetPos, dsn->ref, refLyrTopmet, "annot", 0.0, 0.0, 0.0);

	// --- prepare for expansion and plot generation by op's
	refsDsn.resize(0);
	for (unsigned int i=0 ; i<dsns.nodes.size() ; i++) refsDsn.push_back(dsns.nodes[i]->ref);

	// --- clean up
	delete tpoGratNeg;
	delete tpoMesaPos;
	delete tpoBotmetNeg;
	delete tpoInsNeg;
	delete tpoTopmetPos;

	retval = VecVSge::EXPAND1;

// IP enterSgeCreate --- IEND
	retval = nextIxVSge;
	return retval;
};

void JobPlnrTpoIcabatch2::leaveSgeCreate(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeCreate --- INSERT
};

uint JobPlnrTpoIcabatch2::enterSgeExpand1(
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

void JobPlnrTpoIcabatch2::leaveSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand1 --- INSERT
};

uint JobPlnrTpoIcabatch2::enterSgeExpand2(
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

void JobPlnrTpoIcabatch2::leaveSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand2 --- INSERT
};

uint JobPlnrTpoIcabatch2::enterSgePlot(
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

	// refsDsn[8]: NW for array
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[8], {}, false, false, true, true, true, 1000));
	filenames.push_back("detarr_vtxgds.xml");
	dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 750, refsDsn[8], {}, false, true, false, false, true, 1000));
	filenames.push_back("detarr_fces.xml");

	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoGratNeg));
	filenames.push_back("gratneg.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoMesaPos));
	filenames.push_back("mesapos.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoBotmetNeg));
	filenames.push_back("botmetneg.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoInsNeg));
	filenames.push_back("insneg.cif");
	dpchinvs.push_back(new DpchInvPlnrPlotTpotxt(0, 0, true, false, 0.25, refTpoTopmetPos));
	filenames.push_back("topmetpos.cif");

	// --- pass to op processors
	addInvs(dpchinvs);

	// prepare collection of plot files in one folder	
	plotfolder = Tmp::newfolder(xchg->tmppath);

	for (unsigned int i=0;i<dpchinvs.size();i++) plots[dpchinvs[i]->oref] = filenames[i];
// IP enterSgePlot --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void JobPlnrTpoIcabatch2::leaveSgePlot(
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

uint JobPlnrTpoIcabatch2::enterSgeDone(
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

void JobPlnrTpoIcabatch2::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string JobPlnrTpoIcabatch2::getSquawk(
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

void JobPlnrTpoIcabatch2::handleRequest(
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

bool JobPlnrTpoIcabatch2::handleRun(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
// IP handleRun --- IBEGIN
	changeStage(dbsplnr, VecVSge::CREIDLE);
// IP handleRun --- IEND
	return retval;
};

void JobPlnrTpoIcabatch2::handleTimer(
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


