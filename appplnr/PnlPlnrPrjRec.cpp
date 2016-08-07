/**
  * \file PnlPlnrPrjRec.cpp
  * app access code for job PnlPlnrPrjRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrPrjRec.h"

/******************************************************************************
 class PnlPlnrPrjRec::VecVDo
 ******************************************************************************/

uint PnlPlnrPrjRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrPrjRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrPrjRec::ContInf
 ******************************************************************************/

PnlPlnrPrjRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrPrjRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrPrjRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrPrjRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrPrjRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrPrjRec::ContInf::diff(
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
 class PnlPlnrPrjRec::StatApp
 ******************************************************************************/

PnlPlnrPrjRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NCalc
			, const bool initdone1NDesign
			, const bool initdoneMNTapeout
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdone1NCalc = initdone1NCalc;
	this->initdone1NDesign = initdone1NDesign;
	this->initdoneMNTapeout = initdoneMNTapeout;

	mask = {INITDONEDETAIL, INITDONE1NCALC, INITDONE1NDESIGN, INITDONEMNTAPEOUT};
};

bool PnlPlnrPrjRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrPrjRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrPrjRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCalc", initdone1NCalc)) add(INITDONE1NCALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NDesign", initdone1NDesign)) add(INITDONE1NDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNTapeout", initdoneMNTapeout)) add(INITDONEMNTAPEOUT);
	};

	return basefound;
};

set<uint> PnlPlnrPrjRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NCalc == comp->initdone1NCalc) insert(items, INITDONE1NCALC);
	if (initdone1NDesign == comp->initdone1NDesign) insert(items, INITDONE1NDESIGN);
	if (initdoneMNTapeout == comp->initdoneMNTapeout) insert(items, INITDONEMNTAPEOUT);

	return(items);
};

set<uint> PnlPlnrPrjRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NCALC, INITDONE1NDESIGN, INITDONEMNTAPEOUT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrPrjRec::StatShr
 ******************************************************************************/

PnlPlnrPrjRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NCalc
			, const string& scrJref1NDesign
			, const string& scrJrefMNTapeout
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NCalc = scrJref1NCalc;
	this->scrJref1NDesign = scrJref1NDesign;
	this->scrJrefMNTapeout = scrJrefMNTapeout;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NCALC, SCRJREF1NDESIGN, SCRJREFMNTAPEOUT, BUTREGULARIZEACTIVE};
};

bool PnlPlnrPrjRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrPrjRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrPrjRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCalc", scrJref1NCalc)) add(SCRJREF1NCALC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NDesign", scrJref1NDesign)) add(SCRJREF1NDESIGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNTapeout", scrJrefMNTapeout)) add(SCRJREFMNTAPEOUT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrPrjRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJref1NCalc.compare(comp->scrJref1NCalc) == 0) insert(items, SCRJREF1NCALC);
	if (scrJref1NDesign.compare(comp->scrJref1NDesign) == 0) insert(items, SCRJREF1NDESIGN);
	if (scrJrefMNTapeout.compare(comp->scrJrefMNTapeout) == 0) insert(items, SCRJREFMNTAPEOUT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrPrjRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREF1NCALC, SCRJREF1NDESIGN, SCRJREFMNTAPEOUT, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrPrjRec::Tag
 ******************************************************************************/

PnlPlnrPrjRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrPrjRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrPrjRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrPrjRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrPrjRec::DpchAppDo
 ******************************************************************************/

PnlPlnrPrjRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRPRJRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrPrjRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrPrjRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrPrjRec::DpchEngData
 ******************************************************************************/

PnlPlnrPrjRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRPRJRECDATA) {
};

void PnlPlnrPrjRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrPrjRecData");
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

