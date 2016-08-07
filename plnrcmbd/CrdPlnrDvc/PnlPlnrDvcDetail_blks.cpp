/**
  * \file PnlPlnrDvcDetail_blks.cpp
  * job handler for job PnlPlnrDvcDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDvcDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDvcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;

	return(0);
};

string PnlPlnrDvcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDvcDetail::ContIac
 ******************************************************************************/

PnlPlnrDvcDetail::ContIac::ContIac(
			const uint numFPupMty
			, const uint numFPupAty
			, const string& TxfAv1
			, const string& TxfPv1
			, const string& TxfAv2
			, const string& TxfPv2
			, const string& TxfX
			, const string& TxfY
			, const string& TxfPhi
			, const string& TxfCmt
		) : Block() {
	this->numFPupMty = numFPupMty;
	this->numFPupAty = numFPupAty;
	this->TxfAv1 = TxfAv1;
	this->TxfPv1 = TxfPv1;
	this->TxfAv2 = TxfAv2;
	this->TxfPv2 = TxfPv2;
	this->TxfX = TxfX;
	this->TxfY = TxfY;
	this->TxfPhi = TxfPhi;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPMTY, NUMFPUPATY, TXFAV1, TXFPV1, TXFAV2, TXFPV2, TXFX, TXFY, TXFPHI, TXFCMT};
};

bool PnlPlnrDvcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDvcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDvcDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMty", numFPupMty)) add(NUMFPUPMTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAty", numFPupAty)) add(NUMFPUPATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv1", TxfAv1)) add(TXFAV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPv1", TxfPv1)) add(TXFPV1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAv2", TxfAv2)) add(TXFAV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPv2", TxfPv2)) add(TXFPV2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX", TxfX)) add(TXFX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY", TxfY)) add(TXFY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPhi", TxfPhi)) add(TXFPHI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlPlnrDvcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDvcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDvcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupMty", numFPupMty);
		writeUintAttr(wr, itemtag, "sref", "numFPupAty", numFPupAty);
		writeStringAttr(wr, itemtag, "sref", "TxfAv1", TxfAv1);
		writeStringAttr(wr, itemtag, "sref", "TxfPv1", TxfPv1);
		writeStringAttr(wr, itemtag, "sref", "TxfAv2", TxfAv2);
		writeStringAttr(wr, itemtag, "sref", "TxfPv2", TxfPv2);
		writeStringAttr(wr, itemtag, "sref", "TxfX", TxfX);
		writeStringAttr(wr, itemtag, "sref", "TxfY", TxfY);
		writeStringAttr(wr, itemtag, "sref", "TxfPhi", TxfPhi);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDvcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupMty == comp->numFPupMty) insert(items, NUMFPUPMTY);
	if (numFPupAty == comp->numFPupAty) insert(items, NUMFPUPATY);
	if (TxfAv1 == comp->TxfAv1) insert(items, TXFAV1);
	if (TxfPv1 == comp->TxfPv1) insert(items, TXFPV1);
	if (TxfAv2 == comp->TxfAv2) insert(items, TXFAV2);
	if (TxfPv2 == comp->TxfPv2) insert(items, TXFPV2);
	if (TxfX == comp->TxfX) insert(items, TXFX);
	if (TxfY == comp->TxfY) insert(items, TXFY);
	if (TxfPhi == comp->TxfPhi) insert(items, TXFPHI);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlPlnrDvcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPMTY, NUMFPUPATY, TXFAV1, TXFPV1, TXFAV2, TXFPV2, TXFX, TXFY, TXFPHI, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcDetail::ContInf
 ******************************************************************************/

PnlPlnrDvcDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtDsn
			, const string& TxtSup
			, const string& TxtTpl
			, const string& TxtAv1
			, const string& TxtPv1
			, const string& TxtAv2
			, const string& TxtPv2
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtDsn = TxtDsn;
	this->TxtSup = TxtSup;
	this->TxtTpl = TxtTpl;
	this->TxtAv1 = TxtAv1;
	this->TxtPv1 = TxtPv1;
	this->TxtAv2 = TxtAv2;
	this->TxtPv2 = TxtPv2;

	mask = {TXTSRF, TXTDSN, TXTSUP, TXTTPL, TXTAV1, TXTPV1, TXTAV2, TXTPV2};
};

void PnlPlnrDvcDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDvcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDvcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtDsn", TxtDsn);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTpl", TxtTpl);
		writeStringAttr(wr, itemtag, "sref", "TxtAv1", TxtAv1);
		writeStringAttr(wr, itemtag, "sref", "TxtPv1", TxtPv1);
		writeStringAttr(wr, itemtag, "sref", "TxtAv2", TxtAv2);
		writeStringAttr(wr, itemtag, "sref", "TxtPv2", TxtPv2);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDvcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtDsn == comp->TxtDsn) insert(items, TXTDSN);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTpl == comp->TxtTpl) insert(items, TXTTPL);
	if (TxtAv1 == comp->TxtAv1) insert(items, TXTAV1);
	if (TxtPv1 == comp->TxtPv1) insert(items, TXTPV1);
	if (TxtAv2 == comp->TxtAv2) insert(items, TXTAV2);
	if (TxtPv2 == comp->TxtPv2) insert(items, TXTPV2);

	return(items);
};

set<uint> PnlPlnrDvcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTDSN, TXTSUP, TXTTPL, TXTAV1, TXTPV1, TXTAV2, TXTPV2};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcDetail::StatApp
 ******************************************************************************/

void PnlPlnrDvcDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool TxtAv1Alt
			, const bool TxtPv1Alt
			, const bool TxtAv2Alt
			, const bool TxtPv2Alt
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDvcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDvcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtAv1Alt", TxtAv1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtPv1Alt", TxtPv1Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAv2Alt", TxtAv2Alt);
		writeBoolAttr(wr, itemtag, "sref", "TxtPv2Alt", TxtPv2Alt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDvcDetail::StatShr
 ******************************************************************************/

PnlPlnrDvcDetail::StatShr::StatShr(
			const bool TxfAv1Valid
			, const bool TxfPv1Valid
			, const bool TxfAv2Valid
			, const bool TxfPv2Valid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButDsnViewAvail
		) : Block() {
	this->TxfAv1Valid = TxfAv1Valid;
	this->TxfPv1Valid = TxfPv1Valid;
	this->TxfAv2Valid = TxfAv2Valid;
	this->TxfPv2Valid = TxfPv2Valid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButDsnViewAvail = ButDsnViewAvail;

	mask = {TXFAV1VALID, TXFPV1VALID, TXFAV2VALID, TXFPV2VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
};

void PnlPlnrDvcDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDvcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDvcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfAv1Valid", TxfAv1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfPv1Valid", TxfPv1Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAv2Valid", TxfAv2Valid);
		writeBoolAttr(wr, itemtag, "sref", "TxfPv2Valid", TxfPv2Valid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewAvail", ButDsnViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDvcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAv1Valid == comp->TxfAv1Valid) insert(items, TXFAV1VALID);
	if (TxfPv1Valid == comp->TxfPv1Valid) insert(items, TXFPV1VALID);
	if (TxfAv2Valid == comp->TxfAv2Valid) insert(items, TXFAV2VALID);
	if (TxfPv2Valid == comp->TxfPv2Valid) insert(items, TXFPV2VALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButDsnViewAvail == comp->ButDsnViewAvail) insert(items, BUTDSNVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDvcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFAV1VALID, TXFPV1VALID, TXFAV2VALID, TXFPV2VALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTDSNVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcDetail::Tag
 ******************************************************************************/

void PnlPlnrDvcDetail::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDvcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDvcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "design");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super device");
			writeStringAttr(wr, itemtag, "sref", "CptTpl", "template");
			writeStringAttr(wr, itemtag, "sref", "CptMty", "modification type");
			writeStringAttr(wr, itemtag, "sref", "CptAty", "align type");
			writeStringAttr(wr, itemtag, "sref", "CptAv1", "align vertex 1");
			writeStringAttr(wr, itemtag, "sref", "CptPv1", "partner align vertex 1");
			writeStringAttr(wr, itemtag, "sref", "CptAv2", "align vertex 2");
			writeStringAttr(wr, itemtag, "sref", "CptPv2", "partner align vertex 2");
			writeStringAttr(wr, itemtag, "sref", "CptX", "x position [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptY", "y position [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "rotation angle [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DETAIL, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDvcDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDvcDetail::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDVCDETAILDATA) {
};

void PnlPlnrDvcDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDvcDetailData");
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
 class PnlPlnrDvcDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDvcDetail::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDVCDETAILDO) {
	ixVDo = 0;
};

void PnlPlnrDvcDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDvcDetailDo");
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
 class PnlPlnrDvcDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDvcDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupAty
			, Feed* feedFPupMty
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDVCDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPATY, FEEDFPUPMTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPATY) && feedFPupAty) this->feedFPupAty = *feedFPupAty;
	if (find(this->mask, FEEDFPUPMTY) && feedFPupMty) this->feedFPupMty = *feedFPupMty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDvcDetail::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPATY)) {feedFPupAty = src->feedFPupAty; add(FEEDFPUPATY);};
	if (src->has(FEEDFPUPMTY)) {feedFPupMty = src->feedFPupMty; add(FEEDFPUPMTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDvcDetail::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDvcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPATY)) feedFPupAty.writeXML(wr);
		if (has(FEEDFPUPMTY)) feedFPupMty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


