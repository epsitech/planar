/**
  * \file PlnrExpPhctrigneg.cpp
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

#include "PlnrExpPhctrigneg.h"

DpchRetPlnr* PlnrExpPhctrigneg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhctrigneg* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ubigint refTpl;

	vector<ubigint> refsSubdevPtrnegcav;
	vector<ubigint> refsSubdevPtrnegcavfr;
	ubigint refSubdev;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMArcguide ags, ags2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load ptrnegcav sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "ptrnegcav", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPtrnegcav);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'ptrnegcav'", true, refsSubdevPtrnegcav);

	// load ptrnegcavfr sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "ptrnegcavfr", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPtrnegcavfr);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'ptrnegcavfr'", true, refsSubdevPtrnegcavfr);

	// load baseline parameters
	double r0 = 0.07; double r;
	double a0 = 0.3; double a;
	int M0 = 20; int M;
	int N0 = 20; int N;

	int ptrnegcav_mstart;
	int ptrnegcav_mstop;
	int ptrnegcav_nstart;
	int ptrnegcav_nstop;

	int ptrnegcavfr_mstart;
	int ptrnegcavfr_mstop;
	int ptrnegcavfr_nstart;
	int ptrnegcavfr_nstop;
	double ptrnegcavfr_rstart;
	double ptrnegcavfr_rstep;
	int ptrnegcavfr_rN;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "a", a0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "M", M0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "N", N0);

	// --- expand baseline
	r = r0;
	a = a0;
	M = M0;
	N = N0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, r, a, M, N, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, false, r, a, M, N, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, M, N, refSruAll, vtxs, lgs, ags, fces);

	// sub-devices
	for (unsigned int i=0;i<refsSubdevPtrnegcav.size();i++) {
		refSubdev = refsSubdevPtrnegcav[i];

		ptrnegcav_loadpars(dbsplnr, refSubdev, 0, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop);
		ptrnegcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, vtxs);
		ptrnegcav_guides(dbsplnr, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, vtxs, lgs, ags);
		ptrnegcav_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, refSruAll, vtxs, lgs, ags, fces);
	};

	for (unsigned int i=0;i<refsSubdevPtrnegcavfr.size();i++) {
		refSubdev = refsSubdevPtrnegcavfr[i];

		ptrnegcavfr_loadpars(dbsplnr, refSubdev, 0, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN);
		ptrnegcavfr_vertices(dbsplnr, 0, refPlnrMDevice, refSubdev, false, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, a, M, N, vtxs);
		ptrnegcavfr_guides(dbsplnr, 0, refPlnrMDevice, refSubdev, false, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, M, N, vtxs, lgs, ags);
		ptrnegcavfr_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, M, N, refSruAll, vtxs, lgs, ags, fces);
	};

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);
	dbsplnr->loadRefsBySQL("SELECT x1RefPlnrMDesign FROM TblPlnrMDevice, TblPlnrAMDevicePar WHERE TblPlnrAMDevicePar.refPlnrMDevice = TblPlnrMDevice.ref AND TblPlnrMDevice.supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", true, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		r = r0;
		a = a0;
		M = M0;
		N = N0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "a", a)) modpar += _A;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "M", M)) modpar += _M;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "N", N)) modpar += _N;

		// check for sub-device modified parameters
		for (unsigned int j=0;j<refsSubdevPtrnegcav.size();j++) {
			refSubdev = refsSubdevPtrnegcav[j];

			if (!(modpar & _PTRNEGCAV_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PTRNEGCAV_MSTART;
			if (!(modpar & _PTRNEGCAV_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PTRNEGCAV_MSTOP;
			if (!(modpar & _PTRNEGCAV_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PTRNEGCAV_NSTART;
			if (!(modpar & _PTRNEGCAV_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PTRNEGCAV_NSTOP;
		};
		for (unsigned int j=0;j<refsSubdevPtrnegcavfr.size();j++) {
			refSubdev = refsSubdevPtrnegcavfr[j];

			if (!(modpar & _PTRNEGCAVFR_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PTRNEGCAVFR_MSTART;
			if (!(modpar & _PTRNEGCAVFR_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PTRNEGCAVFR_MSTOP;
			if (!(modpar & _PTRNEGCAVFR_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PTRNEGCAVFR_NSTART;
			if (!(modpar & _PTRNEGCAVFR_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PTRNEGCAVFR_NSTOP;
			if (!(modpar & _PTRNEGCAVFR_RSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart")) modpar += _PTRNEGCAVFR_RSTART;
			if (!(modpar & _PTRNEGCAVFR_RSTEP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) modpar += _PTRNEGCAVFR_RSTEP;
			if (!(modpar & _PTRNEGCAVFR_RN)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rN")) modpar += _PTRNEGCAVFR_RN;
		};

		// dto/dnoto modifications, arcguides; all dto incl. those of sub-devices imply new set of vertices, guides and faces
		dbsplnr->begin();

		if (modpar & (_M + _N + _PTRNEGCAV_MSTART + _PTRNEGCAV_MSTOP + _PTRNEGCAV_NSTART + _PTRNEGCAV_NSTOP + _PTRNEGCAVFR_MSTART + _PTRNEGCAVFR_MSTOP + _PTRNEGCAVFR_NSTART + _PTRNEGCAVFR_NSTOP + _PTRNEGCAVFR_RN)) {
			// dto
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, r, a, M, N, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, r, a, M, N, vtxs2, lgs2, ags2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);

			// sub-devices
			for (unsigned int j=0;j<refsSubdevPtrnegcav.size();j++) {
				refSubdev = refsSubdevPtrnegcav[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				ptrnegcav_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop);
				ptrnegcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, vtxs2);
				ptrnegcav_guides(dbsplnr, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, vtxs2, lgs2, ags2);
				ptrnegcav_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, ptrnegcav_mstart, ptrnegcav_mstop, ptrnegcav_nstart, ptrnegcav_nstop, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);
			};
			for (unsigned int j=0;j<refsSubdevPtrnegcavfr.size();j++) {
				refSubdev = refsSubdevPtrnegcavfr[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				ptrnegcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN);
				ptrnegcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, a, M, N, vtxs2);
				ptrnegcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, M, N, vtxs2, lgs2, ags2);
				ptrnegcavfr_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);
			};
			
			vtxs2.clear();
			lgs2.clear();
			ags2.clear();
			fces2.clear();
			
		} else {
			// dnoto
			if (modpar & (_R + _A)) {
				addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
			};

			if (modpar & (_R + _A)) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, r, a, M, N, vtxs);
			if (modpar & _R) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, r, a, M, N, vtxs, lgs, ags);

			if (modpar & (_PTRNEGCAVFR_RSTART + _PTRNEGCAVFR_RSTEP)) {
				for (unsigned int j=0;j<refsSubdevPtrnegcavfr.size();j++) {
					refSubdev = refsSubdevPtrnegcavfr[j];

					// act only if dnoto parameters in specific sub-device are modified
					if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart") || dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) {
						addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);

						ptrnegcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN);
						ptrnegcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, a, M, N, vtxs);
						ptrnegcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, ptrnegcavfr_mstart, ptrnegcavfr_mstop, ptrnegcavfr_nstart, ptrnegcavfr_nstop, ptrnegcavfr_rstart, ptrnegcavfr_rstep, ptrnegcavfr_rN, M, N, vtxs, lgs, ags);
					};
				};
			};
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpPhctrigneg::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double r
			, const double a
			, const int M
			, const int N
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	double x, y;
	double dx = a;
	double dy = dx*sqrt(3.0)/2.0;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// - element vertices (row loop, then column loop)
	for (int m=mmin;m<=mmax;m++) {
		y = ((double) m) * dy;

		for (int n=nmin;n<=nmax;n++) {
			x = ((double) n) * dx;
			if ((m%2) != 0) x += 0.5*dx;

			// interior vertices
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y, vtxs);
			else if (modpar & _A) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y, vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y+r, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y+r, vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-r, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-r, vtxs);
		};
	};
};

void PlnrExpPhctrigneg::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool ronly
			, const double r
			, const double a
			, const int M
			, const int N
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str, str2;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	vector<string> vsrefs;

	// -- arc guides
	for (int m=mmin;m<=mmax;m++) {
		for (int n=nmin;n<=nmax;n++) {
			str2.str(""); str2 << "am" << intToPnstr(m) << "_n" << intToPnstr(n);

			if (!ronly) {
				vsrefs.resize(0);
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
				vsrefs.push_back(str.str());
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
				vsrefs.push_back(str.str());
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
				vsrefs.push_back(str.str());

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";

				addArcguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, str2.str(), str.str(), r, vsrefs, vtxs, ags);

			} else addArcguideRByAsref(dbsplnr, str2.str(), x1RefPlnrMDesign, r, ags);
		};
	};
};

void PlnrExpPhctrigneg::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int M
			, const int N
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	ostringstream str, str2;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	for (int m=mmin;m<=mmax;m++) {
		for (int n=nmin;n<=nmax;n++) {
			strrefs.push_back(refSruAll);

			str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n);
			fsrefs.push_back(str.str());

			// vertex line-up
			str.str("");
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			vsrefsstrs.push_back(str.str());

			rtesstrs.push_back("agd;agd");

			// guide line-up
			str.str("");
			str << "am" << intToPnstr(m) << "_n" << intToPnstr(n) << ";";
			str << "am" << intToPnstr(m) << "_n" << intToPnstr(n);
			gsrefsstrs.push_back(str.str());

			dirsstrs.push_back("fwd;fwd");
		};
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};

void PlnrExpPhctrigneg::ptrnegcav_loadpars(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, int& mstart
			, int& mstop
			, int& nstart
			, int& nstop
		) {
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mstart", mstart);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mstop", mstop);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "nstart", nstart);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "nstop", nstop);
};

void PlnrExpPhctrigneg::ptrnegcav_vertices(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const int M
			, const int N
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// traverse elements
	for (int m=mstart;m<=mstop;m++) {
		if ((m>=mmin) && (m<=mmax)) {
			for (int n=nstart;n<=nstop;n++) {
				if ((n>=nmin) && (n<=nmax)) {

					// remove element vertices 1 and 2
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
					opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
					opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);
				};
			};
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcav_guides(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const int M
			, const int N
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// traverse elements
	for (int m=mstart;m<=mstop;m++) {
		if ((m>=mmin) && (m<=mmax)) {
			for (int n=nstart;n<=nstop;n++) {
				if ((n>=nmin) && (n<=nmax)) {

					// remove element arc guide
					str.str(""); str << "am" << intToPnstr(m) << "_n" << intToPnstr(n);
					opsubArcguide(dbsplnr, refSupdev, refSubdev, str.str(), ags);
				};
			};
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcav_faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const int M
			, const int N
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// traverse elements
	for (int m=mstart;m<=mstop;m++) {
		if ((m>=mmin) && (m<=mmax)) {
			for (int n=nstart;n<=nstop;n++) {
				if ((n>=nmin) && (n<=nmax)) {

					// remove element face
					str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n);
					opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);
				};
			};
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcavfr_loadpars(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, int& mstart
			, int& mstop
			, int& nstart
			, int& nstop
			, double& rstart
			, double& rstep
			, int& rN
		) {
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mstart", mstart);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "mstop", mstop);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "nstart", nstart);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "nstop", nstop);
	loadModDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "rstart", rstart);
	loadModDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "rstep", rstep);
	loadModIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "rN", rN);
};

void PlnrExpPhctrigneg::ptrnegcavfr_getelems(
			const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const double rstart
			, const double rstep
			, const int rN
			, const int mmin
			, const int mmax
			, const int nmin
			, const int nmax
			, vector<int>& ms
			, vector<int>& ns
			, vector<double>& rs
		) {
	int m, n;
	int nrstart, nrstop;

	int i, j;
	double r, r2;

	ms.resize(0);
	ns.resize(0);
	rs.resize(0);

	// - cavity rows
	for (m=mstart;m<=mstop;m++) {
		for (i=0, r=rstart ; i<rN ; i++, r+=rstep) {
			// west
			n = nstart-i-1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r);
			};

			// east
			n = nstop+i+1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r);
			};
		};
	};

	// - north rows
	for (i=0, r=rstart ; i<rN ; i++, r+=rstep) {
		m = mstop+i+1;

		if ((i%2) == 0) {
			if ((m%2) == 0) {
				// even row
				nrstart = nstart - i/2;
				nrstop = nstop + (i+2)/2;
			} else {
				// odd row
				nrstart = nstart - (i+2)/2;
				nrstop = nstop + i/2;
			};

		} else {
			nrstart = nstart - (i+1)/2;
			nrstop = nstop + (i+1)/2;
		};

		// center
		for (n=nrstart;n<=nrstop;n++) {
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r);
			};
		};

		for (j=0, r2=r+rstep ; j<(rN-i-1) ; j++, r2+=rstep) {
			// west
			n = nrstart-j-1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r2);
			};

			// east
			n = nrstop+j+1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r2);
			};
		};
	};

	// - south rows
	for (i=0, r=rstart ; i<rN ; i++, r+=rstep) {
		m = mstart-i-1;

		if ((i%2) == 0) {
			if ((m%2) == 0) {
				// even row
				nrstart = nstart - i/2;
				nrstop = nstop + (i+2)/2;
			} else {
				// odd row
				nrstart = nstart - (i+2)/2;
				nrstop = nstop + i/2;
			};

		} else {
			nrstart = nstart - (i+1)/2;
			nrstop = nstop + (i+1)/2;
		};

		// center
		for (n=nrstart;n<=nrstop;n++) {
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r);
			};
		};

		for (j=0, r2=r+rstep ; j<(rN-i-1) ; j++, r2+=rstep) {
			// west
			n = nrstart-j-1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r2);
			};

			// east
			n = nrstop+j+1;
			if ((m >= mmin) && (m <= mmax) && (n >= nmin) && (n <= nmax)) {
				ms.push_back(m);
				ns.push_back(n);
				rs.push_back(r2);
			};
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcavfr_vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const bool xyonly
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const double rstart
			, const double rstep
			, const int rN
			, const double a
			, const int M
			, const int N
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// obtain elements to be modified
	vector<int> ms;
	vector<int> ns;
	vector<double> rs;

	ptrnegcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	// traverse elements
	int m, n;
	double r;

	double x, y;
	double dx = a;
	double dy = dx*sqrt(3.0)/2.0;

	for (unsigned int i=0;i<ms.size();i++) {
		m = ms[i];
		n = ns[i];
		r = rs[i];

		x = ((double) n) * dx;
		if ((m%2) != 0) x += 0.5*dx;

		y = ((double) m) * dy;

		if (!xyonly) {
			// remove existing element vertices 1 and 2
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);
	
			// add new element vertices 1 and 2
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x, y+r, vtxs);

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x, y-r, vtxs);

		} else {
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y+r, vtxs);

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-r, vtxs);
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcavfr_guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const bool ronly
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const double rstart
			, const double rstep
			, const int rN
			, const int M
			, const int N
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str;

	int m, n;
	double r;

	string cvsref;
	vector<string> vsrefs;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// obtain elements to be modified
	vector<int> ms;
	vector<int> ns;
	vector<double> rs;

	ptrnegcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	// - arc guides
	for (unsigned int i=0;i<ms.size();i++) {
		m = ms[i];
		n = ns[i];
		r = rs[i];

		if (!ronly) {
			// remove element arc guide
			str.str(""); str << "am" << intToPnstr(m) << "_n" << intToPnstr(n);
			opsubArcguide(dbsplnr, refSupdev, refSubdev, str.str(), ags);

			// add new element arc guide
			vsrefs.resize(0);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
			cvsref = str.str();

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());

			str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n);
			opaddArcguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), cvsref, r, vsrefs, vtxs, ags);

		} else {
			str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n);
			addArcguideRByAsref(dbsplnr, str.str(), x1RefPlnrMDesign, r, ags);
		};
	};
};

void PlnrExpPhctrigneg::ptrnegcavfr_faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const double rstart
			, const double rstep
			, const int rN
			, const int M
			, const int N
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	int m, n;
	double r;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// obtain elements to be modified
	vector<int> ms;
	vector<int> ns;
	vector<double> rs;

	ptrnegcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	// traverse elements
	for (unsigned int i=0;i<ms.size();i++) {
		m = ms[i];
		n = ns[i];
		r = rs[i];

		// remove element face
		str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n);
		opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);

		// add alternate element face
		vsrefs.resize(0);
		rtes.resize(0);
		gsrefs.resize(0);
		dirs.resize(0);

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
		str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
		str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

		StrMod::stringToVector("agd;agd", rtes);
		StrMod::stringToVector("fwd;fwd", dirs);

		str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n);
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	};
};

void PlnrExpPhctrigneg::getminmax(
			const int M
			, const int N
			, int& mmin
			, int& mmax
			, int& nmin
			, int& nmax
		) {
	if ((M%2) == 0) {
		// m even
		mmin = -M/2 +1;
		mmax = M/2;
	} else {
		// m odd
		mmin = -(M+1)/2 +1;
		mmax = (M+1)/2 -1;
	};
	if ((N%2) == 0) {
		// n even
		nmin = -N/2 +1;
		nmax = N/2;
	} else {
		// n odd
		nmin = -(N+1)/2 +1;
		nmax = (N+1)/2 -1;
	};
};
// IP cust --- IEND


