/**
  * \file PnlPlnrNavLayout_blks.cpp
  * job handler for job PnlPlnrNavLayout (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavLayout::VecVDo
 ******************************************************************************/

uint PnlPlnrNavLayout::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "buttpoviewclick") return BUTTPOVIEWCLICK;
	else if (s == "buttponewcrdclick") return BUTTPONEWCRDCLICK;
	else if (s == "butarrviewclick") return BUTARRVIEWCLICK;
	else if (s == "butariviewclick") return BUTARIVIEWCLICK;
	else if (s == "butrtcviewclick") return BUTRTCVIEWCLICK;

	return(0);
};

string PnlPlnrNavLayout::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTTPOVIEWCLICK) return("ButTpoViewClick");
	else if (ix == BUTTPONEWCRDCLICK) return("ButTpoNewcrdClick");
	else if (ix == BUTARRVIEWCLICK) return("ButArrViewClick");
	else if (ix == BUTARIVIEWCLICK) return("ButAriViewClick");
	else if (ix == BUTRTCVIEWCLICK) return("ButRtcViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavLayout::ContIac
 ******************************************************************************/

PnlPlnrNavLayout::ContIac::ContIac(
			const uint numFLstTpo
			, const uint numFLstArr
			, const uint numFLstAri
			, const uint numFLstRtc
		) : Block() {
	this->numFLstTpo = numFLstTpo;
	this->numFLstArr = numFLstArr;
	this->numFLstAri = numFLstAri;
	this->numFLstRtc = numFLstRtc;

	mask = {NUMFLSTTPO, NUMFLSTARR, NUMFLSTARI, NUMFLSTRTC};
};

bool PnlPlnrNavLayout::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavLayout");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavLayout";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTpo", numFLstTpo)) add(NUMFLSTTPO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstArr", numFLstArr)) add(NUMFLSTARR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstAri", numFLstAri)) add(NUMFLSTARI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtc", numFLstRtc)) add(NUMFLSTRTC);
	};

	return basefound;
};

void PnlPlnrNavLayout::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavLayout";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavLayout";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstTpo", numFLstTpo);
		writeUintAttr(wr, itemtag, "sref", "numFLstArr", numFLstArr);
		writeUintAttr(wr, itemtag, "sref", "numFLstAri", numFLstAri);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtc", numFLstRtc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavLayout::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstTpo == comp->numFLstTpo) insert(items, NUMFLSTTPO);
	if (numFLstArr == comp->numFLstArr) insert(items, NUMFLSTARR);
	if (numFLstAri == comp->numFLstAri) insert(items, NUMFLSTARI);
	if (numFLstRtc == comp->numFLstRtc) insert(items, NUMFLSTRTC);

	return(items);
};

set<uint> PnlPlnrNavLayout::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTTPO, NUMFLSTARR, NUMFLSTARI, NUMFLSTRTC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavLayout::StatApp
 ******************************************************************************/

