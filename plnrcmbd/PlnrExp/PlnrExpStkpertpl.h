/**
  * \file PlnrExpStkpertpl.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPSTKPERTPL_H
#define PLNREXPSTKPERTPL_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpStkpertpl {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpStkpertpl* dpchinv);
// IP cust --- IBEGIN
	void levels(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const PlnrMStack* stk, const ListPlnrMLayer& tpllyrs, const vector<unsigned int>& icsTpllyrs, const bool zonly, ListPlnrMLayer& lyrs, ListPlnrMLevel& lvls);
// IP cust --- IEND
};

#endif


