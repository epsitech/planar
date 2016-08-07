/**
  * \file CrdPlnrDgd.cpp
  * app access code for job CrdPlnrDgd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "CrdPlnrDgd.h"

/******************************************************************************
 class CrdPlnrDgd::VecVDo
 ******************************************************************************/

uint CrdPlnrDgd::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("close") == 0) return CLOSE;
	else if (s.compare("mitappabtclick") == 0) return MITAPPABTCLICK;

	return(0);
};

string CrdPlnrDgd::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdPlnrDgd::VecVSge
 ******************************************************************************/

uint CrdPlnrDgd::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("alrplnrabt") == 0) return ALRPLNRABT;
	else if (s.compare("close") == 0) return CLOSE;

	return(0);
};

string CrdPlnrDgd::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdPlnrDgd::ContInf
 ******************************************************************************/

CrdPlnrDgd::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdDgd
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdDgd = MtxCrdDgd;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDDGD};
};

bool CrdPlnrDgd::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDgd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDgd";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdDgd", MtxCrdDgd)) add(MTXCRDDGD);
	};

	return basefound;
};

set<uint> CrdPlnrDgd::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxCrdDgd.compare(comp->MtxCrdDgd) == 0) insert(items, MTXCRDDGD);

	return(items);
};

set<uint> CrdPlnrDgd::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDDGD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrDgd::StatApp
 ******************************************************************************/

CrdPlnrDgd::StatApp::StatApp(
			const uint ixPlnrVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) : Block() {
	this->ixPlnrVReqitmode = ixPlnrVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXPLNRVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdPlnrDgd::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDgd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDgd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode)) {
			ixPlnrVReqitmode = VecPlnrVReqitmode::getIx(srefIxPlnrVReqitmode);
			add(IXPLNRVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdPlnrDgd::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVReqitmode == comp->ixPlnrVReqitmode) insert(items, IXPLNRVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdPlnrDgd::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrDgd::StatShr
 ******************************************************************************/

CrdPlnrDgd::StatShr::StatShr(
			const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
		) : Block() {
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;

	mask = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
};

bool CrdPlnrDgd::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDgd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDgd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
	};

	return basefound;
};

set<uint> CrdPlnrDgd::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefList.compare(comp->scrJrefList) == 0) insert(items, SCRJREFLIST);
	if (scrJrefRec.compare(comp->scrJrefRec) == 0) insert(items, SCRJREFREC);

	return(items);
};

set<uint> CrdPlnrDgd::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrDgd::Tag
 ******************************************************************************/

CrdPlnrDgd::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdPlnrDgd::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDgd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDgd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdPlnrDgd::DpchAppDo
 ******************************************************************************/

CrdPlnrDgd::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void CrdPlnrDgd::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDgdDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrDgd::DpchEngData
 ******************************************************************************/

CrdPlnrDgd::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDGDDATA) {
	feedFSge.tag = "FeedFSge";
};

void CrdPlnrDgd::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDgdData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

