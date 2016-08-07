/**
  * \file PlnrExpRoicadp.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPROICADP_H
#define PLNREXPROICADP_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpRoicadp {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpRoicadp* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _RAST = 1;
	const unsigned int _PIXM = 2;
	const unsigned int _PIXN = 4;
	const unsigned int _FRMN = 8;
	const unsigned int _RATIO = 16;
	const unsigned int _CHIPM = 32;
	const unsigned int _CHIPN = 64;
	const unsigned int _SPCN = 128;
	const unsigned int _OPNW = 256;
	const unsigned int _BUMPD = 512;
	const unsigned int _PADCLR = 1024;

	void vertices();
	void guides();
	void faces();
// IP cust --- IEND
};

#endif


