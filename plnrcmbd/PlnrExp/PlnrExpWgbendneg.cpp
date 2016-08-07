/**
  * \file PlnrExpWgbendneg.cpp
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

#include "PlnrExpWgbendneg.h"

DpchRetPlnr* PlnrExpWgbendneg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgbendneg* dpchinv
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
	double phistart0 = 0.0; double phistart;
	double phistop0 = 90.0; double phistop;
	double r0 = 10.0; double r;
	double ridgew0 = 0.55; double ridgew;
	double clr0 = 2.0; double clr;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "phistart", phistart0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "phistop", phistop0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "clr", clr0);

	// --- expand baseline
	phistart = phistart0;
	phistop = phistop0;
	r = r0;
	ridgew = ridgew0;
	clr = clr0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, phistart, phistop, r, ridgew, clr, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, 0, r, ridgew, clr, vtxs, lgs, ags);
	faces(dbsplnr, refPlnrMDevice, refSruAll, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		phistart = phistart0;
		phistop = phistop0;
		r = r0;
		ridgew = ridgew0;
		clr = clr0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "phistart", phistart)) modpar += _PHISTART;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "phistop", phistop)) modpar += _PHISTOP;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "clr", clr)) modpar += _CLR;

		// dnoto modifications only, arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, phistart, phistop, r, ridgew, clr, vtxs);
			if (modpar & (_R + _RIDGEW + _CLR)) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, r, ridgew, clr, vtxs, lgs, ags);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpWgbendneg::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double phistart
			, const double phistop
			, const double r
			, const double ridgew
			, const double clr
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	double sphistart, cphistart;
	double sphistop, cphistop;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v0", 0.0, 0.0, vtxs);

	// - connector vertices
	sphistart = sin(2.0*pi*phistart/360.0);
	cphistart = cos(2.0*pi*phistart/360.0);
	sphistop = sin(2.0*pi*phistop/360.0);
	cphistop = cos(2.0*pi*phistop/360.0);

	// x,y positions
	vsrefs.push_back("v3"); vxs.push_back((r-0.5*ridgew-clr)*cphistart); vys.push_back((r-0.5*ridgew-clr)*sphistart);
	vsrefs.push_back("vsw"); vxs.push_back((r-0.5*ridgew)*cphistart); vys.push_back((r-0.5*ridgew)*sphistart);
	vsrefs.push_back("vsc"); vxs.push_back(r*cphistart); vys.push_back(r*sphistart);
	vsrefs.push_back("vse"); vxs.push_back((r+0.5*ridgew)*cphistart); vys.push_back((r+0.5*ridgew)*sphistart);
	vsrefs.push_back("v4"); vxs.push_back((r+0.5*ridgew+clr)*cphistart); vys.push_back((r+0.5*ridgew+clr)*sphistart);
	vsrefs.push_back("v1"); vxs.push_back((r-0.5*ridgew-clr)*cphistop); vys.push_back((r-0.5*ridgew-clr)*sphistop);
	vsrefs.push_back("vnw"); vxs.push_back((r-0.5*ridgew)*cphistop); vys.push_back((r-0.5*ridgew)*sphistop);
	vsrefs.push_back("vnc"); vxs.push_back(r*cphistop); vys.push_back(r*sphistop);
	vsrefs.push_back("vne"); vxs.push_back((r+0.5*ridgew)*cphistop); vys.push_back((r+0.5*ridgew)*sphistop);
	vsrefs.push_back("v2"); vxs.push_back((r+0.5*ridgew+clr)*cphistop); vys.push_back((r+0.5*ridgew+clr)*sphistop);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=1;i<=10;i++) {
			if ( (modpar & _R) || ((modpar & _PHISTART) && (i >= 1) && (i <= 5)) || ((modpar & _PHISTOP) && (i >= 6) && (i <= 10))
						|| ((modpar & _RIDGEW) && (i != 3) && (i != 8)) || ((modpar & _CLR) && (i == 1) && (i == 5) && (i == 6) && (i == 10)) ) 
				addVertexXYByVsref(dbsplnr, vsrefs[i-1], x1RefPlnrMDesign, vxs[i-1], vys[i-1], vtxs);
		};
	};
};

void PlnrExpWgbendneg::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double r
			, const double ridgew
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
		lsrefs.push_back("l0"); vsrefsstrs.push_back("v1;vnw;vnc;vne;v2");
		lsrefs.push_back("l1"); vsrefsstrs.push_back("v3;vsw;vsc;vse;v4");

		addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
	};

	// -- arc guides
	asrefs.resize(0);
	vsrefs.resize(0);
	rs.resize(0);
	vsrefsstrs.resize(0);

	asrefs.push_back("a1"); vsrefs.push_back("v0"); rs.push_back(r-0.5*ridgew); vsrefsstrs.push_back("vsw;vnw");
	asrefs.push_back("a2"); vsrefs.push_back("v0"); rs.push_back(r+0.5*ridgew); vsrefsstrs.push_back("vse;vne");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		if (modpar & (_RIDGEW + _R)) addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};

	asrefs.resize(0);
	vsrefs.resize(0);
	rs.resize(0);
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v0"); rs.push_back(r-0.5*ridgew-clr); vsrefsstrs.push_back("v3;v1");
	asrefs.push_back("a3"); vsrefs.push_back("v0"); rs.push_back(r+0.5*ridgew+clr); vsrefsstrs.push_back("v4;v2");

	if (x1RefPlnrMDesign == 0) {
		addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
	} else {
		addArcguideRs(dbsplnr, asrefs, x1RefPlnrMDesign, rs, ags);
	};
};

void PlnrExpWgbendneg::faces(
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
	vsrefsstrs.push_back("vsw;vnw;v1; v3");
	rtesstrs.push_back	("agd;lgd;agd;lgd");
	gsrefsstrs.push_back("a1; l0; a0; l1");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v4; v2; vne;vse");
	rtesstrs.push_back	("agd;lgd;agd;lgd");
	gsrefsstrs.push_back("a3; l0; a2; l1");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


