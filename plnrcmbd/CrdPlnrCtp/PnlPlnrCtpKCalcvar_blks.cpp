/**
  * \file PnlPlnrCtpKCalcvar_blks.cpp
  * job handler for job PnlPlnrCtpKCalcvar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrCtpKCalcvar::VecVDo
 ******************************************************************************/

uint PnlPlnrCtpKCalcvar::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	else if (s == "butdownclick") return BUTDOWNCLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrCtpKCalcvar::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	else if (ix == BUTDOWNCLICK) return("ButDownClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::ContInf
 ******************************************************************************/

PnlPlnrCtpKCalcvar::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlPlnrCtpKCalcvar::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrCtpKCalcvar";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrCtpKCalcvar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKCalcvar::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrCtpKCalcvar::ContInf::diff(
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
 class PnlPlnrCtpKCalcvar::StatApp
 ******************************************************************************/

void PnlPlnrCtpKCalcvar::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrCtpKCalcvar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrCtpKCalcvar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::StatShr
 ******************************************************************************/

PnlPlnrCtpKCalcvar::StatShr::StatShr(
			const bool ButUpActive
			, const bool ButDownActive
			, const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButUpActive = ButUpActive;
	this->ButDownActive = ButDownActive;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

void PnlPlnrCtpKCalcvar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrCtpKCalcvar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrCtpKCalcvar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUpActive", ButUpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDownActive", ButDownActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKCalcvar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrCtpKCalcvar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::StgIac
 ******************************************************************************/

PnlPlnrCtpKCalcvar::StgIac::StgIac(
			const uint TcoFixWidth
			, const uint TcoSrfWidth
			, const uint TcoAvlWidth
			, const uint TcoImpWidth
			, const uint TcoTitWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoFixWidth = TcoFixWidth;
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoAvlWidth = TcoAvlWidth;
	this->TcoImpWidth = TcoImpWidth;
	this->TcoTitWidth = TcoTitWidth;
	this->TcoCmtWidth = TcoCmtWidth;
	mask = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
};

bool PnlPlnrCtpKCalcvar::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrCtpKCalcvar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrCtpKCalcvar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFixWidth", TcoFixWidth)) add(TCOFIXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAvlWidth", TcoAvlWidth)) add(TCOAVLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoImpWidth", TcoImpWidth)) add(TCOIMPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlPlnrCtpKCalcvar::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrCtpKCalcvar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrCtpKCalcvar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFixWidth", TcoFixWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAvlWidth", TcoAvlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoImpWidth", TcoImpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKCalcvar::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFixWidth == comp->TcoFixWidth) insert(items, TCOFIXWIDTH);
	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoAvlWidth == comp->TcoAvlWidth) insert(items, TCOAVLWIDTH);
	if (TcoImpWidth == comp->TcoImpWidth) insert(items, TCOIMPWIDTH);
	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlPlnrCtpKCalcvar::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::Tag
 ******************************************************************************/

void PnlPlnrCtpKCalcvar::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrCtpKCalcvar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrCtpKCalcvar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Variables");
			writeStringAttr(wr, itemtag, "sref", "TcoFix", "Fixed");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "TcoAvl", "Avail. rule");
			writeStringAttr(wr, itemtag, "sref", "TcoImp", "Impl. rule");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecPlnrVTag::getTitle(VecPlnrVTag::SHOWSHORT, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecPlnrVTag::getTitle(VecPlnrVTag::EMPSHORT, ixPlnrVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::DpchAppData
 ******************************************************************************/

PnlPlnrCtpKCalcvar::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPKCALCVARDATA) {
};

void PnlPlnrCtpKCalcvar::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpKCalcvarData");
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
		stgiacqry = QryPlnrCtpKCalcvar::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrCtpKCalcvar::DpchAppDo
 ******************************************************************************/

PnlPlnrCtpKCalcvar::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPKCALCVARDO) {
	ixVDo = 0;
};

void PnlPlnrCtpKCalcvar::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpKCalcvarDo");
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
 class PnlPlnrCtpKCalcvar::DpchEngData
 ******************************************************************************/

PnlPlnrCtpKCalcvar::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQCtpKCalcvar* rst
			, QryPlnrCtpKCalcvar::StatShr* statshrqry
			, QryPlnrCtpKCalcvar::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCTPKCALCVARDATA, jref) {
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

void PnlPlnrCtpKCalcvar::DpchEngData::merge(
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

void PnlPlnrCtpKCalcvar::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrCtpKCalcvarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrCtpKCalcvar::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


