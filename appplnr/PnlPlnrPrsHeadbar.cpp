/**
  * \file PnlPlnrPrsHeadbar.cpp
  * app access code for job PnlPlnrPrsHeadbar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrPrsHeadbar.h"

/******************************************************************************
 class PnlPlnrPrsHeadbar::StgInf
 ******************************************************************************/

PnlPlnrPrsHeadbar::StgInf::StgInf(
			const uint MenAppCptwidth
			, const uint MenAppWidth
			, const uint MenCrdCptwidth
			, const uint MenCrdWidth
		) : Block() {
	this->MenAppCptwidth = MenAppCptwidth;
	this->MenAppWidth = MenAppWidth;
	this->MenCrdCptwidth = MenCrdCptwidth;
	this->MenCrdWidth = MenCrdWidth;

	mask = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
};

bool PnlPlnrPrsHeadbar::StgInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgInfPlnrPrsHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemInfPlnrPrsHeadbar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", MenAppCptwidth)) add(MENAPPCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppWidth", MenAppWidth)) add(MENAPPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdCptwidth", MenCrdCptwidth)) add(MENCRDCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdWidth", MenCrdWidth)) add(MENCRDWIDTH);
	};

	return basefound;
};

set<uint> PnlPlnrPrsHeadbar::StgInf::comm(
			const StgInf* comp
		) {
	set<uint> items;

	if (MenAppCptwidth == comp->MenAppCptwidth) insert(items, MENAPPCPTWIDTH);
	if (MenAppWidth == comp->MenAppWidth) insert(items, MENAPPWIDTH);
	if (MenCrdCptwidth == comp->MenCrdCptwidth) insert(items, MENCRDCPTWIDTH);
	if (MenCrdWidth == comp->MenCrdWidth) insert(items, MENCRDWIDTH);

	return(items);
};

set<uint> PnlPlnrPrsHeadbar::StgInf::diff(
			const StgInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrPrsHeadbar::Tag
 ******************************************************************************/

PnlPlnrPrsHeadbar::Tag::Tag(
			const string& MenApp
			, const string& MenCrd
		) : Block() {
	this->MenApp = MenApp;
	this->MenCrd = MenCrd;

	mask = {MENAPP, MENCRD};
};

bool PnlPlnrPrsHeadbar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrPrsHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrPrsHeadbar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenApp", MenApp)) add(MENAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenCrd", MenCrd)) add(MENCRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrPrsHeadbar::DpchEngData
 ******************************************************************************/

PnlPlnrPrsHeadbar::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRPRSHEADBARDATA) {
};

void PnlPlnrPrsHeadbar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrPrsHeadbarData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (stginf.readXML(docctx, basexpath, true)) add(STGINF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		stginf = StgInf();
		tag = Tag();
	};
};

