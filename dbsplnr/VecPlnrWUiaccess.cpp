/**
  * \file VecPlnrWUiaccess.cpp
  * vector VecPlnrWUiaccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrWUiaccess.h"

/******************************************************************************
 namespace VecPlnrWUiaccess
 ******************************************************************************/

uint VecPlnrWUiaccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void VecPlnrWUiaccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VIEW);i*=2) if (ix & i) ics.insert(i);
};

string VecPlnrWUiaccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string VecPlnrWUiaccess::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == EDIT) return("edit");
		else if (ix == EXEC) return("execute");
		else if (ix == VIEW) return("view");
	};

	return("");
};

void VecPlnrWUiaccess::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=VIEW;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixPlnrVLocale));
};

