/**
  * \file CrdPlnrDsn_blks.cpp
  * job handler for job CrdPlnrDsn (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class CrdPlnrDsn::VecVDo
 ******************************************************************************/

uint CrdPlnrDsn::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitcrdgplclick") return MITCRDGPLCLICK;

	return(0);
};

string CrdPlnrDsn::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITCRDGPLCLICK) return("MitCrdGplClick");

	return("");
};

/******************************************************************************
 class CrdPlnrDsn::VecVSge
 ******************************************************************************/

uint CrdPlnrDsn::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrplnrabt") return ALRPLNRABT;
	else if (s == "close") return CLOSE;

	return(0);
};

string CrdPlnrDsn::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

void CrdPlnrDsn::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdPlnrDsn::ContInf
 ******************************************************************************/

CrdPlnrDsn::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdDsn
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdDsn = MtxCrdDsn;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDDSN};
};

void CrdPlnrDsn::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDsn";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDsn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdDsn", MtxCrdDsn);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrDsn::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdDsn == comp->MtxCrdDsn) insert(items, MTXCRDDSN);

	return(items);
};

set<uint> CrdPlnrDsn::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrDsn::StatApp
 ******************************************************************************/

void CrdPlnrDsn::StatApp::writeXML(
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
	if (difftag.length() == 0) difftag = "StatAppPlnrDsn";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDsn";

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
 class CrdPlnrDsn::StatShr
 ******************************************************************************/

CrdPlnrDsn::StatShr::StatShr(
			const ubigint jrefDlggenplt
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MitCrdGplAvail
			, const bool MitCrdGplActive
		) : Block() {
	this->jrefDlggenplt = jrefDlggenplt;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MitCrdGplAvail = MitCrdGplAvail;
	this->MitCrdGplActive = MitCrdGplActive;

	mask = {JREFDLGGENPLT, JREFHEADBAR, JREFLIST, JREFREC, MITCRDGPLAVAIL, MITCRDGPLACTIVE};
};

void CrdPlnrDsn::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDsn";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDsn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlggenplt", Scr::scramble(mScr, scr, descr, jrefDlggenplt));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(mScr, scr, descr, jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(mScr, scr, descr, jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGplAvail", MitCrdGplAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGplActive", MitCrdGplActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrDsn::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlggenplt == comp->jrefDlggenplt) insert(items, JREFDLGGENPLT);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MitCrdGplAvail == comp->MitCrdGplAvail) insert(items, MITCRDGPLAVAIL);
	if (MitCrdGplActive == comp->MitCrdGplActive) insert(items, MITCRDGPLACTIVE);

	return(items);
};

set<uint> CrdPlnrDsn::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGGENPLT, JREFHEADBAR, JREFLIST, JREFREC, MITCRDGPLAVAIL, MITCRDGPLACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrDsn::Tag
 ******************************************************************************/

void CrdPlnrDsn::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDsn";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDsn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdGpl", "Generate plot ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::ABOUT, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::HELP, ixPlnrVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrDsn::DpchAppDo
 ******************************************************************************/

CrdPlnrDsn::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNDO) {
	ixVDo = 0;
};

void CrdPlnrDsn::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDsnDo");
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
 class CrdPlnrDsn::DpchEngData
 ******************************************************************************/

CrdPlnrDsn::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void CrdPlnrDsn::DpchEngData::merge(
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

void CrdPlnrDsn::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDsnData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


