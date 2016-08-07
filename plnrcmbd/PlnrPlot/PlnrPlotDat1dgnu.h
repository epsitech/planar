/**
  * \file PlnrPlotDat1dgnu.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDAT1DGNU_H
#define PLNRPLOTDAT1DGNU_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDat1dgnu {

	DpchRetPlnrPlotDat1dgnu* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDat1dgnu* dpchinv);
// IP cust --- INSERT
};

#endif


