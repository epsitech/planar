/**
  * \file PlnrPlotDomdat2dgnu.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDOMDAT2DGNU_H
#define PLNRPLOTDOMDAT2DGNU_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDomdat2dgnu {

	DpchRetPlnrPlotDomdat2dgnu* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dgnu* dpchinv);
// IP cust --- INSERT
};

#endif


