/**
  * \file VecPlnrVRMCalcMFileIo.cpp
  * vector VecPlnrVRMCalcMFileIo (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVRMCalcMFileIo.h"

/******************************************************************************
 namespace VecPlnrVRMCalcMFileIo
 ******************************************************************************/

uint VecPlnrVRMCalcMFileIo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "in") return IN;
	else if (s == "out") return OUT;
	else if (s == "imd") return IMD;

	return(0);
};

string VecPlnrVRMCalcMFileIo::getSref(
			const uint ix
		) {
	if (ix == IN) return("in");
	else if (ix == OUT) return("out");
	else if (ix == IMD) return("imd");

	return("");
};

string VecPlnrVRMCalcMFileIo::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == IN) return("input");
		else if (ix == OUT) return("output");
		else if (ix == IMD) return("intermediate");
	};

	return("");
};

void VecPlnrVRMCalcMFileIo::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

