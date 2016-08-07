/**
  * \file PlnrPlotTposvg.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTTPOSVG_H
#define PLNRPLOTTPOSVG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotTposvg {

	DpchRetPlnrPlotTposvg* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotTposvg* dpchinv);
// IP cust --- INSERT
};

#endif


