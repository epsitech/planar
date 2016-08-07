/**
  * \file PlnrExpWgsusp.cpp
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

#include "PlnrExpWgsusp.h"

DpchRetPlnr* PlnrExpWgsusp::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgsusp* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double l0 = 50.0; double l;
	double ridgew0 = 2.0; double ridgew;
	double cantl0 = 20.0; double cantl;
	double cantw0 = 0.5; double cantw;
	double cantd0 = 1.0; double cantd;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "l", l0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cantl", cantl0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cantw", cantw0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cantd", cantd0);

	// --- expand baseline
	l = l0;
	ridgew = ridgew0;
	cantl = cantl0;
	cantw = cantw0;
	cantd = cantd0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, l, ridgew, cantl, cantw, cantd, vtxs);
	guides(dbsplnr, refPlnrMDevice, vtxs, lgs);
	faces(dbsplnr, refPlnrMDevice, refSruAll, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		l = l0;
		ridgew = ridgew0;
		cantl = cantl0;
		cantw = cantw0;
		cantd = cantd0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "l", l)) modpar += _L;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cantl", cantl)) modpar += _CANTL;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cantw", cantw)) modpar += _CANTW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cantd", cantd)) modpar += _CANTD;

		// all modifications are dnoto
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, l, ridgew, cantl, cantw, cantd, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpWgsusp::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double l
			, const double ridgew
			, const double cantl
			, const double cantw
			, const double cantd
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - cantilever vertices
	vsrefs.push_back("v1"); vxs.push_back(-cantl); vys.push_back(-0.5*(cantd+cantw)); // [0]
	vsrefs.push_back("v2"); vxs.push_back(-0.5*ridgew); vys.push_back(-0.5*(cantd+cantw));
	vsrefs.push_back("v3"); vxs.push_back(-0.5*ridgew); vys.push_back(-0.5*(cantd-cantw));
	vsrefs.push_back("v4"); vxs.push_back(-cantl); vys.push_back(-0.5*(cantd-cantw));

	vsrefs.push_back("v5"); vxs.push_back(-vxs[0]); vys.push_back(vys[0]);
	vsrefs.push_back("v6"); vxs.push_back(-vxs[1]); vys.push_back(vys[1]);
	vsrefs.push_back("v7"); vxs.push_back(-vxs[2]); vys.push_back(vys[2]);
	vsrefs.push_back("v8"); vxs.push_back(-vxs[3]); vys.push_back(vys[3]);

	vsrefs.push_back("v9"); vxs.push_back(-vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("v10"); vxs.push_back(-vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("v11"); vxs.push_back(-vxs[2]); vys.push_back(-vys[2]);
	vsrefs.push_back("v12"); vxs.push_back(-vxs[3]); vys.push_back(-vys[3]);

	vsrefs.push_back("v13"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("v14"); vxs.push_back(vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("v15"); vxs.push_back(vxs[2]); vys.push_back(-vys[2]);
	vsrefs.push_back("v16"); vxs.push_back(vxs[3]); vys.push_back(-vys[3]);

	// - connector vertices
	vsrefs.push_back("vsw"); vxs.push_back(-0.5*ridgew); vys.push_back(-0.5*l); // [16]
	vsrefs.push_back("vsc"); vxs.push_back(0.0); vys.push_back(-0.5*l);
	vsrefs.push_back("vse"); vxs.push_back(0.5*ridgew); vys.push_back(-0.5*l);

	vsrefs.push_back("vnw"); vxs.push_back(-0.5*ridgew); vys.push_back(0.5*l);
	vsrefs.push_back("vnc"); vxs.push_back(0.0); vys.push_back(0.5*l);
	vsrefs.push_back("vne"); vxs.push_back(0.5*ridgew); vys.push_back(0.5*l);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=0;i<22;i++) {
			if (i < 16) {
				if ( (modpar & (_CANTD + _CANTW)) ) {
					addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
				} else if ( (modpar & _CANTL) && ( ((i%4) == 0) || ((i%4) == 3) ) ) {
					addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
				} else if ( (modpar & _RIDGEW) && ( ((i%4) == 1) || ((i%4) == 2) ) ) {
					addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
				};

			} else {
				if (modpar & _L) {
					addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
				} else if ((modpar & _RIDGEW) && ( (i==16) || (i==18) || (i==19) || (i==21) )) {
					addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
				};
			};
		};
	};
};

void PlnrExpWgsusp::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;

	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	// - line guides
	lsrefs.push_back("l0"); vsrefsstrs.push_back("v13;v16;v4;v1");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("vnw;v14;v15;v3;v2;vsw");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("vne;v10;v11;v7;v6;vse");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("v9;v12;v8;v5");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("vnw;vnc;vne");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("v13;v14;v10;v9");
	lsrefs.push_back("l6"); vsrefsstrs.push_back("v16;v15;v11;v12");
	lsrefs.push_back("l7"); vsrefsstrs.push_back("v4;v3;v7;v8");
	lsrefs.push_back("l8"); vsrefsstrs.push_back("v1;v2;v6;v5");
	lsrefs.push_back("l9"); vsrefsstrs.push_back("vsw;vsc;vse");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpWgsusp::faces(
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
	vsrefsstrs.push_back("vsw;vse;v6; v5; v8; v7; v11;v12;v9; v10;vne;vnw;v14;v13;v16;v15;v3; v4; v1; v2");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l9; l2; l8; l3; l7; l2; l6; l3; l5; l2; l4; l1; l5; l0; l6; l1; l7; l0; l8; l1");
	dirsstrs.push_back	("fwd;bwd;fwd;bwd;bwd;bwd;fwd;bwd;bwd;bwd;bwd;fwd;bwd;fwd;fwd;fwd;bwd;fwd;fwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


