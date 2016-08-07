/**
  * \file PlnrExpWgneg.cpp
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

#include "PlnrExpWgneg.h"

DpchRetPlnr* PlnrExpWgneg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgneg* dpchinv
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
	double ridgew0 = 0.5; double ridgew;
	double clr0 = 2.0; double clr;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "l", l0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "clr", clr0);

	// --- expand baseline
	l = l0;
	ridgew = ridgew0;
	clr = clr0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, l, ridgew, clr, vtxs);
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
		clr = clr0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "l", l)) modpar += _L;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "clr", clr)) modpar += _CLR;

		// dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, l, ridgew, clr, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpWgneg::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double l
			, const double ridgew
			, const double clr
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - connector vertices
	vsrefs.push_back("v1"); vxs.push_back(-(0.5*ridgew+clr)); vys.push_back(0.5*l); // ridgew, clr, l
	vsrefs.push_back("vnw"); vxs.push_back(-0.5*ridgew); vys.push_back(0.5*l); // ridgew, l
	vsrefs.push_back("vnc"); vxs.push_back(0.0); vys.push_back(0.5*l); // l
	vsrefs.push_back("vne"); vxs.push_back(0.5*ridgew); vys.push_back(0.5*l); // ridgew, l
	vsrefs.push_back("v2"); vxs.push_back(0.5*ridgew+clr); vys.push_back(0.5*l); // ridgew, clr, l

	// s (n /y)
	vsrefs.push_back("v3"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("vsw"); vxs.push_back(vxs[1]); vys.push_back(-vys[1]);
	vsrefs.push_back("vsc"); vxs.push_back(vxs[2]); vys.push_back(-vys[2]);
	vsrefs.push_back("vse"); vxs.push_back(vxs[3]); vys.push_back(-vys[3]);
	vsrefs.push_back("v4"); vxs.push_back(vxs[4]); vys.push_back(-vys[4]);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=0;i<10;i++)
			if ( (modpar & _L) || ((modpar & _RIDGEW) && ((i%5) != 2)) || ((modpar & _CLR) && (((i%5) == 0) || ((i%5) == 4))) )
				addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
	};
};

void PlnrExpWgneg::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	// -- line guides
	lsrefs.push_back("l0"); vsrefsstrs.push_back("v1;vnw;vnc;vne;v2");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("v3;vsw;vsc;vse;v4");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("v1;v3");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("vnw;vsw");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("vne;vse");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("v2;v4");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpWgneg::faces(
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
	vsrefsstrs.push_back("vsw;vnw;v1; v3");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l3; l0; l2; l1");
	dirsstrs.push_back	("bwd;bwd;fwd;fwd");

	strrefs.push_back(refSruAll);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v4; v2; vne;vse");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l5; l0; l4; l1");
	dirsstrs.push_back	("bwd;bwd;fwd;fwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


