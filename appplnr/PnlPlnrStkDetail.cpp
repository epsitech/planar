/**
  * \file PnlPlnrStkDetail.cpp
  * app access code for job PnlPlnrStkDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrStkDetail.h"

/******************************************************************************
 class PnlPlnrStkDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrStkDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;
	else if (s.compare("butlyrviewclick") == 0) return BUTLYRVIEWCLICK;

	return(0);
};

string PnlPlnrStkDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");
	else if (ix == BUTLYRVIEWCLICK) return("ButLyrViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrStkDetail::ContIac
 ******************************************************************************/

PnlPlnrStkDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupMty
			, const uint numFPupFal
			, const string& TxfFlr
			, const string& TxfZfl
			, const uint numFPupCal
			, const string& TxfCil
			, const string& TxfZci
			, const uint numFLstLyr
			, const string& TxfLyr
			, const string& TxfN
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFPupMty = numFPupMty;
	this->numFPupFal = numFPupFal;
	this->TxfFlr = TxfFlr;
	this->TxfZfl = TxfZfl;
	this->numFPupCal = numFPupCal;
	this->TxfCil = TxfCil;
	this->TxfZci = TxfZci;
	this->numFLstLyr = numFLstLyr;
	this->TxfLyr = TxfLyr;
	this->TxfN = TxfN;

	mask = {NUMFPUPTYP, NUMFPUPMTY, NUMFPUPFAL, TXFFLR, TXFZFL, NUMFPUPCAL, TXFCIL, TXFZCI, NUMFLSTLYR, TXFLYR, TXFN};
};

bool PnlPlnrStkDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrStkDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMty", numFPupMty)) add(NUMFPUPMTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFal", numFPupFal)) add(NUMFPUPFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFlr", TxfFlr)) add(TXFFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfZfl", TxfZfl)) add(TXFZFL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCal", numFPupCal)) add(NUMFPUPCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCil", TxfCil)) add(TXFCIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfZci", TxfZci)) add(TXFZCI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLyr", numFLstLyr)) add(NUMFLSTLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLyr", TxfLyr)) add(TXFLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
	};

	return basefound;
};

void PnlPlnrStkDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupMty", numFPupMty);
		writeUintAttr(wr, itemtag, "sref", "numFPupFal", numFPupFal);
		writeStringAttr(wr, itemtag, "sref", "TxfFlr", TxfFlr);
		writeStringAttr(wr, itemtag, "sref", "TxfZfl", TxfZfl);
		writeUintAttr(wr, itemtag, "sref", "numFPupCal", numFPupCal);
		writeStringAttr(wr, itemtag, "sref", "TxfCil", TxfCil);
		writeStringAttr(wr, itemtag, "sref", "TxfZci", TxfZci);
		writeUintAttr(wr, itemtag, "sref", "numFLstLyr", numFLstLyr);
		writeStringAttr(wr, itemtag, "sref", "TxfLyr", TxfLyr);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupMty == comp->numFPupMty) insert(items, NUMFPUPMTY);
	if (numFPupFal == comp->numFPupFal) insert(items, NUMFPUPFAL);
	if (TxfFlr.compare(comp->TxfFlr) == 0) insert(items, TXFFLR);
	if (TxfZfl.compare(comp->TxfZfl) == 0) insert(items, TXFZFL);
	if (numFPupCal == comp->numFPupCal) insert(items, NUMFPUPCAL);
	if (TxfCil.compare(comp->TxfCil) == 0) insert(items, TXFCIL);
	if (TxfZci.compare(comp->TxfZci) == 0) insert(items, TXFZCI);
	if (numFLstLyr == comp->numFLstLyr) insert(items, NUMFLSTLYR);
	if (TxfLyr.compare(comp->TxfLyr) == 0) insert(items, TXFLYR);
	if (TxfN.compare(comp->TxfN) == 0) insert(items, TXFN);

	return(items);
};

set<uint> PnlPlnrStkDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPMTY, NUMFPUPFAL, TXFFLR, TXFZFL, NUMFPUPCAL, TXFCIL, TXFZCI, NUMFLSTLYR, TXFLYR, TXFN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::ContInf
 ******************************************************************************/

PnlPlnrStkDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtFlr
			, const string& TxtCil
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtFlr = TxtFlr;
	this->TxtCil = TxtCil;

	mask = {TXTSRF, TXTDSN, TXTFLR, TXTCIL};
};

bool PnlPlnrStkDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrStkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFlr", TxtFlr)) add(TXTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCil", TxtCil)) add(TXTCIL);
	};

	return basefound;
};

set<uint> PnlPlnrStkDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtFlr.compare(comp->TxtFlr) == 0) insert(items, TXTFLR);
	if (TxtCil.compare(comp->TxtCil) == 0) insert(items, TXTCIL);

	return(items);
};

set<uint> PnlPlnrStkDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTFLR, TXTCIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::StatApp
 ******************************************************************************/

PnlPlnrStkDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool TxtFlrAlt
			, const bool TxtCilAlt
			, const bool LstLyrAlt
			, const uint LstLyrNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->TxtFlrAlt = TxtFlrAlt;
	this->TxtCilAlt = TxtCilAlt;
	this->LstLyrAlt = LstLyrAlt;
	this->LstLyrNumFirstdisp = LstLyrNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, TXTFLRALT, TXTCILALT, LSTLYRALT, LSTLYRNUMFIRSTDISP};
};

