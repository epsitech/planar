/**
  * \file PnlPlnrLyrRec_blks.cpp
  * job handler for job PnlPlnrLyrRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrLyrRec::VecVDo
 ******************************************************************************/

uint PnlPlnrLyrRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrLyrRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrLyrRec::ContInf
 ******************************************************************************/

PnlPlnrLyrRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrLyrRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrLyrRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrLyrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrLyrRec::ContInf::diff(
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
 class PnlPlnrLyrRec::StatApp
 ******************************************************************************/

void PnlPlnrLyrRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NBlock
			, const bool initdone1NReticle
			, const bool initdoneMNStructure
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrLyrRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrLyrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBlock", initdone1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NReticle", initdone1NReticle);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNStructure", initdoneMNStructure);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrRec::StatShr
 ******************************************************************************/

PnlPlnrLyrRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NBlock
			, const bool pnl1nblockAvail
			, const ubigint jref1NReticle
			, const bool pnl1nreticleAvail
			, const ubigint jrefMNStructure
			, const bool pnlmnstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NBlock = jref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->jref1NReticle = jref1NReticle;
	this->pnl1nreticleAvail = pnl1nreticleAvail;
	this->jrefMNStructure = jrefMNStructure;
	this->pnlmnstructureAvail = pnlmnstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFDETAIL, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREF1NRETICLE, PNL1NRETICLEAVAIL, JREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

void PnlPlnrLyrRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrLyrRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrLyrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBlock", Scr::scramble(mScr, scr, descr, jref1NBlock));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nblockAvail", pnl1nblockAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NReticle", Scr::scramble(mScr, scr, descr, jref1NReticle));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nreticleAvail", pnl1nreticleAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNStructure", Scr::scramble(mScr, scr, descr, jrefMNStructure));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnstructureAvail", pnlmnstructureAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrLyrRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NBlock == comp->jref1NBlock) insert(items, JREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (jref1NReticle == comp->jref1NReticle) insert(items, JREF1NRETICLE);
	if (pnl1nreticleAvail == comp->pnl1nreticleAvail) insert(items, PNL1NRETICLEAVAIL);
	if (jrefMNStructure == comp->jrefMNStructure) insert(items, JREFMNSTRUCTURE);
	if (pnlmnstructureAvail == comp->pnlmnstructureAvail) insert(items, PNLMNSTRUCTUREAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrLyrRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFDETAIL, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREF1NRETICLE, PNL1NRETICLEAVAIL, JREFMNSTRUCTURE, PNLMNSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrLyrRec::Tag
 ******************************************************************************/

void PnlPlnrLyrRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrLyrRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrLyrRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Layer");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrLyrRec::DpchAppDo
 ******************************************************************************/

PnlPlnrLyrRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRLYRRECDO) {
	ixVDo = 0;
};

void PnlPlnrLyrRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrLyrRecDo");
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
 class PnlPlnrLyrRec::DpchEngData
 ******************************************************************************/

PnlPlnrLyrRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRLYRRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrLyrRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrLyrRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrLyrRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


