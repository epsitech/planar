/**
  * \file VecPlnrVMDesignDim.cpp
  * vector VecPlnrVMDesignDim (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDesignDim.h"

/******************************************************************************
 namespace VecPlnrVMDesignDim
 ******************************************************************************/

uint VecPlnrVMDesignDim::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "xyz") return XYZ;
	else if (s == "xy") return XY;
	else if (s == "z") return Z;

	return(0);
};

string VecPlnrVMDesignDim::getSref(
			const uint ix
		) {
	if (ix == XYZ) return("xyz");
	else if (ix == XY) return("xy");
	else if (ix == Z) return("z");

	return("");
};

string VecPlnrVMDesignDim::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == XYZ) return("3D");
		else if (ix == XY) return("2D (xy plane)");
		else if (ix == Z) return("1D (z)");
	};

	return("");
};

void VecPlnrVMDesignDim::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

