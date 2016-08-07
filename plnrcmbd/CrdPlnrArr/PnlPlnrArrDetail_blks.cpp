/**
  * \file PnlPlnrArrDetail_blks.cpp
  * job handler for job PnlPlnrArrDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrArrDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrArrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buttpoviewclick") return BUTTPOVIEWCLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrArrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTTPOVIEWCLICK) return("ButTpoViewClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrArrDetail::ContIac
 ******************************************************************************/

PnlPlnrArrDetail::ContIac::ContIac(
			const string& TxfI
			, const string& TxfJ
			, const string& TxfDi
			, const string& TxfDj
			, const string& TxfK
			, const string& TxfL
			, const string& TxfDk
			, const string& TxfDl
			, const string& TxfM
			, const string& TxfN
			, const string& TxfDm
			, const string& TxfDn
		) : Block() {
	this->TxfI = TxfI;
	this->TxfJ = TxfJ;
	this->TxfDi = TxfDi;
	this->TxfDj = TxfDj;
	this->TxfK = TxfK;
	this->TxfL = TxfL;
	this->TxfDk = TxfDk;
	this->TxfDl = TxfDl;
	this->TxfM = TxfM;
	this->TxfN = TxfN;
	this->TxfDm = TxfDm;
	this->TxfDn = TxfDn;

	mask = {TXFI, TXFJ, TXFDI, TXFDJ, TXFK, TXFL, TXFDK, TXFDL, TXFM, TXFN, TXFDM, TXFDN};
};

bool PnlPlnrArrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrArrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrArrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfI", TxfI)) add(TXFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfJ", TxfJ)) add(TXFJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDi", TxfDi)) add(TXFDI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDj", TxfDj)) add(TXFDJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfK", TxfK)) add(TXFK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfL", TxfL)) add(TXFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDk", TxfDk)) add(TXFDK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDl", TxfDl)) add(TXFDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfM", TxfM)) add(TXFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDm", TxfDm)) add(TXFDM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDn", TxfDn)) add(TXFDN);
	};

	return basefound;
};

void PnlPlnrArrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfI", TxfI);
		writeStringAttr(wr, itemtag, "sref", "TxfJ", TxfJ);
		writeStringAttr(wr, itemtag, "sref", "TxfDi", TxfDi);
		writeStringAttr(wr, itemtag, "sref", "TxfDj", TxfDj);
		writeStringAttr(wr, itemtag, "sref", "TxfK", TxfK);
		writeStringAttr(wr, itemtag, "sref", "TxfL", TxfL);
		writeStringAttr(wr, itemtag, "sref", "TxfDk", TxfDk);
		writeStringAttr(wr, itemtag, "sref", "TxfDl", TxfDl);
		writeStringAttr(wr, itemtag, "sref", "TxfM", TxfM);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
		writeStringAttr(wr, itemtag, "sref", "TxfDm", TxfDm);
		writeStringAttr(wr, itemtag, "sref", "TxfDn", TxfDn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfI == comp->TxfI) insert(items, TXFI);
	if (TxfJ == comp->TxfJ) insert(items, TXFJ);
	if (TxfDi == comp->TxfDi) insert(items, TXFDI);
	if (TxfDj == comp->TxfDj) insert(items, TXFDJ);
	if (TxfK == comp->TxfK) insert(items, TXFK);
	if (TxfL == comp->TxfL) insert(items, TXFL);
	if (TxfDk == comp->TxfDk) insert(items, TXFDK);
	if (TxfDl == comp->TxfDl) insert(items, TXFDL);
	if (TxfM == comp->TxfM) insert(items, TXFM);
	if (TxfN == comp->TxfN) insert(items, TXFN);
	if (TxfDm == comp->TxfDm) insert(items, TXFDM);
	if (TxfDn == comp->TxfDn) insert(items, TXFDN);

	return(items);
};

set<uint> PnlPlnrArrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFI, TXFJ, TXFDI, TXFDJ, TXFK, TXFL, TXFDK, TXFDL, TXFM, TXFN, TXFDM, TXFDN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::ContInf
 ******************************************************************************/

PnlPlnrArrDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTpo
			, const string& TxtDsn
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtTpo = TxtTpo;
	this->TxtDsn = TxtDsn;

	mask = {TXTSRF, TXTTPO, TXTDSN};
};

void PnlPlnrArrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTpo", TxtTpo);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTpo == comp->TxtTpo) insert(items, TXTTPO);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);

	return(items);
};

set<uint> PnlPlnrArrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTPO, TXTDSN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::StatApp
 ******************************************************************************/

void PnlPlnrArrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrDetail::StatShr
 ******************************************************************************/

PnlPlnrArrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButTpoViewAvail
			, const bool ButDsnViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButTpoViewAvail = ButTpoViewAvail;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTTPOVIEWAVAIL, BUTDSNVIEWAVAIL};
};

void PnlPlnrArrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTpoViewAvail", ButTpoViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButTpoViewAvail == comp->ButTpoViewAvail) insert(items, BUTTPOVIEWAVAIL);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrArrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTTPOVIEWAVAIL, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrDetail::Tag
 ******************************************************************************/

void PnlPlnrArrDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrArrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrArrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTpo", "tape-out");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptI", "I (rows)");
			writeStringAttr(wr, itemtag, "sref", "CptJ", "J (columns)");
			writeStringAttr(wr, itemtag, "sref", "CptDi", "di (y) [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDj", "dj (x) [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptK", "K (rows)");
			writeStringAttr(wr, itemtag, "sref", "CptL", "L (columns)");
			writeStringAttr(wr, itemtag, "sref", "CptDk", "dk (y) [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDl", "dl (x) [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptM", "M (rows)");
			writeStringAttr(wr, itemtag, "sref", "CptN", "N (columns)");
			writeStringAttr(wr, itemtag, "sref", "CptDm", "dm (y) [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDn", "dn (x) [\\u03bcm]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrDetail::DpchAppData
 ******************************************************************************/

PnlPlnrArrDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRDETAILDATA) {
};

void PnlPlnrArrDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrArrDetailData");
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
 class PnlPlnrArrDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrArrDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrArrDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrArrDetailDo");
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
 class PnlPlnrArrDetail::DpchEngData
 ******************************************************************************/

PnlPlnrArrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARRDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrArrDetail::DpchEngData::merge(
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

void PnlPlnrArrDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrArrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


