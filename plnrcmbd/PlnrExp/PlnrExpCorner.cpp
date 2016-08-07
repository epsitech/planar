/**
  * \file PlnrExpCorner.cpp
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

#include "PlnrExpCorner.h"

DpchRetPlnr* PlnrExpCorner::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpCorner* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruPos = 0;
	ubigint refSruNeg = 0;
	ubigint refSruAlnpos = 0;
	ubigint refSruAlnneg = 0;
	ubigint refSruSprpos = 0;
	ubigint refSruSprneg = 0;

	ListPlnrMVertex vtxs;
	ListPlnrMVertex vtxs2;
	ListPlnrMLineguide lgs;
	ListPlnrMLineguide lgs2;
	ListPlnrMFace fces;
	ListPlnrMFace fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "pos", refSruPos);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "neg", refSruNeg);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "alnpos", refSruAlnpos);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "alnneg", refSruAlnneg);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "sprpos", refSruSprpos);
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "sprneg", refSruSprneg);

	// load baseline parameters
	double size0 = 20.0; double size;
	double w0 = 3.0; double w;
	bool sq0 = true; bool sq;
	double alnclr0 = 1.0; double alnclr;
	double sprclr0 = 5.0; double sprclr;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "size", size0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "w", w0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "sq", sq0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "alnclr", alnclr0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "sprclr", sprclr0);

	// --- expand baseline
	size = size0;
	w = w0;
	sq = sq0;
	alnclr = alnclr0;
	sprclr = sprclr0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, 0, size,	w,	sq, alnclr, sprclr, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, 0, sq, vtxs, lgs);
	faces(dbsplnr, 0, refPlnrMDevice, sq, refSruPos, refSruNeg, refSruAlnpos, refSruAlnneg, refSruSprpos, refSruSprneg, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		size = size0;
		w = w0;
		sq = sq0;
		alnclr = alnclr0;
		sprclr = sprclr0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "size", size)) modpar += _SIZE;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "w", w)) modpar += _W;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "sq", sq)) modpar += _SQ;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "alnclr", alnclr)) modpar += _ALNCLR;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "sprclr", sprclr)) modpar += _SPRCLR;

		// dto/dnoto modifications only, no arcguides
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _SQ) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & _SQ) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, size, w, sq, alnclr, sprclr, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, sq, vtxs2, lgs2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, sq, refSruPos, refSruNeg, refSruAlnpos, refSruAlnneg, refSruSprpos, refSruSprneg, vtxs2, lgs2, fces2);

			vtxs2.clear();
			lgs2.clear();
			fces2.clear();

		} else if (modpar & (_SIZE + _W + _ALNCLR + _SPRCLR)) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, size, w, sq, alnclr, sprclr, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpCorner::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const double size
			,	const double w
			,	const bool sq
			, const double alnclr
			, const double sprclr
			, ListPlnrMVertex& vtxs
		) {
	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	double xy0, a;

	// initial vertex
	if ((x1RefPlnrMDesign == 0) || (modpar & _SQ)) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "v0", 0.0, 0.0, vtxs);

	// remaining vertices (x,y positions)
	vsrefs.push_back("v1"); vxs.push_back(size-sprclr-alnclr); vys.push_back(0.0);
	vsrefs.push_back("v2"); vxs.push_back(size-sprclr-alnclr); vys.push_back(w);
	vsrefs.push_back("v3"); vxs.push_back(w); vys.push_back(w);
	vsrefs.push_back("v4"); vxs.push_back(w); vys.push_back(size-sprclr-alnclr);
	vsrefs.push_back("v5"); vxs.push_back(0.0); vys.push_back(size-sprclr-alnclr);

	vsrefs.push_back("v6"); vxs.push_back(size-sprclr); vys.push_back(0.0);
	vsrefs.push_back("v7"); vxs.push_back(size-sprclr); vys.push_back(w+2.0*alnclr);
	vsrefs.push_back("v8"); vxs.push_back(0.5*((w+alnclr) + (size-sprclr))); vys.push_back(w+2.0*alnclr);
	vsrefs.push_back("v9"); vxs.push_back(0.5*((w+alnclr) + (size-sprclr))); vys.push_back(w+alnclr);
	vsrefs.push_back("v10"); vxs.push_back(w+alnclr); vys.push_back(w+alnclr);
	vsrefs.push_back("v11"); vxs.push_back(w+alnclr); vys.push_back(0.5*((w+alnclr) + (size-sprclr)));
	vsrefs.push_back("v12"); vxs.push_back(w+2.0*alnclr); vys.push_back(0.5*((w+alnclr) + (size-sprclr)));
	vsrefs.push_back("v13"); vxs.push_back(w+2.0*alnclr); vys.push_back(size-sprclr);
	vsrefs.push_back("v14"); vxs.push_back(0.0); vys.push_back(size-sprclr);

	vsrefs.push_back("v15"); vxs.push_back(size); vys.push_back(0.0);
	vsrefs.push_back("v16"); vxs.push_back(size); vys.push_back(w+2.0*alnclr+sprclr);
	vsrefs.push_back("v17"); vxs.push_back(w+2.0*alnclr+sprclr); vys.push_back(w+2.0*alnclr+sprclr);
	vsrefs.push_back("v18"); vxs.push_back(w+2.0*alnclr+sprclr); vys.push_back(size);
	vsrefs.push_back("v19"); vxs.push_back(0.0); vys.push_back(size);

	vsrefs.push_back("v23"); vxs.push_back(size); vys.push_back(size);

	if (sq) {
		xy0 = size-(w+alnclr+sprclr);

		a = 2.0*(w+alnclr+sprclr);
		vsrefs.push_back("v20"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v21"); vxs.push_back(xy0); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v22"); vxs.push_back(xy0+0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v24"); vxs.push_back(xy0); vys.push_back(xy0+0.5*a);
		vsrefs.push_back("v25"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0+0.5*a);

		a = 2.0*(w+alnclr);
		vsrefs.push_back("v26"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v27"); vxs.push_back(xy0); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v28"); vxs.push_back(xy0+0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v29"); vxs.push_back(xy0+0.5*a); vys.push_back(xy0+0.5*a);
		vsrefs.push_back("v30"); vxs.push_back(xy0); vys.push_back(xy0+0.5*a);
		vsrefs.push_back("v31"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0+0.5*a);

		a = 2.0*w;
		vsrefs.push_back("v32"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v33"); vxs.push_back(xy0); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v34"); vxs.push_back(xy0+0.5*a); vys.push_back(xy0-0.5*a);
		vsrefs.push_back("v35"); vxs.push_back(xy0+0.5*a); vys.push_back(xy0+0.5*a);
		vsrefs.push_back("v36"); vxs.push_back(xy0); vys.push_back(xy0+0.5*a);
		vsrefs.push_back("v37"); vxs.push_back(xy0-0.5*a); vys.push_back(xy0+0.5*a);
	};

	if ((x1RefPlnrMDesign == 0) || (modpar & _SQ)) {
		addVertices(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
	} else {
		addVertexXYs(dbsplnr, vsrefs, x1RefPlnrMDesign, vxs, vys, vtxs);
	};
};

void PlnrExpCorner::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const bool sq
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	if (sq) {
		lsrefs.push_back("l0"); vsrefsstrs.push_back("v19;v18;v25;v24;v23");

		lsrefs.push_back("l1"); vsrefsstrs.push_back("v31;v30;v29");
		lsrefs.push_back("l2"); vsrefsstrs.push_back("v37;v36;v35");
		lsrefs.push_back("l3"); vsrefsstrs.push_back("v32;v33;v34");
		lsrefs.push_back("l4"); vsrefsstrs.push_back("v26;v27;v28");
		lsrefs.push_back("l5"); vsrefsstrs.push_back("v20;v21;v22");
	} else {
		lsrefs.push_back("l0"); vsrefsstrs.push_back("v19;v18;v23");
	};

	lsrefs.push_back("l6"); vsrefsstrs.push_back("v14;v13");
	lsrefs.push_back("l7"); vsrefsstrs.push_back("v5;v4");
	lsrefs.push_back("l8"); vsrefsstrs.push_back("v11;v12");
	lsrefs.push_back("l9"); vsrefsstrs.push_back("v17;v16");
	lsrefs.push_back("l10"); vsrefsstrs.push_back("v8;v7");
	lsrefs.push_back("l11"); vsrefsstrs.push_back("v10;v9");
	lsrefs.push_back("l12"); vsrefsstrs.push_back("v3;v2");
	lsrefs.push_back("l13"); vsrefsstrs.push_back("v0;v1;v6;v15");

	lsrefs.push_back("l14"); vsrefsstrs.push_back("v19;v14;v5;v0");
	lsrefs.push_back("l15"); vsrefsstrs.push_back("v4;v3");
	lsrefs.push_back("l16"); vsrefsstrs.push_back("v11;v10");
	lsrefs.push_back("l17"); vsrefsstrs.push_back("v13;v12");
	lsrefs.push_back("l18"); vsrefsstrs.push_back("v18;v17");
	lsrefs.push_back("l19"); vsrefsstrs.push_back("v8;v9");
	lsrefs.push_back("l20"); vsrefsstrs.push_back("v2;v1");
	lsrefs.push_back("l21"); vsrefsstrs.push_back("v7;v6");

	if (sq) {
		lsrefs.push_back("l22"); vsrefsstrs.push_back("v23;v22;v16;v15");

		lsrefs.push_back("l23"); vsrefsstrs.push_back("v25;v20");
		lsrefs.push_back("l24"); vsrefsstrs.push_back("v31;v26");
		lsrefs.push_back("l25"); vsrefsstrs.push_back("v37;v32");
		lsrefs.push_back("l26"); vsrefsstrs.push_back("v24;v30;v36;v33;v27;v21");
		lsrefs.push_back("l27"); vsrefsstrs.push_back("v35;v34");
		lsrefs.push_back("l28"); vsrefsstrs.push_back("v29;v28");
	} else {
		lsrefs.push_back("l22"); vsrefsstrs.push_back("v23;v16;v15");
	};

	addLineguides(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpCorner::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool sq
			, const ubigint refSruPos
			, const ubigint refSruNeg
			, const ubigint refSruAlnpos
			, const ubigint refSruAlnneg
			, const ubigint refSruSprpos
			, const ubigint refSruSprneg
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	ListPlnrMArcguide ags;

	vector<ubigint> srurefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	// -- cross (and square)

	// - positive tone
	srurefs.push_back(refSruPos);
	fsrefs.push_back("f0");
	vsrefsstrs.push_back("v0; v1; v2; v3; v4; v5");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l13;l20;l12;l15;l7; l14");
	dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;fwd");

	if (sq) {
		srurefs.push_back(refSruPos);
		fsrefs.push_back("f3");
		vsrefsstrs.push_back("v32;v34;v35;v37");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l3; l27;l2; l25");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	// - negative tone
	if (!sq) {
		srurefs.push_back(refSruNeg);
		fsrefs.push_back("f6");
		vsrefsstrs.push_back("v1; v15;v23;v19;v5; v4; v3; v2");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l13;l22;l0; l14;l7; l15;l12;l20");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;fwd;fwd");
	};

	if (sq) {
		srurefs.push_back(refSruNeg);
		fsrefs.push_back("f6");
		vsrefsstrs.push_back("v1; v15;v22;v20;v25;v19;v5; v4; v3; v2");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l13;l22;l5; l23;l0; l14;l7; l15;l12;l20");
		dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;fwd;fwd;fwd;fwd;fwd");

		srurefs.push_back(refSruNeg);
		fsrefs.push_back("f7");
		vsrefsstrs.push_back("v20;v21;v33;v32;v37;v36;v24;v25");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l5; l26;l3; l25;l2; l26;l0; l23");
		dirsstrs.push_back	("fwd;bwd;bwd;bwd;fwd;bwd;bwd;fwd");

		srurefs.push_back(refSruNeg);
		fsrefs.push_back("f8");
		vsrefsstrs.push_back("v21;v22;v23;v24;v36;v35;v34;v33");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l5; l22;l0; l26;l2; l27;l3; l26");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");
	};

	// -- aligmnent around cross (and square)

	// - positive tone
	srurefs.push_back(refSruAlnpos);
	fsrefs.push_back("f1");
	vsrefsstrs.push_back("v0; v6; v7; v8; v9; v10;v11;v12;v13;v14");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l13;l21;l10;l19;l11;l16;l8; l17;l6; l14");
	dirsstrs.push_back	("fwd;bwd;bwd;fwd;bwd;bwd;fwd;bwd;bwd;fwd");

	if (sq) {
		srurefs.push_back(refSruAlnpos);
		fsrefs.push_back("f4");
		vsrefsstrs.push_back("v26;v28;v29;v31");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l4; l28;l1; l24");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	// - negative tone
	if (!sq) {
		srurefs.push_back(refSruAlnneg);
		fsrefs.push_back("f9");
		vsrefsstrs.push_back("v6; v15;v23;v19;v14;v13;v12;v11;v10;v9; v8; v7");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l13;l22;l0; l14;l6; l17;l8; l16;l11;l19;l10;l21");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd;fwd;bwd;fwd;fwd");
	};

	if (sq) {
		srurefs.push_back(refSruAlnneg);
		fsrefs.push_back("f9");
		vsrefsstrs.push_back("v6; v15;v22;v20;v25;v19;v14;v13;v12;v11;v10;v9; v8; v7");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l13;l22;l5; l23;l0; l14;l6; l17;l8; l16;l11;l19;l10;l21");
		dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd;fwd;bwd;fwd;fwd");

		srurefs.push_back(refSruAlnneg);
		fsrefs.push_back("f10");
		vsrefsstrs.push_back("v20;v21;v27;v26;v31;v30;v24;v25");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l5; l26;l4; l24;l1; l26;l0; l23");
		dirsstrs.push_back	("fwd;bwd;bwd;bwd;fwd;bwd;bwd;fwd");

		srurefs.push_back(refSruAlnneg);
		fsrefs.push_back("f11");
		vsrefsstrs.push_back("v21;v22;v23;v24;v30;v29;v28;v27");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l5; l22;l0; l26;l1; l28;l4; l26");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");
	};

	// -- spare around cross (and square) & alignment

	// - positive tone
	srurefs.push_back(refSruSprpos);
	fsrefs.push_back("f2");
	vsrefsstrs.push_back("v0; v15;v16;v17;v18;v19");
	rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd");
	gsrefsstrs.push_back("l13;l22;l9; l18;l0; l14");
	dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;fwd");

	if (sq) {
		srurefs.push_back(refSruSprpos);
		fsrefs.push_back("f5");
		vsrefsstrs.push_back("v20;v22;v23;v25");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l5; l22;l0; l23");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	// - negative tone
	if (sq) {
		srurefs.push_back(refSruSprneg);
		fsrefs.push_back("f12");
		vsrefsstrs.push_back("v17;v16;v22;v20;v25;v18");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l9; l22;l5; l23;l0; l18");
		dirsstrs.push_back	("fwd;bwd;bwd;bwd;bwd;fwd");
	} else {
		srurefs.push_back(refSruSprneg);
		fsrefs.push_back("f12");
		vsrefsstrs.push_back("v17;v16;v23;v18");
		rtesstrs.push_back	("lgd;lgd;lgd;lgd");
		gsrefsstrs.push_back("l9; l22;l0; l18");
		dirsstrs.push_back	("fwd;bwd;bwd;fwd");
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, srurefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


