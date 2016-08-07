/**
  * \file PnlPlnrDgdList.cpp
  * app access code for job PnlPlnrDgdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDgdList.h"

/******************************************************************************
 class PnlPlnrDgdList::VecVDo
 ******************************************************************************/

uint PnlPlnrDgdList::VecVDo::getIx(
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

string PnlPlnrDgdList::VecVDo::getSref(
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
 class PnlPlnrDgdList::ContIac
 ******************************************************************************/

PnlPlnrDgdList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrDgdList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDgdList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrDgdList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDgdList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDgdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrDgdList::ContIac::diff(
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
 class PnlPlnrDgdList::ContInf
 ******************************************************************************/

PnlPlnrDgdList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) : Block() {
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

bool PnlPlnrDgdList::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDgdList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPre", TxtPre)) add(TXTPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButFilterOn", ButFilterOn)) add(BUTFILTERON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrDgdList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor.compare(comp->TxtFor) == 0) insert(items, TXTFOR);
	if (TxtPre.compare(comp->TxtPre) == 0) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrDgdList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdList::StatShr
 ******************************************************************************/

PnlPlnrDgdList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

bool PnlPlnrDgdList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDgdList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDgdList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrDgdList::StatShr::diff(
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
 class PnlPlnrDgdList::StgIac
 ******************************************************************************/

PnlPlnrDgdList::StgIac::StgIac(
			const uint TcoSrfWidth
			, const uint TcoTypWidth
			, const uint TcoDsnWidth
		) : Block() {
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoTypWidth = TcoTypWidth;
	this->TcoDsnWidth = TcoDsnWidth;

	mask = {TCOSRFWIDTH, TCOTYPWIDTH, TCODSNWIDTH};
};

bool PnlPlnrDgdList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrDgdList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTypWidth", TcoTypWidth)) add(TCOTYPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDsnWidth", TcoDsnWidth)) add(TCODSNWIDTH);
	};

	return basefound;
};

void PnlPlnrDgdList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrDgdList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrDgdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDsnWidth", TcoDsnWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoTypWidth == comp->TcoTypWidth) insert(items, TCOTYPWIDTH);
	if (TcoDsnWidth == comp->TcoDsnWidth) insert(items, TCODSNWIDTH);

	return(items);
};

set<uint> PnlPlnrDgdList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSRFWIDTH, TCOTYPWIDTH, TCODSNWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdList::Tag
 ******************************************************************************/

PnlPlnrDgdList::Tag::Tag(
			const string& Cpt
			, const string& TxtFor
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoSrf
			, const string& TcoTyp
			, const string& TcoDsn
		) : Block() {
	this->Cpt = Cpt;
	this->TxtFor = TxtFor;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoSrf = TcoSrf;
	this->TcoTyp = TcoTyp;
	this->TcoDsn = TcoDsn;

	mask = {CPT, TXTFOR, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTYP, TCODSN};
};

bool PnlPlnrDgdList::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDgdList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSrf", TcoSrf)) add(TCOSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTyp", TcoTyp)) add(TCOTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDsn", TcoDsn)) add(TCODSN);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDgdList::DpchAppData
 ******************************************************************************/

PnlPlnrDgdList::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, StgIac* stgiac
			, QryPlnrDgdList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDLISTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrDgdList::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDgdListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdList::DpchAppDo
 ******************************************************************************/

PnlPlnrDgdList::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDLISTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDgdList::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDgdListDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdList::DpchEngData
 ******************************************************************************/

PnlPlnrDgdList::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDGDLISTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
	feedFTos.tag = "FeedFTos";
};

void PnlPlnrDgdList::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDgdListData");
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
		statappqry = QryPlnrDgdList::StatApp();
		statshrqry = QryPlnrDgdList::StatShr();
		stgiacqry = QryPlnrDgdList::StgIac();
	};
};

