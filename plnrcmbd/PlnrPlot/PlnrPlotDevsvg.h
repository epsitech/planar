/**
  * \file PlnrPlotDevsvg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDEVSVG_H
#define PLNRPLOTDEVSVG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDevsvg {

	DpchRetPlnrPlotDevsvg* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDevsvg* dpchinv);
// IP cust --- INSERT
};

#endif


