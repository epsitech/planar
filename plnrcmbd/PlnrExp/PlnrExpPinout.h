/**
  * \file PlnrExpPinout.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPINOUT_H
#define PLNREXPPINOUT_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPinout {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPinout* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _RAST = 1;
	const unsigned int _CELLSTOP = 2;
	const unsigned int _RATIO = 4;
	const unsigned int _FRAMEW = 8;
	const unsigned int _PADFILL = 16;
	const unsigned int _BUMPD = 32;
	const unsigned int _WBCLR = 64;
	const unsigned int _WBOLP = 128;
	const unsigned int _CELLCLR = 256;
	const unsigned int _CELLOLP = 512;

	const unsigned int _PIOPIN_WB = 1024;
	const unsigned int _PIOPIN_CELL = 2048;
	const unsigned int _PIOPIN_KEEPOFF = 4096;

	const unsigned int _PIOPAD_CELL = 8192;

	void vtxgdfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const double xofs, const double yofs, const int mmax, const int nmax, const double rast, const int ratio, const double framew, const bool padfill, const double bumpd, const double wbclr, const double wbolp, const double cellclr, const double cellolp, const ubigint refSruBotmet, const ubigint refSruIns, const ubigint refSruTopmet, const ubigint refSruBump);
	void vtxgdfces_addsq(DbsPlnr* dbsplnr, const ubigint strRefPlnrMStructure, const string sref, const ubigint refVtx1, const ubigint refLg1, const ubigint refVtx2, const ubigint refLg2, const ubigint refVtx3, const ubigint refLg3, const ubigint refVtx4, const ubigint refLg4);

	void piopin_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, int& wb, string& cell, bool& keepoff);
	void piopin_gdfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const int mmax, const int nmax, const int ratio, const int wb, const string cell, const bool keepoff, const ubigint refSruBotmet, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMFace& fces);

	void piopad_loadpars(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, string& cell);
	void piopad_fces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const bool padfill, const string cell, const ubigint refSruIns, const ubigint refSruTopmet, const ubigint refSruBump, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
// IP cust --- IEND
};

#endif


