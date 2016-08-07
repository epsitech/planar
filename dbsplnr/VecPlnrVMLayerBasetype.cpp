/**
  * \file VecPlnrVMLayerBasetype.cpp
  * vector VecPlnrVMLayerBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMLayerBasetype.h"

/******************************************************************************
 namespace VecPlnrVMLayerBasetype
 ******************************************************************************/

uint VecPlnrVMLayerBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "litho") return LITHO;
	else if (s == "reg") return REG;
	else if (s == "fill") return FILL;
	else if (s == "tpl") return TPL;

	return(0);
};

string VecPlnrVMLayerBasetype::getSref(
			const uint ix
		) {
	if (ix == LITHO) return("litho");
	else if (ix == REG) return("reg");
	else if (ix == FILL) return("fill");
	else if (ix == TPL) return("tpl");

	return("");
};

string VecPlnrVMLayerBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == LITHO) return("lithography layer (no material)");
		else if (ix == REG) return("regular layer");
		else if (ix == FILL) return("fill material layer for flat stack");
		else if (ix == TPL) return("template layer for multi period stack");
	};

	return("");
};

void VecPlnrVMLayerBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

