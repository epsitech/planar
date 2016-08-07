/**
  * \file PnlPlnrDtpRec.cpp
  * app access code for job PnlPlnrDtpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDtpRec.h"

/******************************************************************************
 class PnlPlnrDtpRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDtpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrDtpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDtpRec::ContInf
 ******************************************************************************/

PnlPlnrDtpRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrDtpRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrDtpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrDtpRec::ContInf::diff(
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
 class PnlPlnrDtpRec::StatApp
 ******************************************************************************/

PnlPlnrDtpRec::StatApp::StatApp(
			const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneKParKey
			, const bool initdoneAPar
			, const bool initdoneSup1NDevice
			, const bool initdoneHk1NStructure
			, const bool initdoneTpl1NDevice
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneView = initdoneView;
	this->initdoneKParKey = initdoneKParKey;
	this->initdoneAPar = initdoneAPar;
	this->initdoneSup1NDevice = initdoneSup1NDevice;
	this->initdoneHk1NStructure = initdoneHk1NStructure;
	this->initdoneTpl1NDevice = initdoneTpl1NDevice;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEKPARKEY, INITDONEAPAR, INITDONESUP1NDEVICE, INITDONEHK1NSTRUCTURE, INITDONETPL1NDEVICE};
};

bool PnlPlnrDtpRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDtpRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneView", initdoneView)) add(INITDONEVIEW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKParKey", initdoneKParKey)) add(INITDONEKPARKEY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NDevice", initdoneSup1NDevice)) add(INITDONESUP1NDEVICE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NStructure", initdoneHk1NStructure)) add(INITDONEHK1NSTRUCTURE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTpl1NDevice", initdoneTpl1NDevice)) add(INITDONETPL1NDEVICE);
	};

	return basefound;
};

set<uint> PnlPlnrDtpRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneView == comp->initdoneView) insert(items, INITDONEVIEW);
	if (initdoneKParKey == comp->initdoneKParKey) insert(items, INITDONEKPARKEY);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdoneSup1NDevice == comp->initdoneSup1NDevice) insert(items, INITDONESUP1NDEVICE);
	if (initdoneHk1NStructure == comp->initdoneHk1NStructure) insert(items, INITDONEHK1NSTRUCTURE);
	if (initdoneTpl1NDevice == comp->initdoneTpl1NDevice) insert(items, INITDONETPL1NDEVICE);

	return(items);
};

set<uint> PnlPlnrDtpRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEKPARKEY, INITDONEAPAR, INITDONESUP1NDEVICE, INITDONEHK1NSTRUCTURE, INITDONETPL1NDEVICE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpRec::StatShr
 ******************************************************************************/

PnlPlnrDtpRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefView
			, const string& scrJrefKParKey
			, const string& scrJrefAPar
			, const string& scrJrefSup1NDevice
			, const string& scrJrefHk1NStructure
			, const string& scrJrefTpl1NDevice
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefView = scrJrefView;
	this->scrJrefKParKey = scrJrefKParKey;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJrefSup1NDevice = scrJrefSup1NDevice;
	this->scrJrefHk1NStructure = scrJrefHk1NStructure;
	this->scrJrefTpl1NDevice = scrJrefTpl1NDevice;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFKPARKEY, SCRJREFAPAR, SCRJREFSUP1NDEVICE, SCRJREFHK1NSTRUCTURE, SCRJREFTPL1NDEVICE, BUTREGULARIZEACTIVE};
};

bool PnlPlnrDtpRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefView", scrJrefView)) add(SCRJREFVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKParKey", scrJrefKParKey)) add(SCRJREFKPARKEY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NDevice", scrJrefSup1NDevice)) add(SCRJREFSUP1NDEVICE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NStructure", scrJrefHk1NStructure)) add(SCRJREFHK1NSTRUCTURE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTpl1NDevice", scrJrefTpl1NDevice)) add(SCRJREFTPL1NDEVICE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefView.compare(comp->scrJrefView) == 0) insert(items, SCRJREFVIEW);
	if (scrJrefKParKey.compare(comp->scrJrefKParKey) == 0) insert(items, SCRJREFKPARKEY);
	if (scrJrefAPar.compare(comp->scrJrefAPar) == 0) insert(items, SCRJREFAPAR);
	if (scrJrefSup1NDevice.compare(comp->scrJrefSup1NDevice) == 0) insert(items, SCRJREFSUP1NDEVICE);
	if (scrJrefHk1NStructure.compare(comp->scrJrefHk1NStructure) == 0) insert(items, SCRJREFHK1NSTRUCTURE);
	if (scrJrefTpl1NDevice.compare(comp->scrJrefTpl1NDevice) == 0) insert(items, SCRJREFTPL1NDEVICE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrDtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFKPARKEY, SCRJREFAPAR, SCRJREFSUP1NDEVICE, SCRJREFHK1NSTRUCTURE, SCRJREFTPL1NDEVICE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpRec::Tag
 ******************************************************************************/

PnlPlnrDtpRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDtpRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDtpRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDtpRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDTPRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDtpRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDtpRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDtpRec::DpchEngData
 ******************************************************************************/

PnlPlnrDtpRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDTPRECDATA) {
};

void PnlPlnrDtpRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDtpRecData");
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

