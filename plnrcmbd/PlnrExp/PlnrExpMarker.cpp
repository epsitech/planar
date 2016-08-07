/**
  * \file PlnrExpMarker.cpp
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

#include "PlnrExpMarker.h"

DpchRetPlnr* PlnrExpMarker::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpMarker* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMFace fces;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double size0 = 10.0; double size;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);

	// --- expand baseline
	size = size0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, size, vtxs);
	guides(dbsplnr, refPlnrMDevice, vtxs, lgs);
	faces(dbsplnr, refPlnrMDevice, refSruAll, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		size = size0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "size", size)) modpar += _SIZE;

		// dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, size, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpMarker::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double size
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// -- nw vertices (se are flipped copies of nw)

	// x,y positions
	vsrefs.push_back("v1"); vxs.push_back(-0.1*size); vys.push_back(0.0);
	vsrefs.push_back("v2"); vxs.push_back(-0.1*size); vys.push_back(0.1*size);
	vsrefs.push_back("v3"); vxs.push_back(0.0); vys.push_back(0.1*size);
	vsrefs.push_back("v4"); vxs.push_back(0.0); vys.push_back(0.5*size);
	vsrefs.push_back("v5"); vxs.push_back(-0.5*size); vys.push_back(0.0);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
	} else {
		addVertexXYs(dbsplnr, vsrefs, x1RefPlnrMDesign, vxs, vys, vtxs);
	};

	// -- se (nw /x/y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=5;i++) {
			str.str(""); str << "v" << (i+5);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=5;i++) {
			str.str(""); str << "v" << (i+5);
			addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], -vys[i-1], vtxs);
		};
	};
};

void PlnrExpMarker::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	lsrefs.push_back("l0"); vsrefsstrs.push_back("v5;v1;vctr;v6;v10");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("v4;v3;vctr;v8;v9");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("v4;v5");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("v10;v9");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("v2;v3");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("v8;v7");
	lsrefs.push_back("l6"); vsrefsstrs.push_back("v2;v1");
	lsrefs.push_back("l7"); vsrefsstrs.push_back("v6;v7");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpMarker::faces(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	ListPlnrMArcguide ags;

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("v1; v2; v3; v4; v5");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l6; l4; l1; l2; l0");
	dirsstrs.push_back	("bwd;fwd;bwd;fwd;fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v6; v7; v8; v9; v10");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l7; l5; l1; l3; l0");
	dirsstrs.push_back	("fwd;bwd;fwd;bwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


