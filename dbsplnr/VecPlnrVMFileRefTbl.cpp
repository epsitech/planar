/**
  * \file VecPlnrVMFileRefTbl.cpp
  * vector VecPlnrVMFileRefTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMFileRefTbl.h"

/******************************************************************************
 namespace VecPlnrVMFileRefTbl
 ******************************************************************************/

uint VecPlnrVMFileRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "cal") return CAL;
	else if (s == "cli") return CLI;
	else if (s == "mat") return MAT;
	else if (s == "dev") return DEV;

	return(0);
};

string VecPlnrVMFileRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == CAL) return("cal");
	else if (ix == CLI) return("cli");
	else if (ix == MAT) return("mat");
	else if (ix == DEV) return("dev");

	return("");
};

string VecPlnrVMFileRefTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == CAL) return("calculation");
		else if (ix == CLI) return("calculation item");
		else if (ix == MAT) return("material");
		else if (ix == DEV) return("device");
	};

	return("");
};

void VecPlnrVMFileRefTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

