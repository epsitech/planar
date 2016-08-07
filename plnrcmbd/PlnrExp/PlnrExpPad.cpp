/**
  * \file PlnrExpPad.cpp
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

#include "PlnrExpPad.h"

DpchRetPlnr* PlnrExpPad::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPad* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruMet = 0;
	ubigint refSruIns = 0;
	ubigint refSruBump = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMLineguide lgs;
	ListPlnrMArcguide ags;
	ListPlnrMFace fces;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "met", refSruMet);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "ins", refSruIns);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "bump", refSruBump);

	// load baseline parameters
	double size0 = 100.0; double size;
	double clr0 = 5.0; double clr;
	double olp0 = 5.0; double olp;
	double bumpd0 = 50.0; double bumpd;
	double bumpofsx0 = 0.0; double bumpofsx;
	double bumpofsy0 = 0.0; double bumpofsy;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "clr", clr0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "olp", olp0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpd", bumpd0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpofsx", bumpofsx0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "bumpofsy", bumpofsy0);

	// --- expand baseline
	size = size0;
	clr = clr0;
	olp = olp0;
	bumpd = bumpd0;
	bumpofsx = bumpofsx0;
	bumpofsy = bumpofsy0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, size, clr, olp, bumpd, bumpofsx, bumpofsy, vtxs);
	guides(dbsplnr, refPlnrMDevice, bumpd, vtxs, lgs, ags);
	faces(dbsplnr, refPlnrMDevice, refSruMet, refSruIns, refSruBump, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs
	// ...
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpPad::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double size
			, const double clr
			, const double olp
			, const double bumpd
			, const double bumpofsx
			, const double bumpofsy
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	vsrefs.push_back("vctr"); vxs.push_back(0.0); vys.push_back(0.0);

	// outer vertices (clr)
	vsrefs.push_back("va"); vxs.push_back(-(0.5*size-clr)); vys.push_back(-(0.5*size-clr));
	vsrefs.push_back("vb"); vxs.push_back(0.5*size-clr); vys.push_back(-(0.5*size-clr));
	vsrefs.push_back("vc"); vxs.push_back(0.5*size-clr); vys.push_back(0.5*size-clr);
	vsrefs.push_back("vd"); vxs.push_back(-(0.5*size-clr)); vys.push_back(0.5*size-clr);

	// inner vertices (olp)
	vsrefs.push_back("ve"); vxs.push_back(-(0.5*size-clr-olp)); vys.push_back(-(0.5*size-clr-olp));
	vsrefs.push_back("vf"); vxs.push_back(0.5*size-clr-olp); vys.push_back(-(0.5*size-clr-olp));
	vsrefs.push_back("vg"); vxs.push_back(0.5*size-clr-olp); vys.push_back(0.5*size-clr-olp);
	vsrefs.push_back("vh"); vxs.push_back(-(0.5*size-clr-olp)); vys.push_back(0.5*size-clr-olp);

	// bump
	vsrefs.push_back("v0"); vxs.push_back(bumpofsx); vys.push_back(bumpofsy);
	vsrefs.push_back("v1"); vxs.push_back(bumpofsx-0.5*bumpd); vys.push_back(bumpofsy);
	vsrefs.push_back("v2"); vxs.push_back(bumpofsx+0.5*bumpd); vys.push_back(bumpofsy);

	addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
};

void PlnrExpPad::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const double bumpd
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
	lsrefs.push_back("l0"); vsrefsstrs.push_back("vd;vc");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("vh;vg");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("ve;vf");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("va;vb");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("vd;va");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("ve;vh");
	lsrefs.push_back("l6"); vsrefsstrs.push_back("vg;vf");
	lsrefs.push_back("l7"); vsrefsstrs.push_back("vc;vb");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);

	// -- arc guides
	vsrefsstrs.resize(0);

	asrefs.push_back("a0"); vsrefs.push_back("v0"); rs.push_back(0.5*bumpd); vsrefsstrs.push_back("v1;v2;v1");

	addArcguides(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, asrefs, vsrefs, rs, vsrefsstrs, vtxs, ags);
};

void PlnrExpPad::faces(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint refSruMet
			, const ubigint refSruIns
			, const ubigint refSruBump
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

	strrefs.push_back(refSruMet);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("va; vb; vc; vd");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l3; l7; l0; l4");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	strrefs.push_back(refSruIns);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("ve; vf; vg; vh");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l2; l6; l1; l5");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd");

	strrefs.push_back(refSruBump);
	fsrefs.push_back("f2");
	vsrefsstrs.push_back("v1; v2");
	rtesstrs.push_back	("agd;agd");
	gsrefsstrs.push_back("a0; a0");
	dirsstrs.push_back	("fwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


