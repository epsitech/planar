/**
  * \file PnlPlnrDgdDetail_blks.cpp
  * job handler for job PnlPlnrDgdDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDgdDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDgdDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrDgdDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDgdDetail::ContIac
 ******************************************************************************/

PnlPlnrDgdDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfLvl
			, const string& TxfAv1
			, const string& TxfAv2
			, const string& TxfAl1
			, const string& TxfAl2
			, const string& TxfAgd
			, const string& TxfD
			, const string& TxfDph
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->TxfLvl = TxfLvl;
	this->TxfAv1 = TxfAv1;
	this->TxfAv2 = TxfAv2;
	this->TxfAl1 = TxfAl1;
	this->TxfAl2 = TxfAl2;
	this->TxfAgd = TxfAgd;
	this->TxfD = TxfD;
	this->TxfDph = TxfDph;

	mask = {NUMFPUPTYP, TXFLVL, TXFAV1, TXFAV2, TXFAL1, TXFAL2, TXFAGD, TXFD, TXFDPH};
};

bool PnlPlnrDgdDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDgdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDgdDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLvl", TxfLvl)) add(TXFLVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv1", TxfAv1)) add(TXFAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv2", TxfAv2)) add(TXFAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl1", TxfAl1)) add(TXFAL1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAl2", TxfAl2)) add(TXFAL2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAgd", TxfAgd)) add(TXFAGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfD", TxfD)) add(TXFD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDph", TxfDph)) add(TXFDPH);
	};

	return basefound;
};

void PnlPlnrDgdDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfLvl", TxfLvl);
		writeStringAttr(wr, itemtag, "sref", "TxfAv1", TxfAv1);
		writeStringAttr(wr, itemtag, "sref", "TxfAv2", TxfAv2);
		writeStringAttr(wr, itemtag, "sref", "TxfAl1", TxfAl1);
		writeStringAttr(wr, itemtag, "sref", "TxfAl2", TxfAl2);
		writeStringAttr(wr, itemtag, "sref", "TxfAgd", TxfAgd);
		writeStringAttr(wr, itemtag, "sref", "TxfD", TxfD);
		writeStringAttr(wr, itemtag, "sref", "TxfDph", TxfDph);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfLvl == comp->TxfLvl) insert(items, TXFLVL);
	if (TxfAv1 == comp->TxfAv1) insert(items, TXFAV1);
	if (TxfAv2 == comp->TxfAv2) insert(items, TXFAV2);
	if (TxfAl1 == comp->TxfAl1) insert(items, TXFAL1);
	if (TxfAl2 == comp->TxfAl2) insert(items, TXFAL2);
	if (TxfAgd == comp->TxfAgd) insert(items, TXFAGD);
	if (TxfD == comp->TxfD) insert(items, TXFD);
	if (TxfDph == comp->TxfDph) insert(items, TXFDPH);

	return(items);
};

set<uint> PnlPlnrDgdDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFLVL, TXFAV1, TXFAV2, TXFAL1, TXFAL2, TXFAGD, TXFD, TXFDPH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::ContInf
 ******************************************************************************/

PnlPlnrDgdDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtLvl
			, const string& TxtAv1
			, const string& TxtAv2
			, const string& TxtAl1
			, const string& TxtAl2
			, const string& TxtAgd
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtLvl = TxtLvl;
	this->TxtAv1 = TxtAv1;
	this->TxtAv2 = TxtAv2;
	this->TxtAl1 = TxtAl1;
	this->TxtAl2 = TxtAl2;
	this->TxtAgd = TxtAgd;

	mask = {TXTSRF, TXTDSN, TXTLVL, TXTAV1, TXTAV2, TXTAL1, TXTAL2, TXTAGD};
};

void PnlPlnrDgdDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtLvl", TxtLvl);
		writeStringAttr(wr, itemtag, "sref", "TxtAv1", TxtAv1);
		writeStringAttr(wr, itemtag, "sref", "TxtAv2", TxtAv2);
		writeStringAttr(wr, itemtag, "sref", "TxtAl1", TxtAl1);
		writeStringAttr(wr, itemtag, "sref", "TxtAl2", TxtAl2);
		writeStringAttr(wr, itemtag, "sref", "TxtAgd", TxtAgd);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtLvl == comp->TxtLvl) insert(items, TXTLVL);
	if (TxtAv1 == comp->TxtAv1) insert(items, TXTAV1);
	if (TxtAv2 == comp->TxtAv2) insert(items, TXTAV2);
	if (TxtAl1 == comp->TxtAl1) insert(items, TXTAL1);
	if (TxtAl2 == comp->TxtAl2) insert(items, TXTAL2);
	if (TxtAgd == comp->TxtAgd) insert(items, TXTAGD);

	return(items);
};

set<uint> PnlPlnrDgdDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTLVL, TXTAV1, TXTAV2, TXTAL1, TXTAL2, TXTAGD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::StatApp
 ******************************************************************************/

void PnlPlnrDgdDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool TxtLvlAlt
			, const bool TxtAv1Alt
			, const bool TxtAv2Alt
			, const bool TxtAl1Alt
			, const bool TxtAl2Alt
			, const bool TxtAgdAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtLvlAlt", TxtLvlAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAv1Alt", TxtAv1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAv2Alt", TxtAv2Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAl1Alt", TxtAl1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAl2Alt", TxtAl2Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAgdAlt", TxtAgdAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdDetail::StatShr
 ******************************************************************************/

PnlPlnrDgdDetail::StatShr::StatShr(
			const bool TxfLvlValid
			, const bool TxfAv1Valid
			, const bool TxfAv2Valid
			, const bool TxfAl1Valid
			, const bool TxfAl2Valid
			, const bool TxfAgdValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
		) : Block() {
	this->TxfLvlValid = TxfLvlValid;
	this->TxfAv1Valid = TxfAv1Valid;
	this->TxfAv2Valid = TxfAv2Valid;
	this->TxfAl1Valid = TxfAl1Valid;
	this->TxfAl2Valid = TxfAl2Valid;
	this->TxfAgdValid = TxfAgdValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {TXFLVLVALID, TXFAV1VALID, TXFAV2VALID, TXFAL1VALID, TXFAL2VALID, TXFAGDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
};

void PnlPlnrDgdDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfLvlValid", TxfLvlValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAv1Valid", TxfAv1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAv2Valid", TxfAv2Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAl1Valid", TxfAl1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAl2Valid", TxfAl2Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAgdValid", TxfAgdValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDgdDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfLvlValid == comp->TxfLvlValid) insert(items, TXFLVLVALID);
	if (TxfAv1Valid == comp->TxfAv1Valid) insert(items, TXFAV1VALID);
	if (TxfAv2Valid == comp->TxfAv2Valid) insert(items, TXFAV2VALID);
	if (TxfAl1Valid == comp->TxfAl1Valid) insert(items, TXFAL1VALID);
	if (TxfAl2Valid == comp->TxfAl2Valid) insert(items, TXFAL2VALID);
	if (TxfAgdValid == comp->TxfAgdValid) insert(items, TXFAGDVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDgdDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFLVLVALID, TXFAV1VALID, TXFAV2VALID, TXFAL1VALID, TXFAL2VALID, TXFAGDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDgdDetail::Tag
 ******************************************************************************/

void PnlPlnrDgdDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDgdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDgdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptLvl", "level");
			writeStringAttr(wr, itemtag, "sref", "CptAv1", "reference vertex 1");
			writeStringAttr(wr, itemtag, "sref", "CptAv2", "reference vertex 2");
			writeStringAttr(wr, itemtag, "sref", "CptAl1", "reference line guide 1");
			writeStringAttr(wr, itemtag, "sref", "CptAl2", "reference line guide 2");
			writeStringAttr(wr, itemtag, "sref", "CptAgd", "reference arc guide");
			writeStringAttr(wr, itemtag, "sref", "CptD", "distance [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptDph", "angular distance [\\u00b0]");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDgdDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDgdDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDATA) {
};

void PnlPlnrDgdDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDgdDetailData");
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
 class PnlPlnrDgdDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDgdDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrDgdDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDgdDetailDo");
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
 class PnlPlnrDgdDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDgdDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDGDDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDgdDetail::DpchEngData::merge(
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

void PnlPlnrDgdDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDgdDetailData");
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


