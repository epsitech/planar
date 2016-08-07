/**
  * \file PnlPlnrAriDetail_blks.cpp
  * job handler for job PnlPlnrAriDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrAriDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrAriDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butarrviewclick") return BUTARRVIEWCLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrAriDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTARRVIEWCLICK) return("ButArrViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrAriDetail::ContIac
 ******************************************************************************/

PnlPlnrAriDetail::ContIac::ContIac(
			const string& TxfI
			, const string& TxfJ
			, const string& TxfK
			, const string& TxfL
			, const string& TxfM
			, const string& TxfN
			, const string& TxfDx
			, const string& TxfDy
		) : Block() {
	this->TxfI = TxfI;
	this->TxfJ = TxfJ;
	this->TxfK = TxfK;
	this->TxfL = TxfL;
	this->TxfM = TxfM;
	this->TxfN = TxfN;
	this->TxfDx = TxfDx;
	this->TxfDy = TxfDy;

	mask = {TXFI, TXFJ, TXFK, TXFL, TXFM, TXFN, TXFDX, TXFDY};
};

bool PnlPlnrAriDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrAriDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrAriDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfI", TxfI)) add(TXFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfJ", TxfJ)) add(TXFJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfK", TxfK)) add(TXFK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfL", TxfL)) add(TXFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfM", TxfM)) add(TXFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDx", TxfDx)) add(TXFDX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDy", TxfDy)) add(TXFDY);
	};

	return basefound;
};

void PnlPlnrAriDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfI", TxfI);
		writeStringAttr(wr, itemtag, "sref", "TxfJ", TxfJ);
		writeStringAttr(wr, itemtag, "sref", "TxfK", TxfK);
		writeStringAttr(wr, itemtag, "sref", "TxfL", TxfL);
		writeStringAttr(wr, itemtag, "sref", "TxfM", TxfM);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
		writeStringAttr(wr, itemtag, "sref", "TxfDx", TxfDx);
		writeStringAttr(wr, itemtag, "sref", "TxfDy", TxfDy);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfI == comp->TxfI) insert(items, TXFI);
	if (TxfJ == comp->TxfJ) insert(items, TXFJ);
	if (TxfK == comp->TxfK) insert(items, TXFK);
	if (TxfL == comp->TxfL) insert(items, TXFL);
	if (TxfM == comp->TxfM) insert(items, TXFM);
	if (TxfN == comp->TxfN) insert(items, TXFN);
	if (TxfDx == comp->TxfDx) insert(items, TXFDX);
	if (TxfDy == comp->TxfDy) insert(items, TXFDY);

	return(items);
};

set<uint> PnlPlnrAriDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFI, TXFJ, TXFK, TXFL, TXFM, TXFN, TXFDX, TXFDY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::ContInf
 ******************************************************************************/

PnlPlnrAriDetail::ContInf::ContInf(
			const string& TxtArr
			, const string& TxtDsn
		) : Block() {
	this->TxtArr = TxtArr;
	this->TxtDsn = TxtDsn;

	mask = {TXTARR, TXTDSN};
};

void PnlPlnrAriDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtArr", TxtArr);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtArr == comp->TxtArr) insert(items, TXTARR);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);

	return(items);
};

set<uint> PnlPlnrAriDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTARR, TXTDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::StatApp
 ******************************************************************************/

void PnlPlnrAriDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriDetail::StatShr
 ******************************************************************************/

PnlPlnrAriDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButArrViewAvail
			, const bool ButDsnViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButArrViewAvail = ButArrViewAvail;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTARRVIEWAVAIL, BUTDSNVIEWAVAIL};
};

void PnlPlnrAriDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButArrViewAvail", ButArrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButArrViewAvail == comp->ButArrViewAvail) insert(items, BUTARRVIEWAVAIL);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrAriDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTARRVIEWAVAIL, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriDetail::Tag
 ******************************************************************************/

void PnlPlnrAriDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrAriDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrAriDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptI", "i");
			writeStringAttr(wr, itemtag, "sref", "CptJ", "j");
			writeStringAttr(wr, itemtag, "sref", "CptK", "k");
			writeStringAttr(wr, itemtag, "sref", "CptL", "l");
			writeStringAttr(wr, itemtag, "sref", "CptM", "m");
			writeStringAttr(wr, itemtag, "sref", "CptN", "n");
			writeStringAttr(wr, itemtag, "sref", "CptArr", "array");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptDx", "dx [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDy", "dy [\\u03bcm]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriDetail::DpchAppData
 ******************************************************************************/

PnlPlnrAriDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARIDETAILDATA) {
};

void PnlPlnrAriDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAriDetailData");
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
 class PnlPlnrAriDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrAriDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARIDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrAriDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAriDetailDo");
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
 class PnlPlnrAriDetail::DpchEngData
 ******************************************************************************/

PnlPlnrAriDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARIDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrAriDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrAriDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrAriDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


