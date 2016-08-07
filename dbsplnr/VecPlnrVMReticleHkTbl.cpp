/**
  * \file VecPlnrVMReticleHkTbl.cpp
  * vector VecPlnrVMReticleHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMReticleHkTbl.h"

/******************************************************************************
 namespace VecPlnrVMReticleHkTbl
 ******************************************************************************/

uint VecPlnrVMReticleHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "tpo") return TPO;
	else if (s == "arr") return ARR;

	return(0);
};

string VecPlnrVMReticleHkTbl::getSref(
			const uint ix
		) {
	if (ix == TPO) return("tpo");
	else if (ix == ARR) return("arr");

	return("");
};

string VecPlnrVMReticleHkTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == TPO) return("tape-out");
		else if (ix == ARR) return("array");
	};

	return("");
};

void VecPlnrVMReticleHkTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

