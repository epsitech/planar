/**
  * \file PnlPlnrSruMNLayer_blks.cpp
  * job handler for job PnlPlnrSruMNLayer (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrSruMNLayer::VecVDo
 ******************************************************************************/

uint PnlPlnrSruMNLayer::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butaddclick") return BUTADDCLICK;
	else if (s == "butsubclick") return BUTSUBCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrSruMNLayer::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTADDCLICK) return("ButAddClick");
	else if (ix == BUTSUBCLICK) return("ButSubClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrSruMNLayer::ContInf
 ******************************************************************************/

PnlPlnrSruMNLayer::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlPlnrSruMNLayer::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrSruMNLayer";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrSruMNLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruMNLayer::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrSruMNLayer::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruMNLayer::StatApp
 ******************************************************************************/

void PnlPlnrSruMNLayer::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrSruMNLayer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrSruMNLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruMNLayer::StatShr
 ******************************************************************************/

PnlPlnrSruMNLayer::StatShr::StatShr(
			const bool ButViewActive
			, const bool ButSubActive
		) : Block() {
	this->ButViewActive = ButViewActive;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWACTIVE, BUTSUBACTIVE};
};

void PnlPlnrSruMNLayer::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrSruMNLayer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrSruMNLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSubActive", ButSubActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruMNLayer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlPlnrSruMNLayer::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWACTIVE, BUTSUBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruMNLayer::StgIac
 ******************************************************************************/

PnlPlnrSruMNLayer::StgIac::StgIac(
			const uint TcoMrefWidth
		) : Block() {
	this->TcoMrefWidth = TcoMrefWidth;
	mask = {TCOMREFWIDTH};
};

bool PnlPlnrSruMNLayer::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrSruMNLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrSruMNLayer";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
	};

	return basefound;
};

void PnlPlnrSruMNLayer::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrSruMNLayer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrSruMNLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruMNLayer::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);

	return(items);
};

set<uint> PnlPlnrSruMNLayer::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruMNLayer::Tag
 ******************************************************************************/

void PnlPlnrSruMNLayer::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrSruMNLayer";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrSruMNLayer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Layers");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Layer");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecPlnrVTag::getTitle(VecPlnrVTag::SHOWSHORT, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecPlnrVTag::getTitle(VecPlnrVTag::EMPSHORT, ixPlnrVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruMNLayer::DpchAppData
 ******************************************************************************/

PnlPlnrSruMNLayer::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUMNLAYERDATA) {
};

void PnlPlnrSruMNLayer::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrSruMNLayerData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryPlnrSruMNLayer::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrSruMNLayer::DpchAppDo
 ******************************************************************************/

PnlPlnrSruMNLayer::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRUMNLAYERDO) {
	ixVDo = 0;
};

void PnlPlnrSruMNLayer::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrSruMNLayerDo");
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
 class PnlPlnrSruMNLayer::DpchEngData
 ******************************************************************************/

PnlPlnrSruMNLayer::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQSruMNLayer* rst
			, QryPlnrSruMNLayer::StatShr* statshrqry
			, QryPlnrSruMNLayer::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSRUMNLAYERDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrSruMNLayer::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlPlnrSruMNLayer::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrSruMNLayerData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrSruMNLayer::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


