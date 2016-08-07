/**
  * \file VecPlnrVValuelist.cpp
  * vector VecPlnrVValuelist (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVValuelist.h"

/******************************************************************************
 namespace VecPlnrVValuelist
 ******************************************************************************/

uint VecPlnrVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstplnrumpersontitle") return VLSTPLNRUMPERSONTITLE;

	return(0);
};

string VecPlnrVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTPLNRUMPERSONTITLE) return("VlstPlnrUMPersonTitle");

	return("");
};

string VecPlnrVValuelist::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VLSTPLNRUMPERSONTITLE) return("title");
	};

	return("");
};

