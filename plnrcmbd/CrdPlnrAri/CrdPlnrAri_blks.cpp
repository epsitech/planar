/**
  * \file CrdPlnrAri_blks.cpp
  * job handler for job CrdPlnrAri (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class CrdPlnrAri::VecVDo
 ******************************************************************************/

uint CrdPlnrAri::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdPlnrAri::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdPlnrAri::VecVSge
 ******************************************************************************/

uint CrdPlnrAri::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrplnrabt") return ALRPLNRABT;
	else if (s == "close") return CLOSE;

	return(0);
};

string CrdPlnrAri::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

void CrdPlnrAri::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdPlnrAri::ContInf
 ******************************************************************************/

CrdPlnrAri::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdAri
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdAri = MtxCrdAri;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDARI};
};

void CrdPlnrAri::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrAri";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrAri";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdAri", MtxCrdAri);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrAri::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdAri == comp->MtxCrdAri) insert(items, MTXCRDARI);

	return(items);
};

set<uint> CrdPlnrAri::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDARI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrAri::StatApp
 ******************************************************************************/

void CrdPlnrAri::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrAri";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrAri";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVReqitmode", VecPlnrVReqitmode::getSref(ixPlnrVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrAri::StatShr
 ******************************************************************************/

CrdPlnrAri::StatShr::StatShr(
			const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
		) : Block() {
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;

	mask = {JREFHEADBAR, JREFLIST, JREFREC};
};

void CrdPlnrAri::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrAri";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrAri";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(mScr, scr, descr, jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(mScr, scr, descr, jrefRec));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrAri::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);

	return(items);
};

set<uint> CrdPlnrAri::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFHEADBAR, JREFLIST, JREFREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrAri::Tag
 ******************************************************************************/

void CrdPlnrAri::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrAri";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrAri";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::ABOUT, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::HELP, ixPlnrVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrAri::DpchAppDo
 ******************************************************************************/

CrdPlnrAri::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARIDO) {
	ixVDo = 0;
};

void CrdPlnrAri::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAriDo");
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
 class CrdPlnrAri::DpchEngData
 ******************************************************************************/

CrdPlnrAri::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARIDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void CrdPlnrAri::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdPlnrAri::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrAriData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


