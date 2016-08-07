/**
  * \file PnlPlnrUsrList.cpp
  * app access code for job PnlPlnrUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrUsrList.h"

/******************************************************************************
 class PnlPlnrUsrList::VecVDo
 ******************************************************************************/

uint PnlPlnrUsrList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;
	else if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butfilterclick") == 0) return BUTFILTERCLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrUsrList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTFILTERCLICK) return("ButFilterClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrUsrList::ContIac
 ******************************************************************************/

PnlPlnrUsrList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrUsrList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrUsrList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrUsrList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrUsrList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrUsrList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrUsrList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrList::ContInf
 ******************************************************************************/

PnlPlnrUsrList::ContInf::ContInf(
			const bool ButFilterOn
			, const uint numFCsiQst
		) : Block() {
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {BUTFILTERON, NUMFCSIQST};
};

bool PnlPlnrUsrList::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrUsrList";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButFilterOn", ButFilterOn)) add(BUTFILTERON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrUsrList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrUsrList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTFILTERON, NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrList::StatShr
 ******************************************************************************/

PnlPlnrUsrList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

bool PnlPlnrUsrList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrUsrList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrUsrList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrUsrList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrList::StgIac
 ******************************************************************************/

PnlPlnrUsrList::StgIac::StgIac(
			const uint TcoPrsWidth
			, const uint TcoSrfWidth
			, const uint TcoUsgWidth
			, const uint TcoSteWidth
			, const uint TcoLclWidth
			, const uint TcoUlvWidth
		) : Block() {
	this->TcoPrsWidth = TcoPrsWidth;
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoUsgWidth = TcoUsgWidth;
	this->TcoSteWidth = TcoSteWidth;
	this->TcoLclWidth = TcoLclWidth;
	this->TcoUlvWidth = TcoUlvWidth;

	mask = {TCOPRSWIDTH, TCOSRFWIDTH, TCOUSGWIDTH, TCOSTEWIDTH, TCOLCLWIDTH, TCOULVWIDTH};
};

bool PnlPlnrUsrList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrUsrList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrsWidth", TcoPrsWidth)) add(TCOPRSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUsgWidth", TcoUsgWidth)) add(TCOUSGWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSteWidth", TcoSteWidth)) add(TCOSTEWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLclWidth", TcoLclWidth)) add(TCOLCLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUlvWidth", TcoUlvWidth)) add(TCOULVWIDTH);
	};

	return basefound;
};

void PnlPlnrUsrList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrUsrList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoPrsWidth", TcoPrsWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUsgWidth", TcoUsgWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSteWidth", TcoSteWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLclWidth", TcoLclWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrUsrList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoPrsWidth == comp->TcoPrsWidth) insert(items, TCOPRSWIDTH);
	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoUsgWidth == comp->TcoUsgWidth) insert(items, TCOUSGWIDTH);
	if (TcoSteWidth == comp->TcoSteWidth) insert(items, TCOSTEWIDTH);
	if (TcoLclWidth == comp->TcoLclWidth) insert(items, TCOLCLWIDTH);
	if (TcoUlvWidth == comp->TcoUlvWidth) insert(items, TCOULVWIDTH);

	return(items);
};

set<uint> PnlPlnrUsrList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOPRSWIDTH, TCOSRFWIDTH, TCOUSGWIDTH, TCOSTEWIDTH, TCOLCLWIDTH, TCOULVWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrUsrList::Tag
 ******************************************************************************/

PnlPlnrUsrList::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoPrs
			, const string& TcoSrf
			, const string& TcoUsg
			, const string& TcoSte
			, const string& TcoLcl
			, const string& TcoUlv
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoPrs = TcoPrs;
	this->TcoSrf = TcoSrf;
	this->TcoUsg = TcoUsg;
	this->TcoSte = TcoSte;
	this->TcoLcl = TcoLcl;
	this->TcoUlv = TcoUlv;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOPRS, TCOSRF, TCOUSG, TCOSTE, TCOLCL, TCOULV};
};

bool PnlPlnrUsrList::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrUsrList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoPrs", TcoPrs)) add(TCOPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSrf", TcoSrf)) add(TCOSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoUsg", TcoUsg)) add(TCOUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSte", TcoSte)) add(TCOSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoLcl", TcoLcl)) add(TCOLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoUlv", TcoUlv)) add(TCOULV);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrUsrList::DpchAppData
 ******************************************************************************/

PnlPlnrUsrList::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, StgIac* stgiac
			, QryPlnrUsrList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRUSRLISTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrUsrList::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrUsrListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrUsrList::DpchAppDo
 ******************************************************************************/

PnlPlnrUsrList::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRUSRLISTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrUsrList::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrUsrListDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrUsrList::DpchEngData
 ******************************************************************************/

PnlPlnrUsrList::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRUSRLISTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
	feedFTos.tag = "FeedFTos";
};

void PnlPlnrUsrList::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrUsrListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (feedFTos.readXML(docctx, basexpath, true)) add(FEEDFTOS);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFCsiQst.clear();
		feedFTos.clear();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryPlnrUsrList::StatApp();
		statshrqry = QryPlnrUsrList::StatShr();
		stgiacqry = QryPlnrUsrList::StgIac();
	};
};

