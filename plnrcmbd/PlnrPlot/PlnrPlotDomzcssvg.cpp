/**
  * \file PlnrPlotDomzcssvg.cpp
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

#include "PlnrPlotDomzcssvg.h"

DpchRetPlnrPlotDomzcssvg* PlnrPlotDomzcssvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomzcssvg* dpchinv
		) {
	DpchRetPlnrPlotDomzcssvg* dpchret = new DpchRetPlnrPlotDomzcssvg();

	string datPngpath = dpchinv->datPngpath;
	string datTit = dpchinv->datTit;
	bool eqz = dpchinv->eqz;
	uint height = dpchinv->height;
	ubigint refPlnrMDomain = dpchinv->refPlnrMDomain;
	bool showfces = dpchinv->showfces;
	bool showlvls = dpchinv->showlvls;
	bool showvtxs = dpchinv->showvtxs;
	uint width = dpchinv->width;

// IP run --- INSERT

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


