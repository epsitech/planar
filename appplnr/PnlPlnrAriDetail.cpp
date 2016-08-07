/**
  * \file PnlPlnrAriDetail.cpp
  * app access code for job PnlPlnrAriDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrAriDetail.h"

/******************************************************************************
 class PnlPlnrAriDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrAriDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butarrviewclick") == 0) return BUTARRVIEWCLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrAriDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTARRVIEWCLICK) return("ButArrViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrAriDetail::ContIac
 ******************************************************************************/

PnlPlnrAriDetail::ContIac::ContIac(
			const string& TxfI
			, const string& TxfJ
			, const string& TxfK
			, const string& TxfL
			, const string& TxfM
			, const string& TxfN
			, const string& TxfDx
			, const string& TxfDy
		) : Block() {
	this->TxfI = TxfI;
	this->TxfJ = TxfJ;
	this->TxfK = TxfK;
	this->TxfL = TxfL;
	this->TxfM = TxfM;
	this->TxfN = TxfN;
	this->TxfDx = TxfDx;
	this->TxfDy = TxfDy;

	mask = {TXFI, TXFJ, TXFK, TXFL, TXFM, TXFN, TXFDX, TXFDY};
};

bool PnlPlnrAriDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrAriDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfI", TxfI)) add(TXFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfJ", TxfJ)) add(TXFJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfK", TxfK)) add(TXFK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfL", TxfL)) add(TXFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfM", TxfM)) add(TXFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDx", TxfDx)) add(TXFDX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDy", TxfDy)) add(TXFDY);
	};

	return basefound;
};

void PnlPlnrAriDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfI", TxfI);
		writeStringAttr(wr, itemtag, "sref", "TxfJ", TxfJ);
		writeStringAttr(wr, itemtag, "sref", "TxfK", TxfK);
		writeStringAttr(wr, itemtag, "sref", "TxfL", TxfL);
		writeStringAttr(wr, itemtag, "sref", "TxfM", TxfM);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
		writeStringAttr(wr, itemtag, "sref", "TxfDx", TxfDx);
		writeStringAttr(wr, itemtag, "sref", "TxfDy", TxfDy);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfI.compare(comp->TxfI) == 0) insert(items, TXFI);
	if (TxfJ.compare(comp->TxfJ) == 0) insert(items, TXFJ);
	if (TxfK.compare(comp->TxfK) == 0) insert(items, TXFK);
	if (TxfL.compare(comp->TxfL) == 0) insert(items, TXFL);
	if (TxfM.compare(comp->TxfM) == 0) insert(items, TXFM);
	if (TxfN.compare(comp->TxfN) == 0) insert(items, TXFN);
	if (TxfDx.compare(comp->TxfDx) == 0) insert(items, TXFDX);
	if (TxfDy.compare(comp->TxfDy) == 0) insert(items, TXFDY);

	return(items);
};

set<uint> PnlPlnrAriDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFI, TXFJ, TXFK, TXFL, TXFM, TXFN, TXFDX, TXFDY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::ContInf
 ******************************************************************************/

PnlPlnrAriDetail::ContInf::ContInf(
			const string& TxtArr
			, const string& TxtDsn
		) : Block() {
	this->TxtArr = TxtArr;
	this->TxtDsn = TxtDsn;

	mask = {TXTARR, TXTDSN};
};

bool PnlPlnrAriDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrAriDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtArr", TxtArr)) add(TXTARR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
	};

	return basefound;
};

set<uint> PnlPlnrAriDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtArr.compare(comp->TxtArr) == 0) insert(items, TXTARR);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);

	return(items);
};

set<uint> PnlPlnrAriDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTARR, TXTDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::StatApp
 ******************************************************************************/

PnlPlnrAriDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrAriDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrAriDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrAriDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrAriDetail::StatApp::diff(
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
 class PnlPlnrAriDetail::StatShr
 ******************************************************************************/

PnlPlnrAriDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButArrViewAvail
			, const bool ButDsnViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButArrViewAvail = ButArrViewAvail;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTARRVIEWAVAIL, BUTDSNVIEWAVAIL};
};

bool PnlPlnrAriDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrAriDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButArrViewAvail", ButArrViewAvail)) add(BUTARRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrAriDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButArrViewAvail == comp->ButArrViewAvail) insert(items, BUTARRVIEWAVAIL);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrAriDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTARRVIEWAVAIL, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::Tag
 ******************************************************************************/

PnlPlnrAriDetail::Tag::Tag(
			const string& Cpt
			, const string& CptI
			, const string& CptJ
			, const string& CptK
			, const string& CptL
			, const string& CptM
			, const string& CptN
			, const string& CptArr
			, const string& CptDsn
			, const string& CptDx
			, const string& CptDy
		) : Block() {
	this->Cpt = Cpt;
	this->CptI = CptI;
	this->CptJ = CptJ;
	this->CptK = CptK;
	this->CptL = CptL;
	this->CptM = CptM;
	this->CptN = CptN;
	this->CptArr = CptArr;
	this->CptDsn = CptDsn;
	this->CptDx = CptDx;
	this->CptDy = CptDy;

	mask = {CPT, CPTI, CPTJ, CPTK, CPTL, CPTM, CPTN, CPTARR, CPTDSN, CPTDX, CPTDY};
};

bool PnlPlnrAriDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrAriDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptI", CptI)) add(CPTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJ", CptJ)) add(CPTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptK", CptK)) add(CPTK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptL", CptL)) add(CPTL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptM", CptM)) add(CPTM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptN", CptN)) add(CPTN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptArr", CptArr)) add(CPTARR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDx", CptDx)) add(CPTDX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDy", CptDy)) add(CPTDY);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrAriDetail::DpchAppData
 ******************************************************************************/

PnlPlnrAriDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARIDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrAriDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrAriDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrAriDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARIDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrAriDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrAriDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriDetail::DpchEngData
 ******************************************************************************/

PnlPlnrAriDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARIDETAILDATA) {
};

void PnlPlnrAriDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrAriDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

