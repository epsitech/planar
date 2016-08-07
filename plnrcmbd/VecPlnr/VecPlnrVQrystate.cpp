/**
  * \file VecPlnrVQrystate.cpp
  * vector VecPlnrVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVQrystate.h"

/******************************************************************************
 namespace VecPlnrVQrystate
 ******************************************************************************/

uint VecPlnrVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	else if (s == "ood") return OOD;
	else if (s == "slm") return SLM;
	else if (s == "utd") return UTD;

	return(0);
};

string VecPlnrVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	else if (ix == OOD) return("ood");
	else if (ix == SLM) return("slm");
	else if (ix == UTD) return("utd");

	return("");
};

string VecPlnrVQrystate::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		else if (ix == OOD) return("out of date");
		else if (ix == SLM) return("slightly modified");
		else if (ix == UTD) return("up to date");
	};

	return("");
};

void VecPlnrVQrystate::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};


