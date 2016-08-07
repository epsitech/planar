/**
  * \file PlnrExpWgbend.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPWGBEND_H
#define PLNREXPWGBEND_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpWgbend {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpWgbend* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _PHISTART = 1;
	const unsigned int _PHISTOP = 2;
	const unsigned int _R = 4;
	const unsigned int _RIDGEW = 8;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double phistart, const double phistop, const double r, const double ridgew, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double r, const double ridgew, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


