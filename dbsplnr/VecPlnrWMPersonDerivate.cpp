/**
  * \file VecPlnrWMPersonDerivate.cpp
  * vector VecPlnrWMPersonDerivate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrWMPersonDerivate.h"

/******************************************************************************
 namespace VecPlnrWMPersonDerivate
 ******************************************************************************/

uint VecPlnrWMPersonDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void VecPlnrWMPersonDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*USR);i*=2) if (ix & i) ics.insert(i);
};

string VecPlnrWMPersonDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecPlnrWMPersonDerivate::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == USR) return("user");
	};

	return("");
};

void VecPlnrWMPersonDerivate::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=USR;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixPlnrVLocale));
};

