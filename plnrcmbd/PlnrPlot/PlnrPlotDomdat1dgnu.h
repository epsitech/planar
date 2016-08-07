/**
  * \file PlnrPlotDomdat1dgnu.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDOMDAT1DGNU_H
#define PLNRPLOTDOMDAT1DGNU_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDomdat1dgnu {

	DpchRetPlnrPlotDomdat1dgnu* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat1dgnu* dpchinv);
// IP cust --- INSERT
};

#endif


