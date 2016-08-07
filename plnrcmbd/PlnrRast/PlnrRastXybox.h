/**
  * \file PlnrRastXybox.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRASTXYBOX_H
#define PLNRRASTXYBOX_H

#include "PlnrRast.h"

using namespace PlnrRast;

// IP incl --- INSERT

namespace PlnrRastXybox {

	DpchRetPlnrRastXybox* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrRastXybox* dpchinv);
// IP cust --- INSERT
};

#endif


