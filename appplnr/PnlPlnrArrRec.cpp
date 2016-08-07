/**
  * \file PnlPlnrArrRec.cpp
  * app access code for job PnlPlnrArrRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrArrRec.h"

/******************************************************************************
 class PnlPlnrArrRec::VecVDo
 ******************************************************************************/

uint PnlPlnrArrRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrArrRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrArrRec::ContInf
 ******************************************************************************/

PnlPlnrArrRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrArrRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrArrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrArrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrArrRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrArrRec::ContInf::diff(
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
 class PnlPlnrArrRec::StatApp
 ******************************************************************************/

PnlPlnrArrRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKEnvKey
			, const bool initdoneAEnv
			, const bool initdone1NArrayitem
			, const bool initdoneHk1NReticle
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneKEnvKey = initdoneKEnvKey;
	this->initdoneAEnv = initdoneAEnv;
	this->initdone1NArrayitem = initdone1NArrayitem;
	this->initdoneHk1NReticle = initdoneHk1NReticle;

	mask = {INITDONEDETAIL, INITDONEKENVKEY, INITDONEAENV, INITDONE1NARRAYITEM, INITDONEHK1NRETICLE};
};

bool PnlPlnrArrRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrArrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrArrRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKEnvKey", initdoneKEnvKey)) add(INITDONEKENVKEY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAEnv", initdoneAEnv)) add(INITDONEAENV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NArrayitem", initdone1NArrayitem)) add(INITDONE1NARRAYITEM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NReticle", initdoneHk1NReticle)) add(INITDONEHK1NRETICLE);
	};

	return basefound;
};

set<uint> PnlPlnrArrRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKEnvKey == comp->initdoneKEnvKey) insert(items, INITDONEKENVKEY);
	if (initdoneAEnv == comp->initdoneAEnv) insert(items, INITDONEAENV);
	if (initdone1NArrayitem == comp->initdone1NArrayitem) insert(items, INITDONE1NARRAYITEM);
	if (initdoneHk1NReticle == comp->initdoneHk1NReticle) insert(items, INITDONEHK1NRETICLE);

	return(items);
};

set<uint> PnlPlnrArrRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKENVKEY, INITDONEAENV, INITDONE1NARRAYITEM, INITDONEHK1NRETICLE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrRec::StatShr
 ******************************************************************************/

PnlPlnrArrRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKEnvKey
			, const string& scrJrefAEnv
			, const string& scrJref1NArrayitem
			, const string& scrJrefHk1NReticle
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKEnvKey = scrJrefKEnvKey;
	this->scrJrefAEnv = scrJrefAEnv;
	this->scrJref1NArrayitem = scrJref1NArrayitem;
	this->scrJrefHk1NReticle = scrJrefHk1NReticle;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFKENVKEY, SCRJREFAENV, SCRJREF1NARRAYITEM, SCRJREFHK1NRETICLE, BUTREGULARIZEACTIVE};
};

bool PnlPlnrArrRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrArrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrArrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKEnvKey", scrJrefKEnvKey)) add(SCRJREFKENVKEY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAEnv", scrJrefAEnv)) add(SCRJREFAENV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NArrayitem", scrJref1NArrayitem)) add(SCRJREF1NARRAYITEM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NReticle", scrJrefHk1NReticle)) add(SCRJREFHK1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrArrRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefKEnvKey.compare(comp->scrJrefKEnvKey) == 0) insert(items, SCRJREFKENVKEY);
	if (scrJrefAEnv.compare(comp->scrJrefAEnv) == 0) insert(items, SCRJREFAENV);
	if (scrJref1NArrayitem.compare(comp->scrJref1NArrayitem) == 0) insert(items, SCRJREF1NARRAYITEM);
	if (scrJrefHk1NReticle.compare(comp->scrJrefHk1NReticle) == 0) insert(items, SCRJREFHK1NRETICLE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrArrRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFKENVKEY, SCRJREFAENV, SCRJREF1NARRAYITEM, SCRJREFHK1NRETICLE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrRec::Tag
 ******************************************************************************/

PnlPlnrArrRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrArrRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrArrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrArrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrArrRec::DpchAppDo
 ******************************************************************************/

PnlPlnrArrRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrArrRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrArrRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrRec::DpchEngData
 ******************************************************************************/

PnlPlnrArrRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARRRECDATA) {
};

void PnlPlnrArrRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrArrRecData");
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

