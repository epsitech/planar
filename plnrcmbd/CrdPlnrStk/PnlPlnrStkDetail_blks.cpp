/**
  * \file PnlPlnrStkDetail_blks.cpp
  * job handler for job PnlPlnrStkDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrStkDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrStkDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;
	else if (s == "butlyrviewclick") return BUTLYRVIEWCLICK;

	return(0);
};

string PnlPlnrStkDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");
	else if (ix == BUTLYRVIEWCLICK) return("ButLyrViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrStkDetail::ContIac
 ******************************************************************************/

PnlPlnrStkDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupMty
			, const uint numFPupFal
			, const string& TxfFlr
			, const string& TxfZfl
			, const uint numFPupCal
			, const string& TxfCil
			, const string& TxfZci
			, const uint numFLstLyr
			, const string& TxfLyr
			, const string& TxfN
		) : Block() {
	this->numFPupTyp = numFPupTyp;
	this->numFPupMty = numFPupMty;
	this->numFPupFal = numFPupFal;
	this->TxfFlr = TxfFlr;
	this->TxfZfl = TxfZfl;
	this->numFPupCal = numFPupCal;
	this->TxfCil = TxfCil;
	this->TxfZci = TxfZci;
	this->numFLstLyr = numFLstLyr;
	this->TxfLyr = TxfLyr;
	this->TxfN = TxfN;

	mask = {NUMFPUPTYP, NUMFPUPMTY, NUMFPUPFAL, TXFFLR, TXFZFL, NUMFPUPCAL, TXFCIL, TXFZCI, NUMFLSTLYR, TXFLYR, TXFN};
};

bool PnlPlnrStkDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrStkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrStkDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMty", numFPupMty)) add(NUMFPUPMTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFal", numFPupFal)) add(NUMFPUPFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFlr", TxfFlr)) add(TXFFLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfZfl", TxfZfl)) add(TXFZFL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCal", numFPupCal)) add(NUMFPUPCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCil", TxfCil)) add(TXFCIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfZci", TxfZci)) add(TXFZCI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLyr", numFLstLyr)) add(NUMFLSTLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLyr", TxfLyr)) add(TXFLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfN", TxfN)) add(TXFN);
	};

	return basefound;
};

void PnlPlnrStkDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupMty", numFPupMty);
		writeUintAttr(wr, itemtag, "sref", "numFPupFal", numFPupFal);
		writeStringAttr(wr, itemtag, "sref", "TxfFlr", TxfFlr);
		writeStringAttr(wr, itemtag, "sref", "TxfZfl", TxfZfl);
		writeUintAttr(wr, itemtag, "sref", "numFPupCal", numFPupCal);
		writeStringAttr(wr, itemtag, "sref", "TxfCil", TxfCil);
		writeStringAttr(wr, itemtag, "sref", "TxfZci", TxfZci);
		writeUintAttr(wr, itemtag, "sref", "numFLstLyr", numFLstLyr);
		writeStringAttr(wr, itemtag, "sref", "TxfLyr", TxfLyr);
		writeStringAttr(wr, itemtag, "sref", "TxfN", TxfN);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupMty == comp->numFPupMty) insert(items, NUMFPUPMTY);
	if (numFPupFal == comp->numFPupFal) insert(items, NUMFPUPFAL);
	if (TxfFlr == comp->TxfFlr) insert(items, TXFFLR);
	if (TxfZfl == comp->TxfZfl) insert(items, TXFZFL);
	if (numFPupCal == comp->numFPupCal) insert(items, NUMFPUPCAL);
	if (TxfCil == comp->TxfCil) insert(items, TXFCIL);
	if (TxfZci == comp->TxfZci) insert(items, TXFZCI);
	if (numFLstLyr == comp->numFLstLyr) insert(items, NUMFLSTLYR);
	if (TxfLyr == comp->TxfLyr) insert(items, TXFLYR);
	if (TxfN == comp->TxfN) insert(items, TXFN);

	return(items);
};

set<uint> PnlPlnrStkDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPMTY, NUMFPUPFAL, TXFFLR, TXFZFL, NUMFPUPCAL, TXFCIL, TXFZCI, NUMFLSTLYR, TXFLYR, TXFN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::ContInf
 ******************************************************************************/

PnlPlnrStkDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtFlr
			, const string& TxtCil
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtFlr = TxtFlr;
	this->TxtCil = TxtCil;

	mask = {TXTSRF, TXTDSN, TXTFLR, TXTCIL};
};

void PnlPlnrStkDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtFlr", TxtFlr);
		writeStringAttr(wr, itemtag, "sref", "TxtCil", TxtCil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtFlr == comp->TxtFlr) insert(items, TXTFLR);
	if (TxtCil == comp->TxtCil) insert(items, TXTCIL);

	return(items);
};

