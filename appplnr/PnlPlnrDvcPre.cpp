/**
  * \file PnlPlnrDvcPre.cpp
  * app access code for job PnlPlnrDvcPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDvcPre.h"

/******************************************************************************
 class PnlPlnrDvcPre::Tag
 ******************************************************************************/

PnlPlnrDvcPre::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDvcPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDvcPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDvcPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDvcPre::DpchEngData
 ******************************************************************************/

PnlPlnrDvcPre::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDVCPREDATA) {
};

void PnlPlnrDvcPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDvcPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		tag = Tag();
	};
};

