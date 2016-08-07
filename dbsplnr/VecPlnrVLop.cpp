/**
  * \file VecPlnrVLop.cpp
  * vector VecPlnrVLop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVLop.h"

/******************************************************************************
 namespace VecPlnrVLop
 ******************************************************************************/

uint VecPlnrVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	else if (s == "rmv") return RMV;

	return(0);
};

string VecPlnrVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	else if (ix == RMV) return("rmv");

	return("");
};

