/**
  * \file PnlPlnrNavPre.cpp
  * app access code for job PnlPlnrNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrNavPre.h"

/******************************************************************************
 class PnlPlnrNavPre::VecVDo
 ******************************************************************************/

uint PnlPlnrNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdsnremoveclick") == 0) return BUTDSNREMOVECLICK;
	else if (s.compare("butprjremoveclick") == 0) return BUTPRJREMOVECLICK;

	return(0);
};

string PnlPlnrNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDSNREMOVECLICK) return("ButDsnRemoveClick");
	else if (ix == BUTPRJREMOVECLICK) return("ButPrjRemoveClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavPre::ContInf
 ******************************************************************************/

PnlPlnrNavPre::ContInf::ContInf(
			const string& TxtDsn
			, const string& TxtPrj
		) : Block() {
	this->TxtDsn = TxtDsn;
	this->TxtPrj = TxtPrj;

	mask = {TXTDSN, TXTPRJ};
};

bool PnlPlnrNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDsn", TxtDsn)) add(TXTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrj", TxtPrj)) add(TXTPRJ);
	};

	return basefound;
};

set<uint> PnlPlnrNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtDsn.compare(comp->TxtDsn) == 0) insert(items, TXTDSN);
	if (TxtPrj.compare(comp->TxtPrj) == 0) insert(items, TXTPRJ);

	return(items);
};

set<uint> PnlPlnrNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDSN, TXTPRJ};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavPre::StatShr
 ******************************************************************************/

PnlPlnrNavPre::StatShr::StatShr(
			const bool TxtDsnAvail
			, const bool TxtPrjAvail
		) : Block() {
	this->TxtDsnAvail = TxtDsnAvail;
	this->TxtPrjAvail = TxtPrjAvail;

	mask = {TXTDSNAVAIL, TXTPRJAVAIL};
};

bool PnlPlnrNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtDsnAvail", TxtDsnAvail)) add(TXTDSNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrjAvail", TxtPrjAvail)) add(TXTPRJAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtDsnAvail == comp->TxtDsnAvail) insert(items, TXTDSNAVAIL);
	if (TxtPrjAvail == comp->TxtPrjAvail) insert(items, TXTPRJAVAIL);

	return(items);
};

set<uint> PnlPlnrNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDSNAVAIL, TXTPRJAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavPre::Tag
 ******************************************************************************/

PnlPlnrNavPre::Tag::Tag(
			const string& CptDsn
			, const string& CptPrj
		) : Block() {
	this->CptDsn = CptDsn;
	this->CptPrj = CptPrj;

	mask = {CPTDSN, CPTPRJ};
};

bool PnlPlnrNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrNavPre::DpchAppDo
 ******************************************************************************/

PnlPlnrNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVPREDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavPre::DpchEngData
 ******************************************************************************/

PnlPlnrNavPre::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVPREDATA) {
};

void PnlPlnrNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

