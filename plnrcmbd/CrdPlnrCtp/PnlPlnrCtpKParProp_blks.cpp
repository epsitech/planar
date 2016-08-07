/**
  * \file PnlPlnrCtpKParProp_blks.cpp
  * job handler for job PnlPlnrCtpKParProp (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrCtpKParProp::VecVDo
 ******************************************************************************/

uint PnlPlnrCtpKParProp::VecVDo::getIx(
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

string PnlPlnrCtpKParProp::VecVDo::getSref(
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
 class PnlPlnrCtpKParProp::ContInf
 ******************************************************************************/

PnlPlnrCtpKParProp::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlPlnrCtpKParProp::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrCtpKParProp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKParProp::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrCtpKParProp::ContInf::diff(
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
 class PnlPlnrCtpKParProp::StatApp
 ******************************************************************************/

void PnlPlnrCtpKParProp::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrCtpKParProp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpKParProp::StatShr
 ******************************************************************************/

PnlPlnrCtpKParProp::StatShr::StatShr(
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

void PnlPlnrCtpKParProp::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrCtpKParProp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUpActive", ButUpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDownActive", ButDownActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKParProp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrCtpKParProp::StatShr::diff(
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
 class PnlPlnrCtpKParProp::StgIac
 ******************************************************************************/

PnlPlnrCtpKParProp::StgIac::StgIac(
			const uint TcoSrfWidth
			, const uint TcoAvlWidth
			, const uint TcoTitWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoAvlWidth = TcoAvlWidth;
	this->TcoTitWidth = TcoTitWidth;
	this->TcoCmtWidth = TcoCmtWidth;
	mask = {TCOSRFWIDTH, TCOAVLWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
};

bool PnlPlnrCtpKParProp::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrCtpKParProp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrCtpKParProp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAvlWidth", TcoAvlWidth)) add(TCOAVLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlPlnrCtpKParProp::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrCtpKParProp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAvlWidth", TcoAvlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpKParProp::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoAvlWidth == comp->TcoAvlWidth) insert(items, TCOAVLWIDTH);
	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlPlnrCtpKParProp::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSRFWIDTH, TCOAVLWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpKParProp::Tag
 ******************************************************************************/

void PnlPlnrCtpKParProp::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrCtpKParProp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Parameter property keys");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "TcoAvl", "Avail. rule");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecPlnrVTag::getTitle(VecPlnrVTag::SHOWSHORT, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecPlnrVTag::getTitle(VecPlnrVTag::EMPSHORT, ixPlnrVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpKParProp::DpchAppData
 ******************************************************************************/

PnlPlnrCtpKParProp::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPKPARPROPDATA) {
};

void PnlPlnrCtpKParProp::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpKParPropData");
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
		stgiacqry = QryPlnrCtpKParProp::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrCtpKParProp::DpchAppDo
 ******************************************************************************/

PnlPlnrCtpKParProp::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPKPARPROPDO) {
	ixVDo = 0;
};

void PnlPlnrCtpKParProp::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpKParPropDo");
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
 class PnlPlnrCtpKParProp::DpchEngData
 ******************************************************************************/

PnlPlnrCtpKParProp::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQCtpKParProp* rst
			, QryPlnrCtpKParProp::StatShr* statshrqry
			, QryPlnrCtpKParProp::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCTPKPARPROPDATA, jref) {
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

void PnlPlnrCtpKParProp::DpchEngData::merge(
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

void PnlPlnrCtpKParProp::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrCtpKParPropData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrCtpKParProp::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


