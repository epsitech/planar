/**
  * \file PnlPlnrNavGlobal.cpp
  * app access code for job PnlPlnrNavGlobal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrNavGlobal.h"

/******************************************************************************
 class PnlPlnrNavGlobal::VecVDo
 ******************************************************************************/

uint PnlPlnrNavGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdtpviewclick") == 0) return BUTDTPVIEWCLICK;
	else if (s.compare("butdtpnewcrdclick") == 0) return BUTDTPNEWCRDCLICK;
	else if (s.compare("butctpviewclick") == 0) return BUTCTPVIEWCLICK;
	else if (s.compare("butctpnewcrdclick") == 0) return BUTCTPNEWCRDCLICK;
	else if (s.compare("butmatviewclick") == 0) return BUTMATVIEWCLICK;
	else if (s.compare("butmatnewcrdclick") == 0) return BUTMATNEWCRDCLICK;

	return(0);
};

string PnlPlnrNavGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDTPVIEWCLICK) return("ButDtpViewClick");
	else if (ix == BUTDTPNEWCRDCLICK) return("ButDtpNewcrdClick");
	else if (ix == BUTCTPVIEWCLICK) return("ButCtpViewClick");
	else if (ix == BUTCTPNEWCRDCLICK) return("ButCtpNewcrdClick");
	else if (ix == BUTMATVIEWCLICK) return("ButMatViewClick");
	else if (ix == BUTMATNEWCRDCLICK) return("ButMatNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavGlobal::ContIac
 ******************************************************************************/

PnlPlnrNavGlobal::ContIac::ContIac(
			const uint numFLstDtp
			, const uint numFLstCtp
			, const uint numFLstMat
		) : Block() {
	this->numFLstDtp = numFLstDtp;
	this->numFLstCtp = numFLstCtp;
	this->numFLstMat = numFLstMat;

	mask = {NUMFLSTDTP, NUMFLSTCTP, NUMFLSTMAT};
};

bool PnlPlnrNavGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavGlobal";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDtp", numFLstDtp)) add(NUMFLSTDTP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCtp", numFLstCtp)) add(NUMFLSTCTP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMat", numFLstMat)) add(NUMFLSTMAT);
	};

	return basefound;
};

void PnlPlnrNavGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstDtp", numFLstDtp);
		writeUintAttr(wr, itemtag, "sref", "numFLstCtp", numFLstCtp);
		writeUintAttr(wr, itemtag, "sref", "numFLstMat", numFLstMat);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstDtp == comp->numFLstDtp) insert(items, NUMFLSTDTP);
	if (numFLstCtp == comp->numFLstCtp) insert(items, NUMFLSTCTP);
	if (numFLstMat == comp->numFLstMat) insert(items, NUMFLSTMAT);

	return(items);
};

set<uint> PnlPlnrNavGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTDTP, NUMFLSTCTP, NUMFLSTMAT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavGlobal::StatApp
 ******************************************************************************/

PnlPlnrNavGlobal::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool LstDtpAlt
			, const bool LstCtpAlt
			, const bool LstMatAlt
			, const uint LstDtpNumFirstdisp
			, const uint LstCtpNumFirstdisp
			, const uint LstMatNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->LstDtpAlt = LstDtpAlt;
	this->LstCtpAlt = LstCtpAlt;
	this->LstMatAlt = LstMatAlt;
	this->LstDtpNumFirstdisp = LstDtpNumFirstdisp;
	this->LstCtpNumFirstdisp = LstCtpNumFirstdisp;
	this->LstMatNumFirstdisp = LstMatNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, LSTDTPALT, LSTCTPALT, LSTMATALT, LSTDTPNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMATNUMFIRSTDISP};
};

