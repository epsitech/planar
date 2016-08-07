/**
  * \file PnlPlnrRtcDetail_blks.cpp
  * job handler for job PnlPlnrRtcDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrRtcDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrRtcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;
	else if (s == "butlyrviewclick") return BUTLYRVIEWCLICK;

	return(0);
};

string PnlPlnrRtcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");
	else if (ix == BUTLYRVIEWCLICK) return("ButLyrViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrRtcDetail::ContIac
 ******************************************************************************/

PnlPlnrRtcDetail::ContIac::ContIac(
			const uint numFPupHkt
			, const string& TxfX0
			, const string& TxfY0
			, const string& TxfPhi
		) : Block() {
	this->numFPupHkt = numFPupHkt;
	this->TxfX0 = TxfX0;
	this->TxfY0 = TxfY0;
	this->TxfPhi = TxfPhi;

	mask = {NUMFPUPHKT, TXFX0, TXFY0, TXFPHI};
};

bool PnlPlnrRtcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrRtcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrRtcDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX0", TxfX0)) add(TXFX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY0", TxfY0)) add(TXFY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPhi", TxfPhi)) add(TXFPHI);
	};

	return basefound;
};

void PnlPlnrRtcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfX0", TxfX0);
		writeStringAttr(wr, itemtag, "sref", "TxfY0", TxfY0);
		writeStringAttr(wr, itemtag, "sref", "TxfPhi", TxfPhi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrRtcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfX0 == comp->TxfX0) insert(items, TXFX0);
	if (TxfY0 == comp->TxfY0) insert(items, TXFY0);
	if (TxfPhi == comp->TxfPhi) insert(items, TXFPHI);

	return(items);
};

set<uint> PnlPlnrRtcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPHKT, TXFX0, TXFY0, TXFPHI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::ContInf
 ******************************************************************************/

PnlPlnrRtcDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
			, const string& TxtDsn
			, const string& TxtLyr
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtDsn = TxtDsn;
	this->TxtLyr = TxtLyr;

	mask = {TXTSRF, TXTHKU, TXTDSN, TXTLYR};
};

void PnlPlnrRtcDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtLyr", TxtLyr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrRtcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtLyr == comp->TxtLyr) insert(items, TXTLYR);

	return(items);
};

set<uint> PnlPlnrRtcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTDSN, TXTLYR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::StatApp
 ******************************************************************************/

void PnlPlnrRtcDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrRtcDetail::StatShr
 ******************************************************************************/

PnlPlnrRtcDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
			, const bool ButLyrViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;
	this->ButLyrViewAvail = ButLyrViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL};
};

void PnlPlnrRtcDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLyrViewAvail", ButLyrViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrRtcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);
	if (ButLyrViewAvail == comp->ButLyrViewAvail) insert(items, BUTLYRVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrRtcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrRtcDetail::Tag
 ******************************************************************************/

void PnlPlnrRtcDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrRtcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrRtcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptLyr", "layer");
			writeStringAttr(wr, itemtag, "sref", "CptX0", "x offset [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptY0", "y offset [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "rotation angle [\\u00b0]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrRtcDetail::DpchAppData
 ******************************************************************************/

PnlPlnrRtcDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDATA) {
};

void PnlPlnrRtcDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrRtcDetailData");
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
 class PnlPlnrRtcDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrRtcDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrRtcDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrRtcDetailDo");
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
 class PnlPlnrRtcDetail::DpchEngData
 ******************************************************************************/

PnlPlnrRtcDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupHkt
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRRTCDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPHKT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrRtcDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPHKT)) {feedFPupHkt = src->feedFPupHkt; add(FEEDFPUPHKT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrRtcDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrRtcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPHKT)) feedFPupHkt.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


