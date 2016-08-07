/**
  * \file PlnrExpGratcpl.cpp
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

#include "PlnrExpGratcpl.h"

DpchRetPlnr* PlnrExpGratcpl::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpGratcpl* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruWg = 0;
	ubigint refSruGrat = 0;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "wg", refSruWg);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "grat", refSruGrat);

	// load baseline parameters
	double ridgew0 = 5.0; double ridgew;
	double prd0 = 0.7; double prd;
	double fill0 = 0.8; double fill;
	int N0 = 40; int N;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "ridgew", ridgew0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "prd", prd0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "fill", fill0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "N", N0);

	// --- expand baseline
	ridgew = ridgew0;
	prd = prd0;
	fill = fill0;
	N = N0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, ridgew, prd, fill, N, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, N, vtxs, lgs);
	faces(dbsplnr, 0, refPlnrMDevice, N, refSruWg, refSruGrat, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		ridgew = ridgew0;
		prd = prd0;
		fill = fill0;
		N = N0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "ridgew", ridgew)) modpar += _RIDGEW;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "prd", prd)) modpar += _PRD;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "fill", fill)) modpar += _FILL;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "N", N)) modpar += _N;

		// dto/dnoto modifications, no arcguides; dto (N) implies new set of vertices, guides and faces
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _N) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & _N) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, ridgew, prd, fill, N, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, N, vtxs2, lgs2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, N, refSruWg, refSruGrat, vtxs2, lgs2, fces2);

			vtxs2.clear();
			lgs2.clear();
			fces2.clear();

		} else {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, ridgew, prd, fill, N, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpGratcpl::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double ridgew
			, const double prd
			, const double fill
			, const int N
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	// grating period loop (a-b-...-a) ; will generate N*4+2 vertices
	for (int i=0;i<(N+1);i++) {
		str.str(""); str << "vwa" << i;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -0.5*ridgew, ((double) i)*prd, vtxs);
		else {
			if (modpar & (_RIDGEW + _PRD)) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -0.5*ridgew, ((double) i)*prd, vtxs);
		};

		str.str(""); str << "vea" << i;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), 0.5*ridgew, ((double) i)*prd, vtxs);
		else {
			if (modpar & (_RIDGEW + _PRD)) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, 0.5*ridgew, ((double) i)*prd, vtxs);
		};

		if (i != N) {
			str.str(""); str << "vwb" << i;
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), -0.5*ridgew, ((double) i)*prd + (1.0-fill)*prd, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, -0.5*ridgew, ((double) i)*prd + (1.0-fill)*prd, vtxs);

			str.str(""); str << "veb" << i;
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), 0.5*ridgew, ((double) i)*prd + (1.0-fill)*prd, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, 0.5*ridgew, ((double) i)*prd + (1.0-fill)*prd, vtxs);
		};
	};

	// special vertices: vs (ix:N*4+2), vn (ix:N*4+3)
	if (!xyonly) {
		addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vs", 0.0, 0.0, vtxs);
		addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vn", 0.0, ((double) N)*prd, vtxs);
	} else {
		if (modpar & _PRD) addVertexXYByVsref(dbsplnr, "vn", x1RefPlnrMDesign, 0.0, ((double) N)*prd, vtxs);
	};
};

void PlnrExpGratcpl::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int N
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;

	vector<unsigned int> vics;

	// -- line guides

	// - horizontal line guides
	for (int i=0;i<(N+1);i++) {
		// a
		str.str(""); str << "lha" << i;
		vics.resize(0);

		vics.push_back(i*4);
		if (i == 0) {
			vics.push_back(N*4+2);
		} else if (i == N) {
			vics.push_back(N*4+3);
		};
		vics.push_back(i*4+1);

		addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vics, vtxs, lgs);

		// b
		if (i != N) {
			str.str(""); str << "lhb" << i;
			vics.resize(0);

			vics.push_back(i*4+2);
			vics.push_back(i*4+3);

			addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), vics, vtxs, lgs);
		};
	};

	// - vertical line guides
	vics.resize(0);
	for (int i=N;i>=0;i--) {
		if (i != N) vics.push_back(i*4+2); // wb
		vics.push_back(i*4); // wa
	};
	addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "lvw", vics, vtxs, lgs);

	vics.resize(0);
	for (int i=N;i>=0;i--) {
		if (i != N) vics.push_back(i*4+3); // eb
		vics.push_back(i*4+1); // ea
	};
	addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "lve", vics, vtxs, lgs);
};

void PlnrExpGratcpl::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int N
			, const ubigint refSruWg
			, const ubigint refSruGrat
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	ListPlnrMArcguide ags;

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	// - single waveguide rect
	strrefs.push_back(refSruWg);
	fsrefs.push_back("fwg0");

	str.str(""); str << "vwa0;vea0;vea" << N << ";vwa" << N;
	vsrefsstrs.push_back(str.str());

	rtesstrs.push_back("lgd;lgd;lgd;lgd");

	str.str(""); str << "lha0;lve;lha" << N << ";lvw";
	gsrefsstrs.push_back(str.str());

	dirsstrs.push_back("fwd;bwd;bwd;fwd");

	// - grating element rect's
	for (int i=0;i<N;i++) {
		strrefs.push_back(refSruGrat);

		str.str(""); str << "fgrat" << i;
		fsrefs.push_back(str.str());

		str.str(""); str << "vwb" << i << ";veb" << i << ";vea" << (i+1) << ";vwa" << (i+1);
		vsrefsstrs.push_back(str.str());

		rtesstrs.push_back("lgd;lgd;lgd;lgd");

		str.str(""); str << "lhb" << i << ";lve;lha" << (i+1) << ";lvw";
		gsrefsstrs.push_back(str.str());

		dirsstrs.push_back("fwd;bwd;bwd;fwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


