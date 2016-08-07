/**
  * \file PlnrExpRtresneg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPRTRESNEG_H
#define PLNREXPRTRESNEG_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpRtresneg {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpRtresneg* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _WG2 = 1;
	const unsigned int _RIDGEW = 2;
	const unsigned int _R = 4;
	const unsigned int _CPLLEN = 8;
	const unsigned int _DIST = 16;
	const unsigned int _CLR = 32;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double ridgew, const double r, const double cpllen, const double dist, const double clr, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const double ridgew, const double r, const double clr, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool wg2, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


