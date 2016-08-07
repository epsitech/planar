/**
  * \file VecPlnrVRMFaceMVertexDir.cpp
  * vector VecPlnrVRMFaceMVertexDir (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVRMFaceMVertexDir.h"

/******************************************************************************
 namespace VecPlnrVRMFaceMVertexDir
 ******************************************************************************/

uint VecPlnrVRMFaceMVertexDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fwd") return FWD;
	else if (s == "bwd") return BWD;

	return(0);
};

string VecPlnrVRMFaceMVertexDir::getSref(
			const uint ix
		) {
	if (ix == FWD) return("fwd");
	else if (ix == BWD) return("bwd");

	return("");
};

string VecPlnrVRMFaceMVertexDir::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == FWD) return("forward");
		else if (ix == BWD) return("backward");
	};

	return("");
};

void VecPlnrVRMFaceMVertexDir::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

