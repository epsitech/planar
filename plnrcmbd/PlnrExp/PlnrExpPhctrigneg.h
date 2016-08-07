/**
  * \file PlnrExpPhctrigneg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPHCTRIGNEG_H
#define PLNREXPPHCTRIGNEG_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPhctrigneg {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPhctrigneg* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _R = 1;
	const unsigned int _A = 2;
	const unsigned int _M = 4;
	const unsigned int _N = 8;

	const unsigned int _PTRNEGCAV_MSTART = 16;
	const unsigned int _PTRNEGCAV_MSTOP = 32;
	const unsigned int _PTRNEGCAV_NSTART = 64;
	const unsigned int _PTRNEGCAV_NSTOP = 128;

	const unsigned int _PTRNEGCAVFR_MSTART = 256;
	const unsigned int _PTRNEGCAVFR_MSTOP = 512;
	const unsigned int _PTRNEGCAVFR_NSTART = 1024;
	const unsigned int _PTRNEGCAVFR_NSTOP = 2048;
	const unsigned int _PTRNEGCAVFR_RSTART = 4096;
	const unsigned int _PTRNEGCAVFR_RSTEP = 8192;
	const unsigned int _PTRNEGCAVFR_RN = 16384;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool xyonly, const unsigned int modpar, const double r, const double a, const int M, const int N, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool ronly, const double r, const double a, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void ptrnegcav_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop);
	void ptrnegcav_vertices(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, ListPlnrMVertex& vtxs);
	void ptrnegcav_guides(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void ptrnegcav_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void ptrnegcavfr_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop, double& rstart, double& rstep, int& rN);
	void ptrnegcavfr_getelems(const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int mmin, const int mmax, const int nmin, const int nmax, vector<int>& ms, vector<int>& ns, vector<double>& rs);
	void ptrnegcavfr_vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool xyonly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const double a, const int M, const int N, ListPlnrMVertex& vtxs);
	void ptrnegcavfr_guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool ronly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void ptrnegcavfr_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void getminmax(const int M, const int N, int& mmin, int& mmax, int& nmin, int& nmax);
// IP cust --- IEND
};

#endif


