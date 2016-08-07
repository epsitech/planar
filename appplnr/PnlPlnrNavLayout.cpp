/**
  * \file PnlPlnrNavLayout.cpp
  * app access code for job PnlPlnrNavLayout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrNavLayout.h"

/******************************************************************************
 class PnlPlnrNavLayout::VecVDo
 ******************************************************************************/

uint PnlPlnrNavLayout::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("buttpoviewclick") == 0) return BUTTPOVIEWCLICK;
	else if (s.compare("buttponewcrdclick") == 0) return BUTTPONEWCRDCLICK;
	else if (s.compare("butarrviewclick") == 0) return BUTARRVIEWCLICK;
	else if (s.compare("butariviewclick") == 0) return BUTARIVIEWCLICK;
	else if (s.compare("butrtcviewclick") == 0) return BUTRTCVIEWCLICK;

	return(0);
};

string PnlPlnrNavLayout::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTTPOVIEWCLICK) return("ButTpoViewClick");
	else if (ix == BUTTPONEWCRDCLICK) return("ButTpoNewcrdClick");
	else if (ix == BUTARRVIEWCLICK) return("ButArrViewClick");
	else if (ix == BUTARIVIEWCLICK) return("ButAriViewClick");
	else if (ix == BUTRTCVIEWCLICK) return("ButRtcViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavLayout::ContIac
 ******************************************************************************/

PnlPlnrNavLayout::ContIac::ContIac(
			const uint numFLstTpo
			, const uint numFLstArr
			, const uint numFLstAri
			, const uint numFLstRtc
		) : Block() {
	this->numFLstTpo = numFLstTpo;
	this->numFLstArr = numFLstArr;
	this->numFLstAri = numFLstAri;
	this->numFLstRtc = numFLstRtc;

	mask = {NUMFLSTTPO, NUMFLSTARR, NUMFLSTARI, NUMFLSTRTC};
};

bool PnlPlnrNavLayout::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavLayout");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavLayout";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTpo", numFLstTpo)) add(NUMFLSTTPO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstArr", numFLstArr)) add(NUMFLSTARR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstAri", numFLstAri)) add(NUMFLSTARI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtc", numFLstRtc)) add(NUMFLSTRTC);
	};

	return basefound;
};

void PnlPlnrNavLayout::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavLayout";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavLayout";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstTpo", numFLstTpo);
		writeUintAttr(wr, itemtag, "sref", "numFLstArr", numFLstArr);
		writeUintAttr(wr, itemtag, "sref", "numFLstAri", numFLstAri);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtc", numFLstRtc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavLayout::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstTpo == comp->numFLstTpo) insert(items, NUMFLSTTPO);
	if (numFLstArr == comp->numFLstArr) insert(items, NUMFLSTARR);
	if (numFLstAri == comp->numFLstAri) insert(items, NUMFLSTARI);
	if (numFLstRtc == comp->numFLstRtc) insert(items, NUMFLSTRTC);

	return(items);
};

set<uint> PnlPlnrNavLayout::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTTPO, NUMFLSTARR, NUMFLSTARI, NUMFLSTRTC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavLayout::StatApp
 ******************************************************************************/

PnlPlnrNavLayout::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool LstTpoAlt
			, const bool LstArrAlt
			, const bool LstAriAlt
			, const bool LstRtcAlt
			, const uint LstTpoNumFirstdisp
			, const uint LstArrNumFirstdisp
			, const uint LstAriNumFirstdisp
			, const uint LstRtcNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->LstTpoAlt = LstTpoAlt;
	this->LstArrAlt = LstArrAlt;
	this->LstAriAlt = LstAriAlt;
	this->LstRtcAlt = LstRtcAlt;
	this->LstTpoNumFirstdisp = LstTpoNumFirstdisp;
	this->LstArrNumFirstdisp = LstArrNumFirstdisp;
	this->LstAriNumFirstdisp = LstAriNumFirstdisp;
	this->LstRtcNumFirstdisp = LstRtcNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, LSTTPOALT, LSTARRALT, LSTARIALT, LSTRTCALT, LSTTPONUMFIRSTDISP, LSTARRNUMFIRSTDISP, LSTARINUMFIRSTDISP, LSTRTCNUMFIRSTDISP};
};

