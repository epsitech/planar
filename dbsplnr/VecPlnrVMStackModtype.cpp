/**
  * \file VecPlnrVMStackModtype.cpp
  * vector VecPlnrVMStackModtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMStackModtype.h"

/******************************************************************************
 namespace VecPlnrVMStackModtype
 ******************************************************************************/

uint VecPlnrVMStackModtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "noln") return NOLN;
	else if (s == "lyr") return LYR;

	return(0);
};

string VecPlnrVMStackModtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == NOLN) return("noln");
	else if (ix == LYR) return("lyr");

	return("");
};

string VecPlnrVMStackModtype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == NOLN) return("no modification of layer number");
		else if (ix == LYR) return("layers");
	};

	return("");
};

void VecPlnrVMStackModtype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