set<uint> PnlPlnrStkDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTFLR, TXTCIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::StatApp
 ******************************************************************************/

void PnlPlnrStkDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool TxtFlrAlt
			, const bool TxtCilAlt
			, const bool LstLyrAlt
			, const uint LstLyrNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtFlrAlt", TxtFlrAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtCilAlt", TxtCilAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLyrAlt", LstLyrAlt);
		writeUintAttr(wr, itemtag, "sref", "LstLyrNumFirstdisp", LstLyrNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkDetail::StatShr
 ******************************************************************************/

PnlPlnrStkDetail::StatShr::StatShr(
			const bool TxfFlrValid
			, const bool TxfCilValid
			, const bool TxfLyrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
			, const bool ButLyrViewAvail
			, const bool ButLyrViewActive
		) : Block() {
	this->TxfFlrValid = TxfFlrValid;
	this->TxfCilValid = TxfCilValid;
	this->TxfLyrValid = TxfLyrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;
	this->ButLyrViewAvail = ButLyrViewAvail;
	this->ButLyrViewActive = ButLyrViewActive;

	mask = {TXFFLRVALID, TXFCILVALID, TXFLYRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL, BUTLYRVIEWACTIVE};
};

void PnlPlnrStkDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfFlrValid", TxfFlrValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfCilValid", TxfCilValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfLyrValid", TxfLyrValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLyrViewAvail", ButLyrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLyrViewActive", ButLyrViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfFlrValid == comp->TxfFlrValid) insert(items, TXFFLRVALID);
	if (TxfCilValid == comp->TxfCilValid) insert(items, TXFCILVALID);
	if (TxfLyrValid == comp->TxfLyrValid) insert(items, TXFLYRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);
	if (ButLyrViewAvail == comp->ButLyrViewAvail) insert(items, BUTLYRVIEWAVAIL);
	if (ButLyrViewActive == comp->ButLyrViewActive) insert(items, BUTLYRVIEWACTIVE);

	return(items);
};

set<uint> PnlPlnrStkDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFLRVALID, TXFCILVALID, TXFLYRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL, BUTLYRVIEWAVAIL, BUTLYRVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkDetail::Tag
 ******************************************************************************/

void PnlPlnrStkDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrStkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrStkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "base type");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptMty", "modification type");
			writeStringAttr(wr, itemtag, "sref", "CptFal", "floor align type");
			writeStringAttr(wr, itemtag, "sref", "CptFlr", "floor level");
			writeStringAttr(wr, itemtag, "sref", "CptZfl", "floor z position [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "ceiling align type");
			writeStringAttr(wr, itemtag, "sref", "CptCil", "ceiling level");
			writeStringAttr(wr, itemtag, "sref", "CptZci", "ceiling z position [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptLyr", "layer sequence");
			writeStringAttr(wr, itemtag, "sref", "CptN", "number of layers");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkDetail::DpchAppData
 ******************************************************************************/

PnlPlnrStkDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDATA) {
};

void PnlPlnrStkDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrStkDetailData");
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
 class PnlPlnrStkDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrStkDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrStkDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrStkDetailDo");
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
 class PnlPlnrStkDetail::DpchEngData
 ******************************************************************************/

PnlPlnrStkDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstLyr
			, Feed* feedFPupCal
			, Feed* feedFPupFal
			, Feed* feedFPupMty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSTKDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTLYR, FEEDFPUPCAL, FEEDFPUPFAL, FEEDFPUPMTY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTLYR) && feedFLstLyr) this->feedFLstLyr = *feedFLstLyr;
	if (find(this->mask, FEEDFPUPCAL) && feedFPupCal) this->feedFPupCal = *feedFPupCal;
	if (find(this->mask, FEEDFPUPFAL) && feedFPupFal) this->feedFPupFal = *feedFPupFal;
	if (find(this->mask, FEEDFPUPMTY) && feedFPupMty) this->feedFPupMty = *feedFPupMty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrStkDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTLYR)) {feedFLstLyr = src->feedFLstLyr; add(FEEDFLSTLYR);};
	if (src->has(FEEDFPUPCAL)) {feedFPupCal = src->feedFPupCal; add(FEEDFPUPCAL);};
	if (src->has(FEEDFPUPFAL)) {feedFPupFal = src->feedFPupFal; add(FEEDFPUPFAL);};
	if (src->has(FEEDFPUPMTY)) {feedFPupMty = src->feedFPupMty; add(FEEDFPUPMTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrStkDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrStkDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTLYR)) feedFLstLyr.writeXML(wr);
		if (has(FEEDFPUPCAL)) feedFPupCal.writeXML(wr);
		if (has(FEEDFPUPFAL)) feedFPupFal.writeXML(wr);
		if (has(FEEDFPUPMTY)) feedFPupMty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


