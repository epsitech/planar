/**
  * \file VecPlnrVAccess.cpp
  * vector VecPlnrVAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVAccess.h"

/******************************************************************************
 namespace VecPlnrVAccess
 ******************************************************************************/

uint VecPlnrVAccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	else if (s == "none") return NONE;
	else if (s == "view") return VIEW;

	return(0);
};

string VecPlnrVAccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	else if (ix == NONE) return("none");
	else if (ix == VIEW) return("view");

	return("");
};

string VecPlnrVAccess::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == FULL) return("full");
		else if (ix == NONE) return("none");
		else if (ix == VIEW) return("view");
	};

	return("");
};

void VecPlnrVAccess::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