void PnlPlnrNavLayout::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool LstTpoAlt
			, const bool LstArrAlt
			, const bool LstAriAlt
			, const bool LstRtcAlt
			, const uint LstTpoNumFirstdisp
			, const uint LstArrNumFirstdisp
			, const uint LstAriNumFirstdisp
			, const uint LstRtcNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrNavLayout";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrNavLayout";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstTpoAlt", LstTpoAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstArrAlt", LstArrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstAriAlt", LstAriAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRtcAlt", LstRtcAlt);
		writeUintAttr(wr, itemtag, "sref", "LstTpoNumFirstdisp", LstTpoNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstArrNumFirstdisp", LstArrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstAriNumFirstdisp", LstAriNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRtcNumFirstdisp", LstRtcNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavLayout::StatShr
 ******************************************************************************/

PnlPlnrNavLayout::StatShr::StatShr(
			const bool LstTpoAvail
			, const bool ButTpoViewActive
			, const bool LstArrAvail
			, const bool ButArrViewActive
			, const bool LstAriAvail
			, const bool ButAriViewActive
			, const bool LstRtcAvail
			, const bool ButRtcViewActive
		) : Block() {
	this->LstTpoAvail = LstTpoAvail;
	this->ButTpoViewActive = ButTpoViewActive;
	this->LstArrAvail = LstArrAvail;
	this->ButArrViewActive = ButArrViewActive;
	this->LstAriAvail = LstAriAvail;
	this->ButAriViewActive = ButAriViewActive;
	this->LstRtcAvail = LstRtcAvail;
	this->ButRtcViewActive = ButRtcViewActive;

	mask = {LSTTPOAVAIL, BUTTPOVIEWACTIVE, LSTARRAVAIL, BUTARRVIEWACTIVE, LSTARIAVAIL, BUTARIVIEWACTIVE, LSTRTCAVAIL, BUTRTCVIEWACTIVE};
};

void PnlPlnrNavLayout::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavLayout";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavLayout";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstTpoAvail", LstTpoAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTpoViewActive", ButTpoViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstArrAvail", LstArrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButArrViewActive", ButArrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstAriAvail", LstAriAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButAriViewActive", ButAriViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRtcAvail", LstRtcAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRtcViewActive", ButRtcViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavLayout::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstTpoAvail == comp->LstTpoAvail) insert(items, LSTTPOAVAIL);
	if (ButTpoViewActive == comp->ButTpoViewActive) insert(items, BUTTPOVIEWACTIVE);
	if (LstArrAvail == comp->LstArrAvail) insert(items, LSTARRAVAIL);
	if (ButArrViewActive == comp->ButArrViewActive) insert(items, BUTARRVIEWACTIVE);
	if (LstAriAvail == comp->LstAriAvail) insert(items, LSTARIAVAIL);
	if (ButAriViewActive == comp->ButAriViewActive) insert(items, BUTARIVIEWACTIVE);
	if (LstRtcAvail == comp->LstRtcAvail) insert(items, LSTRTCAVAIL);
	if (ButRtcViewActive == comp->ButRtcViewActive) insert(items, BUTRTCVIEWACTIVE);

	return(items);
};

set<uint> PnlPlnrNavLayout::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTTPOAVAIL, BUTTPOVIEWACTIVE, LSTARRAVAIL, BUTARRVIEWACTIVE, LSTARIAVAIL, BUTARIVIEWACTIVE, LSTRTCAVAIL, BUTRTCVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavLayout::Tag
 ******************************************************************************/

void PnlPlnrNavLayout::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavLayout";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavLayout";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Layout module");
			writeStringAttr(wr, itemtag, "sref", "CptTpo", "tape-outs");
			writeStringAttr(wr, itemtag, "sref", "CptArr", "arrays");
			writeStringAttr(wr, itemtag, "sref", "CptAri", "array items");
			writeStringAttr(wr, itemtag, "sref", "CptRtc", "reticles");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavLayout::DpchAppData
 ******************************************************************************/

PnlPlnrNavLayout::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDATA) {
};

void PnlPlnrNavLayout::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavLayoutData");
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
 class PnlPlnrNavLayout::DpchAppDo
 ******************************************************************************/

PnlPlnrNavLayout::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDO) {
	ixVDo = 0;
};

void PnlPlnrNavLayout::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavLayoutDo");
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
 class PnlPlnrNavLayout::DpchEngData
 ******************************************************************************/

PnlPlnrNavLayout::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstAri
			, Feed* feedFLstArr
			, Feed* feedFLstRtc
			, Feed* feedFLstTpo
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVLAYOUTDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTARI, FEEDFLSTARR, FEEDFLSTRTC, FEEDFLSTTPO, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTARI) && feedFLstAri) this->feedFLstAri = *feedFLstAri;
	if (find(this->mask, FEEDFLSTARR) && feedFLstArr) this->feedFLstArr = *feedFLstArr;
	if (find(this->mask, FEEDFLSTRTC) && feedFLstRtc) this->feedFLstRtc = *feedFLstRtc;
	if (find(this->mask, FEEDFLSTTPO) && feedFLstTpo) this->feedFLstTpo = *feedFLstTpo;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavLayout::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTARI)) {feedFLstAri = src->feedFLstAri; add(FEEDFLSTARI);};
	if (src->has(FEEDFLSTARR)) {feedFLstArr = src->feedFLstArr; add(FEEDFLSTARR);};
	if (src->has(FEEDFLSTRTC)) {feedFLstRtc = src->feedFLstRtc; add(FEEDFLSTRTC);};
	if (src->has(FEEDFLSTTPO)) {feedFLstTpo = src->feedFLstTpo; add(FEEDFLSTTPO);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavLayout::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavLayoutData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTARI)) feedFLstAri.writeXML(wr);
		if (has(FEEDFLSTARR)) feedFLstArr.writeXML(wr);
		if (has(FEEDFLSTRTC)) feedFLstRtc.writeXML(wr);
		if (has(FEEDFLSTTPO)) feedFLstTpo.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


