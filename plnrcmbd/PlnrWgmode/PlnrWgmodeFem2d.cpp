/**
  * \file PlnrWgmodeFem2d.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrWgmodeFem2d.h"

DpchRetPlnr* PlnrWgmodeFem2d::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrWgmodeFem2d* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMCalc = dpchinv->refPlnrMCalc;
	ubigint refPlnrMCalcitem = dpchinv->refPlnrMCalcitem;

// IP run --- INSERT

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


