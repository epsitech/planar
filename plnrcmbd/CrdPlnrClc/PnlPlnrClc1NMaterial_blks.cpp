/**
  * \file PnlPlnrClc1NMaterial_blks.cpp
  * job handler for job PnlPlnrClc1NMaterial (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrClc1NMaterial::VecVDo
 ******************************************************************************/

uint PnlPlnrClc1NMaterial::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlPlnrClc1NMaterial::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::ContInf
 ******************************************************************************/

PnlPlnrClc1NMaterial::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlPlnrClc1NMaterial::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrClc1NMaterial";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrClc1NMaterial";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrClc1NMaterial::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrClc1NMaterial::ContInf::diff(
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
 class PnlPlnrClc1NMaterial::StatApp
 ******************************************************************************/

void PnlPlnrClc1NMaterial::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrClc1NMaterial";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrClc1NMaterial";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::StatShr
 ******************************************************************************/

PnlPlnrClc1NMaterial::StatShr::StatShr(
			const bool ButViewActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButViewActive = ButViewActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTVIEWACTIVE, BUTDELETEACTIVE};
};

void PnlPlnrClc1NMaterial::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrClc1NMaterial";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrClc1NMaterial";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrClc1NMaterial::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrClc1NMaterial::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::StgIac
 ******************************************************************************/

PnlPlnrClc1NMaterial::StgIac::StgIac(
			const uint TcoRefWidth
		) : Block() {
	this->TcoRefWidth = TcoRefWidth;
	mask = {TCOREFWIDTH};
};

bool PnlPlnrClc1NMaterial::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrClc1NMaterial");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrClc1NMaterial";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlPlnrClc1NMaterial::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrClc1NMaterial";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrClc1NMaterial";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrClc1NMaterial::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlPlnrClc1NMaterial::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOREFWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::Tag
 ******************************************************************************/

void PnlPlnrClc1NMaterial::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrClc1NMaterial";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrClc1NMaterial";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Customized materials");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Material");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecPlnrVTag::getTitle(VecPlnrVTag::SHOWSHORT, ixPlnrVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecPlnrVTag::getTitle(VecPlnrVTag::EMPSHORT, ixPlnrVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::DpchAppData
 ******************************************************************************/

PnlPlnrClc1NMaterial::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLC1NMATERIALDATA) {
};

void PnlPlnrClc1NMaterial::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrClc1NMaterialData");
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
		stgiacqry = QryPlnrClc1NMaterial::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrClc1NMaterial::DpchAppDo
 ******************************************************************************/

PnlPlnrClc1NMaterial::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLC1NMATERIALDO) {
	ixVDo = 0;
};

void PnlPlnrClc1NMaterial::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrClc1NMaterialDo");
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
 class PnlPlnrClc1NMaterial::DpchEngData
 ******************************************************************************/

PnlPlnrClc1NMaterial::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQClc1NMaterial* rst
			, QryPlnrClc1NMaterial::StatShr* statshrqry
			, QryPlnrClc1NMaterial::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLC1NMATERIALDATA, jref) {
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

void PnlPlnrClc1NMaterial::DpchEngData::merge(
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

void PnlPlnrClc1NMaterial::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrClc1NMaterialData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryPlnrClc1NMaterial::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


