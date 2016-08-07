/**
  * \file PlnrExpPhotdet.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPPHOTDET_H
#define PLNREXPPHOTDET_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpPhotdet {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpPhotdet* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _SIZE = 1;
	const unsigned int _EXT = 2;
	const unsigned int _METGRAT = 4;
	const unsigned int _MIS = 8;
	const unsigned int _SCHKY = 16;
	const unsigned int _HGRAT = 32;
	const unsigned int _VGRAT = 64;
	const unsigned int _GRATPRD = 128;
	const unsigned int _GRATFILL = 256;
	const unsigned int _MESACLR = 512;
	const unsigned int _BOTW = 1024;
	const unsigned int _SBOT = 2048;
	const unsigned int _EBOT = 4096;
	const unsigned int _NBOT = 8192;
	const unsigned int _WBOT = 16384;
	const unsigned int _METCLR = 32768;
	const unsigned int _OHMLINE = 65536;
	const unsigned int _OHMRING = 131072;
	const unsigned int _OLP = 262144;
	const unsigned int _SIDEOPN = 524288;
	const unsigned int _OPNSIZE = 1048576;
	const unsigned int _TOPFILL = 2097152;
	const unsigned int _EXTSIZE = 4194304;
	const unsigned int _EXTOFSX = 8388608;
	const unsigned int _EXTOFSY = 16777216;
	const unsigned int _BUMPD = 33554432;
	const unsigned int _BUMPOFSX = 67108864;
	const unsigned int _BUMPOFSY = 134217728;

	void vlxgdfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const double size, const bool ext, const bool metgrat, const bool mis, const bool schky, const double mesaclr, const double botw, const bool sbot, const bool ebot, const bool nbot, const bool wbot, const double metclr, const bool ohmline, const bool ohmring, const double olp, const bool sideopn, const double opnsize, const bool topfill, const double extsize, const double extofsx, const double extofsy, const double bumpd, const double bumpofsx, const double bumpofsy, const ubigint refSruMesa, const ubigint refSruBotmet, const ubigint refSruIns, const ubigint refSruTopmet, const ubigint refSruBump, ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs, ListPlnrMArcguide& ags, ListPlnrMFace& fces);
	void grat_vtxgdfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const double size, const double mesaclr, const bool hgrat, const bool vgrat, const double gratprd, const double gratfill, const double botw, const bool sbot, const bool ebot, const bool nbot, const bool wbot, const ubigint refSruGrat, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs);

	void getminmax(const int N, int& nmin, int& nmax);
// IP cust --- IEND
};

#endif


