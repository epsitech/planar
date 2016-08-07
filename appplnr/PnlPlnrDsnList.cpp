/**
  * \file PnlPlnrDsnList.cpp
  * app access code for job PnlPlnrDsnList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnList.h"

/******************************************************************************
 class PnlPlnrDsnList::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnList::VecVDo::getIx(
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

string PnlPlnrDsnList::VecVDo::getSref(
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
 class PnlPlnrDsnList::ContIac
 ******************************************************************************/

PnlPlnrDsnList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrDsnList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDsnList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrDsnList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDsnList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDsnList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrDsnList::ContIac::diff(
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
 class PnlPlnrDsnList::ContInf
 ******************************************************************************/

PnlPlnrDsnList::ContInf::ContInf(
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

bool PnlPlnrDsnList::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDsnList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPre", TxtPre)) add(TXTPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButFilterOn", ButFilterOn)) add(BUTFILTERON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlPlnrDsnList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor.compare(comp->TxtFor) == 0) insert(items, TXTFOR);
	if (TxtPre.compare(comp->TxtPre) == 0) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrDsnList::ContInf::diff(
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
 class PnlPlnrDsnList::StatShr
 ******************************************************************************/

PnlPlnrDsnList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

bool PnlPlnrDsnList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDsnList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDsnList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrDsnList::StatShr::diff(
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
 class PnlPlnrDsnList::StgIac
 ******************************************************************************/

PnlPlnrDsnList::StgIac::StgIac(
			const uint TcoTitWidth
			, const uint TcoTypWidth
			, const uint TcoDimWidth
			, const uint TcoRetWidth
			, const uint TcoReuWidth
			, const uint TcoPrjWidth
			, const uint TcoMtyWidth
			, const uint TcoModWidth
			, const uint TcoDrvWidth
			, const uint TcoMajWidth
			, const uint TcoSubWidth
		) : Block() {
	this->TcoTitWidth = TcoTitWidth;
	this->TcoTypWidth = TcoTypWidth;
	this->TcoDimWidth = TcoDimWidth;
	this->TcoRetWidth = TcoRetWidth;
	this->TcoReuWidth = TcoReuWidth;
	this->TcoPrjWidth = TcoPrjWidth;
	this->TcoMtyWidth = TcoMtyWidth;
	this->TcoModWidth = TcoModWidth;
	this->TcoDrvWidth = TcoDrvWidth;
	this->TcoMajWidth = TcoMajWidth;
	this->TcoSubWidth = TcoSubWidth;

	mask = {TCOTITWIDTH, TCOTYPWIDTH, TCODIMWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOPRJWIDTH, TCOMTYWIDTH, TCOMODWIDTH, TCODRVWIDTH, TCOMAJWIDTH, TCOSUBWIDTH};
};

bool PnlPlnrDsnList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrDsnList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTypWidth", TcoTypWidth)) add(TCOTYPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDimWidth", TcoDimWidth)) add(TCODIMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRetWidth", TcoRetWidth)) add(TCORETWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoReuWidth", TcoReuWidth)) add(TCOREUWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrjWidth", TcoPrjWidth)) add(TCOPRJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMtyWidth", TcoMtyWidth)) add(TCOMTYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoModWidth", TcoModWidth)) add(TCOMODWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDrvWidth", TcoDrvWidth)) add(TCODRVWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMajWidth", TcoMajWidth)) add(TCOMAJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSubWidth", TcoSubWidth)) add(TCOSUBWIDTH);
	};

	return basefound;
};

void PnlPlnrDsnList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrDsnList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrDsnList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDimWidth", TcoDimWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRetWidth", TcoRetWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoReuWidth", TcoReuWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrjWidth", TcoPrjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMtyWidth", TcoMtyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoModWidth", TcoModWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDrvWidth", TcoDrvWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMajWidth", TcoMajWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSubWidth", TcoSubWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoTypWidth == comp->TcoTypWidth) insert(items, TCOTYPWIDTH);
	if (TcoDimWidth == comp->TcoDimWidth) insert(items, TCODIMWIDTH);
	if (TcoRetWidth == comp->TcoRetWidth) insert(items, TCORETWIDTH);
	if (TcoReuWidth == comp->TcoReuWidth) insert(items, TCOREUWIDTH);
	if (TcoPrjWidth == comp->TcoPrjWidth) insert(items, TCOPRJWIDTH);
	if (TcoMtyWidth == comp->TcoMtyWidth) insert(items, TCOMTYWIDTH);
	if (TcoModWidth == comp->TcoModWidth) insert(items, TCOMODWIDTH);
	if (TcoDrvWidth == comp->TcoDrvWidth) insert(items, TCODRVWIDTH);
	if (TcoMajWidth == comp->TcoMajWidth) insert(items, TCOMAJWIDTH);
	if (TcoSubWidth == comp->TcoSubWidth) insert(items, TCOSUBWIDTH);

	return(items);
};

set<uint> PnlPlnrDsnList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOTITWIDTH, TCOTYPWIDTH, TCODIMWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOPRJWIDTH, TCOMTYWIDTH, TCOMODWIDTH, TCODRVWIDTH, TCOMAJWIDTH, TCOSUBWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnList::Tag
 ******************************************************************************/

PnlPlnrDsnList::Tag::Tag(
			const string& Cpt
			, const string& TxtFor
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoTit
			, const string& TcoTyp
			, const string& TcoDim
			, const string& TcoRet
			, const string& TcoReu
			, const string& TcoPrj
			, const string& TcoMty
			, const string& TcoMod
			, const string& TcoDrv
			, const string& TcoMaj
			, const string& TcoSub
		) : Block() {
	this->Cpt = Cpt;
	this->TxtFor = TxtFor;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoTit = TcoTit;
	this->TcoTyp = TcoTyp;
	this->TcoDim = TcoDim;
	this->TcoRet = TcoRet;
	this->TcoReu = TcoReu;
	this->TcoPrj = TcoPrj;
	this->TcoMty = TcoMty;
	this->TcoMod = TcoMod;
	this->TcoDrv = TcoDrv;
	this->TcoMaj = TcoMaj;
	this->TcoSub = TcoSub;

	mask = {CPT, TXTFOR, TRS, TXTSHOWING1, TXTSHOWING2, TCOTIT, TCOTYP, TCODIM, TCORET, TCOREU, TCOPRJ, TCOMTY, TCOMOD, TCODRV, TCOMAJ, TCOSUB};
};

bool PnlPlnrDsnList::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtFor", TxtFor)) add(TXTFOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTit", TcoTit)) add(TCOTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTyp", TcoTyp)) add(TCOTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDim", TcoDim)) add(TCODIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRet", TcoRet)) add(TCORET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoReu", TcoReu)) add(TCOREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoPrj", TcoPrj)) add(TCOPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMty", TcoMty)) add(TCOMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMod", TcoMod)) add(TCOMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDrv", TcoDrv)) add(TCODRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMaj", TcoMaj)) add(TCOMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSub", TcoSub)) add(TCOSUB);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnList::DpchAppData
 ******************************************************************************/

PnlPlnrDsnList::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, StgIac* stgiac
			, QryPlnrDsnList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNLISTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrDsnList::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnList::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnList::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNLISTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDsnList::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnListDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnList::DpchEngData
 ******************************************************************************/

PnlPlnrDsnList::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNLISTDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
	feedFTos.tag = "FeedFTos";
};

void PnlPlnrDsnList::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnListData");
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
		statappqry = QryPlnrDsnList::StatApp();
		statshrqry = QryPlnrDsnList::StatShr();
		stgiacqry = QryPlnrDsnList::StgIac();
	};
};

