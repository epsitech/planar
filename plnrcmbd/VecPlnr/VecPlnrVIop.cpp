/**
  * \file VecPlnrVIop.cpp
  * vector VecPlnrVIop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVIop.h"

/******************************************************************************
 namespace VecPlnrVIop
 ******************************************************************************/

uint VecPlnrVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "retr") return RETR;
	else if (s == "retrins") return RETRINS;
	else if (s == "retrupd") return RETRUPD;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecPlnrVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RETR) return("retr");
	else if (ix == RETRINS) return("retrins");
	else if (ix == RETRUPD) return("retrupd");
	else if (ix == RMV) return("rmv");

	return("");
};

string VecPlnrVIop::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == INS) return("insert");
		else if (ix == RETR) return("retrieve");
		else if (ix == RETRINS) return("retrieve, else insert");
		else if (ix == RETRUPD) return("retrieve and update");
		else if (ix == RMV) return("remove");
	};

	return("");
};

void VecPlnrVIop::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};


