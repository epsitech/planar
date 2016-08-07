/**
  * \file CrdPlnrClc_blks.cpp
  * job handler for job CrdPlnrClc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class CrdPlnrClc::VecVDo
 ******************************************************************************/

uint CrdPlnrClc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitcrducsclick") return MITCRDUCSCLICK;
	else if (s == "mitcrdgpvclick") return MITCRDGPVCLICK;
	else if (s == "mitcrdetxclick") return MITCRDETXCLICK;

	return(0);
};

string CrdPlnrClc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITCRDUCSCLICK) return("MitCrdUcsClick");
	else if (ix == MITCRDGPVCLICK) return("MitCrdGpvClick");
	else if (ix == MITCRDETXCLICK) return("MitCrdEtxClick");

	return("");
};

/******************************************************************************
 class CrdPlnrClc::VecVSge
 ******************************************************************************/

uint CrdPlnrClc::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrplnrabt") return ALRPLNRABT;
	else if (s == "close") return CLOSE;

	return(0);
};

string CrdPlnrClc::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

void CrdPlnrClc::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdPlnrClc::ContInf
 ******************************************************************************/

CrdPlnrClc::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdClc
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdClc = MtxCrdClc;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDCLC};
};

void CrdPlnrClc::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrClc";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrClc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdClc", MtxCrdClc);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrClc::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdClc == comp->MtxCrdClc) insert(items, MTXCRDCLC);

	return(items);
};

set<uint> CrdPlnrClc::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDCLC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrClc::StatApp
 ******************************************************************************/

void CrdPlnrClc::StatApp::writeXML(
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
	if (difftag.length() == 0) difftag = "StatAppPlnrClc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrClc";

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
 class CrdPlnrClc::StatShr
 ******************************************************************************/

CrdPlnrClc::StatShr::StatShr(
			const ubigint jrefDlgexprtx
			, const ubigint jrefDlggenrpv
			, const ubigint jrefDlgusecase
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdUcsAvail
			, const bool MitCrdGpvAvail
			, const bool MitCrdGpvActive
			, const bool MitCrdEtxAvail
			, const bool MitCrdEtxActive
		) : Block() {
	this->jrefDlgexprtx = jrefDlgexprtx;
	this->jrefDlggenrpv = jrefDlggenrpv;
	this->jrefDlgusecase = jrefDlgusecase;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUcsAvail = MitCrdUcsAvail;
	this->MitCrdGpvAvail = MitCrdGpvAvail;
	this->MitCrdGpvActive = MitCrdGpvActive;
	this->MitCrdEtxAvail = MitCrdEtxAvail;
	this->MitCrdEtxActive = MitCrdEtxActive;

	mask = {JREFDLGEXPRTX, JREFDLGGENRPV, JREFDLGUSECASE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDUCSAVAIL, MITCRDGPVAVAIL, MITCRDGPVACTIVE, MITCRDETXAVAIL, MITCRDETXACTIVE};
};

void CrdPlnrClc::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrClc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrClc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgexprtx", Scr::scramble(mScr, scr, descr, jrefDlgexprtx));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlggenrpv", Scr::scramble(mScr, scr, descr, jrefDlggenrpv));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgusecase", Scr::scramble(mScr, scr, descr, jrefDlgusecase));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(mScr, scr, descr, jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(mScr, scr, descr, jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUcsAvail", MitCrdUcsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGpvAvail", MitCrdGpvAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGpvActive", MitCrdGpvActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEtxAvail", MitCrdEtxAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEtxActive", MitCrdEtxActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrClc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgexprtx == comp->jrefDlgexprtx) insert(items, JREFDLGEXPRTX);
	if (jrefDlggenrpv == comp->jrefDlggenrpv) insert(items, JREFDLGGENRPV);
	if (jrefDlgusecase == comp->jrefDlgusecase) insert(items, JREFDLGUSECASE);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUcsAvail == comp->MitCrdUcsAvail) insert(items, MITCRDUCSAVAIL);
	if (MitCrdGpvAvail == comp->MitCrdGpvAvail) insert(items, MITCRDGPVAVAIL);
	if (MitCrdGpvActive == comp->MitCrdGpvActive) insert(items, MITCRDGPVACTIVE);
	if (MitCrdEtxAvail == comp->MitCrdEtxAvail) insert(items, MITCRDETXAVAIL);
	if (MitCrdEtxActive == comp->MitCrdEtxActive) insert(items, MITCRDETXACTIVE);

	return(items);
};

set<uint> CrdPlnrClc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGEXPRTX, JREFDLGGENRPV, JREFDLGUSECASE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDUCSAVAIL, MITCRDGPVAVAIL, MITCRDGPVACTIVE, MITCRDETXAVAIL, MITCRDETXACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrClc::Tag
 ******************************************************************************/

void CrdPlnrClc::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrClc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrClc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUcs", "Run use case ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdGpv", "Generate result data plot or video ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdEtx", "Export result data as text ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::ABOUT, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::HELP, ixPlnrVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrClc::DpchAppDo
 ******************************************************************************/

CrdPlnrClc::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLCDO) {
	ixVDo = 0;
};

void CrdPlnrClc::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrClcDo");
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
 class CrdPlnrClc::DpchEngData
 ******************************************************************************/

CrdPlnrClc::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLCDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void CrdPlnrClc::DpchEngData::merge(
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

void CrdPlnrClc::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrClcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


