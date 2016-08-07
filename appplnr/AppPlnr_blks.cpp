/**
  * \file AppPlnr_blks.cpp
  * Plnr app access library global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "AppPlnr_blks.h"

/******************************************************************************
 class ContInfPlnrAlert
 ******************************************************************************/

ContInfPlnrAlert::ContInfPlnrAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
		) : Block() {
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10};
};

bool ContInfPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;

	return true;
};

bool ContInfPlnrAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrAlert";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpt", TxtCpt)) add(TXTCPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg1", TxtMsg1)) add(TXTMSG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg2", TxtMsg2)) add(TXTMSG2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg3", TxtMsg3)) add(TXTMSG3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg4", TxtMsg4)) add(TXTMSG4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg5", TxtMsg5)) add(TXTMSG5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg6", TxtMsg6)) add(TXTMSG6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg7", TxtMsg7)) add(TXTMSG7);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg8", TxtMsg8)) add(TXTMSG8);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg9", TxtMsg9)) add(TXTMSG9);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg10", TxtMsg10)) add(TXTMSG10);
	};

	return basefound;
};

set<uint> ContInfPlnrAlert::compare(
			const ContInfPlnrAlert* comp
		) {
	set<uint> items;

	if (TxtCpt.compare(comp->TxtCpt) == 0) insert(items, TXTCPT);
	if (TxtMsg1.compare(comp->TxtMsg1) == 0) insert(items, TXTMSG1);
	if (TxtMsg2.compare(comp->TxtMsg2) == 0) insert(items, TXTMSG2);
	if (TxtMsg3.compare(comp->TxtMsg3) == 0) insert(items, TXTMSG3);
	if (TxtMsg4.compare(comp->TxtMsg4) == 0) insert(items, TXTMSG4);
	if (TxtMsg5.compare(comp->TxtMsg5) == 0) insert(items, TXTMSG5);
	if (TxtMsg6.compare(comp->TxtMsg6) == 0) insert(items, TXTMSG6);
	if (TxtMsg7.compare(comp->TxtMsg7) == 0) insert(items, TXTMSG7);
	if (TxtMsg8.compare(comp->TxtMsg8) == 0) insert(items, TXTMSG8);
	if (TxtMsg9.compare(comp->TxtMsg9) == 0) insert(items, TXTMSG9);
	if (TxtMsg10.compare(comp->TxtMsg10) == 0) insert(items, TXTMSG10);

	return(items);
};

/******************************************************************************
 class DpchPlnr
 ******************************************************************************/

DpchPlnr::DpchPlnr(
			const uint ixPlnrVDpch
		) {
	this->ixPlnrVDpch = ixPlnrVDpch;
};

DpchPlnr::~DpchPlnr() {
};

/******************************************************************************
 class DpchAppPlnr
 ******************************************************************************/

DpchAppPlnr::DpchAppPlnr(
			const uint ixPlnrVDpch
			, const string& scrJref
		) : DpchPlnr(ixPlnrVDpch) {
	this->scrJref = scrJref;

	mask = {SCRJREF};
};

DpchAppPlnr::~DpchAppPlnr() {
};

bool DpchAppPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;

	return true;
};

void DpchAppPlnr::writeXML(
			xmlTextWriter* wr
		) {
	string tag = VecPlnrVDpch::getSref(ixPlnrVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchAppPlnrAlert
 ******************************************************************************/

DpchAppPlnrAlert::DpchAppPlnrAlert(
			const string& scrJref
			, const uint numFMcb
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRALERT, scrJref) {
	this->numFMcb = numFMcb;

	if (find(mask, ALL)) this->mask = {SCRJREF, NUMFMCB};
	else this->mask = mask;
};

bool DpchAppPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

void DpchAppPlnrAlert::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(NUMFMCB)) writeUint(wr, "numFMcb", numFMcb);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchAppPlnrInit
 ******************************************************************************/

DpchAppPlnrInit::DpchAppPlnrInit(
			const string& scrJref
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRINIT, scrJref) {
};

/******************************************************************************
 class DpchAppPlnrResume
 ******************************************************************************/

DpchAppPlnrResume::DpchAppPlnrResume(
			const string& scrJref
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRESUME, scrJref) {
};

/******************************************************************************
 class DpchEngPlnr
 ******************************************************************************/

DpchEngPlnr::DpchEngPlnr(
			const uint ixPlnrVDpch
		) : DpchPlnr(ixPlnrVDpch) {
};

DpchEngPlnr::~DpchEngPlnr() {
};

bool DpchEngPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;

	return true;
};

void DpchEngPlnr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecPlnrVDpch::getSref(ixPlnrVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

/******************************************************************************
 class DpchEngPlnrAck
 ******************************************************************************/

DpchEngPlnrAck::DpchEngPlnrAck() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRACK) {
};

/******************************************************************************
 class DpchEngPlnrAlert
 ******************************************************************************/

DpchEngPlnrAlert::DpchEngPlnrAlert() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRALERT) {
};

bool DpchEngPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

void DpchEngPlnrAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFMcb.readXML(docctx, basexpath, true)) add(FEEDFMCB);
	} else {
		continf = ContInfPlnrAlert();
		feedFMcb.clear();
	};
};

/******************************************************************************
 class DpchEngPlnrConfirm
 ******************************************************************************/

DpchEngPlnrConfirm::DpchEngPlnrConfirm() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCONFIRM) {
	accepted = false;
};

bool DpchEngPlnrConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, SCRJREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

void DpchEngPlnrConfirm::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrConfirm");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractBoolUclc(docctx, basexpath, "accepted", "", accepted)) add(ACCEPTED);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "sref", "", sref)) add(SREF);
	} else {
	};
};

/******************************************************************************
 class DpchEngPlnrSuspend
 ******************************************************************************/

DpchEngPlnrSuspend::DpchEngPlnrSuspend() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSUSPEND) {
};

