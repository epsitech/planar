/**
  * \file PlnrPlotTpotxt.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTTPOTXT_H
#define PLNRPLOTTPOTXT_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotTpotxt {

	DpchRetPlnrPlotTpotxt* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotTpotxt* dpchinv);
// IP cust --- INSERT
};

#endif


