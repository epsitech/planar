/**
  * \file PnlPlnrLyrDetail.cpp
  * app access code for job PnlPlnrLyrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrLyrDetail.h"

/******************************************************************************
 class PnlPlnrLyrDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrLyrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("buthkuviewclick") == 0) return BUTHKUVIEWCLICK;
	else if (s.compare("butmatviewclick") == 0) return BUTMATVIEWCLICK;

	return(0);
};

string PnlPlnrLyrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	else if (ix == BUTMATVIEWCLICK) return("ButMatViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrLyrDetail::ContIac
 ******************************************************************************/

PnlPlnrLyrDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupHkt
			, const uint numFPupTty
			, const string& TxfT
			, const string& TxfMl
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFPupHkt = numFPupHkt;
	this->numFPupTty = numFPupTty;
	this->TxfT = TxfT;
	this->TxfMl = TxfMl;

	mask = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTTY, TXFT, TXFML};
};

bool PnlPlnrLyrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrLyrDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTty", numFPupTty)) add(NUMFPUPTTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfT", TxfT)) add(TXFT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMl", TxfMl)) add(TXFML);
	};

	return basefound;
};

void PnlPlnrLyrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeUintAttr(wr, itemtag, "sref", "numFPupTty", numFPupTty);
		writeStringAttr(wr, itemtag, "sref", "TxfT", TxfT);
		writeStringAttr(wr, itemtag, "sref", "TxfMl", TxfMl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupTty == comp->numFPupTty) insert(items, NUMFPUPTTY);
	if (TxfT.compare(comp->TxfT) == 0) insert(items, TXFT);
	if (TxfMl.compare(comp->TxfMl) == 0) insert(items, TXFML);

	return(items);
};

set<uint> PnlPlnrLyrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTTY, TXFT, TXFML};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::ContInf
 ******************************************************************************/

PnlPlnrLyrDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
			, const string& TxtMat
			, const string& TxtFlr
			, const string& TxtCtr
			, const string& TxtCei
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtMat = TxtMat;
	this->TxtFlr = TxtFlr;
	this->TxtCtr = TxtCtr;
	this->TxtCei = TxtCei;

	mask = {TXTSRF, TXTHKU, TXTMAT, TXTFLR, TXTCTR, TXTCEI};
};

bool PnlPlnrLyrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrLyrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMat", TxtMat)) add(TXTMAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFlr", TxtFlr)) add(TXTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCtr", TxtCtr)) add(TXTCTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCei", TxtCei)) add(TXTCEI);
	};

	return basefound;
};

set<uint> PnlPlnrLyrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtHku.compare(comp->TxtHku) == 0) insert(items, TXTHKU);
	if (TxtMat.compare(comp->TxtMat) == 0) insert(items, TXTMAT);
	if (TxtFlr.compare(comp->TxtFlr) == 0) insert(items, TXTFLR);
	if (TxtCtr.compare(comp->TxtCtr) == 0) insert(items, TXTCTR);
	if (TxtCei.compare(comp->TxtCei) == 0) insert(items, TXTCEI);

	return(items);
};

set<uint> PnlPlnrLyrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTMAT, TXTFLR, TXTCTR, TXTCEI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::StatApp
 ******************************************************************************/

PnlPlnrLyrDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrLyrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrLyrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrLyrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrLyrDetail::StatApp::diff(
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
 class PnlPlnrLyrDetail::StatShr
 ******************************************************************************/

PnlPlnrLyrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButMatViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButMatViewAvail = ButMatViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTMATVIEWAVAIL};
};

bool PnlPlnrLyrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrLyrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMatViewAvail", ButMatViewAvail)) add(BUTMATVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrLyrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButMatViewAvail == comp->ButMatViewAvail) insert(items, BUTMATVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrLyrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTMATVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::Tag
 ******************************************************************************/

PnlPlnrLyrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptHku
			, const string& CptMat
			, const string& CptTty
			, const string& CptFlr
			, const string& CptCtr
			, const string& CptCei
			, const string& CptT
			, const string& CptMl
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptHku = CptHku;
	this->CptMat = CptMat;
	this->CptTty = CptTty;
	this->CptFlr = CptFlr;
	this->CptCtr = CptCtr;
	this->CptCei = CptCei;
	this->CptT = CptT;
	this->CptMl = CptMl;

	mask = {CPT, CPTSRF, CPTTYP, CPTHKU, CPTMAT, CPTTTY, CPTFLR, CPTCTR, CPTCEI, CPTT, CPTML};
};

bool PnlPlnrLyrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrLyrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMat", CptMat)) add(CPTMAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTty", CptTty)) add(CPTTTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlr", CptFlr)) add(CPTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtr", CptCtr)) add(CPTCTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCei", CptCei)) add(CPTCEI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptT", CptT)) add(CPTT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMl", CptMl)) add(CPTML);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrLyrDetail::DpchAppData
 ******************************************************************************/

PnlPlnrLyrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrLyrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrLyrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrLyrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrLyrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrLyrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrDetail::DpchEngData
 ******************************************************************************/

PnlPlnrLyrDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRLYRDETAILDATA) {
	feedFPupHkt.tag = "FeedFPupHkt";
	feedFPupTty.tag = "FeedFPupTty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

void PnlPlnrLyrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrLyrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (feedFPupTty.readXML(docctx, basexpath, true)) add(FEEDFPUPTTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupHkt.clear();
		feedFPupTty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

