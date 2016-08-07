/**
  * \file PlnrExpSpring.cpp
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

#include "PlnrExpSpring.h"

DpchRetPlnr* PlnrExpSpring::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpSpring* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	double l0 = 80.0; double l;
	double w0 = 2.0; double w;
	int N0 = 5; int N;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "l", l0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "w", w0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "N", N0);

	// --- expand baseline
	l = l0;
	w = w0;
	N = N0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, l, w, N, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, 0, N, vtxs, lgs);
	faces(dbsplnr, 0, refPlnrMDevice, N, refSruAll, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		l = l0;
		w = w0;
		N = N0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "l", l)) modpar += _L;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "w", w)) modpar += _W;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "N", N)) modpar += _N;

		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _N) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & _N) {
			// dto if number of segments changes
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, l, w, N, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, modpar, N, vtxs2, lgs2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, N, refSruAll, vtxs2, lgs2, fces2);

			vtxs2.clear();
			lgs2.clear();
			fces2.clear();
		} else if (modpar != 0) {
			// dnoto
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, l, w, N, vtxs);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpSpring::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double l
			, const double w
			, const int N
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	vector<string> vsrefs;
	vector<double> vxs;
	vector<double> vys;

	double Nd = N;
	double id;

	double x, y;

	// center vertex
	if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// - connector vertices
	vsrefs.push_back("v1"); vxs.push_back(-0.5*w); vys.push_back(-(Nd+1.5)*w); // [0]
	vsrefs.push_back("v2"); vxs.push_back(0.5*w); vys.push_back(-(Nd+1.5)*w);
	vsrefs.push_back("v3"); vxs.push_back(0.5*w); vys.push_back(-(Nd+0.5)*w);
	vsrefs.push_back("v4"); vxs.push_back(-0.5*w); vys.push_back(-(Nd-0.5)*w);
	vsrefs.push_back("v5"); vxs.push_back(vxs[0]); vys.push_back(-vys[0]);
	vsrefs.push_back("v6"); vxs.push_back(vxs[1]); vys.push_back(-vys[1]);
	if ((N%2) == 0) {
		// N even
		vsrefs.push_back("v7"); vxs.push_back(0.5*w); vys.push_back((Nd-0.5)*w);
		vsrefs.push_back("v8"); vxs.push_back(-0.5*w); vys.push_back((Nd+0.5)*w);
	} else {
		vsrefs.push_back("v7"); vxs.push_back(vxs[2]); vys.push_back(-vys[2]);
		vsrefs.push_back("v8"); vxs.push_back(vxs[3]); vys.push_back(-vys[3]);
	};

	if (!xyonly) {
		addVertices(dbsplnr, 0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, vsrefs, vxs, vys, vtxs);
	} else if (modpar & (_W + _N)) {
		for (unsigned int i=0;i<8;i++) addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, vxs[i], vys[i], vtxs);
	};

	// - segment vertices
	for (int i=1;i<=N;i++) {
		id = i;

		str.str(""); str << "v" << i << "_a";
		x = 0.5*(l-w); if ((i%2) == 0) x = -x;
		y = (-Nd+2.0*(id-1.0)+0.5)*w;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y, vtxs);
		else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y, vtxs);

		str.str(""); str << "v" << i << "_b";
		x = 0.5*(l+w); if ((i%2) == 0) x = -x;
		y = (-Nd+2.0*(id-1.0)-0.5)*w;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y, vtxs);
		else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y, vtxs);

		str.str(""); str << "v" << i << "_c";
		x = 0.5*(l+w); if ((i%2) == 0) x = -x;
		y = (-Nd+2.0*(id-1.0)+2.5)*w;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y, vtxs);
		else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y, vtxs);

		str.str(""); str << "v" << i << "_d";
		x = 0.5*(l-w); if ((i%2) == 0) x = -x;
		y = (-Nd+2.0*(id-1.0)+1.5)*w;
		if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y, vtxs);
		else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y, vtxs);
	};
};

void PlnrExpSpring::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const unsigned int modpar
			, const int N
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;

	vector<string> lsrefs;
	vector<string> vsrefsstrs;

	bool first;

	// - line guides
	lsrefs.push_back("l0");
	str.str("");
	first = true;
	for (int i=N;i>=1;i--) {
		if ((i%2) == 0) {
			// even segment
			if (first) first = false;
			else str << ";";

			str << "v" << i << "_c;v" << i << "_b";
		};
	};
	vsrefsstrs.push_back(str.str());

	lsrefs.push_back("l1");
	str.str("");
	first = true;
	for (int i=N;i>=1;i--) {
		if ((i%2) == 0) {
			// even segment
			if (first) first = false;
			else str << ";";

			str << "v" << i << "_d;v" << i << "_a";
		};
	};
	vsrefsstrs.push_back(str.str());

	lsrefs.push_back("l2"); vsrefsstrs.push_back("v5;v8;v4;v1");
	lsrefs.push_back("l3"); vsrefsstrs.push_back("v6;v7;v3;v2");

	lsrefs.push_back("l4");
	str.str("");
	first = true;
	for (int i=N;i>=1;i--) {
		if ((i%2) == 1) {
			// odd segment
			if (first) first = false;
			else str << ";";

			str << "v" << i << "_d;v" << i << "_a";
		};
	};
	vsrefsstrs.push_back(str.str());

	lsrefs.push_back("l5");
	str.str("");
	first = true;
	for (int i=N;i>=1;i--) {
		if ((i%2) == 1) {
			// odd segment
			if (first) first = false;
			else str << ";";

			str << "v" << i << "_c;v" << i << "_b";
		};
	};
	vsrefsstrs.push_back(str.str());

	lsrefs.push_back("l6"); vsrefsstrs.push_back("v5;v6");

	lsrefs.push_back("l7");
	str.str("");
	if ((N%2) == 0) {
		str << "v" << N << "_c;v8";
	} else {
		str << "v7;v" << N << "_c";
	};
 	vsrefsstrs.push_back(str.str());

	lsrefs.push_back("l8"); vsrefsstrs.push_back("v3;v1_b");
	lsrefs.push_back("l9"); vsrefsstrs.push_back("v1;v2");

	// - horizontal segment line guides
	for (int i=1;i<=N;i++) {
		if ((i%2) == 0) {
			// even segment

			// north
			str.str(""); str << "ln" << i;
			lsrefs.push_back(str.str());
			str.str("");
			if (i==N) {
				str << "v" << i << "_d;v7";
			} else {
				str << "v" << i << "_d;v" << (i+1) << "_b";
			};
			vsrefsstrs.push_back(str.str());

			// south
			str.str(""); str << "ls" << i;
			lsrefs.push_back(str.str());
			str.str(""); str << "v" << i << "_a;v" << (i-1) << "_c";
			vsrefsstrs.push_back(str.str());

		} else {
			// odd segment

			// north
			str.str(""); str << "ln" << i;
			lsrefs.push_back(str.str());
			if (i==N) {
				str.str(""); str << "v8;v" << i << "_d";
			} else {
				str.str(""); str << "v" << (i+1) << "_b;v" << i << "_d";
			};
			vsrefsstrs.push_back(str.str());

			// south
			str.str(""); str << "ls" << i;
			lsrefs.push_back(str.str());
			str.str("");
			if (i==1) {
				vsrefsstrs.push_back("v4;v1_a");
			} else {
				str << "v" << (i-1) << "_c;v" << i << "_a";
				vsrefsstrs.push_back(str.str());
			};
		};
	};

	addLineguides(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, lsrefs, vsrefsstrs, vtxs, lgs);
};

void PlnrExpSpring::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int N
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	ListPlnrMArcguide ags;

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	// - lower end
	vsrefs.push_back("v1"); rtes.push_back("lgd"); gsrefs.push_back("l9"); dirs.push_back("fwd");
	vsrefs.push_back("v2"); rtes.push_back("lgd"); gsrefs.push_back("l3"); dirs.push_back("bwd");
	vsrefs.push_back("v3"); rtes.push_back("lgd"); gsrefs.push_back("l8"); dirs.push_back("fwd");

	// - rhs upwards part
	for (int i=1;i<=N;i++) {
		if ((i%2) == 0) {
			// even segment
			str.str(""); str << "v" << i << "_a";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd"); gsrefs.push_back("l1"); dirs.push_back("bwd");

			str.str(""); str << "v" << i << "_d";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd");
			str.str(""); str << "ln" << i;
			gsrefs.push_back(str.str());
			dirs.push_back("fwd");

		} else {
			// odd segment
			str.str(""); str << "v" << i << "_b";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd"); gsrefs.push_back("l5"); dirs.push_back("bwd");

			if (i != N) {
				str.str(""); str << "v" << i << "_c";
				vsrefs.push_back(str.str());
				rtes.push_back("lgd");
				str.str(""); str << "ls" << (i+1);
				gsrefs.push_back(str.str());
				dirs.push_back("bwd");
			};
		};
	};

	// - upper end
	if ((N%2) == 0) {
		// even N
		vsrefs.push_back("v7"); rtes.push_back("lgd"); gsrefs.push_back("l3"); dirs.push_back("bwd");
		vsrefs.push_back("v6"); rtes.push_back("lgd"); gsrefs.push_back("l6"); dirs.push_back("bwd");
		vsrefs.push_back("v5"); rtes.push_back("lgd"); gsrefs.push_back("l2"); dirs.push_back("fwd");
		vsrefs.push_back("v8"); rtes.push_back("lgd"); gsrefs.push_back("l7"); dirs.push_back("bwd");
		
	} else {
		// odd N
		str.str(""); str << "v" << N << "_c";
		vsrefs.push_back(str.str());
		rtes.push_back("lgd"); gsrefs.push_back("l7"); dirs.push_back("bwd");

		vsrefs.push_back("v7"); rtes.push_back("lgd"); gsrefs.push_back("l3"); dirs.push_back("bwd");
		vsrefs.push_back("v6"); rtes.push_back("lgd"); gsrefs.push_back("l6"); dirs.push_back("bwd");
		vsrefs.push_back("v5"); rtes.push_back("lgd"); gsrefs.push_back("l2"); dirs.push_back("fwd");

		vsrefs.push_back("v8"); rtes.push_back("lgd");
		str.str(""); str << "ln" << N;
		gsrefs.push_back(str.str());
		dirs.push_back("fwd");
	};

	// - lhs downwards part
	for (int i=N;i>=1;i--) {
		if ((i%2) == 0) {
			// even segment
			str.str(""); str << "v" << i << "_c";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd"); gsrefs.push_back("l0"); dirs.push_back("fwd");

			str.str(""); str << "v" << i << "_b";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd");
			str.str(""); str << "ln" << (i-1);
			gsrefs.push_back(str.str());
			dirs.push_back("fwd");

		} else {
			// odd segment
			str.str(""); str << "v" << i << "_d";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd"); gsrefs.push_back("l4"); dirs.push_back("fwd");

			str.str(""); str << "v" << i << "_a";
			vsrefs.push_back(str.str());
			rtes.push_back("lgd");
			str.str(""); str << "ls" << i;
			gsrefs.push_back(str.str());
			dirs.push_back("bwd");
		};
	};

	// - lower end (2)
	vsrefs.push_back("v4"); rtes.push_back("lgd"); gsrefs.push_back("l2"); dirs.push_back("fwd");

	addFaceByVgsrefs(dbsplnr, 0, refSruAll, "f0", vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


