/**
  * \file VecPlnrVMDeviceModtype.cpp
  * vector VecPlnrVMDeviceModtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDeviceModtype.h"

/******************************************************************************
 namespace VecPlnrVMDeviceModtype
 ******************************************************************************/

uint VecPlnrVMDeviceModtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "noto") return NOTO;
	else if (s == "vtxgdfce") return VTXGDFCE;
	else if (s == "fce") return FCE;

	return(0);
};

string VecPlnrVMDeviceModtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == NOTO) return("noto");
	else if (ix == VTXGDFCE) return("vtxgdfce");
	else if (ix == FCE) return("fce");

	return("");
};

string VecPlnrVMDeviceModtype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == NOTO) return("no modification to topology");
		else if (ix == VTXGDFCE) return("vertices, guides and faces");
		else if (ix == FCE) return("faces only");
	};

	return("");
};

void VecPlnrVMDeviceModtype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

