/**
  * \file PnlPlnrNavPre_blks.cpp
  * job handler for job PnlPlnrNavPre (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavPre::VecVDo
 ******************************************************************************/

uint PnlPlnrNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdsnremoveclick") return BUTDSNREMOVECLICK;
	else if (s == "butprjremoveclick") return BUTPRJREMOVECLICK;

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

void PnlPlnrNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);

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

void PnlPlnrNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtDsnAvail", TxtDsnAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrjAvail", TxtPrjAvail);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrNavPre::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "project");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavPre::DpchAppDo
 ******************************************************************************/

PnlPlnrNavPre::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVPREDO) {
	ixVDo = 0;
};

void PnlPlnrNavPre::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavPreDo");
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
 class PnlPlnrNavPre::DpchEngData
 ******************************************************************************/

PnlPlnrNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVPREDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavPre::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavPre::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


