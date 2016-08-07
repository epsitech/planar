/**
  * \file PlnrExpPhcsq.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPHCSQ_H
#define PLNREXPPHCSQ_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPhcsq {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPhcsq* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _R = 1;
	const unsigned int _A = 2;
	const unsigned int _M = 4;
	const unsigned int _N = 8;
	const unsigned int _SQHOLE = 16;

	const unsigned int _PSQCAV_MSTART = 32;
	const unsigned int _PSQCAV_MSTOP = 64;
	const unsigned int _PSQCAV_NSTART = 128;
	const unsigned int _PSQCAV_NSTOP = 256;

	const unsigned int _PSQCAVFR_MSTART = 512;
	const unsigned int _PSQCAVFR_MSTOP = 1024;
	const unsigned int _PSQCAVFR_NSTART = 2048;
	const unsigned int _PSQCAVFR_NSTOP = 4096;
	const unsigned int _PSQCAVFR_RSTART = 8192;
	const unsigned int _PSQCAVFR_RSTEP = 16384;
	const unsigned int _PSQCAVFR_RN = 32768;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool xyonly, const unsigned int modpar, const double r, const double a, const int M, const int N, const bool sqhole, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool ronly, const double r, const double a, const int M, const int N, const bool sqhole, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int M, const int N, const bool sqhole, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void psqcav_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop);
	void psqcav_vertices(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const bool sqhole, ListPlnrMVertex& vtxs);
	void psqcav_guides(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const bool sqhole, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void psqcav_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const bool sqhole, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void psqcavfr_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop, double& rstart, double& rstep, int& rN);
	void psqcavfr_getelems(const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int mmin, const int mmax, const int nmin, const int nmax, vector<int>& ms, vector<int>& ns, vector<double>& rs);
	void psqcavfr_vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool xyonly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const double a, const int M, const int N, const bool sqhole, ListPlnrMVertex& vtxs);
	void psqcavfr_guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool ronly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const bool sqhole, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void psqcavfr_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const bool sqhole, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void getminmax(const int M, const int N, int& mmin, int& mmax, int& nmin, int& nmax);
// IP cust --- IEND
};

#endif


