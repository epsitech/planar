/**
  * \file VecPlnrVMProjectState.cpp
  * vector VecPlnrVMProjectState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMProjectState.h"

/******************************************************************************
 namespace VecPlnrVMProjectState
 ******************************************************************************/

uint VecPlnrVMProjectState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "plan") return PLAN;
	else if (s == "act") return ACT;
	else if (s == "cpl") return CPL;

	return(0);
};

string VecPlnrVMProjectState::getSref(
			const uint ix
		) {
	if (ix == PLAN) return("plan");
	else if (ix == ACT) return("act");
	else if (ix == CPL) return("cpl");

	return("");
};

string VecPlnrVMProjectState::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == PLAN) return("planned");
		else if (ix == ACT) return("active");
		else if (ix == CPL) return("completed");
	};

	return("");
};

void VecPlnrVMProjectState::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

