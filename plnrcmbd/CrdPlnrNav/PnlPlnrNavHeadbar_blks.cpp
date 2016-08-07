/**
  * \file PnlPlnrNavHeadbar_blks.cpp
  * job handler for job PnlPlnrNavHeadbar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavHeadbar::StatShr
 ******************************************************************************/

PnlPlnrNavHeadbar::StatShr::StatShr(
			const bool MenCrdAvail
		) : Block() {
	this->MenCrdAvail = MenCrdAvail;

	mask = {MENCRDAVAIL};
};

void PnlPlnrNavHeadbar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "MenCrdAvail", MenCrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavHeadbar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (MenCrdAvail == comp->MenCrdAvail) insert(items, MENCRDAVAIL);

	return(items);
};

set<uint> PnlPlnrNavHeadbar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENCRDAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavHeadbar::StgInf
 ******************************************************************************/

void PnlPlnrNavHeadbar::StgInf::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfPlnrNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfPlnrNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "70");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "204");
			writeStringAttr(wr, itemtag, "sref", "MenSesCptwidth", "66");
			writeStringAttr(wr, itemtag, "sref", "MenSesWidth", "323");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "183");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavHeadbar::Tag
 ******************************************************************************/

void PnlPlnrNavHeadbar::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Planar");
		};
		writeStringAttr(wr, itemtag, "sref", "MenSes", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::SESS, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MenCrd", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::NAV, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavHeadbar::DpchEngData
 ******************************************************************************/

PnlPlnrNavHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVHEADBARDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STATSHR, STGINF, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavHeadbar::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavHeadbar::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGINF)) StgInf::writeXML(ixPlnrVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


