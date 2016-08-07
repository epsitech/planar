/**
  * \file VecPlnrVMTapeoutBasetype.cpp
  * vector VecPlnrVMTapeoutBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMTapeoutBasetype.h"

/******************************************************************************
 namespace VecPlnrVMTapeoutBasetype
 ******************************************************************************/

uint VecPlnrVMTapeoutBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pln") return PLN;
	else if (s == "btch") return BTCH;

	return(0);
};

string VecPlnrVMTapeoutBasetype::getSref(
			const uint ix
		) {
	if (ix == PLN) return("pln");
	else if (ix == BTCH) return("btch");

	return("");
};

string VecPlnrVMTapeoutBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == PLN) return("single plane (photomask)");
		else if (ix == BTCH) return("batch (e-beam writer fields)");
	};

	return("");
};

void VecPlnrVMTapeoutBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

