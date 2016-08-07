/**
  * \file PnlPlnrFilMNCalc.cpp
  * app access code for job PnlPlnrFilMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrFilMNCalc.h"

/******************************************************************************
 class PnlPlnrFilMNCalc::VecVDo
 ******************************************************************************/

uint PnlPlnrFilMNCalc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butaddclick") == 0) return BUTADDCLICK;
	else if (s.compare("butsubclick") == 0) return BUTSUBCLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrFilMNCalc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrFilMNCalc::ContInf
 ******************************************************************************/

PnlPlnrFilMNCalc::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlPlnrFilMNCalc::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrFilMNCalc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrFilMNCalc::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrFilMNCalc::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::StatApp
 ******************************************************************************/

PnlPlnrFilMNCalc::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrFilMNCalc::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrFilMNCalc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrFilMNCalc::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrFilMNCalc::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::StatShr
 ******************************************************************************/

PnlPlnrFilMNCalc::StatShr::StatShr(
			const bool ButSubActive
		) : Block() {
	this->ButSubActive = ButSubActive;

	mask = {BUTSUBACTIVE};
};

bool PnlPlnrFilMNCalc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrFilMNCalc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubActive", ButSubActive)) add(BUTSUBACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrFilMNCalc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlPlnrFilMNCalc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSUBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::StgIac
 ******************************************************************************/

PnlPlnrFilMNCalc::StgIac::StgIac(
			const uint TcoMrefWidth
			, const uint TcoCliWidth
			, const uint TcoIoWidth
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	this->TcoCliWidth = TcoCliWidth;
	this->TcoIoWidth = TcoIoWidth;

	mask = {TCOMREFWIDTH, TCOCLIWIDTH, TCOIOWIDTH};
};

bool PnlPlnrFilMNCalc::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrFilMNCalc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCliWidth", TcoCliWidth)) add(TCOCLIWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIoWidth", TcoIoWidth)) add(TCOIOWIDTH);
	};

	return basefound;
};

void PnlPlnrFilMNCalc::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrFilMNCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrFilMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCliWidth", TcoCliWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoIoWidth", TcoIoWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrFilMNCalc::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);
	if (TcoCliWidth == comp->TcoCliWidth) insert(items, TCOCLIWIDTH);
	if (TcoIoWidth == comp->TcoIoWidth) insert(items, TCOIOWIDTH);

	return(items);
};

set<uint> PnlPlnrFilMNCalc::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH, TCOCLIWIDTH, TCOIOWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::Tag
 ******************************************************************************/

PnlPlnrFilMNCalc::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoMref
			, const string& TcoCli
			, const string& TcoIo
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoMref = TcoMref;
	this->TcoCli = TcoCli;
	this->TcoIo = TcoIo;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOCLI, TCOIO};
};

bool PnlPlnrFilMNCalc::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrFilMNCalc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMref", TcoMref)) add(TCOMREF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCli", TcoCli)) add(TCOCLI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIo", TcoIo)) add(TCOIO);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrFilMNCalc::DpchAppData
 ******************************************************************************/

PnlPlnrFilMNCalc::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryPlnrFilMNCalc::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRFILMNCALCDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrFilMNCalc::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrFilMNCalcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::DpchAppDo
 ******************************************************************************/

PnlPlnrFilMNCalc::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRFILMNCALCDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrFilMNCalc::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrFilMNCalcDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrFilMNCalc::DpchEngData
 ******************************************************************************/

PnlPlnrFilMNCalc::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRFILMNCALCDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

void PnlPlnrFilMNCalc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrFilMNCalcData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryPlnrFilMNCalc::StatApp();
		statshrqry = QryPlnrFilMNCalc::StatShr();
		stgiacqry = QryPlnrFilMNCalc::StgIac();
	};
};

