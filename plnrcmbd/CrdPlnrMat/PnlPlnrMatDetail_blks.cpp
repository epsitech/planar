/**
  * \file PnlPlnrMatDetail_blks.cpp
  * job handler for job PnlPlnrMatDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrMatDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrMatDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butsupviewclick") return BUTSUPVIEWCLICK;

	return(0);
};

string PnlPlnrMatDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrMatDetail::ContIac
 ******************************************************************************/

PnlPlnrMatDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupTyp
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupTyp = numFPupTyp;

	mask = {TXFTIT, NUMFPUPTYP};
};

bool PnlPlnrMatDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrMatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrMatDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
	};

	return basefound;
};

void PnlPlnrMatDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrMatDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrMatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);

	return(items);
};

set<uint> PnlPlnrMatDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPTYP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMatDetail::ContInf
 ******************************************************************************/

PnlPlnrMatDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtCal
			, const string& TxtSup
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtCal = TxtCal;
	this->TxtSup = TxtSup;

	mask = {TXTSRF, TXTCAL, TXTSUP};
};

void PnlPlnrMatDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrMatDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrMatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtCal", TxtCal);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtCal == comp->TxtCal) insert(items, TXTCAL);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);

	return(items);
};

set<uint> PnlPlnrMatDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCAL, TXTSUP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMatDetail::StatApp
 ******************************************************************************/

void PnlPlnrMatDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrMatDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrMatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMatDetail::StatShr
 ******************************************************************************/

PnlPlnrMatDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButSupViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButSupViewAvail = ButSupViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTSUPVIEWAVAIL};
};

void PnlPlnrMatDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrMatDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrMatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrMatDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTSUPVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMatDetail::Tag
 ******************************************************************************/

void PnlPlnrMatDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrMatDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrMatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "calculation");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "parent material");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMatDetail::DpchAppData
 ******************************************************************************/

PnlPlnrMatDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMATDETAILDATA) {
};

void PnlPlnrMatDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrMatDetailData");
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
 class PnlPlnrMatDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrMatDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMATDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrMatDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrMatDetailDo");
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
 class PnlPlnrMatDetail::DpchEngData
 ******************************************************************************/

PnlPlnrMatDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRMATDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrMatDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrMatDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrMatDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


