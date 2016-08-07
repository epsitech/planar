/**
  * \file PnlPlnrAriList.cpp
  * app access code for job PnlPlnrAriList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrAriList.h"

/******************************************************************************
 class PnlPlnrAriList::VecVDo
 ******************************************************************************/

uint PnlPlnrAriList::VecVDo::getIx(
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

string PnlPlnrAriList::VecVDo::getSref(
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
 class PnlPlnrAriList::ContIac
 ******************************************************************************/

PnlPlnrAriList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrAriList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrAriList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrAriList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrAriList::ContIac::diff(
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
 class PnlPlnrAriList::ContInf
 ******************************************************************************/

PnlPlnrAriList::ContInf::ContInf(
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

bool PnlPlnrAriList::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrAriList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPre", TxtPre)) add(TXTPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButFilterOn", ButFilterOn)) add(BUTFILTERON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrAriList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor.compare(comp->TxtFor) == 0) insert(items, TXTFOR);
	if (TxtPre.compare(comp->TxtPre) == 0) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrAriList::ContInf::diff(
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
 class PnlPlnrAriList::StatShr
 ******************************************************************************/

PnlPlnrAriList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

bool PnlPlnrAriList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrAriList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrAriList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrAriList::StatShr::diff(
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
 class PnlPlnrAriList::StgIac
 ******************************************************************************/

PnlPlnrAriList::StgIac::StgIac(
			const uint TcoIWidth
			, const uint TcoJWidth
			, const uint TcoKWidth
			, const uint TcoLWidth
			, const uint TcoMWidth
			, const uint TcoNWidth
			, const uint TcoArrWidth
			, const uint TcoDsnWidth
			, const uint TcoDxWidth
			, const uint TcoDyWidth
		) : Block() {
	this->TcoIWidth = TcoIWidth;
	this->TcoJWidth = TcoJWidth;
	this->TcoKWidth = TcoKWidth;
	this->TcoLWidth = TcoLWidth;
	this->TcoMWidth = TcoMWidth;
	this->TcoNWidth = TcoNWidth;
	this->TcoArrWidth = TcoArrWidth;
	this->TcoDsnWidth = TcoDsnWidth;
	this->TcoDxWidth = TcoDxWidth;
	this->TcoDyWidth = TcoDyWidth;

	mask = {TCOIWIDTH, TCOJWIDTH, TCOKWIDTH, TCOLWIDTH, TCOMWIDTH, TCONWIDTH, TCOARRWIDTH, TCODSNWIDTH, TCODXWIDTH, TCODYWIDTH};
};

bool PnlPlnrAriList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrAriList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIWidth", TcoIWidth)) add(TCOIWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoJWidth", TcoJWidth)) add(TCOJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoKWidth", TcoKWidth)) add(TCOKWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLWidth", TcoLWidth)) add(TCOLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMWidth", TcoMWidth)) add(TCOMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoNWidth", TcoNWidth)) add(TCONWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoArrWidth", TcoArrWidth)) add(TCOARRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDsnWidth", TcoDsnWidth)) add(TCODSNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDxWidth", TcoDxWidth)) add(TCODXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDyWidth", TcoDyWidth)) add(TCODYWIDTH);
	};

	return basefound;
};

void PnlPlnrAriList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoIWidth", TcoIWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoJWidth", TcoJWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoKWidth", TcoKWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLWidth", TcoLWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMWidth", TcoMWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoNWidth", TcoNWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoArrWidth", TcoArrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDsnWidth", TcoDsnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDxWidth", TcoDxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDyWidth", TcoDyWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoIWidth == comp->TcoIWidth) insert(items, TCOIWIDTH);
	if (TcoJWidth == comp->TcoJWidth) insert(items, TCOJWIDTH);
	if (TcoKWidth == comp->TcoKWidth) insert(items, TCOKWIDTH);
	if (TcoLWidth == comp->TcoLWidth) insert(items, TCOLWIDTH);
	if (TcoMWidth == comp->TcoMWidth) insert(items, TCOMWIDTH);
	if (TcoNWidth == comp->TcoNWidth) insert(items, TCONWIDTH);
	if (TcoArrWidth == comp->TcoArrWidth) insert(items, TCOARRWIDTH);
	if (TcoDsnWidth == comp->TcoDsnWidth) insert(items, TCODSNWIDTH);
	if (TcoDxWidth == comp->TcoDxWidth) insert(items, TCODXWIDTH);
	if (TcoDyWidth == comp->TcoDyWidth) insert(items, TCODYWIDTH);

	return(items);
};

set<uint> PnlPlnrAriList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOIWIDTH, TCOJWIDTH, TCOKWIDTH, TCOLWIDTH, TCOMWIDTH, TCONWIDTH, TCOARRWIDTH, TCODSNWIDTH, TCODXWIDTH, TCODYWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriList::Tag
 ******************************************************************************/

PnlPlnrAriList::Tag::Tag(
			const string& Cpt
			, const string& TxtFor
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoI
			, const string& TcoJ
			, const string& TcoK
			, const string& TcoL
			, const string& TcoM
			, const string& TcoN
			, const string& TcoArr
			, const string& TcoDsn
			, const string& TcoDx
			, const string& TcoDy
		) : Block() {
	this->Cpt = Cpt;
	this->TxtFor = TxtFor;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoI = TcoI;
	this->TcoJ = TcoJ;
	this->TcoK = TcoK;
	this->TcoL = TcoL;
	this->TcoM = TcoM;
	this->TcoN = TcoN;
	this->TcoArr = TcoArr;
	this->TcoDsn = TcoDsn;
	this->TcoDx = TcoDx;
	this->TcoDy = TcoDy;

	mask = {CPT, TXTFOR, TRS, TXTSHOWING1, TXTSHOWING2, TCOI, TCOJ, TCOK, TCOL, TCOM, TCON, TCOARR, TCODSN, TCODX, TCODY};
};

bool PnlPlnrAriList::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrAriList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoI", TcoI)) add(TCOI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoJ", TcoJ)) add(TCOJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoK", TcoK)) add(TCOK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoL", TcoL)) add(TCOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoM", TcoM)) add(TCOM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoN", TcoN)) add(TCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoArr", TcoArr)) add(TCOARR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDsn", TcoDsn)) add(TCODSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDx", TcoDx)) add(TCODX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDy", TcoDy)) add(TCODY);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrAriList::DpchAppData
 ******************************************************************************/

PnlPlnrAriList::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, StgIac* stgiac
			, QryPlnrAriList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARILISTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrAriList::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrAriListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriList::DpchAppDo
 ******************************************************************************/

PnlPlnrAriList::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARILISTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrAriList::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrAriListDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriList::DpchEngData
 ******************************************************************************/

PnlPlnrAriList::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARILISTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
	feedFTos.tag = "FeedFTos";
};

void PnlPlnrAriList::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrAriListData");
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
		statappqry = QryPlnrAriList::StatApp();
		statshrqry = QryPlnrAriList::StatShr();
		stgiacqry = QryPlnrAriList::StgIac();
	};
};

