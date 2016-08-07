/**
  * \file VecPlnrVKeylist.cpp
  * vector VecPlnrVKeylist (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVKeylist.h"

/******************************************************************************
 namespace VecPlnrVKeylist
 ******************************************************************************/

uint VecPlnrVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstplnrkcalcdomprp") return KLSTPLNRKCALCDOMPRP;
	else if (s == "klstplnrkcalcvar") return KLSTPLNRKCALCVAR;
	else if (s == "klstplnrkamarrayenvkey") return KLSTPLNRKAMARRAYENVKEY;
	else if (s == "klstplnrkamcalcenvkey") return KLSTPLNRKAMCALCENVKEY;
	else if (s == "klstplnrkamcalcparcat") return KLSTPLNRKAMCALCPARCAT;
	else if (s == "klstplnrkamcalcparprop") return KLSTPLNRKAMCALCPARPROP;
	else if (s == "klstplnrkamdeviceparkey") return KLSTPLNRKAMDEVICEPARKEY;
	else if (s == "klstplnrkammaterialparcat") return KLSTPLNRKAMMATERIALPARCAT;
	else if (s == "klstplnrkammaterialparprop") return KLSTPLNRKAMMATERIALPARPROP;
	else if (s == "klstplnrkampersondetailtype") return KLSTPLNRKAMPERSONDETAILTYPE;
	else if (s == "klstplnrkmfilecontent") return KLSTPLNRKMFILECONTENT;
	else if (s == "klstplnrkmfilemimetype") return KLSTPLNRKMFILEMIMETYPE;

	return(0);
};

string VecPlnrVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTPLNRKCALCDOMPRP) return("KlstPlnrKCalcdomprp");
	else if (ix == KLSTPLNRKCALCVAR) return("KlstPlnrKCalcvar");
	else if (ix == KLSTPLNRKAMARRAYENVKEY) return("KlstPlnrKAMArrayEnvKey");
	else if (ix == KLSTPLNRKAMCALCENVKEY) return("KlstPlnrKAMCalcEnvKey");
	else if (ix == KLSTPLNRKAMCALCPARCAT) return("KlstPlnrKAMCalcParCat");
	else if (ix == KLSTPLNRKAMCALCPARPROP) return("KlstPlnrKAMCalcParProp");
	else if (ix == KLSTPLNRKAMDEVICEPARKEY) return("KlstPlnrKAMDeviceParKey");
	else if (ix == KLSTPLNRKAMMATERIALPARCAT) return("KlstPlnrKAMMaterialParCat");
	else if (ix == KLSTPLNRKAMMATERIALPARPROP) return("KlstPlnrKAMMaterialParProp");
	else if (ix == KLSTPLNRKAMPERSONDETAILTYPE) return("KlstPlnrKAMPersonDetailType");
	else if (ix == KLSTPLNRKMFILECONTENT) return("KlstPlnrKMFileContent");
	else if (ix == KLSTPLNRKMFILEMIMETYPE) return("KlstPlnrKMFileMimetype");

	return("");
};

string VecPlnrVKeylist::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == KLSTPLNRKAMARRAYENVKEY) return("environment variable key");
		else if (ix == KLSTPLNRKAMCALCENVKEY) return("environment variable key");
		else if (ix == KLSTPLNRKAMCALCPARCAT) return("category");
		else if (ix == KLSTPLNRKAMCALCPARPROP) return("property");
		else if (ix == KLSTPLNRKAMDEVICEPARKEY) return("parameter key");
		else if (ix == KLSTPLNRKAMMATERIALPARCAT) return("category");
		else if (ix == KLSTPLNRKAMMATERIALPARPROP) return("property");
		else if (ix == KLSTPLNRKAMPERSONDETAILTYPE) return("type");
		else if (ix == KLSTPLNRKMFILECONTENT) return("content");
		else if (ix == KLSTPLNRKMFILEMIMETYPE) return("MIME type");
		else return(getSref(ix));
	};

	return("");
};

