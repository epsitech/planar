/**
  * \file SessPlnr.cpp
  * app access code for job SessPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "SessPlnr.h"

/******************************************************************************
 class SessPlnr::StatShr
 ******************************************************************************/

SessPlnr::StatShr::StatShr(
			const string& scrJrefCrdnav
		) : Block() {
	this->scrJrefCrdnav = scrJrefCrdnav;

	mask = {SCRJREFCRDNAV};
};

bool SessPlnr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrSessPlnr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrSessPlnr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", scrJrefCrdnav)) add(SCRJREFCRDNAV);
	};

	return basefound;
};

set<uint> SessPlnr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefCrdnav.compare(comp->scrJrefCrdnav) == 0) insert(items, SCRJREFCRDNAV);

	return(items);
};

set<uint> SessPlnr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCRDNAV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessPlnr::DpchEngData
 ******************************************************************************/

SessPlnr::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGSESSPLNRDATA) {
};

void SessPlnr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngSessPlnrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		statshr = StatShr();
	};
};

