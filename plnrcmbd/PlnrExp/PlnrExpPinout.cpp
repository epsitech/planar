/**
  * \file PlnrExpPinout.cpp
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

#include "PlnrExpPinout.h"

DpchRetPlnr* PlnrExpPinout::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPinout* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruBotmet = 0;
	ubigint refSruIns = 0;
	ubigint refSruTopmet = 0;
	ubigint refSruBump = 0;

	ubigint refTpl;

	vector<ubigint> refsSubdevPiopin;
	vector<ubigint> refsSubdevPiopad;
	ubigint refSubdev;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "botmet", refSruBotmet);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "ins", refSruIns);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "topmet", refSruTopmet);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "bump", refSruBump);

	// load piopin sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "piopin", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPiopin);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'piopin'", true, refsSubdevPiopin);

	// load piopad sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "piopad", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPiopad);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'piopad'", true, refsSubdevPiopad);

	// load baseline parameters
	double rast0 = 100.0; double rast;
	string cellstop0 = "AF32"; string cellstop;
	int ratio0 = 2; int ratio;
	double framew0 = 100.0; double framew;
	bool padfill0 = false; bool padfill;
	double bumpd0 = 50.0; double bumpd;
	double wbclr0 = 5.0; double wbclr;
	double wbolp0 = 5.0; double wbolp;
	double cellclr0 = 5.0; double cellclr;
	double cellolp0 = 5.0; double cellolp;

	int piopin_wb;
	string piopin_cell;
	bool piopin_keepoff;

	string piopad_cell;

	double xofs, yofs;
	int mmax, nmax;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "rast", rast0);
	loadStringDevpar(dbsplnr, refPlnrMDevice, 0, "cellstop", cellstop0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "ratio", ratio0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "framew", framew0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "padfill", padfill0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpd", bumpd0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "wbclr", wbclr0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "wbolp", wbolp0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cellclr", cellclr0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cellolp", cellolp0);

	// -- expand baseline
	rast = rast0;
	cellstop = cellstop0;
	ratio = ratio0;
	framew = framew0;
	padfill = padfill0;
	bumpd = bumpd0;
	wbclr = wbclr0;
	wbolp = wbolp0;
	cellclr = cellclr0;
	cellolp = cellolp0;

	dbsplnr->begin();

	// determine number of rows/cols
	Plnr::cellstopToXyofs(rast, cellstop, xofs, yofs);
	Plnr::crefToMn(cellstop, mmax, nmax);

	vtxgdfces(dbsplnr, 0, refPlnrMDevice, xofs, yofs, mmax, nmax, rast, ratio, framew, padfill, bumpd, wbclr, wbolp, cellclr, cellolp, refSruBotmet, refSruIns, refSruTopmet, refSruBump);

	dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, false, vtxs);
	dbsplnr->tblplnrmlineguide->loadRstByDsnHktHku(0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, false, lgs);
	dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, false, ags);

	dbsplnr->tblplnrmface->loadRstByDsnSru(0, refSruBotmet, false, fces);
	dbsplnr->tblplnrmface->loadRstByDsnSru(0, refSruIns, true, fces);
	dbsplnr->tblplnrmface->loadRstByDsnSru(0, refSruTopmet, true, fces);
	dbsplnr->tblplnrmface->loadRstByDsnSru(0, refSruBump, true, fces);

	// sub-devices
	for (unsigned int i=0;i<refsSubdevPiopin.size();i++) {
		refSubdev = refsSubdevPiopin[i];

		piopin_loadpars(dbsplnr, refSubdev, 0, piopin_wb, piopin_cell, piopin_keepoff);
		piopin_gdfces(dbsplnr, 0, refPlnrMDevice, refSubdev, mmax, nmax, ratio, piopin_wb, piopin_cell, piopin_keepoff, refSruBotmet, vtxs, lgs, fces);
	};

	for (unsigned int i=0;i<refsSubdevPiopad.size();i++) {
		refSubdev = refsSubdevPiopad[i];

		piopad_loadpars(dbsplnr, refSubdev, 0, piopad_cell);
		piopad_fces(dbsplnr, 0, refPlnrMDevice, refSubdev, padfill, piopad_cell, refSruIns, refSruTopmet, refSruBump, vtxs, lgs, ags, fces);
	};

	dbsplnr->commit();

	// --- expand for modified designs
	// ...
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpPinout::vtxgdfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double xofs
			, const double yofs
			, const int mmax
			, const int nmax
			, const double rast
			, const int ratio
			, const double framew
			, const bool padfill
			, const double bumpd
			, const double wbclr
			, const double wbolp
			, const double cellclr
			, const double cellolp
			, const ubigint refSruBotmet
			, const ubigint refSruIns
			, const ubigint refSruTopmet
			, const ubigint refSruBump
		) {
	// to deal with the large number of elements, non-standard expansion methods are employed

	ostringstream str;

	PlnrMVertex vtx;

	PlnrMLineguide lg;
	PlnrLRMLineguideMVertex lrv;

	PlnrMArcguide ag;
	PlnrLRMArcguideMVertex arv;
	
	PlnrMFace fce;
	PlnrRMFaceMVertex frv;

	vector<ubigint> refsVtx0;
	vector<ubigint> refsVtx1;
	vector<ubigint> refsVtx2;

	vector<ubigint> refsVtxa;
	vector<ubigint> refsVtxb;
	vector<ubigint> refsVtxc;
	vector<ubigint> refsVtxd;

	vector<ubigint> refsVtxe;
	vector<ubigint> refsVtxf;
	vector<ubigint> refsVtxg;
	vector<ubigint> refsVtxh;

	vector<ubigint> refsVtxpa;
	vector<ubigint> refsVtxpb;
	vector<ubigint> refsVtxpc;
	vector<ubigint> refsVtxpd;

	vector<ubigint> refsVtxpe;
	vector<ubigint> refsVtxpf;
	vector<ubigint> refsVtxpg;
	vector<ubigint> refsVtxph;

	vector<ubigint> refsLgha;
	vector<ubigint> refsLghb;
	vector<ubigint> refsLghc;
	vector<ubigint> refsLghd;

	vector<ubigint> refsLgva;
	vector<ubigint> refsLgvb;
	vector<ubigint> refsLgvc;
	vector<ubigint> refsLgvd;

	vector<ubigint> refsLgpa;
	vector<ubigint> refsLgpb;
	vector<ubigint> refsLgpc;
	vector<ubigint> refsLgpd;

	vector<ubigint> refsAg;

	ubigint refLgvwa, refLgvwb, refLgvwc, refLgvwd;
	ubigint refLgvea, refLgveb, refLgvec, refLgved;
	ubigint refLghsa, refLghsb, refLghsc, refLghsd;
	ubigint refLghna, refLghnb, refLghnc, refLghnd;

	double x0, y0;

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

	// ag: sref, ctrRefPlnrMVertex vary
	ag.x1RefPlnrMDesign = x1RefPlnrMDesign;
	ag.devRefPlnrMArcguide = 0;
	ag.hkIxPlnrVLat = VecPlnrVLat::INI;
	ag.hkIxVTbl = VecPlnrVMLineguideHkTbl::DEV;
	ag.hkUref = refPlnrMDevice;
	ag.r = 0.5*bumpd;

	// arv: agdRefPlnrMArcguide, agdNum, refPlnrMVertex vary
	arv.agdIxPlnrVLat = VecPlnrVLat::INI;

	// fce: sref, sruRefPlnrMStructure vary
	fce.x1RefPlnrMDesign = x1RefPlnrMDesign;
	fce.devRefPlnrMFace = 0;
	fce.sruIxPlnrVLat = VecPlnrVLat::INI;

	// frv: all vary

	vtx.sref = "vctr";
	vtx.x = 0.0;
	vtx.y = 0.0;
	dbsplnr->tblplnrmvertex->insertRec(&vtx);

	// -- cell array elements

	// - cell array vertices
	for (int i=0;i<=mmax;i++) {
		y0 = yofs + ((double) i)*rast;

		for (int j=0;j<=nmax;j++) {
			x0 = xofs + ((double) j)*rast;

			str.str(""); str << "vm" << i << "_n" << j << "_0";
			vtx.sref = str.str(); vtx.x = x0; vtx.y = y0;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx0.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_1";
			vtx.sref = str.str(); vtx.x = x0+0.5*bumpd; vtx.y = y0;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx1.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_2";
			vtx.sref = str.str(); vtx.x = x0-0.5*bumpd; vtx.y = y0;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtx2.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_a";
			vtx.sref = str.str(); vtx.x = x0 - (0.5*rast-cellclr); vtx.y = y0 - (0.5*rast-cellclr);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxa.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_b";
			vtx.sref = str.str(); vtx.x = x0 + (0.5*rast-cellclr); vtx.y = y0 - (0.5*rast-cellclr);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxb.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_c";
			vtx.sref = str.str(); vtx.x = x0 + (0.5*rast-cellclr); vtx.y = y0 + (0.5*rast-cellclr);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxc.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_d";
			vtx.sref = str.str(); vtx.x = x0 - (0.5*rast-cellclr); vtx.y = y0 + (0.5*rast-cellclr);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxd.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_e";
			vtx.sref = str.str(); vtx.x = x0 - (0.5*rast-cellclr-cellolp); vtx.y = y0 - (0.5*rast-cellclr-cellolp);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxe.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_f";
			vtx.sref = str.str(); vtx.x = x0 + (0.5*rast-cellclr-cellolp); vtx.y = y0 - (0.5*rast-cellclr-cellolp);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxf.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_g";
			vtx.sref = str.str(); vtx.x = x0 + (0.5*rast-cellclr-cellolp); vtx.y = y0 + (0.5*rast-cellclr-cellolp);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxg.push_back(vtx.ref);

			str.str(""); str << "vm" << i << "_n" << j << "_h";
			vtx.sref = str.str(); vtx.x = x0 - (0.5*rast-cellclr-cellolp); vtx.y = y0 + (0.5*rast-cellclr-cellolp);
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxh.push_back(vtx.ref);
		};
	};

	// - cell array line guides plus vertex line-up
	for (int i=0;i<=mmax;i++) {
		str.str(""); str << "lha" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgha.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=0;j<=nmax;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxa[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxb[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		str.str(""); str << "lhb" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLghb.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=0;j<=nmax;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxe[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxf[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		str.str(""); str << "lhc" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLghc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=0;j<=nmax;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxh[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxg[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		str.str(""); str << "lhd" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLghd.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=0;j<=nmax;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxd[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxc[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	for (int i=0;i<=nmax;i++) {
		str.str(""); str << "lva" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgva.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=mmax;j>=0;j--) {
			lrv.lgdNum = 1 + (2*(mmax-j));
			lrv.refPlnrMVertex = refsVtxd[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*(mmax-j)+1);
			lrv.refPlnrMVertex = refsVtxa[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	for (int i=0;i<=nmax;i++) {
		str.str(""); str << "lvb" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgvb.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=mmax;j>=0;j--) {
			lrv.lgdNum = 1 + (2*(mmax-j));
			lrv.refPlnrMVertex = refsVtxh[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*(mmax-j)+1);
			lrv.refPlnrMVertex = refsVtxe[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	for (int i=0;i<=nmax;i++) {
		str.str(""); str << "lvc" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgvc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=mmax;j>=0;j--) {
			lrv.lgdNum = 1 + (2*(mmax-j));
			lrv.refPlnrMVertex = refsVtxg[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*(mmax-j)+1);
			lrv.refPlnrMVertex = refsVtxf[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	for (int i=0;i<=nmax;i++) {
		str.str(""); str << "lvd" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgvd.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		for (int j=mmax;j>=0;j--) {
			lrv.lgdNum = 1 + (2*(mmax-j));
			lrv.refPlnrMVertex = refsVtxc[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*(mmax-j)+1);
			lrv.refPlnrMVertex = refsVtxb[j*(nmax+1)+i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	// - cell array arc guides plus vertex line-up
	for (int i=0;i<=mmax;i++) {
		for (int j=0;j<=nmax;j++) {
			str.str(""); str << "am" << i << "_n" << j;
			ag.sref = str.str();
			ag.ctrRefPlnrMVertex = refsVtx0[i*(nmax+1)+j];
			dbsplnr->tblplnrmarcguide->insertRec(&ag);
			refsAg.push_back(ag.ref);

			arv.agdRefPlnrMArcguide = ag.ref;
			arv.agdNum = 1;
			arv.refPlnrMVertex = refsVtx1[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmarcguidemvertex->insertRec(&arv);

			arv.agdNum = 2;
			arv.refPlnrMVertex = refsVtx2[i*(nmax+1)+j];
			dbsplnr->tblplnrlrmarcguidemvertex->insertRec(&arv);
		};
	};

	// - cell array faces
	if (padfill) {
		for (int i=0;i<=mmax;i++) {
			for (int j=0;j<=nmax;j++) {
				// top metallization
				str.str(""); str << "fm" << i << "_n" << j << "_1";
				fce.sruRefPlnrMStructure = refSruTopmet;
				fce.sref = str.str();
				dbsplnr->tblplnrmface->insertRec(&fce);

				frv.fceRefPlnrMFace = fce.ref;

				frv.fceNum = 1;
				frv.refPlnrMVertex = refsVtxa[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;
				frv.rteUref = refsLgha[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 2;
				frv.refPlnrMVertex = refsVtxb[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;
				frv.rteUref = refsLgvd[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 3;
				frv.refPlnrMVertex = refsVtxc[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;
				frv.rteUref = refsLghd[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4;
				frv.refPlnrMVertex = refsVtxd[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;
				frv.rteUref = refsLgva[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				// bump
				str.str(""); str << "fm" << i << "_n" << j << "_2";
				fce.sruRefPlnrMStructure = refSruBump;
				fce.sref = str.str();
				dbsplnr->tblplnrmface->insertRec(&fce);

				frv.fceRefPlnrMFace = fce.ref;

				frv.fceNum = 1;
				frv.refPlnrMVertex = refsVtx1[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::AGD;
				frv.rteUref = refsAg[i*(nmax+1)+j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 2;
				frv.refPlnrMVertex = refsVtx2[i*(nmax+1)+j];
				frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::AGD;
				frv.rteUref = refsAg[i*(nmax+1)+j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
			};
		};
	};

	// -- wire bond pad elements

	// - wire bond pad vertices
	for (int i=0; i < (2*(nmax+1 + mmax+1)/ratio) ;i++) {

		if ( i < ((nmax+1)/ratio) ) {
			// south
			x0 = xofs - 0.5*rast + 0.5*((double) ratio)*rast;
			y0 = yofs - 0.5*rast - framew - 0.5*((double) ratio)*rast;

			x0 += ((double) (i*ratio))*rast;

		} else if ( (i >= ((nmax+1)/ratio)) && (i < ((nmax+1 + mmax+1)/ratio)) ) {
			// east
			x0 = xofs - 0.5*rast + ((double) (nmax+1))*rast + framew + 0.5*((double) ratio)*rast;
			y0 = yofs - 0.5*rast + 0.5*((double) ratio)*rast;

			y0 += ((double) ((i-(nmax+1)/ratio)*ratio))*rast;

		} else if ( (i >= ((nmax+1 + mmax+1)/ratio)) && (i < ((nmax+1 + mmax+1 + nmax+1)/ratio)) ) {
			// north
			x0 = xofs - 0.5*rast + ((double) (nmax+1))*rast - 0.5*((double) ratio)*rast;
			y0 = yofs - 0.5*rast + ((double) (mmax+1))*rast + framew + 0.5*((double) ratio)*rast;

			x0 -= ((double) ((i-(nmax+1 + mmax+1)/ratio)*ratio))*rast;

		} else if ( i >= ((nmax+1 + mmax+1 + nmax+1)/ratio) ) {
			// west
			x0 = xofs - 0.5*rast - framew - 0.5*((double) ratio)*rast;
			y0 = yofs - 0.5*rast + ((double) (mmax+1))*rast - 0.5*((double) ratio)*rast;

			y0 -= ((double) ((i-(nmax+1 + mmax+1 + nmax+1)/ratio)*ratio))*rast;
		};

		str.str(""); str << "vp" << (i+1) << "_a";
		vtx.sref = str.str(); vtx.x = x0 - (0.5*((double) ratio)*rast-wbclr); vtx.y = y0 - (0.5*((double) ratio)*rast-wbclr);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpa.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_b";
		vtx.sref = str.str(); vtx.x = x0 + (0.5*((double) ratio)*rast-wbclr); vtx.y = y0 - (0.5*((double) ratio)*rast-wbclr);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpb.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_c";
		vtx.sref = str.str(); vtx.x = x0 + (0.5*((double) ratio)*rast-wbclr); vtx.y = y0 + (0.5*((double) ratio)*rast-wbclr);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpc.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_d";
		vtx.sref = str.str(); vtx.x = x0 - (0.5*((double) ratio)*rast-wbclr); vtx.y = y0 + (0.5*((double) ratio)*rast-wbclr);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpd.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_e";
		vtx.sref = str.str(); vtx.x = x0 - (0.5*((double) ratio)*rast-wbclr-wbolp); vtx.y = y0 - (0.5*((double) ratio)*rast-wbclr-wbolp);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpe.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_f";
		vtx.sref = str.str(); vtx.x = x0 + (0.5*((double) ratio)*rast-wbclr-wbolp); vtx.y = y0 - (0.5*((double) ratio)*rast-wbclr-wbolp);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpf.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_g";
		vtx.sref = str.str(); vtx.x = x0 + (0.5*((double) ratio)*rast-wbclr-wbolp); vtx.y = y0 + (0.5*((double) ratio)*rast-wbclr-wbolp);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxpg.push_back(vtx.ref);

		str.str(""); str << "vp" << (i+1) << "_h";
		vtx.sref = str.str(); vtx.x = x0 - (0.5*((double) ratio)*rast-wbclr-wbolp); vtx.y = y0 + (0.5*((double) ratio)*rast-wbclr-wbolp);
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxph.push_back(vtx.ref);
	};

	// - wire bond pad global line guides
	lg.sref = "lvwa"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvwa = lg.ref;
	lg.sref = "lvwb"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvwb = lg.ref;
	lg.sref = "lvwc"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvwc = lg.ref;
	lg.sref = "lvwd"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvwd = lg.ref;

	for (int i=0; i < ((mmax+1)/ratio) ;i++) {
		int ix = i + (nmax+1 + mmax+1 + nmax+1)/ratio;

		lrv.lgdRefPlnrMLineguide = refLgvwa;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpd[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpa[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgvwb;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxph[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpe[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgvwc;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpg[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpf[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgvwd;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpc[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpb[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	lg.sref = "lvea"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvea = lg.ref;
	lg.sref = "lveb"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgveb = lg.ref;
	lg.sref = "lvec"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgvec = lg.ref;
	lg.sref = "lved"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLgved = lg.ref;

	for (int i=0; i < ((mmax+1)/ratio) ;i++) {
		int ix = ((mmax+1)/ratio-i-1) + (nmax+1)/ratio; // pin index

		lrv.lgdRefPlnrMLineguide = refLgvea;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpd[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpa[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgveb;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxph[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpe[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgvec;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpg[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpf[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLgved;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpc[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpb[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	lg.sref = "lhsa"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghsa = lg.ref;
	lg.sref = "lhsb"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghsb = lg.ref;
	lg.sref = "lhsc"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghsc = lg.ref;
	lg.sref = "lhsd"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghsd = lg.ref;

	for (int i=0; i < ((nmax+1)/ratio) ;i++) {
		int ix = i;

		lrv.lgdRefPlnrMLineguide = refLghsa;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpa[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpb[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghsb;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpe[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpf[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghsc;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxph[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpg[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghsd;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpd[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpc[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	lg.sref = "lhna"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghna = lg.ref;
	lg.sref = "lhnb"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghnb = lg.ref;
	lg.sref = "lhnc"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghnc = lg.ref;
	lg.sref = "lhnd"; dbsplnr->tblplnrmlineguide->insertRec(&lg); refLghnd = lg.ref;

	for (int i=0; i < ((nmax+1)/ratio) ;i++) {
		int ix = ((nmax+1)/ratio-i-1) + (nmax+1 + mmax+1)/ratio; // pin index

		lrv.lgdRefPlnrMLineguide = refLghna;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpa[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpb[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghnb;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpe[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpf[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghnc;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxph[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpg[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdRefPlnrMLineguide = refLghnd;
		lrv.lgdNum = 2*i+1;
		lrv.refPlnrMVertex = refsVtxpd[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2*i+2;
		lrv.refPlnrMVertex = refsVtxpc[ix];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	// - wire bond pad individual line guides
	for (int i=0; i < (2*(nmax+1 + mmax+1)/ratio) ;i++) {

		if ( ( i < ((nmax+1)/ratio) ) || ( (i >= ((nmax+1 + mmax+1)/ratio)) && (i < ((nmax+1 + mmax+1 + nmax+1)/ratio)) ) ) {
			// south / north
			str.str(""); str << "lp" << (i+1) << "a"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpa.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpd[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpa[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "b"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpb.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxph[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpe[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "c"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpc.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpg[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpf[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "d"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpd.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpc[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpb[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		} else {
			// east / west
			str.str(""); str << "lp" << (i+1) << "a"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpa.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpa[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpb[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "b"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpb.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpe[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpf[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "c"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpc.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxph[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpg[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			str.str(""); str << "lp" << (i+1) << "d"; lg.sref = str.str();
			dbsplnr->tblplnrmlineguide->insertRec(&lg); refsLgpd.push_back(lg.ref);
			lrv.lgdRefPlnrMLineguide = lg.ref;

			lrv.lgdNum = 1;
			lrv.refPlnrMVertex = refsVtxpd[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 2;
			lrv.refPlnrMVertex = refsVtxpc[i];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

	};

	// - wire bond pad faces
	frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;

	for (int i=0; i < (2*(nmax+1 + mmax+1)/ratio) ;i++) {

		if ( i < ((nmax+1)/ratio) ) {
			// south
			// f0,f2: a(lhsa)b(/lpd)c(/lhsd)d(lpa)
			// f1: e(lhsb)f(/lpc)g(/lhsc)h(lpb)
			str.str(""); str << "fp" << (i+1) << "_0"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruBotmet, str.str(), refsVtxpa[i], refLghsa, refsVtxpb[i], refsLgpd[i], refsVtxpc[i], refLghsd, refsVtxpd[i], refsLgpa[i]);

			str.str(""); str << "fp" << (i+1) << "_1"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruIns, str.str(), refsVtxpe[i], refLghsb, refsVtxpf[i], refsLgpc[i], refsVtxpg[i], refLghsc, refsVtxph[i], refsLgpb[i]);

			str.str(""); str << "fp" << (i+1) << "_2"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruTopmet, str.str(), refsVtxpa[i], refLghsa, refsVtxpb[i], refsLgpd[i], refsVtxpc[i], refLghsd, refsVtxpd[i], refsLgpa[i]);

		} else if ( (i >= ((nmax+1)/ratio)) && (i < ((nmax+1 + mmax+1)/ratio)) ) {
			// east
			// f0,f2: a(lpa)b(/lved)c(/lpd)d(lvea)
			// f1: e(lpb)f(/lvec)g(/lpc)h(lveb)
			str.str(""); str << "fp" << (i+1) << "_0"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruBotmet, str.str(), refsVtxpa[i], refsLgpa[i], refsVtxpb[i], refLgved, refsVtxpc[i], refsLgpd[i], refsVtxpd[i], refLgvea);

			str.str(""); str << "fp" << (i+1) << "_1"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruIns, str.str(), refsVtxpe[i], refsLgpb[i], refsVtxpf[i], refLgvec, refsVtxpg[i], refsLgpc[i], refsVtxph[i], refLgveb);

			str.str(""); str << "fp" << (i+1) << "_2"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruTopmet, str.str(), refsVtxpa[i], refsLgpa[i], refsVtxpb[i], refLgved, refsVtxpc[i], refsLgpd[i], refsVtxpd[i], refLgvea);

		} else if ( (i >= ((nmax+1 + mmax+1)/ratio)) && (i < ((nmax+1 + mmax+1 + nmax+1)/ratio)) ) {
			// north
			// f0: a(lhna)b(/lpd)c(/lhnd)d(lpa)
			// f1: e(lhnb)f(/lpc)g(/lhnc)h(lpb)
			str.str(""); str << "fp" << (i+1) << "_0"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruBotmet, str.str(), refsVtxpa[i], refLghna, refsVtxpb[i], refsLgpd[i], refsVtxpc[i], refLghnd, refsVtxpd[i], refsLgpa[i]);

			str.str(""); str << "fp" << (i+1) << "_1"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruIns, str.str(), refsVtxpe[i], refLghnb, refsVtxpf[i], refsLgpc[i], refsVtxpg[i], refLghnc, refsVtxph[i], refsLgpb[i]);

			str.str(""); str << "fp" << (i+1) << "_2"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruTopmet, str.str(), refsVtxpa[i], refLghna, refsVtxpb[i], refsLgpd[i], refsVtxpc[i], refLghnd, refsVtxpd[i], refsLgpa[i]);

		} else if ( i >= ((nmax+1 + mmax+1 + nmax+1)/ratio) ) {
			// west
			// f0: a(lpa)b(/lvwd)c(/lpd)d(lvwa)
			// f1: e(lpb)f(/lvwc)g(/lpc)h(lvwb)
			str.str(""); str << "fp" << (i+1) << "_0"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruBotmet, str.str(), refsVtxpa[i], refsLgpa[i], refsVtxpb[i], refLgvwd, refsVtxpc[i], refsLgpd[i], refsVtxpd[i], refLgvwa);

			str.str(""); str << "fp" << (i+1) << "_1"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruIns, str.str(), refsVtxpe[i], refsLgpb[i], refsVtxpf[i], refLgvwc, refsVtxpg[i], refsLgpc[i], refsVtxph[i], refLgvwb);

			str.str(""); str << "fp" << (i+1) << "_2"; fce.sref = str.str();
			vtxgdfces_addsq(dbsplnr, refSruTopmet, str.str(), refsVtxpa[i], refsLgpa[i], refsVtxpb[i], refLgvwd, refsVtxpc[i], refsLgpd[i], refsVtxpd[i], refLgvwa);
		};
	};
};

void PlnrExpPinout::vtxgdfces_addsq(
			DbsPlnr* dbsplnr
			, const ubigint sruRefPlnrMStructure
			, const string sref
			, const ubigint refVtx1
			, const ubigint refLg1
			, const ubigint refVtx2
			, const ubigint refLg2
			, const ubigint refVtx3
			, const ubigint refLg3
			, const ubigint refVtx4
			, const ubigint refLg4
		) {
	PlnrMFace fce(0, 0, 0, VecPlnrVLat::INI, sruRefPlnrMStructure, sref);
	dbsplnr->tblplnrmface->insertRec(&fce);

	PlnrRMFaceMVertex frv(0, fce.ref, 0, 0, VecPlnrVRMFaceMVertexRteTbl::LGD, 0, 0);

	frv.fceNum = 1;
	frv.refPlnrMVertex = refVtx1;
	frv.rteUref = refLg1;
	frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
	dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

	frv.fceNum = 2;
	frv.refPlnrMVertex = refVtx2;
	frv.rteUref = refLg2;
	frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
	dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

	frv.fceNum = 3;
	frv.refPlnrMVertex = refVtx3;
	frv.rteUref = refLg3;
	frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
	dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

	frv.fceNum = 4;
	frv.refPlnrMVertex = refVtx4;
	frv.rteUref = refLg4;
	frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
	dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
};

void PlnrExpPinout::piopin_loadpars(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, int& wb
			, string& cell
			, bool& keepoff
		) {
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wb", wb);
	loadModStringDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cell", cell);
	loadModBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "keepoff", keepoff);
};

void PlnrExpPinout::piopin_gdfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mmax
			, const int nmax
			, const int ratio
			, const int wb
			, const string cell
			, const bool keepoff
			, const ubigint refSruBotmet
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	// lxp<i>a, lxp<i>b for trapezoid
	// fxp<i> is trapezoid plus wire

	ostringstream str;
	ostringstream stra;
	ostringstream strb;

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;
	ListPlnrMArcguide ags;	

	int m, n;

	Plnr::crefToMn(cell, m, n);

	// - diagonal line guides
	if ( wb <= ((nmax+1)/ratio) ) {
		// south
		stra.str(""); stra << "vp" << wb << "_d;vm0_n" << n << "_a";
		strb.str(""); strb << "vp" << wb << "_c;vm0_n" << n << "_b";
	} else if ( (wb > ((nmax+1)/ratio)) && (wb <= ((nmax+1 + mmax+1)/ratio)) ) {
		// east
		stra.str(""); stra << "vp" << wb << "_a;vm" << m << "_n" << nmax << "_b";
		strb.str(""); strb << "vp" << wb << "_d;vm" << m << "_n" << nmax << "_c";
	} else if ( (wb > ((nmax+1 + mmax+1)/ratio)) && (wb <= ((nmax+1 + mmax+1 + nmax+1)/ratio)) ) {
		// north
		stra.str(""); stra << "vp" << wb << "_a;vm" << mmax << "_n" << n << "_d";
		strb.str(""); strb << "vp" << wb << "_b;vm" << mmax << "_n" << n << "_c";
	} else if ( wb > ((nmax+1 + mmax+1 + nmax+1)/ratio) ) {
		// west
		stra.str(""); stra << "vp" << wb << "_c;vm" << m << "_n0_d";
		strb.str(""); strb << "vp" << wb << "_b;vm" << m << "_n0_a";
	};

	str.str(""); str << "lxp" << wb << "a";
	StrMod::stringToVector(stra.str(), vsrefs);
	opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);

	str.str(""); str << "lxp" << wb << "b";
	StrMod::stringToVector(strb.str(), vsrefs);
	opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);

	// - pin face
	if ( wb <= ((nmax+1)/ratio) ) {
		// south
		stra.str(""); stra << "vp" << wb << "_d;vm0_n" << n << "_a;";
		if (keepoff) {
			if (m != 0) stra << "vm" << m << "_n" << n << "_a;vm" << m << "_n" << n << "_b;";
		} else {
			stra << "vm" << m << "_n" << n << "_d;vm" << m << "_n" << n << "_c;";
		};
		stra << "vm0_n" << n << "_b;vp" << wb << "_c";

		if (keepoff && (m == 0)) {
			StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
		} else {
			StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		};

		// gsrefs
		strb.str(""); strb << "lxp" << wb << "a;";
		if (keepoff) {
			if (m == 0) {
				strb << "lha0;";
			} else {
				strb << "lva" << n << ";lha" << m << ";lvd" << n << ";";
			};
		} else {
			strb << "lva" << n << ";lhd" << m << ";lvd" << n << ";";
		};
		strb << "lxp" << wb << "b;lp" << wb << "d";

		// dirs
		if (keepoff && (m == 0)) {
			StrMod::stringToVector("fwd;fwd;bwd;bwd", dirs);
		} else {
			StrMod::stringToVector("fwd;bwd;fwd;fwd;bwd;bwd", dirs);
		};

	} else if ( (wb > ((nmax+1)/ratio)) && (wb <= ((nmax+1 + mmax+1)/ratio)) ) {
		// east
		stra.str(""); stra << "vp" << wb << "_a;vm" << m << "_n" << nmax << "_b;";
		if (keepoff) {
			if (n != nmax) stra << "vm" << m << "_n" << n << "_b;vm" << m << "_n" << n << "_c;";
		} else {
			stra << "vm" << m << "_n" << n << "_a;vm" << m << "_n" << n << "_d;";
		};
		stra << "vm" << m << "_n" << nmax << "_c;vp" << wb << "_d";

		if (keepoff && (n == nmax)) {
			StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
		} else {
			StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		};

		// gsrefs
		strb.str(""); strb << "lxp" << wb << "a;";
		if (keepoff) {
			if (n == nmax) {
				strb << "lvd" << nmax << ";";
			} else {
				strb << "lha" << m << ";lvd" << n << ";lhd" << m << ";";
			};
		} else {
			strb << "lha" << m << ";lva" << n << ";lhd" << m << ";";
		};
		strb << "lxp" << wb << "b;lp" << wb << "a";

		// dirs
		if (keepoff && (n == nmax)) {
			StrMod::stringToVector("fwd;bwd;bwd;fwd", dirs);
		} else {
			StrMod::stringToVector("fwd;bwd;bwd;fwd;bwd;fwd", dirs);
		};

	} else if ( (wb > ((nmax+1 + mmax+1)/ratio)) && (wb <= ((nmax+1 + mmax+1 + nmax+1)/ratio)) ) {
		// north
		stra.str(""); stra << "vp" << wb << "_a;vm" << mmax << "_n" << n << "_d;";
		if (keepoff) {
			if (m != mmax) stra << "vm" << m << "_n" << n << "_d;vm" << m << "_n" << n << "_c;";
		} else {
			stra << "vm" << m << "_n" << n << "_a;vm" << m << "_n" << n << "_b;";
		};
		stra << "vm" << mmax << "_n" << n << "_c;vp" << wb << "_b";

		if (keepoff && (m == mmax)) {
			StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
		} else {
			StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		};

		// gsrefs
		strb.str(""); strb << "lxp" << wb << "a;";
		if (keepoff) {
			if (m == mmax) {
				strb << "lha" << mmax << ";";
			} else {
				strb << "lva" << n << ";lhd" << m << ";lvd" << n << ";";
			};
		} else {
			strb << "lva" << n << ";lha" << m << ";lvd" << n << ";";
		};
		strb << "lxp" << wb << "b;lp" << wb << "a";

		// dirs
		if (keepoff && (m == mmax)) {
			StrMod::stringToVector("fwd;fwd;bwd;bwd", dirs);
		} else {
			StrMod::stringToVector("fwd;fwd;fwd;bwd;bwd;bwd", dirs);
		};

	} else if ( wb > ((nmax+1 + mmax+1 + nmax+1)/ratio) ) {
		// west
		stra.str(""); stra << "vp" << wb << "_c;vm" << m << "_n0_d;";
		if (keepoff) {
			if (n != 0) stra << "vm" << m << "_n" << n << "_d;vm" << m << "_n" << n << "_a;";
		} else {
			stra << "vm" << m << "_n" << n << "_c;vm" << m << "_n" << n << "_b;";
		};
		stra << "vm" << m << "_n0_a;vp" << wb << "_b";

		if (keepoff && (n == 0)) {
			StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
		} else {
			StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		};

		// gsrefs
		strb.str(""); strb << "lxp" << wb << "a;";
		if (keepoff) {
			if (n == 0) {
				strb << "lva0;";
			} else {
				strb << "lhd" << m << ";lva" << n << ";lha" << m << ";";
			};
		} else {
			strb << "lhd" << m << ";lvd" << n << ";lha" << m << ";";
		};
		strb << "lxp" << wb << "b;lp" << wb << "d";

		// dirs
		if (keepoff && (n == 0)) {
			StrMod::stringToVector("fwd;fwd;bwd;bwd", dirs);
		} else {
			StrMod::stringToVector("fwd;fwd;fwd;bwd;bwd;bwd", dirs);
		};
	};

	str.str(""); str << "fxp" << wb;
	StrMod::stringToVector(stra.str(), vsrefs);
	StrMod::stringToVector(strb.str(), gsrefs);
	opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruBotmet, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
};

void PlnrExpPinout::piopad_loadpars(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, string& cell
		) {
	loadModStringDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cell", cell);
};

void PlnrExpPinout::piopad_fces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const bool padfill
			, const string cell
			, const ubigint refSruIns
			, const ubigint refSruTopmet
			, const ubigint refSruBump
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	// fxm<i>_n<j>_0 (ins) and _1 (topmet) and _2 (bump)
	// skip _1, _2 for padfill

	ostringstream str;

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	int m, n;

	Plnr::crefToMn(cell, m, n);

	str.str(""); str << "vm" << m << "_n" << n << "_e;vm" << m << "_n" << n << "_f;vm" << m << "_n" << n << "_g;vm" << m << "_n" << n << "_h";
	StrMod::stringToVector(str.str(), vsrefs);
	StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
	str.str(""); str << "lhb" << m << ";lvc" << n << ";lhc" << m << ";lvb" << n;
	StrMod::stringToVector(str.str(), gsrefs);
	StrMod::stringToVector("fwd;bwd;bwd;fwd", dirs);
	str.str(""); str << "fxm" << m << "_n" << n << "_0";
	opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruIns, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);

	if (!padfill) {
		str.str(""); str << "vm" << m << "_n" << n << "_a;vm" << m << "_n" << n << "_b;vm" << m << "_n" << n << "_c;vm" << m << "_n" << n << "_d";
		StrMod::stringToVector(str.str(), vsrefs);
		StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
		str.str(""); str << "lha" << m << ";lvd" << n << ";lhd" << m << ";lva" << n;
		StrMod::stringToVector(str.str(), gsrefs);
		StrMod::stringToVector("fwd;bwd;bwd;fwd", dirs);
		str.str(""); str << "fxm" << m << "_n" << n << "_1";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruTopmet, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);

		str.str(""); str << "vm" << m << "_n" << n << "_1;vm" << m << "_n" << n << "_2";
		StrMod::stringToVector(str.str(), vsrefs);
		StrMod::stringToVector("agd;agd", rtes);
		str.str(""); str << "am" << m << "_n" << n << ";am" << m << "_n" << n;
		StrMod::stringToVector(str.str(), gsrefs);
		StrMod::stringToVector("fwd;fwd", dirs);
		str.str(""); str << "fxm" << m << "_n" << n << "_2";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruBump, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	};
};
// IP cust --- IEND


