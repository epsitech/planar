/**
  * \file PlnrPlotDsnxysvg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDSNXYSVG_H
#define PLNRPLOTDSNXYSVG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDsnxysvg {

	DpchRetPlnrPlotDsnxysvg* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDsnxysvg* dpchinv);
// IP cust --- IBEGIN
	bool finddevvtx(DbsPlnr* dbsplnr, const string& sref, const ListPlnrMDevice& devs, map<string, unsigned int>& devics2, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMDesign, ubigint& ref);
	bool finddevlg(DbsPlnr* dbsplnr, const string& sref, const ListPlnrMDevice& devs, map<string, unsigned int>& devics2, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMDesign, ubigint& ref);
// IP cust --- IEND
};

#endif


