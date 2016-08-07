/**
  * \file PlnrExpPie.cpp
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

#include "PlnrExpPie.h"

DpchRetPlnr* PlnrExpPie::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPie* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMArcguide ags, ags2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double r0 = 50.0; double r;
	int slcN0 = 8; int slcN;
	double cd0 = 1.0; double cd;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "slcN", slcN0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cd", cd0);

	// --- expand baseline
	r = r0;
	slcN = slcN0;
	cd = cd0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, r, slcN, cd, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, false, 0, r, slcN, cd, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, slcN, refSruAll, vtxs, lgs, ags, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		r = r0;
		slcN = slcN0;
		cd = cd0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "slcN", slcN)) modpar += _SLCN;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cd", cd)) modpar += _CD;

		// dto/dnoto modifications, arcguides; dto (slcN) affects vertices, guides, faces
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _SLCN) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & _SLCN) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, r, slcN, cd, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, r, slcN, cd, vtxs2, lgs2, ags2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, slcN, refSruAll, vtxs2, lgs2, ags2, fces2);

			vtxs2.clear();
			lgs2.clear();
			ags2.clear();
			fces2.clear();

		} else if (modpar & (_R + _CD)) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, r, slcN, cd, vtxs);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, r, slcN, cd, vtxs, lgs, ags);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpPie::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double r
			, const int slcN
			, const double cd
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	double dphi, ri;

	dphi = pi / ((double) slcN);
	ri = cd / dphi;

	// center vertex
	if (!xyonly) addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// circle vertices
	for (int i=0 ; i<(2*slcN) ; i++) {
		str.str(""); str << "vi" << i;
		if (!xyonly) {
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), ri*cos(((double) i) * dphi), ri*sin(((double) i) * dphi), vtxs);
		} else {
			if (modpar & _CD) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, ri*cos(((double) i) * dphi), ri*sin(((double) i) * dphi), vtxs);
		};

		str.str(""); str << "vo" << i;
		if (!xyonly) {
			addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), r*cos(((double) i) * dphi), r*sin(((double) i) * dphi), vtxs);
		} else {
			if (modpar & _R) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, r*cos(((double) i) * dphi), r*sin(((double) i) * dphi), vtxs);
		}
	};
};

void PlnrExpPie::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool ronly
			, const unsigned int modpar
			, const double r
			, const int slcN
			, const double cd
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str;

	vector<unsigned int> vics;

	double dphi, ri;

	dphi = pi / ((double) slcN);
	ri = cd / dphi;

	if (!ronly) {
		// -- radial lineguides (spokes)
		vics.resize(2);

		for (int i=0 ; i<(2*slcN) ; i++) {
			vics[0] = 1 + 2*i;
			vics[1] = 1 + 2*i+1;

			str.str(""); str << "l" << i;
			addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vics, vtxs, lgs);
		};
	};

	// -- inner and outer circle arcguides
	if (!ronly) {
		vics.resize(2*slcN + 1);

		for (int i=0 ; i<(2*slcN) ; i++) vics[i] = 1 + 2*i;
		vics[2*slcN] = 1;

		addArcguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, "ai", 0, ri, vics, vtxs, ags);

		for (int i=0 ; i<(2*slcN) ; i++) vics[i] = 1 + 2*i + 1;
		vics[2*slcN] = 1 + 1;

		addArcguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, "ao", 0, r, vics, vtxs, ags);

	} else {
		if (modpar & _CD) addArcguideRByAsref(dbsplnr, "ai", x1RefPlnrMDesign, ri, ags);
		if (modpar & _R) addArcguideRByAsref(dbsplnr, "ao", x1RefPlnrMDesign, r, ags);
	};
};

void PlnrExpPie::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int slcN
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	for (int i=0 ; i<slcN ; i++) {
		strrefs.push_back(refSruAll);

		str.str(""); str << "f" << i;
		fsrefs.push_back(str.str());

		str.str("");
		str << "vi" << (2*i) << ";";
		str << "vo" << (2*i) << ";";
		str << "vo" << (2*i+1) << ";";
		str << "vi" << (2*i+1);
		vsrefsstrs.push_back(str.str());

		rtesstrs.push_back("lgd;agd;lgd;agd");

		str.str("");
		str << "l" << (2*i) << ";";
		str << "ao;";
		str << "l" << (2*i+1) << ";";
		str << "ai";
		gsrefsstrs.push_back(str.str());

		dirsstrs.push_back("fwd;fwd;bwd;bwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


