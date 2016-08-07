/**
  * \file PlnrExpWgtap.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPWGTAP_H
#define PLNREXPWGTAP_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpWgtap {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpWgtap* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _L = 1;
	const unsigned int _TAPSTART = 2;
	const unsigned int _TAPSTOP = 4;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double l, const double tapstart, const double tapstop, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void faces(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


