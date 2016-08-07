/**
  * \file DlgPlnrClcExprtx.cpp
  * app access code for job DlgPlnrClcExprtx (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DlgPlnrClcExprtx.h"

/******************************************************************************
 class DlgPlnrClcExprtx::VecVDo
 ******************************************************************************/

uint DlgPlnrClcExprtx::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgPlnrClcExprtx::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcExprtx::StatApp
 ******************************************************************************/

DlgPlnrClcExprtx::StatApp::StatApp(
			const string& shortMenu
		) : Block() {
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgPlnrClcExprtx::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgPlnrClcExprtx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgPlnrClcExprtx";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgPlnrClcExprtx::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgPlnrClcExprtx::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrClcExprtx::Tag
 ******************************************************************************/

DlgPlnrClcExprtx::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgPlnrClcExprtx::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrClcExprtx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrClcExprtx";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrClcExprtx::DpchAppDo
 ******************************************************************************/

DlgPlnrClcExprtx::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCEXPRTXDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void DlgPlnrClcExprtx::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrClcExprtxDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcExprtx::DpchEngData
 ******************************************************************************/

DlgPlnrClcExprtx::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRCLCEXPRTXDATA) {
};

void DlgPlnrClcExprtx::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgPlnrClcExprtxData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		statapp = StatApp();
		tag = Tag();
	};
};