bool PnlPlnrNavLayout::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrNavLayout");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrNavLayout";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTpoAlt", LstTpoAlt)) add(LSTTPOALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArrAlt", LstArrAlt)) add(LSTARRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAriAlt", LstAriAlt)) add(LSTARIALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtcAlt", LstRtcAlt)) add(LSTRTCALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTpoNumFirstdisp", LstTpoNumFirstdisp)) add(LSTTPONUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArrNumFirstdisp", LstArrNumFirstdisp)) add(LSTARRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAriNumFirstdisp", LstAriNumFirstdisp)) add(LSTARINUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtcNumFirstdisp", LstRtcNumFirstdisp)) add(LSTRTCNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrNavLayout::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (LstTpoAlt == comp->LstTpoAlt) insert(items, LSTTPOALT);
	if (LstArrAlt == comp->LstArrAlt) insert(items, LSTARRALT);
	if (LstAriAlt == comp->LstAriAlt) insert(items, LSTARIALT);
	if (LstRtcAlt == comp->LstRtcAlt) insert(items, LSTRTCALT);
	if (LstTpoNumFirstdisp == comp->LstTpoNumFirstdisp) insert(items, LSTTPONUMFIRSTDISP);
	if (LstArrNumFirstdisp == comp->LstArrNumFirstdisp) insert(items, LSTARRNUMFIRSTDISP);
	if (LstAriNumFirstdisp == comp->LstAriNumFirstdisp) insert(items, LSTARINUMFIRSTDISP);
	if (LstRtcNumFirstdisp == comp->LstRtcNumFirstdisp) insert(items, LSTRTCNUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrNavLayout::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, LSTTPOALT, LSTARRALT, LSTARIALT, LSTRTCALT, LSTTPONUMFIRSTDISP, LSTARRNUMFIRSTDISP, LSTARINUMFIRSTDISP, LSTRTCNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavLayout::StatShr
 ******************************************************************************/

PnlPlnrNavLayout::StatShr::StatShr(
			const bool LstTpoAvail
			, const bool ButTpoViewActive
			, const bool LstArrAvail
			, const bool ButArrViewActive
			, const bool LstAriAvail
			, const bool ButAriViewActive
			, const bool LstRtcAvail
			, const bool ButRtcViewActive
		) : Block() {
	this->LstTpoAvail = LstTpoAvail;
	this->ButTpoViewActive = ButTpoViewActive;
	this->LstArrAvail = LstArrAvail;
	this->ButArrViewActive = ButArrViewActive;
	this->LstAriAvail = LstAriAvail;
	this->ButAriViewActive = ButAriViewActive;
	this->LstRtcAvail = LstRtcAvail;
	this->ButRtcViewActive = ButRtcViewActive;

	mask = {LSTTPOAVAIL, BUTTPOVIEWACTIVE, LSTARRAVAIL, BUTARRVIEWACTIVE, LSTARIAVAIL, BUTARIVIEWACTIVE, LSTRTCAVAIL, BUTRTCVIEWACTIVE};
};

bool PnlPlnrNavLayout::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNavLayout");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNavLayout";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTpoAvail", LstTpoAvail)) add(LSTTPOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTpoViewActive", ButTpoViewActive)) add(BUTTPOVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArrAvail", LstArrAvail)) add(LSTARRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButArrViewActive", ButArrViewActive)) add(BUTARRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAriAvail", LstAriAvail)) add(LSTARIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAriViewActive", ButAriViewActive)) add(BUTARIVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtcAvail", LstRtcAvail)) add(LSTRTCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRtcViewActive", ButRtcViewActive)) add(BUTRTCVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrNavLayout::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstTpoAvail == comp->LstTpoAvail) insert(items, LSTTPOAVAIL);
	if (ButTpoViewActive == comp->ButTpoViewActive) insert(items, BUTTPOVIEWACTIVE);
	if (LstArrAvail == comp->LstArrAvail) insert(items, LSTARRAVAIL);
	if (ButArrViewActive == comp->ButArrViewActive) insert(items, BUTARRVIEWACTIVE);
	if (LstAriAvail == comp->LstAriAvail) insert(items, LSTARIAVAIL);
	if (ButAriViewActive == comp->ButAriViewActive) insert(items, BUTARIVIEWACTIVE);
	if (LstRtcAvail == comp->LstRtcAvail) insert(items, LSTRTCAVAIL);
	if (ButRtcViewActive == comp->ButRtcViewActive) insert(items, BUTRTCVIEWACTIVE);

	return(items);
};

set<uint> PnlPlnrNavLayout::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTTPOAVAIL, BUTTPOVIEWACTIVE, LSTARRAVAIL, BUTARRVIEWACTIVE, LSTARIAVAIL, BUTARIVIEWACTIVE, LSTRTCAVAIL, BUTRTCVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavLayout::Tag
 ******************************************************************************/

PnlPlnrNavLayout::Tag::Tag(
			const string& Cpt
			, const string& CptTpo
			, const string& CptArr
			, const string& CptAri
			, const string& CptRtc
		) : Block() {
	this->Cpt = Cpt;
	this->CptTpo = CptTpo;
	this->CptArr = CptArr;
	this->CptAri = CptAri;
	this->CptRtc = CptRtc;

	mask = {CPT, CPTTPO, CPTARR, CPTARI, CPTRTC};
};

bool PnlPlnrNavLayout::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNavLayout");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNavLayout";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTpo", CptTpo)) add(CPTTPO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptArr", CptArr)) add(CPTARR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAri", CptAri)) add(CPTARI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRtc", CptRtc)) add(CPTRTC);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrNavLayout::DpchAppData
 ******************************************************************************/

PnlPlnrNavLayout::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrNavLayout::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavLayoutData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavLayout::DpchAppDo
 ******************************************************************************/

PnlPlnrNavLayout::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrNavLayout::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavLayoutDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavLayout::DpchEngData
 ******************************************************************************/

PnlPlnrNavLayout::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVLAYOUTDATA) {
	feedFLstAri.tag = "FeedFLstAri";
	feedFLstArr.tag = "FeedFLstArr";
	feedFLstRtc.tag = "FeedFLstRtc";
	feedFLstTpo.tag = "FeedFLstTpo";
};

void PnlPlnrNavLayout::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavLayoutData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstAri.readXML(docctx, basexpath, true)) add(FEEDFLSTARI);
		if (feedFLstArr.readXML(docctx, basexpath, true)) add(FEEDFLSTARR);
		if (feedFLstRtc.readXML(docctx, basexpath, true)) add(FEEDFLSTRTC);
		if (feedFLstTpo.readXML(docctx, basexpath, true)) add(FEEDFLSTTPO);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstAri.clear();
		feedFLstArr.clear();
		feedFLstRtc.clear();
		feedFLstTpo.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

