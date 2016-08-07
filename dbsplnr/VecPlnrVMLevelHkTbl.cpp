/**
  * \file VecPlnrVMLevelHkTbl.cpp
  * vector VecPlnrVMLevelHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMLevelHkTbl.h"

/******************************************************************************
 namespace VecPlnrVMLevelHkTbl
 ******************************************************************************/

uint VecPlnrVMLevelHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dsn") return DSN;
	else if (s == "stk") return STK;

	return(0);
};

string VecPlnrVMLevelHkTbl::getSref(
			const uint ix
		) {
	if (ix == DSN) return("dsn");
	else if (ix == STK) return("stk");

	return("");
};

string VecPlnrVMLevelHkTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DSN) return("design");
		else if (ix == STK) return("stack");
	};

	return("");
};

void VecPlnrVMLevelHkTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

