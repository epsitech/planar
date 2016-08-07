/**
  * \file PlnrRastCub.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRASTCUB_H
#define PLNRRASTCUB_H

#include "PlnrRast.h"

using namespace PlnrRast;

// IP incl --- INSERT

namespace PlnrRastCub {

	DpchRetPlnrRastCub* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrRastCub* dpchinv);
// IP cust --- INSERT
};

#endif


