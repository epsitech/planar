/**
  * \file PnlPlnrDsnViewxy.cpp
  * app access code for job PnlPlnrDsnViewxy (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnViewxy.h"

/******************************************************************************
 class PnlPlnrDsnViewxy::Tag
 ******************************************************************************/

PnlPlnrDsnViewxy::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDsnViewxy::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnViewxy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnViewxy";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnViewxy::DpchEngData
 ******************************************************************************/

PnlPlnrDsnViewxy::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNVIEWXYDATA) {
};

void PnlPlnrDsnViewxy::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnViewxyData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		tag = Tag();
	};
};

