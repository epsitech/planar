/**
  * \file PlnrExpPhcsq.cpp
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

#include "PlnrExpPhcsq.h"

DpchRetPlnr* PlnrExpPhcsq::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhcsq* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ubigint refTpl;

	vector<ubigint> refsSubdevPsqcav;
	vector<ubigint> refsSubdevPsqcavfr;
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

	// load psqcav sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "psqcav", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPsqcav);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'psqcav'", true, refsSubdevPsqcav);

	// load psqcavfr sub-device refs
	dbsplnr->tblplnrmdevice->loadRefByTplSrf(0, "psqcavfr", refTpl);
	dbsplnr->tblplnrmdevice->loadRefsBySupTpl(refPlnrMDevice, refTpl, false, refsSubdevPsqcavfr);
	dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(refPlnrMDevice) + " AND tplRefPlnrMDevice = 0 AND sref = 'psqcavfr'", true, refsSubdevPsqcavfr);

	// load baseline parameters
	double r0 = 0.07; double r;
	double a0 = 0.3; double a;
	int M0 = 20; int M;
	int N0 = 20; int N;
	bool sqhole0 = false; bool sqhole;

	int psqcav_mstart;
	int psqcav_mstop;
	int psqcav_nstart;
	int psqcav_nstop;

	int psqcavfr_mstart;
	int psqcavfr_mstop;
	int psqcavfr_nstart;
	int psqcavfr_nstop;
	double psqcavfr_rstart;
	double psqcavfr_rstep;
	int psqcavfr_rN;

	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "r", r0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "a", a0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "M", M0);
	loadIntDevpar(dbsplnr, refPlnrMDevice, 0, "N", N0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "sqhole", sqhole0);

	// --- expand baseline
	r = r0;
	a = a0;
	M = M0;
	N = N0;
	sqhole = sqhole0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, 0, r, a, M, N, sqhole, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, false, r, a, M, N, sqhole, vtxs, lgs, ags);
	faces(dbsplnr, 0, refPlnrMDevice, M, N, sqhole, refSruAll, vtxs, lgs, ags, fces);

	// sub-devices
	for (unsigned int i=0;i<refsSubdevPsqcav.size();i++) {
		refSubdev = refsSubdevPsqcav[i];

		psqcav_loadpars(dbsplnr, refSubdev, 0, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop);
		psqcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, vtxs);
		psqcav_guides(dbsplnr, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, vtxs, lgs, ags);
		psqcav_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, refSruAll, vtxs, lgs, ags, fces);
	};

	for (unsigned int i=0;i<refsSubdevPsqcavfr.size();i++) {
		refSubdev = refsSubdevPsqcavfr[i];

		psqcavfr_loadpars(dbsplnr, refSubdev, 0, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN);
		psqcavfr_vertices(dbsplnr, 0, refPlnrMDevice, refSubdev, false, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, a, M, N, sqhole, vtxs);
		psqcavfr_guides(dbsplnr, 0, refPlnrMDevice, refSubdev, false, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, M, N, sqhole, vtxs, lgs, ags);
		psqcavfr_faces(dbsplnr, 0, refPlnrMDevice, refSubdev, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, M, N, sqhole, refSruAll, vtxs, lgs, ags, fces);
	};

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);
	dbsplnr->loadRefsBySQL("SELECT x1RefPlnrMDesign FROM TblPlnrMDevice, TblPlnrAMDevicePar WHERE TblPlnrAMDevicePar.refPlnrMDevice = TblPlnrMDevice.ref AND TblPlnrMDevice.supRefPlnrMDevice = " + to_string(refPlnrMDevice)
				+ " AND x1RefPlnrMDesign <> 0", true, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		r = r0;
		a = a0;
		M = M0;
		N = N0;
		sqhole = sqhole0;

		modpar = 0;

		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "r", r)) modpar += _R;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "a", a)) modpar += _A;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "M", M)) modpar += _M;
		if (loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "N", N)) modpar += _N;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "sqhole", sqhole)) modpar += _SQHOLE;

		// check for sub-device modified parameters
		for (unsigned int j=0;j<refsSubdevPsqcav.size();j++) {
			refSubdev = refsSubdevPsqcav[j];

			if (!(modpar & _PSQCAV_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PSQCAV_MSTART;
			if (!(modpar & _PSQCAV_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PSQCAV_MSTOP;
			if (!(modpar & _PSQCAV_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PSQCAV_NSTART;
			if (!(modpar & _PSQCAV_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PSQCAV_NSTOP;
		};
		for (unsigned int j=0;j<refsSubdevPsqcavfr.size();j++) {
			refSubdev = refsSubdevPsqcavfr[j];

			if (!(modpar & _PSQCAVFR_MSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstart")) modpar += _PSQCAVFR_MSTART;
			if (!(modpar & _PSQCAVFR_MSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "mstop")) modpar += _PSQCAVFR_MSTOP;
			if (!(modpar & _PSQCAVFR_NSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstart")) modpar += _PSQCAVFR_NSTART;
			if (!(modpar & _PSQCAVFR_NSTOP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "nstop")) modpar += _PSQCAVFR_NSTOP;
			if (!(modpar & _PSQCAVFR_RSTART)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart")) modpar += _PSQCAVFR_RSTART;
			if (!(modpar & _PSQCAVFR_RSTEP)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) modpar += _PSQCAVFR_RSTEP;
			if (!(modpar & _PSQCAVFR_RN)) if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rN")) modpar += _PSQCAVFR_RN;
		};

		// dto/dnoto modifications, arcguides; all dto incl. those of sub-devices imply new set of vertices, guides and faces
		dbsplnr->begin();

		if (modpar & (_M + _N + _SQHOLE + _PSQCAV_MSTART + _PSQCAV_MSTOP + _PSQCAV_NSTART + _PSQCAV_NSTOP + _PSQCAVFR_MSTART + _PSQCAVFR_MSTOP + _PSQCAVFR_NSTART + _PSQCAVFR_NSTOP + _PSQCAVFR_RN)) {
			// dto
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, modpar, r, a, M, N, sqhole, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, r, a, M, N, sqhole, vtxs2, lgs2, ags2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, M, N, sqhole, refSruAll, vtxs2, lgs2, ags2, fces2);

			// sub-devices
			for (unsigned int j=0;j<refsSubdevPsqcav.size();j++) {
				refSubdev = refsSubdevPsqcav[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				psqcav_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop);
				psqcav_vertices(dbsplnr, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, vtxs2);
				psqcav_guides(dbsplnr, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, vtxs2, lgs2, ags2);
				psqcav_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, psqcav_mstart, psqcav_mstop, psqcav_nstart, psqcav_nstop, M, N, sqhole, refSruAll, vtxs2, lgs2, ags2, fces2);
			};
			for (unsigned int j=0;j<refsSubdevPsqcavfr.size();j++) {
				refSubdev = refsSubdevPsqcavfr[j];

				addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);

				psqcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN);
				psqcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, a, M, N, sqhole, vtxs2);
				psqcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, false, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, M, N, sqhole, vtxs2, lgs2, ags2);
				psqcavfr_faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, M, N, sqhole, refSruAll, vtxs2, lgs2, ags2, fces2);
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

			if (modpar & (_R + _A)) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, modpar, r, a, M, N, sqhole, vtxs);
			if (modpar & _R) guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, r, a, M, N, sqhole, vtxs, lgs, ags);

			if (modpar & (_PSQCAVFR_RSTART + _PSQCAVFR_RSTEP)) {
				for (unsigned int j=0;j<refsSubdevPsqcavfr.size();j++) {
					refSubdev = refsSubdevPsqcavfr[j];

					// act only if dnoto parameters in specific sub-device are modified
					if (dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstart") || dbsplnr->tblplnramdevicepar->confirmByDevDsnKey(refSubdev, x1RefPlnrMDesign, "rstep")) {
						addDevModtype(dbsplnr, refSubdev, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);

						psqcavfr_loadpars(dbsplnr, refSubdev, x1RefPlnrMDesign, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN);
						psqcavfr_vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, a, M, N, sqhole, vtxs);
						psqcavfr_guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, refSubdev, true, psqcavfr_mstart, psqcavfr_mstop, psqcavfr_nstart, psqcavfr_nstop, psqcavfr_rstart, psqcavfr_rstep, psqcavfr_rN, M, N, sqhole, vtxs, lgs, ags);
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
void PlnrExpPhcsq::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const unsigned int modpar
			, const double r
			, const double a
			, const int M
			, const int N
			, const bool sqhole
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	double x, y;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// - element vertices (row loop, then column loop)
	for (int m=mmin;m<=mmax;m++) {
		y = ((double) m) * a;

		for (int n=nmin;n<=nmax;n++) {
			x = ((double) n) * a;

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

			// additional element vertices for square holes
			if (sqhole) {
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-r, y-r, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-r, y-r, vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x+r, y-r, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x+r, y-r, vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x+r, y+r, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x+r, y+r, vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-r, y+r, vtxs);
				else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-r, y+r, vtxs);
			};

			// unit cell square vertices
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*a, y-0.5*a, vtxs);
			else if (modpar & _A) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*a, y-0.5*a, vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-0.5*a, vtxs);
			else if (modpar & _A) addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-0.5*a, vtxs);
		};
	};

	// - additional vertices at boundaries
	if ((!xyonly) || (xyonly && (modpar & _A))) {
		// 'a' column for (mmin .. mmax+1, nmax+1)
		x = ((double) (nmax+1)) * a;

		for (int m=mmin;m<=mmax+1;m++) {
			y = ((double) m) * a;

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(nmax+1) << "_a";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*a, y-0.5*a, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*a, y-0.5*a, vtxs);
		};

		// 'a' row for (mmax+1, nmin .. nmax)
		y = ((double) (mmax+1)) * a;

		for (int n=nmin;n<=nmax;n++) {
			x = ((double) n) * a;

			str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_a";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x-0.5*a, y-0.5*a, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-0.5*a, y-0.5*a, vtxs);
		};

		// 'b' row for (mmax+1, nmin .. nmax)
		y = ((double) (mmax+1)) * a;

		for (int n=nmin;n<=nmax;n++) {
			x = ((double) n) * a;

			str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b";
			if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), x, y-0.5*a, vtxs);
			else addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-0.5*a, vtxs);
		};
	};
};

void PlnrExpPhcsq::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool ronly
			, const double r
			, const double a
			, const int M
			, const int N
			, const bool sqhole
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str, str2;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	vector<string> lsrefs;

	vector<string> asrefs;
	vector<string> vsrefs;
	vector<double> rs;

	// -- line guides
	if (!ronly) {
		int m, n, v;

		// - lh horizontal line guides (includes last guide on top)
		for (m=mmin;m<=(mmax+1);m++) {
			vsrefs.resize(0);

			for (n=nmin;n<=nmax;n++) {
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
			};

			// final vertex
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(nmax+1) << "_a"; vsrefs.push_back(str.str());

			// create line guide
			str.str(""); str << "lh" << intToPnstr(m);
			addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);
		};

		// - lv vertical line guides (includes last guide to the right)
		for (v=2*nmin;v<=(2*nmax+2);v++) {
			// odd v divide elements in half
			if ((v%2) == 0) n = v/2; else n = (v-1)/2;

			vsrefs.resize(0);

			if ((v%2) == 0) {
				// 'a' vertices only
				for (m=mmax+1;m>=mmin;m--) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
				};

			} else {
				// initial vertex
				str.str(""); str << "vm" << intToPnstr(mmax+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());

				// '1', '0', '2', 'b' vertices
				for (m=mmax;m>=mmin;m--) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
				};
			};

			// create line guide
			str.str(""); str << "lv" << intToPnstr(v);
			addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);
		};

		if (sqhole) {
			for (m=mmin;m<=mmax;m++) {
				// - ln interior horizontal line guide
				vsrefs.resize(0);

				for (n=nmin;n<=nmax;n++) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne"; vsrefs.push_back(str.str());
				};

				// create line guide
				str.str(""); str << "ln" << intToPnstr(m);
				addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);

				// - ls interior horizontal line guide
				vsrefs.resize(0);

				for (n=nmin;n<=nmax;n++) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se"; vsrefs.push_back(str.str());
				};

				// create line guide
				str.str(""); str << "ls" << intToPnstr(m);
				addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);
			};

			for (n=nmin;n<=nmax;n++) {
				// - lw interior vertical line guide
				vsrefs.resize(0);

				for (m=mmax;m>=mmin;m--) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw"; vsrefs.push_back(str.str());
				};

				// create line guide
				str.str(""); str << "lw" << intToPnstr(n);
				addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);

				// - le interior vertical line guide
				vsrefs.resize(0);

				for (m=mmax;m>=mmin;m--) {
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne"; vsrefs.push_back(str.str());
					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se"; vsrefs.push_back(str.str());
				};

				// create line guide
				str.str(""); str << "le" << intToPnstr(n);
				addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vsrefs, vtxs, lgs);
			};
		};
	};

	// -- arc guides
	if (!sqhole) {
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
};

void PlnrExpPhcsq::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int M
			, const int N
			, const bool sqhole
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

	int v;

	for (int m=mmin;m<=mmax;m++) {
		for (int n=nmin;n<=nmax;n++) {
			v = 2*n;

			// - element west face
			strrefs.push_back(refSruAll);

			str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
			fsrefs.push_back(str.str());

			// vertex line-up
			str.str("");
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2;";
			if (sqhole) {
				str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw;";
				str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw;";
			};
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1;";
			str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a";
			vsrefsstrs.push_back(str.str());

			if (sqhole) rtesstrs.push_back("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
			else rtesstrs.push_back("lgd;agd;lgd;lgd;lgd;lgd");

			// guide line-up
			str.str("");
			str << "lv" << intToPnstr(v+1) << ";";
			if (sqhole) {
				str << "ls" << intToPnstr(m) << ";";
				str << "lw" << intToPnstr(n) << ";";
				str << "ln" << intToPnstr(m) << ";";
			} else {
				str << "am" << intToPnstr(m) << "_n" << intToPnstr(n) << ";";
			};
			str << "lv" << intToPnstr(v+1) << ";";
			str << "lh" << intToPnstr(m+1) << ";";
			str << "lv" << intToPnstr(v) << ";";
			str << "lh" << intToPnstr(m);
			gsrefsstrs.push_back(str.str());

			if (sqhole) dirsstrs.push_back("bwd;bwd;bwd;fwd;bwd;bwd;fwd;fwd");
			else dirsstrs.push_back("bwd;bwd;bwd;bwd;fwd;fwd");

			// - element east face
			strrefs.push_back(refSruAll);

			str.str(""); str << "fm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			fsrefs.push_back(str.str());

			// vertex line-up
			str.str("");
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a;";
			str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a;";
			str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b;";
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1;";
			if (sqhole) {
				str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne;";
				str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se;";
			};
			str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			vsrefsstrs.push_back(str.str());

			if (sqhole) rtesstrs.push_back("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd");
			else rtesstrs.push_back("lgd;lgd;lgd;lgd;agd;lgd");

			// guide line-up
			str.str("");
			str << "lh" << intToPnstr(m) << ";";
			str << "lv" << intToPnstr(v+2) << ";";
			str << "lh" << intToPnstr(m+1) << ";";
			str << "lv" << intToPnstr(v+1) << ";";
			if (sqhole) {
				str << "ln" << intToPnstr(m) << ";";
				str << "le" << intToPnstr(n) << ";";
				str << "ls" << intToPnstr(m) << ";";
			} else {
				str << "am" << intToPnstr(m) << "_n" << intToPnstr(n) << ";";
			};
			str << "lv" << intToPnstr(v+1);
			gsrefsstrs.push_back(str.str());

			if (sqhole) dirsstrs.push_back("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd");
			else dirsstrs.push_back("fwd;bwd;bwd;fwd;bwd;fwd");
		};
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};

void PlnrExpPhcsq::psqcav_loadpars(
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

void PlnrExpPhcsq::psqcav_vertices(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const int M
			, const int N
			, const bool sqhole
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

					// remove additional element vertices for square holes
					if (sqhole) {
						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
						opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
						opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
						opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

						str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
						opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);
					};
				};
			};
		};
	};
};

void PlnrExpPhcsq::psqcav_guides(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const int mstart
			, const int mstop
			, const int nstart
			, const int nstop
			, const int M
			, const int N
			, const bool sqhole
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
			, ListPlnrMArcguide& ags
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	if (!sqhole) {
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
};

void PlnrExpPhcsq::psqcav_faces(
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
			, const bool sqhole
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

	int v;

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
					v = 2*n;

					vsrefs.resize(0);
					rtes.resize(0);
					gsrefs.resize(0);
					dirs.resize(0);

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lh" << intToPnstr(m); gsrefs.push_back(str.str());

					str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lv" << intToPnstr(v+2); gsrefs.push_back(str.str());

					str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lh" << intToPnstr(m+1); gsrefs.push_back(str.str());

					str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
					str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());

					StrMod::stringToVector("lgd;lgd;lgd;lgd", rtes);
					StrMod::stringToVector("fwd;bwd;bwd;fwd", dirs);

					str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n);
					opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
				};
			};
		};
	};
};

void PlnrExpPhcsq::psqcavfr_loadpars(
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

void PlnrExpPhcsq::psqcavfr_getelems(
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

	int i;
	double r;

	ms.resize(0);
	ns.resize(0);
	rs.resize(0);

	// - growing (in radius) frames around cavity
	for (i=0, r=rstart ; i<rN ; i++, r+=rstep) {
		// west column
		n = nstart-i-1;
		if ((n >= nmin) && (n <= nmax)) {
			for (m = (mstart-i) ; m <= (mstop+i) ; m++) {
				if ((m >= mmin) && (m <= mmax)) {
					ms.push_back(m);
					ns.push_back(n);
					rs.push_back(r);
				};
			};
		};

		// east column
		n = nstop+i+1;
		if ((n >= nmin) && (n <= nmax)) {
			for (m = (mstart-i) ; m <= (mstop+i) ; m++) {
				if ((m >= mmin) && (m <= mmax)) {
					ms.push_back(m);
					ns.push_back(n);
					rs.push_back(r);
				};
			};
		};

		// south row
		m = mstart-i-1;
		if ((m >= mmin) && (m <= mmax)) {
			for (n = (nstart-i-1) ; n <= (nstop+i+1) ; n++) {
				if ((n >= nmin) && (n <= nmax)) {
					ms.push_back(m);
					ns.push_back(n);
					rs.push_back(r);
				};
			};
		};

		// north row
		m = mstop+i+1;
		if ((m >= mmin) && (m <= mmax)) {
			for (n = (nstart-i-1) ; n <= (nstop+i+1) ; n++) {
				if ((n >= nmin) && (n <= nmax)) {
					ms.push_back(m);
					ns.push_back(n);
					rs.push_back(r);
				};
			};
		};
	};
};

void PlnrExpPhcsq::psqcavfr_vertices(
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
			, const bool sqhole
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	int mmin, mmax, nmin, nmax;
	getminmax(M, N, mmin, mmax, nmin, nmax);

	// obtain elements to be modified
	vector<int> ms;
	vector<int> ns;
	vector<double> rs;

	psqcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	// traverse elements
	int m, n;
	double r;

	double x, y;

	for (unsigned int i=0;i<ms.size();i++) {
		m = ms[i];
		n = ns[i];
		r = rs[i];

		x = ((double) n) * a;
		y = ((double) m) * a;

		if (!xyonly) {
			// remove existing element vertices 1 and 2
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

			// remove additional element vertices for square holes
			if (sqhole) {
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				opsubVertex(dbsplnr, refSupdev, refSubdev, str.str(), vtxs);
			};

			// add new element vertices 1 and 2
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x, y+r, vtxs);

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x, y-r, vtxs);

			// add additional element vertices for square holes
			if (sqhole) {
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x-r, y-r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x+r, y-r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x+r, y+r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				opaddVertex(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), x-r, y+r, vtxs);
			};

		} else {
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
			addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y+r, vtxs);

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2";
			addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x, y-r, vtxs);

			if (sqhole) {
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-r, y-r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x+r, y-r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x+r, y+r, vtxs);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, x-r, y+r, vtxs);
			};
		};
	};
};

void PlnrExpPhcsq::psqcavfr_guides(
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
			, const bool sqhole
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

	psqcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	if (!ronly) {
		// - line guides
		for (unsigned int i=0;i<ms.size();i++) {
			m = ms[i];
			n = ns[i];

			v = 2*n + 1;
			str.str(""); str << "lv" << intToPnstr(v); lsref = str.str();

			// replace vertices 1 and 2 on vertical line guide
			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsreforig = str.str();
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefrepl = str.str();
			opaddLgdVtxAtVsrefNum(dbsplnr, refSubdev, lsref, vsreforig, vsrefrepl, vtxs, lgs);

			str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsreforig = str.str();
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefrepl = str.str();
			opaddLgdVtxAtVsrefNum(dbsplnr, refSubdev, lsref, vsreforig, vsrefrepl, vtxs, lgs);

			if (sqhole) {
				// - interior line guides

				// remove vertices nw, ne, sw, se from through line guides
				str.str(""); str << "ln" << intToPnstr(m); lsref = str.str();

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);

				str.str(""); str << "ls" << intToPnstr(m); lsref = str.str();

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);

				str.str(""); str << "lw" << intToPnstr(n); lsref = str.str();

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);

				str.str(""); str << "le" << intToPnstr(n); lsref = str.str();

				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);
				str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se";
				opsubLgdVtx(dbsplnr, refSubdev, lsref, str.str(), vtxs, lgs);

				// create element-only line guides
				vsrefs.resize(0);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw"; vsrefs.push_back(str.str());
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne"; vsrefs.push_back(str.str());

				str.str(""); str << "lxnm" << intToPnstr(m) << "_n" << intToPnstr(n);
				opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);

				vsrefs.resize(0);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw"; vsrefs.push_back(str.str());
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se"; vsrefs.push_back(str.str());

				str.str(""); str << "lxsm" << intToPnstr(m) << "_n" << intToPnstr(n);
				opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);

				vsrefs.resize(0);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw"; vsrefs.push_back(str.str());
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw"; vsrefs.push_back(str.str());

				str.str(""); str << "lxwm" << intToPnstr(m) << "_n" << intToPnstr(n);
				opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);

				vsrefs.resize(0);

				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne"; vsrefs.push_back(str.str());
				str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se"; vsrefs.push_back(str.str());

				str.str(""); str << "lxem" << intToPnstr(m) << "_n" << intToPnstr(n);
				opaddLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, str.str(), vsrefs, vtxs, lgs);
			};
		};
	};

	if (!sqhole) {
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
};

void PlnrExpPhcsq::psqcavfr_faces(
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
			, const bool sqhole
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

	psqcavfr_getelems(mstart, mstop, nstart, nstop, rstart, rstep, rN, mmin, mmax, nmin, nmax, ms, ns, rs);

	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	int v;

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
		v = 2*n;

		// - element west face
		vsrefs.resize(0);
		rtes.resize(0);
		gsrefs.resize(0);
		dirs.resize(0);

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
		if (sqhole) {
			str.str(""); str << "lxsm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		} else {
			str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		};

		if (sqhole) {
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_sw"; vsrefs.push_back(str.str());
			str.str(""); str << "lxwm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_nw"; vsrefs.push_back(str.str());
			str.str(""); str << "lxnm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		};

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "lh" << intToPnstr(m+1); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lh" << intToPnstr(m); gsrefs.push_back(str.str());

		if (sqhole) StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		else StrMod::stringToVector("lgd;agd;lgd;lgd;lgd;lgd", rtes);

		if (sqhole) StrMod::stringToVector("bwd;bwd;bwd;fwd;bwd;bwd;fwd;fwd", dirs);
		else StrMod::stringToVector("bwd;bwd;bwd;bwd;fwd;fwd", dirs);

		str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_0";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);

		// - element east face
		vsrefs.resize(0);
		rtes.resize(0);
		gsrefs.resize(0);
		dirs.resize(0);

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "lh" << intToPnstr(m); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+2); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n+1) << "_a"; vsrefs.push_back(str.str());
		str.str(""); str << "lh" << intToPnstr(m+1); gsrefs.push_back(str.str());

		str.str(""); str << "vm" << intToPnstr(m+1) << "_n" << intToPnstr(n) << "_b"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1"; vsrefs.push_back(str.str());
		if (sqhole) {
			str.str(""); str << "lxnm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		} else {
			str.str(""); str << "axm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		};

		if (sqhole) {
			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_ne"; vsrefs.push_back(str.str());
			str.str(""); str << "lxem" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());

			str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_se"; vsrefs.push_back(str.str());
			str.str(""); str << "lxsm" << intToPnstr(m) << "_n" << intToPnstr(n); gsrefs.push_back(str.str());
		};

		str.str(""); str << "vxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_2"; vsrefs.push_back(str.str());
		str.str(""); str << "lv" << intToPnstr(v+1); gsrefs.push_back(str.str());

		if (sqhole) StrMod::stringToVector("lgd;lgd;lgd;lgd;lgd;lgd;lgd;lgd", rtes);
		else StrMod::stringToVector("lgd;lgd;lgd;lgd;agd;lgd", rtes);

		if (sqhole) StrMod::stringToVector("fwd;bwd;bwd;fwd;fwd;fwd;bwd;fwd", dirs);
		else StrMod::stringToVector("fwd;bwd;bwd;fwd;bwd;fwd", dirs);

		str.str(""); str << "fxm" << intToPnstr(m) << "_n" << intToPnstr(n) << "_1";
		opaddFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, refSupdev, refSubdev, refSruAll, str.str(), vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	};
};

void PlnrExpPhcsq::getminmax(
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


