/**
  * \file VecPlnrVLocale.cpp
  * vector VecPlnrVLocale (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVLocale.h"

/******************************************************************************
 namespace VecPlnrVLocale
 ******************************************************************************/

uint VecPlnrVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;

	return(0);
};

string VecPlnrVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");

	return("");
};

string VecPlnrVLocale::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
	};

	return("");
};

void VecPlnrVLocale::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=1;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

