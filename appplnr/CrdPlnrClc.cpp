/**
  * \file CrdPlnrClc.cpp
  * app access code for job CrdPlnrClc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "CrdPlnrClc.h"

/******************************************************************************
 class CrdPlnrClc::VecVDo
 ******************************************************************************/

uint CrdPlnrClc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("close") == 0) return CLOSE;
	else if (s.compare("mitappabtclick") == 0) return MITAPPABTCLICK;
	else if (s.compare("mitcrducsclick") == 0) return MITCRDUCSCLICK;
	else if (s.compare("mitcrdgpvclick") == 0) return MITCRDGPVCLICK;
	else if (s.compare("mitcrdetxclick") == 0) return MITCRDETXCLICK;

	return(0);
};

string CrdPlnrClc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITCRDUCSCLICK) return("MitCrdUcsClick");
	else if (ix == MITCRDGPVCLICK) return("MitCrdGpvClick");
	else if (ix == MITCRDETXCLICK) return("MitCrdEtxClick");

	return("");
};

/******************************************************************************
 class CrdPlnrClc::VecVSge
 ******************************************************************************/

uint CrdPlnrClc::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("alrplnrabt") == 0) return ALRPLNRABT;
	else if (s.compare("close") == 0) return CLOSE;

	return(0);
};

string CrdPlnrClc::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdPlnrClc::ContInf
 ******************************************************************************/

CrdPlnrClc::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdClc
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdClc = MtxCrdClc;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDCLC};
};

bool CrdPlnrClc::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrClc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrClc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdClc", MtxCrdClc)) add(MTXCRDCLC);
	};

	return basefound;
};

set<uint> CrdPlnrClc::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxCrdClc.compare(comp->MtxCrdClc) == 0) insert(items, MTXCRDCLC);

	return(items);
};

set<uint> CrdPlnrClc::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDCLC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrClc::StatApp
 ******************************************************************************/

CrdPlnrClc::StatApp::StatApp(
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

bool CrdPlnrClc::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrClc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrClc";

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

set<uint> CrdPlnrClc::StatApp::comm(
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

set<uint> CrdPlnrClc::StatApp::diff(
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
 class CrdPlnrClc::StatShr
 ******************************************************************************/

CrdPlnrClc::StatShr::StatShr(
			const string& scrJrefDlgexprtx
			, const string& scrJrefDlggenrpv
			, const string& scrJrefDlgusecase
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdUcsAvail
			, const bool MitCrdGpvAvail
			, const bool MitCrdGpvActive
			, const bool MitCrdEtxAvail
			, const bool MitCrdEtxActive
		) : Block() {
	this->scrJrefDlgexprtx = scrJrefDlgexprtx;
	this->scrJrefDlggenrpv = scrJrefDlggenrpv;
	this->scrJrefDlgusecase = scrJrefDlgusecase;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUcsAvail = MitCrdUcsAvail;
	this->MitCrdGpvAvail = MitCrdGpvAvail;
	this->MitCrdGpvActive = MitCrdGpvActive;
	this->MitCrdEtxAvail = MitCrdEtxAvail;
	this->MitCrdEtxActive = MitCrdEtxActive;

	mask = {SCRJREFDLGEXPRTX, SCRJREFDLGGENRPV, SCRJREFDLGUSECASE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDUCSAVAIL, MITCRDGPVAVAIL, MITCRDGPVACTIVE, MITCRDETXAVAIL, MITCRDETXACTIVE};
};

bool CrdPlnrClc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrClc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrClc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgexprtx", scrJrefDlgexprtx)) add(SCRJREFDLGEXPRTX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlggenrpv", scrJrefDlggenrpv)) add(SCRJREFDLGGENRPV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgusecase", scrJrefDlgusecase)) add(SCRJREFDLGUSECASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUcsAvail", MitCrdUcsAvail)) add(MITCRDUCSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGpvAvail", MitCrdGpvAvail)) add(MITCRDGPVAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGpvActive", MitCrdGpvActive)) add(MITCRDGPVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEtxAvail", MitCrdEtxAvail)) add(MITCRDETXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEtxActive", MitCrdEtxActive)) add(MITCRDETXACTIVE);
	};

	return basefound;
};

set<uint> CrdPlnrClc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgexprtx.compare(comp->scrJrefDlgexprtx) == 0) insert(items, SCRJREFDLGEXPRTX);
	if (scrJrefDlggenrpv.compare(comp->scrJrefDlggenrpv) == 0) insert(items, SCRJREFDLGGENRPV);
	if (scrJrefDlgusecase.compare(comp->scrJrefDlgusecase) == 0) insert(items, SCRJREFDLGUSECASE);
	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefList.compare(comp->scrJrefList) == 0) insert(items, SCRJREFLIST);
	if (scrJrefRec.compare(comp->scrJrefRec) == 0) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUcsAvail == comp->MitCrdUcsAvail) insert(items, MITCRDUCSAVAIL);
	if (MitCrdGpvAvail == comp->MitCrdGpvAvail) insert(items, MITCRDGPVAVAIL);
	if (MitCrdGpvActive == comp->MitCrdGpvActive) insert(items, MITCRDGPVACTIVE);
	if (MitCrdEtxAvail == comp->MitCrdEtxAvail) insert(items, MITCRDETXAVAIL);
	if (MitCrdEtxActive == comp->MitCrdEtxActive) insert(items, MITCRDETXACTIVE);

	return(items);
};

set<uint> CrdPlnrClc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGEXPRTX, SCRJREFDLGGENRPV, SCRJREFDLGUSECASE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDUCSAVAIL, MITCRDGPVAVAIL, MITCRDGPVACTIVE, MITCRDETXAVAIL, MITCRDETXACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrClc::Tag
 ******************************************************************************/

CrdPlnrClc::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdUcs
			, const string& MitCrdGpv
			, const string& MitCrdEtx
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdUcs = MitCrdUcs;
	this->MitCrdGpv = MitCrdGpv;
	this->MitCrdEtx = MitCrdEtx;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDUCS, MITCRDGPV, MITCRDETX};
};

bool CrdPlnrClc::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrClc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrClc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUcs", MitCrdUcs)) add(MITCRDUCS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdGpv", MitCrdGpv)) add(MITCRDGPV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdEtx", MitCrdEtx)) add(MITCRDETX);
	};

	return basefound;
};

/******************************************************************************
 class CrdPlnrClc::DpchAppDo
 ******************************************************************************/

CrdPlnrClc::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLCDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void CrdPlnrClc::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrClcDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrClc::DpchEngData
 ******************************************************************************/

CrdPlnrClc::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLCDATA) {
	feedFSge.tag = "FeedFSge";
};

void CrdPlnrClc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrClcData");
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

