/**
  * \file PlnrExpVanderpauw.cpp
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

#include "PlnrExpVanderpauw.h"

DpchRetPlnr* PlnrExpVanderpauw::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpVanderpauw* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double crsl0 = 6.0; double crsl;
	double crsw0 = 3.0; double crsw;
	double size0 = 100.0; double size;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "crsl", crsl0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "crsw", crsw0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);

	// --- expand baseline
	crsl = crsl0;
	crsw = crsw0;
	size = size0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, crsl, crsw, size, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, crsw, size, vtxs, lgs, ags);
	faces(dbsplnr, refPlnrMDevice, refSruAll, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		crsl = crsl0;
		crsw = crsw0;
		size = size0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "crsl", crsl)) modpar += _CRSL;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "crsw", crsw)) modpar += _CRSW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "size", size)) modpar += _SIZE;

		// dnoto modifications only, arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, crsl, crsw, size, vtxs);
			if (modpar & (_CRSW + _SIZE)) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, crsw, size, vtxs, lgs, ags);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpVanderpauw::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double crsl
			, const double crsw
			, const double size
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// -- nw vertices (ne, sw and se are flipped copies of nw)

	// x,y positions
	vsrefs.push_back("v1"); vxs.push_back(-0.5*size); vys.push_back(0.5*crsw);
	vsrefs.push_back("v2"); vxs.push_back(-0.5*crsl); vys.push_back(0.5*crsw);
	vsrefs.push_back("v3"); vxs.push_back(-0.5*crsw); vys.push_back(0.5*crsl);
	vsrefs.push_back("v4"); vxs.push_back(-0.5*crsw); vys.push_back(0.5*size);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=1;i<=4;i++) {
			if ( (((i == 1) || (i == 4)) && (modpar & (_SIZE + _CRSW))) 
						|| (((i == 2) || (i == 3)) && (modpar & (_CRSL + _CRSW))) ) addVertexXYByVsref(dbsplnr, vsrefs[i-1], x1RefPlnrMDesign, vxs[i-1], vys[i-1], vtxs);
		};
	};

	// -- ne (nw /x)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+4);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+4);
			if ( (((i == 1) || (i == 4)) && (modpar & (_SIZE + _CRSW))) 
						|| (((i == 2) || (i == 3)) && (modpar & (_CRSL + _CRSW))) ) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], vys[i-1], vtxs);
		};
	};

	// -- sw (nw /y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+8);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+8);
			if ( (((i == 1) || (i == 4)) && (modpar & (_SIZE + _CRSW))) 
						|| (((i == 2) || (i == 3)) && (modpar & (_CRSL + _CRSW))) ) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, vxs[i-1], -vys[i-1], vtxs);
		};
	};

	// -- se (nw /x/y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+12);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=4;i++) {
			str.str(""); str << "v" << (i+12);
			if ( (((i == 1) || (i == 4)) && (modpar & (_SIZE + _CRSW))) 
						|| (((i == 2) || (i == 3)) && (modpar & (_CRSL + _CRSW))) ) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], -vys[i-1], vtxs);
		};
	};

	// -- arc center vertices
	if (x1RefPlnrMDesign == 0) {
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v17", -0.5*crsw, 0.5*crsw, vtxs);
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v18", 0.5*crsw, 0.5*crsw, vtxs);
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v19", -0.5*crsw, -0.5*crsw, vtxs);
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v20", 0.5*crsw, -0.5*crsw, vtxs);

	} else if ((x1RefPlnrMDesign != 0) && (modpar & _CRSW)) {
		addVertexXYByVsref(dbsplnr, "v17", x1RefPlnrMDesign, -0.5*crsw, 0.5*crsw, vtxs);
		addVertexXYByVsref(dbsplnr, "v18", x1RefPlnrMDesign, 0.5*crsw, 0.5*crsw, vtxs);
		addVertexXYByVsref(dbsplnr, "v19", x1RefPlnrMDesign, -0.5*crsw, -0.5*crsw, vtxs);
		addVertexXYByVsref(dbsplnr, "v20", x1RefPlnrMDesign, 0.5*crsw, -0.5*crsw, vtxs);
	};
};

void PlnrExpVanderpauw::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double crsw
			, const double size
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	vector<string> asrefs;
	vector<string> vsrefs;
	vector<double> rs;

	// -- line guides
	if (x1RefPlnrMDesign == 0) {
		lsrefs.push_back("l0"); vsrefsstrs.push_back("v1;v9");
		lsrefs.push_back("l1"); vsrefsstrs.push_back("v2;v10");
		lsrefs.push_back("l2"); vsrefsstrs.push_back("v4;v3;v17;v19;v11;v12");
		lsrefs.push_back("l3"); vsrefsstrs.push_back("v8;v7;v18;v20;v15;v16");
		lsrefs.push_back("l4"); vsrefsstrs.push_back("v6;v14");
		lsrefs.push_back("l5"); vsrefsstrs.push_back("v5;v13");
		lsrefs.push_back("l6"); vsrefsstrs.push_back("v4;v8");
		lsrefs.push_back("l7"); vsrefsstrs.push_back("v3;v7");
		lsrefs.push_back("l8"); vsrefsstrs.push_back("v1;v2;v17;v18;v6;v5");
		lsrefs.push_back("l9"); vsrefsstrs.push_back("v9;v10;v19;v20;v14;v13");
		lsrefs.push_back("l10"); vsrefsstrs.push_back("v11;v15");
		lsrefs.push_back("l11"); vsrefsstrs.push_back("v12;v16");

		addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
	};

	// -- arc guides
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v17"); rs.push_back(0.5*(size-crsw)); vsrefsstrs.push_back("v4;v1");
	asrefs.push_back("a1"); vsrefs.push_back("v18"); rs.push_back(0.5*(size-crsw)); vsrefsstrs.push_back("v5;v8");
	asrefs.push_back("a2"); vsrefs.push_back("v19"); rs.push_back(0.5*(size-crsw)); vsrefsstrs.push_back("v9;v12");
	asrefs.push_back("a3"); vsrefs.push_back("v20"); rs.push_back(0.5*(size-crsw)); vsrefsstrs.push_back("v16;v13");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};
};

void PlnrExpVanderpauw::faces(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("v1; v2; v10;v9; v12;v11;v15;v16;v13;v14;v6; v5; v8; v7; v3; v4");
	rtesstrs.push_back	("lgd;lgd;lgd;agd;lgd;lgd;lgd;agd;lgd;lgd;lgd;agd;lgd;lgd;lgd;agd");
	gsrefsstrs.push_back("l8; l1; l9; a2; l2; l10;l3; a3; l9; l4; l8; a1; l3; l7; l2; a0");
	dirsstrs.push_back	("fwd;fwd;bwd;fwd;bwd;fwd;fwd;fwd;bwd;bwd;fwd;fwd;fwd;bwd;bwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


