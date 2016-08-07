/**
  * \file PlnrWgmodeFem1d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRWGMODEFEM1D_H
#define PLNRWGMODEFEM1D_H

#include "PlnrWgmode.h"

using namespace PlnrWgmode;

// IP incl --- INSERT

namespace PlnrWgmodeFem1d {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFem1d* dpchinv);
// IP cust --- INSERT
};

#endif


