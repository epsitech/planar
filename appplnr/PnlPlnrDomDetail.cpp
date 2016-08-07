/**
  * \file PnlPlnrDomDetail.cpp
  * app access code for job PnlPlnrDomDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDomDetail.h"

/******************************************************************************
 class PnlPlnrDomDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDomDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrDomDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDomDetail::ContIac
 ******************************************************************************/

PnlPlnrDomDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfFlr
			, const string& TxfCei
			, const string& TxfVx1
			, const string& TxfLg1
			, const string& TxfVx2
			, const string& TxfLg2
			, const string& TxfVx3
			, const string& TxfLg3
			, const string& TxfVx4
			, const string& TxfLg4
			, const string& TxfDx
			, const string& TxfDy
			, const string& TxfDxy
			, const string& TxfDz
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->TxfFlr = TxfFlr;
	this->TxfCei = TxfCei;
	this->TxfVx1 = TxfVx1;
	this->TxfLg1 = TxfLg1;
	this->TxfVx2 = TxfVx2;
	this->TxfLg2 = TxfLg2;
	this->TxfVx3 = TxfVx3;
	this->TxfLg3 = TxfLg3;
	this->TxfVx4 = TxfVx4;
	this->TxfLg4 = TxfLg4;
	this->TxfDx = TxfDx;
	this->TxfDy = TxfDy;
	this->TxfDxy = TxfDxy;
	this->TxfDz = TxfDz;

	mask = {NUMFPUPTYP, TXFFLR, TXFCEI, TXFVX1, TXFLG1, TXFVX2, TXFLG2, TXFVX3, TXFLG3, TXFVX4, TXFLG4, TXFDX, TXFDY, TXFDXY, TXFDZ};
};

bool PnlPlnrDomDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDomDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDomDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFlr", TxfFlr)) add(TXFFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCei", TxfCei)) add(TXFCEI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVx1", TxfVx1)) add(TXFVX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLg1", TxfLg1)) add(TXFLG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVx2", TxfVx2)) add(TXFVX2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLg2", TxfLg2)) add(TXFLG2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVx3", TxfVx3)) add(TXFVX3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLg3", TxfLg3)) add(TXFLG3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVx4", TxfVx4)) add(TXFVX4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLg4", TxfLg4)) add(TXFLG4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDx", TxfDx)) add(TXFDX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDy", TxfDy)) add(TXFDY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDxy", TxfDxy)) add(TXFDXY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDz", TxfDz)) add(TXFDZ);
	};

	return basefound;
};

void PnlPlnrDomDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDomDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDomDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfFlr", TxfFlr);
		writeStringAttr(wr, itemtag, "sref", "TxfCei", TxfCei);
		writeStringAttr(wr, itemtag, "sref", "TxfVx1", TxfVx1);
		writeStringAttr(wr, itemtag, "sref", "TxfLg1", TxfLg1);
		writeStringAttr(wr, itemtag, "sref", "TxfVx2", TxfVx2);
		writeStringAttr(wr, itemtag, "sref", "TxfLg2", TxfLg2);
		writeStringAttr(wr, itemtag, "sref", "TxfVx3", TxfVx3);
		writeStringAttr(wr, itemtag, "sref", "TxfLg3", TxfLg3);
		writeStringAttr(wr, itemtag, "sref", "TxfVx4", TxfVx4);
		writeStringAttr(wr, itemtag, "sref", "TxfLg4", TxfLg4);
		writeStringAttr(wr, itemtag, "sref", "TxfDx", TxfDx);
		writeStringAttr(wr, itemtag, "sref", "TxfDy", TxfDy);
		writeStringAttr(wr, itemtag, "sref", "TxfDxy", TxfDxy);
		writeStringAttr(wr, itemtag, "sref", "TxfDz", TxfDz);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDomDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfFlr.compare(comp->TxfFlr) == 0) insert(items, TXFFLR);
	if (TxfCei.compare(comp->TxfCei) == 0) insert(items, TXFCEI);
	if (TxfVx1.compare(comp->TxfVx1) == 0) insert(items, TXFVX1);
	if (TxfLg1.compare(comp->TxfLg1) == 0) insert(items, TXFLG1);
	if (TxfVx2.compare(comp->TxfVx2) == 0) insert(items, TXFVX2);
	if (TxfLg2.compare(comp->TxfLg2) == 0) insert(items, TXFLG2);
	if (TxfVx3.compare(comp->TxfVx3) == 0) insert(items, TXFVX3);
	if (TxfLg3.compare(comp->TxfLg3) == 0) insert(items, TXFLG3);
	if (TxfVx4.compare(comp->TxfVx4) == 0) insert(items, TXFVX4);
	if (TxfLg4.compare(comp->TxfLg4) == 0) insert(items, TXFLG4);
	if (TxfDx.compare(comp->TxfDx) == 0) insert(items, TXFDX);
	if (TxfDy.compare(comp->TxfDy) == 0) insert(items, TXFDY);
	if (TxfDxy.compare(comp->TxfDxy) == 0) insert(items, TXFDXY);
	if (TxfDz.compare(comp->TxfDz) == 0) insert(items, TXFDZ);

	return(items);
};

