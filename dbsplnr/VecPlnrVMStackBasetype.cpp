/**
  * \file VecPlnrVMStackBasetype.cpp
  * vector VecPlnrVMStackBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMStackBasetype.h"

/******************************************************************************
 namespace VecPlnrVMStackBasetype
 ******************************************************************************/

uint VecPlnrVMStackBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "litho") return LITHO;
	else if (s == "flat") return FLAT;
	else if (s == "reg") return REG;
	else if (s == "fill") return FILL;
	else if (s == "pertpl") return PERTPL;

	return(0);
};

string VecPlnrVMStackBasetype::getSref(
			const uint ix
		) {
	if (ix == LITHO) return("litho");
	else if (ix == FLAT) return("flat");
	else if (ix == REG) return("reg");
	else if (ix == FILL) return("fill");
	else if (ix == PERTPL) return("pertpl");

	return("");
};

string VecPlnrVMStackBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == LITHO) return("virtual layers for lithography");
		else if (ix == FLAT) return("flat stack for 2D design");
		else if (ix == REG) return("regular stack");
		else if (ix == FILL) return("fill material stack");
		else if (ix == PERTPL) return("multi period stack template");
	};

	return("");
};

void VecPlnrVMStackBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

