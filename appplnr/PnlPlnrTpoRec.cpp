/**
  * \file PnlPlnrTpoRec.cpp
  * app access code for job PnlPlnrTpoRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrTpoRec.h"

/******************************************************************************
 class PnlPlnrTpoRec::VecVDo
 ******************************************************************************/

uint PnlPlnrTpoRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrTpoRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrTpoRec::ContInf
 ******************************************************************************/

PnlPlnrTpoRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrTpoRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrTpoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrTpoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrTpoRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrTpoRec::ContInf::diff(
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
 class PnlPlnrTpoRec::StatApp
 ******************************************************************************/

PnlPlnrTpoRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneFloorplan
			, const bool initdone1NArray
			, const bool initdoneHk1NReticle
			, const bool initdoneMNProject
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneFloorplan = initdoneFloorplan;
	this->initdone1NArray = initdone1NArray;
	this->initdoneHk1NReticle = initdoneHk1NReticle;
	this->initdoneMNProject = initdoneMNProject;

	mask = {INITDONEDETAIL, INITDONEFLOORPLAN, INITDONE1NARRAY, INITDONEHK1NRETICLE, INITDONEMNPROJECT};
};

bool PnlPlnrTpoRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrTpoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrTpoRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFloorplan", initdoneFloorplan)) add(INITDONEFLOORPLAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NArray", initdone1NArray)) add(INITDONE1NARRAY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NReticle", initdoneHk1NReticle)) add(INITDONEHK1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNProject", initdoneMNProject)) add(INITDONEMNPROJECT);
	};

	return basefound;
};

set<uint> PnlPlnrTpoRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneFloorplan == comp->initdoneFloorplan) insert(items, INITDONEFLOORPLAN);
	if (initdone1NArray == comp->initdone1NArray) insert(items, INITDONE1NARRAY);
	if (initdoneHk1NReticle == comp->initdoneHk1NReticle) insert(items, INITDONEHK1NRETICLE);
	if (initdoneMNProject == comp->initdoneMNProject) insert(items, INITDONEMNPROJECT);

	return(items);
};

set<uint> PnlPlnrTpoRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEFLOORPLAN, INITDONE1NARRAY, INITDONEHK1NRETICLE, INITDONEMNPROJECT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrTpoRec::StatShr
 ******************************************************************************/

PnlPlnrTpoRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefFloorplan
			, const string& scrJref1NArray
			, const string& scrJrefHk1NReticle
			, const string& scrJrefMNProject
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefFloorplan = scrJrefFloorplan;
	this->scrJref1NArray = scrJref1NArray;
	this->scrJrefHk1NReticle = scrJrefHk1NReticle;
	this->scrJrefMNProject = scrJrefMNProject;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFFLOORPLAN, SCRJREF1NARRAY, SCRJREFHK1NRETICLE, SCRJREFMNPROJECT, BUTREGULARIZEACTIVE};
};

bool PnlPlnrTpoRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrTpoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrTpoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFloorplan", scrJrefFloorplan)) add(SCRJREFFLOORPLAN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NArray", scrJref1NArray)) add(SCRJREF1NARRAY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NReticle", scrJrefHk1NReticle)) add(SCRJREFHK1NRETICLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNProject", scrJrefMNProject)) add(SCRJREFMNPROJECT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrTpoRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefFloorplan.compare(comp->scrJrefFloorplan) == 0) insert(items, SCRJREFFLOORPLAN);
	if (scrJref1NArray.compare(comp->scrJref1NArray) == 0) insert(items, SCRJREF1NARRAY);
	if (scrJrefHk1NReticle.compare(comp->scrJrefHk1NReticle) == 0) insert(items, SCRJREFHK1NRETICLE);
	if (scrJrefMNProject.compare(comp->scrJrefMNProject) == 0) insert(items, SCRJREFMNPROJECT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrTpoRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFFLOORPLAN, SCRJREF1NARRAY, SCRJREFHK1NRETICLE, SCRJREFMNPROJECT, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrTpoRec::Tag
 ******************************************************************************/

PnlPlnrTpoRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrTpoRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrTpoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrTpoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrTpoRec::DpchAppDo
 ******************************************************************************/

PnlPlnrTpoRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRTPORECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrTpoRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrTpoRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrTpoRec::DpchEngData
 ******************************************************************************/

PnlPlnrTpoRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRTPORECDATA) {
};

void PnlPlnrTpoRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrTpoRecData");
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

