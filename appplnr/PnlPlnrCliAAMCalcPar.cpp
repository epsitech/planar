/**
  * \file PnlPlnrCliAAMCalcPar.cpp
  * app access code for job PnlPlnrCliAAMCalcPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrCliAAMCalcPar.h"

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::VecVDo
 ******************************************************************************/

uint PnlPlnrCliAAMCalcPar::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butduplicateclick") == 0) return BUTDUPLICATECLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrCliAAMCalcPar::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::ContInf
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlPlnrCliAAMCalcPar::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrCliAAMCalcPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrCliAAMCalcPar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrCliAAMCalcPar::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrCliAAMCalcPar::ContInf::diff(
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
 class PnlPlnrCliAAMCalcPar::StatApp
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrCliAAMCalcPar::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrCliAAMCalcPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrCliAAMCalcPar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrCliAAMCalcPar::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrCliAAMCalcPar::StatApp::diff(
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
 class PnlPlnrCliAAMCalcPar::StatShr
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::StatShr::StatShr(
			const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

bool PnlPlnrCliAAMCalcPar::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrCliAAMCalcPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrCliAAMCalcPar";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrCliAAMCalcPar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrCliAAMCalcPar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::StgIac
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::StgIac::StgIac(
			const uint TcoCatWidth
			, const uint TcoPrpWidth
			, const uint TcoValWidth
		) : Block() {
	this->TcoCatWidth = TcoCatWidth;
	this->TcoPrpWidth = TcoPrpWidth;
	this->TcoValWidth = TcoValWidth;

	mask = {TCOCATWIDTH, TCOPRPWIDTH, TCOVALWIDTH};
};

bool PnlPlnrCliAAMCalcPar::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrCliAAMCalcPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrCliAAMCalcPar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCatWidth", TcoCatWidth)) add(TCOCATWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrpWidth", TcoPrpWidth)) add(TCOPRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoValWidth", TcoValWidth)) add(TCOVALWIDTH);
	};

	return basefound;
};

void PnlPlnrCliAAMCalcPar::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrCliAAMCalcPar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrCliAAMCalcPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoCatWidth", TcoCatWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrpWidth", TcoPrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoValWidth", TcoValWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCliAAMCalcPar::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoCatWidth == comp->TcoCatWidth) insert(items, TCOCATWIDTH);
	if (TcoPrpWidth == comp->TcoPrpWidth) insert(items, TCOPRPWIDTH);
	if (TcoValWidth == comp->TcoValWidth) insert(items, TCOVALWIDTH);

	return(items);
};

set<uint> PnlPlnrCliAAMCalcPar::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOCATWIDTH, TCOPRPWIDTH, TCOVALWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::Tag
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoCat
			, const string& TcoPrp
			, const string& TcoVal
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoCat = TcoCat;
	this->TcoPrp = TcoPrp;
	this->TcoVal = TcoVal;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOCAT, TCOPRP, TCOVAL};
};

bool PnlPlnrCliAAMCalcPar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrCliAAMCalcPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrCliAAMCalcPar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCat", TcoCat)) add(TCOCAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoPrp", TcoPrp)) add(TCOPRP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoVal", TcoVal)) add(TCOVAL);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::DpchAppData
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryPlnrCliAAMCalcPar::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrCliAAMCalcPar::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrCliAAMCalcParData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::DpchAppDo
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrCliAAMCalcPar::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrCliAAMCalcParDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCliAAMCalcPar::DpchEngData
 ******************************************************************************/

PnlPlnrCliAAMCalcPar::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLIAAMCALCPARDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

void PnlPlnrCliAAMCalcPar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrCliAAMCalcParData");
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
		statappqry = QryPlnrCliAAMCalcPar::StatApp();
		statshrqry = QryPlnrCliAAMCalcPar::StatShr();
		stgiacqry = QryPlnrCliAAMCalcPar::StgIac();
	};
};