set<uint> PnlPlnrDomDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFFLR, TXFCEI, TXFVX1, TXFLG1, TXFVX2, TXFLG2, TXFVX3, TXFLG3, TXFVX4, TXFLG4, TXFDX, TXFDY, TXFDXY, TXFDZ};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDomDetail::ContInf
 ******************************************************************************/

PnlPlnrDomDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtFlr
			, const string& TxtCei
			, const string& TxtVx1
			, const string& TxtLg1
			, const string& TxtVx2
			, const string& TxtLg2
			, const string& TxtVx3
			, const string& TxtLg3
			, const string& TxtVx4
			, const string& TxtLg4
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtFlr = TxtFlr;
	this->TxtCei = TxtCei;
	this->TxtVx1 = TxtVx1;
	this->TxtLg1 = TxtLg1;
	this->TxtVx2 = TxtVx2;
	this->TxtLg2 = TxtLg2;
	this->TxtVx3 = TxtVx3;
	this->TxtLg3 = TxtLg3;
	this->TxtVx4 = TxtVx4;
	this->TxtLg4 = TxtLg4;

	mask = {TXTSRF, TXTDSN, TXTFLR, TXTCEI, TXTVX1, TXTLG1, TXTVX2, TXTLG2, TXTVX3, TXTLG3, TXTVX4, TXTLG4};
};

bool PnlPlnrDomDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDomDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDomDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFlr", TxtFlr)) add(TXTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCei", TxtCei)) add(TXTCEI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVx1", TxtVx1)) add(TXTVX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLg1", TxtLg1)) add(TXTLG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVx2", TxtVx2)) add(TXTVX2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLg2", TxtLg2)) add(TXTLG2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVx3", TxtVx3)) add(TXTVX3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLg3", TxtLg3)) add(TXTLG3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVx4", TxtVx4)) add(TXTVX4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLg4", TxtLg4)) add(TXTLG4);
	};

	return basefound;
};

set<uint> PnlPlnrDomDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtFlr.compare(comp->TxtFlr) == 0) insert(items, TXTFLR);
	if (TxtCei.compare(comp->TxtCei) == 0) insert(items, TXTCEI);
	if (TxtVx1.compare(comp->TxtVx1) == 0) insert(items, TXTVX1);
	if (TxtLg1.compare(comp->TxtLg1) == 0) insert(items, TXTLG1);
	if (TxtVx2.compare(comp->TxtVx2) == 0) insert(items, TXTVX2);
	if (TxtLg2.compare(comp->TxtLg2) == 0) insert(items, TXTLG2);
	if (TxtVx3.compare(comp->TxtVx3) == 0) insert(items, TXTVX3);
	if (TxtLg3.compare(comp->TxtLg3) == 0) insert(items, TXTLG3);
	if (TxtVx4.compare(comp->TxtVx4) == 0) insert(items, TXTVX4);
	if (TxtLg4.compare(comp->TxtLg4) == 0) insert(items, TXTLG4);

	return(items);
};

set<uint> PnlPlnrDomDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTFLR, TXTCEI, TXTVX1, TXTLG1, TXTVX2, TXTLG2, TXTVX3, TXTLG3, TXTVX4, TXTLG4};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDomDetail::StatApp
 ******************************************************************************/

PnlPlnrDomDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool TxtFlrAlt
			, const bool TxtCeiAlt
			, const bool TxtVx1Alt
			, const bool TxtLg1Alt
			, const bool TxtVx2Alt
			, const bool TxtLg2Alt
			, const bool TxtVx3Alt
			, const bool TxtLg3Alt
			, const bool TxtVx4Alt
			, const bool TxtLg4Alt
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->TxtFlrAlt = TxtFlrAlt;
	this->TxtCeiAlt = TxtCeiAlt;
	this->TxtVx1Alt = TxtVx1Alt;
	this->TxtLg1Alt = TxtLg1Alt;
	this->TxtVx2Alt = TxtVx2Alt;
	this->TxtLg2Alt = TxtLg2Alt;
	this->TxtVx3Alt = TxtVx3Alt;
	this->TxtLg3Alt = TxtLg3Alt;
	this->TxtVx4Alt = TxtVx4Alt;
	this->TxtLg4Alt = TxtLg4Alt;

	mask = {IXPLNRVEXPSTATE, TXTFLRALT, TXTCEIALT, TXTVX1ALT, TXTLG1ALT, TXTVX2ALT, TXTLG2ALT, TXTVX3ALT, TXTLG3ALT, TXTVX4ALT, TXTLG4ALT};
};

bool PnlPlnrDomDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDomDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDomDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFlrAlt", TxtFlrAlt)) add(TXTFLRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCeiAlt", TxtCeiAlt)) add(TXTCEIALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVx1Alt", TxtVx1Alt)) add(TXTVX1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLg1Alt", TxtLg1Alt)) add(TXTLG1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVx2Alt", TxtVx2Alt)) add(TXTVX2ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLg2Alt", TxtLg2Alt)) add(TXTLG2ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVx3Alt", TxtVx3Alt)) add(TXTVX3ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLg3Alt", TxtLg3Alt)) add(TXTLG3ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVx4Alt", TxtVx4Alt)) add(TXTVX4ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLg4Alt", TxtLg4Alt)) add(TXTLG4ALT);
	};

	return basefound;
};

set<uint> PnlPlnrDomDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (TxtFlrAlt == comp->TxtFlrAlt) insert(items, TXTFLRALT);
	if (TxtCeiAlt == comp->TxtCeiAlt) insert(items, TXTCEIALT);
	if (TxtVx1Alt == comp->TxtVx1Alt) insert(items, TXTVX1ALT);
	if (TxtLg1Alt == comp->TxtLg1Alt) insert(items, TXTLG1ALT);
	if (TxtVx2Alt == comp->TxtVx2Alt) insert(items, TXTVX2ALT);
	if (TxtLg2Alt == comp->TxtLg2Alt) insert(items, TXTLG2ALT);
	if (TxtVx3Alt == comp->TxtVx3Alt) insert(items, TXTVX3ALT);
	if (TxtLg3Alt == comp->TxtLg3Alt) insert(items, TXTLG3ALT);
	if (TxtVx4Alt == comp->TxtVx4Alt) insert(items, TXTVX4ALT);
	if (TxtLg4Alt == comp->TxtLg4Alt) insert(items, TXTLG4ALT);

	return(items);
};

set<uint> PnlPlnrDomDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, TXTFLRALT, TXTCEIALT, TXTVX1ALT, TXTLG1ALT, TXTVX2ALT, TXTLG2ALT, TXTVX3ALT, TXTLG3ALT, TXTVX4ALT, TXTLG4ALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDomDetail::StatShr
 ******************************************************************************/

