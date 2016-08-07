/**
  * \file VecPlnrVExpstate.cpp
  * vector VecPlnrVExpstate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVExpstate.h"

/******************************************************************************
 namespace VecPlnrVExpstate
 ******************************************************************************/

uint VecPlnrVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	else if (s == "maxd") return MAXD;
	else if (s == "mind") return MIND;
	else if (s == "regd") return REGD;

	return(0);
};

string VecPlnrVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	else if (ix == MAXD) return("maxd");
	else if (ix == MIND) return("mind");
	else if (ix == REGD) return("regd");

	return("");
};


