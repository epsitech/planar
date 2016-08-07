/**
  * \file PlnrPlotStksvg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTSTKSVG_H
#define PLNRPLOTSTKSVG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotStksvg {

	DpchRetPlnrPlotStksvg* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotStksvg* dpchinv);
// IP cust --- INSERT
};

#endif


