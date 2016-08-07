/**
  * \file VecPlnrVMDomaingdBasetype.cpp
  * vector VecPlnrVMDomaingdBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDomaingdBasetype.h"

/******************************************************************************
 namespace VecPlnrVMDomaingdBasetype
 ******************************************************************************/

uint VecPlnrVMDomaingdBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lvl") return LVL;
	else if (s == "vtxlg") return VTXLG;
	else if (s == "vtxag") return VTXAG;
	else if (s == "vtxprplg") return VTXPRPLG;
	else if (s == "vtxlgx") return VTXLGX;
	else if (s == "lgpar") return LGPAR;
	else if (s == "lgpar2") return LGPAR2;
	else if (s == "lgprpag") return LGPRPAG;
	else if (s == "lgprplg") return LGPRPLG;
	else if (s == "lgvtx") return LGVTX;

	return(0);
};

string VecPlnrVMDomaingdBasetype::getSref(
			const uint ix
		) {
	if (ix == LVL) return("lvl");
	else if (ix == VTXLG) return("vtxlg");
	else if (ix == VTXAG) return("vtxag");
	else if (ix == VTXPRPLG) return("vtxprplg");
	else if (ix == VTXLGX) return("vtxlgx");
	else if (ix == LGPAR) return("lgpar");
	else if (ix == LGPAR2) return("lgpar2");
	else if (ix == LGPRPAG) return("lgprpag");
	else if (ix == LGPRPLG) return("lgprplg");
	else if (ix == LGVTX) return("lgvtx");

	return("");
};

string VecPlnrVMDomaingdBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == LVL) return("level ref. ex. level");
		else if (ix == VTXLG) return("line guide vertex ref. dist. vertex");
		else if (ix == VTXAG) return("arc guide vertex ref. ang. dist. vertex");
		else if (ix == VTXPRPLG) return("vtx ref. perp. line guide and vtx");
		else if (ix == VTXLGX) return("vertex at xsec of line guides");
		else if (ix == LGPAR) return("line guide ref. par. line guide");
		else if (ix == LGPAR2) return("line guide ref. vertex and par. line guide");
		else if (ix == LGPRPAG) return("line guide ref. perp. arc guide");
		else if (ix == LGPRPLG) return("line guide ref. perp. line guide");
		else if (ix == LGVTX) return("line guide ref. two ex. vertices");
	};

	return("");
};

void VecPlnrVMDomaingdBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=10;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

