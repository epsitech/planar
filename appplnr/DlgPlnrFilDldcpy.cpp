/**
  * \file DlgPlnrFilDldcpy.cpp
  * app access code for job DlgPlnrFilDldcpy (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DlgPlnrFilDldcpy.h"

/******************************************************************************
 class DlgPlnrFilDldcpy::VecVDo
 ******************************************************************************/

uint DlgPlnrFilDldcpy::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgPlnrFilDldcpy::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrFilDldcpy::StatApp
 ******************************************************************************/

DlgPlnrFilDldcpy::StatApp::StatApp(
			const string& shortMenu
		) : Block() {
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgPlnrFilDldcpy::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgPlnrFilDldcpy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgPlnrFilDldcpy";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgPlnrFilDldcpy::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgPlnrFilDldcpy::StatApp::diff(
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
 class DlgPlnrFilDldcpy::Tag
 ******************************************************************************/

DlgPlnrFilDldcpy::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgPlnrFilDldcpy::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrFilDldcpy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrFilDldcpy";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrFilDldcpy::DpchAppDo
 ******************************************************************************/

DlgPlnrFilDldcpy::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRFILDLDCPYDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void DlgPlnrFilDldcpy::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrFilDldcpyDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrFilDldcpy::DpchEngData
 ******************************************************************************/

DlgPlnrFilDldcpy::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRFILDLDCPYDATA) {
};

void DlgPlnrFilDldcpy::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgPlnrFilDldcpyData");
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

