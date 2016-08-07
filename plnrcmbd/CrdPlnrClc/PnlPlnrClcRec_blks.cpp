/**
  * \file PnlPlnrClcRec_blks.cpp
  * job handler for job PnlPlnrClcRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrClcRec::VecVDo
 ******************************************************************************/

uint PnlPlnrClcRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrClcRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrClcRec::ContInf
 ******************************************************************************/

PnlPlnrClcRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrClcRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrClcRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrClcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrClcRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrClcRec::ContInf::diff(
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
 class PnlPlnrClcRec::StatApp
 ******************************************************************************/

void PnlPlnrClcRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneView
			, const bool initdoneAEnv
			, const bool initdoneAPar
			, const bool initdoneCal1NCalcitem
			, const bool initdone1NMaterial
			, const bool initdoneSup1NCalc
			, const bool initdoneRef1NFile
			, const bool initdoneMNFile
			, const bool initdoneMNDomain
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrClcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrClcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneView", initdoneView);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAEnv", initdoneAEnv);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCal1NCalcitem", initdoneCal1NCalcitem);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NMaterial", initdone1NMaterial);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NCalc", initdoneSup1NCalc);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFile", initdoneMNFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNDomain", initdoneMNDomain);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrClcRec::StatShr
 ******************************************************************************/

PnlPlnrClcRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefView
			, const ubigint jrefAEnv
			, const ubigint jrefAPar
			, const ubigint jrefCal1NCalcitem
			, const ubigint jref1NMaterial
			, const ubigint jrefSup1NCalc
			, const ubigint jrefRef1NFile
			, const ubigint jrefMNFile
			, const ubigint jrefMNDomain
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefView = jrefView;
	this->jrefAEnv = jrefAEnv;
	this->jrefAPar = jrefAPar;
	this->jrefCal1NCalcitem = jrefCal1NCalcitem;
	this->jref1NMaterial = jref1NMaterial;
	this->jrefSup1NCalc = jrefSup1NCalc;
	this->jrefRef1NFile = jrefRef1NFile;
	this->jrefMNFile = jrefMNFile;
	this->jrefMNDomain = jrefMNDomain;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFAENV, JREFAPAR, JREFCAL1NCALCITEM, JREF1NMATERIAL, JREFSUP1NCALC, JREFREF1NFILE, JREFMNFILE, JREFMNDOMAIN, BUTREGULARIZEACTIVE};
};

void PnlPlnrClcRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrClcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrClcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefView", Scr::scramble(mScr, scr, descr, jrefView));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAEnv", Scr::scramble(mScr, scr, descr, jrefAEnv));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(mScr, scr, descr, jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCal1NCalcitem", Scr::scramble(mScr, scr, descr, jrefCal1NCalcitem));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NMaterial", Scr::scramble(mScr, scr, descr, jref1NMaterial));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NCalc", Scr::scramble(mScr, scr, descr, jrefSup1NCalc));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(mScr, scr, descr, jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFile", Scr::scramble(mScr, scr, descr, jrefMNFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNDomain", Scr::scramble(mScr, scr, descr, jrefMNDomain));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrClcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefView == comp->jrefView) insert(items, JREFVIEW);
	if (jrefAEnv == comp->jrefAEnv) insert(items, JREFAENV);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jrefCal1NCalcitem == comp->jrefCal1NCalcitem) insert(items, JREFCAL1NCALCITEM);
	if (jref1NMaterial == comp->jref1NMaterial) insert(items, JREF1NMATERIAL);
	if (jrefSup1NCalc == comp->jrefSup1NCalc) insert(items, JREFSUP1NCALC);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefMNFile == comp->jrefMNFile) insert(items, JREFMNFILE);
	if (jrefMNDomain == comp->jrefMNDomain) insert(items, JREFMNDOMAIN);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrClcRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEW, JREFAENV, JREFAPAR, JREFCAL1NCALCITEM, JREF1NMATERIAL, JREFSUP1NCALC, JREFREF1NFILE, JREFMNFILE, JREFMNDOMAIN, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrClcRec::Tag
 ******************************************************************************/

void PnlPlnrClcRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrClcRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrClcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Calculation");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrClcRec::DpchAppDo
 ******************************************************************************/

PnlPlnrClcRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLCRECDO) {
	ixVDo = 0;
};

void PnlPlnrClcRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrClcRecDo");
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
 class PnlPlnrClcRec::DpchEngData
 ******************************************************************************/

PnlPlnrClcRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLCRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrClcRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrClcRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrClcRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


