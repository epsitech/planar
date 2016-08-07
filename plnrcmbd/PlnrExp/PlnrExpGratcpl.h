/**
  * \file PlnrExpGratcpl.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPGRATCPL_H
#define PLNREXPGRATCPL_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpGratcpl {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpGratcpl* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _RIDGEW = 1;
	const unsigned int _PRD = 2;
	const unsigned int _FILL = 4;
	const unsigned int _N = 8;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool xyonly, const unsigned int modpar, const double ridgew, const double prd, const double fill, const int N, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int N, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int N, const ubigint refSruWg, const ubigint refSruGrat, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


