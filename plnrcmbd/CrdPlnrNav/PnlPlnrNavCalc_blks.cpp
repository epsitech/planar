/**
  * \file PnlPlnrNavCalc_blks.cpp
  * job handler for job PnlPlnrNavCalc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavCalc::VecVDo
 ******************************************************************************/

uint PnlPlnrNavCalc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butclcviewclick") return BUTCLCVIEWCLICK;
	else if (s == "butclcnewcrdclick") return BUTCLCNEWCRDCLICK;
	else if (s == "butcliviewclick") return BUTCLIVIEWCLICK;
	else if (s == "butclinewcrdclick") return BUTCLINEWCRDCLICK;

	return(0);
};

string PnlPlnrNavCalc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCLCVIEWCLICK) return("ButClcViewClick");
	else if (ix == BUTCLCNEWCRDCLICK) return("ButClcNewcrdClick");
	else if (ix == BUTCLIVIEWCLICK) return("ButCliViewClick");
	else if (ix == BUTCLINEWCRDCLICK) return("ButCliNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavCalc::ContIac
 ******************************************************************************/

PnlPlnrNavCalc::ContIac::ContIac(
			const uint numFLstClc
			, const uint numFLstCli
		) : Block() {
	this->numFLstClc = numFLstClc;
	this->numFLstCli = numFLstCli;

	mask = {NUMFLSTCLC, NUMFLSTCLI};
};

bool PnlPlnrNavCalc::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavCalc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClc", numFLstClc)) add(NUMFLSTCLC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCli", numFLstCli)) add(NUMFLSTCLI);
	};

	return basefound;
};

void PnlPlnrNavCalc::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavCalc";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClc", numFLstClc);
		writeUintAttr(wr, itemtag, "sref", "numFLstCli", numFLstCli);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavCalc::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClc == comp->numFLstClc) insert(items, NUMFLSTCLC);
	if (numFLstCli == comp->numFLstCli) insert(items, NUMFLSTCLI);

	return(items);
};

set<uint> PnlPlnrNavCalc::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLC, NUMFLSTCLI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavCalc::StatApp
 ******************************************************************************/

void PnlPlnrNavCalc::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
			, const bool LstClcAlt
			, const bool LstCliAlt
			, const uint LstClcNumFirstdisp
			, const uint LstCliNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrNavCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrNavCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstClcAlt", LstClcAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCliAlt", LstCliAlt);
		writeUintAttr(wr, itemtag, "sref", "LstClcNumFirstdisp", LstClcNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCliNumFirstdisp", LstCliNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavCalc::StatShr
 ******************************************************************************/

PnlPlnrNavCalc::StatShr::StatShr(
			const bool LstClcAvail
			, const bool ButClcViewActive
			, const bool ButClcNewcrdActive
			, const bool LstCliAvail
			, const bool ButCliViewActive
			, const bool ButCliNewcrdActive
		) : Block() {
	this->LstClcAvail = LstClcAvail;
	this->ButClcViewActive = ButClcViewActive;
	this->ButClcNewcrdActive = ButClcNewcrdActive;
	this->LstCliAvail = LstCliAvail;
	this->ButCliViewActive = ButCliViewActive;
	this->ButCliNewcrdActive = ButCliNewcrdActive;

	mask = {LSTCLCAVAIL, BUTCLCVIEWACTIVE, BUTCLCNEWCRDACTIVE, LSTCLIAVAIL, BUTCLIVIEWACTIVE, BUTCLINEWCRDACTIVE};
};

void PnlPlnrNavCalc::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstClcAvail", LstClcAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButClcViewActive", ButClcViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButClcNewcrdActive", ButClcNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCliAvail", LstCliAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCliViewActive", ButCliViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCliNewcrdActive", ButCliNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavCalc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstClcAvail == comp->LstClcAvail) insert(items, LSTCLCAVAIL);
	if (ButClcViewActive == comp->ButClcViewActive) insert(items, BUTCLCVIEWACTIVE);
	if (ButClcNewcrdActive == comp->ButClcNewcrdActive) insert(items, BUTCLCNEWCRDACTIVE);
	if (LstCliAvail == comp->LstCliAvail) insert(items, LSTCLIAVAIL);
	if (ButCliViewActive == comp->ButCliViewActive) insert(items, BUTCLIVIEWACTIVE);
	if (ButCliNewcrdActive == comp->ButCliNewcrdActive) insert(items, BUTCLINEWCRDACTIVE);

	return(items);
};

set<uint> PnlPlnrNavCalc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCLCAVAIL, BUTCLCVIEWACTIVE, BUTCLCNEWCRDACTIVE, LSTCLIAVAIL, BUTCLIVIEWACTIVE, BUTCLINEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavCalc::Tag
 ******************************************************************************/

void PnlPlnrNavCalc::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavCalc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Calculation module");
			writeStringAttr(wr, itemtag, "sref", "CptClc", "calculations");
			writeStringAttr(wr, itemtag, "sref", "CptCli", "calculation items");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavCalc::DpchAppData
 ******************************************************************************/

PnlPlnrNavCalc::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVCALCDATA) {
};

void PnlPlnrNavCalc::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavCalcData");
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
 class PnlPlnrNavCalc::DpchAppDo
 ******************************************************************************/

PnlPlnrNavCalc::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVCALCDO) {
	ixVDo = 0;
};

void PnlPlnrNavCalc::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavCalcDo");
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
 class PnlPlnrNavCalc::DpchEngData
 ******************************************************************************/

PnlPlnrNavCalc::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstClc
			, Feed* feedFLstCli
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVCALCDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCLC, FEEDFLSTCLI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCLC) && feedFLstClc) this->feedFLstClc = *feedFLstClc;
	if (find(this->mask, FEEDFLSTCLI) && feedFLstCli) this->feedFLstCli = *feedFLstCli;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavCalc::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCLC)) {feedFLstClc = src->feedFLstClc; add(FEEDFLSTCLC);};
	if (src->has(FEEDFLSTCLI)) {feedFLstCli = src->feedFLstCli; add(FEEDFLSTCLI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavCalc::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavCalcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCLC)) feedFLstClc.writeXML(wr);
		if (has(FEEDFLSTCLI)) feedFLstCli.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


