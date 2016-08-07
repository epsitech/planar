/**
  * \file VecPlnrVMDeviceAligntype.cpp
  * vector VecPlnrVMDeviceAligntype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDeviceAligntype.h"

/******************************************************************************
 namespace VecPlnrVMDeviceAligntype
 ******************************************************************************/

uint VecPlnrVMDeviceAligntype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "rdev") return RDEV;
	else if (s == "abs") return ABS;

	return(0);
};

string VecPlnrVMDeviceAligntype::getSref(
			const uint ix
		) {
	if (ix == RDEV) return("rdev");
	else if (ix == ABS) return("abs");

	return("");
};

string VecPlnrVMDeviceAligntype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == RDEV) return("relative to other device (two point connect)");
		else if (ix == ABS) return("absolute (one point x, y and phi)");
	};

	return("");
};

void VecPlnrVMDeviceAligntype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

