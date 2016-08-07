/**
  * \file PlnrPlotDat1dgnumult.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDAT1DGNUMULT_H
#define PLNRPLOTDAT1DGNUMULT_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDat1dgnumult {

	DpchRetPlnrPlotDat1dgnumult* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDat1dgnumult* dpchinv);
// IP cust --- INSERT
};

#endif


