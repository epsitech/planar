/**
  * \file PnlPlnrRtcDetail.cpp
  * app access code for job PnlPlnrRtcDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrRtcDetail.h"

/******************************************************************************
 class PnlPlnrRtcDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrRtcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("buthkuviewclick") == 0) return BUTHKUVIEWCLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;
	else if (s.compare("butlyrviewclick") == 0) return BUTLYRVIEWCLICK;

	return(0);
};

string PnlPlnrRtcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");
	else if (ix == BUTLYRVIEWCLICK) return("ButLyrViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrRtcDetail::ContIac
 ******************************************************************************/

PnlPlnrRtcDetail::ContIac::ContIac(
			const uint numFPupHkt
			, const string& TxfX0
			, const string& TxfY0
			, const string& TxfPhi
		) : Block() {
	this->numFPupHkt = numFPupHkt;
	this->TxfX0 = TxfX0;
	this->TxfY0 = TxfY0;
	this->TxfPhi = TxfPhi;

	mask = {NUMFPUPHKT, TXFX0, TXFY0, TXFPHI};
};

bool PnlPlnrRtcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrRtcDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX0", TxfX0)) add(TXFX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY0", TxfY0)) add(TXFY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPhi", TxfPhi)) add(TXFPHI);
	};

	return basefound;
};

void PnlPlnrRtcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfX0", TxfX0);
		writeStringAttr(wr, itemtag, "sref", "TxfY0", TxfY0);
		writeStringAttr(wr, itemtag, "sref", "TxfPhi", TxfPhi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrRtcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfX0.compare(comp->TxfX0) == 0) insert(items, TXFX0);
	if (TxfY0.compare(comp->TxfY0) == 0) insert(items, TXFY0);
	if (TxfPhi.compare(comp->TxfPhi) == 0) insert(items, TXFPHI);

	return(items);
};

set<uint> PnlPlnrRtcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPHKT, TXFX0, TXFY0, TXFPHI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::ContInf
 ******************************************************************************/

PnlPlnrRtcDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
			, const string& TxtDsn
			, const string& TxtLyr
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtDsn = TxtDsn;
	this->TxtLyr = TxtLyr;

	mask = {TXTSRF, TXTHKU, TXTDSN, TXTLYR};
};

bool PnlPlnrRtcDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrRtcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLyr", TxtLyr)) add(TXTLYR);
	};

	return basefound;
};

set<uint> PnlPlnrRtcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtHku.compare(comp->TxtHku) == 0) insert(items, TXTHKU);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtLyr.compare(comp->TxtLyr) == 0) insert(items, TXTLYR);

	return(items);
};

set<uint> PnlPlnrRtcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTDSN, TXTLYR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::StatApp
 ******************************************************************************/

PnlPlnrRtcDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrRtcDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrRtcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrRtcDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrRtcDetail::StatApp::diff(
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
 class PnlPlnrRtcDetail::StatShr
 ******************************************************************************/

PnlPlnrRtcDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
			, const bool ButLyrViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;
	this->ButLyrViewAvail = ButLyrViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL};
};

bool PnlPlnrRtcDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrRtcDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLyrViewAvail", ButLyrViewAvail)) add(BUTLYRVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrRtcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);
	if (ButLyrViewAvail == comp->ButLyrViewAvail) insert(items, BUTLYRVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrRtcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::Tag
 ******************************************************************************/

PnlPlnrRtcDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptHku
			, const string& CptDsn
			, const string& CptLyr
			, const string& CptX0
			, const string& CptY0
			, const string& CptPhi
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptHku = CptHku;
	this->CptDsn = CptDsn;
	this->CptLyr = CptLyr;
	this->CptX0 = CptX0;
	this->CptY0 = CptY0;
	this->CptPhi = CptPhi;

	mask = {CPT, CPTSRF, CPTHKU, CPTDSN, CPTLYR, CPTX0, CPTY0, CPTPHI};
};

bool PnlPlnrRtcDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrRtcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLyr", CptLyr)) add(CPTLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptX0", CptX0)) add(CPTX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptY0", CptY0)) add(CPTY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPhi", CptPhi)) add(CPTPHI);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrRtcDetail::DpchAppData
 ******************************************************************************/

PnlPlnrRtcDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrRtcDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrRtcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrRtcDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrRtcDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrRtcDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrRtcDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrRtcDetail::DpchEngData
 ******************************************************************************/

PnlPlnrRtcDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRRTCDETAILDATA) {
	feedFPupHkt.tag = "FeedFPupHkt";
};

void PnlPlnrRtcDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrRtcDetailData");
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

