/**
  * \file PnlPlnrDtpDetail.cpp
  * app access code for job PnlPlnrDtpDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDtpDetail.h"

/******************************************************************************
 class PnlPlnrDtpDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDtpDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrDtpDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDtpDetail::ContIac
 ******************************************************************************/

PnlPlnrDtpDetail::ContIac::ContIac(
			const uint numFPupMty
			, const uint numFPupAty
			, const string& TxfAv1
			, const string& TxfPv1
			, const string& TxfAv2
			, const string& TxfPv2
			, const string& TxfX
			, const string& TxfY
			, const string& TxfPhi
			, const string& TxfCmt
		) : Block() {
	this->numFPupMty = numFPupMty;
	this->numFPupAty = numFPupAty;
	this->TxfAv1 = TxfAv1;
	this->TxfPv1 = TxfPv1;
	this->TxfAv2 = TxfAv2;
	this->TxfPv2 = TxfPv2;
	this->TxfX = TxfX;
	this->TxfY = TxfY;
	this->TxfPhi = TxfPhi;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPMTY, NUMFPUPATY, TXFAV1, TXFPV1, TXFAV2, TXFPV2, TXFX, TXFY, TXFPHI, TXFCMT};
};

bool PnlPlnrDtpDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDtpDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMty", numFPupMty)) add(NUMFPUPMTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAty", numFPupAty)) add(NUMFPUPATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv1", TxfAv1)) add(TXFAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPv1", TxfPv1)) add(TXFPV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv2", TxfAv2)) add(TXFAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPv2", TxfPv2)) add(TXFPV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX", TxfX)) add(TXFX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY", TxfY)) add(TXFY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPhi", TxfPhi)) add(TXFPHI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlPlnrDtpDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupMty", numFPupMty);
		writeUintAttr(wr, itemtag, "sref", "numFPupAty", numFPupAty);
		writeStringAttr(wr, itemtag, "sref", "TxfAv1", TxfAv1);
		writeStringAttr(wr, itemtag, "sref", "TxfPv1", TxfPv1);
		writeStringAttr(wr, itemtag, "sref", "TxfAv2", TxfAv2);
		writeStringAttr(wr, itemtag, "sref", "TxfPv2", TxfPv2);
		writeStringAttr(wr, itemtag, "sref", "TxfX", TxfX);
		writeStringAttr(wr, itemtag, "sref", "TxfY", TxfY);
		writeStringAttr(wr, itemtag, "sref", "TxfPhi", TxfPhi);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDtpDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupMty == comp->numFPupMty) insert(items, NUMFPUPMTY);
	if (numFPupAty == comp->numFPupAty) insert(items, NUMFPUPATY);
	if (TxfAv1.compare(comp->TxfAv1) == 0) insert(items, TXFAV1);
	if (TxfPv1.compare(comp->TxfPv1) == 0) insert(items, TXFPV1);
	if (TxfAv2.compare(comp->TxfAv2) == 0) insert(items, TXFAV2);
	if (TxfPv2.compare(comp->TxfPv2) == 0) insert(items, TXFPV2);
	if (TxfX.compare(comp->TxfX) == 0) insert(items, TXFX);
	if (TxfY.compare(comp->TxfY) == 0) insert(items, TXFY);
	if (TxfPhi.compare(comp->TxfPhi) == 0) insert(items, TXFPHI);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlPlnrDtpDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPMTY, NUMFPUPATY, TXFAV1, TXFPV1, TXFAV2, TXFPV2, TXFX, TXFY, TXFPHI, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpDetail::ContInf
 ******************************************************************************/

PnlPlnrDtpDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtSup
			, const string& TxtTpl
			, const string& TxtAv1
			, const string& TxtPv1
			, const string& TxtAv2
			, const string& TxtPv2
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtSup = TxtSup;
	this->TxtTpl = TxtTpl;
	this->TxtAv1 = TxtAv1;
	this->TxtPv1 = TxtPv1;
	this->TxtAv2 = TxtAv2;
	this->TxtPv2 = TxtPv2;

	mask = {TXTSRF, TXTDSN, TXTSUP, TXTTPL, TXTAV1, TXTPV1, TXTAV2, TXTPV2};
};

bool PnlPlnrDtpDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDtpDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTpl", TxtTpl)) add(TXTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAv1", TxtAv1)) add(TXTAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPv1", TxtPv1)) add(TXTPV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAv2", TxtAv2)) add(TXTAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPv2", TxtPv2)) add(TXTPV2);
	};

	return basefound;
};

set<uint> PnlPlnrDtpDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtSup.compare(comp->TxtSup) == 0) insert(items, TXTSUP);
	if (TxtTpl.compare(comp->TxtTpl) == 0) insert(items, TXTTPL);
	if (TxtAv1.compare(comp->TxtAv1) == 0) insert(items, TXTAV1);
	if (TxtPv1.compare(comp->TxtPv1) == 0) insert(items, TXTPV1);
	if (TxtAv2.compare(comp->TxtAv2) == 0) insert(items, TXTAV2);
	if (TxtPv2.compare(comp->TxtPv2) == 0) insert(items, TXTPV2);

	return(items);
};

