/**
  * \file PlnrExpRtresneg.cpp
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

#include "PlnrExpRtresneg.h"

DpchRetPlnr* PlnrExpRtresneg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpRtresneg* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	bool wg20 = true; bool wg2;
	double ridgew0 = 0.3; double ridgew;
	double r0 = 5.0; double r;
	double cpllen0 = 10.0; double cpllen;
	double dist0 = 0.3; double dist;
	double clr0 = 2.0; double clr;

	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "wg2", wg20);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cpllen", cpllen0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "dist", dist0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "clr", clr0);

	// -- expand baseline
	wg2 = wg20;
	ridgew = ridgew0;
	r = r0;
	cpllen = cpllen0;
	dist = dist0;
	clr = clr0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, ridgew, r, cpllen, dist, clr, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, ridgew, r, clr, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, wg2, refSruAll, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		wg2 = wg20;
		ridgew = ridgew0;
		r = r0;
		cpllen = cpllen0;
		dist = dist0;
		clr = clr0;

		modpar = 0;

		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "wg2", wg2)) modpar += _WG2;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cpllen", cpllen)) modpar += _CPLLEN;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "dist", dist)) modpar += _DIST;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "clr", clr)) modpar += _CLR;

		// dto/dnoto modifications, arcguides; dto (wg2) affects faces only
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _WG2) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::FCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & (_RIDGEW + _R + _CPLLEN + _DIST + _CLR)) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, ridgew, r, cpllen, dist, clr, vtxs); // NOTO
		if (modpar & _R) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, ridgew, r, clr, vtxs, lgs, ags); // NOTO
		if (modpar & _WG2) { // FCE
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, wg2, refSruAll, vtxs, lgs, ags, fces2);
			fces2.clear();
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpRtresneg::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double ridgew
			, const double r
			, const double cpllen
			, const double dist
			, const double clr
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - w center line vertices (e are flipped copies of w)
	vsrefs.push_back("v1"); vxs.push_back(-(r+0.5*ridgew+clr)); vys.push_back(0.0);
	vsrefs.push_back("v2"); vxs.push_back(-(r+0.5*ridgew+dist)); vys.push_back(0.0);
	vsrefs.push_back("v3"); vxs.push_back(-(r+0.5*ridgew)); vys.push_back(0.0);
	vsrefs.push_back("v4"); vxs.push_back(-(r-0.5*ridgew)); vys.push_back(0.0);
	vsrefs.push_back("v5"); vxs.push_back(-(r-0.5*ridgew-clr)); vys.push_back(0.0);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=1;i<=5;i++) {
			if ( (((i == 1) || (i == 5))  && (modpar & (_R + _RIDGEW + _CLR)))
							|| ((i == 2)  && (modpar & (_R + _RIDGEW + _DIST)))
							|| (((i == 3) || (i == 4)) && (modpar & (_R + _RIDGEW))) )
				addVertexXYByVsref(dbsplnr, vsrefs[i-1], x1RefPlnrMDesign, vxs[i-1], vys[i-1], vtxs);
		};
	};

	// e (w /x)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=5;i++) {
			str.str(""); str << "v" << (i+5);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], 0.0, vtxs);
		};

	} else {
		for (unsigned int i=1;i<=5;i++) {
			str.str(""); str << "v" << (i+5);
			if ( (((i == 1) || (i == 5))  && (modpar & (_R + _RIDGEW + _CLR)))
							|| ((i == 2)  && (modpar & (_R + _RIDGEW + _DIST)))
							|| (((i == 3) || (i == 4)) && (modpar & (_R + _RIDGEW))) )
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], 0.0, vtxs);
		};
	};

	// - arc center vertices
	if (x1RefPlnrMDesign == 0) {
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v11", 0.0, 0.5*cpllen, vtxs);
		addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v12", 0.0, -0.5*cpllen, vtxs);

	} else {
		if (modpar & _CPLLEN) {
			addVertexXYByVsref(dbsplnr, "v11", x1RefPlnrMDesign, 0.0, 0.5*cpllen, vtxs);
			addVertexXYByVsref(dbsplnr, "v12", x1RefPlnrMDesign, 0.0, -0.5*cpllen, vtxs);
		};
	};

	// - nw vertices
	vsrefs.resize(0);
	vxs.resize(0);
	vys.resize(0);

	vsrefs.push_back("v13"); vxs.push_back(-(r+0.5*ridgew+clr)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v14"); vxs.push_back(-(r+0.5*ridgew)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v15"); vxs.push_back(-(r-0.5*ridgew)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v16"); vxs.push_back(-(r-0.5*ridgew-clr)); vys.push_back(0.5*cpllen);
	vsrefs.push_back("v17"); vxs.push_back(-(r+0.5*ridgew+dist)); vys.push_back(0.5*cpllen+sqrt( (r+0.5*ridgew+clr)*(r+0.5*ridgew+clr) - (r+0.5*ridgew+dist)*(r+0.5*ridgew+dist) ));
	vsrefs.push_back("v18"); vxs.push_back(-(r+0.5*ridgew+dist-clr)); vys.push_back(0.5*cpllen+sqrt( (r+0.5*ridgew+clr)*(r+0.5*ridgew+clr) - (-(r+0.5*ridgew+dist)+clr)*(-(r+0.5*ridgew+dist)+clr) ));
	vsrefs.push_back("v19"); vxs.push_back(-(r+0.5*ridgew+dist-clr)); vys.push_back(0.5*cpllen+r+0.5*ridgew+clr);
	vsrefs.push_back("v20"); vxs.push_back(-(r+0.5*ridgew+dist+ridgew+clr)); vys.push_back(0.5*cpllen+r+0.5*ridgew+clr);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=13;i<=20;i++) {
			if ( (((i == 13) || (i == 16))  && (modpar & (_R + _RIDGEW + _CLR + _CPLLEN)))
							|| (((i == 14) || (i == 15))  && (modpar & (_R + _RIDGEW + _CPLLEN)))
							|| ((i == 17) || (i == 18) || (i == 19) || (i == 20)) )
				addVertexXYByVsref(dbsplnr, vsrefs[i-13], x1RefPlnrMDesign, vxs[i-13], vys[i-13], vtxs);
		};
	};

	// ne (nw /x)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+8);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-13], vys[i-13], vtxs);
		};

	} else {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+8);
			if ( (((i == 13) || (i == 16))  && (modpar & (_R + _RIDGEW + _CLR + _CPLLEN)))
							|| (((i == 14) || (i == 15))  && (modpar & (_R + _RIDGEW + _CPLLEN)))
							|| ((i == 17) || (i == 18) || (i == 19) || (i == 20)) )
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-13], vys[i-13], vtxs);
		};
	};

	// sw (nw /y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+16);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vxs[i-13], -vys[i-13], vtxs);
		};

	} else {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+16);
			if ( (((i == 13) || (i == 16))  && (modpar & (_R + _RIDGEW + _CLR + _CPLLEN)))
							|| (((i == 14) || (i == 15))  && (modpar & (_R + _RIDGEW + _CPLLEN)))
							|| ((i == 17) || (i == 18) || (i == 19) || (i == 20)) )
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, vxs[i-13], -vys[i-13], vtxs);
		};
	};

	// se (nw /x/y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+24);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-13], -vys[i-13], vtxs);
		};

	} else {
		for (unsigned int i=13;i<=20;i++) {
			str.str(""); str << "v" << (i+24);
			if ( (((i == 13) || (i == 16))  && (modpar & (_R + _RIDGEW + _CLR + _CPLLEN)))
							|| (((i == 14) || (i == 15))  && (modpar & (_R + _RIDGEW + _CPLLEN)))
							|| ((i == 17) || (i == 18) || (i == 19) || (i == 20)) )
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-13], -vys[i-13], vtxs);
		};
	};

	// - waveguide connector vertices
	vsrefs.resize(0);
	vxs.resize(0);
	vys.resize(0);

	vsrefs.push_back("vwg1nw"); vxs.push_back(-(r+0.5*ridgew+dist+ridgew)); vys.push_back(0.5*cpllen+r+0.5*ridgew+clr);
	vsrefs.push_back("vwg1nc"); vxs.push_back(-(r+0.5*ridgew+dist+0.5*ridgew)); vys.push_back(0.5*cpllen+r+0.5*ridgew+clr);
	vsrefs.push_back("vwg1ne"); vxs.push_back(-(r+0.5*ridgew+dist)); vys.push_back(0.5*cpllen+r+0.5*ridgew+clr);

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
		addVertexXYs(dbsplnr, vsrefs, x1RefPlnrMDesign, vxs, vys, vtxs);
	};
};

void PlnrExpRtresneg::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double ridgew
			, const double r
			, const double clr
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
		lsrefs.push_back("l0"); vsrefsstrs.push_back("v20;v36");
		lsrefs.push_back("l1"); vsrefsstrs.push_back("vwg1nw;vwg1sw");
		lsrefs.push_back("l2"); vsrefsstrs.push_back("v13;v1;v29");
		lsrefs.push_back("l3"); vsrefsstrs.push_back("vwg1ne;v17;v2;v33;vwg1se");
		lsrefs.push_back("l4"); vsrefsstrs.push_back("v14;v3;v30");
		lsrefs.push_back("l5"); vsrefsstrs.push_back("v19;v18;v34;v35");
		lsrefs.push_back("l6"); vsrefsstrs.push_back("v15;v4;v31");
		lsrefs.push_back("l7"); vsrefsstrs.push_back("v16;v5;v32");
		lsrefs.push_back("l8"); vsrefsstrs.push_back("v24;v10;v40");
		lsrefs.push_back("l9"); vsrefsstrs.push_back("v23;v9;v39");
		lsrefs.push_back("l10"); vsrefsstrs.push_back("v27;v26;v42;v43");
		lsrefs.push_back("l11"); vsrefsstrs.push_back("v22;v8;v38");
		lsrefs.push_back("l12"); vsrefsstrs.push_back("vwg2nw;v25;v7;v41;vwg2sw");
		lsrefs.push_back("l13"); vsrefsstrs.push_back("v21;v6;v37");
		lsrefs.push_back("l14"); vsrefsstrs.push_back("vwg2ne;vwg2se");
		lsrefs.push_back("l15"); vsrefsstrs.push_back("v28;v44");
		lsrefs.push_back("l16"); vsrefsstrs.push_back("v20;vwg1nw;vwg1nc;vwg1ne;v19;v27;vwg2nw;vwg2nc;vwg2ne;v28");
		lsrefs.push_back("l17"); vsrefsstrs.push_back("v1;v2;v3;v4;v5;vctr;v10;v9;v8;v7;v6");
		lsrefs.push_back("l18"); vsrefsstrs.push_back("v36;vwg1sw;vwg1sc;vwg1se;v35;v43;vwg2sw;vwg2sc;vwg2se;v44");

		addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
	};

	// -- arc guides
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v11"); rs.push_back(r-0.5*ridgew-clr); vsrefsstrs.push_back("v24;v16");
	asrefs.push_back("a1"); vsrefs.push_back("v11"); rs.push_back(r-0.5*ridgew); vsrefsstrs.push_back("v23;v15");
	asrefs.push_back("a2"); vsrefs.push_back("v11"); rs.push_back(r+0.5*ridgew); vsrefsstrs.push_back("v22;v14");
	asrefs.push_back("a3"); vsrefs.push_back("v11"); rs.push_back(r+0.5*ridgew+clr); vsrefsstrs.push_back("v21;v25;v26;v18;v17;v13");
	asrefs.push_back("a4"); vsrefs.push_back("v12"); rs.push_back(r-0.5*ridgew-clr); vsrefsstrs.push_back("v32;v40");
	asrefs.push_back("a5"); vsrefs.push_back("v12"); rs.push_back(r-0.5*ridgew); vsrefsstrs.push_back("v31;v39");
	asrefs.push_back("a6"); vsrefs.push_back("v12"); rs.push_back(r+0.5*ridgew); vsrefsstrs.push_back("v30;v38");
	asrefs.push_back("a7"); vsrefs.push_back("v12"); rs.push_back(r+0.5*ridgew+clr); vsrefsstrs.push_back("v29;v33;v34;v42;v41;v37");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};
};

void PlnrExpRtresneg::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool wg2
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
	if (wg2) {
		vsrefsstrs.push_back("v7; v25;v17;v2; v3; v14;v22;v8");
		rtesstrs.push_back	("lgd;agd;lgd;lgd;lgd;agd;lgd;lgd");
		gsrefsstrs.push_back("l12;a3; l3; l17;l4; a2; l11;l17");
		dirsstrs.push_back	("bwd;fwd;fwd;fwd;bwd;bwd;fwd;fwd");
	} else {
		vsrefsstrs.push_back("v6; v21;v17;v2; v3; v14;v22;v8");
		rtesstrs.push_back	("lgd;agd;lgd;lgd;lgd;agd;lgd;lgd");
		gsrefsstrs.push_back("l13;a3; l3; l17;l4; a2; l11;l17");
		dirsstrs.push_back	("bwd;fwd;fwd;fwd;bwd;bwd;fwd;fwd");
	};

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v9; v23;v15;v4; v5; v16;v24;v10");
	rtesstrs.push_back	("lgd;agd;lgd;lgd;lgd;agd;lgd;lgd");
	gsrefsstrs.push_back("l9; a1; l6; l17;l7; a0; l8; l17");
	dirsstrs.push_back	("bwd;fwd;fwd;fwd;bwd;bwd;fwd;fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f2");
	vsrefsstrs.push_back("v9; v10;v40;v32;v5; v4; v31;v39");
	rtesstrs.push_back	("lgd;lgd;agd;lgd;lgd;lgd;agd;lgd");
	gsrefsstrs.push_back("l17;l8; a4; l7; l17;l6; a5; l9");
	dirsstrs.push_back	("bwd;fwd;bwd;bwd;bwd;fwd;fwd;fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f3");
	if (wg2) {
		vsrefsstrs.push_back("v7; v8; v38;v30;v3; v2; v33;v41");
		rtesstrs.push_back	("lgd;lgd;agd;lgd;lgd;lgd;agd;lgd");
		gsrefsstrs.push_back("l17;l11;a6; l4; l17;l3; a7; l12");
		dirsstrs.push_back	("bwd;fwd;bwd;bwd;bwd;fwd;fwd;fwd");
	} else {
		vsrefsstrs.push_back("v6; v8; v38;v30;v3; v2; v33;v37");
		rtesstrs.push_back	("lgd;lgd;agd;lgd;lgd;lgd;agd;lgd");
		gsrefsstrs.push_back("l17;l11;a6; l4; l17;l3; a7; l13");
		dirsstrs.push_back	("bwd;fwd;bwd;bwd;bwd;fwd;fwd;fwd");
	};

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f4");
	vsrefsstrs.push_back("vwg1nw;v20;v36;vwg1sw");
	rtesstrs.push_back	("lgd;   lgd;lgd;lgd");
	gsrefsstrs.push_back("l16;   l0; l18;l1");
	dirsstrs.push_back	("bwd;   fwd;fwd;bwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f5");
	vsrefsstrs.push_back("v18;v19;vwg1ne;v17");
	rtesstrs.push_back	("lgd;lgd;lgd;   agd");
	gsrefsstrs.push_back("l5; l16;l3;    a3");
	dirsstrs.push_back	("bwd;bwd;fwd;   bwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f6");
	vsrefsstrs.push_back("v34;v33;vwg1se;v35");
	rtesstrs.push_back	("agd;lgd;lgd;   lgd");
	gsrefsstrs.push_back("a7; l3; l18;   l5");
	dirsstrs.push_back	("bwd;fwd;fwd;   bwd");

	if (wg2) {
		strrefs.push_back(refSruAll);
		fsrefs.push_back("f7");
		vsrefsstrs.push_back("vwg2ne;v28;v44;vwg2se");
		rtesstrs.push_back	("lgd;   lgd;lgd;lgd");
		gsrefsstrs.push_back("l16;   l15;l18;l14");
		dirsstrs.push_back	("fwd;   fwd;bwd;bwd");

		strrefs.push_back(refSruAll);
		fsrefs.push_back("f8");
		vsrefsstrs.push_back("v25;vwg2nw;v27;v26");
		rtesstrs.push_back	("lgd;lgd;   lgd;agd");
		gsrefsstrs.push_back("l12;l16;   l10;a3");
		dirsstrs.push_back	("bwd;bwd;   fwd;bwd");

		strrefs.push_back(refSruAll);
		fsrefs.push_back("f9");
		vsrefsstrs.push_back("v41;v42;v43;vwg2sw");
		rtesstrs.push_back	("agd;lgd;lgd;lgd");
		gsrefsstrs.push_back("a7; l10;l18;l12");
		dirsstrs.push_back	("bwd;fwd;fwd;bwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


