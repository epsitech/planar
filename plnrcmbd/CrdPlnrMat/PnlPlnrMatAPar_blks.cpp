/**
  * \file PnlPlnrMatAPar_blks.cpp
  * job handler for job PnlPlnrMatAPar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrMatAPar::VecVDo
 ******************************************************************************/

uint PnlPlnrMatAPar::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrMatAPar::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrMatAPar::ContInf
 ******************************************************************************/

PnlPlnrMatAPar::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlPlnrMatAPar::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrMatAPar";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatAPar::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrMatAPar::ContInf::diff(
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
 class PnlPlnrMatAPar::StatApp
 ******************************************************************************/

void PnlPlnrMatAPar::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrMatAPar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMatAPar::StatShr
 ******************************************************************************/

PnlPlnrMatAPar::StatShr::StatShr(
			const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

void PnlPlnrMatAPar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrMatAPar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatAPar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrMatAPar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMatAPar::StgIac
 ******************************************************************************/

PnlPlnrMatAPar::StgIac::StgIac(
			const uint TcoDsnWidth
			, const uint TcoCatWidth
			, const uint TcoPrpWidth
			, const uint TcoFilWidth
			, const uint TcoValWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoDsnWidth = TcoDsnWidth;
	this->TcoCatWidth = TcoCatWidth;
	this->TcoPrpWidth = TcoPrpWidth;
	this->TcoFilWidth = TcoFilWidth;
	this->TcoValWidth = TcoValWidth;
	this->TcoCmtWidth = TcoCmtWidth;
	mask = {TCODSNWIDTH, TCOCATWIDTH, TCOPRPWIDTH, TCOFILWIDTH, TCOVALWIDTH, TCOCMTWIDTH};
};

bool PnlPlnrMatAPar::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrMatAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrMatAPar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDsnWidth", TcoDsnWidth)) add(TCODSNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCatWidth", TcoCatWidth)) add(TCOCATWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrpWidth", TcoPrpWidth)) add(TCOPRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFilWidth", TcoFilWidth)) add(TCOFILWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoValWidth", TcoValWidth)) add(TCOVALWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlPlnrMatAPar::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrMatAPar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoDsnWidth", TcoDsnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCatWidth", TcoCatWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrpWidth", TcoPrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFilWidth", TcoFilWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoValWidth", TcoValWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrMatAPar::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoDsnWidth == comp->TcoDsnWidth) insert(items, TCODSNWIDTH);
	if (TcoCatWidth == comp->TcoCatWidth) insert(items, TCOCATWIDTH);
	if (TcoPrpWidth == comp->TcoPrpWidth) insert(items, TCOPRPWIDTH);
	if (TcoFilWidth == comp->TcoFilWidth) insert(items, TCOFILWIDTH);
	if (TcoValWidth == comp->TcoValWidth) insert(items, TCOVALWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlPlnrMatAPar::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCODSNWIDTH, TCOCATWIDTH, TCOPRPWIDTH, TCOFILWIDTH, TCOVALWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrMatAPar::Tag
 ******************************************************************************/

void PnlPlnrMatAPar::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrMatAPar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Parameters");
			writeStringAttr(wr, itemtag, "sref", "TcoDsn", "Design mod.");
			writeStringAttr(wr, itemtag, "sref", "TcoCat", "Category");
			writeStringAttr(wr, itemtag, "sref", "TcoPrp", "Property");
			writeStringAttr(wr, itemtag, "sref", "TcoFil", "File");
			writeStringAttr(wr, itemtag, "sref", "TcoVal", "Value");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecPlnrVTag::getTitle(VecPlnrVTag::SHOWSHORT, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecPlnrVTag::getTitle(VecPlnrVTag::EMPSHORT, ixPlnrVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrMatAPar::DpchAppData
 ******************************************************************************/

PnlPlnrMatAPar::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMATAPARDATA) {
};

void PnlPlnrMatAPar::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrMatAParData");
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
		stgiacqry = QryPlnrMatAPar::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrMatAPar::DpchAppDo
 ******************************************************************************/

PnlPlnrMatAPar::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRMATAPARDO) {
	ixVDo = 0;
};

void PnlPlnrMatAPar::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrMatAParDo");
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
 class PnlPlnrMatAPar::DpchEngData
 ******************************************************************************/

PnlPlnrMatAPar::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQMatAPar* rst
			, QryPlnrMatAPar::StatShr* statshrqry
			, QryPlnrMatAPar::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRMATAPARDATA, jref) {
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

void PnlPlnrMatAPar::DpchEngData::merge(
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

void PnlPlnrMatAPar::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrMatAParData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrMatAPar::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


