/**
  * \file VecPlnrVUserlevel.cpp
  * vector VecPlnrVUserlevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVUserlevel.h"

/******************************************************************************
 namespace VecPlnrVUserlevel
 ******************************************************************************/

uint VecPlnrVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	else if (s == "gadm") return GADM;
	else if (s == "reg") return REG;
	else if (s == "vtor") return VTOR;

	return(0);
};

string VecPlnrVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	else if (ix == GADM) return("gadm");
	else if (ix == REG) return("reg");
	else if (ix == VTOR) return("vtor");

	return("");
};

string VecPlnrVUserlevel::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == ADM) return("administrator");
		else if (ix == GADM) return("user group administrator");
		else if (ix == REG) return("regular user");
		else if (ix == VTOR) return("visitor");
	};

	return("");
};

void VecPlnrVUserlevel::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

