/**
  * \file PlnrExpGray.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPGRAY_H
#define PLNREXPGRAY_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpGray {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpGray* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _P = 1;
	const unsigned int _PIX = 2;
	const unsigned int _M = 4;
	const unsigned int _N = 8;
	const unsigned int _INVSQ = 16;

	void vtxlgfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const double p, const double pix, const int M, const int N, const bool invsq, const ubigint refSruAll);
// IP cust --- IEND
};

#endif


