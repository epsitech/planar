/**
  * \file VecPlnrVMStackFlrAligntype.cpp
  * vector VecPlnrVMStackFlrAligntype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMStackFlrAligntype.h"

/******************************************************************************
 namespace VecPlnrVMStackFlrAligntype
 ******************************************************************************/

uint VecPlnrVMStackFlrAligntype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "abs") return ABS;
	else if (s == "rel") return REL;
	else if (s == "ninf") return NINF;

	return(0);
};

string VecPlnrVMStackFlrAligntype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == ABS) return("abs");
	else if (ix == REL) return("rel");
	else if (ix == NINF) return("ninf");

	return("");
};

string VecPlnrVMStackFlrAligntype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == ABS) return("absolute");
		else if (ix == REL) return("relative to existing level");
		else if (ix == NINF) return("negative infinity");
	};

	return("");
};

void VecPlnrVMStackFlrAligntype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

