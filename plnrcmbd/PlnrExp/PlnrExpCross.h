/**
  * \file PlnrExpCross.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPCROSS_H
#define PLNREXPCROSS_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpCross {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpCross* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _SIZE = 1;
	const unsigned int _NARRW = 2;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double size, const double narrw, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void faces(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refSruAll, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


