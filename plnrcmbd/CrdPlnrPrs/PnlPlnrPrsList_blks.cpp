/**
  * \file PnlPlnrPrsList_blks.cpp
  * job handler for job PnlPlnrPrsList (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrPrsList::VecVDo
 ******************************************************************************/

uint PnlPlnrPrsList::VecVDo::getIx(
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

string PnlPlnrPrsList::VecVDo::getSref(
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
 class PnlPlnrPrsList::ContIac
 ******************************************************************************/

PnlPlnrPrsList::ContIac::ContIac(
			const uint numFTos
		) : Block() {
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlPlnrPrsList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrPrsList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlPlnrPrsList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrPrsList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlPlnrPrsList::ContIac::diff(
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
 class PnlPlnrPrsList::ContInf
 ******************************************************************************/

PnlPlnrPrsList::ContInf::ContInf(
			const bool ButFilterOn
			, const uint numFCsiQst
		) : Block() {
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {BUTFILTERON, NUMFCSIQST};
};

void PnlPlnrPrsList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrPrsList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlPlnrPrsList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTFILTERON, NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrPrsList::StatShr
 ******************************************************************************/

PnlPlnrPrsList::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const bool ButDeleteActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXPLNRVEXPSTATE, BUTDELETEACTIVE};
};

void PnlPlnrPrsList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrPrsList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlPlnrPrsList::StatShr::diff(
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
 class PnlPlnrPrsList::StgIac
 ******************************************************************************/

PnlPlnrPrsList::StgIac::StgIac(
			const uint TcoTitWidth
			, const uint TcoFnmWidth
			, const uint TcoLnmWidth
			, const uint TcoGrpWidth
			, const uint TcoOwnWidth
			, const uint TcoSexWidth
			, const uint TcoTelWidth
			, const uint TcoEmlWidth
		) : Block() {
	this->TcoTitWidth = TcoTitWidth;
	this->TcoFnmWidth = TcoFnmWidth;
	this->TcoLnmWidth = TcoLnmWidth;
	this->TcoGrpWidth = TcoGrpWidth;
	this->TcoOwnWidth = TcoOwnWidth;
	this->TcoSexWidth = TcoSexWidth;
	this->TcoTelWidth = TcoTelWidth;
	this->TcoEmlWidth = TcoEmlWidth;
	mask = {TCOTITWIDTH, TCOFNMWIDTH, TCOLNMWIDTH, TCOGRPWIDTH, TCOOWNWIDTH, TCOSEXWIDTH, TCOTELWIDTH, TCOEMLWIDTH};
};

bool PnlPlnrPrsList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacPlnrPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacPlnrPrsList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFnmWidth", TcoFnmWidth)) add(TCOFNMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLnmWidth", TcoLnmWidth)) add(TCOLNMWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", TcoGrpWidth)) add(TCOGRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", TcoOwnWidth)) add(TCOOWNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSexWidth", TcoSexWidth)) add(TCOSEXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTelWidth", TcoTelWidth)) add(TCOTELWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoEmlWidth", TcoEmlWidth)) add(TCOEMLWIDTH);
	};

	return basefound;
};

void PnlPlnrPrsList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFnmWidth", TcoFnmWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLnmWidth", TcoLnmWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSexWidth", TcoSexWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTelWidth", TcoTelWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoEmlWidth", TcoEmlWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrPrsList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoFnmWidth == comp->TcoFnmWidth) insert(items, TCOFNMWIDTH);
	if (TcoLnmWidth == comp->TcoLnmWidth) insert(items, TCOLNMWIDTH);
	if (TcoGrpWidth == comp->TcoGrpWidth) insert(items, TCOGRPWIDTH);
	if (TcoOwnWidth == comp->TcoOwnWidth) insert(items, TCOOWNWIDTH);
	if (TcoSexWidth == comp->TcoSexWidth) insert(items, TCOSEXWIDTH);
	if (TcoTelWidth == comp->TcoTelWidth) insert(items, TCOTELWIDTH);
	if (TcoEmlWidth == comp->TcoEmlWidth) insert(items, TCOEMLWIDTH);

	return(items);
};

set<uint> PnlPlnrPrsList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOTITWIDTH, TCOFNMWIDTH, TCOLNMWIDTH, TCOGRPWIDTH, TCOOWNWIDTH, TCOSEXWIDTH, TCOTELWIDTH, TCOEMLWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrPrsList::Tag
 ******************************************************************************/

void PnlPlnrPrsList::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Persons");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Title");
			writeStringAttr(wr, itemtag, "sref", "TcoFnm", "First name");
			writeStringAttr(wr, itemtag, "sref", "TcoLnm", "Last name");
			writeStringAttr(wr, itemtag, "sref", "TcoGrp", "Group");
			writeStringAttr(wr, itemtag, "sref", "TcoOwn", "Owner");
			writeStringAttr(wr, itemtag, "sref", "TcoSex", "Sex");
			writeStringAttr(wr, itemtag, "sref", "TcoTel", "Phone");
			writeStringAttr(wr, itemtag, "sref", "TcoEml", "E-mail");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::GOTO, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::SHOWLONG, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::EMPLONG, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrPrsList::DpchAppData
 ******************************************************************************/

PnlPlnrPrsList::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRPRSLISTDATA) {
};

void PnlPlnrPrsList::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrPrsListData");
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
		stgiacqry = QryPlnrPrsList::StgIac();
	};
};

/******************************************************************************
 class PnlPlnrPrsList::DpchAppDo
 ******************************************************************************/

PnlPlnrPrsList::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRPRSLISTDO) {
	ixVDo = 0;
};

void PnlPlnrPrsList::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrPrsListDo");
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
 class PnlPlnrPrsList::DpchEngData
 ******************************************************************************/

PnlPlnrPrsList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListPlnrQPrsList* rst
			, QryPlnrPrsList::StatShr* statshrqry
			, QryPlnrPrsList::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRPRSLISTDATA, jref) {
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

void PnlPlnrPrsList::DpchEngData::merge(
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

void PnlPlnrPrsList::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrPrsListData");
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
		if (has(STATAPPQRY)) QryPlnrPrsList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


