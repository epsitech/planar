/**
  * \file PlnrExpDircoup.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPDIRCOUP_H
#define PLNREXPDIRCOUP_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpDircoup {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpDircoup* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _WG2 = 1;
	const unsigned int _RIDGEW1 = 2;
	const unsigned int _RIDGEW2 = 4;
	const unsigned int _R = 8;
	const unsigned int _CPLLEN = 16;
	const unsigned int _DIST = 32;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double ridgew1, const double ridgew2, const double r, const double cpllen, const double dist, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double ridgew1, const double ridgew2, const double r, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool wg2, const ubigint refSruWg1, const ubigint refSruWg2, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


