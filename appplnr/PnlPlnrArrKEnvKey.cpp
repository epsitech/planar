/**
  * \file PnlPlnrArrKEnvKey.cpp
  * app access code for job PnlPlnrArrKEnvKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrArrKEnvKey.h"

/******************************************************************************
 class PnlPlnrArrKEnvKey::VecVDo
 ******************************************************************************/

uint PnlPlnrArrKEnvKey::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butupclick") == 0) return BUTUPCLICK;
	else if (s.compare("butdownclick") == 0) return BUTDOWNCLICK;
	else if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butduplicateclick") == 0) return BUTDUPLICATECLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrArrKEnvKey::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	else if (ix == BUTDOWNCLICK) return("ButDownClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::ContInf
 ******************************************************************************/

PnlPlnrArrKEnvKey::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlPlnrArrKEnvKey::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrArrKEnvKey";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrArrKEnvKey::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrArrKEnvKey::ContInf::diff(
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
 class PnlPlnrArrKEnvKey::StatApp
 ******************************************************************************/

PnlPlnrArrKEnvKey::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrArrKEnvKey::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrArrKEnvKey";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrArrKEnvKey::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrArrKEnvKey::StatApp::diff(
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
 class PnlPlnrArrKEnvKey::StatShr
 ******************************************************************************/

PnlPlnrArrKEnvKey::StatShr::StatShr(
			const bool ButUpActive
			, const bool ButDownActive
			, const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButUpActive = ButUpActive;
	this->ButDownActive = ButDownActive;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

bool PnlPlnrArrKEnvKey::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrArrKEnvKey";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpActive", ButUpActive)) add(BUTUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownActive", ButDownActive)) add(BUTDOWNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrArrKEnvKey::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrArrKEnvKey::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::StgIac
 ******************************************************************************/

PnlPlnrArrKEnvKey::StgIac::StgIac(
			const uint TcoFixWidth
			, const uint TcoSrfWidth
			, const uint TcoAvlWidth
			, const uint TcoImpWidth
			, const uint TcoTitWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoFixWidth = TcoFixWidth;
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoAvlWidth = TcoAvlWidth;
	this->TcoImpWidth = TcoImpWidth;
	this->TcoTitWidth = TcoTitWidth;
	this->TcoCmtWidth = TcoCmtWidth;

	mask = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
};

bool PnlPlnrArrKEnvKey::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrArrKEnvKey";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFixWidth", TcoFixWidth)) add(TCOFIXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAvlWidth", TcoAvlWidth)) add(TCOAVLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoImpWidth", TcoImpWidth)) add(TCOIMPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlPlnrArrKEnvKey::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrArrKEnvKey";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrArrKEnvKey";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFixWidth", TcoFixWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAvlWidth", TcoAvlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoImpWidth", TcoImpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrKEnvKey::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFixWidth == comp->TcoFixWidth) insert(items, TCOFIXWIDTH);
	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoAvlWidth == comp->TcoAvlWidth) insert(items, TCOAVLWIDTH);
	if (TcoImpWidth == comp->TcoImpWidth) insert(items, TCOIMPWIDTH);
	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlPlnrArrKEnvKey::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::Tag
 ******************************************************************************/

PnlPlnrArrKEnvKey::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoFix
			, const string& TcoSrf
			, const string& TcoAvl
			, const string& TcoImp
			, const string& TcoTit
			, const string& TcoCmt
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoFix = TcoFix;
	this->TcoSrf = TcoSrf;
	this->TcoAvl = TcoAvl;
	this->TcoImp = TcoImp;
	this->TcoTit = TcoTit;
	this->TcoCmt = TcoCmt;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOFIX, TCOSRF, TCOAVL, TCOIMP, TCOTIT, TCOCMT};
};

bool PnlPlnrArrKEnvKey::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrArrKEnvKey";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoFix", TcoFix)) add(TCOFIX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSrf", TcoSrf)) add(TCOSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoAvl", TcoAvl)) add(TCOAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoImp", TcoImp)) add(TCOIMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTit", TcoTit)) add(TCOTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCmt", TcoCmt)) add(TCOCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::DpchAppData
 ******************************************************************************/

PnlPlnrArrKEnvKey::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryPlnrArrKEnvKey::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRKENVKEYDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrArrKEnvKey::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrArrKEnvKeyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::DpchAppDo
 ******************************************************************************/

PnlPlnrArrKEnvKey::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRKENVKEYDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrArrKEnvKey::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrArrKEnvKeyDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrKEnvKey::DpchEngData
 ******************************************************************************/

PnlPlnrArrKEnvKey::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARRKENVKEYDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

void PnlPlnrArrKEnvKey::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrArrKEnvKeyData");
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
		statappqry = QryPlnrArrKEnvKey::StatApp();
		statshrqry = QryPlnrArrKEnvKey::StatShr();
		stgiacqry = QryPlnrArrKEnvKey::StgIac();
	};
};

