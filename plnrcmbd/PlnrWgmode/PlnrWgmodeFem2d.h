/**
  * \file PlnrWgmodeFem2d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRWGMODEFEM2D_H
#define PLNRWGMODEFEM2D_H

#include "PlnrWgmode.h"

using namespace PlnrWgmode;

// IP incl --- INSERT

namespace PlnrWgmodeFem2d {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFem2d* dpchinv);
// IP cust --- INSERT
};

#endif


