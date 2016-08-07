/**
  * \file PnlPlnrSruRec.cpp
  * app access code for job PnlPlnrSruRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrSruRec.h"

/******************************************************************************
 class PnlPlnrSruRec::VecVDo
 ******************************************************************************/

uint PnlPlnrSruRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrSruRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrSruRec::ContInf
 ******************************************************************************/

PnlPlnrSruRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrSruRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrSruRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrSruRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrSruRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrSruRec::ContInf::diff(
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
 class PnlPlnrSruRec::StatApp
 ******************************************************************************/

PnlPlnrSruRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NBlock
			, const bool initdoneSru1NFace
			, const bool initdoneMNLayer
			, const bool initdoneMNStack
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdone1NBlock = initdone1NBlock;
	this->initdoneSru1NFace = initdoneSru1NFace;
	this->initdoneMNLayer = initdoneMNLayer;
	this->initdoneMNStack = initdoneMNStack;

	mask = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONESRU1NFACE, INITDONEMNLAYER, INITDONEMNSTACK};
};

bool PnlPlnrSruRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrSruRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrSruRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBlock", initdone1NBlock)) add(INITDONE1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSru1NFace", initdoneSru1NFace)) add(INITDONESRU1NFACE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLayer", initdoneMNLayer)) add(INITDONEMNLAYER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNStack", initdoneMNStack)) add(INITDONEMNSTACK);
	};

	return basefound;
};

set<uint> PnlPlnrSruRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NBlock == comp->initdone1NBlock) insert(items, INITDONE1NBLOCK);
	if (initdoneSru1NFace == comp->initdoneSru1NFace) insert(items, INITDONESRU1NFACE);
	if (initdoneMNLayer == comp->initdoneMNLayer) insert(items, INITDONEMNLAYER);
	if (initdoneMNStack == comp->initdoneMNStack) insert(items, INITDONEMNSTACK);

	return(items);
};

set<uint> PnlPlnrSruRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONESRU1NFACE, INITDONEMNLAYER, INITDONEMNSTACK};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruRec::StatShr
 ******************************************************************************/

PnlPlnrSruRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NBlock
			, const bool pnl1nblockAvail
			, const string& scrJrefSru1NFace
			, const string& scrJrefMNLayer
			, const bool pnlmnlayerAvail
			, const string& scrJrefMNStack
			, const bool pnlmnstackAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NBlock = scrJref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->scrJrefSru1NFace = scrJrefSru1NFace;
	this->scrJrefMNLayer = scrJrefMNLayer;
	this->pnlmnlayerAvail = pnlmnlayerAvail;
	this->scrJrefMNStack = scrJrefMNStack;
	this->pnlmnstackAvail = pnlmnstackAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREFSRU1NFACE, SCRJREFMNLAYER, PNLMNLAYERAVAIL, SCRJREFMNSTACK, PNLMNSTACKAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlPlnrSruRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrSruRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrSruRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBlock", scrJref1NBlock)) add(SCRJREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nblockAvail", pnl1nblockAvail)) add(PNL1NBLOCKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSru1NFace", scrJrefSru1NFace)) add(SCRJREFSRU1NFACE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLayer", scrJrefMNLayer)) add(SCRJREFMNLAYER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnlayerAvail", pnlmnlayerAvail)) add(PNLMNLAYERAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNStack", scrJrefMNStack)) add(SCRJREFMNSTACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnstackAvail", pnlmnstackAvail)) add(PNLMNSTACKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrSruRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJref1NBlock.compare(comp->scrJref1NBlock) == 0) insert(items, SCRJREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (scrJrefSru1NFace.compare(comp->scrJrefSru1NFace) == 0) insert(items, SCRJREFSRU1NFACE);
	if (scrJrefMNLayer.compare(comp->scrJrefMNLayer) == 0) insert(items, SCRJREFMNLAYER);
	if (pnlmnlayerAvail == comp->pnlmnlayerAvail) insert(items, PNLMNLAYERAVAIL);
	if (scrJrefMNStack.compare(comp->scrJrefMNStack) == 0) insert(items, SCRJREFMNSTACK);
	if (pnlmnstackAvail == comp->pnlmnstackAvail) insert(items, PNLMNSTACKAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrSruRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREFSRU1NFACE, SCRJREFMNLAYER, PNLMNLAYERAVAIL, SCRJREFMNSTACK, PNLMNSTACKAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruRec::Tag
 ******************************************************************************/

PnlPlnrSruRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrSruRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrSruRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrSruRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrSruRec::DpchAppDo
 ******************************************************************************/

PnlPlnrSruRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRURECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrSruRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrSruRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruRec::DpchEngData
 ******************************************************************************/

PnlPlnrSruRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSRURECDATA) {
};

void PnlPlnrSruRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrSruRecData");
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

