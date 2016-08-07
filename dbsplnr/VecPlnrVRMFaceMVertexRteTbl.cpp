/**
  * \file VecPlnrVRMFaceMVertexRteTbl.cpp
  * vector VecPlnrVRMFaceMVertexRteTbl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVRMFaceMVertexRteTbl.h"

/******************************************************************************
 namespace VecPlnrVRMFaceMVertexRteTbl
 ******************************************************************************/

uint VecPlnrVRMFaceMVertexRteTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lgd") return LGD;
	else if (s == "agd") return AGD;

	return(0);
};

string VecPlnrVRMFaceMVertexRteTbl::getSref(
			const uint ix
		) {
	if (ix == LGD) return("lgd");
	else if (ix == AGD) return("agd");

	return("");
};

string VecPlnrVRMFaceMVertexRteTbl::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == LGD) return("line guide");
		else if (ix == AGD) return("arc guide");
	};

	return("");
};

void VecPlnrVRMFaceMVertexRteTbl::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

