/**
  * \file PlnrExpRoicadp.cpp
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

#include "PlnrExpRoicadp.h"

DpchRetPlnr* PlnrExpRoicadp::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpRoicadp* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- INSERT

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpRoicadp::vertices() {
};

void PlnrExpRoicadp::guides() {
};

void PlnrExpRoicadp::faces() {
};
// IP cust --- IEND


