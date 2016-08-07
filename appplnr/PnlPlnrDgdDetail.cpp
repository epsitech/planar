/**
  * \file PnlPlnrDgdDetail.cpp
  * app access code for job PnlPlnrDgdDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDgdDetail.h"

/******************************************************************************
 class PnlPlnrDgdDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDgdDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrDgdDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDgdDetail::ContIac
 ******************************************************************************/

PnlPlnrDgdDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfLvl
			, const string& TxfAv1
			, const string& TxfAv2
			, const string& TxfAl1
			, const string& TxfAl2
			, const string& TxfAgd
			, const string& TxfD
			, const string& TxfDph
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->TxfLvl = TxfLvl;
	this->TxfAv1 = TxfAv1;
	this->TxfAv2 = TxfAv2;
	this->TxfAl1 = TxfAl1;
	this->TxfAl2 = TxfAl2;
	this->TxfAgd = TxfAgd;
	this->TxfD = TxfD;
	this->TxfDph = TxfDph;

	mask = {NUMFPUPTYP, TXFLVL, TXFAV1, TXFAV2, TXFAL1, TXFAL2, TXFAGD, TXFD, TXFDPH};
};

bool PnlPlnrDgdDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDgdDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLvl", TxfLvl)) add(TXFLVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv1", TxfAv1)) add(TXFAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv2", TxfAv2)) add(TXFAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl1", TxfAl1)) add(TXFAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl2", TxfAl2)) add(TXFAL2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAgd", TxfAgd)) add(TXFAGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfD", TxfD)) add(TXFD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
	};

	return basefound;
};

void PnlPlnrDgdDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfLvl", TxfLvl);
		writeStringAttr(wr, itemtag, "sref", "TxfAv1", TxfAv1);
		writeStringAttr(wr, itemtag, "sref", "TxfAv2", TxfAv2);
		writeStringAttr(wr, itemtag, "sref", "TxfAl1", TxfAl1);
		writeStringAttr(wr, itemtag, "sref", "TxfAl2", TxfAl2);
		writeStringAttr(wr, itemtag, "sref", "TxfAgd", TxfAgd);
		writeStringAttr(wr, itemtag, "sref", "TxfD", TxfD);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfLvl.compare(comp->TxfLvl) == 0) insert(items, TXFLVL);
	if (TxfAv1.compare(comp->TxfAv1) == 0) insert(items, TXFAV1);
	if (TxfAv2.compare(comp->TxfAv2) == 0) insert(items, TXFAV2);
	if (TxfAl1.compare(comp->TxfAl1) == 0) insert(items, TXFAL1);
	if (TxfAl2.compare(comp->TxfAl2) == 0) insert(items, TXFAL2);
	if (TxfAgd.compare(comp->TxfAgd) == 0) insert(items, TXFAGD);
	if (TxfD.compare(comp->TxfD) == 0) insert(items, TXFD);
	if (TxfDph.compare(comp->TxfDph) == 0) insert(items, TXFDPH);

	return(items);
};

set<uint> PnlPlnrDgdDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFLVL, TXFAV1, TXFAV2, TXFAL1, TXFAL2, TXFAGD, TXFD, TXFDPH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::ContInf
 ******************************************************************************/

PnlPlnrDgdDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtLvl
			, const string& TxtAv1
			, const string& TxtAv2
			, const string& TxtAl1
			, const string& TxtAl2
			, const string& TxtAgd
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtLvl = TxtLvl;
	this->TxtAv1 = TxtAv1;
	this->TxtAv2 = TxtAv2;
	this->TxtAl1 = TxtAl1;
	this->TxtAl2 = TxtAl2;
	this->TxtAgd = TxtAgd;

	mask = {TXTSRF, TXTDSN, TXTLVL, TXTAV1, TXTAV2, TXTAL1, TXTAL2, TXTAGD};
};

bool PnlPlnrDgdDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDgdDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLvl", TxtLvl)) add(TXTLVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAv1", TxtAv1)) add(TXTAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAv2", TxtAv2)) add(TXTAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAl1", TxtAl1)) add(TXTAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAl2", TxtAl2)) add(TXTAL2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAgd", TxtAgd)) add(TXTAGD);
	};

	return basefound;
};

set<uint> PnlPlnrDgdDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtLvl.compare(comp->TxtLvl) == 0) insert(items, TXTLVL);
	if (TxtAv1.compare(comp->TxtAv1) == 0) insert(items, TXTAV1);
	if (TxtAv2.compare(comp->TxtAv2) == 0) insert(items, TXTAV2);
	if (TxtAl1.compare(comp->TxtAl1) == 0) insert(items, TXTAL1);
	if (TxtAl2.compare(comp->TxtAl2) == 0) insert(items, TXTAL2);
	if (TxtAgd.compare(comp->TxtAgd) == 0) insert(items, TXTAGD);

	return(items);
};

set<uint> PnlPlnrDgdDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTLVL, TXTAV1, TXTAV2, TXTAL1, TXTAL2, TXTAGD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::StatApp
 ******************************************************************************/

PnlPlnrDgdDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool TxtLvlAlt
			, const bool TxtAv1Alt
			, const bool TxtAv2Alt
			, const bool TxtAl1Alt
			, const bool TxtAl2Alt
			, const bool TxtAgdAlt
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->TxtLvlAlt = TxtLvlAlt;
	this->TxtAv1Alt = TxtAv1Alt;
	this->TxtAv2Alt = TxtAv2Alt;
	this->TxtAl1Alt = TxtAl1Alt;
	this->TxtAl2Alt = TxtAl2Alt;
	this->TxtAgdAlt = TxtAgdAlt;

	mask = {IXPLNRVEXPSTATE, TXTLVLALT, TXTAV1ALT, TXTAV2ALT, TXTAL1ALT, TXTAL2ALT, TXTAGDALT};
};

