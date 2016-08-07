/**
  * \file PlnrPlotDomdat2dpng.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDOMDAT2DPNG_H
#define PLNRPLOTDOMDAT2DPNG_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDomdat2dpng {

	DpchRetPlnrPlotDomdat2dpng* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dpng* dpchinv);
// IP cust --- INSERT
};

#endif


