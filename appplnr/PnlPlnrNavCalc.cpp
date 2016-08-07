/**
  * \file PnlPlnrNavCalc.cpp
  * app access code for job PnlPlnrNavCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrNavCalc.h"

/******************************************************************************
 class PnlPlnrNavCalc::VecVDo
 ******************************************************************************/

uint PnlPlnrNavCalc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butclcviewclick") == 0) return BUTCLCVIEWCLICK;
	else if (s.compare("butclcnewcrdclick") == 0) return BUTCLCNEWCRDCLICK;
	else if (s.compare("butcliviewclick") == 0) return BUTCLIVIEWCLICK;
	else if (s.compare("butclinewcrdclick") == 0) return BUTCLINEWCRDCLICK;

	return(0);
};

string PnlPlnrNavCalc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCLCVIEWCLICK) return("ButClcViewClick");
	else if (ix == BUTCLCNEWCRDCLICK) return("ButClcNewcrdClick");
	else if (ix == BUTCLIVIEWCLICK) return("ButCliViewClick");
	else if (ix == BUTCLINEWCRDCLICK) return("ButCliNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavCalc::ContIac
 ******************************************************************************/

PnlPlnrNavCalc::ContIac::ContIac(
			const uint numFLstClc
			, const uint numFLstCli
		) : Block() {
	this->numFLstClc = numFLstClc;
	this->numFLstCli = numFLstCli;

	mask = {NUMFLSTCLC, NUMFLSTCLI};
};

bool PnlPlnrNavCalc::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavCalc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClc", numFLstClc)) add(NUMFLSTCLC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCli", numFLstCli)) add(NUMFLSTCLI);
	};

	return basefound;
};

void PnlPlnrNavCalc::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavCalc";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClc", numFLstClc);
		writeUintAttr(wr, itemtag, "sref", "numFLstCli", numFLstCli);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavCalc::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClc == comp->numFLstClc) insert(items, NUMFLSTCLC);
	if (numFLstCli == comp->numFLstCli) insert(items, NUMFLSTCLI);

	return(items);
};

set<uint> PnlPlnrNavCalc::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLC, NUMFLSTCLI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavCalc::StatApp
 ******************************************************************************/

PnlPlnrNavCalc::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool LstClcAlt
			, const bool LstCliAlt
			, const uint LstClcNumFirstdisp
			, const uint LstCliNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->LstClcAlt = LstClcAlt;
	this->LstCliAlt = LstCliAlt;
	this->LstClcNumFirstdisp = LstClcNumFirstdisp;
	this->LstCliNumFirstdisp = LstCliNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, LSTCLCALT, LSTCLIALT, LSTCLCNUMFIRSTDISP, LSTCLINUMFIRSTDISP};
};

bool PnlPlnrNavCalc::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrNavCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrNavCalc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClcAlt", LstClcAlt)) add(LSTCLCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCliAlt", LstCliAlt)) add(LSTCLIALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClcNumFirstdisp", LstClcNumFirstdisp)) add(LSTCLCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCliNumFirstdisp", LstCliNumFirstdisp)) add(LSTCLINUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrNavCalc::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (LstClcAlt == comp->LstClcAlt) insert(items, LSTCLCALT);
	if (LstCliAlt == comp->LstCliAlt) insert(items, LSTCLIALT);
	if (LstClcNumFirstdisp == comp->LstClcNumFirstdisp) insert(items, LSTCLCNUMFIRSTDISP);
	if (LstCliNumFirstdisp == comp->LstCliNumFirstdisp) insert(items, LSTCLINUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrNavCalc::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, LSTCLCALT, LSTCLIALT, LSTCLCNUMFIRSTDISP, LSTCLINUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavCalc::StatShr
 ******************************************************************************/

PnlPlnrNavCalc::StatShr::StatShr(
			const bool LstClcAvail
			, const bool ButClcViewActive
			, const bool ButClcNewcrdActive
			, const bool LstCliAvail
			, const bool ButCliViewActive
			, const bool ButCliNewcrdActive
		) : Block() {
	this->LstClcAvail = LstClcAvail;
	this->ButClcViewActive = ButClcViewActive;
	this->ButClcNewcrdActive = ButClcNewcrdActive;
	this->LstCliAvail = LstCliAvail;
	this->ButCliViewActive = ButCliViewActive;
	this->ButCliNewcrdActive = ButCliNewcrdActive;

	mask = {LSTCLCAVAIL, BUTCLCVIEWACTIVE, BUTCLCNEWCRDACTIVE, LSTCLIAVAIL, BUTCLIVIEWACTIVE, BUTCLINEWCRDACTIVE};
};

bool PnlPlnrNavCalc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNavCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNavCalc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClcAvail", LstClcAvail)) add(LSTCLCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClcViewActive", ButClcViewActive)) add(BUTCLCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClcNewcrdActive", ButClcNewcrdActive)) add(BUTCLCNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCliAvail", LstCliAvail)) add(LSTCLIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCliViewActive", ButCliViewActive)) add(BUTCLIVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCliNewcrdActive", ButCliNewcrdActive)) add(BUTCLINEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrNavCalc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstClcAvail == comp->LstClcAvail) insert(items, LSTCLCAVAIL);
	if (ButClcViewActive == comp->ButClcViewActive) insert(items, BUTCLCVIEWACTIVE);
	if (ButClcNewcrdActive == comp->ButClcNewcrdActive) insert(items, BUTCLCNEWCRDACTIVE);
	if (LstCliAvail == comp->LstCliAvail) insert(items, LSTCLIAVAIL);
	if (ButCliViewActive == comp->ButCliViewActive) insert(items, BUTCLIVIEWACTIVE);
	if (ButCliNewcrdActive == comp->ButCliNewcrdActive) insert(items, BUTCLINEWCRDACTIVE);

	return(items);
};

set<uint> PnlPlnrNavCalc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCLCAVAIL, BUTCLCVIEWACTIVE, BUTCLCNEWCRDACTIVE, LSTCLIAVAIL, BUTCLIVIEWACTIVE, BUTCLINEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavCalc::Tag
 ******************************************************************************/

PnlPlnrNavCalc::Tag::Tag(
			const string& Cpt
			, const string& CptClc
			, const string& CptCli
		) : Block() {
	this->Cpt = Cpt;
	this->CptClc = CptClc;
	this->CptCli = CptCli;

	mask = {CPT, CPTCLC, CPTCLI};
};

bool PnlPlnrNavCalc::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNavCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNavCalc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClc", CptClc)) add(CPTCLC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCli", CptCli)) add(CPTCLI);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrNavCalc::DpchAppData
 ******************************************************************************/

PnlPlnrNavCalc::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVCALCDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrNavCalc::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavCalcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavCalc::DpchAppDo
 ******************************************************************************/

PnlPlnrNavCalc::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVCALCDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrNavCalc::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavCalcDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavCalc::DpchEngData
 ******************************************************************************/

PnlPlnrNavCalc::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVCALCDATA) {
	feedFLstClc.tag = "FeedFLstClc";
	feedFLstCli.tag = "FeedFLstCli";
};

void PnlPlnrNavCalc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavCalcData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstClc.readXML(docctx, basexpath, true)) add(FEEDFLSTCLC);
		if (feedFLstCli.readXML(docctx, basexpath, true)) add(FEEDFLSTCLI);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstClc.clear();
		feedFLstCli.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

