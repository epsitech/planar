/**
  * \file VecPlnrWMDesignModtype.cpp
  * vector VecPlnrWMDesignModtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrWMDesignModtype.h"

/******************************************************************************
 namespace VecPlnrWMDesignModtype
 ******************************************************************************/

uint VecPlnrWMDesignModtype::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "dnoto") ix |= DNOTO;
		else if (ss[i] == "dto") ix |= DTO;
		else if (ss[i] == "snoln") ix |= SNOLN;
		else if (ss[i] == "sln") ix |= SLN;
		else if (ss[i] == "mlt") ix |= MLT;
		else if (ss[i] == "domxy") ix |= DOMXY;
		else if (ss[i] == "domz") ix |= DOMZ;
		else if (ss[i] == "mvar") ix |= MVAR;
		else if (ss[i] == "mat") ix |= MAT;
		else if (ss[i] == "grid") ix |= GRID;
	};

	return(ix);
};

void VecPlnrWMDesignModtype::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*GRID);i*=2) if (ix & i) ics.insert(i);
};

string VecPlnrWMDesignModtype::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & DNOTO) ss.push_back("dnoto");
	if (ix & DTO) ss.push_back("dto");
	if (ix & SNOLN) ss.push_back("snoln");
	if (ix & SLN) ss.push_back("sln");
	if (ix & MLT) ss.push_back("mlt");
	if (ix & DOMXY) ss.push_back("domxy");
	if (ix & DOMZ) ss.push_back("domz");
	if (ix & MVAR) ss.push_back("mvar");
	if (ix & MAT) ss.push_back("mat");
	if (ix & GRID) ss.push_back("grid");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecPlnrWMDesignModtype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == DNOTO) return("device parameter not affecting topology");
		else if (ix == DTO) return("device parameter affecting topology");
		else if (ix == SNOLN) return("stack parameter not changing layer number");
		else if (ix == SLN) return("stack parameter changing layer number");
		else if (ix == MLT) return("material parameter changing layer thickness");
		else if (ix == DOMXY) return("domain guide parameter affecting xy plane");
		else if (ix == DOMZ) return("domain guide parameter affecting z");
		else if (ix == MVAR) return("material parameter not changing geometry");
		else if (ix == MAT) return("layer material");
		else if (ix == GRID) return("domain grid");
	};

	return("");
};

void VecPlnrWMDesignModtype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=GRID;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixPlnrVLocale));
};

