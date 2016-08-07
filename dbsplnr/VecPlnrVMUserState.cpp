/**
  * \file VecPlnrVMUserState.cpp
  * vector VecPlnrVMUserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMUserState.h"

/******************************************************************************
 namespace VecPlnrVMUserState
 ******************************************************************************/

uint VecPlnrVMUserState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	else if (s == "dsg") return DSG;
	else if (s == "due") return DUE;
	else if (s == "exp") return EXP;

	return(0);
};

string VecPlnrVMUserState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	else if (ix == DSG) return("dsg");
	else if (ix == DUE) return("due");
	else if (ix == EXP) return("exp");

	return("");
};

string VecPlnrVMUserState::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == ACT) return("active");
		else if (ix == DSG) return("designated");
		else if (ix == DUE) return("due for expiration");
		else if (ix == EXP) return("expired");
	};

	return("");
};

void VecPlnrVMUserState::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

