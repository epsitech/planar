/**
  * \file VecPlnrVReqitmode.cpp
  * vector VecPlnrVReqitmode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVReqitmode.h"

/******************************************************************************
 namespace VecPlnrVReqitmode
 ******************************************************************************/

uint VecPlnrVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "notify") return NOTIFY;
	else if (s == "poll") return POLL;

	return(0);
};

string VecPlnrVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == NOTIFY) return("notify");
	else if (ix == POLL) return("poll");

	return("");
};


