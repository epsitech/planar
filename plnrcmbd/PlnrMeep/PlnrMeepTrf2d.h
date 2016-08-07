/**
  * \file PlnrMeepTrf2d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMEEPTRF2D_H
#define PLNRMEEPTRF2D_H

#include "PlnrMeep.h"

using namespace PlnrMeep;

// IP incl --- INSERT

namespace PlnrMeepTrf2d {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrMeepTrf2d* dpchinv);
// IP cust --- IBEGIN
	void getMonExEy(const fields& meepF, ZcsboxrastMeep& rast, const unsigned int ixMon, const bool append, vector<complex<double> >* _Ex, vector<complex<double> >* _Ey);
// IP cust --- IEND
};

#endif


