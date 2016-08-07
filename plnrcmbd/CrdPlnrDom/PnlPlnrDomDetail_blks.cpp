/**
  * \file PnlPlnrDomDetail_blks.cpp
  * job handler for job PnlPlnrDomDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDomDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDomDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

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
	if (TxfFlr == comp->TxfFlr) insert(items, TXFFLR);
	if (TxfCei == comp->TxfCei) insert(items, TXFCEI);
	if (TxfVx1 == comp->TxfVx1) insert(items, TXFVX1);
	if (TxfLg1 == comp->TxfLg1) insert(items, TXFLG1);
	if (TxfVx2 == comp->TxfVx2) insert(items, TXFVX2);
	if (TxfLg2 == comp->TxfLg2) insert(items, TXFLG2);
	if (TxfVx3 == comp->TxfVx3) insert(items, TXFVX3);
	if (TxfLg3 == comp->TxfLg3) insert(items, TXFLG3);
	if (TxfVx4 == comp->TxfVx4) insert(items, TXFVX4);
	if (TxfLg4 == comp->TxfLg4) insert(items, TXFLG4);
	if (TxfDx == comp->TxfDx) insert(items, TXFDX);
	if (TxfDy == comp->TxfDy) insert(items, TXFDY);
	if (TxfDxy == comp->TxfDxy) insert(items, TXFDXY);
	if (TxfDz == comp->TxfDz) insert(items, TXFDZ);

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

void PnlPlnrDomDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDomDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDomDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtFlr", TxtFlr);
		writeStringAttr(wr, itemtag, "sref", "TxtCei", TxtCei);
		writeStringAttr(wr, itemtag, "sref", "TxtVx1", TxtVx1);
		writeStringAttr(wr, itemtag, "sref", "TxtLg1", TxtLg1);
		writeStringAttr(wr, itemtag, "sref", "TxtVx2", TxtVx2);
		writeStringAttr(wr, itemtag, "sref", "TxtLg2", TxtLg2);
		writeStringAttr(wr, itemtag, "sref", "TxtVx3", TxtVx3);
		writeStringAttr(wr, itemtag, "sref", "TxtLg3", TxtLg3);
		writeStringAttr(wr, itemtag, "sref", "TxtVx4", TxtVx4);
		writeStringAttr(wr, itemtag, "sref", "TxtLg4", TxtLg4);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDomDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtFlr == comp->TxtFlr) insert(items, TXTFLR);
	if (TxtCei == comp->TxtCei) insert(items, TXTCEI);
	if (TxtVx1 == comp->TxtVx1) insert(items, TXTVX1);
	if (TxtLg1 == comp->TxtLg1) insert(items, TXTLG1);
	if (TxtVx2 == comp->TxtVx2) insert(items, TXTVX2);
	if (TxtLg2 == comp->TxtLg2) insert(items, TXTLG2);
	if (TxtVx3 == comp->TxtVx3) insert(items, TXTVX3);
	if (TxtLg3 == comp->TxtLg3) insert(items, TXTLG3);
	if (TxtVx4 == comp->TxtVx4) insert(items, TXTVX4);
	if (TxtLg4 == comp->TxtLg4) insert(items, TXTLG4);

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

void PnlPlnrDomDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDomDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDomDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtFlrAlt", TxtFlrAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtCeiAlt", TxtCeiAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtVx1Alt", TxtVx1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtLg1Alt", TxtLg1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtVx2Alt", TxtVx2Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtLg2Alt", TxtLg2Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtVx3Alt", TxtVx3Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtLg3Alt", TxtLg3Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtVx4Alt", TxtVx4Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtLg4Alt", TxtLg4Alt);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrDomDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDomDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDomDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfFlrValid", TxfFlrValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfCeiValid", TxfCeiValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfVx1Valid", TxfVx1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfLg1Valid", TxfLg1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfVx2Valid", TxfVx2Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfLg2Valid", TxfLg2Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfVx3Valid", TxfVx3Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfLg3Valid", TxfLg3Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfVx4Valid", TxfVx4Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfLg4Valid", TxfLg4Valid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrDomDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDomDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDomDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptFlr", "floor level");
			writeStringAttr(wr, itemtag, "sref", "CptCei", "ceiling level");
			writeStringAttr(wr, itemtag, "sref", "CptVx1", "vertex 1");
			writeStringAttr(wr, itemtag, "sref", "CptLg1", "line guide 1");
			writeStringAttr(wr, itemtag, "sref", "CptVx2", "vertex 2");
			writeStringAttr(wr, itemtag, "sref", "CptLg2", "line guide 2");
			writeStringAttr(wr, itemtag, "sref", "CptVx3", "vertex 3");
			writeStringAttr(wr, itemtag, "sref", "CptLg3", "line guide 3");
			writeStringAttr(wr, itemtag, "sref", "CptVx4", "vertex 4");
			writeStringAttr(wr, itemtag, "sref", "CptLg4", "line guide 4");
			writeStringAttr(wr, itemtag, "sref", "CptDx", "x grid [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDy", "y grid [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDxy", "xy grid [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDz", "z grid [\\u03bcm]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDomDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDATA) {
};

void PnlPlnrDomDetail::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDomDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDomDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrDomDetail::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDomDetailDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlPlnrDomDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDomDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDOMDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDomDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDomDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDomDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


