/**
  * \file PlnrExpCorner.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPCORNER_H
#define PLNREXPCORNER_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpCorner {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpCorner* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _SIZE = 1;
	const unsigned int _W = 2;
	const unsigned int _SQ = 4;
	const unsigned int _ALNCLR = 8;
	const unsigned int _SPRCLR = 16;

	void vertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const double size,	const double w,	const bool sq, const double alnclr, const double sprclr, ListPlnrMVertex& vtxs);
	void guides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const unsigned int modpar, const bool sq, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void faces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const bool sq, const ubigint refSruPos, const ubigint refSruNeg, const ubigint refSruAlnpos, const ubigint refSruAlnneg, const ubigint refSruSprpos, const ubigint refSruSprneg, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


