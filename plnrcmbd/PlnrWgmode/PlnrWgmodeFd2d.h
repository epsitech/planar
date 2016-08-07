/**
  * \file PlnrWgmodeFd2d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRWGMODEFD2D_H
#define PLNRWGMODEFD2D_H

#include "PlnrWgmode.h"

using namespace PlnrWgmode;

// IP incl --- INSERT

namespace PlnrWgmodeFd2d {

	DpchRetPlnrWgmodeFd2d* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFd2d* dpchinv);
// IP cust --- INSERT
};

#endif


