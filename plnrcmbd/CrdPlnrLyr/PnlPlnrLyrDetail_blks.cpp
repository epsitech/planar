/**
  * \file PnlPlnrLyrDetail_blks.cpp
  * job handler for job PnlPlnrLyrDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrLyrDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrLyrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	else if (s == "butmatviewclick") return BUTMATVIEWCLICK;

	return(0);
};

string PnlPlnrLyrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	else if (ix == BUTMATVIEWCLICK) return("ButMatViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrLyrDetail::ContIac
 ******************************************************************************/

PnlPlnrLyrDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupHkt
			, const uint numFPupTty
			, const string& TxfT
			, const string& TxfMl
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFPupHkt = numFPupHkt;
	this->numFPupTty = numFPupTty;
	this->TxfT = TxfT;
	this->TxfMl = TxfMl;

	mask = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTTY, TXFT, TXFML};
};

bool PnlPlnrLyrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrLyrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrLyrDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTty", numFPupTty)) add(NUMFPUPTTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfT", TxfT)) add(TXFT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMl", TxfMl)) add(TXFML);
	};

	return basefound;
};

void PnlPlnrLyrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeUintAttr(wr, itemtag, "sref", "numFPupTty", numFPupTty);
		writeStringAttr(wr, itemtag, "sref", "TxfT", TxfT);
		writeStringAttr(wr, itemtag, "sref", "TxfMl", TxfMl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupTty == comp->numFPupTty) insert(items, NUMFPUPTTY);
	if (TxfT == comp->TxfT) insert(items, TXFT);
	if (TxfMl == comp->TxfMl) insert(items, TXFML);

	return(items);
};

set<uint> PnlPlnrLyrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTTY, TXFT, TXFML};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::ContInf
 ******************************************************************************/

PnlPlnrLyrDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
			, const string& TxtMat
			, const string& TxtFlr
			, const string& TxtCtr
			, const string& TxtCei
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtMat = TxtMat;
	this->TxtFlr = TxtFlr;
	this->TxtCtr = TxtCtr;
	this->TxtCei = TxtCei;

	mask = {TXTSRF, TXTHKU, TXTMAT, TXTFLR, TXTCTR, TXTCEI};
};

void PnlPlnrLyrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
		writeStringAttr(wr, itemtag, "sref", "TxtMat", TxtMat);
		writeStringAttr(wr, itemtag, "sref", "TxtFlr", TxtFlr);
		writeStringAttr(wr, itemtag, "sref", "TxtCtr", TxtCtr);
		writeStringAttr(wr, itemtag, "sref", "TxtCei", TxtCei);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);
	if (TxtMat == comp->TxtMat) insert(items, TXTMAT);
	if (TxtFlr == comp->TxtFlr) insert(items, TXTFLR);
	if (TxtCtr == comp->TxtCtr) insert(items, TXTCTR);
	if (TxtCei == comp->TxtCei) insert(items, TXTCEI);

	return(items);
};

set<uint> PnlPlnrLyrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTMAT, TXTFLR, TXTCTR, TXTCEI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::StatApp
 ******************************************************************************/

void PnlPlnrLyrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrDetail::StatShr
 ******************************************************************************/

PnlPlnrLyrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButMatViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButMatViewAvail = ButMatViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTMATVIEWAVAIL};
};

void PnlPlnrLyrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMatViewAvail", ButMatViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButMatViewAvail == comp->ButMatViewAvail) insert(items, BUTMATVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrLyrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTMATVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrDetail::Tag
 ******************************************************************************/

void PnlPlnrLyrDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrLyrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrLyrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptMat", "material");
			writeStringAttr(wr, itemtag, "sref", "CptTty", "thickness type");
			writeStringAttr(wr, itemtag, "sref", "CptFlr", "floor level");
			writeStringAttr(wr, itemtag, "sref", "CptCtr", "center level");
			writeStringAttr(wr, itemtag, "sref", "CptCei", "ceiling level");
			writeStringAttr(wr, itemtag, "sref", "CptT", "thickness [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptMl", "number of monolayers");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrDetail::DpchAppData
 ******************************************************************************/

PnlPlnrLyrDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDATA) {
};

void PnlPlnrLyrDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrLyrDetailData");
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
 class PnlPlnrLyrDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrLyrDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrLyrDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrLyrDetailDo");
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
 class PnlPlnrLyrDetail::DpchEngData
 ******************************************************************************/

PnlPlnrLyrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupHkt
			, Feed* feedFPupTty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRLYRDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPHKT, FEEDFPUPTTY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, FEEDFPUPTTY) && feedFPupTty) this->feedFPupTty = *feedFPupTty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrLyrDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPHKT)) {feedFPupHkt = src->feedFPupHkt; add(FEEDFPUPHKT);};
	if (src->has(FEEDFPUPTTY)) {feedFPupTty = src->feedFPupTty; add(FEEDFPUPTTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrLyrDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrLyrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPHKT)) feedFPupHkt.writeXML(wr);
		if (has(FEEDFPUPTTY)) feedFPupTty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


