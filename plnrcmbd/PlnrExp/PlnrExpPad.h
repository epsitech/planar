/**
  * \file PlnrExpPad.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPAD_H
#define PLNREXPPAD_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPad {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPad* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _SIZE = 1;
	const unsigned int _CLR = 2;
	const unsigned int _OLP = 4;
	const unsigned int _BUMPD = 8;
	const unsigned int _BUMPOFSX = 16;
	const unsigned int _BUMPOFSY = 32;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double size, const double clr, const double olp, const double bumpd, const double bumpofsx, const double bumpofsy, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const double bumpd, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags);
	void faces(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refSruMet, const ubigint refSruIns, const ubigint refSruBump, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


