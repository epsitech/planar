/**
  * \file PnlPlnrArrRec_blks.cpp
  * job handler for job PnlPlnrArrRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrArrRec::VecVDo
 ******************************************************************************/

uint PnlPlnrArrRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrArrRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrArrRec::ContInf
 ******************************************************************************/

PnlPlnrArrRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrArrRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrArrRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrArrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrArrRec::ContInf::diff(
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
 class PnlPlnrArrRec::StatApp
 ******************************************************************************/

void PnlPlnrArrRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKEnvKey
			, const bool initdoneAEnv
			, const bool initdone1NArrayitem
			, const bool initdoneHk1NReticle
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrArrRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrArrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKEnvKey", initdoneKEnvKey);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAEnv", initdoneAEnv);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NArrayitem", initdone1NArrayitem);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NReticle", initdoneHk1NReticle);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrRec::StatShr
 ******************************************************************************/

PnlPlnrArrRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKEnvKey
			, const ubigint jrefAEnv
			, const ubigint jref1NArrayitem
			, const ubigint jrefHk1NReticle
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKEnvKey = jrefKEnvKey;
	this->jrefAEnv = jrefAEnv;
	this->jref1NArrayitem = jref1NArrayitem;
	this->jrefHk1NReticle = jrefHk1NReticle;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFDETAIL, JREFKENVKEY, JREFAENV, JREF1NARRAYITEM, JREFHK1NRETICLE, BUTREGULARIZEACTIVE};
};

void PnlPlnrArrRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrArrRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrArrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKEnvKey", Scr::scramble(mScr, scr, descr, jrefKEnvKey));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAEnv", Scr::scramble(mScr, scr, descr, jrefAEnv));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NArrayitem", Scr::scramble(mScr, scr, descr, jref1NArrayitem));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NReticle", Scr::scramble(mScr, scr, descr, jrefHk1NReticle));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrArrRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKEnvKey == comp->jrefKEnvKey) insert(items, JREFKENVKEY);
	if (jrefAEnv == comp->jrefAEnv) insert(items, JREFAENV);
	if (jref1NArrayitem == comp->jref1NArrayitem) insert(items, JREF1NARRAYITEM);
	if (jrefHk1NReticle == comp->jrefHk1NReticle) insert(items, JREFHK1NRETICLE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrArrRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFDETAIL, JREFKENVKEY, JREFAENV, JREF1NARRAYITEM, JREFHK1NRETICLE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrArrRec::Tag
 ******************************************************************************/

void PnlPlnrArrRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrArrRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrArrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Array");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrArrRec::DpchAppDo
 ******************************************************************************/

PnlPlnrArrRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRARRRECDO) {
	ixVDo = 0;
};

void PnlPlnrArrRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrArrRecDo");
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
 class PnlPlnrArrRec::DpchEngData
 ******************************************************************************/

PnlPlnrArrRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRARRRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrArrRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrArrRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrArrRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


