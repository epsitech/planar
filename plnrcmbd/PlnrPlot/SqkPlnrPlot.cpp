/**
  * \file SqkPlnrPlot.cpp
  * squawk generation for operation pack PlnrPlot (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "SqkPlnrPlot.h"

/******************************************************************************
 namespace SqkPlnrPlot
 ******************************************************************************/

string SqkPlnrPlot::getSquawkDat1dgnu(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDat1dgnu* dpchinv
		) {
	string retval;
// IP getSquawkDat1dgnu --- IBEGIN
	retval = "generate 1D plot from file '" + StubPlnr::getStubFilShort(dbsplnr, dpchinv->refFile) + "' using gnuplot";
// IP getSquawkDat1dgnu --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDat1dgnumult(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDat1dgnumult* dpchinv
		) {
	string retval;
// IP getSquawkDat1dgnumult --- IBEGIN
	retval = "generate 1D plot of multiple data sets with title '" +  dpchinv->title + "'";
// IP getSquawkDat1dgnumult --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDevsvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDevsvg* dpchinv
		) {
	string retval;
// IP getSquawkDevsvg --- IBEGIN
	retval = "generate SVG plot of device '" +  StubPlnr::getStubDevStd(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkDevsvg --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDomdat1dgnu(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat1dgnu* dpchinv
		) {
	string retval;
// IP getSquawkDomdat1dgnu --- IBEGIN
	retval = "generate plot of 1D data on domain '" + dpchinv->srefDom + "' using gnuplot";
// IP getSquawkDomdat1dgnu --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDomdat2dgnu(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dgnu* dpchinv
		) {
	string retval;
// IP getSquawkDomdat2dgnu --- IBEGIN
	retval = "generate plot of 2D data on domain '" + dpchinv->srefDom + "' using gnuplot";
// IP getSquawkDomdat2dgnu --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDomdat2dpng(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dpng* dpchinv
		) {
	string retval;
// IP getSquawkDomdat2dpng --- IBEGIN
	retval = "generate PNG plot of 2D data on domain '" + dpchinv->srefDom + "'";
// IP getSquawkDomdat2dpng --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDomdat2dvid(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dvid* dpchinv
		) {
	string retval;
// IP getSquawkDomdat2dvid --- INSERT
	return(retval);
};

string SqkPlnrPlot::getSquawkDomzcssvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomzcssvg* dpchinv
		) {
	string retval;
// IP getSquawkDomzcssvg --- INSERT
	return(retval);
};

string SqkPlnrPlot::getSquawkDsnxysvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDsnxysvg* dpchinv
		) {
	string retval;
// IP getSquawkDsnxysvg --- IBEGIN
	retval = "generate in-plane SVG plot of design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "'";
// IP getSquawkDsnxysvg --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkDsnzsvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDsnzsvg* dpchinv
		) {
	string retval;
// IP getSquawkDsnzsvg --- IBEGIN
	retval = "generate vertical build-up SVG plot of design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "'";
// IP getSquawkDsnzsvg --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkStksvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotStksvg* dpchinv
		) {
	string retval;
// IP getSquawkStksvg --- IBEGIN
	retval = "generate SVG plot of stack '" + StubPlnr::getStubStkStd(dbsplnr, dpchinv->refPlnrMStack) + "'";
// IP getSquawkStksvg --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkTposvg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotTposvg* dpchinv
		) {
	string retval;
// IP getSquawkTposvg --- IBEGIN
	retval = "generate floorplan SVG plot of tape-out '" + StubPlnr::getStubTpoStd(dbsplnr, dpchinv->refPlnrMTapeout) + "'";
// IP getSquawkTposvg --- IEND
	return(retval);
};

string SqkPlnrPlot::getSquawkTpotxt(
			DbsPlnr* dbsplnr
			, DpchInvPlnrPlotTpotxt* dpchinv
		) {
	string retval;
// IP getSquawkTpotxt --- IBEGIN
	retval = "generate fabrication data for tape-out '" + StubPlnr::getStubTpoStd(dbsplnr, dpchinv->refPlnrMTapeout) + "'";
// IP getSquawkTpotxt --- IEND
	return(retval);
};


