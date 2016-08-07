/**
  * \file PlnrExpPhotdet.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrExpPhotdet.h"

DpchRetPlnr* PlnrExpPhotdet::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhotdet* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruMesa = 0;
	ubigint refSruGrat = 0;
	ubigint refSruBotmet = 0;
	ubigint refSruIns = 0;
	ubigint refSruTopmet = 0;
	ubigint refSruBump = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "mesa", refSruMesa);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "grat", refSruGrat);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "botmet", refSruBotmet);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "ins", refSruIns);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "topmet", refSruTopmet);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "bump", refSruBump);

	// load baseline parameters
	double size0 = 100.0; double size;
	bool ext0 = false; bool ext;
	bool metgrat0 = false; bool metgrat;
	bool mis0 = false; bool mis;
	bool schky0 = false; bool schky;
	bool hgrat0 = true; bool hgrat;
	bool vgrat0 = false; bool vgrat;
	double gratprd0 = 8.0; double gratprd;
	double gratfill0 = 0.5; double gratfill;
	double mesaclr0 = 5.0; double mesaclr;
	double botw0 = 5.0; double botw;
	bool sbot0 = false; bool sbot;
	bool ebot0 = false; bool ebot;
	bool nbot0 = false; bool nbot;
	bool wbot0 = false; bool wbot;
	double metclr0 = 4.0; double metclr;
	bool ohmline0 = true; bool ohmline;
	bool ohmring0 = false; bool ohmring;
	double olp0 = 2.0; double olp;
	bool sideopn0 = false; bool sideopn;
	double opnsize0 = 2.0; double opnsize;
	bool topfill0 = false; bool topfill;
	double extsize0 = 80.0; double extsize;
	double extofsx0 = 0.0; double extofsx;
	double extofsy0 = 0.0; double extofsy;
	double bumpd0 = 50.0; double bumpd;
	double bumpofsx0 = 0.0; double bumpofsx;
	double bumpofsy0 = 0.0; double bumpofsy;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "ext", ext0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "metgrat", metgrat0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "mis", mis0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "schky", schky0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "hgrat", hgrat0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "vgrat", vgrat0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "gratprd", gratprd0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "gratfill", gratfill0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "mesaclr", mesaclr0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "botw", botw0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "sbot", sbot0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "ebot", ebot0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "nbot", nbot0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "wbot", wbot0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "metclr", metclr0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "ohmline", ohmline0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "ohmring", ohmring0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "olp", olp0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "sideopn", sideopn0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "opnsize", opnsize0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "topfill", topfill0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "extsize", extsize0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "extofsx", extofsx0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "extofsy", extofsy0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpd", bumpd0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpofsx", bumpofsx0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpofsy", bumpofsy0);

	// -- expand baseline
	size = size0;
	ext = ext0;
	metgrat = metgrat0;
	mis = mis0;
	schky = schky0;
	hgrat = hgrat0;
	vgrat = vgrat0;
	gratprd = gratprd0;
	gratfill = gratfill0;
	mesaclr = mesaclr0;
	botw = botw0;
	sbot = sbot0;
	ebot = ebot0;
	nbot = nbot0;
	wbot = wbot0;
	metclr = metclr0;
	ohmline = ohmline0;
	ohmring = ohmring0;
	olp = olp0;
	sideopn = sideopn0;
	opnsize = opnsize0;
	topfill = topfill0;
	extsize = extsize0;
	extofsx = extofsx0;
	extofsy = extofsy0;
	bumpd = bumpd0;
	bumpofsx = bumpofsx0;
	bumpofsy = bumpofsy0;

	dbsplnr->begin();

	vlxgdfces(dbsplnr, 0, refPlnrMDevice, size, ext, metgrat, mis, schky, mesaclr, botw, sbot, ebot, nbot, wbot, metclr, ohmline, ohmring, olp, sideopn, opnsize, topfill, extsize, extofsx, extofsy, bumpd, bumpofsx, bumpofsy, refSruMesa, refSruBotmet, refSruIns, refSruTopmet, refSruBump, vtxs, lgs, ags, fces);
	if (hgrat || vgrat) grat_vtxgdfces(dbsplnr, 0, refPlnrMDevice, size, mesaclr, hgrat, vgrat, gratprd, gratfill, botw, sbot, ebot, nbot, wbot, refSruGrat, vtxs, lgs);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		size = size0;
		ext = ext0;
		metgrat = metgrat0;
		mis = mis0;
		schky = schky0;
		hgrat = hgrat0;
		vgrat = vgrat0;
		gratprd = gratprd0;
		gratfill = gratfill0;
		mesaclr = mesaclr0;
		botw = botw0;
		sbot = sbot0;
		ebot = ebot0;
		nbot = nbot0;
		wbot = wbot0;
		metclr = metclr0;
		ohmline = ohmline0;
		ohmring = ohmring0;
		olp = olp0;
		sideopn = sideopn0;
		opnsize = opnsize0;
		topfill = topfill0;
		extsize = extsize0;
		extofsx = extofsx0;
		extofsy = extofsy0;
		bumpd = bumpd0;
		bumpofsx = bumpofsx0;
		bumpofsy = bumpofsy0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "size", size)) modpar += _SIZE;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ext", ext)) modpar += _EXT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "metgrat", metgrat)) modpar += _METGRAT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mis", mis)) modpar += _MIS;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "schky", schky)) modpar += _SCHKY;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "hgrat", hgrat)) modpar += _HGRAT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "vgrat", vgrat)) modpar += _VGRAT;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "gratprd", gratprd)) modpar += _GRATPRD;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "gratfill", gratfill)) modpar += _GRATFILL;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mesaclr", mesaclr)) modpar += _MESACLR;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "botw", botw)) modpar += _BOTW;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "sbot", sbot)) modpar += _SBOT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ebot", ebot)) modpar += _EBOT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "nbot", nbot)) modpar += _NBOT;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wbot", wbot)) modpar += _WBOT;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "metclr", metclr)) modpar += _METCLR;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ohmline", ohmline)) modpar += _OHMLINE;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ohmring", ohmring)) modpar += _OHMRING;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "olp", olp)) modpar += _OLP;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "sideopn", sideopn)) modpar += _SIDEOPN;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "opnsize", opnsize)) modpar += _OPNSIZE;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "topfill", topfill)) modpar += _TOPFILL;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "extsize", extsize)) modpar += _EXTSIZE;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "extofsx", extofsx)) modpar += _EXTOFSX;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "extofsy", extofsy)) modpar += _EXTOFSY;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "bumpd", bumpd)) modpar += _BUMPD;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "bumpofsx", bumpofsx)) modpar += _BUMPOFSX;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "bumpofsy", bumpofsy)) modpar += _BUMPOFSY;

		vtxs.clear();
		lgs.clear();
		ags.clear();
		fces.clear();

		// no check for dnoto modifications to simplify things
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		};

		if (modpar != 0) {
			vlxgdfces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, size, ext, metgrat, mis, schky, mesaclr, botw, sbot, ebot, nbot, wbot, metclr, ohmline, ohmring, olp, sideopn, opnsize, topfill, extsize, extofsx, extofsy, bumpd, bumpofsx, bumpofsy, refSruMesa, refSruBotmet, refSruIns, refSruTopmet, refSruBump, vtxs, lgs, ags, fces);
			if (hgrat || vgrat) grat_vtxgdfces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, size, mesaclr, hgrat, vgrat, gratprd, gratfill, botw, sbot, ebot, nbot, wbot, refSruGrat, vtxs, lgs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpPhotdet::vlxgdfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double size
			, const bool ext
			, const bool metgrat
			, const bool mis
			, const bool schky
			, const double mesaclr
			, const double botw
			, const bool sbot
			, const bool ebot
			, const bool nbot
			, const bool wbot
			, const double metclr
			, const bool ohmline
			, const bool ohmring
			, const double olp
			, const bool sideopn
			, const double opnsize
			, const bool topfill
			, const double extsize
			, const double extofsx
			, const double extofsy
			, const double bumpd
			, const double bumpofsx
			, const double bumpofsy
			, const ubigint refSruMesa
			, const ubigint refSruBotmet
			, const ubigint refSruIns
			, const ubigint refSruTopmet
			, const ubigint refSruBump
			, ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	vector<string> asrefs;
	vector<double> rs;

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	double x0prime, y0prime, clipw, cliph;
	bool leftohm, rightohm;
	double opnofsx, opnofsy;

	// actual size and translation due to surrounding botmet
	x0prime = 0.0; y0prime = 0.0;
	if (ebot && !wbot) {
		x0prime = -0.25*botw;
	} else if (!ebot && wbot) {
		x0prime = 0.25*botw;
	};
	if (sbot && !nbot) {
		y0prime = 0.25*botw;
	} else if (!sbot && nbot) {
		y0prime = -0.25*botw;
	};

	clipw = size; cliph = size;
	if (wbot) clipw -= 0.5*botw;
	if (ebot) clipw -= 0.5*botw;
	if (sbot) cliph -= 0.5*botw;
	if (nbot) cliph -= 0.5*botw;

	// determine Ohmic contact position
	rightohm = (sideopn && (extofsx > 0.0));
	leftohm = (sideopn && (extofsx <= 0.0));

	// determine opening center position
	opnofsx = 0.0; opnofsy = 0.0;
	if (sideopn) {
		if (rightohm) {
			opnofsx = x0prime+(0.5*clipw-mesaclr-metclr) - (olp+0.5*opnsize);
		} else {
			opnofsx = x0prime-(0.5*clipw-mesaclr-metclr) + (olp+0.5*opnsize);
		};

		if (ext && (extsize < size)) {
			opnofsy = extofsy;
		} else if (bumpd >= (0.5*size)) {
			// shift opening away from bump
			if (ohmring) {
				opnofsy = y0prime-(0.5*cliph-mesaclr-metclr-botw)+2.0*botw+olp+0.5*opnsize;
			} else {
				opnofsy = y0prime-(0.5*cliph-mesaclr-metclr)+botw+olp+0.5*opnsize;
			};
		};
	};

	// --- vertices

	// center vertex
	vsrefs.push_back("vctr"); vxs.push_back(0.0); vys.push_back(0.0);

	// - non-grating vertices

	// box
	vsrefs.push_back("v54"); vxs.push_back(-0.5*size); vys.push_back(-0.5*size);
	vsrefs.push_back("v55"); vxs.push_back(0.5*size); vys.push_back(-0.5*size);
	vsrefs.push_back("v56"); vxs.push_back(0.5*size); vys.push_back(0.5*size);
	vsrefs.push_back("v57"); vxs.push_back(-0.5*size); vys.push_back(0.5*size);

	// bottom metal clipping
	vsrefs.push_back("v1"); vxs.push_back(x0prime-0.5*clipw); vys.push_back(y0prime-0.5*cliph);
	vsrefs.push_back("v2"); vxs.push_back(x0prime+0.5*clipw); vys.push_back(y0prime-0.5*cliph);
	vsrefs.push_back("v3"); vxs.push_back(x0prime+0.5*clipw); vys.push_back(y0prime+0.5*cliph);
	vsrefs.push_back("v4"); vxs.push_back(x0prime-0.5*clipw); vys.push_back(y0prime+0.5*cliph);

	// mesa
	vsrefs.push_back("v5"); vxs.push_back(x0prime-(0.5*clipw-mesaclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr));
	vsrefs.push_back("v6"); vxs.push_back(x0prime+(0.5*clipw-mesaclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr));
	vsrefs.push_back("v7"); vxs.push_back(x0prime+(0.5*clipw-mesaclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr));
	vsrefs.push_back("v8"); vxs.push_back(x0prime-(0.5*clipw-mesaclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr));

	// Ohmic top / top metal in general
	vsrefs.push_back("v9"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
	vsrefs.push_back("v10"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
	vsrefs.push_back("v11"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));
	vsrefs.push_back("v12"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));

	// auxiliary for bottom metal on top of mesa
	if (metgrat || (!mis && !schky && leftohm)) {
		vsrefs.push_back("v13"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime-0.5*cliph);
		vsrefs.push_back("v14"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime+0.5*cliph);
	} else if (!mis && !schky && !sideopn) {
		vsrefs.push_back("v13"); vxs.push_back(-(0.5*opnsize+olp)); vys.push_back(y0prime-0.5*cliph);
		vsrefs.push_back("v14"); vxs.push_back(-(0.5*opnsize+olp)); vys.push_back(y0prime+0.5*cliph);
	} else if (!mis && !schky && rightohm) {
		vsrefs.push_back("v13"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime-0.5*cliph);
		vsrefs.push_back("v14"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(y0prime+0.5*cliph);
	};

	// bump
	vsrefs.push_back("v15"); vxs.push_back(bumpofsx); vys.push_back(bumpofsy);
	vsrefs.push_back("v16"); vxs.push_back(bumpofsx-0.5*bumpd); vys.push_back(bumpofsy);
	vsrefs.push_back("v17"); vxs.push_back(bumpofsx+0.5*bumpd); vys.push_back(bumpofsy);

	if (ext) {
		// extended pad clipping
		vsrefs.push_back("v18"); vxs.push_back(extofsx-(0.5*extsize-botw)); vys.push_back(extofsy-(0.5*extsize-botw));
		vsrefs.push_back("v19"); vxs.push_back(extofsx+(0.5*extsize-botw)); vys.push_back(extofsy-(0.5*extsize-botw));
		vsrefs.push_back("v20"); vxs.push_back(extofsx+(0.5*extsize-botw)); vys.push_back(extofsy+(0.5*extsize-botw));
		vsrefs.push_back("v21"); vxs.push_back(extofsx-(0.5*extsize-botw)); vys.push_back(extofsy+(0.5*extsize-botw));

		// extended pad metal
		vsrefs.push_back("v22"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(extofsy-(0.5*extsize-botw-metclr));
		vsrefs.push_back("v23"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(extofsy-(0.5*extsize-botw-metclr));
		vsrefs.push_back("v24"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(extofsy+(0.5*extsize-botw-metclr));
		vsrefs.push_back("v25"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(extofsy+(0.5*extsize-botw-metclr));

		// - extended pad connector
		if (mis || schky || topfill) {
			// connect to entire top metal pad

			if (size > extsize) {
				// size of extended pad relevant
				if (extofsx <= 0.0) {
					vsrefs.push_back("v27"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(extofsy-(0.5*extsize-botw-metclr));
					vsrefs.push_back("v28"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(extofsy+(0.5*extsize-botw-metclr));
				} else {
					vsrefs.push_back("v26"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(extofsy-(0.5*extsize-botw-metclr));
					vsrefs.push_back("v29"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(extofsy+(0.5*extsize-botw-metclr));
				};

			} else {
				// size of top metal relevant
				if (extofsx <= 0.0) {
					vsrefs.push_back("v26"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
					vsrefs.push_back("v29"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));
				} else {
					vsrefs.push_back("v27"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
					vsrefs.push_back("v28"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));
				};
			};

		} else {
			// connect to opening to Ohmic contact pad (sideopn is implied)
			if (extofsx <= 0.0) {
				vsrefs.push_back("v26"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(opnofsy-(0.5*opnsize+olp));
				vsrefs.push_back("v29"); vxs.push_back(extofsx+(0.5*extsize-botw-metclr)); vys.push_back(opnofsy+(0.5*opnsize+olp));
			} else {
				vsrefs.push_back("v27"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(opnofsy-(0.5*opnsize+olp));
				vsrefs.push_back("v28"); vxs.push_back(extofsx-(0.5*extsize-botw-metclr)); vys.push_back(opnofsy+(0.5*opnsize+olp));
			};
		};
	};

	if (!mis && !schky) {
		// insulation opening
		vsrefs.push_back("v30"); vxs.push_back(opnofsx-(0.5*opnsize+olp)); vys.push_back(opnofsy-(0.5*opnsize+olp));
		vsrefs.push_back("v31"); vxs.push_back(opnofsx+(0.5*opnsize+olp)); vys.push_back(opnofsy-(0.5*opnsize+olp));
		vsrefs.push_back("v32"); vxs.push_back(opnofsx+(0.5*opnsize+olp)); vys.push_back(opnofsy+(0.5*opnsize+olp));
		vsrefs.push_back("v33"); vxs.push_back(opnofsx-(0.5*opnsize+olp)); vys.push_back(opnofsy+(0.5*opnsize+olp));

		// Ohmic contact pad
		vsrefs.push_back("v34"); vxs.push_back(opnofsx-0.5*opnsize); vys.push_back(opnofsy-0.5*opnsize);
		vsrefs.push_back("v35"); vxs.push_back(opnofsx+0.5*opnsize); vys.push_back(opnofsy-0.5*opnsize);
		vsrefs.push_back("v36"); vxs.push_back(opnofsx+0.5*opnsize); vys.push_back(opnofsy+0.5*opnsize);
		vsrefs.push_back("v37"); vxs.push_back(opnofsx-0.5*opnsize); vys.push_back(opnofsy+0.5*opnsize);

		// ohmline and ohmring
		if ((ohmline && leftohm) || ohmring) {
			vsrefs.push_back("v38"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
			vsrefs.push_back("v43"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));
		};

		if ((ohmline && rightohm) || ohmring) {
			vsrefs.push_back("v44"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr));
			vsrefs.push_back("v49"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr));
		};

		if ((ohmline || ohmring) && leftohm) {
			vsrefs.push_back("v39"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(opnofsy-(0.5*opnsize+olp));
			vsrefs.push_back("v40"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(opnofsy-(0.5*opnsize+olp));
			vsrefs.push_back("v41"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr)); vys.push_back(opnofsy+(0.5*opnsize+olp));
			vsrefs.push_back("v42"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(opnofsy+(0.5*opnsize+olp));
		};

		if ((ohmline || ohmring) && rightohm) {
			vsrefs.push_back("v45"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(opnofsy-(0.5*opnsize+olp));
			vsrefs.push_back("v46"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(opnofsy-(0.5*opnsize+olp));
			vsrefs.push_back("v47"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(opnofsy+(0.5*opnsize+olp));
			vsrefs.push_back("v48"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr)); vys.push_back(opnofsy+(0.5*opnsize+olp));
		};

		if (ohmring) {
			vsrefs.push_back("v50"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr-botw));
			vsrefs.push_back("v51"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime-(0.5*cliph-mesaclr-metclr-botw));
			vsrefs.push_back("v52"); vxs.push_back(x0prime-(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr-botw));
			vsrefs.push_back("v53"); vxs.push_back(x0prime+(0.5*clipw-mesaclr-metclr-botw)); vys.push_back(y0prime+(0.5*cliph-mesaclr-metclr-botw));
		};
	};

	addVertices(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	// --- line guides
	lsrefs.push_back("l0");
	if (mis || schky) vsrefsstrs.push_back("v4;v3"); else vsrefsstrs.push_back("v4;v14;v3");

	lsrefs.push_back("l1"); vsrefsstrs.push_back("v8;v7");

	lsrefs.push_back("l2");
	if (ohmring) {
		vsrefsstrs.push_back("v12;v43;v49;v11");
	} else if (ohmline) {
		if (leftohm) vsrefsstrs.push_back("v12;v43;v11"); else vsrefsstrs.push_back("v12;v49;v11");
	} else {
		vsrefsstrs.push_back("v12;v11");
	};

	if (ohmring) {
		lsrefs.push_back("l3");
		vsrefsstrs.push_back("v52;v53");
	};

	if (leftohm && (ohmline || ohmring)) {
		lsrefs.push_back("l4");
		vsrefsstrs.push_back("v33;v42");
		lsrefs.push_back("l5");
		vsrefsstrs.push_back("v30;v39");
	};

	if (rightohm && (ohmline || ohmring)) {
		lsrefs.push_back("l6");
		vsrefsstrs.push_back("v47;v32");
		lsrefs.push_back("l7");
		vsrefsstrs.push_back("v46;v31");
	};

	if (ohmring) {
		lsrefs.push_back("l8");
		vsrefsstrs.push_back("v51;v50");
	};

	lsrefs.push_back("l9");
	if (ohmring) {
		vsrefsstrs.push_back("v9;v38;v44;v10");
	} else if (ohmline) {
		if (leftohm) vsrefsstrs.push_back("v9;v38;v10"); else vsrefsstrs.push_back("v9;v44;v10");
	} else {
		vsrefsstrs.push_back("v9;v10");
	};

	lsrefs.push_back("l10"); vsrefsstrs.push_back("v5;v6");

	lsrefs.push_back("l11");
	if (mis || schky) vsrefsstrs.push_back("v1;v2"); else vsrefsstrs.push_back("v1;v13;v2");

	lsrefs.push_back("l12"); vsrefsstrs.push_back("v4;v1");
	lsrefs.push_back("l13"); vsrefsstrs.push_back("v8;v5");

	lsrefs.push_back("l14");
	if (leftohm) {
		vsrefsstrs.push_back("v14;v12;v33;v30;v9;v13");
	} else {
		vsrefsstrs.push_back("v12;v9");
	};

	if (ohmring) {
		if (leftohm) {
			lsrefs.push_back("l15"); vsrefsstrs.push_back("v43;v52;v42;v39;v51;v38");
		} else {
			lsrefs.push_back("l15"); vsrefsstrs.push_back("v43;v52;v51;v38");
		};
	} else if (ohmline && leftohm) {
		lsrefs.push_back("l15"); vsrefsstrs.push_back("v43;v42;v39;v38");
	};

	if (ohmring) {
		if (leftohm) {
			lsrefs.push_back("l16"); vsrefsstrs.push_back("v49;v53;v50;v44");
		} else {
			lsrefs.push_back("l16"); vsrefsstrs.push_back("v49;v53;v47;v46;v50;v44");
		};
	} else if (ohmline && rightohm) {
		lsrefs.push_back("l16"); vsrefsstrs.push_back("v49;v47;v46;v44");
	};

	lsrefs.push_back("l17");
	if (rightohm) {
		vsrefsstrs.push_back("v11;v32;v31;v10");
	} else {
		vsrefsstrs.push_back("v11;v10");
	};

	lsrefs.push_back("l18"); vsrefsstrs.push_back("v7;v6");
	lsrefs.push_back("l19"); vsrefsstrs.push_back("v3;v2");

	if (ext) {
		lsrefs.push_back("l20"); vsrefsstrs.push_back("v21;v20");
		lsrefs.push_back("l21"); vsrefsstrs.push_back("v25;v24");
		lsrefs.push_back("l22"); vsrefsstrs.push_back("v22;v23");
		lsrefs.push_back("l23"); vsrefsstrs.push_back("v18;v19");
		lsrefs.push_back("l24"); vsrefsstrs.push_back("v21;v18");

		lsrefs.push_back("l25");
		if ( (extofsx > 0.0) && ( (!topfill && !mis && !schky) || ((topfill || mis || schky) && (size > extsize))) ) {
			vsrefsstrs.push_back("v25;v28;v27;v22");
		} else {
			vsrefsstrs.push_back("v25;v22");
		};

		lsrefs.push_back("l26");
		if ( (extofsx <= 0.0) && ( (!topfill && !mis && !schky) || ((topfill || mis || schky) && (size > extsize))) ) {
			vsrefsstrs.push_back("v24;v29;v26;v23");
		} else {
			vsrefsstrs.push_back("v24;v23");
		};

		lsrefs.push_back("l27"); vsrefsstrs.push_back("v20;v19");

		lsrefs.push_back("l28");
		lsrefs.push_back("l29");
		if (extofsx <= 0.0) {
			// left
			if (topfill || mis || schky) {
				// connect to top metal pad
				if (size > extsize) {
					vsrefsstrs.push_back("v24;v28");
					vsrefsstrs.push_back("v23;v27");
				} else {
					vsrefsstrs.push_back("v29;v12");
					vsrefsstrs.push_back("v26;v9");
				};

			} else {
				// connect to Ohmic contact pad
				vsrefsstrs.push_back("v29;v33");
				vsrefsstrs.push_back("v26;v30");
			};

		} else {
			// right
			if (topfill || mis || schky) {
				// connect to top metal pad
				if (size > extsize) {
					vsrefsstrs.push_back("v29;v25");
					vsrefsstrs.push_back("v26;v22");
				} else {
					vsrefsstrs.push_back("v11;v28");
					vsrefsstrs.push_back("v10;v27");
				};

			} else {
				// connect to Ohmic contact pad
				vsrefsstrs.push_back("v32;v28");
				vsrefsstrs.push_back("v31;v27");
			};
		};
	};

	if (!mis && !schky) {
		lsrefs.push_back("l30");
		if (leftohm) {
			vsrefsstrs.push_back("v33;v42;v32");
		} else if (rightohm) {
			vsrefsstrs.push_back("v33;v47;v32");
		} else {
			vsrefsstrs.push_back("v33;v32");
		};

		lsrefs.push_back("l31"); vsrefsstrs.push_back("v37;v36");
		lsrefs.push_back("l32"); vsrefsstrs.push_back("v34;v35");

		lsrefs.push_back("l33");
		if (leftohm) {
			vsrefsstrs.push_back("v30;v39;v31");
		} else if (rightohm) {
			vsrefsstrs.push_back("v30;v46;v31");
		} else {
			vsrefsstrs.push_back("v30;v31");
		};

		if (sideopn) {
			lsrefs.push_back("l34"); vsrefsstrs.push_back("v33;v30");
		} else {
			lsrefs.push_back("l34"); vsrefsstrs.push_back("v14;v33;v30;v13");
		};

		lsrefs.push_back("l35"); vsrefsstrs.push_back("v37;v34");
		lsrefs.push_back("l36"); vsrefsstrs.push_back("v36;v35");
		lsrefs.push_back("l37"); vsrefsstrs.push_back("v32;v31");
	};

	addLineguides(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);

	// --- arc guides
	vsrefs.resize(0);
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v15"); rs.push_back(0.5*bumpd); vsrefsstrs.push_back("v16;v17;v16");

	addArcguides(dbsplnr, x1RefPlnrMDesign, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);

	// --- faces
	vsrefsstrs.resize(0);

	// - mesa
	strrefs.push_back(refSruMesa);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("v5; v6; v7; v8");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l10;l18;l1; l13");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	// - grating generated separately

	// - bottom metallization
	if (mis || schky) {
		strrefs.push_back(refSruBotmet);
		fsrefs.push_back("f1");
		vsrefsstrs.push_back("v1; v2; v3; v4");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l11;l19;l0; l12");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	} else if (metgrat) {
			strrefs.push_back(refSruBotmet);
			fsrefs.push_back("f2");
			vsrefsstrs.push_back("v1; v13;v14;v4");
			rtesstrs.push_back	("lgd;lgd;lgd;lgd");
			gsrefsstrs.push_back("l11;l14;l0; l12");
			dirsstrs.push_back	("fwd;bwd;bwd;fwd");

			strrefs.push_back(refSruBotmet);
			fsrefs.push_back("f3");
			vsrefsstrs.push_back("v13;v2; v3; v14;v12;v11;v10;v9");
			rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
			gsrefsstrs.push_back("l11;l19;l0; l14;l2; l17;l9; l14");
			dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");

	} else {
		if (ohmring) {
			if (leftohm) {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v1; v13;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l14;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v13;v2; v3; v14;v12;v11;v10;v9");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l14;l2; l17;l9; l14");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f4");
				vsrefsstrs.push_back("v51;v50;v53;v52;v42;v32;v31;v39");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l8; l16;l3; l15;l30;l37;l33;l15");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");

			} else {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v13;v2; v3; v14");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l17");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v1; v13;v10;v9; v12;v11;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l17;l9; l14;l2; l17;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;bwd;fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f4");
				vsrefsstrs.push_back("v51;v50;v46;v30;v33;v47;v53;v52");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l8; l16;l33;l34;l30;l16;l3; l15");
				dirsstrs.push_back	("fwd;bwd;bwd;bwd;fwd;bwd;bwd;fwd");
			};

		} else if (ohmline) {
			if (leftohm) {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v1; v13;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l14;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v13;v2; v3; v14;v12;v43;v42;v32;v31;v39;v38;v9");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l14;l2; l15;l30;l37;l33;l15;l9;l14");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;fwd;fwd;bwd;fwd;bwd;fwd");

			} else {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v13;v2; v3; v14");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l17");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v1; v13;v10;v44;v46;v30;v33;v47;v49;v11;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l17;l9; l16;l33;l34;l30;l16;l2; l17;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;bwd;fwd;bwd;fwd;bwd;bwd;fwd");
			};

		} else {
			if (leftohm) {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v1; v13;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l14;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v13;v2; v3; v14;v33;v32;v31;v30");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l14;l30;l37;l33;l14");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");

			} else if (rightohm) {
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v13;v2; v3; v14");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l17");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v1; v13;v31;v30;v33;v32;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l17;l33;l34;l30;l17;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;bwd;fwd;bwd;bwd;fwd");

			} else {
				// not a side contact
				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f2");
				vsrefsstrs.push_back("v1; v13;v14;v4");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l34;l0; l12");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd");

				strrefs.push_back(refSruBotmet);
				fsrefs.push_back("f3");
				vsrefsstrs.push_back("v13;v2; v3; v14;v33;v32;v31;v30");
				rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
				gsrefsstrs.push_back("l11;l19;l0; l34;l30;l37;l33;l34");
				dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");
			};
		};
	};

	if (ext) {
		strrefs.push_back(refSruBotmet);
		fsrefs.push_back("f5");
		vsrefsstrs.push_back("v18;v19;v20;v21");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l23;l27;l20;l24");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	// - insulation
	if (schky) {
		strrefs.push_back(refSruIns);
		fsrefs.push_back("f6");
		vsrefsstrs.push_back("v9; v10;v11;v12");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l9; l17;l2; l14");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	} else if (!mis) {
		strrefs.push_back(refSruIns);
		fsrefs.push_back("f6");
		vsrefsstrs.push_back("v34;v35;v36;v37");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l32;l36;l31;l35");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	// - topmet
	strrefs.push_back(refSruTopmet);
	fsrefs.push_back("f7");
	if (mis || schky || topfill) {
		vsrefsstrs.push_back("v9; v10;v11;v12");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l9; l17;l2; l14");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	} else {
		vsrefsstrs.push_back("v30;v31;v32;v33");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l33;l37;l30;l34");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	if (ext) {
		strrefs.push_back(refSruTopmet);
		fsrefs.push_back("f8");
		vsrefsstrs.push_back("v22;v23;v24;v25");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l22;l26;l21;l25");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");

		strrefs.push_back(refSruTopmet);
		fsrefs.push_back("f9");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");

		if (extofsx <= 0.0) {
			// left
			if (mis || schky || topfill) {
				if (size > extsize) {
					vsrefsstrs.push_back("v23;v27;v28;v24");
					gsrefsstrs.push_back("l29;l14;l28;l26");
				} else {
					vsrefsstrs.push_back("v26;v9; v12;v29");
					gsrefsstrs.push_back("l29;l14;l28;l26");
				};
			} else {
				vsrefsstrs.push_back("v26;v30;v33;v29");
				gsrefsstrs.push_back("l29;l14;l28;l26");
			};

		} else {
			// right
			if (mis || schky || topfill) {
				if (size > extsize) {
					vsrefsstrs.push_back("v26;v22;v25;v29");
					gsrefsstrs.push_back("l29;l25;l28;l37");
				} else {
					vsrefsstrs.push_back("v10;v27;v28;v11");
					gsrefsstrs.push_back("l29;l25;l28;l17");
				};
			} else {
				vsrefsstrs.push_back("v31;v27;v28;v32");
				gsrefsstrs.push_back("l29;l25;l28;l17");
			};
		};
	};

	// - bump
	strrefs.push_back(refSruBump);
	fsrefs.push_back("f10");
	vsrefsstrs.push_back("v16;v17");
	rtesstrs.push_back	("agd;agd");
	gsrefsstrs.push_back("a0; a0");
	dirsstrs.push_back	("fwd;fwd");

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};

void PlnrExpPhotdet::grat_vtxgdfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double size
			, const double mesaclr
			, const bool hgrat
			, const bool vgrat
			, const double gratprd
			, const double gratfill
			, const double botw
			, const bool sbot
			, const bool ebot
			, const bool nbot
			, const bool wbot
			, const ubigint refSruGrat
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
		) {
	ostringstream str;

	PlnrMVertex vtx;

	PlnrMLineguide lg;
	PlnrLRMLineguideMVertex lrv;
	
	PlnrMFace fce;
	PlnrRMFaceMVertex frv;

	vector<ubigint> refsVtx;
	vector<ubigint> refsLg;
	vector<ubigint> refsLgh;
	vector<ubigint> refsLgv;

	ubigint refLg1, refLg10, refLg13, refLg18;
	ubigint refVtx5, refVtx6, refVtx7;

	int M, N, mmin, mmax, nmin, nmax;
	double x0, y0, x0prime, y0prime, w, h;

	// -- initialization

	// vtx: sref, x and y vary
	vtx.x1RefPlnrMDesign = x1RefPlnrMDesign;
	vtx.hkIxPlnrVLat = VecPlnrVLat::INI;
	vtx.hkIxVTbl = VecPlnrVMVertexHkTbl::DEV;
	vtx.hkUref = refPlnrMDevice;

	// lg: sref varies
	lg.x1RefPlnrMDesign = x1RefPlnrMDesign;
	lg.hkIxPlnrVLat = VecPlnrVLat::INI;
	lg.hkIxVTbl = VecPlnrVMLineguideHkTbl::DEV;
	lg.hkUref = refPlnrMDevice;

	// lrv: lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex vary
	lrv.lgdIxPlnrVLat = VecPlnrVLat::INI;

	// fce: sref vary
	fce.x1RefPlnrMDesign = x1RefPlnrMDesign;
	fce.devRefPlnrMFace = 0;
	fce.sruIxPlnrVLat = VecPlnrVLat::INI;
	fce.sruRefPlnrMStructure = refSruGrat;

	// frv: all but rteIxVTbl vary
	frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;

	// - find boundary line guides and the respective final vertices
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		if (lgs.nodes[i]->sref.compare("l1") == 0) {
			refLg1 = lgs.nodes[i]->ref;
			break;
		};
	};
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		if (lgs.nodes[i]->sref.compare("l10") == 0) {
			refLg10 = lgs.nodes[i]->ref;
			break;
		};
	};
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		if (lgs.nodes[i]->sref.compare("l13") == 0) {
			refLg13 = lgs.nodes[i]->ref;
			break;
		};
	};
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		if (lgs.nodes[i]->sref.compare("l18") == 0) {
			refLg18 = lgs.nodes[i]->ref;
			break;
		};
	};

	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		if (vtxs.nodes[i]->sref.compare("v5") == 0) {
			refVtx5 = vtxs.nodes[i]->ref;
			break;
		};
	};
	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		if (vtxs.nodes[i]->sref.compare("v6") == 0) {
			refVtx6 = vtxs.nodes[i]->ref;
			break;
		};
	};
	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		if (vtxs.nodes[i]->sref.compare("v7") == 0) {
			refVtx7 = vtxs.nodes[i]->ref;
			break;
		};
	};

	// - determine grating x,y offset and max. number of elements in both directions
	x0prime = 0.0; y0prime = 0.0;
	if (ebot && !wbot) {
		x0prime = -0.25*botw;
	} else if (!ebot && wbot) {
		x0prime = 0.25*botw;
	};
	if (sbot && !nbot) {
		y0prime = 0.25*botw;
	} else if (!sbot && nbot) {
		y0prime = -0.25*botw;
	};

	w = size - 2.0*mesaclr; h = size - 2.0*mesaclr;
	if (wbot) w -= 0.5*botw;
	if (ebot) w -= 0.5*botw;
	if (sbot) h -= 0.5*botw;
	if (nbot) h -= 0.5*botw;

	M = lround(floor(h/gratprd));
	N = lround(floor(w/gratprd));

	getminmax(M, mmin, mmax);
	getminmax(N, nmin, nmax);

	if (hgrat && !vgrat) {
		// -- horizontal line grating

		// - vertices
		for (int i=mmin;i<=mmax;i++) {
			y0 = y0prime + ((double) i)*gratprd;
			if ((M%2) == 0) y0 -= 0.5*gratprd;

			str.str(""); str << "vm" << intToPnstr(i) << "_a";
			vtx.x = x0prime-0.5*w; vtx.y = y0-0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vm" << intToPnstr(i) << "_b";
			vtx.x = x0prime+0.5*w; vtx.y = y0-0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vm" << intToPnstr(i) << "_c";
			vtx.x = x0prime+0.5*w; vtx.y = y0+0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vm" << intToPnstr(i) << "_d";
			vtx.x = x0prime-0.5*w; vtx.y = y0+0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);
		};

		// - horizontal line guides
		for (int i=mmin;i<=mmax;i++) {
			str.str(""); str << "lha" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLg.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;
			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+1];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lhb" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLg.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;
			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+3];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+2];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - vertex incorporation in vertical line guides l13 and l18
		lrv.lgdRefPlnrMLineguide = refLg13;
		for (int i=mmin;i<=mmax;i++) {
			lrv.lgdNum = 2+2*(i-mmin);
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+3];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2+2*(i-mmin)+1;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		lrv.lgdRefPlnrMLineguide = refLg18;
		for (int i=mmin;i<=mmax;i++) {
			lrv.lgdNum = 2+2*(i-mmin);
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+2];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2+2*(i-mmin)+1;
			lrv.refPlnrMVertex = refsVtx[4*(i-mmin)+1];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - v5 and v6 as last vertices on l13 and l18, respectively
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = " + to_string(2+2*(mmax-mmin+1)) + " WHERE lgdRefPlnrMLineguide = " + to_string(refLg13) + " AND refPlnrMVertex = " + to_string(refVtx5));
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = " + to_string(2+2*(mmax-mmin+1)) + " WHERE lgdRefPlnrMLineguide = " + to_string(refLg18) + " AND refPlnrMVertex = " + to_string(refVtx6));

		// - faces
		for (int i=mmin;i<=mmax;i++) {
			str.str(""); str << "fm" << intToPnstr(i);
			fce.sref = str.str();
			dbsplnr->tblplnrmface->insertRec(&fce);

			frv.fceRefPlnrMFace = fce.ref;

			frv.fceNum = 1;
			frv.refPlnrMVertex = refsVtx[4*(i-mmin)];
			frv.rteUref = refsLg[2*(i-mmin)];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 2;
			frv.refPlnrMVertex = refsVtx[4*(i-mmin)+1];
			frv.rteUref = refLg18;
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 3;
			frv.refPlnrMVertex = refsVtx[4*(i-mmin)+2];
			frv.rteUref = refsLg[2*(i-mmin)+1];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 4;
			frv.refPlnrMVertex = refsVtx[4*(i-mmin)+3];
			frv.rteUref = refLg13;
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
		};

	} else if (!hgrat && vgrat) {
		// -- vertical line grating

		// - vertices
		for (int i=nmin;i<=nmax;i++) {
			x0 = x0prime + ((double) i)*gratprd;
			if ((N%2) == 0) x0 -= 0.5*gratprd;

			str.str(""); str << "vn" << intToPnstr(i) << "_a";
			vtx.x = x0-0.5*gratprd*(1.0-gratfill); vtx.y = y0prime-0.5*h; vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vn" << intToPnstr(i) << "_b";
			vtx.x = x0+0.5*gratprd*(1.0-gratfill); vtx.y = y0prime-0.5*h; vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vn" << intToPnstr(i) << "_c";
			vtx.x = x0+0.5*gratprd*(1.0-gratfill); vtx.y = y0prime+0.5*h; vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);

			str.str(""); str << "vn" << intToPnstr(i) << "_d";
			vtx.x = x0-0.5*gratprd*(1.0-gratfill); vtx.y = y0prime+0.5*h; vtx.sref = str.str();
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx.push_back(vtx.ref);
		};

		// - vertical line guides
		for (int i=nmin;i<=nmax;i++) {
			str.str(""); str << "lva" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLg.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;
			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+3];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lvb" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLg.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;
			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+2];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+1];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - vertex incorporation in horizontal line guides l1 and l10
		lrv.lgdRefPlnrMLineguide = refLg1;
		for (int i=nmin;i<=nmax;i++) {
			lrv.lgdNum = 2+2*(i-nmin);
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+3];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2+2*(i-nmin)+1;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+2];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		lrv.lgdRefPlnrMLineguide = refLg10;
		for (int i=nmin;i<=nmax;i++) {
			lrv.lgdNum = 2+2*(i-nmin);
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2+2*(i-nmin)+1;
			lrv.refPlnrMVertex = refsVtx[4*(i-nmin)+1];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - v7 and v6 as last vertices on l1 and l10
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = " + to_string(2+2*(nmax-nmin+1)) + " WHERE lgdRefPlnrMLineguide = " + to_string(refLg1) + " AND refPlnrMVertex = " + to_string(refVtx7));
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = " + to_string(2+2*(nmax-nmin+1)) + " WHERE lgdRefPlnrMLineguide = " + to_string(refLg10) + " AND refPlnrMVertex = " + to_string(refVtx6));

		// - faces
		for (int i=nmin;i<=nmax;i++) {
			str.str(""); str << "fn" << intToPnstr(i);
			fce.sref = str.str();
			dbsplnr->tblplnrmface->insertRec(&fce);

			frv.fceRefPlnrMFace = fce.ref;

			frv.fceNum = 1;
			frv.refPlnrMVertex = refsVtx[4*(i-nmin)];
			frv.rteUref = refLg10;
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 2;
			frv.refPlnrMVertex = refsVtx[4*(i-nmin)+1];
			frv.rteUref = refsLg[2*(i-nmin)+1];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 3;
			frv.refPlnrMVertex = refsVtx[4*(i-nmin)+2];
			frv.rteUref = refLg1;
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 4;
			frv.refPlnrMVertex = refsVtx[4*(i-nmin)+3];
			frv.rteUref = refsLg[2*(i-nmin)];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
		};

	} else {
		// -- pit grating (raster)

		// - vertices
		for (int i=mmin;i<=mmax;i++) {
			y0 = y0prime + ((double) i)*gratprd;
			if ((M%2) == 0) y0 -= 0.5*gratprd;

			for (int j=nmin;j<=nmax;j++) {
				x0 = x0prime + ((double) j)*gratprd;
				if ((N%2) == 0) x0 -= 0.5*gratprd;

				str.str(""); str << "vm" << intToPnstr(i) << "_n" << intToPnstr(j) << "_a";
				vtx.x = x0-0.5*gratprd*(1.0-gratfill); vtx.y = y0-0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refsVtx.push_back(vtx.ref);

				str.str(""); str << "vm" << intToPnstr(i) << "_n" << intToPnstr(j) << "_b";
				vtx.x = x0+0.5*gratprd*(1.0-gratfill); vtx.y = y0-0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refsVtx.push_back(vtx.ref);

				str.str(""); str << "vm" << intToPnstr(i) << "_n" << intToPnstr(j) << "_c";
				vtx.x = x0+0.5*gratprd*(1.0-gratfill); vtx.y = y0+0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refsVtx.push_back(vtx.ref);

				str.str(""); str << "vm" << intToPnstr(i) << "_n" << intToPnstr(j) << "_d";
				vtx.x = x0-0.5*gratprd*(1.0-gratfill); vtx.y = y0+0.5*gratprd*(1.0-gratfill); vtx.sref = str.str();
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refsVtx.push_back(vtx.ref);
			};
		};

		// - horizontal and vertical line guides
		for (int i=mmin;i<=mmax;i++) {
			str.str(""); str << "lha" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLgh.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			for (int j=nmin;j<=nmax;j++) {
				lrv.lgdNum = 2*(j-nmin)+1;
				lrv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2*(j-nmin)+2;
				lrv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+1];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			};

			str.str(""); str << "lhb" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLgh.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			for (int j=nmin;j<=nmax;j++) {
				lrv.lgdNum = 2*(j-nmin)+1;
				lrv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+3];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2*(j-nmin)+2;
				lrv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+2];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			};
		};

		for (int i=nmin;i<=nmax;i++) {
			str.str(""); str << "lva" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLgv.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			for (int j=mmin;j<=mmax;j++) {
				lrv.lgdNum = 2*(mmax-j)+1;
				lrv.refPlnrMVertex = refsVtx[4*((j-mmin)*N+(i-nmin))+3];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2*(mmax-j)+2;
				lrv.refPlnrMVertex = refsVtx[4*((j-mmin)*N+(i-nmin))];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			};

			str.str(""); str << "lvb" << intToPnstr(i);
			lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg);
			refsLgv.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			for (int j=mmin;j<=mmax;j++) {
				lrv.lgdNum = 2*(mmax-j)+1;
				lrv.refPlnrMVertex = refsVtx[4*((j-mmin)*N+(i-nmin))+2];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2*(mmax-j)+2;
				lrv.refPlnrMVertex = refsVtx[4*((j-mmin)*N+(i-nmin))+1];
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			};
		};

		// - faces
		for (int i=mmin;i<=mmax;i++) {
			for (int j=nmin;j<=nmax;j++) {
				str.str(""); str << "fm" << intToPnstr(i) << "_n" << intToPnstr(j);
				fce.sref = str.str();
				dbsplnr->tblplnrmface->insertRec(&fce);

				frv.fceRefPlnrMFace = fce.ref;

				frv.fceNum = 1;
				frv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))];
				frv.rteUref = refsLgh[2*(i-mmin)];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 2;
				frv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+1];
				frv.rteUref = refsLgv[2*(j-nmin)+1];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 3;
				frv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+2];
				frv.rteUref = refsLgh[2*(i-mmin)+1];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4;
				frv.refPlnrMVertex = refsVtx[4*((i-mmin)*N+(j-nmin))+3];
				frv.rteUref = refsLgv[2*(j-nmin)];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
			};
		};
	};
};

void PlnrExpPhotdet::getminmax(
			const int N
			, int& nmin
			, int& nmax
		) {
	if ((N%2) == 0) {
		// n even
		nmin = -N/2 +1;
		nmax = N/2;
	} else {
		// n odd
		nmin = -(N+1)/2 +1;
		nmax = (N+1)/2 -1;
	};
};
// IP cust --- IEND