bool PnlPlnrStkDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrStkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFlrAlt", TxtFlrAlt)) add(TXTFLRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCilAlt", TxtCilAlt)) add(TXTCILALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLyrAlt", LstLyrAlt)) add(LSTLYRALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLyrNumFirstdisp", LstLyrNumFirstdisp)) add(LSTLYRNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrStkDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (TxtFlrAlt == comp->TxtFlrAlt) insert(items, TXTFLRALT);
	if (TxtCilAlt == comp->TxtCilAlt) insert(items, TXTCILALT);
	if (LstLyrAlt == comp->LstLyrAlt) insert(items, LSTLYRALT);
	if (LstLyrNumFirstdisp == comp->LstLyrNumFirstdisp) insert(items, LSTLYRNUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrStkDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, TXTFLRALT, TXTCILALT, LSTLYRALT, LSTLYRNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::StatShr
 ******************************************************************************/

PnlPlnrStkDetail::StatShr::StatShr(
			const bool TxfFlrValid
			, const bool TxfCilValid
			, const bool TxfLyrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
			, const bool ButLyrViewAvail
			, const bool ButLyrViewActive
		) : Block() {
	this->TxfFlrValid = TxfFlrValid;
	this->TxfCilValid = TxfCilValid;
	this->TxfLyrValid = TxfLyrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;
	this->ButLyrViewAvail = ButLyrViewAvail;
	this->ButLyrViewActive = ButLyrViewActive;

	mask = {TXFFLRVALID, TXFCILVALID, TXFLYRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL, BUTLYRVIEWACTIVE};
};

bool PnlPlnrStkDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrStkDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFlrValid", TxfFlrValid)) add(TXFFLRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCilValid", TxfCilValid)) add(TXFCILVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLyrValid", TxfLyrValid)) add(TXFLYRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLyrViewAvail", ButLyrViewAvail)) add(BUTLYRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLyrViewActive", ButLyrViewActive)) add(BUTLYRVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrStkDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfFlrValid == comp->TxfFlrValid) insert(items, TXFFLRVALID);
	if (TxfCilValid == comp->TxfCilValid) insert(items, TXFCILVALID);
	if (TxfLyrValid == comp->TxfLyrValid) insert(items, TXFLYRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);
	if (ButLyrViewAvail == comp->ButLyrViewAvail) insert(items, BUTLYRVIEWAVAIL);
	if (ButLyrViewActive == comp->ButLyrViewActive) insert(items, BUTLYRVIEWACTIVE);

	return(items);
};

set<uint> PnlPlnrStkDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFLRVALID, TXFCILVALID, TXFLYRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL, BUTLYRVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::Tag
 ******************************************************************************/

PnlPlnrStkDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptDsn
			, const string& CptMty
			, const string& CptFal
			, const string& CptFlr
			, const string& CptZfl
			, const string& CptCal
			, const string& CptCil
			, const string& CptZci
			, const string& CptLyr
			, const string& CptN
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptDsn = CptDsn;
	this->CptMty = CptMty;
	this->CptFal = CptFal;
	this->CptFlr = CptFlr;
	this->CptZfl = CptZfl;
	this->CptCal = CptCal;
	this->CptCil = CptCil;
	this->CptZci = CptZci;
	this->CptLyr = CptLyr;
	this->CptN = CptN;

	mask = {CPT, CPTSRF, CPTTYP, CPTDSN, CPTMTY, CPTFAL, CPTFLR, CPTZFL, CPTCAL, CPTCIL, CPTZCI, CPTLYR, CPTN};
};

bool PnlPlnrStkDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrStkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMty", CptMty)) add(CPTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFal", CptFal)) add(CPTFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlr", CptFlr)) add(CPTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptZfl", CptZfl)) add(CPTZFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCal", CptCal)) add(CPTCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCil", CptCil)) add(CPTCIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptZci", CptZci)) add(CPTZCI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLyr", CptLyr)) add(CPTLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptN", CptN)) add(CPTN);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrStkDetail::DpchAppData
 ******************************************************************************/

PnlPlnrStkDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrStkDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrStkDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrStkDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrStkDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrStkDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkDetail::DpchEngData
 ******************************************************************************/

PnlPlnrStkDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSTKDETAILDATA) {
	feedFLstLyr.tag = "FeedFLstLyr";
	feedFPupCal.tag = "FeedFPupCal";
	feedFPupFal.tag = "FeedFPupFal";
	feedFPupMty.tag = "FeedFPupMty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

void PnlPlnrStkDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrStkDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstLyr.readXML(docctx, basexpath, true)) add(FEEDFLSTLYR);
		if (feedFPupCal.readXML(docctx, basexpath, true)) add(FEEDFPUPCAL);
		if (feedFPupFal.readXML(docctx, basexpath, true)) add(FEEDFPUPFAL);
		if (feedFPupMty.readXML(docctx, basexpath, true)) add(FEEDFPUPMTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstLyr.clear();
		feedFPupCal.clear();
		feedFPupFal.clear();
		feedFPupMty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

