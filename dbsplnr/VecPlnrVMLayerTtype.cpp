/**
  * \file VecPlnrVMLayerTtype.cpp
  * vector VecPlnrVMLayerTtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMLayerTtype.h"

/******************************************************************************
 namespace VecPlnrVMLayerTtype
 ******************************************************************************/

uint VecPlnrVMLayerTtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "zero") return ZERO;
	else if (s == "abs") return ABS;
	else if (s == "mat") return MAT;
	else if (s == "ffill") return FFILL;
	else if (s == "cfill") return CFILL;

	return(0);
};

string VecPlnrVMLayerTtype::getSref(
			const uint ix
		) {
	if (ix == ZERO) return("zero");
	else if (ix == ABS) return("abs");
	else if (ix == MAT) return("mat");
	else if (ix == FFILL) return("ffill");
	else if (ix == CFILL) return("cfill");

	return("");
};

string VecPlnrVMLayerTtype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == ZERO) return("zero thickness");
		else if (ix == ABS) return("absolute thickness");
		else if (ix == MAT) return("material dependent thickness (monolayers)");
		else if (ix == FFILL) return("fill to stack floor");
		else if (ix == CFILL) return("fill to stack ceiling");
	};

	return("");
};

void VecPlnrVMLayerTtype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

