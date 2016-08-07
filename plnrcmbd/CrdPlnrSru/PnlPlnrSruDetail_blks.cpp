/**
  * \file PnlPlnrSruDetail_blks.cpp
  * job handler for job PnlPlnrSruDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrSruDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrSruDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;

	return(0);
};

string PnlPlnrSruDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrSruDetail::ContIac
 ******************************************************************************/

PnlPlnrSruDetail::ContIac::ContIac(
			const uint numFPupHkt
			, const string& TxfX0
			, const string& TxfX1
			, const string& TxfY0
			, const string& TxfY1
		) : Block() {
	this->numFPupHkt = numFPupHkt;
	this->TxfX0 = TxfX0;
	this->TxfX1 = TxfX1;
	this->TxfY0 = TxfY0;
	this->TxfY1 = TxfY1;

	mask = {NUMFPUPHKT, TXFX0, TXFX1, TXFY0, TXFY1};
};

bool PnlPlnrSruDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrSruDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrSruDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX0", TxfX0)) add(TXFX0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX1", TxfX1)) add(TXFX1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY0", TxfY0)) add(TXFY0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY1", TxfY1)) add(TXFY1);
	};

	return basefound;
};

void PnlPlnrSruDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfX0", TxfX0);
		writeStringAttr(wr, itemtag, "sref", "TxfX1", TxfX1);
		writeStringAttr(wr, itemtag, "sref", "TxfY0", TxfY0);
		writeStringAttr(wr, itemtag, "sref", "TxfY1", TxfY1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfX0 == comp->TxfX0) insert(items, TXFX0);
	if (TxfX1 == comp->TxfX1) insert(items, TXFX1);
	if (TxfY0 == comp->TxfY0) insert(items, TXFY0);
	if (TxfY1 == comp->TxfY1) insert(items, TXFY1);

	return(items);
};

set<uint> PnlPlnrSruDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPHKT, TXFX0, TXFX1, TXFY0, TXFY1};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::ContInf
 ******************************************************************************/

PnlPlnrSruDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;

	mask = {TXTSRF, TXTHKU};
};

void PnlPlnrSruDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);

	return(items);
};

set<uint> PnlPlnrSruDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::StatApp
 ******************************************************************************/

void PnlPlnrSruDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruDetail::StatShr
 ******************************************************************************/

PnlPlnrSruDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE};
};

void PnlPlnrSruDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);

	return(items);
};

set<uint> PnlPlnrSruDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruDetail::Tag
 ******************************************************************************/

void PnlPlnrSruDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrSruDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrSruDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptX0", "lowest x coordinate [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptX1", "highest x coordinate [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptY0", "lowest y coordinate [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptY1", "highest y coordinate [\\u03bcm]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruDetail::DpchAppData
 ******************************************************************************/

PnlPlnrSruDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDATA) {
};

void PnlPlnrSruDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrSruDetailData");
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
 class PnlPlnrSruDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrSruDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrSruDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrSruDetailDo");
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
 class PnlPlnrSruDetail::DpchEngData
 ******************************************************************************/

PnlPlnrSruDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupHkt
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSRUDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPHKT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrSruDetail::DpchEngData::merge(
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

void PnlPlnrSruDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrSruDetailData");
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


