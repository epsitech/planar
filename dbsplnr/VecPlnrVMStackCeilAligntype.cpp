/**
  * \file VecPlnrVMStackCeilAligntype.cpp
  * vector VecPlnrVMStackCeilAligntype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMStackCeilAligntype.h"

/******************************************************************************
 namespace VecPlnrVMStackCeilAligntype
 ******************************************************************************/

uint VecPlnrVMStackCeilAligntype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "abs") return ABS;
	else if (s == "slyr") return SLYR;
	else if (s == "rel") return REL;
	else if (s == "pinf") return PINF;

	return(0);
};

string VecPlnrVMStackCeilAligntype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == ABS) return("abs");
	else if (ix == SLYR) return("slyr");
	else if (ix == REL) return("rel");
	else if (ix == PINF) return("pinf");

	return("");
};

string VecPlnrVMStackCeilAligntype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == ABS) return("absolute");
		else if (ix == SLYR) return("sum of layers");
		else if (ix == REL) return("relative to existing level");
		else if (ix == PINF) return("positive infinity");
	};

	return("");
};

void VecPlnrVMStackCeilAligntype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

