/**
  * \file PnlPlnrDsnHk1NLevel.cpp
  * app access code for job PnlPlnrDsnHk1NLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnHk1NLevel.h"

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnHk1NLevel::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrDsnHk1NLevel::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::ContInf
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlPlnrDsnHk1NLevel::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDsnHk1NLevel";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrDsnHk1NLevel::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrDsnHk1NLevel::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::StatApp
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrDsnHk1NLevel::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDsnHk1NLevel";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrDsnHk1NLevel::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrDsnHk1NLevel::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::StatShr
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::StatShr::StatShr(
			const bool ButDeleteActive
		) : Block() {
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTDELETEACTIVE};
};

bool PnlPlnrDsnHk1NLevel::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDsnHk1NLevel";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDsnHk1NLevel::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrDsnHk1NLevel::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::StgIac
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::StgIac::StgIac(
			const uint TcoRefWidth
		) : Block() {
	this->TcoRefWidth = TcoRefWidth;

	mask = {TCOREFWIDTH};
};

bool PnlPlnrDsnHk1NLevel::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrDsnHk1NLevel";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlPlnrDsnHk1NLevel::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrDsnHk1NLevel";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrDsnHk1NLevel";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnHk1NLevel::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlPlnrDsnHk1NLevel::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOREFWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::Tag
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoRef
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoRef = TcoRef;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOREF};
};

bool PnlPlnrDsnHk1NLevel::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnHk1NLevel";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRef", TcoRef)) add(TCOREF);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::DpchAppData
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryPlnrDsnHk1NLevel::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLEVELDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrDsnHk1NLevel::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnHk1NLevelData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLEVELDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDsnHk1NLevel::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnHk1NLevelDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnHk1NLevel::DpchEngData
 ******************************************************************************/

PnlPlnrDsnHk1NLevel::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNHK1NLEVELDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

void PnlPlnrDsnHk1NLevel::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnHk1NLevelData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryPlnrDsnHk1NLevel::StatApp();
		statshrqry = QryPlnrDsnHk1NLevel::StatShr();
		stgiacqry = QryPlnrDsnHk1NLevel::StgIac();
	};
};

