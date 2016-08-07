/**
  * \file PnlPlnrSruDetail.cpp
  * app access code for job PnlPlnrSruDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrSruDetail.h"

/******************************************************************************
 class PnlPlnrSruDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrSruDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("buthkuviewclick") == 0) return BUTHKUVIEWCLICK;

	return(0);
};

string PnlPlnrSruDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrSruDetail::ContIac
 ******************************************************************************/

PnlPlnrSruDetail::ContIac::ContIac(
			const uint numFPupHkt
			, const string& TxfX0
			, const string& TxfX1
			, const string& TxfY0
			, const string& TxfY1
		) : Block() {
	this->numFPupHkt = numFPupHkt;
	this->TxfX0 = TxfX0;
	this->TxfX1 = TxfX1;
	this->TxfY0 = TxfY0;
	this->TxfY1 = TxfY1;

	mask = {NUMFPUPHKT, TXFX0, TXFX1, TXFY0, TXFY1};
};

bool PnlPlnrSruDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrSruDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX0", TxfX0)) add(TXFX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX1", TxfX1)) add(TXFX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY0", TxfY0)) add(TXFY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY1", TxfY1)) add(TXFY1);
	};

	return basefound;
};

void PnlPlnrSruDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfX0", TxfX0);
		writeStringAttr(wr, itemtag, "sref", "TxfX1", TxfX1);
		writeStringAttr(wr, itemtag, "sref", "TxfY0", TxfY0);
		writeStringAttr(wr, itemtag, "sref", "TxfY1", TxfY1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfX0.compare(comp->TxfX0) == 0) insert(items, TXFX0);
	if (TxfX1.compare(comp->TxfX1) == 0) insert(items, TXFX1);
	if (TxfY0.compare(comp->TxfY0) == 0) insert(items, TXFY0);
	if (TxfY1.compare(comp->TxfY1) == 0) insert(items, TXFY1);

	return(items);
};

set<uint> PnlPlnrSruDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPHKT, TXFX0, TXFX1, TXFY0, TXFY1};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::ContInf
 ******************************************************************************/

PnlPlnrSruDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;

	mask = {TXTSRF, TXTHKU};
};

bool PnlPlnrSruDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrSruDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
	};

	return basefound;
};

set<uint> PnlPlnrSruDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtHku.compare(comp->TxtHku) == 0) insert(items, TXTHKU);

	return(items);
};

set<uint> PnlPlnrSruDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::StatApp
 ******************************************************************************/

PnlPlnrSruDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrSruDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrSruDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrSruDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrSruDetail::StatApp::diff(
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
 class PnlPlnrSruDetail::StatShr
 ******************************************************************************/

PnlPlnrSruDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE};
};

bool PnlPlnrSruDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrSruDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrSruDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);

	return(items);
};

set<uint> PnlPlnrSruDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::Tag
 ******************************************************************************/

PnlPlnrSruDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptHku
			, const string& CptX0
			, const string& CptX1
			, const string& CptY0
			, const string& CptY1
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptHku = CptHku;
	this->CptX0 = CptX0;
	this->CptX1 = CptX1;
	this->CptY0 = CptY0;
	this->CptY1 = CptY1;

	mask = {CPT, CPTSRF, CPTHKU, CPTX0, CPTX1, CPTY0, CPTY1};
};

bool PnlPlnrSruDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrSruDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptX0", CptX0)) add(CPTX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptX1", CptX1)) add(CPTX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptY0", CptY0)) add(CPTY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptY1", CptY1)) add(CPTY1);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrSruDetail::DpchAppData
 ******************************************************************************/

PnlPlnrSruDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrSruDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrSruDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrSruDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrSruDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrSruDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruDetail::DpchEngData
 ******************************************************************************/

PnlPlnrSruDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSRUDETAILDATA) {
	feedFPupHkt.tag = "FeedFPupHkt";
};

void PnlPlnrSruDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrSruDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupHkt.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

