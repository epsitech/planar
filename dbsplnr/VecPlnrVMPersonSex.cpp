/**
  * \file VecPlnrVMPersonSex.cpp
  * vector VecPlnrVMPersonSex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMPersonSex.h"

/******************************************************************************
 namespace VecPlnrVMPersonSex
 ******************************************************************************/

uint VecPlnrVMPersonSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	else if (s == "m") return M;

	return(0);
};

string VecPlnrVMPersonSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	else if (ix == M) return("m");

	return("");
};

string VecPlnrVMPersonSex::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == F) return("female");
		else if (ix == M) return("male");
	};

	return("");
};

void VecPlnrVMPersonSex::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

