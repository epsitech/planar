/**
  * \file PnlPlnrUsrDetail.cpp
  * app access code for job PnlPlnrUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrUsrDetail.h"

/******************************************************************************
 class PnlPlnrUsrDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrUsrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butprsviewclick") == 0) return BUTPRSVIEWCLICK;
	else if (s.compare("butusgviewclick") == 0) return BUTUSGVIEWCLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;

	return(0);
};

string PnlPlnrUsrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	else if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlPlnrUsrDetail::ContIac
 ******************************************************************************/

PnlPlnrUsrDetail::ContIac::ContIac(
			const uint numFPupJ
			, const uint numFPupSte
			, const uint numFPupLcl
			, const uint numFPupUlv
			, const string& TxfPwd
		) : Block() {
	this->numFPupJ = numFPupJ;
	this->numFPupSte = numFPupSte;
	this->numFPupLcl = numFPupLcl;
	this->numFPupUlv = numFPupUlv;
	this->TxfPwd = TxfPwd;

	mask = {NUMFPUPJ, NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD};
};

bool PnlPlnrUsrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrUsrDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLcl", numFPupLcl)) add(NUMFPUPLCL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupUlv", numFPupUlv)) add(NUMFPUPULV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPwd", TxfPwd)) add(TXFPWD);
	};

	return basefound;
};

void PnlPlnrUsrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeUintAttr(wr, itemtag, "sref", "numFPupLcl", numFPupLcl);
		writeUintAttr(wr, itemtag, "sref", "numFPupUlv", numFPupUlv);
		writeStringAttr(wr, itemtag, "sref", "TxfPwd", TxfPwd);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrUsrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (numFPupLcl == comp->numFPupLcl) insert(items, NUMFPUPLCL);
	if (numFPupUlv == comp->numFPupUlv) insert(items, NUMFPUPULV);
	if (TxfPwd.compare(comp->TxfPwd) == 0) insert(items, TXFPWD);

	return(items);
};

set<uint> PnlPlnrUsrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJ, NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrDetail::ContInf
 ******************************************************************************/

PnlPlnrUsrDetail::ContInf::ContInf(
			const string& TxtPrs
			, const string& TxtSrf
			, const string& TxtUsg
		) : Block() {
	this->TxtPrs = TxtPrs;
	this->TxtSrf = TxtSrf;
	this->TxtUsg = TxtUsg;

	mask = {TXTPRS, TXTSRF, TXTUSG};
};

bool PnlPlnrUsrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrs", TxtPrs)) add(TXTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUsg", TxtUsg)) add(TXTUSG);
	};

	return basefound;
};

set<uint> PnlPlnrUsrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrs.compare(comp->TxtPrs) == 0) insert(items, TXTPRS);
	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtUsg.compare(comp->TxtUsg) == 0) insert(items, TXTUSG);

	return(items);
};

set<uint> PnlPlnrUsrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRS, TXTSRF, TXTUSG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrDetail::StatApp
 ******************************************************************************/

PnlPlnrUsrDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrUsrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrUsrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrUsrDetail::StatApp::diff(
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
 class PnlPlnrUsrDetail::StatShr
 ******************************************************************************/

PnlPlnrUsrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPrsViewAvail
			, const bool ButUsgViewAvail
			, const bool ButJEditAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPrsViewAvail = ButPrsViewAvail;
	this->ButUsgViewAvail = ButUsgViewAvail;
	this->ButJEditAvail = ButJEditAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRSVIEWAVAIL, BUTUSGVIEWAVAIL, BUTJEDITAVAIL};
};

bool PnlPlnrUsrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrUsrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewAvail", ButPrsViewAvail)) add(BUTPRSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewAvail", ButUsgViewAvail)) add(BUTUSGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrUsrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPrsViewAvail == comp->ButPrsViewAvail) insert(items, BUTPRSVIEWAVAIL);
	if (ButUsgViewAvail == comp->ButUsgViewAvail) insert(items, BUTUSGVIEWAVAIL);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);

	return(items);
};

set<uint> PnlPlnrUsrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRSVIEWAVAIL, BUTUSGVIEWAVAIL, BUTJEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrDetail::Tag
 ******************************************************************************/

PnlPlnrUsrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptPrs
			, const string& CptSrf
			, const string& CptUsg
			, const string& CptSte
			, const string& CptLcl
			, const string& CptUlv
			, const string& CptPwd
		) : Block() {
	this->Cpt = Cpt;
	this->CptPrs = CptPrs;
	this->CptSrf = CptSrf;
	this->CptUsg = CptUsg;
	this->CptSte = CptSte;
	this->CptLcl = CptLcl;
	this->CptUlv = CptUlv;
	this->CptPwd = CptPwd;

	mask = {CPT, CPTPRS, CPTSRF, CPTUSG, CPTSTE, CPTLCL, CPTULV, CPTPWD};
};

bool PnlPlnrUsrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLcl", CptLcl)) add(CPTLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUlv", CptUlv)) add(CPTULV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPwd", CptPwd)) add(CPTPWD);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrUsrDetail::DpchAppData
 ******************************************************************************/

PnlPlnrUsrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrUsrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrUsrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrUsrDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrUsrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrUsrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrUsrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrUsrDetail::DpchEngData
 ******************************************************************************/

PnlPlnrUsrDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRUSRDETAILDATA) {
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcl.tag = "FeedFPupLcl";
	feedFPupSte.tag = "FeedFPupSte";
	feedFPupUlv.tag = "FeedFPupUlv";
};

void PnlPlnrUsrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrUsrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (feedFPupLcl.readXML(docctx, basexpath, true)) add(FEEDFPUPLCL);
		if (feedFPupSte.readXML(docctx, basexpath, true)) add(FEEDFPUPSTE);
		if (feedFPupUlv.readXML(docctx, basexpath, true)) add(FEEDFPUPULV);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJ.clear();
		feedFPupLcl.clear();
		feedFPupSte.clear();
		feedFPupUlv.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

