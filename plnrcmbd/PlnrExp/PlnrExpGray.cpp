/**
  * \file PlnrExpGray.cpp
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

#include "PlnrExpGray.h"

DpchRetPlnr* PlnrExpGray::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpGray* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double p0 = 0.5; double p;
	double pix0 = 20.0; double pix;
	int M0 = 20; int M;
	int N0 = 20; int N;
	bool invsq0 = false; bool invsq;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "p", p0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "pix", pix0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "M", M0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "N", N0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "invsq", invsq0);

	// --- expand baseline
	p = p0;
	pix = pix0;
	M = M0;
	N = N0;
	invsq = invsq0;

	dbsplnr->begin();

	vtxlgfces(dbsplnr, 0, refPlnrMDevice, p, pix, M, N, invsq, refSruAll);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		p = p0;
		pix = pix0;
		M = M0;
		N = N0;
		invsq = invsq0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "p", p)) modpar += _P;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "pix", pix)) modpar += _PIX;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "M", M)) modpar += _M;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "N", N)) modpar += _N;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "invsq", invsq)) modpar += _INVSQ;

		// dto modifications, no arcguides; dto (p, pix, M, N, invsq) affect vertices, lineguides, faces
		// for practical reasons, also p and pix are included in dto parameters

		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		};

		if (modpar != 0) {
			vtxlgfces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, p, pix, M, N, invsq, refSruAll);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpGray::vtxlgfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const double p
			, const double pix
			, const int M
			, const int N
			, const bool invsq
			, const ubigint refSruAll
		) {
	// to deal with the large number of pixels, non-standard expansion methods are employed

	ostringstream str;

	PlnrMVertex vtx;

	PlnrMLineguide lg;
	PlnrLRMLineguideMVertex lrv;
	
	PlnrMFace fce;
	PlnrRMFaceMVertex frv;

	vector<ubigint> refsVtxspc;
	vector<ubigint> refsLgspc;

	vector<ubigint> refsVtxa;
	vector<ubigint> refsVtxb;
	vector<ubigint> refsVtxc;
	vector<ubigint> refsVtxd;

	vector<ubigint> refsLgw;
	vector<ubigint> refsLge;
	vector<ubigint> refsLgn;
	vector<ubigint> refsLgs;

	double x, y;
	double d;

	// -- initialization

	// vtx: sref, x and y vary
	vtx.x1RefPlnrMDesign = x1RefPlnrMDesign;
	vtx.hkIxPlnrVLat = VecPlnrVLat::INI;
	vtx.hkIxVTbl = VecPlnrVMVertexHkTbl::DEV;
	vtx.hkUref = refPlnrMDevice;

	// lg: sref varies
	lg.x1RefPlnrMDesign = x1RefPlnrMDesign;
	lg.hkIxPlnrVLat = VecPlnrVLat::INI;
	lg.hkIxVTbl = VecPlnrVMLineguideHkTbl::DEV;
	lg.hkUref = refPlnrMDevice;

	// lrv: lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex vary
	lrv.lgdIxPlnrVLat = VecPlnrVLat::INI;

	// fce: sref varies
	fce.x1RefPlnrMDesign = x1RefPlnrMDesign;
	fce.devRefPlnrMFace = 0;
	fce.sruIxPlnrVLat = VecPlnrVLat::INI;
	fce.sruRefPlnrMStructure = refSruAll;

	// frv: fceRefPlnrMFace, fceNum, refPlnrMVertex, rteUref, ixVDir vary
	frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;

	if (invsq) d = 0.5 * sqrt(1.0-p) * pix;
	else d = 0.5 * sqrt(p) * pix;

	vtx.sref = "vctr";
	vtx.x = 0.0;
	vtx.y = 0.0;
	dbsplnr->tblplnrmvertex->insertRec(&vtx);
	refsVtxspc.push_back(vtx.ref);

	if (invsq) {
		// -- special vertices
		vtx.sref = "v1";
		vtx.x = (-0.5*((double) N)) * pix;
		vtx.y = (-0.5*((double) M)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		vtx.sref = "v2";
		vtx.x = (-0.5*((double) N) + 0.5)*pix - d;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		// v3, v4 are v2, v1 x-flipped
		vtx.sref = "v3";
		vtx.x = (0.5*((double) N) - 0.5)*pix + d;
		vtx.y = (-0.5*((double) M)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		vtx.sref = "v4";
		vtx.x = (0.5*((double) N)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		// v5, v6 are v1, v2 x,y-flipped
		vtx.sref = "v5";
		vtx.x = (0.5*((double) N)) * pix;
		vtx.y = (0.5*((double) M)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		vtx.sref = "v6";
		vtx.x = (0.5*((double) N) - 0.5)*pix + d;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		// v7, v8 are v2, v1 y-flipped
		vtx.sref = "v7";
		vtx.x = (-0.5*((double) N) + 0.5)*pix - d;
		vtx.y = (0.5*((double) M)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		vtx.sref = "v8";
		vtx.x = (-0.5*((double) N)) * pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);
		refsVtxspc.push_back(vtx.ref);

		// -- special lineguides

		// - north
		lg.sref = "l0";
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgspc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[8];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2;
		lrv.refPlnrMVertex = refsVtxspc[7];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 3;
		lrv.refPlnrMVertex = refsVtxspc[6];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 4;
		lrv.refPlnrMVertex = refsVtxspc[5];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		// - south
		lg.sref = "l1";
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgspc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[1];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2;
		lrv.refPlnrMVertex = refsVtxspc[2];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 3;
		lrv.refPlnrMVertex = refsVtxspc[3];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 4;
		lrv.refPlnrMVertex = refsVtxspc[4];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		// - west
		lg.sref = "l2";
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgspc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[8];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2;
		lrv.refPlnrMVertex = refsVtxspc[1];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		// - east
		lg.sref = "l3";
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgspc.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[5];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		lrv.lgdNum = 2;
		lrv.refPlnrMVertex = refsVtxspc[4];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	// -- array vertices
	for (int i=0;i<M;i++) {
		y = (-0.5*((double) M) + ((double) i) + 0.5) * pix;

		for (int j=0;j<N;j++) {
			x = (-0.5*((double) N) + ((double) j) + 0.5) * pix;

			// 'a' vertex
			str.str(""); str << "vr" << i << "_c" << j << "_a";
			vtx.sref = str.str();
			vtx.x = x - d;
			vtx.y = y - d;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxa.push_back(vtx.ref);

			// 'b' vertex
			str.str(""); str << "vr" << i << "_c" << j << "_b";
			vtx.sref = str.str();
			vtx.x = x + d;
			vtx.y = y - d;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxb.push_back(vtx.ref);

			// 'c' vertex
			str.str(""); str << "vr" << i << "_c" << j << "_c";
			vtx.sref = str.str();
			vtx.x = x + d;
			vtx.y = y + d;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxc.push_back(vtx.ref);

			// 'd' vertex
			str.str(""); str << "vr" << i << "_c" << j << "_d";
			vtx.sref = str.str();
			vtx.x = x - d;
			vtx.y = y + d;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refsVtxd.push_back(vtx.ref);
		};
	};

	// -- array lineguides plus vertex line-up
	for (int i=0;i<M;i++) {
		// - 'n' lineguide
		str.str(""); str << "lhn" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgn.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		for (int j=0;j<N;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxd[i*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxc[i*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - 's' lineguide
		str.str(""); str << "lhs" << i;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgs.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		for (int j=0;j<N;j++) {
			lrv.lgdNum = 1 + (2*j);
			lrv.refPlnrMVertex = refsVtxa[i*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*j+1);
			lrv.refPlnrMVertex = refsVtxb[i*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	for (int j=0;j<N;j++) {
		// - 'w' lineguide
		str.str(""); str << "lvw" << j;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLgw.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		for (int i=0;i<M;i++) {
			lrv.lgdNum = 1 + (2*i);
			lrv.refPlnrMVertex = refsVtxd[(M-i-1)*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*i+1);
			lrv.refPlnrMVertex = refsVtxa[(M-i-1)*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};

		// - 'e' lineguide
		str.str(""); str << "lve" << j;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLge.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;

		for (int i=0;i<M;i++) {
			lrv.lgdNum = 1 + (2*i);
			lrv.refPlnrMVertex = refsVtxc[(M-i-1)*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdNum = 1 + (2*i+1);
			lrv.refPlnrMVertex = refsVtxb[(M-i-1)*N+j];
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
		};
	};

	if (invsq) {
		// -- extend lineguides

		// - leftmost west lineguide
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = lgdNum + 1 WHERE lgdRefPlnrMLineguide = " + to_string(refsLgw[0]));

		lrv.lgdRefPlnrMLineguide = refsLgw[0];

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[7];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdNum = M+1;
		lrv.refPlnrMVertex = refsVtxspc[2];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		// - rightmost east lineguide
		dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = lgdNum + 1 WHERE lgdRefPlnrMLineguide = " + to_string(refsLge[N-1]));

		lrv.lgdRefPlnrMLineguide = refsLge[N-1];

		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsVtxspc[6];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		lrv.lgdNum = M+1;
		lrv.refPlnrMVertex = refsVtxspc[3];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
	};

	// -- faces plus vertex line-up
	if (invsq) {
		// - one face per row
		for (int i=0 ; i<M ; i++) {
			str.str(""); str << "fr" << i;

			fce.sref = str.str();
			dbsplnr->tblplnrmface->insertRec(&fce);

			frv.fceRefPlnrMFace = fce.ref;

			// first pixel in column d-c-b
			frv.fceNum = 1;
			frv.refPlnrMVertex = refsVtxd[i*N+0];
			frv.rteUref = refsLgn[i];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 2;
			frv.refPlnrMVertex = refsVtxc[i*N+0];
			frv.rteUref = refsLge[0];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 3;
			frv.refPlnrMVertex = refsVtxb[i*N+0];
			frv.rteUref = refsLgs[i];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			// central pixels a-d-c-b
			for (int j=1 ; j<(N-1) ; j++) {
				frv.fceNum = 4 + 4*(j-1);
				frv.refPlnrMVertex = refsVtxa[i*N+j];
				frv.rteUref = refsLgw[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4 + 4*(j-1) + 1;
				frv.refPlnrMVertex = refsVtxd[i*N+j];
				frv.rteUref = refsLgn[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4 + 4*(j-1) + 2;
				frv.refPlnrMVertex = refsVtxc[i*N+j];
				frv.rteUref = refsLge[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4 + 4*(j-1) + 3;
				frv.refPlnrMVertex = refsVtxb[i*N+j];
				frv.rteUref = refsLgs[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
			};

			// last pixel in column a-d-c
			frv.fceNum = 4 + 4*(N-2);
			frv.refPlnrMVertex = refsVtxa[i*N+(N-1)];
			frv.rteUref = refsLgw[N-1];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 4 + 4*(N-2) + 1;
			frv.refPlnrMVertex = refsVtxd[i*N+(N-1)];
			frv.rteUref = refsLgn[i];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			frv.fceNum = 4 + 4*(N-2) + 2;
			frv.refPlnrMVertex = refsVtxc[i*N+(N-1)];
			frv.rteUref = refsLge[N-1];
			frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
			dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			// close polygon
			if (i == (M-1)) {
				// special treatment for last row
				frv.fceNum = 4 + 4*(N-2) + 3;
				frv.refPlnrMVertex = refsVtxspc[6];
				frv.rteUref = refsLgspc[0];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4 + 4*(N-2) + 4;
				frv.refPlnrMVertex = refsVtxspc[7];
				frv.rteUref = refsLgw[0];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

			} else {
				frv.fceNum = 4 + 4*(N-2) + 3;
				frv.refPlnrMVertex = refsVtxb[(i+1)*N+(N-1)];
				frv.rteUref = refsLgs[i+1];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4 + 4*(N-2) + 4;
				frv.refPlnrMVertex = refsVtxa[(i+1)*N+0];
				frv.rteUref = refsLgw[0];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
			};
		};

		// - special faces

		// west face
		fce.sref = "fw";
		dbsplnr->tblplnrmface->insertRec(&fce);

		frv.fceRefPlnrMFace = fce.ref;

		frv.fceNum = 1;
		frv.refPlnrMVertex = refsVtxspc[1];
		frv.rteUref = refsLgspc[1];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 2;
		frv.refPlnrMVertex = refsVtxspc[2];
		frv.rteUref = refsLgw[0];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 3;
		frv.refPlnrMVertex = refsVtxspc[7];
		frv.rteUref = refsLgspc[0];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 4;
		frv.refPlnrMVertex = refsVtxspc[8];
		frv.rteUref = refsLgspc[2];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		// south face
		fce.sref = "fs";
		dbsplnr->tblplnrmface->insertRec(&fce);

		frv.fceRefPlnrMFace = fce.ref;

		frv.fceNum = 1;
		frv.refPlnrMVertex = refsVtxspc[2];
		frv.rteUref = refsLgspc[1];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 2;
		frv.refPlnrMVertex = refsVtxspc[3];
		frv.rteUref = refsLge[N-1];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 3;
		frv.refPlnrMVertex = refsVtxb[N-1];
		frv.rteUref = refsLgs[0];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 4;
		frv.refPlnrMVertex = refsVtxa[0];
		frv.rteUref = refsLgw[0];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		// east face
		fce.sref = "fe";
		dbsplnr->tblplnrmface->insertRec(&fce);

		frv.fceRefPlnrMFace = fce.ref;

		frv.fceNum = 1;
		frv.refPlnrMVertex = refsVtxspc[3];
		frv.rteUref = refsLgspc[1];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 2;
		frv.refPlnrMVertex = refsVtxspc[4];
		frv.rteUref = refsLgspc[3];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 3;
		frv.refPlnrMVertex = refsVtxspc[5];
		frv.rteUref = refsLgspc[0];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

		frv.fceNum = 4;
		frv.refPlnrMVertex = refsVtxspc[6];
		frv.rteUref = refsLge[N-1];
		frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
		dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

	} else {
		// - one face per pixel
		for (int i=0;i<M;i++) {
			for (int j=0;j<N;j++) {
				str.str(""); str << "fr" << i << "_c" << j;
				fce.sref = str.str();
				dbsplnr->tblplnrmface->insertRec(&fce);

				frv.fceRefPlnrMFace = fce.ref;

				// square a-b-c-d
				frv.fceNum = 1;
				frv.refPlnrMVertex = refsVtxa[i*N+j];
				frv.rteUref = refsLgs[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 2;
				frv.refPlnrMVertex = refsVtxb[i*N+j];
				frv.rteUref = refsLge[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 3;
				frv.refPlnrMVertex = refsVtxc[i*N+j];
				frv.rteUref = refsLgn[i];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				frv.fceNum = 4;
				frv.refPlnrMVertex = refsVtxd[i*N+j];
				frv.rteUref = refsLgw[j];
				frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
				dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
			};
		};
	};
};
// IP cust --- IEND


