/**
  * \file VecPlnrVMCalcDim.cpp
  * vector VecPlnrVMCalcDim (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMCalcDim.h"

/******************************************************************************
 namespace VecPlnrVMCalcDim
 ******************************************************************************/

uint VecPlnrVMCalcDim::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mshbox") return MSHBOX;
	else if (s == "mshline") return MSHLINE;
	else if (s == "rstcub") return RSTCUB;
	else if (s == "rstbox") return RSTBOX;
	else if (s == "rstline") return RSTLINE;

	return(0);
};

string VecPlnrVMCalcDim::getSref(
			const uint ix
		) {
	if (ix == MSHBOX) return("mshbox");
	else if (ix == MSHLINE) return("mshline");
	else if (ix == RSTCUB) return("rstcub");
	else if (ix == RSTBOX) return("rstbox");
	else if (ix == RSTLINE) return("rstline");

	return("");
};

string VecPlnrVMCalcDim::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == MSHBOX) return("meshed box");
		else if (ix == MSHLINE) return("segmented line");
		else if (ix == RSTCUB) return("rasterized cuboid");
		else if (ix == RSTBOX) return("rasterized box");
		else if (ix == RSTLINE) return("rasterized line");
	};

	return("");
};

void VecPlnrVMCalcDim::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

