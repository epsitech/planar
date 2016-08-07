/**
  * \file PnlPlnrStkPre.cpp
  * app access code for job PnlPlnrStkPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrStkPre.h"

/******************************************************************************
 class PnlPlnrStkPre::Tag
 ******************************************************************************/

PnlPlnrStkPre::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrStkPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrStkPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrStkPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrStkPre::DpchEngData
 ******************************************************************************/

PnlPlnrStkPre::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSTKPREDATA) {
};

void PnlPlnrStkPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrStkPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		tag = Tag();
	};
};

