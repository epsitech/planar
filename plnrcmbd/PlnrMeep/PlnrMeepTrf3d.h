/**
  * \file PlnrMeepTrf3d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMEEPTRF3D_H
#define PLNRMEEPTRF3D_H

#include "PlnrMeep.h"

using namespace PlnrMeep;

// IP incl --- INSERT

namespace PlnrMeepTrf3d {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrMeepTrf3d* dpchinv);
// IP cust --- INSERT
};

#endif


