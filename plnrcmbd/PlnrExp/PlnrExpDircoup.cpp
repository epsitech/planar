/**
  * \file PlnrExpDircoup.cpp
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

#include "PlnrExpDircoup.h"

DpchRetPlnr* PlnrExpDircoup::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpDircoup* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruWg1 = 0;
	ubigint refSruWg2 = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "wg1", refSruWg1);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "wg2", refSruWg2);

	// load baseline parameters
	bool wg20 = true; bool wg2;
	double ridgew10 = 0.55; double ridgew1;
	double ridgew20 = 0.55; double ridgew2;
	double r0 = 10.0; double r;
	double cpllen0 = 10.0; double cpllen;
	double dist0 = 0.3; double dist;

	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "wg2", wg20);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew1", ridgew10);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew2", ridgew20);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cpllen", cpllen0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "dist", dist0);

	// -- expand baseline
	wg2 = wg20;
	ridgew1 = ridgew10;
	ridgew2 = ridgew20;
	r = r0;
	cpllen = cpllen0;
	dist = dist0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, ridgew1, ridgew2, r, cpllen, dist, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, 0, ridgew1, ridgew2, r, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, wg2, refSruWg1, refSruWg2, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		wg2 = wg20;
		ridgew1 = ridgew10;
		ridgew2 = ridgew20;
		r = r0;
		cpllen = cpllen0;
		dist = dist0;

		modpar = 0;

		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wg2", wg2)) modpar += _WG2;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew1", ridgew1)) modpar += _RIDGEW1;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew2", ridgew2)) modpar += _RIDGEW2;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cpllen", cpllen)) modpar += _CPLLEN;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "dist", dist)) modpar += _DIST;

		// dto/dnoto modifications, arcguides; dto (wg2) affects faces only
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _WG2) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::FCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & (_RIDGEW1 + _RIDGEW2 + _R + _CPLLEN + _DIST)) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, ridgew1, ridgew2, r, cpllen, dist, vtxs);
		if (modpar & (_R + _RIDGEW1 + _RIDGEW2)) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, ridgew1, ridgew2, r, vtxs, lgs, ags);
		if (modpar & _WG2) {
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, wg2, refSruWg1, refSruWg2, vtxs, lgs, ags, fces2);
			fces2.clear();
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpDircoup::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double ridgew1
			, const double ridgew2
			, const double r
			, const double cpllen
			, const double dist
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// -- n vertices (s are flipped copies of n)

	// x,y positions
	vsrefs.push_back("v1"); vxs.push_back(-(0.5*dist+0.5*ridgew1+r)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v2"); vxs.push_back(-(0.5*dist+ridgew1)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v3"); vxs.push_back(-0.5*dist); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v4"); vxs.push_back(0.5*dist+0.5*ridgew2+r); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v5"); vxs.push_back(0.5*dist+ridgew2); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v6"); vxs.push_back(0.5*dist); vys.push_back(0.5*cpllen);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=1;i<=6;i++) {
			if ( (modpar & (_CPLLEN + _DIST)) || ((modpar & _RIDGEW1) && (i >= 1) && (i <= 3)) || ((modpar & _RIDGEW2) && (i >= 4) && (i <= 6)) 
						|| ((modpar & _R) && ((i == 1) || (i == 4))) ) addVertexXYByVsref(dbsplnr, vsrefs[i-1], x1RefPlnrMDesign, vxs[i-1], vys[i-1], vtxs);
		};
	};

	// -- s (n /y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=6;i++) {
			str.str(""); str << "v" << (i+6);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=6;i++) {
			str.str(""); str << "v" << (i+6);
			if ( (modpar & (_CPLLEN + _DIST)) || ((modpar & _RIDGEW1) && (i >= 1) && (i <= 3)) || ((modpar & _RIDGEW2) && (i >= 4) && (i <= 6)) 
						|| ((modpar & _R) && ((i == 1) || (i == 4))) ) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, vxs[i-1], -vys[i-1], vtxs);
		};
	};

	// - waveguide 1 connector vertices
	vsrefs.resize(0);
	vxs.resize(0);
	vys.resize(0);

	vsrefs.push_back("vwg1nn"); vxs.push_back(-(0.5*dist+0.5*ridgew1+r)); vys.push_back(0.5*cpllen+r+0.5*ridgew1);
	vsrefs.push_back("vwg1nc"); vxs.push_back(vxs[0]); vys.push_back(0.5*cpllen+r);
	vsrefs.push_back("vwg1ns"); vxs.push_back(vxs[0]); vys.push_back(0.5*cpllen+r-0.5*ridgew1);

	vsrefs.push_back("vwg1sn"); vxs.push_back(vxs[0]); vys.push_back(-vys[2]);
	vsrefs.push_back("vwg1sc"); vxs.push_back(vxs[0]); vys.push_back(-vys[1]);
	vsrefs.push_back("vwg1ss"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
	} else {
		if (modpar != _RIDGEW2) addVertexXYs(dbsplnr, vsrefs, x1RefPlnrMDesign, vxs, vys, vtxs);
	};

	// - waveguide 2 connector vertices
	vsrefs.resize(0);
	vxs.resize(0);
	vys.resize(0);

	vsrefs.push_back("vwg2nn"); vxs.push_back(0.5*dist+0.5*ridgew2+r); vys.push_back(0.5*cpllen+r+0.5*ridgew2);
	vsrefs.push_back("vwg2nc"); vxs.push_back(vxs[0]); vys.push_back(0.5*cpllen+r);
	vsrefs.push_back("vwg2ns"); vxs.push_back(vxs[0]); vys.push_back(0.5*cpllen+r-0.5*ridgew2);

	vsrefs.push_back("vwg2sn"); vxs.push_back(vxs[0]); vys.push_back(-vys[2]);
	vsrefs.push_back("vwg2sc"); vxs.push_back(vxs[0]); vys.push_back(-vys[1]);
	vsrefs.push_back("vwg2ss"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
	} else {
		if (modpar != _RIDGEW1) addVertexXYs(dbsplnr, vsrefs, x1RefPlnrMDesign, vxs, vys, vtxs);
	};
};

void PlnrExpDircoup::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double ridgew1
			, const double ridgew2
			, const double r
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
		lsrefs.push_back("l0"); vsrefsstrs.push_back("vwg1nn;vwg1nc;vwg1ns;v1;v7;vwg1sn;vwg1sc;vwg1ss");
		lsrefs.push_back("l1"); vsrefsstrs.push_back("v2;v8");
		lsrefs.push_back("l2"); vsrefsstrs.push_back("v3;v9");
		lsrefs.push_back("l3"); vsrefsstrs.push_back("v6;v12");
		lsrefs.push_back("l4"); vsrefsstrs.push_back("v5;v11");
		lsrefs.push_back("l5"); vsrefsstrs.push_back("vwg2nn;vwg2nc;vwg2ns;v4;v10;vwg2sn;vwg2sc;vwg2ss");

		addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
	};

	// -- arc guides
	asrefs.resize(0);
	vsrefs.resize(0);
	rs.resize(0);
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v1"); rs.push_back(r-0.5*ridgew1); vsrefsstrs.push_back("v2;vwg1ns");
	asrefs.push_back("a1"); vsrefs.push_back("v1"); rs.push_back(r+0.5*ridgew1); vsrefsstrs.push_back("v3;vwg1nn");
	asrefs.push_back("a4"); vsrefs.push_back("v7"); rs.push_back(r-0.5*ridgew1); vsrefsstrs.push_back("vwg1sn;v8");
	asrefs.push_back("a5"); vsrefs.push_back("v7"); rs.push_back(r+0.5*ridgew1); vsrefsstrs.push_back("vwg1ss;v9");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		if (modpar & (_RIDGEW1 + _R)) addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};

	asrefs.resize(0);
	vsrefs.resize(0);
	rs.resize(0);
	vsrefsstrs.resize(0);

	asrefs.push_back("a2"); vsrefs.push_back("v4"); rs.push_back(r-0.5*ridgew2); vsrefsstrs.push_back("vwg2ns;v5");
	asrefs.push_back("a3"); vsrefs.push_back("v4"); rs.push_back(r+0.5*ridgew2); vsrefsstrs.push_back("vwg2nn;v6");
	asrefs.push_back("a6"); vsrefs.push_back("v10"); rs.push_back(r-0.5*ridgew2); vsrefsstrs.push_back("v11;vwg2sn");
	asrefs.push_back("a7"); vsrefs.push_back("v10"); rs.push_back(r+0.5*ridgew2); vsrefsstrs.push_back("v12;vwg2ss");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		if (modpar & (_RIDGEW2 + _R)) addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};
};

void PlnrExpDircoup::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool wg2
			, const ubigint refSruWg1
			, const ubigint refSruWg2
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

	strrefs.push_back(refSruWg1);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("vwg1ss;v9; v3; vwg1nn;vwg1ns;v2; v8; vwg1sn");
	rtesstrs.push_back	("agd;   lgd;agd;lgd;   agd;   lgd;agd;lgd");
	gsrefsstrs.push_back("a5;    l2; a1; l0;    a0;    l1; a4; l0");
	dirsstrs.push_back	("fwd;   bwd;fwd;fwd;   bwd;   fwd;bwd;fwd");

	if (wg2) {
		strrefs.push_back(refSruWg2);
		fsrefs.push_back("f1");
		vsrefsstrs.push_back("vwg2ss;vwg2sn;v11;v5; vwg2ns;vwg2nn;v6; v12");
		rtesstrs.push_back	("lgd;   agd;   lgd;agd;lgd;   agd;   lgd;agd");
		gsrefsstrs.push_back("l5;    a6;    l4; a2; l5;    a3;    l3; a7");
		dirsstrs.push_back	("bwd;   bwd;   bwd;bwd;bwd;   fwd;   fwd;fwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


