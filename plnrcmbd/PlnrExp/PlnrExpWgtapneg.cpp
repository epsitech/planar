/**
  * \file PlnrExpWgtapneg.cpp
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

#include "PlnrExpWgtapneg.h"

DpchRetPlnr* PlnrExpWgtapneg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgtapneg* dpchinv
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
	double l0 = 50.0; double l;
	double tapstart0 = 0.55; double tapstart;
	double tapstop0 = 5.0; double tapstop;
	double clr0 = 2.0; double clr;
	bool rectbox0 = false; bool rectbox;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "l", l0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "tapstart", tapstart0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "tapstop", tapstop0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "clr", clr0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "rectbox", rectbox0);

	// --- expand baseline
	l = l0;
	tapstart = tapstart0;
	tapstop = tapstop0;
	clr = clr0;
	rectbox = rectbox0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, l, tapstart, tapstop, clr, rectbox, vtxs);
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
		tapstart = tapstart0;
		tapstop = tapstop0;
		clr = clr0;
		rectbox = rectbox0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "l", l)) modpar += _L;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "tapstart", tapstart)) modpar += _TAPSTART;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "tapstop", tapstop)) modpar += _TAPSTOP;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "clr", clr)) modpar += _CLR;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "rectbox", rectbox)) modpar += _RECTBOX;

		// dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, l, tapstart, tapstop, clr, rectbox, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpWgtapneg::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double l
			, const double tapstart
			, const double tapstop
			, const double clr
			, const bool rectbox
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	double xmax;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - connector vertices
	if (tapstart > tapstop) xmax = 0.5*tapstart+clr; else xmax = 0.5*tapstop+clr;

	vsrefs.push_back("v1"); if (rectbox) vxs.push_back(-xmax); else vxs.push_back(-(0.5*tapstop+clr)); vys.push_back(0.5*l);
	vsrefs.push_back("vstow"); vxs.push_back(-0.5*tapstop); vys.push_back(0.5*l);
	vsrefs.push_back("vstoc"); vxs.push_back(0.0); vys.push_back(0.5*l);
	vsrefs.push_back("vstoe"); vxs.push_back(0.5*tapstop); vys.push_back(0.5*l);
	vsrefs.push_back("v2"); if (rectbox) vxs.push_back(xmax); else vxs.push_back(0.5*tapstop+clr); vys.push_back(0.5*l);

	vsrefs.push_back("v3"); if (rectbox) vxs.push_back(-xmax); else vxs.push_back(-(0.5*tapstart+clr)); vys.push_back(-vys[0]);
	vsrefs.push_back("vstaw"); vxs.push_back(-0.5*tapstart); vys.push_back(-vys[1]);
	vsrefs.push_back("vstac"); vxs.push_back(vxs[2]); vys.push_back(-vys[2]);
	vsrefs.push_back("vstae"); vxs.push_back(0.5*tapstart); vys.push_back(-vys[3]);
	vsrefs.push_back("v4"); if (rectbox) vxs.push_back(xmax); else vxs.push_back(0.5*tapstart+clr); vys.push_back(-vys[4]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=0;i<10;i++)
			if ( (modpar & _L) || (((i == 1) || (i == 3)) && (modpar & _TAPSTOP)) || (((i == 6) || (i == 7)) && (modpar & _TAPSTART))
						|| (i == 0) || (i == 4) || (i == 5) || (i == 9) )
				addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
	};
};

void PlnrExpWgtapneg::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	// -- line guides
	lsrefs.push_back("l0"); vsrefsstrs.push_back("v1;vstow;vstoc;vstoe;v2");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("v3;vstaw;vstac;vstae;v4");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("v1;v3");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("vstow;vstaw");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("vstoe;vstae");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("v2;v4");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpWgtapneg::faces(
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
	vsrefsstrs.push_back("vstaw;vstow;v1; v3");
	rtesstrs.push_back	("lgd;  lgd;  lgd;lgd");
	gsrefsstrs.push_back("l3;   l0;   l2;   l1");
	dirsstrs.push_back	("bwd;  bwd;  fwd;  fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v4; v2; vstoe;vstae");
	rtesstrs.push_back	("lgd;lgd;lgd;  lgd");
	gsrefsstrs.push_back("l5; l0; l4;   l1");
	dirsstrs.push_back	("bwd;bwd;fwd;  fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


