/**
  * \file PnlPlnrTpoFloorplan.cpp
  * app access code for job PnlPlnrTpoFloorplan (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrTpoFloorplan.h"

/******************************************************************************
 class PnlPlnrTpoFloorplan::Tag
 ******************************************************************************/

PnlPlnrTpoFloorplan::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrTpoFloorplan::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrTpoFloorplan");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrTpoFloorplan";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrTpoFloorplan::DpchEngData
 ******************************************************************************/

PnlPlnrTpoFloorplan::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRTPOFLOORPLANDATA) {
};

void PnlPlnrTpoFloorplan::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrTpoFloorplanData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		tag = Tag();
	};
};

