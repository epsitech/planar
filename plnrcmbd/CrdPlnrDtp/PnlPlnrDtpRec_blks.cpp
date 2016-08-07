/**
  * \file PnlPlnrDtpRec_blks.cpp
  * job handler for job PnlPlnrDtpRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDtpRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDtpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrDtpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDtpRec::ContInf
 ******************************************************************************/

PnlPlnrDtpRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrDtpRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDtpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrDtpRec::ContInf::diff(
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
 class PnlPlnrDtpRec::StatApp
 ******************************************************************************/

void PnlPlnrDtpRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneKParKey
			, const bool initdoneAPar
			, const bool initdoneSup1NDevice
			, const bool initdoneHk1NStructure
			, const bool initdoneTpl1NDevice
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneView", initdoneView);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKParKey", initdoneKParKey);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NDevice", initdoneSup1NDevice);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NStructure", initdoneHk1NStructure);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTpl1NDevice", initdoneTpl1NDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDtpRec::StatShr
 ******************************************************************************/

PnlPlnrDtpRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefView
			, const ubigint jrefKParKey
			, const ubigint jrefAPar
			, const ubigint jrefSup1NDevice
			, const ubigint jrefHk1NStructure
			, const ubigint jrefTpl1NDevice
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefView = jrefView;
	this->jrefKParKey = jrefKParKey;
	this->jrefAPar = jrefAPar;
	this->jrefSup1NDevice = jrefSup1NDevice;
	this->jrefHk1NStructure = jrefHk1NStructure;
	this->jrefTpl1NDevice = jrefTpl1NDevice;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFKPARKEY, JREFAPAR, JREFSUP1NDEVICE, JREFHK1NSTRUCTURE, JREFTPL1NDEVICE, BUTREGULARIZEACTIVE};
};

void PnlPlnrDtpRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefView", Scr::scramble(mScr, scr, descr, jrefView));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKParKey", Scr::scramble(mScr, scr, descr, jrefKParKey));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(mScr, scr, descr, jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NDevice", Scr::scramble(mScr, scr, descr, jrefSup1NDevice));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NStructure", Scr::scramble(mScr, scr, descr, jrefHk1NStructure));
		writeStringAttr(wr, itemtag, "sref", "scrJrefTpl1NDevice", Scr::scramble(mScr, scr, descr, jrefTpl1NDevice));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefView == comp->jrefView) insert(items, JREFVIEW);
	if (jrefKParKey == comp->jrefKParKey) insert(items, JREFKPARKEY);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jrefSup1NDevice == comp->jrefSup1NDevice) insert(items, JREFSUP1NDEVICE);
	if (jrefHk1NStructure == comp->jrefHk1NStructure) insert(items, JREFHK1NSTRUCTURE);
	if (jrefTpl1NDevice == comp->jrefTpl1NDevice) insert(items, JREFTPL1NDEVICE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrDtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFKPARKEY, JREFAPAR, JREFSUP1NDEVICE, JREFHK1NSTRUCTURE, JREFTPL1NDEVICE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDtpRec::Tag
 ******************************************************************************/

void PnlPlnrDtpRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Device template");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDtpRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDtpRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDTPRECDO) {
	ixVDo = 0;
};

void PnlPlnrDtpRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDtpRecDo");
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
 class PnlPlnrDtpRec::DpchEngData
 ******************************************************************************/

PnlPlnrDtpRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDTPRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDtpRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDtpRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDtpRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