set<uint> PnlPlnrDtpDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTSUP, TXTTPL, TXTAV1, TXTPV1, TXTAV2, TXTPV2};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpDetail::StatApp
 ******************************************************************************/

PnlPlnrDtpDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool TxtAv1Alt
			, const bool TxtPv1Alt
			, const bool TxtAv2Alt
			, const bool TxtPv2Alt
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->TxtAv1Alt = TxtAv1Alt;
	this->TxtPv1Alt = TxtPv1Alt;
	this->TxtAv2Alt = TxtAv2Alt;
	this->TxtPv2Alt = TxtPv2Alt;

	mask = {IXPLNRVEXPSTATE, TXTAV1ALT, TXTPV1ALT, TXTAV2ALT, TXTPV2ALT};
};

bool PnlPlnrDtpDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDtpDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAv1Alt", TxtAv1Alt)) add(TXTAV1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPv1Alt", TxtPv1Alt)) add(TXTPV1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAv2Alt", TxtAv2Alt)) add(TXTAV2ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPv2Alt", TxtPv2Alt)) add(TXTPV2ALT);
	};

	return basefound;
};

set<uint> PnlPlnrDtpDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (TxtAv1Alt == comp->TxtAv1Alt) insert(items, TXTAV1ALT);
	if (TxtPv1Alt == comp->TxtPv1Alt) insert(items, TXTPV1ALT);
	if (TxtAv2Alt == comp->TxtAv2Alt) insert(items, TXTAV2ALT);
	if (TxtPv2Alt == comp->TxtPv2Alt) insert(items, TXTPV2ALT);

	return(items);
};

set<uint> PnlPlnrDtpDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, TXTAV1ALT, TXTPV1ALT, TXTAV2ALT, TXTPV2ALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpDetail::StatShr
 ******************************************************************************/

PnlPlnrDtpDetail::StatShr::StatShr(
			const bool TxfAv1Valid
			, const bool TxfPv1Valid
			, const bool TxfAv2Valid
			, const bool TxfPv2Valid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
		) : Block() {
	this->TxfAv1Valid = TxfAv1Valid;
	this->TxfPv1Valid = TxfPv1Valid;
	this->TxfAv2Valid = TxfAv2Valid;
	this->TxfPv2Valid = TxfPv2Valid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {TXFAV1VALID, TXFPV1VALID, TXFAV2VALID, TXFPV2VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
};

bool PnlPlnrDtpDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDtpDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAv1Valid", TxfAv1Valid)) add(TXFAV1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPv1Valid", TxfPv1Valid)) add(TXFPV1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAv2Valid", TxfAv2Valid)) add(TXFAV2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPv2Valid", TxfPv2Valid)) add(TXFPV2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrDtpDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAv1Valid == comp->TxfAv1Valid) insert(items, TXFAV1VALID);
	if (TxfPv1Valid == comp->TxfPv1Valid) insert(items, TXFPV1VALID);
	if (TxfAv2Valid == comp->TxfAv2Valid) insert(items, TXFAV2VALID);
	if (TxfPv2Valid == comp->TxfPv2Valid) insert(items, TXFPV2VALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDtpDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFAV1VALID, TXFPV1VALID, TXFAV2VALID, TXFPV2VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpDetail::Tag
 ******************************************************************************/

PnlPlnrDtpDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptDsn
			, const string& CptSup
			, const string& CptTpl
			, const string& CptMty
			, const string& CptAty
			, const string& CptAv1
			, const string& CptPv1
			, const string& CptAv2
			, const string& CptPv2
			, const string& CptX
			, const string& CptY
			, const string& CptPhi
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptDsn = CptDsn;
	this->CptSup = CptSup;
	this->CptTpl = CptTpl;
	this->CptMty = CptMty;
	this->CptAty = CptAty;
	this->CptAv1 = CptAv1;
	this->CptPv1 = CptPv1;
	this->CptAv2 = CptAv2;
	this->CptPv2 = CptPv2;
	this->CptX = CptX;
	this->CptY = CptY;
	this->CptPhi = CptPhi;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTDSN, CPTSUP, CPTTPL, CPTMTY, CPTATY, CPTAV1, CPTPV1, CPTAV2, CPTPV2, CPTX, CPTY, CPTPHI, CPTCMT};
};

bool PnlPlnrDtpDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDtpDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTpl", CptTpl)) add(CPTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMty", CptMty)) add(CPTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAty", CptAty)) add(CPTATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAv1", CptAv1)) add(CPTAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPv1", CptPv1)) add(CPTPV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAv2", CptAv2)) add(CPTAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPv2", CptPv2)) add(CPTPV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptX", CptX)) add(CPTX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptY", CptY)) add(CPTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPhi", CptPhi)) add(CPTPHI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDtpDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDtpDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrDtpDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDtpDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDtpDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDtpDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDtpDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDtpDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDtpDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDtpDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDTPDETAILDATA) {
	feedFPupAty.tag = "FeedFPupAty";
	feedFPupMty.tag = "FeedFPupMty";
};

void PnlPlnrDtpDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDtpDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAty.readXML(docctx, basexpath, true)) add(FEEDFPUPATY);
		if (feedFPupMty.readXML(docctx, basexpath, true)) add(FEEDFPUPMTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAty.clear();
		feedFPupMty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

