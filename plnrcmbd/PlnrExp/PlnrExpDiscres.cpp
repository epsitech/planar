/**
  * \file PlnrExpDiscres.cpp
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

#include "PlnrExpDiscres.h"

DpchRetPlnr* PlnrExpDiscres::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpDiscres* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruWg = 0;
	ubigint refSruDisc = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "wg", refSruWg);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "disc", refSruDisc);

	// load baseline parameters
	bool wg10 = true; bool wg1;
	bool wg20 = true; bool wg2;
	bool disc0 = true; bool disc;
	double ridgew0 = 0.55; double ridgew;
	double r0 = 1.25; double r;
	double dist0 = 0.3; double dist;

	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "wg1", wg10);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "wg2", wg20);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "disc", disc0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "dist", dist0);

	// -- expand baseline
	wg1 = wg10;
	wg2 = wg20;
	disc = disc0;
	ridgew = ridgew0;
	r = r0;
	dist = dist0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, ridgew, r, dist, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, r, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, wg1, wg2, disc, refSruWg, refSruDisc, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		wg1 = wg10;
		wg2 = wg20;
		disc = disc0;
		ridgew = ridgew0;
		r = r0;
		dist = dist0;

		modpar = 0;

		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wg1", wg1)) modpar += _WG1;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wg2", wg2)) modpar += _WG2;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "disc", disc)) modpar += _DISC;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "dist", dist)) modpar += _DIST;

		// dto/dnoto modifications, arcguides; dto (wg1,wg2,disc) affect faces only
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & (_WG1 + _WG2 + _DISC)) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::FCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & (_RIDGEW + _R + _DIST)) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, ridgew, r, dist, vtxs);
		if (modpar & _R) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, r, vtxs, lgs, ags);
		if (modpar & (_WG1 + _WG2 + _DISC)) {
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, wg1, wg2, disc, refSruWg, refSruDisc, vtxs, lgs, ags, fces2);
			fces2.clear();
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpDiscres::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double ridgew
			, const double r
			, const double dist
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - center line vertices
	if (x1RefPlnrMDesign == 0) {
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v1", -r, 0.0, vtxs);
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v2", r, 0.0, vtxs);

	} else {
		if (modpar & _R) {
			addVertexXYByVsref(dbsplnr, "v1", x1RefPlnrMDesign, -r, 0.0, vtxs);
			addVertexXYByVsref(dbsplnr, "v2", x1RefPlnrMDesign, r, 0.0, vtxs);
		};
	};

	// - waveguide connector vertices
	vsrefs.push_back("vwg1nw"); vxs.push_back(-(r+dist+ridgew)); vys.push_back(r);
	vsrefs.push_back("vwg1nc"); vxs.push_back(-(r+dist+0.5*ridgew)); vys.push_back(r);
	vsrefs.push_back("vwg1ne"); vxs.push_back(-(r+dist)); vys.push_back(r);

	// wg2n (wg1n /x)
	vsrefs.push_back("vwg2ne"); vxs.push_back(-vxs[0]); vys.push_back(vys[0]);
	vsrefs.push_back("vwg2nc"); vxs.push_back(-vxs[1]); vys.push_back(vys[1]);
	vsrefs.push_back("vwg2nw"); vxs.push_back(-vxs[2]); vys.push_back(vys[2]);

	// wg1s (wg1n /y)
	vsrefs.push_back("vwg1sw"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("vwg1sc"); vxs.push_back(vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("vwg1se"); vxs.push_back(vxs[2]); vys.push_back(-vys[2]);

	// wg2s (wg1n /x/y)
	vsrefs.push_back("vwg2se"); vxs.push_back(-vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("vwg2sc"); vxs.push_back(-vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("vwg2sw"); vxs.push_back(-vxs[2]); vys.push_back(-vys[2]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=0;i<12;i++)
			if ( ((i%3) == 0) || ((i%3) == 1) || (((i%3) == 2) && (modpar & _RIDGEW)) )
				addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
	};
};

void PlnrExpDiscres::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
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
		lsrefs.push_back("l0"); vsrefsstrs.push_back("vwg1nw;vwg1nc;vwg1ne;vwg2nw;vwg2nc;vwg2ne");
		lsrefs.push_back("l1"); vsrefsstrs.push_back("vwg1sw;vwg1sc;vwg1se;vwg2sw;vwg2sc;vwg2se");
		lsrefs.push_back("l2"); vsrefsstrs.push_back("vwg1nw;vwg1sw");
		lsrefs.push_back("l3"); vsrefsstrs.push_back("vwg1ne;vwg1se");
		lsrefs.push_back("l4"); vsrefsstrs.push_back("vwg2nw;vwg2sw");
		lsrefs.push_back("l5"); vsrefsstrs.push_back("vwg2ne;vwg2se");

		addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
	};

	// -- arc guides
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("vctr"); rs.push_back(r); vsrefsstrs.push_back("v2;v1;v2");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};
};

void PlnrExpDiscres::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool wg1
			, const bool wg2
			, const bool disc
			, const ubigint refSruWg
			, const ubigint refSruDisc
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

	if (disc) {
		strrefs.push_back(refSruDisc);
		fsrefs.push_back("f0");
		vsrefsstrs.push_back("v2;v1");
		rtesstrs.push_back("agd;agd");
		gsrefsstrs.push_back("a0;a0");
		dirsstrs.push_back("fwd;fwd");
	};

	if (wg1) {
		strrefs.push_back(refSruWg);
		fsrefs.push_back("f1");
		vsrefsstrs.push_back("vwg1se;vwg1ne;vwg1nw;vwg1sw");
		rtesstrs.push_back	("lgd;   lgd;   lgd;   lgd");
		gsrefsstrs.push_back("l3;    l0;    l2;    l1");
		dirsstrs.push_back	("bwd;   bwd;   fwd;   fwd");
	};

	if (wg2) {
		strrefs.push_back(refSruWg);
		fsrefs.push_back("f2");
		vsrefsstrs.push_back("vwg2se;vwg2ne;vwg2nw;vwg2sw");
		rtesstrs.push_back	("lgd;   lgd;   lgd;   lgd");
		gsrefsstrs.push_back("l5;    l0;    l4;    l1");
		dirsstrs.push_back	("bwd;   bwd;   fwd;   fwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


