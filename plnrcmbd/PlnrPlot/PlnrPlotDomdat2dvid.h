/**
  * \file PlnrPlotDomdat2dvid.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOTDOMDAT2DVID_H
#define PLNRPLOTDOMDAT2DVID_H

#include "PlnrPlot.h"

using namespace PlnrPlot;

// IP incl --- INSERT

namespace PlnrPlotDomdat2dvid {

	DpchRetPlnrPlotDomdat2dvid* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dvid* dpchinv);
// IP cust --- INSERT
};

#endif


