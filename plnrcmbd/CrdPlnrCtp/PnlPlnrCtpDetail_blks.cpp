/**
  * \file PnlPlnrCtpDetail_blks.cpp
  * job handler for job PnlPlnrCtpDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrCtpDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrCtpDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrCtpDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrCtpDetail::ContIac
 ******************************************************************************/

PnlPlnrCtpDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupDim
			, const string& TxfSta
			, const string& TxfCmt
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupDim = numFPupDim;
	this->TxfSta = TxfSta;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, NUMFPUPDIM, TXFSTA, TXFCMT};
};

bool PnlPlnrCtpDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrCtpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrCtpDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDim", numFPupDim)) add(NUMFPUPDIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlPlnrCtpDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrCtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrCtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupDim", numFPupDim);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupDim == comp->numFPupDim) insert(items, NUMFPUPDIM);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlPlnrCtpDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPDIM, TXFSTA, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpDetail::ContInf
 ******************************************************************************/

PnlPlnrCtpDetail::ContInf::ContInf(
			const string& TxtPrj
			, const string& TxtTpl
			, const string& TxtSup
			, const string& TxtDsn
		) : Block() {
	this->TxtPrj = TxtPrj;
	this->TxtTpl = TxtTpl;
	this->TxtSup = TxtSup;
	this->TxtDsn = TxtDsn;

	mask = {TXTPRJ, TXTTPL, TXTSUP, TXTDSN};
};

void PnlPlnrCtpDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrCtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrCtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
		writeStringAttr(wr, itemtag, "sref", "TxtTpl", TxtTpl);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);
	if (TxtTpl == comp->TxtTpl) insert(items, TXTTPL);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);

	return(items);
};

set<uint> PnlPlnrCtpDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRJ, TXTTPL, TXTSUP, TXTDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpDetail::StatApp
 ******************************************************************************/

void PnlPlnrCtpDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrCtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrCtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpDetail::StatShr
 ******************************************************************************/

PnlPlnrCtpDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPrjViewAvail
			, const bool ButDsnViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTDSNVIEWAVAIL};
};

void PnlPlnrCtpDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrCtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrCtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewAvail", ButPrjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrCtpDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpDetail::Tag
 ******************************************************************************/

void PnlPlnrCtpDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrCtpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrCtpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "project");
			writeStringAttr(wr, itemtag, "sref", "CptDim", "dimensionality");
			writeStringAttr(wr, itemtag, "sref", "CptTpl", "template");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super calculation");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "start time");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpDetail::DpchAppData
 ******************************************************************************/

PnlPlnrCtpDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPDETAILDATA) {
};

void PnlPlnrCtpDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpDetailData");
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
 class PnlPlnrCtpDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrCtpDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrCtpDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpDetailDo");
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
 class PnlPlnrCtpDetail::DpchEngData
 ******************************************************************************/

PnlPlnrCtpDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupDim
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCTPDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPDIM, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPDIM) && feedFPupDim) this->feedFPupDim = *feedFPupDim;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrCtpDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPDIM)) {feedFPupDim = src->feedFPupDim; add(FEEDFPUPDIM);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrCtpDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrCtpDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPDIM)) feedFPupDim.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


