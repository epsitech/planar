/**
  * \file PlnrPlotDsnzsvg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDSNZSVG_H
#define PLNRPLOTDSNZSVG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDsnzsvg {

	DpchRetPlnrPlotDsnzsvg* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDsnzsvg* dpchinv);
// IP cust --- IBEGIN
	bool findstklvl(DbsPlnr* dbsplnr, const string& sref, const ListPlnrMStack& stks, map<string, unsigned int>& stkics2, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMDesign, ubigint& ref);
// IP cust --- IEND
};

#endif


