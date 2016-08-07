/**
  * \file PnlPlnrArrDetail.cpp
  * app access code for job PnlPlnrArrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrArrDetail.h"

/******************************************************************************
 class PnlPlnrArrDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrArrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("buttpoviewclick") == 0) return BUTTPOVIEWCLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrArrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTTPOVIEWCLICK) return("ButTpoViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrArrDetail::ContIac
 ******************************************************************************/

PnlPlnrArrDetail::ContIac::ContIac(
			const string& TxfI
			, const string& TxfJ
			, const string& TxfDi
			, const string& TxfDj
			, const string& TxfK
			, const string& TxfL
			, const string& TxfDk
			, const string& TxfDl
			, const string& TxfM
			, const string& TxfN
			, const string& TxfDm
			, const string& TxfDn
		) : Block() {
	this->TxfI = TxfI;
	this->TxfJ = TxfJ;
	this->TxfDi = TxfDi;
	this->TxfDj = TxfDj;
	this->TxfK = TxfK;
	this->TxfL = TxfL;
	this->TxfDk = TxfDk;
	this->TxfDl = TxfDl;
	this->TxfM = TxfM;
	this->TxfN = TxfN;
	this->TxfDm = TxfDm;
	this->TxfDn = TxfDn;

	mask = {TXFI, TXFJ, TXFDI, TXFDJ, TXFK, TXFL, TXFDK, TXFDL, TXFM, TXFN, TXFDM, TXFDN};
};

bool PnlPlnrArrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrArrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfI", TxfI)) add(TXFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfJ", TxfJ)) add(TXFJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDi", TxfDi)) add(TXFDI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDj", TxfDj)) add(TXFDJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfK", TxfK)) add(TXFK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfL", TxfL)) add(TXFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDk", TxfDk)) add(TXFDK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDl", TxfDl)) add(TXFDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfM", TxfM)) add(TXFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDm", TxfDm)) add(TXFDM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDn", TxfDn)) add(TXFDN);
	};

	return basefound;
};

void PnlPlnrArrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfI", TxfI);
		writeStringAttr(wr, itemtag, "sref", "TxfJ", TxfJ);
		writeStringAttr(wr, itemtag, "sref", "TxfDi", TxfDi);
		writeStringAttr(wr, itemtag, "sref", "TxfDj", TxfDj);
		writeStringAttr(wr, itemtag, "sref", "TxfK", TxfK);
		writeStringAttr(wr, itemtag, "sref", "TxfL", TxfL);
		writeStringAttr(wr, itemtag, "sref", "TxfDk", TxfDk);
		writeStringAttr(wr, itemtag, "sref", "TxfDl", TxfDl);
		writeStringAttr(wr, itemtag, "sref", "TxfM", TxfM);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
		writeStringAttr(wr, itemtag, "sref", "TxfDm", TxfDm);
		writeStringAttr(wr, itemtag, "sref", "TxfDn", TxfDn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfI.compare(comp->TxfI) == 0) insert(items, TXFI);
	if (TxfJ.compare(comp->TxfJ) == 0) insert(items, TXFJ);
	if (TxfDi.compare(comp->TxfDi) == 0) insert(items, TXFDI);
	if (TxfDj.compare(comp->TxfDj) == 0) insert(items, TXFDJ);
	if (TxfK.compare(comp->TxfK) == 0) insert(items, TXFK);
	if (TxfL.compare(comp->TxfL) == 0) insert(items, TXFL);
	if (TxfDk.compare(comp->TxfDk) == 0) insert(items, TXFDK);
	if (TxfDl.compare(comp->TxfDl) == 0) insert(items, TXFDL);
	if (TxfM.compare(comp->TxfM) == 0) insert(items, TXFM);
	if (TxfN.compare(comp->TxfN) == 0) insert(items, TXFN);
	if (TxfDm.compare(comp->TxfDm) == 0) insert(items, TXFDM);
	if (TxfDn.compare(comp->TxfDn) == 0) insert(items, TXFDN);

	return(items);
};

set<uint> PnlPlnrArrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFI, TXFJ, TXFDI, TXFDJ, TXFK, TXFL, TXFDK, TXFDL, TXFM, TXFN, TXFDM, TXFDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::ContInf
 ******************************************************************************/

PnlPlnrArrDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTpo
			, const string& TxtDsn
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtTpo = TxtTpo;
	this->TxtDsn = TxtDsn;

	mask = {TXTSRF, TXTTPO, TXTDSN};
};

bool PnlPlnrArrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrArrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTpo", TxtTpo)) add(TXTTPO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
	};

	return basefound;
};

set<uint> PnlPlnrArrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtTpo.compare(comp->TxtTpo) == 0) insert(items, TXTTPO);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);

	return(items);
};

set<uint> PnlPlnrArrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTPO, TXTDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::StatApp
 ******************************************************************************/

PnlPlnrArrDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;

	mask = {IXPLNRVEXPSTATE};
};

bool PnlPlnrArrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrArrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlPlnrArrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);

	return(items);
};

set<uint> PnlPlnrArrDetail::StatApp::diff(
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
 class PnlPlnrArrDetail::StatShr
 ******************************************************************************/

PnlPlnrArrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButTpoViewAvail
			, const bool ButDsnViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButTpoViewAvail = ButTpoViewAvail;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTTPOVIEWAVAIL, BUTDSNVIEWAVAIL};
};

bool PnlPlnrArrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrArrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTpoViewAvail", ButTpoViewAvail)) add(BUTTPOVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrArrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButTpoViewAvail == comp->ButTpoViewAvail) insert(items, BUTTPOVIEWAVAIL);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrArrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTTPOVIEWAVAIL, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::Tag
 ******************************************************************************/

PnlPlnrArrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTpo
			, const string& CptDsn
			, const string& CptI
			, const string& CptJ
			, const string& CptDi
			, const string& CptDj
			, const string& CptK
			, const string& CptL
			, const string& CptDk
			, const string& CptDl
			, const string& CptM
			, const string& CptN
			, const string& CptDm
			, const string& CptDn
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTpo = CptTpo;
	this->CptDsn = CptDsn;
	this->CptI = CptI;
	this->CptJ = CptJ;
	this->CptDi = CptDi;
	this->CptDj = CptDj;
	this->CptK = CptK;
	this->CptL = CptL;
	this->CptDk = CptDk;
	this->CptDl = CptDl;
	this->CptM = CptM;
	this->CptN = CptN;
	this->CptDm = CptDm;
	this->CptDn = CptDn;

	mask = {CPT, CPTSRF, CPTTPO, CPTDSN, CPTI, CPTJ, CPTDI, CPTDJ, CPTK, CPTL, CPTDK, CPTDL, CPTM, CPTN, CPTDM, CPTDN};
};

bool PnlPlnrArrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrArrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTpo", CptTpo)) add(CPTTPO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptI", CptI)) add(CPTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJ", CptJ)) add(CPTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDi", CptDi)) add(CPTDI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDj", CptDj)) add(CPTDJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptK", CptK)) add(CPTK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptL", CptL)) add(CPTL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDk", CptDk)) add(CPTDK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDl", CptDl)) add(CPTDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptM", CptM)) add(CPTM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptN", CptN)) add(CPTN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDm", CptDm)) add(CPTDM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDn", CptDn)) add(CPTDN);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrArrDetail::DpchAppData
 ******************************************************************************/

PnlPlnrArrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrArrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrArrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrArrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrArrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrArrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrDetail::DpchEngData
 ******************************************************************************/

PnlPlnrArrDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARRDETAILDATA) {
};

void PnlPlnrArrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrArrDetailData");
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