bool PnlPlnrDgdDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDgdDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLvlAlt", TxtLvlAlt)) add(TXTLVLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAv1Alt", TxtAv1Alt)) add(TXTAV1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAv2Alt", TxtAv2Alt)) add(TXTAV2ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAl1Alt", TxtAl1Alt)) add(TXTAL1ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAl2Alt", TxtAl2Alt)) add(TXTAL2ALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAgdAlt", TxtAgdAlt)) add(TXTAGDALT);
	};

	return basefound;
};

set<uint> PnlPlnrDgdDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (TxtLvlAlt == comp->TxtLvlAlt) insert(items, TXTLVLALT);
	if (TxtAv1Alt == comp->TxtAv1Alt) insert(items, TXTAV1ALT);
	if (TxtAv2Alt == comp->TxtAv2Alt) insert(items, TXTAV2ALT);
	if (TxtAl1Alt == comp->TxtAl1Alt) insert(items, TXTAL1ALT);
	if (TxtAl2Alt == comp->TxtAl2Alt) insert(items, TXTAL2ALT);
	if (TxtAgdAlt == comp->TxtAgdAlt) insert(items, TXTAGDALT);

	return(items);
};

set<uint> PnlPlnrDgdDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, TXTLVLALT, TXTAV1ALT, TXTAV2ALT, TXTAL1ALT, TXTAL2ALT, TXTAGDALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::StatShr
 ******************************************************************************/

PnlPlnrDgdDetail::StatShr::StatShr(
			const bool TxfLvlValid
			, const bool TxfAv1Valid
			, const bool TxfAv2Valid
			, const bool TxfAl1Valid
			, const bool TxfAl2Valid
			, const bool TxfAgdValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
		) : Block() {
	this->TxfLvlValid = TxfLvlValid;
	this->TxfAv1Valid = TxfAv1Valid;
	this->TxfAv2Valid = TxfAv2Valid;
	this->TxfAl1Valid = TxfAl1Valid;
	this->TxfAl2Valid = TxfAl2Valid;
	this->TxfAgdValid = TxfAgdValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {TXFLVLVALID, TXFAV1VALID, TXFAV2VALID, TXFAL1VALID, TXFAL2VALID, TXFAGDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
};

bool PnlPlnrDgdDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDgdDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLvlValid", TxfLvlValid)) add(TXFLVLVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAv1Valid", TxfAv1Valid)) add(TXFAV1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAv2Valid", TxfAv2Valid)) add(TXFAV2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAl1Valid", TxfAl1Valid)) add(TXFAL1VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAl2Valid", TxfAl2Valid)) add(TXFAL2VALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAgdValid", TxfAgdValid)) add(TXFAGDVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewAvail", ButDsnViewAvail)) add(BUTDSNVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrDgdDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfLvlValid == comp->TxfLvlValid) insert(items, TXFLVLVALID);
	if (TxfAv1Valid == comp->TxfAv1Valid) insert(items, TXFAV1VALID);
	if (TxfAv2Valid == comp->TxfAv2Valid) insert(items, TXFAV2VALID);
	if (TxfAl1Valid == comp->TxfAl1Valid) insert(items, TXFAL1VALID);
	if (TxfAl2Valid == comp->TxfAl2Valid) insert(items, TXFAL2VALID);
	if (TxfAgdValid == comp->TxfAgdValid) insert(items, TXFAGDVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDgdDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFLVLVALID, TXFAV1VALID, TXFAV2VALID, TXFAL1VALID, TXFAL2VALID, TXFAGDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::Tag
 ******************************************************************************/

PnlPlnrDgdDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptDsn
			, const string& CptLvl
			, const string& CptAv1
			, const string& CptAv2
			, const string& CptAl1
			, const string& CptAl2
			, const string& CptAgd
			, const string& CptD
			, const string& CptDph
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptDsn = CptDsn;
	this->CptLvl = CptLvl;
	this->CptAv1 = CptAv1;
	this->CptAv2 = CptAv2;
	this->CptAl1 = CptAl1;
	this->CptAl2 = CptAl2;
	this->CptAgd = CptAgd;
	this->CptD = CptD;
	this->CptDph = CptDph;

	mask = {CPT, CPTSRF, CPTTYP, CPTDSN, CPTLVL, CPTAV1, CPTAV2, CPTAL1, CPTAL2, CPTAGD, CPTD, CPTDPH};
};

bool PnlPlnrDgdDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDgdDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLvl", CptLvl)) add(CPTLVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAv1", CptAv1)) add(CPTAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAv2", CptAv2)) add(CPTAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAl1", CptAl1)) add(CPTAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAl2", CptAl2)) add(CPTAL2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAgd", CptAgd)) add(CPTAGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptD", CptD)) add(CPTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDph", CptDph)) add(CPTDPH);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDgdDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDgdDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrDgdDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDgdDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDgdDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDgdDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDgdDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDgdDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDGDDETAILDATA) {
	feedFPupTyp.tag = "FeedFPupTyp";
};

void PnlPlnrDgdDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDgdDetailData");
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

