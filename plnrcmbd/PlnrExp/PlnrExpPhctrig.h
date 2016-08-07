/**
  * \file PlnrExpPhctrig.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPHCTRIG_H
#define PLNREXPPHCTRIG_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPhctrig {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPhctrig* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _R = 1;
	const unsigned int _A = 2;
	const unsigned int _M = 4;
	const unsigned int _N = 8;

	const unsigned int _PTRCAV_MSTART = 16;
	const unsigned int _PTRCAV_MSTOP = 32;
	const unsigned int _PTRCAV_NSTART = 64;
	const unsigned int _PTRCAV_NSTOP = 128;

	const unsigned int _PTRCAVFR_MSTART = 256;
	const unsigned int _PTRCAVFR_MSTOP = 512;
	const unsigned int _PTRCAVFR_NSTART = 1024;
	const unsigned int _PTRCAVFR_NSTOP = 2048;
	const unsigned int _PTRCAVFR_RSTART = 4096;
	const unsigned int _PTRCAVFR_RSTEP = 8192;
	const unsigned int _PTRCAVFR_RN = 16384;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool xyonly, const unsigned int modpar, const double r, const double a, const int M, const int N, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool ronly, const double r, const double a, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void ptrcav_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop);
	void ptrcav_vertices(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, ListPlnrMVertex& vtxs);
	void ptrcav_guides(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void ptrcav_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void ptrcavfr_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& mstart, int& mstop, int& nstart, int& nstop, double& rstart, double& rstep, int& rN);
	void ptrcavfr_getelems(const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int mmin, const int mmax, const int nmin, const int nmax, vector<int>& ms, vector<int>& ns, vector<double>& rs);
	void ptrcavfr_vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool xyonly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const double a, const int M, const int N, ListPlnrMVertex& vtxs);
	void ptrcavfr_guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool ronly, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void ptrcavfr_faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mstart, const int mstop, const int nstart, const int nstop, const double rstart, const double rstep, const int rN, const int M, const int N, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void getminmax(const int M, const int N, int& mmin, int& mmax, int& nmin, int& nmax);
	void addLda(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint hkUref, const int da, const int db0, const int mmax, const int nmax, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void addLdb(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint hkUref, const int da0, const int db, const int mmin, const int nmax, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void dadbToMn(int da, int db, int& m, int& n, bool& va, bool& vb, bool& vc);
	void mnToDadb(const int m, const int n, int& da, int& db);
	void mnToDadbv(const int m, const int n, int& da, int& db, int& v);
// IP cust --- IEND
};

#endif


