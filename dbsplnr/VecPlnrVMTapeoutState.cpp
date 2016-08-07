/**
  * \file VecPlnrVMTapeoutState.cpp
  * vector VecPlnrVMTapeoutState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMTapeoutState.h"

/******************************************************************************
 namespace VecPlnrVMTapeoutState
 ******************************************************************************/

uint VecPlnrVMTapeoutState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dsn") return DSN;
	else if (s == "ord") return ORD;
	else if (s == "rdy") return RDY;

	return(0);
};

string VecPlnrVMTapeoutState::getSref(
			const uint ix
		) {
	if (ix == DSN) return("dsn");
	else if (ix == ORD) return("ord");
	else if (ix == RDY) return("rdy");

	return("");
};

string VecPlnrVMTapeoutState::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DSN) return("design phase");
		else if (ix == ORD) return("ordered");
		else if (ix == RDY) return("ready for use");
	};

	return("");
};

void VecPlnrVMTapeoutState::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

