/**
  * \file VecPlnrVMLayerHkTbl.cpp
  * vector VecPlnrVMLayerHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMLayerHkTbl.h"

/******************************************************************************
 namespace VecPlnrVMLayerHkTbl
 ******************************************************************************/

uint VecPlnrVMLayerHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dsn") return DSN;
	else if (s == "stk") return STK;

	return(0);
};

string VecPlnrVMLayerHkTbl::getSref(
			const uint ix
		) {
	if (ix == DSN) return("dsn");
	else if (ix == STK) return("stk");

	return("");
};

string VecPlnrVMLayerHkTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DSN) return("design");
		else if (ix == STK) return("stack");
	};

	return("");
};

void VecPlnrVMLayerHkTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

