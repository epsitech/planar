/**
  * \file PnlPlnrDvcRec_blks.cpp
  * job handler for job PnlPlnrDvcRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDvcRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDvcRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrDvcRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDvcRec::ContInf
 ******************************************************************************/

PnlPlnrDvcRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrDvcRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDvcRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDvcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDvcRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrDvcRec::ContInf::diff(
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
 class PnlPlnrDvcRec::StatApp
 ******************************************************************************/

void PnlPlnrDvcRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneAPar
			, const bool initdoneSup1NDevice
			, const bool initdoneHk1NStructure
			, const bool initdoneHk1NVertex
			, const bool initdoneHk1NLineguide
			, const bool initdoneHk1NArcguide
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDvcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDvcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneView", initdoneView);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NDevice", initdoneSup1NDevice);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NStructure", initdoneHk1NStructure);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVertex", initdoneHk1NVertex);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLineguide", initdoneHk1NLineguide);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NArcguide", initdoneHk1NArcguide);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDvcRec::StatShr
 ******************************************************************************/

PnlPlnrDvcRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefView
			, const ubigint jrefAPar
			, const ubigint jrefSup1NDevice
			, const ubigint jrefHk1NStructure
			, const ubigint jrefHk1NVertex
			, const ubigint jrefHk1NLineguide
			, const ubigint jrefHk1NArcguide
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefView = jrefView;
	this->jrefAPar = jrefAPar;
	this->jrefSup1NDevice = jrefSup1NDevice;
	this->jrefHk1NStructure = jrefHk1NStructure;
	this->jrefHk1NVertex = jrefHk1NVertex;
	this->jrefHk1NLineguide = jrefHk1NLineguide;
	this->jrefHk1NArcguide = jrefHk1NArcguide;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFAPAR, JREFSUP1NDEVICE, JREFHK1NSTRUCTURE, JREFHK1NVERTEX, JREFHK1NLINEGUIDE, JREFHK1NARCGUIDE, BUTREGULARIZEACTIVE};
};

void PnlPlnrDvcRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDvcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDvcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefView", Scr::scramble(mScr, scr, descr, jrefView));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(mScr, scr, descr, jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NDevice", Scr::scramble(mScr, scr, descr, jrefSup1NDevice));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NStructure", Scr::scramble(mScr, scr, descr, jrefHk1NStructure));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVertex", Scr::scramble(mScr, scr, descr, jrefHk1NVertex));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLineguide", Scr::scramble(mScr, scr, descr, jrefHk1NLineguide));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NArcguide", Scr::scramble(mScr, scr, descr, jrefHk1NArcguide));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDvcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefView == comp->jrefView) insert(items, JREFVIEW);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jrefSup1NDevice == comp->jrefSup1NDevice) insert(items, JREFSUP1NDEVICE);
	if (jrefHk1NStructure == comp->jrefHk1NStructure) insert(items, JREFHK1NSTRUCTURE);
	if (jrefHk1NVertex == comp->jrefHk1NVertex) insert(items, JREFHK1NVERTEX);
	if (jrefHk1NLineguide == comp->jrefHk1NLineguide) insert(items, JREFHK1NLINEGUIDE);
	if (jrefHk1NArcguide == comp->jrefHk1NArcguide) insert(items, JREFHK1NARCGUIDE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrDvcRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFAPAR, JREFSUP1NDEVICE, JREFHK1NSTRUCTURE, JREFHK1NVERTEX, JREFHK1NLINEGUIDE, JREFHK1NARCGUIDE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDvcRec::Tag
 ******************************************************************************/

void PnlPlnrDvcRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDvcRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDvcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Device");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDvcRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDvcRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDVCRECDO) {
	ixVDo = 0;
};

void PnlPlnrDvcRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDvcRecDo");
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
 class PnlPlnrDvcRec::DpchEngData
 ******************************************************************************/

PnlPlnrDvcRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDVCRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDvcRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDvcRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDvcRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


