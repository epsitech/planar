/**
  * \file PlnrRastZline.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRASTZLINE_H
#define PLNRRASTZLINE_H

#include "PlnrRast.h"

using namespace PlnrRast;

// IP incl --- INSERT

namespace PlnrRastZline {

	DpchRetPlnrRastZline* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrRastZline* dpchinv);
// IP cust --- INSERT
};

#endif


