/**
  * \file PlnrExpWgsusp.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPWGSUSP_H
#define PLNREXPWGSUSP_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpWgsusp {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpWgsusp* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _L = 1;
	const unsigned int _RIDGEW = 2;
	const unsigned int _CANTL = 4;
	const unsigned int _CANTW = 8;
	const unsigned int _CANTD = 16;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool xyonly, const unsigned int modpar, const double l, const double ridgew, const double cantl, const double cantw, const double cantd, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void faces(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


