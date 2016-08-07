/**
  * \file PnlPlnrDsnDetail_blks.cpp
  * job handler for job PnlPlnrDsnDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDsnDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	else if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	else if (s == "butmodviewclick") return BUTMODVIEWCLICK;
	else if (s == "butdrvviewclick") return BUTDRVVIEWCLICK;

	return(0);
};

string PnlPlnrDsnDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
	else if (ix == BUTDRVVIEWCLICK) return("ButDrvViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDsnDetail::ContIac
 ******************************************************************************/

PnlPlnrDsnDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupTyp
			, const uint numFPupDim
			, const uint numFPupRet
			, const vector<uint>& numsFLstMty
			, const string& TxfMaj
			, const string& TxfSub
			, const string& TxfCmt
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupTyp = numFPupTyp;
	this->numFPupDim = numFPupDim;
	this->numFPupRet = numFPupRet;
	this->numsFLstMty = numsFLstMty;
	this->TxfMaj = TxfMaj;
	this->TxfSub = TxfSub;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, NUMFPUPTYP, NUMFPUPDIM, NUMFPUPRET, NUMSFLSTMTY, TXFMAJ, TXFSUB, TXFCMT};
};

bool PnlPlnrDsnDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDsnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDim", numFPupDim)) add(NUMFPUPDIM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstMty", numsFLstMty)) add(NUMSFLSTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMaj", TxfMaj)) add(TXFMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSub", TxfSub)) add(TXFSUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlPlnrDsnDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupDim", numFPupDim);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstMty", numsFLstMty);
		writeStringAttr(wr, itemtag, "sref", "TxfMaj", TxfMaj);
		writeStringAttr(wr, itemtag, "sref", "TxfSub", TxfSub);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupDim == comp->numFPupDim) insert(items, NUMFPUPDIM);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (compareUintvec(numsFLstMty, comp->numsFLstMty)) insert(items, NUMSFLSTMTY);
	if (TxfMaj == comp->TxfMaj) insert(items, TXFMAJ);
	if (TxfSub == comp->TxfSub) insert(items, TXFSUB);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlPlnrDsnDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPTYP, NUMFPUPDIM, NUMFPUPRET, NUMSFLSTMTY, TXFMAJ, TXFSUB, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::ContInf
 ******************************************************************************/

PnlPlnrDsnDetail::ContInf::ContInf(
			const string& TxtReu
			, const string& TxtPrj
			, const string& TxtMty
			, const string& TxtMod
			, const string& TxtDrv
		) : Block() {
	this->TxtReu = TxtReu;
	this->TxtPrj = TxtPrj;
	this->TxtMty = TxtMty;
	this->TxtMod = TxtMod;
	this->TxtDrv = TxtDrv;

	mask = {TXTREU, TXTPRJ, TXTMTY, TXTMOD, TXTDRV};
};

void PnlPlnrDsnDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
		writeStringAttr(wr, itemtag, "sref", "TxtMty", TxtMty);
		writeStringAttr(wr, itemtag, "sref", "TxtMod", TxtMod);
		writeStringAttr(wr, itemtag, "sref", "TxtDrv", TxtDrv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);
	if (TxtMty == comp->TxtMty) insert(items, TXTMTY);
	if (TxtMod == comp->TxtMod) insert(items, TXTMOD);
	if (TxtDrv == comp->TxtDrv) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlPlnrDsnDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREU, TXTPRJ, TXTMTY, TXTMOD, TXTDRV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::StatApp
 ******************************************************************************/

void PnlPlnrDsnDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool LstMtyAlt
			, const uint LstMtyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstMtyAlt", LstMtyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstMtyNumFirstdisp", LstMtyNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnDetail::StatShr
 ******************************************************************************/

PnlPlnrDsnDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPrjViewAvail
			, const bool ButModViewAvail
			, const bool ButDrvViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButModViewAvail = ButModViewAvail;
	this->ButDrvViewAvail = ButDrvViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTMODVIEWAVAIL, BUTDRVVIEWAVAIL};
};

void PnlPlnrDsnDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewAvail", ButPrjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButModViewAvail", ButModViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDrvViewAvail", ButDrvViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButModViewAvail == comp->ButModViewAvail) insert(items, BUTMODVIEWAVAIL);
	if (ButDrvViewAvail == comp->ButDrvViewAvail) insert(items, BUTDRVVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDsnDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTMODVIEWAVAIL, BUTDRVVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::Tag
 ******************************************************************************/

void PnlPlnrDsnDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptDim", "dimensionality");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "project");
			writeStringAttr(wr, itemtag, "sref", "CptMty", "modification types");
			writeStringAttr(wr, itemtag, "sref", "CptMod", "parent design");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "design derived from");
			writeStringAttr(wr, itemtag, "sref", "CptMaj", "major version number");
			writeStringAttr(wr, itemtag, "sref", "CptSub", "sub version number");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDsnDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDATA) {
};

void PnlPlnrDsnDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDsnDetailData");
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
 class PnlPlnrDsnDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrDsnDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDsnDetailDo");
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
 class PnlPlnrDsnDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDsnDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstMty
			, Feed* feedFPupDim
			, Feed* feedFPupRet
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTMTY, FEEDFPUPDIM, FEEDFPUPRET, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTMTY) && feedFLstMty) this->feedFLstMty = *feedFLstMty;
	if (find(this->mask, FEEDFPUPDIM) && feedFPupDim) this->feedFPupDim = *feedFPupDim;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDsnDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTMTY)) {feedFLstMty = src->feedFLstMty; add(FEEDFLSTMTY);};
	if (src->has(FEEDFPUPDIM)) {feedFPupDim = src->feedFPupDim; add(FEEDFPUPDIM);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDsnDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDsnDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTMTY)) feedFLstMty.writeXML(wr);
		if (has(FEEDFPUPDIM)) feedFPupDim.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


