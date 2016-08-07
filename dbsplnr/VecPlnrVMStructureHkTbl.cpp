/**
  * \file VecPlnrVMStructureHkTbl.cpp
  * vector VecPlnrVMStructureHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMStructureHkTbl.h"

/******************************************************************************
 namespace VecPlnrVMStructureHkTbl
 ******************************************************************************/

uint VecPlnrVMStructureHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dsn") return DSN;
	else if (s == "dev") return DEV;

	return(0);
};

string VecPlnrVMStructureHkTbl::getSref(
			const uint ix
		) {
	if (ix == DSN) return("dsn");
	else if (ix == DEV) return("dev");

	return("");
};

string VecPlnrVMStructureHkTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DSN) return("design");
		else if (ix == DEV) return("device");
	};

	return("");
};

void VecPlnrVMStructureHkTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

