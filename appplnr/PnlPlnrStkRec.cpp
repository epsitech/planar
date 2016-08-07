/**
  * \file PnlPlnrStkRec.cpp
  * app access code for job PnlPlnrStkRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrStkRec.h"

/******************************************************************************
 class PnlPlnrStkRec::VecVDo
 ******************************************************************************/

uint PnlPlnrStkRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrStkRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrStkRec::ContInf
 ******************************************************************************/

PnlPlnrStkRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrStkRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrStkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrStkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrStkRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrStkRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkRec::StatApp
 ******************************************************************************/

PnlPlnrStkRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneHk1NLevel
			, const bool initdoneHk1NLayer
			, const bool initdoneMNStructure
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneView = initdoneView;
	this->initdoneHk1NLevel = initdoneHk1NLevel;
	this->initdoneHk1NLayer = initdoneHk1NLayer;
	this->initdoneMNStructure = initdoneMNStructure;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEHK1NLEVEL, INITDONEHK1NLAYER, INITDONEMNSTRUCTURE};
};

bool PnlPlnrStkRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrStkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrStkRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneView", initdoneView)) add(INITDONEVIEW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLevel", initdoneHk1NLevel)) add(INITDONEHK1NLEVEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLayer", initdoneHk1NLayer)) add(INITDONEHK1NLAYER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNStructure", initdoneMNStructure)) add(INITDONEMNSTRUCTURE);
	};

	return basefound;
};

set<uint> PnlPlnrStkRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneView == comp->initdoneView) insert(items, INITDONEVIEW);
	if (initdoneHk1NLevel == comp->initdoneHk1NLevel) insert(items, INITDONEHK1NLEVEL);
	if (initdoneHk1NLayer == comp->initdoneHk1NLayer) insert(items, INITDONEHK1NLAYER);
	if (initdoneMNStructure == comp->initdoneMNStructure) insert(items, INITDONEMNSTRUCTURE);

	return(items);
};

set<uint> PnlPlnrStkRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEHK1NLEVEL, INITDONEHK1NLAYER, INITDONEMNSTRUCTURE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkRec::StatShr
 ******************************************************************************/

PnlPlnrStkRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefView
			, const string& scrJrefHk1NLevel
			, const string& scrJrefHk1NLayer
			, const string& scrJrefMNStructure
			, const bool pnlmnstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefView = scrJrefView;
	this->scrJrefHk1NLevel = scrJrefHk1NLevel;
	this->scrJrefHk1NLayer = scrJrefHk1NLayer;
	this->scrJrefMNStructure = scrJrefMNStructure;
	this->pnlmnstructureAvail = pnlmnstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFHK1NLEVEL, SCRJREFHK1NLAYER, SCRJREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlPlnrStkRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrStkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrStkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefView", scrJrefView)) add(SCRJREFVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLevel", scrJrefHk1NLevel)) add(SCRJREFHK1NLEVEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLayer", scrJrefHk1NLayer)) add(SCRJREFHK1NLAYER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNStructure", scrJrefMNStructure)) add(SCRJREFMNSTRUCTURE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnstructureAvail", pnlmnstructureAvail)) add(PNLMNSTRUCTUREAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrStkRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefView.compare(comp->scrJrefView) == 0) insert(items, SCRJREFVIEW);
	if (scrJrefHk1NLevel.compare(comp->scrJrefHk1NLevel) == 0) insert(items, SCRJREFHK1NLEVEL);
	if (scrJrefHk1NLayer.compare(comp->scrJrefHk1NLayer) == 0) insert(items, SCRJREFHK1NLAYER);
	if (scrJrefMNStructure.compare(comp->scrJrefMNStructure) == 0) insert(items, SCRJREFMNSTRUCTURE);
	if (pnlmnstructureAvail == comp->pnlmnstructureAvail) insert(items, PNLMNSTRUCTUREAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrStkRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFHK1NLEVEL, SCRJREFHK1NLAYER, SCRJREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkRec::Tag
 ******************************************************************************/

PnlPlnrStkRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrStkRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrStkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrStkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrStkRec::DpchAppDo
 ******************************************************************************/

PnlPlnrStkRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrStkRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrStkRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkRec::DpchEngData
 ******************************************************************************/

PnlPlnrStkRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSTKRECDATA) {
};

void PnlPlnrStkRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrStkRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