bool PnlPlnrNavGlobal::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDtpAlt", LstDtpAlt)) add(LSTDTPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpAlt", LstCtpAlt)) add(LSTCTPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMatAlt", LstMatAlt)) add(LSTMATALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDtpNumFirstdisp", LstDtpNumFirstdisp)) add(LSTDTPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpNumFirstdisp", LstCtpNumFirstdisp)) add(LSTCTPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMatNumFirstdisp", LstMatNumFirstdisp)) add(LSTMATNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrNavGlobal::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (LstDtpAlt == comp->LstDtpAlt) insert(items, LSTDTPALT);
	if (LstCtpAlt == comp->LstCtpAlt) insert(items, LSTCTPALT);
	if (LstMatAlt == comp->LstMatAlt) insert(items, LSTMATALT);
	if (LstDtpNumFirstdisp == comp->LstDtpNumFirstdisp) insert(items, LSTDTPNUMFIRSTDISP);
	if (LstCtpNumFirstdisp == comp->LstCtpNumFirstdisp) insert(items, LSTCTPNUMFIRSTDISP);
	if (LstMatNumFirstdisp == comp->LstMatNumFirstdisp) insert(items, LSTMATNUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrNavGlobal::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, LSTDTPALT, LSTCTPALT, LSTMATALT, LSTDTPNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMATNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavGlobal::StatShr
 ******************************************************************************/

PnlPlnrNavGlobal::StatShr::StatShr(
			const bool LstDtpAvail
			, const bool ButDtpViewActive
			, const bool LstCtpAvail
			, const bool ButCtpViewActive
			, const bool LstMatAvail
			, const bool ButMatViewActive
		) : Block() {
	this->LstDtpAvail = LstDtpAvail;
	this->ButDtpViewActive = ButDtpViewActive;
	this->LstCtpAvail = LstCtpAvail;
	this->ButCtpViewActive = ButCtpViewActive;
	this->LstMatAvail = LstMatAvail;
	this->ButMatViewActive = ButMatViewActive;

	mask = {LSTDTPAVAIL, BUTDTPVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMATAVAIL, BUTMATVIEWACTIVE};
};

bool PnlPlnrNavGlobal::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNavGlobal";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDtpAvail", LstDtpAvail)) add(LSTDTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDtpViewActive", ButDtpViewActive)) add(BUTDTPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpAvail", LstCtpAvail)) add(LSTCTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtpViewActive", ButCtpViewActive)) add(BUTCTPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMatAvail", LstMatAvail)) add(LSTMATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMatViewActive", ButMatViewActive)) add(BUTMATVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrNavGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstDtpAvail == comp->LstDtpAvail) insert(items, LSTDTPAVAIL);
	if (ButDtpViewActive == comp->ButDtpViewActive) insert(items, BUTDTPVIEWACTIVE);
	if (LstCtpAvail == comp->LstCtpAvail) insert(items, LSTCTPAVAIL);
	if (ButCtpViewActive == comp->ButCtpViewActive) insert(items, BUTCTPVIEWACTIVE);
	if (LstMatAvail == comp->LstMatAvail) insert(items, LSTMATAVAIL);
	if (ButMatViewActive == comp->ButMatViewActive) insert(items, BUTMATVIEWACTIVE);

	return(items);
};

set<uint> PnlPlnrNavGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTDTPAVAIL, BUTDTPVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMATAVAIL, BUTMATVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavGlobal::Tag
 ******************************************************************************/

PnlPlnrNavGlobal::Tag::Tag(
			const string& Cpt
			, const string& CptDtp
			, const string& CptCtp
			, const string& CptMat
		) : Block() {
	this->Cpt = Cpt;
	this->CptDtp = CptDtp;
	this->CptCtp = CptCtp;
	this->CptMat = CptMat;

	mask = {CPT, CPTDTP, CPTCTP, CPTMAT};
};

bool PnlPlnrNavGlobal::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDtp", CptDtp)) add(CPTDTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtp", CptCtp)) add(CPTCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMat", CptMat)) add(CPTMAT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrNavGlobal::DpchAppData
 ******************************************************************************/

PnlPlnrNavGlobal::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrNavGlobal::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavGlobal::DpchAppDo
 ******************************************************************************/

PnlPlnrNavGlobal::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrNavGlobal::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavGlobalDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavGlobal::DpchEngData
 ******************************************************************************/

PnlPlnrNavGlobal::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVGLOBALDATA) {
	feedFLstCtp.tag = "FeedFLstCtp";
	feedFLstDtp.tag = "FeedFLstDtp";
	feedFLstMat.tag = "FeedFLstMat";
};

void PnlPlnrNavGlobal::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavGlobalData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCtp.readXML(docctx, basexpath, true)) add(FEEDFLSTCTP);
		if (feedFLstDtp.readXML(docctx, basexpath, true)) add(FEEDFLSTDTP);
		if (feedFLstMat.readXML(docctx, basexpath, true)) add(FEEDFLSTMAT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCtp.clear();
		feedFLstDtp.clear();
		feedFLstMat.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

