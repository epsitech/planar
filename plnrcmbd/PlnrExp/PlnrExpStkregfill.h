/**
  * \file PlnrExpStkregfill.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPSTKREGFILL_H
#define PLNREXPSTKREGFILL_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpStkregfill {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpStkregfill* dpchinv);
// IP cust --- IBEGIN
	void levels(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMStack, ListPlnrMLayer& lyrs, ListPlnrMLevel& lvls);
// IP cust --- IEND
};

#endif


