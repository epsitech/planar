/**
  * \file PnlPlnrCliRec.cpp
  * app access code for job PnlPlnrCliRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrCliRec.h"

/******************************************************************************
 class PnlPlnrCliRec::VecVDo
 ******************************************************************************/

uint PnlPlnrCliRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrCliRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrCliRec::ContInf
 ******************************************************************************/

PnlPlnrCliRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlPlnrCliRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrCliRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrCliRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrCliRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrCliRec::ContInf::diff(
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
 class PnlPlnrCliRec::StatApp
 ******************************************************************************/

PnlPlnrCliRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAAMCalcEnv
			, const bool initdoneAAMCalcPar
			, const bool initdoneRef1NFile
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneAAMCalcEnv = initdoneAAMCalcEnv;
	this->initdoneAAMCalcPar = initdoneAAMCalcPar;
	this->initdoneRef1NFile = initdoneRef1NFile;

	mask = {INITDONEDETAIL, INITDONEAAMCALCENV, INITDONEAAMCALCPAR, INITDONEREF1NFILE};
};

bool PnlPlnrCliRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrCliRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrCliRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAAMCalcEnv", initdoneAAMCalcEnv)) add(INITDONEAAMCALCENV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAAMCalcPar", initdoneAAMCalcPar)) add(INITDONEAAMCALCPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
	};

	return basefound;
};

set<uint> PnlPlnrCliRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAAMCalcEnv == comp->initdoneAAMCalcEnv) insert(items, INITDONEAAMCALCENV);
	if (initdoneAAMCalcPar == comp->initdoneAAMCalcPar) insert(items, INITDONEAAMCALCPAR);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);

	return(items);
};

set<uint> PnlPlnrCliRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAAMCALCENV, INITDONEAAMCALCPAR, INITDONEREF1NFILE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCliRec::StatShr
 ******************************************************************************/

PnlPlnrCliRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAAMCalcEnv
			, const string& scrJrefAAMCalcPar
			, const string& scrJrefRef1NFile
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAAMCalcEnv = scrJrefAAMCalcEnv;
	this->scrJrefAAMCalcPar = scrJrefAAMCalcPar;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFAAMCALCENV, SCRJREFAAMCALCPAR, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
};

bool PnlPlnrCliRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrCliRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrCliRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAAMCalcEnv", scrJrefAAMCalcEnv)) add(SCRJREFAAMCALCENV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAAMCalcPar", scrJrefAAMCalcPar)) add(SCRJREFAAMCALCPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrCliRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefAAMCalcEnv.compare(comp->scrJrefAAMCalcEnv) == 0) insert(items, SCRJREFAAMCALCENV);
	if (scrJrefAAMCalcPar.compare(comp->scrJrefAAMCalcPar) == 0) insert(items, SCRJREFAAMCALCPAR);
	if (scrJrefRef1NFile.compare(comp->scrJrefRef1NFile) == 0) insert(items, SCRJREFREF1NFILE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrCliRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFAAMCALCENV, SCRJREFAAMCALCPAR, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCliRec::Tag
 ******************************************************************************/

PnlPlnrCliRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrCliRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrCliRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrCliRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrCliRec::DpchAppDo
 ******************************************************************************/

PnlPlnrCliRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLIRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrCliRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrCliRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCliRec::DpchEngData
 ******************************************************************************/

PnlPlnrCliRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLIRECDATA) {
};

void PnlPlnrCliRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrCliRecData");
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

