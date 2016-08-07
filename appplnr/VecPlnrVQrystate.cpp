/**
  * \file VecPlnrVQrystate.cpp
  * vector VecPlnrVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVQrystate.h"

/******************************************************************************
 namespace VecPlnrVQrystate
 ******************************************************************************/

uint VecPlnrVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("mnr") == 0) return MNR;
	else if (s.compare("ood") == 0) return OOD;
	else if (s.compare("slm") == 0) return SLM;
	else if (s.compare("utd") == 0) return UTD;

	return(0);
};

string VecPlnrVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	else if (ix == OOD) return("ood");
	else if (ix == SLM) return("slm");
	else if (ix == UTD) return("utd");

	return("");
};

