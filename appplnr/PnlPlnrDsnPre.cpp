/**
  * \file PnlPlnrDsnPre.cpp
  * app access code for job PnlPlnrDsnPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnPre.h"

/******************************************************************************
 class PnlPlnrDsnPre::Tag
 ******************************************************************************/

PnlPlnrDsnPre::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDsnPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnPre::DpchEngData
 ******************************************************************************/

PnlPlnrDsnPre::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNPREDATA) {
};

void PnlPlnrDsnPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		tag = Tag();
	};
};

