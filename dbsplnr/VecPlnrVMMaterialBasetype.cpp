/**
  * \file VecPlnrVMMaterialBasetype.cpp
  * vector VecPlnrVMMaterialBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMMaterialBasetype.h"

/******************************************************************************
 namespace VecPlnrVMMaterialBasetype
 ******************************************************************************/

uint VecPlnrVMMaterialBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "reg") return REG;
	else if (s == "meta") return META;

	return(0);
};

string VecPlnrVMMaterialBasetype::getSref(
			const uint ix
		) {
	if (ix == REG) return("reg");
	else if (ix == META) return("meta");

	return("");
};

string VecPlnrVMMaterialBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == REG) return("regular");
		else if (ix == META) return("meta");
	};

	return("");
};

void VecPlnrVMMaterialBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

