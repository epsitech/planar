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

	if (s.compare("detd") == 0) return DETD;
	else if (s.compare("maxd") == 0) return MAXD;
	else if (s.compare("mind") == 0) return MIND;
	else if (s.compare("regd") == 0) return REGD;

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

