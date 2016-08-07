/**
  * \file PnlPlnrStkRec_blks.cpp
  * job handler for job PnlPlnrStkRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrStkRec::VecVDo
 ******************************************************************************/

uint PnlPlnrStkRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrStkRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrStkRec::ContInf
 ******************************************************************************/

PnlPlnrStkRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrStkRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrStkRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrStkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrStkRec::ContInf::diff(
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
 class PnlPlnrStkRec::StatApp
 ******************************************************************************/

void PnlPlnrStkRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneHk1NLevel
			, const bool initdoneHk1NLayer
			, const bool initdoneMNStructure
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrStkRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrStkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneView", initdoneView);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLevel", initdoneHk1NLevel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLayer", initdoneHk1NLayer);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNStructure", initdoneMNStructure);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkRec::StatShr
 ******************************************************************************/

PnlPlnrStkRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefView
			, const ubigint jrefHk1NLevel
			, const ubigint jrefHk1NLayer
			, const ubigint jrefMNStructure
			, const bool pnlmnstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefView = jrefView;
	this->jrefHk1NLevel = jrefHk1NLevel;
	this->jrefHk1NLayer = jrefHk1NLayer;
	this->jrefMNStructure = jrefMNStructure;
	this->pnlmnstructureAvail = pnlmnstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFHK1NLEVEL, JREFHK1NLAYER, JREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

void PnlPlnrStkRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrStkRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrStkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefView", Scr::scramble(mScr, scr, descr, jrefView));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLevel", Scr::scramble(mScr, scr, descr, jrefHk1NLevel));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLayer", Scr::scramble(mScr, scr, descr, jrefHk1NLayer));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNStructure", Scr::scramble(mScr, scr, descr, jrefMNStructure));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnstructureAvail", pnlmnstructureAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrStkRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefView == comp->jrefView) insert(items, JREFVIEW);
	if (jrefHk1NLevel == comp->jrefHk1NLevel) insert(items, JREFHK1NLEVEL);
	if (jrefHk1NLayer == comp->jrefHk1NLayer) insert(items, JREFHK1NLAYER);
	if (jrefMNStructure == comp->jrefMNStructure) insert(items, JREFMNSTRUCTURE);
	if (pnlmnstructureAvail == comp->pnlmnstructureAvail) insert(items, PNLMNSTRUCTUREAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrStkRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFHK1NLEVEL, JREFHK1NLAYER, JREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrStkRec::Tag
 ******************************************************************************/

void PnlPlnrStkRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrStkRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrStkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Stack");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrStkRec::DpchAppDo
 ******************************************************************************/

PnlPlnrStkRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRSTKRECDO) {
	ixVDo = 0;
};

void PnlPlnrStkRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrStkRecDo");
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
 class PnlPlnrStkRec::DpchEngData
 ******************************************************************************/

PnlPlnrStkRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSTKRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrStkRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrStkRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrStkRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


