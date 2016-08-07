/**
  * \file VecPlnrVMDesignBasetype.cpp
  * vector VecPlnrVMDesignBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDesignBasetype.h"

/******************************************************************************
 namespace VecPlnrVMDesignBasetype
 ******************************************************************************/

uint VecPlnrVMDesignBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "trlyr") return TRLYR;
	else if (s == "vrtlyr") return VRTLYR;

	return(0);
};

string VecPlnrVMDesignBasetype::getSref(
			const uint ix
		) {
	if (ix == TRLYR) return("trlyr");
	else if (ix == VRTLYR) return("vrtlyr");

	return("");
};

string VecPlnrVMDesignBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == TRLYR) return("true layer design for calculations");
		else if (ix == VRTLYR) return("virtual layer design for lithography");
	};

	return("");
};

void VecPlnrVMDesignBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

