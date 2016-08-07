/**
  * \file SqkPlnrPlot.h
  * squawk generation for operation pack PlnrPlot (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SQKPLNRPLOT_H
#define SQKPLNRPLOT_H

#include "PlnrPlot_blks.h"

/**
  * SqkPlnrPlot
  */
namespace SqkPlnrPlot {
	string getSquawkDat1dgnu(DbsPlnr* dbsplnr, DpchInvPlnrPlotDat1dgnu* dpchinv);
	string getSquawkDat1dgnumult(DbsPlnr* dbsplnr, DpchInvPlnrPlotDat1dgnumult* dpchinv);
	string getSquawkDevsvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotDevsvg* dpchinv);
	string getSquawkDomdat1dgnu(DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat1dgnu* dpchinv);
	string getSquawkDomdat2dgnu(DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dgnu* dpchinv);
	string getSquawkDomdat2dpng(DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dpng* dpchinv);
	string getSquawkDomdat2dvid(DbsPlnr* dbsplnr, DpchInvPlnrPlotDomdat2dvid* dpchinv);
	string getSquawkDomzcssvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotDomzcssvg* dpchinv);
	string getSquawkDsnxysvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotDsnxysvg* dpchinv);
	string getSquawkDsnzsvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotDsnzsvg* dpchinv);
	string getSquawkStksvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotStksvg* dpchinv);
	string getSquawkTposvg(DbsPlnr* dbsplnr, DpchInvPlnrPlotTposvg* dpchinv);
	string getSquawkTpotxt(DbsPlnr* dbsplnr, DpchInvPlnrPlotTpotxt* dpchinv);
};

#endif