PnlPlnrDomDetail::StatShr::StatShr(
			const bool TxfFlrValid
			, const bool TxfCeiValid
			, const bool TxfVx1Valid
			, const bool TxfLg1Valid
			, const bool TxfVx2Valid
			, const bool TxfLg2Valid
			, const bool TxfVx3Valid
			, const bool TxfLg3Valid
			, const bool TxfVx4Valid
			, const bool TxfLg4Valid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
		) : Block() {
	this->TxfFlrValid = TxfFlrValid;
	this->TxfCeiValid = TxfCeiValid;
	this->TxfVx1Valid = TxfVx1Valid;
	this->TxfLg1Valid = TxfLg1Valid;
	this->TxfVx2Valid = TxfVx2Valid;
	this->TxfLg2Valid = TxfLg2Valid;
	this->TxfVx3Valid = TxfVx3Valid;
	this->TxfLg3Valid = TxfLg3Valid;
	this->TxfVx4Valid = TxfVx4Valid;
	this->TxfLg4Valid = TxfLg4Valid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {TXFFLRVALID, TXFCEIVALID, TXFVX1VALID, TXFLG1VALID, TXFVX2VALID, TXFLG2VALID, TXFVX3VALID, TXFLG3VALID, TXFVX4VALID, TXFLG4VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
};

bool PnlPlnrDomDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDomDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDomDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFlrValid", TxfFlrValid)) add(TXFFLRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCeiValid", TxfCeiValid)) add(TXFCEIVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVx1Valid", TxfVx1Valid)) add(TXFVX1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLg1Valid", TxfLg1Valid)) add(TXFLG1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVx2Valid", TxfVx2Valid)) add(TXFVX2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLg2Valid", TxfLg2Valid)) add(TXFLG2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVx3Valid", TxfVx3Valid)) add(TXFVX3VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLg3Valid", TxfLg3Valid)) add(TXFLG3VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVx4Valid", TxfVx4Valid)) add(TXFVX4VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLg4Valid", TxfLg4Valid)) add(TXFLG4VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrDomDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfFlrValid == comp->TxfFlrValid) insert(items, TXFFLRVALID);
	if (TxfCeiValid == comp->TxfCeiValid) insert(items, TXFCEIVALID);
	if (TxfVx1Valid == comp->TxfVx1Valid) insert(items, TXFVX1VALID);
	if (TxfLg1Valid == comp->TxfLg1Valid) insert(items, TXFLG1VALID);
	if (TxfVx2Valid == comp->TxfVx2Valid) insert(items, TXFVX2VALID);
	if (TxfLg2Valid == comp->TxfLg2Valid) insert(items, TXFLG2VALID);
	if (TxfVx3Valid == comp->TxfVx3Valid) insert(items, TXFVX3VALID);
	if (TxfLg3Valid == comp->TxfLg3Valid) insert(items, TXFLG3VALID);
	if (TxfVx4Valid == comp->TxfVx4Valid) insert(items, TXFVX4VALID);
	if (TxfLg4Valid == comp->TxfLg4Valid) insert(items, TXFLG4VALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDomDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFLRVALID, TXFCEIVALID, TXFVX1VALID, TXFLG1VALID, TXFVX2VALID, TXFLG2VALID, TXFVX3VALID, TXFLG3VALID, TXFVX4VALID, TXFLG4VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDomDetail::Tag
 ******************************************************************************/

PnlPlnrDomDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptDsn
			, const string& CptFlr
			, const string& CptCei
			, const string& CptVx1
			, const string& CptLg1
			, const string& CptVx2
			, const string& CptLg2
			, const string& CptVx3
			, const string& CptLg3
			, const string& CptVx4
			, const string& CptLg4
			, const string& CptDx
			, const string& CptDy
			, const string& CptDxy
			, const string& CptDz
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptDsn = CptDsn;
	this->CptFlr = CptFlr;
	this->CptCei = CptCei;
	this->CptVx1 = CptVx1;
	this->CptLg1 = CptLg1;
	this->CptVx2 = CptVx2;
	this->CptLg2 = CptLg2;
	this->CptVx3 = CptVx3;
	this->CptLg3 = CptLg3;
	this->CptVx4 = CptVx4;
	this->CptLg4 = CptLg4;
	this->CptDx = CptDx;
	this->CptDy = CptDy;
	this->CptDxy = CptDxy;
	this->CptDz = CptDz;

	mask = {CPT, CPTSRF, CPTTYP, CPTDSN, CPTFLR, CPTCEI, CPTVX1, CPTLG1, CPTVX2, CPTLG2, CPTVX3, CPTLG3, CPTVX4, CPTLG4, CPTDX, CPTDY, CPTDXY, CPTDZ};
};

bool PnlPlnrDomDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDomDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDomDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFlr", CptFlr)) add(CPTFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCei", CptCei)) add(CPTCEI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVx1", CptVx1)) add(CPTVX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLg1", CptLg1)) add(CPTLG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVx2", CptVx2)) add(CPTVX2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLg2", CptLg2)) add(CPTLG2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVx3", CptVx3)) add(CPTVX3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLg3", CptLg3)) add(CPTLG3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVx4", CptVx4)) add(CPTVX4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLg4", CptLg4)) add(CPTLG4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDx", CptDx)) add(CPTDX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDy", CptDy)) add(CPTDY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDxy", CptDxy)) add(CPTDXY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDz", CptDz)) add(CPTDZ);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDomDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrDomDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDomDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDomDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDomDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDomDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDomDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDOMDETAILDATA) {
	feedFPupTyp.tag = "FeedFPupTyp";
};

void PnlPlnrDomDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDomDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

