/**
  * \file VecPlnrVLat.cpp
  * vector VecPlnrVLat (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVLat.h"

/******************************************************************************
 namespace VecPlnrVLat
 ******************************************************************************/

uint VecPlnrVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	else if (s == "ini") return INI;

	return(0);
};

string VecPlnrVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	else if (ix == INI) return("ini");

	return("");
};

