/**
  * \file VecPlnrVMVertexHkTbl.cpp
  * vector VecPlnrVMVertexHkTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMVertexHkTbl.h"

/******************************************************************************
 namespace VecPlnrVMVertexHkTbl
 ******************************************************************************/

uint VecPlnrVMVertexHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dsn") return DSN;
	else if (s == "dev") return DEV;

	return(0);
};

string VecPlnrVMVertexHkTbl::getSref(
			const uint ix
		) {
	if (ix == DSN) return("dsn");
	else if (ix == DEV) return("dev");

	return("");
};

string VecPlnrVMVertexHkTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DSN) return("design");
		else if (ix == DEV) return("device");
	};

	return("");
};

void VecPlnrVMVertexHkTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

