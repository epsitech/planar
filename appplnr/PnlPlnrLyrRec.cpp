/**
  * \file PnlPlnrLyrRec.cpp
  * app access code for job PnlPlnrLyrRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrLyrRec.h"

/******************************************************************************
 class PnlPlnrLyrRec::VecVDo
 ******************************************************************************/

uint PnlPlnrLyrRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrLyrRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrLyrRec::ContInf
 ******************************************************************************/

PnlPlnrLyrRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrLyrRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrLyrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrLyrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrLyrRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrLyrRec::ContInf::diff(
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
 class PnlPlnrLyrRec::StatApp
 ******************************************************************************/

PnlPlnrLyrRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NBlock
			, const bool initdone1NReticle
			, const bool initdoneMNStructure
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdone1NBlock = initdone1NBlock;
	this->initdone1NReticle = initdone1NReticle;
	this->initdoneMNStructure = initdoneMNStructure;

	mask = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONE1NRETICLE, INITDONEMNSTRUCTURE};
};

bool PnlPlnrLyrRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrLyrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrLyrRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBlock", initdone1NBlock)) add(INITDONE1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NReticle", initdone1NReticle)) add(INITDONE1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNStructure", initdoneMNStructure)) add(INITDONEMNSTRUCTURE);
	};

	return basefound;
};

set<uint> PnlPlnrLyrRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NBlock == comp->initdone1NBlock) insert(items, INITDONE1NBLOCK);
	if (initdone1NReticle == comp->initdone1NReticle) insert(items, INITDONE1NRETICLE);
	if (initdoneMNStructure == comp->initdoneMNStructure) insert(items, INITDONEMNSTRUCTURE);

	return(items);
};

set<uint> PnlPlnrLyrRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONE1NRETICLE, INITDONEMNSTRUCTURE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrRec::StatShr
 ******************************************************************************/

PnlPlnrLyrRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NBlock
			, const bool pnl1nblockAvail
			, const string& scrJref1NReticle
			, const bool pnl1nreticleAvail
			, const string& scrJrefMNStructure
			, const bool pnlmnstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NBlock = scrJref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->scrJref1NReticle = scrJref1NReticle;
	this->pnl1nreticleAvail = pnl1nreticleAvail;
	this->scrJrefMNStructure = scrJrefMNStructure;
	this->pnlmnstructureAvail = pnlmnstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREF1NRETICLE, PNL1NRETICLEAVAIL, SCRJREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlPlnrLyrRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrLyrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrLyrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBlock", scrJref1NBlock)) add(SCRJREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nblockAvail", pnl1nblockAvail)) add(PNL1NBLOCKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NReticle", scrJref1NReticle)) add(SCRJREF1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nreticleAvail", pnl1nreticleAvail)) add(PNL1NRETICLEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNStructure", scrJrefMNStructure)) add(SCRJREFMNSTRUCTURE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnstructureAvail", pnlmnstructureAvail)) add(PNLMNSTRUCTUREAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrLyrRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJref1NBlock.compare(comp->scrJref1NBlock) == 0) insert(items, SCRJREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (scrJref1NReticle.compare(comp->scrJref1NReticle) == 0) insert(items, SCRJREF1NRETICLE);
	if (pnl1nreticleAvail == comp->pnl1nreticleAvail) insert(items, PNL1NRETICLEAVAIL);
	if (scrJrefMNStructure.compare(comp->scrJrefMNStructure) == 0) insert(items, SCRJREFMNSTRUCTURE);
	if (pnlmnstructureAvail == comp->pnlmnstructureAvail) insert(items, PNLMNSTRUCTUREAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrLyrRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREF1NRETICLE, PNL1NRETICLEAVAIL, SCRJREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrRec::Tag
 ******************************************************************************/

PnlPlnrLyrRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrLyrRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrLyrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrLyrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrLyrRec::DpchAppDo
 ******************************************************************************/

PnlPlnrLyrRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrLyrRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrLyrRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrRec::DpchEngData
 ******************************************************************************/

PnlPlnrLyrRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRLYRRECDATA) {
};

void PnlPlnrLyrRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrLyrRecData");
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

