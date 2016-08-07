/**
  * \file PnlPlnrMat1NLayer.cpp
  * app access code for job PnlPlnrMat1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrMat1NLayer.h"

/******************************************************************************
 class PnlPlnrMat1NLayer::VecVDo
 ******************************************************************************/

uint PnlPlnrMat1NLayer::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butviewclick") == 0) return BUTVIEWCLICK;
	else if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrMat1NLayer::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrMat1NLayer::ContInf
 ******************************************************************************/

PnlPlnrMat1NLayer::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlPlnrMat1NLayer::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrMat1NLayer";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrMat1NLayer::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrMat1NLayer::ContInf::diff(
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
 class PnlPlnrMat1NLayer::StatApp
 ******************************************************************************/

PnlPlnrMat1NLayer::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrMat1NLayer::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrMat1NLayer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrMat1NLayer::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrMat1NLayer::StatApp::diff(
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
 class PnlPlnrMat1NLayer::StatShr
 ******************************************************************************/

PnlPlnrMat1NLayer::StatShr::StatShr(
			const bool ButViewActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButViewActive = ButViewActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTVIEWACTIVE, BUTDELETEACTIVE};
};

bool PnlPlnrMat1NLayer::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrMat1NLayer";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewActive", ButViewActive)) add(BUTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrMat1NLayer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrMat1NLayer::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMat1NLayer::StgIac
 ******************************************************************************/

PnlPlnrMat1NLayer::StgIac::StgIac(
			const uint TcoRefWidth
		) : Block() {
	this->TcoRefWidth = TcoRefWidth;

	mask = {TCOREFWIDTH};
};

bool PnlPlnrMat1NLayer::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrMat1NLayer";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlPlnrMat1NLayer::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrMat1NLayer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrMat1NLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMat1NLayer::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlPlnrMat1NLayer::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOREFWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMat1NLayer::Tag
 ******************************************************************************/

PnlPlnrMat1NLayer::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoRef
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoRef = TcoRef;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOREF};
};

bool PnlPlnrMat1NLayer::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrMat1NLayer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRef", TcoRef)) add(TCOREF);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrMat1NLayer::DpchAppData
 ******************************************************************************/

PnlPlnrMat1NLayer::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryPlnrMat1NLayer::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMAT1NLAYERDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrMat1NLayer::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrMat1NLayerData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMat1NLayer::DpchAppDo
 ******************************************************************************/

PnlPlnrMat1NLayer::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMAT1NLAYERDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrMat1NLayer::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrMat1NLayerDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMat1NLayer::DpchEngData
 ******************************************************************************/

PnlPlnrMat1NLayer::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRMAT1NLAYERDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

void PnlPlnrMat1NLayer::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrMat1NLayerData");
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
		statappqry = QryPlnrMat1NLayer::StatApp();
		statshrqry = QryPlnrMat1NLayer::StatShr();
		stgiacqry = QryPlnrMat1NLayer::StgIac();
	};
};

