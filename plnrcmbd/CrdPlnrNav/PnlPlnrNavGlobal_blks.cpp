/**
  * \file PnlPlnrNavGlobal_blks.cpp
  * job handler for job PnlPlnrNavGlobal (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavGlobal::VecVDo
 ******************************************************************************/

uint PnlPlnrNavGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdtpviewclick") return BUTDTPVIEWCLICK;
	else if (s == "butdtpnewcrdclick") return BUTDTPNEWCRDCLICK;
	else if (s == "butctpviewclick") return BUTCTPVIEWCLICK;
	else if (s == "butctpnewcrdclick") return BUTCTPNEWCRDCLICK;
	else if (s == "butmatviewclick") return BUTMATVIEWCLICK;
	else if (s == "butmatnewcrdclick") return BUTMATNEWCRDCLICK;

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

void PnlPlnrNavGlobal::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool LstDtpAlt
			, const bool LstCtpAlt
			, const bool LstMatAlt
			, const uint LstDtpNumFirstdisp
			, const uint LstCtpNumFirstdisp
			, const uint LstMatNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstDtpAlt", LstDtpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCtpAlt", LstCtpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMatAlt", LstMatAlt);
		writeUintAttr(wr, itemtag, "sref", "LstDtpNumFirstdisp", LstDtpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCtpNumFirstdisp", LstCtpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMatNumFirstdisp", LstMatNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrNavGlobal::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstDtpAvail", LstDtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDtpViewActive", ButDtpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCtpAvail", LstCtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtpViewActive", ButCtpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMatAvail", LstMatAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMatViewActive", ButMatViewActive);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrNavGlobal::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Global data module");
			writeStringAttr(wr, itemtag, "sref", "CptDtp", "device templates");
			writeStringAttr(wr, itemtag, "sref", "CptCtp", "calculation templates");
			writeStringAttr(wr, itemtag, "sref", "CptMat", "materials");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavGlobal::DpchAppData
 ******************************************************************************/

PnlPlnrNavGlobal::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDATA) {
};

void PnlPlnrNavGlobal::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavGlobalData");
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
 class PnlPlnrNavGlobal::DpchAppDo
 ******************************************************************************/

PnlPlnrNavGlobal::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDO) {
	ixVDo = 0;
};

void PnlPlnrNavGlobal::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavGlobalDo");
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
 class PnlPlnrNavGlobal::DpchEngData
 ******************************************************************************/

PnlPlnrNavGlobal::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCtp
			, Feed* feedFLstDtp
			, Feed* feedFLstMat
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVGLOBALDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCTP, FEEDFLSTDTP, FEEDFLSTMAT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCTP) && feedFLstCtp) this->feedFLstCtp = *feedFLstCtp;
	if (find(this->mask, FEEDFLSTDTP) && feedFLstDtp) this->feedFLstDtp = *feedFLstDtp;
	if (find(this->mask, FEEDFLSTMAT) && feedFLstMat) this->feedFLstMat = *feedFLstMat;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavGlobal::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCTP)) {feedFLstCtp = src->feedFLstCtp; add(FEEDFLSTCTP);};
	if (src->has(FEEDFLSTDTP)) {feedFLstDtp = src->feedFLstDtp; add(FEEDFLSTDTP);};
	if (src->has(FEEDFLSTMAT)) {feedFLstMat = src->feedFLstMat; add(FEEDFLSTMAT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavGlobal::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCTP)) feedFLstCtp.writeXML(wr);
		if (has(FEEDFLSTDTP)) feedFLstDtp.writeXML(wr);
		if (has(FEEDFLSTMAT)) feedFLstMat.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


