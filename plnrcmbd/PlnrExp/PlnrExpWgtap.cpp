/**
  * \file PlnrExpWgtap.cpp
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

#include "PlnrExpWgtap.h"

DpchRetPlnr* PlnrExpWgtap::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgtap* dpchinv
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

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "l", l0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "tapstart", tapstart0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "tapstop", tapstop0);

	// --- expand baseline
	l = l0;
	tapstart = tapstart0;
	tapstop = tapstop0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, l, tapstart, tapstop, vtxs);
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

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "l", l)) modpar += _L;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "tapstart", tapstart)) modpar += _TAPSTART;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "tapstop", tapstop)) modpar += _TAPSTOP;

		// dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, l, tapstart, tapstop, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpWgtap::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double l
			, const double tapstart
			, const double tapstop
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - connector vertices
	vsrefs.push_back("vstow"); vxs.push_back(-0.5*tapstop); vys.push_back(0.5*l);
	vsrefs.push_back("vstoc"); vxs.push_back(0.0); vys.push_back(0.5*l);
	vsrefs.push_back("vstoe"); vxs.push_back(0.5*tapstop); vys.push_back(0.5*l);

	vsrefs.push_back("vstaw"); vxs.push_back(-0.5*tapstart); vys.push_back(-vys[0]);
	vsrefs.push_back("vstac"); vxs.push_back(vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("vstae"); vxs.push_back(0.5*tapstart); vys.push_back(-vys[2]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=0;i<6;i++)
			if ( (modpar & _L) || (((i == 0) || (i == 2)) && (modpar & _TAPSTOP)) || (((i == 3) || (i == 5)) && (modpar & _TAPSTART)) )
				addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
	};
};

void PlnrExpWgtap::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	// -- line guides
	lsrefs.push_back("l0"); vsrefsstrs.push_back("vstow;vstoc;vstoe");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("vstaw;vstac;vstae");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("vstow;vstaw");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("vstoe;vstae");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpWgtap::faces(
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
	vsrefsstrs.push_back("vstae;vstoe;vstow;vstaw");
	rtesstrs.push_back	("lgd;  lgd;  lgd;  lgd");
	gsrefsstrs.push_back("l3;   l0;   l2;   l1");
	dirsstrs.push_back	("bwd;  bwd;  fwd;  fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


