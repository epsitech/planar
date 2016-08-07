/**
  * \file PnlPlnrSruRec_blks.cpp
  * job handler for job PnlPlnrSruRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrSruRec::VecVDo
 ******************************************************************************/

uint PnlPlnrSruRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrSruRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrSruRec::ContInf
 ******************************************************************************/

PnlPlnrSruRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrSruRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrSruRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrSruRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrSruRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruRec::StatApp
 ******************************************************************************/

void PnlPlnrSruRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NBlock
			, const bool initdoneSru1NFace
			, const bool initdoneMNLayer
			, const bool initdoneMNStack
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrSruRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrSruRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBlock", initdone1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSru1NFace", initdoneSru1NFace);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLayer", initdoneMNLayer);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNStack", initdoneMNStack);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruRec::StatShr
 ******************************************************************************/

PnlPlnrSruRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NBlock
			, const bool pnl1nblockAvail
			, const ubigint jrefSru1NFace
			, const ubigint jrefMNLayer
			, const bool pnlmnlayerAvail
			, const ubigint jrefMNStack
			, const bool pnlmnstackAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NBlock = jref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->jrefSru1NFace = jrefSru1NFace;
	this->jrefMNLayer = jrefMNLayer;
	this->pnlmnlayerAvail = pnlmnlayerAvail;
	this->jrefMNStack = jrefMNStack;
	this->pnlmnstackAvail = pnlmnstackAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFDETAIL, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREFSRU1NFACE, JREFMNLAYER, PNLMNLAYERAVAIL, JREFMNSTACK, PNLMNSTACKAVAIL, BUTREGULARIZEACTIVE};
};

void PnlPlnrSruRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrSruRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrSruRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBlock", Scr::scramble(mScr, scr, descr, jref1NBlock));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nblockAvail", pnl1nblockAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefSru1NFace", Scr::scramble(mScr, scr, descr, jrefSru1NFace));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLayer", Scr::scramble(mScr, scr, descr, jrefMNLayer));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnlayerAvail", pnlmnlayerAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNStack", Scr::scramble(mScr, scr, descr, jrefMNStack));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnstackAvail", pnlmnstackAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrSruRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NBlock == comp->jref1NBlock) insert(items, JREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (jrefSru1NFace == comp->jrefSru1NFace) insert(items, JREFSRU1NFACE);
	if (jrefMNLayer == comp->jrefMNLayer) insert(items, JREFMNLAYER);
	if (pnlmnlayerAvail == comp->pnlmnlayerAvail) insert(items, PNLMNLAYERAVAIL);
	if (jrefMNStack == comp->jrefMNStack) insert(items, JREFMNSTACK);
	if (pnlmnstackAvail == comp->pnlmnstackAvail) insert(items, PNLMNSTACKAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrSruRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFDETAIL, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREFSRU1NFACE, JREFMNLAYER, PNLMNLAYERAVAIL, JREFMNSTACK, PNLMNSTACKAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrSruRec::Tag
 ******************************************************************************/

void PnlPlnrSruRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrSruRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrSruRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Structure");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrSruRec::DpchAppDo
 ******************************************************************************/

PnlPlnrSruRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSRURECDO) {
	ixVDo = 0;
};

void PnlPlnrSruRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrSruRecDo");
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
 class PnlPlnrSruRec::DpchEngData
 ******************************************************************************/

PnlPlnrSruRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSRURECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrSruRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrSruRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrSruRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


