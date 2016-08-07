/**
  * \file PlnrExpPhctrig.cpp
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

#include "PlnrExpPhctrig.h"

DpchRetPlnr* PlnrExpPhctrig::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhctrig* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ubigint refTpl;

	vector<ubigint> refsSubdevPtrcav;
	vector<ubigint> refsSubdevPtrcavfr;
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

	// load ptrcav sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "ptrcav", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPtrcav);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'ptrcav'", true, refsSubdevPtrcav);

	// load ptrcavfr sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "ptrcavfr", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPtrcavfr);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'ptrcavfr'", true, refsSubdevPtrcavfr);

	// load baseline parameters
	double r0 = 0.07; double r;
	double a0 = 0.3; double a;
	int M0 = 20; int M;
	int N0 = 20; int N;

	int ptrcav_mstart;
	int ptrcav_mstop;
	int ptrcav_nstart;
	int ptrcav_nstop;

	int ptrcavfr_mstart;
	int ptrcavfr_mstop;
	int ptrcavfr_nstart;
	int ptrcavfr_nstop;
	double ptrcavfr_rstart;
	double ptrcavfr_rstep;
	int ptrcavfr_rN;

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
	for (unsigned int i=0;i<refsSubdevPtrcav.size();i++) {
		refSubdev = refsSubdevPtrcav[i];

		ptrcav_loadpars(dbsplnr, refSubdev, 0, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop);
		ptrcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, vtxs);
		ptrcav_guides(dbsplnr, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, vtxs, lgs, ags);
		ptrcav_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, refSruAll, vtxs, lgs, ags, fces);
	};

	for (unsigned int i=0;i<refsSubdevPtrcavfr.size();i++) {
		refSubdev = refsSubdevPtrcavfr[i];

		ptrcavfr_loadpars(dbsplnr, refSubdev, 0, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN);
		ptrcavfr_vertices(dbsplnr, 0, refPlnrMDevice, refSubdev, false, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, a, M, N, vtxs);
		ptrcavfr_guides(dbsplnr, 0, refPlnrMDevice, refSubdev, false, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, M, N, vtxs, lgs, ags);
		ptrcavfr_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, M, N, refSruAll, vtxs, lgs, ags, fces);
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
		for (unsigned int j=0;j<refsSubdevPtrcav.size();j++) {
			refSubdev = refsSubdevPtrcav[j];

			if (!(modpar & _PTRCAV_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PTRCAV_MSTART;
			if (!(modpar & _PTRCAV_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PTRCAV_MSTOP;
			if (!(modpar & _PTRCAV_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PTRCAV_NSTART;
			if (!(modpar & _PTRCAV_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PTRCAV_NSTOP;
		};
		for (unsigned int j=0;j<refsSubdevPtrcavfr.size();j++) {
			refSubdev = refsSubdevPtrcavfr[j];

			if (!(modpar & _PTRCAVFR_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PTRCAVFR_MSTART;
			if (!(modpar & _PTRCAVFR_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PTRCAVFR_MSTOP;
			if (!(modpar & _PTRCAVFR_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PTRCAVFR_NSTART;
			if (!(modpar & _PTRCAVFR_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PTRCAVFR_NSTOP;
			if (!(modpar & _PTRCAVFR_RSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart")) modpar += _PTRCAVFR_RSTART;
			if (!(modpar & _PTRCAVFR_RSTEP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) modpar += _PTRCAVFR_RSTEP;
			if (!(modpar & _PTRCAVFR_RN)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rN")) modpar += _PTRCAVFR_RN;
		};

		// dto/dnoto modifications, arcguides; all dto incl. those of sub-devices imply new set of vertices, guides and faces
		dbsplnr->begin();

		if (modpar & (_M + _N + _PTRCAV_MSTART + _PTRCAV_MSTOP + _PTRCAV_NSTART + _PTRCAV_NSTOP + _PTRCAVFR_MSTART + _PTRCAVFR_MSTOP + _PTRCAVFR_NSTART + _PTRCAVFR_NSTOP + _PTRCAVFR_RN)) {
			// dto
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, r, a, M, N, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, r, a, M, N, vtxs2, lgs2, ags2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);

			// sub-devices
			for (unsigned int j=0;j<refsSubdevPtrcav.size();j++) {
				refSubdev = refsSubdevPtrcav[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				ptrcav_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop);
				ptrcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, vtxs2);
				ptrcav_guides(dbsplnr, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, vtxs2, lgs2, ags2);
				ptrcav_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, ptrcav_mstart, ptrcav_mstop, ptrcav_nstart, ptrcav_nstop, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);
			};
			for (unsigned int j=0;j<refsSubdevPtrcavfr.size();j++) {
				refSubdev = refsSubdevPtrcavfr[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				ptrcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN);
				ptrcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, a, M, N, vtxs2);
				ptrcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, M, N, vtxs2, lgs2, ags2);
				ptrcavfr_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, M, N, refSruAll, vtxs2, lgs2, ags2, fces2);
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

			if (modpar & (_PTRCAVFR_RSTART + _PTRCAVFR_RSTEP)) {
				for (unsigned int j=0;j<refsSubdevPtrcavfr.size();j++) {
					refSubdev = refsSubdevPtrcavfr[j];

					// act only if dnoto parameters in specific sub-device are modified
					if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart") || dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) {
						addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);

						ptrcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN);
						ptrcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, a, M, N, vtxs);
						ptrcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, ptrcavfr_mstart, ptrcavfr_mstop, ptrcavfr_nstart, ptrcavfr_nstop, ptrcavfr_rstart, ptrcavfr_rstep, ptrcavfr_rN, M, N, vtxs, lgs, ags);
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
void PlnrExpPhctrig::vertices(
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

			// unit cell hexagon vertices
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*dx, y-dy/3.0, vtxs);
			else if (modpar & _A) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*dx, y-0.5*dy, vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-2.0*dy/3.0, vtxs);
			else if (modpar & _A) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-2.0*dy/3.0, vtxs);
		};
	};

	// - additional vertices at boundaries
	if ((!xyonly) || (xyonly && (modpar & _A))) {
		// 'a' column for (mmin .. mmax, nmax+1) [1]
		for (int m=mmin;m<=mmax;m++) {
			x = ((double) (nmax+1)) * dx;
			if ((m%2) != 0) x += 0.5*dx;

			y = ((double) m) * dy;

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(nmax+1) << "_a";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*dx, y-dy/3.0, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*dx, y-dy/3.0, vtxs);
		};

		if ((mmax%2) == 0) {
			// even top row
			y = ((double) (mmax+1)) * dy;

			// 'a' row for (mmax+1, nmin .. nmax) [3]
			for (int n=nmin;n<=nmax;n++) {
				x = ((double) n)*dx + 0.5*dx;

				str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_a";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*dx, y-dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*dx, y-dy/3.0, vtxs);
			};

			// 'b' row for (mmax+1, nmin-1 .. nmax) [2]
			for (int n=(nmin-1);n<=nmax;n++) {
				x = ((double) n)*dx + 0.5*dx;

				str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-2.0*dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-2.0*dy/3.0, vtxs);
			};

		} else {
			// odd top row
			y = ((double) (mmax+1)) * dy;

			// 'a' row for (mmax+1, nmin+1 .. nmax+1) [5]
			for (int n=(nmin+1);n<=(nmax+1);n++) {
				x = ((double) n) * dx;

				str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_a";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*dx, y-dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*dx, y-dy/3.0, vtxs);
			};

			// 'b' row for (mmax+1, nmin .. nmax+1) [6]
			for (int n=nmin;n<=(nmax+1);n++) {
				x = ((double) n) * dx;

				str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-2.0*dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-2.0*dy/3.0, vtxs);
			};
		};

		for (int m=mmin;m<mmax;m++) {
			y = ((double) (m+1)) * dy;

			if ((m%2) == 0) {
				// even row, 'b' for (m+1, nmin-1) [4]
				x = ((double) (nmin-1)) * dx;
				if ((m%2) == 0) x += 0.5*dx;

				str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(nmin-1) << "_b";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-2.0*dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-2.0*dy/3.0, vtxs);

			} else {
				// odd row, 'b' for (m+1, nmax+1) [7]
				x = ((double) (nmax+1)) * dx;
				if ((m%2) == 0) x += 0.5*dx;

				str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(nmax+1) << "_b";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-2.0*dy/3.0, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-2.0*dy/3.0, vtxs);
			};
		};
	};
};

void PlnrExpPhctrig::guides(
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

	// -- line guides
	if (!ronly) {
		int m, n, v, da, db;

		// - lv vertical line guides
		for (v=2*nmin;v<=(2*nmax+1);v++) {
			// elements at n are divided in half by this line guide
			if ((v%2) == 0) n = v/2; else n = (v-1)/2;

			vsrefs.resize(0);

			// initial vertex
			if ((v%2) == 0) {
				// even line guide
				if ((mmax%2) == 0) {
					// even top row
					str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
				} else {
					// odd top row
					str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
				};

			} else {
				// odd line guide
				if ((mmax%2) == 0) {
					// even top row
					str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
				} else {
					// odd top row
					str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
				};
			};

			// interior vertices
			for (m=mmax;m>=mmin;m--) {
				if ((v%2) == 0) {
					// even line guide
					if ((m%2) == 0) {
						// even row
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
					} else {
						// odd row
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
					};

				} else {
					// odd line guide
					if ((m%2) == 0) {
						// even row
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
					} else {
						// odd row
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
					};
				};

			};
			
			// create line guide
			str.str(""); str << "lv" << intToPnstr(v);
			addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);
		};

		// west guide (contributions of even rows only)
		v = 2*nmin - 1; // always odd
		n = (v-1)/2;
		vsrefs.resize(0);

		for (m=mmax;m>=mmin;m--) {
			if ((m%2) == 0) {
				str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
			};
		};

		str.str(""); str << "lv" << intToPnstr(v);
		addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);

		// east guide (contributions of odd rows only)
		v = 2*nmax + 2; // always even
		n = v/2;
		vsrefs.resize(0);

		for (m=mmax;m>=mmin;m--) {
			if ((m%2) != 0) {
				str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
			};
		};

		str.str(""); str << "lv" << intToPnstr(v);
		addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);

		// - lda diagonal line guides

		// top row
		for (n=nmin;n<=nmax;n++) {
			// begin in north vertex - transform into (da,db) coordinates 
			mnToDadb(mmax, n, da, db); // center vertex of (mmax,n)
			da += 1; db += 1;
			addLda(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmin, nmax, vtxs, lgs);
		};

		// west
		for (m=mmin;m<=mmax;m++) {
			// begin in sw vertex
			mnToDadb(m, nmin, da, db);
			da -= 1;
			addLda(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmin, nmax, vtxs, lgs);

			if ((m%2) == 0) {
				// even row, begin in nw vertex
				mnToDadb(m, nmin, da, db);
				db += 1;
				addLda(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmin, nmax, vtxs, lgs);
			};
		};

		// device nw corner for odd last row
		if ((mmax%2) != 0) {
			// begin in nw vertex
			mnToDadb(mmax, nmin, da, db);
			db += 1;
			addLda(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmin, nmax, vtxs, lgs);
		};

		// - ldb diagonal line guides

		// bottom row
		for (n=nmin;n<=nmax;n++) {
			// begin in south vertex - transform into (da,db) coordinates 
			mnToDadb(mmin, n, da, db); // center vertex of (mmin,n)
			da -= 1; db -= 1;
			addLdb(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmax, nmax, vtxs, lgs);
		};

		// west
		for (m=mmin;m<=mmax;m++) {
			// begin in nw vertex
			mnToDadb(m, nmin, da, db);
			db += 1;
			addLdb(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmax, nmax, vtxs, lgs);

			if ((m%2) == 0) {
				// even row, begin in sw vertex
				mnToDadb(m, nmin, da, db);
				da -= 1;
				addLdb(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmax, nmax, vtxs, lgs);
			};
		};

		// device sw corner for odd first row
		if ((mmin%2) != 0) {
			// begin in sw vertex
			mnToDadb(mmin, nmin, da, db);
			da -= 1;
			addLdb(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, da, db, mmax, nmax, vtxs, lgs);
		};
	};

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

void PlnrExpPhctrig::faces(
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

	int v, da, db;

	for (int m=mmin;m<=mmax;m++) {
		for (int n=nmin;n<=nmax;n++) {
			// - affine coordinate transform for guide indices
			mnToDadbv(m, n, da, db, v);

			// - element west face
			strrefs.push_back(refSruAll);

			str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
			fsrefs.push_back(str.str());

			// vertex line-up
			str.str("");
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a;";
			if ((m%2) == 0) {
				// m even
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b;";
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a;";
			} else {
				// m odd
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_b;";
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a;";
			};
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			vsrefsstrs.push_back(str.str());

			rtesstrs.push_back("lgd;lgd;lgd;lgd;agd;lgd");

			// guide line-up
			str.str("");
			str << "ldb" << intToPnstr(db-1) << ";";
			str << "lv" << intToPnstr(v+1) << ";";
			str << "lda" << intToPnstr(da+1) << ";";
			str << "lv" << intToPnstr(v) << ";";
			str << "am" << intToPnstr(m) << "_n" << intToPnstr(n) << ";";
			str << "lv" << intToPnstr(v);
			gsrefsstrs.push_back(str.str());

			dirsstrs.push_back("fwd;bwd;bwd;fwd;bwd;fwd");

			// - element east face
			strrefs.push_back(refSruAll);

			str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			fsrefs.push_back(str.str());

			// vertex line-up
			str.str("");
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1;";
			if ((m%2) == 0) {
				// m even
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a;";
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n-1) << "_b;";
			} else {
				// m odd
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a;";
				str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b;";
			};
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a";
			vsrefsstrs.push_back(str.str());

			rtesstrs.push_back("lgd;agd;lgd;lgd;lgd;lgd");

			// guide line-up
			str.str("");
			str << "lv" << intToPnstr(v) << ";";
			str << "am" << intToPnstr(m) << "_n" << intToPnstr(n) << ";";
			str << "lv" << intToPnstr(v) << ";";
			str << "ldb" << intToPnstr(db+1) << ";";
			str << "lv" << intToPnstr(v-1) << ";";
			str << "lda" << intToPnstr(da-1);
			gsrefsstrs.push_back(str.str());

			dirsstrs.push_back("bwd;bwd;bwd;bwd;fwd;fwd");
		};
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};

void PlnrExpPhctrig::ptrcav_loadpars(
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

void PlnrExpPhctrig::ptrcav_vertices(
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

void PlnrExpPhctrig::ptrcav_guides(
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

void PlnrExpPhctrig::ptrcav_faces(
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

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	int v, da, db;

	// traverse elements
	for (int m=mstart;m<=mstop;m++) {
		if ((m>=mmin) && (m<=mmax)) {
			for (int n=nstart;n<=nstop;n++) {
				if ((n>=nmin) && (n<=nmax)) {

					// remove element faces 0 and 1
					str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
					opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);

					str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
					opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);

					// add alternate element face
					mnToDadbv(m, n, da, db, v);

					vsrefs.resize(0);
					rtes.resize(0);
					gsrefs.resize(0);
					dirs.resize(0);

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
					str.str(""); str << "ldb" << intToPnstr(db-1); gsrefs.push_back(str.str());

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

					if ((m%2) == 0) {
						// m even
						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
						str.str(""); str << "lda" << intToPnstr(da+1); gsrefs.push_back(str.str());

						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
						str.str(""); str << "ldb" << intToPnstr(db+1); gsrefs.push_back(str.str());

						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n-1) << "_b"; vsrefs.push_back(str.str());
						str.str(""); str << "lv" << intToPnstr(v-1); gsrefs.push_back(str.str());

					} else {
						// m odd
						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_b"; vsrefs.push_back(str.str());
						str.str(""); str << "lda" << intToPnstr(da+1); gsrefs.push_back(str.str());

						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
						str.str(""); str << "ldb" << intToPnstr(db+1); gsrefs.push_back(str.str());

						str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
						str.str(""); str << "lv" << intToPnstr(v-1); gsrefs.push_back(str.str());
					};

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lda" << intToPnstr(da-1); gsrefs.push_back(str.str());

					StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd", rtes);
					StrMod::stringToVector("fwd;bwd;bwd;bwd;fwd;fwd", dirs);

					str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n);
					opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
				};
			};
		};
	};
};

void PlnrExpPhctrig::ptrcavfr_loadpars(
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

void PlnrExpPhctrig::ptrcavfr_getelems(
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

void PlnrExpPhctrig::ptrcavfr_vertices(
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

	ptrcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

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

void PlnrExpPhctrig::ptrcavfr_guides(
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

	int m, n, v;
	double r;

	string lsref;
	string vsreforig;
	string vsrefrepl;

	string cvsref;
	vector<string> vsrefs;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// obtain elements to be modified
	vector<int> ms;
	vector<int> ns;
	vector<double> rs;

	ptrcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	// - line guides
	if (!ronly) {
		for (unsigned int i=0;i<ms.size();i++) {
			m = ms[i];
			n = ns[i];

			if ((m%2) == 0) v = 2*n; else v = 2*n+1;
			str.str(""); str << "lv" << intToPnstr(v); lsref = str.str();

			// replace vertices 1 and 2 on vertical line guide
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsreforig = str.str();
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefrepl = str.str();
			opaddLgdVtxAtVsrefNum(dbsplnr, refSubdev, lsref, vsreforig, vsrefrepl, vtxs, lgs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsreforig = str.str();
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefrepl = str.str();
			opaddLgdVtxAtVsrefNum(dbsplnr, refSubdev, lsref, vsreforig, vsrefrepl, vtxs, lgs);
		};
	};

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

void PlnrExpPhctrig::ptrcavfr_faces(
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

	ptrcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	int v, da, db;

	// traverse elements
	for (unsigned int i=0;i<ms.size();i++) {
		m = ms[i];
		n = ns[i];
		r = rs[i];

		// remove element faces 0 and 1
		str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
		opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);

		str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
		opsubFace(dbsplnr, refSubdev, str.str(), refSruAll, fces);

		// add alternate element faces
		mnToDadbv(m, n, da, db, v);

		// - element west face
		vsrefs.resize(0);
		rtes.resize(0);
		gsrefs.resize(0);
		dirs.resize(0);

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "ldb" << intToPnstr(db-1); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

		if ((m%2) == 0) {
			// m even
			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
			str.str(""); str << "lda" << intToPnstr(da+1); gsrefs.push_back(str.str());

			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
			str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());
		} else {
			// m odd
			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_b"; vsrefs.push_back(str.str());
			str.str(""); str << "lda" << intToPnstr(da+1); gsrefs.push_back(str.str());

			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
			str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());
		};

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
		str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());

		StrMod::stringToVector("lgd;lgd;lgd;lgd;agd;lgd", rtes);
		StrMod::stringToVector("fwd;bwd;bwd;fwd;bwd;fwd", dirs);

		str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);

		// - element east face
		vsrefs.resize(0);
		rtes.resize(0);
		gsrefs.resize(0);
		dirs.resize(0);

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
		str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());

		if ((m%2) == 0) {
			// m even
			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
			str.str(""); str << "ldb" << intToPnstr(db+1); gsrefs.push_back(str.str());

			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n-1) << "_b"; vsrefs.push_back(str.str());
			str.str(""); str << "lv" << intToPnstr(v-1); gsrefs.push_back(str.str());
		} else {
			// m odd
			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
			str.str(""); str << "ldb" << intToPnstr(db+1); gsrefs.push_back(str.str());

			str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
			str.str(""); str << "lv" << intToPnstr(v-1); gsrefs.push_back(str.str());
		};

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lda" << intToPnstr(da-1); gsrefs.push_back(str.str());

		StrMod::stringToVector("lgd;agd;lgd;lgd;lgd;lgd", rtes);
		StrMod::stringToVector("bwd;bwd;bwd;bwd;fwd;fwd", dirs);

		str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	};
};

void PlnrExpPhctrig::getminmax(
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

void PlnrExpPhctrig::addLda(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint hkUref
			, const int da
			, const int db0
			, const int mmin
			, const int nmax
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;
	bool found;

	int m, n;
	bool va, vb, vc;

	vector<string> vsrefs;

	PlnrMVertex* vtx = NULL;

	// scan db while leaving da constant
	found = true;
	for (int db=db0;found;) {
		dadbToMn(da, db, m, n, va, vb, vc);

		// compose vertex sref
		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n);

		if (va) str << "_a";
		else if (vb) str << "_b";
		else if (vc) str << "_0";

		// check if out of regular range
		if ((m<mmin) || (n>nmax)) {
			if (vc) break; // center vertex doesn't exist

			// check if vertex is listed
			found = false;
			for (unsigned int i=0;i<vtxs.nodes.size();i++) {
				vtx = vtxs.nodes[i];

				if (vtx->sref.compare(str.str()) == 0) {
					found = true;
					break;
				};
			};
		};

		if (found) {
			// add vertex and move on
			vsrefs.push_back(str.str());
			db--;
		};
	};

	// create line guide
	str.str(""); str << "lda" << intToPnstr(da);
	addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, hkUref, str.str(), vsrefs, vtxs, lgs);
};

void PlnrExpPhctrig::addLdb(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint hkUref
			, const int da0
			, const int db
			, const int mmax
			, const int nmax
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;
	bool found;

	int m, n;
	bool va, vb, vc;

	vector<string> vsrefs;

	PlnrMVertex* vtx = NULL;

	// scan da while leaving db constant
	found = true;
	for (int da=da0;found;) {
		dadbToMn(da, db, m, n, va, vb, vc);

		// compose vertex sref
		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n);

		if (va) str << "_a";
		else if (vb) str << "_b";
		else if (vc) str << "_0";

		// check if out of regular range
		if ((m>mmax) || (n>nmax)) {
			if (vc) break; // center vertex doesn't exist

			// check if vertex is listed
			found = false;
			for (unsigned int i=0;i<vtxs.nodes.size();i++) {
				vtx = vtxs.nodes[i];

				if (vtx->sref.compare(str.str()) == 0) {
					found = true;
					break;
				};
			};
		};

		if (found) {
			// add vertex and move on
			vsrefs.push_back(str.str());
			da++;
		};
	};

	// create line guide
	str.str(""); str << "ldb" << intToPnstr(db);
	addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, hkUref, str.str(), vsrefs, vtxs, lgs);
};

void PlnrExpPhctrig::dadbToMn(
			int da
			, int db
			, int& m
			, int& n
			, bool& va
			, bool& vb
			, bool& vc
		) {
	int damod = (da%3); if (damod < 0) damod += 3;
	int dbmod = (db%3); if (dbmod < 0) dbmod += 3;

	// categorize resulting vertex as a,b,c
	va = ((damod + dbmod) == 2);
	vb = (((damod + dbmod)%3) == 1);
	vc = (((damod + dbmod)%3) == 0);

	// reduce to 3x3 grid
	da = da-damod;
	db = db-dbmod;

	// affine transform
	m = da/3 + db/3;
	n = da - db; // x2

	// odd row adjust
	if ((m%2) != 0) n -= 1;
	n /= 2;

	// final transform to m,n host element
	if ((m%2) == 0) {
		// even row
		if (damod == 0) {
			if (dbmod == 0) {}
			else if (dbmod == 1) {m+=1;n-=1;}
			else if (dbmod == 2) {m+=1;n-=1;};

		} else if (damod == 1) {
			if (dbmod == 0) {m+=1;}
			else if (dbmod == 1) {m+=1;}
			else if (dbmod == 2) {m+=1;n-=1;};

		} else if (damod == 2) {
			if (dbmod == 0) {m+=1;n+=1;}
			else if (dbmod == 1) {m+=1;}
			else if (dbmod == 2) {m+=2;};
		};

	} else {
		// odd row
		if (damod == 0) {
			if (dbmod == 0) {}
			else if (dbmod == 1) {m+=1;n+=0;}
			else if (dbmod == 2) {m+=1;n+=0;};

		} else if (damod == 1) {
			if (dbmod == 0) {m+=1;n+=1;}
			else if (dbmod == 1) {m+=1;n+=1;}
			else if (dbmod == 2) {m+=1;n+=0;};

		} else if (damod == 2) {
			if (dbmod == 0) {m+=1;n+=2;}
			else if (dbmod == 1) {m+=1;n+=1;}
			else if (dbmod == 2) {m+=2;};
		};
	};
};

void PlnrExpPhctrig::mnToDadb(
			const int m
			, const int n
			, int& da
			, int& db
		) {
	if ((m%2) == 0) {
		da = (3*m)/2 + n;
		db = (3*m)/2 - n;
	} else {
		da = (3*m + 2*n + 1) / 2;
		db = (3*m - 2*n - 1) / 2;
	};
};

void PlnrExpPhctrig::mnToDadbv(
			const int m
			, const int n
			, int& da
			, int& db
			, int& v
		) {
	if ((m%2) == 0) {
		v = 2*n;
		da = (3*m)/2 + n;
		db = (3*m)/2 - n;
	} else {
		v = 2*n+1;
		da = (3*m + 2*n + 1) / 2;
		db = (3*m - 2*n - 1) / 2;
	};
};
// IP cust --- IEND


