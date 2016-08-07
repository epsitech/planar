/**
  * \file VecPlnrVOolop.cpp
  * vector VecPlnrVOolop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVOolop.h"

/******************************************************************************
 namespace VecPlnrVOolop
 ******************************************************************************/

uint VecPlnrVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	else if (s == "inb") return INB;
	else if (s == "rmv") return RMV;
	else if (s == "swp") return SWP;
	else if (s == "toa") return TOA;
	else if (s == "tob") return TOB;

	return(0);
};

string VecPlnrVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	else if (ix == INB) return("inb");
	else if (ix == RMV) return("rmv");
	else if (ix == SWP) return("swp");
	else if (ix == TOA) return("toa");
	else if (ix == TOB) return("tob");

	return("");
};

