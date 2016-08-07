/**
  * \file PnlPlnrAriList_blks.cpp
  * job handler for job PnlPlnrAriList (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrAriList::VecVDo
 ******************************************************************************/

uint PnlPlnrAriList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butfilterclick") return BUTFILTERCLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrAriList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTFILTERCLICK) return("ButFilterClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrAriList::ContIac
 ******************************************************************************/

PnlPlnrAriList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrAriList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrAriList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrAriList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrAriList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriList::ContInf
 ******************************************************************************/

PnlPlnrAriList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) : Block() {
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

void PnlPlnrAriList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrAriList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriList::StatShr
 ******************************************************************************/

PnlPlnrAriList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

void PnlPlnrAriList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrAriList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriList::StgIac
 ******************************************************************************/

PnlPlnrAriList::StgIac::StgIac(
			const uint TcoIWidth
			, const uint TcoJWidth
			, const uint TcoKWidth
			, const uint TcoLWidth
			, const uint TcoMWidth
			, const uint TcoNWidth
			, const uint TcoArrWidth
			, const uint TcoDsnWidth
			, const uint TcoDxWidth
			, const uint TcoDyWidth
		) : Block() {
	this->TcoIWidth = TcoIWidth;
	this->TcoJWidth = TcoJWidth;
	this->TcoKWidth = TcoKWidth;
	this->TcoLWidth = TcoLWidth;
	this->TcoMWidth = TcoMWidth;
	this->TcoNWidth = TcoNWidth;
	this->TcoArrWidth = TcoArrWidth;
	this->TcoDsnWidth = TcoDsnWidth;
	this->TcoDxWidth = TcoDxWidth;
	this->TcoDyWidth = TcoDyWidth;
	mask = {TCOIWIDTH, TCOJWIDTH, TCOKWIDTH, TCOLWIDTH, TCOMWIDTH, TCONWIDTH, TCOARRWIDTH, TCODSNWIDTH, TCODXWIDTH, TCODYWIDTH};
};

bool PnlPlnrAriList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrAriList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIWidth", TcoIWidth)) add(TCOIWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoJWidth", TcoJWidth)) add(TCOJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoKWidth", TcoKWidth)) add(TCOKWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLWidth", TcoLWidth)) add(TCOLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMWidth", TcoMWidth)) add(TCOMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoNWidth", TcoNWidth)) add(TCONWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoArrWidth", TcoArrWidth)) add(TCOARRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDsnWidth", TcoDsnWidth)) add(TCODSNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDxWidth", TcoDxWidth)) add(TCODXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDyWidth", TcoDyWidth)) add(TCODYWIDTH);
	};

	return basefound;
};

void PnlPlnrAriList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoIWidth", TcoIWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoJWidth", TcoJWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoKWidth", TcoKWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLWidth", TcoLWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMWidth", TcoMWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoNWidth", TcoNWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoArrWidth", TcoArrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDsnWidth", TcoDsnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDxWidth", TcoDxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDyWidth", TcoDyWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrAriList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoIWidth == comp->TcoIWidth) insert(items, TCOIWIDTH);
	if (TcoJWidth == comp->TcoJWidth) insert(items, TCOJWIDTH);
	if (TcoKWidth == comp->TcoKWidth) insert(items, TCOKWIDTH);
	if (TcoLWidth == comp->TcoLWidth) insert(items, TCOLWIDTH);
	if (TcoMWidth == comp->TcoMWidth) insert(items, TCOMWIDTH);
	if (TcoNWidth == comp->TcoNWidth) insert(items, TCONWIDTH);
	if (TcoArrWidth == comp->TcoArrWidth) insert(items, TCOARRWIDTH);
	if (TcoDsnWidth == comp->TcoDsnWidth) insert(items, TCODSNWIDTH);
	if (TcoDxWidth == comp->TcoDxWidth) insert(items, TCODXWIDTH);
	if (TcoDyWidth == comp->TcoDyWidth) insert(items, TCODYWIDTH);

	return(items);
};

set<uint> PnlPlnrAriList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOIWIDTH, TCOJWIDTH, TCOKWIDTH, TCOLWIDTH, TCOMWIDTH, TCONWIDTH, TCOARRWIDTH, TCODSNWIDTH, TCODXWIDTH, TCODYWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrAriList::Tag
 ******************************************************************************/

void PnlPlnrAriList::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrAriList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Array items");
			writeStringAttr(wr, itemtag, "sref", "TcoI", "I");
			writeStringAttr(wr, itemtag, "sref", "TcoJ", "J");
			writeStringAttr(wr, itemtag, "sref", "TcoK", "K");
			writeStringAttr(wr, itemtag, "sref", "TcoL", "L");
			writeStringAttr(wr, itemtag, "sref", "TcoM", "M");
			writeStringAttr(wr, itemtag, "sref", "TcoN", "N");
			writeStringAttr(wr, itemtag, "sref", "TcoArr", "Array");
			writeStringAttr(wr, itemtag, "sref", "TcoDsn", "Array item");
			writeStringAttr(wr, itemtag, "sref", "TcoDx", "Dx [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "TcoDy", "Dy [\\u03bcm]");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecPlnrVTag::getTitle(VecPlnrVTag::FOR, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::SHOWLONG, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::EMPLONG, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrAriList::DpchAppData
 ******************************************************************************/

PnlPlnrAriList::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARILISTDATA) {
};

void PnlPlnrAriList::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAriListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryPlnrAriList::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrAriList::DpchAppDo
 ******************************************************************************/

PnlPlnrAriList::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARILISTDO) {
	ixVDo = 0;
};

void PnlPlnrAriList::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAriListDo");
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
 class PnlPlnrAriList::DpchEngData
 ******************************************************************************/

PnlPlnrAriList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQAriList* rst
			, QryPlnrAriList::StatShr* statshrqry
			, QryPlnrAriList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARILISTDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

void PnlPlnrAriList::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlPlnrAriList::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrAriListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrAriList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


