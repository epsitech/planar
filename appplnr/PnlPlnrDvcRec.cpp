/**
  * \file PnlPlnrDvcRec.cpp
  * app access code for job PnlPlnrDvcRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDvcRec.h"

/******************************************************************************
 class PnlPlnrDvcRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDvcRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrDvcRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDvcRec::ContInf
 ******************************************************************************/

PnlPlnrDvcRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrDvcRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDvcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDvcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrDvcRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrDvcRec::ContInf::diff(
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
 class PnlPlnrDvcRec::StatApp
 ******************************************************************************/

PnlPlnrDvcRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneAPar
			, const bool initdoneSup1NDevice
			, const bool initdoneHk1NStructure
			, const bool initdoneHk1NVertex
			, const bool initdoneHk1NLineguide
			, const bool initdoneHk1NArcguide
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneView = initdoneView;
	this->initdoneAPar = initdoneAPar;
	this->initdoneSup1NDevice = initdoneSup1NDevice;
	this->initdoneHk1NStructure = initdoneHk1NStructure;
	this->initdoneHk1NVertex = initdoneHk1NVertex;
	this->initdoneHk1NLineguide = initdoneHk1NLineguide;
	this->initdoneHk1NArcguide = initdoneHk1NArcguide;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEAPAR, INITDONESUP1NDEVICE, INITDONEHK1NSTRUCTURE, INITDONEHK1NVERTEX, INITDONEHK1NLINEGUIDE, INITDONEHK1NARCGUIDE};
};

bool PnlPlnrDvcRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDvcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDvcRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneView", initdoneView)) add(INITDONEVIEW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NDevice", initdoneSup1NDevice)) add(INITDONESUP1NDEVICE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NStructure", initdoneHk1NStructure)) add(INITDONEHK1NSTRUCTURE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVertex", initdoneHk1NVertex)) add(INITDONEHK1NVERTEX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLineguide", initdoneHk1NLineguide)) add(INITDONEHK1NLINEGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NArcguide", initdoneHk1NArcguide)) add(INITDONEHK1NARCGUIDE);
	};

	return basefound;
};

set<uint> PnlPlnrDvcRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneView == comp->initdoneView) insert(items, INITDONEVIEW);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdoneSup1NDevice == comp->initdoneSup1NDevice) insert(items, INITDONESUP1NDEVICE);
	if (initdoneHk1NStructure == comp->initdoneHk1NStructure) insert(items, INITDONEHK1NSTRUCTURE);
	if (initdoneHk1NVertex == comp->initdoneHk1NVertex) insert(items, INITDONEHK1NVERTEX);
	if (initdoneHk1NLineguide == comp->initdoneHk1NLineguide) insert(items, INITDONEHK1NLINEGUIDE);
	if (initdoneHk1NArcguide == comp->initdoneHk1NArcguide) insert(items, INITDONEHK1NARCGUIDE);

	return(items);
};

set<uint> PnlPlnrDvcRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEAPAR, INITDONESUP1NDEVICE, INITDONEHK1NSTRUCTURE, INITDONEHK1NVERTEX, INITDONEHK1NLINEGUIDE, INITDONEHK1NARCGUIDE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcRec::StatShr
 ******************************************************************************/

PnlPlnrDvcRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefView
			, const string& scrJrefAPar
			, const string& scrJrefSup1NDevice
			, const string& scrJrefHk1NStructure
			, const string& scrJrefHk1NVertex
			, const string& scrJrefHk1NLineguide
			, const string& scrJrefHk1NArcguide
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefView = scrJrefView;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJrefSup1NDevice = scrJrefSup1NDevice;
	this->scrJrefHk1NStructure = scrJrefHk1NStructure;
	this->scrJrefHk1NVertex = scrJrefHk1NVertex;
	this->scrJrefHk1NLineguide = scrJrefHk1NLineguide;
	this->scrJrefHk1NArcguide = scrJrefHk1NArcguide;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFAPAR, SCRJREFSUP1NDEVICE, SCRJREFHK1NSTRUCTURE, SCRJREFHK1NVERTEX, SCRJREFHK1NLINEGUIDE, SCRJREFHK1NARCGUIDE, BUTREGULARIZEACTIVE};
};

bool PnlPlnrDvcRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDvcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDvcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefView", scrJrefView)) add(SCRJREFVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NDevice", scrJrefSup1NDevice)) add(SCRJREFSUP1NDEVICE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NStructure", scrJrefHk1NStructure)) add(SCRJREFHK1NSTRUCTURE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVertex", scrJrefHk1NVertex)) add(SCRJREFHK1NVERTEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLineguide", scrJrefHk1NLineguide)) add(SCRJREFHK1NLINEGUIDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NArcguide", scrJrefHk1NArcguide)) add(SCRJREFHK1NARCGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDvcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefView.compare(comp->scrJrefView) == 0) insert(items, SCRJREFVIEW);
	if (scrJrefAPar.compare(comp->scrJrefAPar) == 0) insert(items, SCRJREFAPAR);
	if (scrJrefSup1NDevice.compare(comp->scrJrefSup1NDevice) == 0) insert(items, SCRJREFSUP1NDEVICE);
	if (scrJrefHk1NStructure.compare(comp->scrJrefHk1NStructure) == 0) insert(items, SCRJREFHK1NSTRUCTURE);
	if (scrJrefHk1NVertex.compare(comp->scrJrefHk1NVertex) == 0) insert(items, SCRJREFHK1NVERTEX);
	if (scrJrefHk1NLineguide.compare(comp->scrJrefHk1NLineguide) == 0) insert(items, SCRJREFHK1NLINEGUIDE);
	if (scrJrefHk1NArcguide.compare(comp->scrJrefHk1NArcguide) == 0) insert(items, SCRJREFHK1NARCGUIDE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrDvcRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFAPAR, SCRJREFSUP1NDEVICE, SCRJREFHK1NSTRUCTURE, SCRJREFHK1NVERTEX, SCRJREFHK1NLINEGUIDE, SCRJREFHK1NARCGUIDE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcRec::Tag
 ******************************************************************************/

PnlPlnrDvcRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDvcRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDvcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDvcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDvcRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDvcRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDVCRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDvcRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDvcRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDvcRec::DpchEngData
 ******************************************************************************/

PnlPlnrDvcRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDVCRECDATA) {
};

void PnlPlnrDvcRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDvcRecData");
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

