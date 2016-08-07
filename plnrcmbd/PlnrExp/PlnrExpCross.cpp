/**
  * \file PlnrExpCross.cpp
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

#include "PlnrExpCross.h"

DpchRetPlnr* PlnrExpCross::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpCross* dpchinv
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
	double size0 = 20.0; double size;
	double narrw0 = 2.0; double narrw;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "narrw", narrw0);

	// --- expand baseline
	size = size0;
	narrw = narrw0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, size, narrw, vtxs);
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
		narrw = narrw0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "size", size)) modpar += _SIZE;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "narrw", narrw)) modpar += _NARRW;

		// dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar != 0) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, size, narrw, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpCross::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double size
			, const double narrw
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	// center vertex
	if (x1RefPlnrMDesign == 0) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// -- nw vertices (ne, sw and se are flipped copies of nw)

	// x,y positions
	vsrefs.push_back("v1"); vxs.push_back(-0.5*size); vys.push_back(narrw);
	vsrefs.push_back("v2"); vxs.push_back(-0.5*2.0*size/3.0); vys.push_back(narrw);
	vsrefs.push_back("v3"); vxs.push_back(-0.5*2.0*size/3.0); vys.push_back(0.5*narrw);
	vsrefs.push_back("v4"); vxs.push_back(-0.5*size/3.0); vys.push_back(0.5*narrw);
	vsrefs.push_back("v5"); vxs.push_back(-0.5*size/3.0); vys.push_back(narrw);
	vsrefs.push_back("v6"); vxs.push_back(-narrw); vys.push_back(narrw);
	vsrefs.push_back("v7"); vxs.push_back(-narrw); vys.push_back(0.5*size/3.0);
	vsrefs.push_back("v8"); vxs.push_back(-0.5*narrw); vys.push_back(0.5*size/3.0);
	vsrefs.push_back("v9"); vxs.push_back(-0.5*narrw); vys.push_back(0.5*2.0*size/3.0);
	vsrefs.push_back("v10"); vxs.push_back(-narrw); vys.push_back(0.5*2.0*size/3.0);
	vsrefs.push_back("v11"); vxs.push_back(-narrw); vys.push_back(0.5*size);

	if (x1RefPlnrMDesign == 0) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);

	} else {
		for (unsigned int i=1;i<=11;i++) {
			if ((i != 6) || ((i == 6) && (modpar & _NARRW))) addVertexXYByVsref(dbsplnr, vsrefs[i-1], x1RefPlnrMDesign, vxs[i-1], vys[i-1], vtxs);
		};
	};

	// -- ne (nw /x)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+11);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+11);
			if ((i != 6) || ((i == 6) && (modpar & _NARRW))) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], vys[i-1], vtxs);
		};
	};

	// -- sw (nw /y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+22);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+22);
			if ((i != 6) || ((i == 6) && (modpar & _NARRW))) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, vxs[i-1], -vys[i-1], vtxs);
		};
	};

	// -- se (nw /x/y)
	if (x1RefPlnrMDesign == 0) {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+33);
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -vxs[i-1], -vys[i-1], vtxs);
		};

	} else {
		for (unsigned int i=1;i<=11;i++) {
			str.str(""); str << "v" << (i+33);
			if ((i != 6) || ((i == 6) && (modpar & _NARRW))) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -vxs[i-1], -vys[i-1], vtxs);
		};
	};
};

void PlnrExpCross::guides(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	lsrefs.push_back("l0"); vsrefsstrs.push_back("v11;v22");
	lsrefs.push_back("l1"); vsrefsstrs.push_back("v10;v9;v20;v21");
	lsrefs.push_back("l2"); vsrefsstrs.push_back("v7;v8;v19;v18");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("v1;v2;v5;v6;v17;v16;v13;v12");
	lsrefs.push_back("l4"); vsrefsstrs.push_back("v3;v4;v15;v14");
	lsrefs.push_back("l5"); vsrefsstrs.push_back("v25;v26;v37;v36");
	lsrefs.push_back("l6"); vsrefsstrs.push_back("v23;v24;v27;v28;v39;v38;v35;v34");
	lsrefs.push_back("l7"); vsrefsstrs.push_back("v29;v30;v41;v40");
	lsrefs.push_back("l8"); vsrefsstrs.push_back("v32;v31;v42;v43");
	lsrefs.push_back("l9"); vsrefsstrs.push_back("v33;v44");
	lsrefs.push_back("l10"); vsrefsstrs.push_back("v1;v23");
	lsrefs.push_back("l11"); vsrefsstrs.push_back("v2;v3;v25;v24");
	lsrefs.push_back("l12"); vsrefsstrs.push_back("v5;v4;v26;v27");
	lsrefs.push_back("l13"); vsrefsstrs.push_back("v11;v10;v7;v6;v28;v29;v32;v33");
	lsrefs.push_back("l14"); vsrefsstrs.push_back("v9;v8;v30;v31");
	lsrefs.push_back("l15"); vsrefsstrs.push_back("v20;v19;v41;v42");
	lsrefs.push_back("l16"); vsrefsstrs.push_back("v22;v21;v18;v17;v39;v40;v43;v44");
	lsrefs.push_back("l17"); vsrefsstrs.push_back("v16;v15;v37;v38");
	lsrefs.push_back("l18"); vsrefsstrs.push_back("v13;v14;v36;v35");
	lsrefs.push_back("l19"); vsrefsstrs.push_back("v12;v34");

	addLineguides(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpCross::faces(
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
	vsrefsstrs.push_back("v1; v2; v3; v4; v5; v6; v7; v8; v9; v10;v11;v22;v21;v20;v19;v18;v17;v16;v15;v14;v13;v12;v34;v35;v36;v37;v38;v39;v40;v41;v42;v43;v44;v33;v32;v31;v30;v29;v28;v27;v26;v25;v24;v23");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l3; l11;l4; l12;l3; l13;l2; l14;l1; l13;l0; l16;l1; l15;l2; l16;l3; l17;l4; l18;l3; l19;l6; l18;l5; l17;l6; l16;l7; l15;l8; l16;l9; l13;l8; l14;l7; l13;l6; l12;l5; l11;l6; l10");
	dirsstrs.push_back	("fwd;fwd;fwd;bwd;fwd;bwd;fwd;bwd;bwd;bwd;fwd;fwd;bwd;fwd;fwd;fwd;fwd;fwd;fwd;bwd;fwd;fwd;bwd;bwd;bwd;fwd;bwd;fwd;bwd;fwd;fwd;fwd;bwd;bwd;fwd;bwd;bwd;bwd;bwd;bwd;bwd;fwd;bwd;bwd");

	addFaces(dbsplnr, 0, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


