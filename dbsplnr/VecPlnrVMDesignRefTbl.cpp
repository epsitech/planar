/**
  * \file VecPlnrVMDesignRefTbl.cpp
  * vector VecPlnrVMDesignRefTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDesignRefTbl.h"

/******************************************************************************
 namespace VecPlnrVMDesignRefTbl
 ******************************************************************************/

uint VecPlnrVMDesignRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "cal") return CAL;
	else if (s == "cli") return CLI;
	else if (s == "arr") return ARR;
	else if (s == "ari") return ARI;

	return(0);
};

string VecPlnrVMDesignRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == CAL) return("cal");
	else if (ix == CLI) return("cli");
	else if (ix == ARR) return("arr");
	else if (ix == ARI) return("ari");

	return("");
};

string VecPlnrVMDesignRefTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == CAL) return("calculation");
		else if (ix == CLI) return("calculation item");
		else if (ix == ARR) return("reticle array");
		else if (ix == ARI) return("reticle array item");
	};

	return("");
};

void VecPlnrVMDesignRefTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

