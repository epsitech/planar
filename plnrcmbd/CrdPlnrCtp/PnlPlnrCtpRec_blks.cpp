/**
  * \file PnlPlnrCtpRec_blks.cpp
  * job handler for job PnlPlnrCtpRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrCtpRec::VecVDo
 ******************************************************************************/

uint PnlPlnrCtpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrCtpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrCtpRec::ContInf
 ******************************************************************************/

PnlPlnrCtpRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrCtpRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrCtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrCtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrCtpRec::ContInf::diff(
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
 class PnlPlnrCtpRec::StatApp
 ******************************************************************************/

void PnlPlnrCtpRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKEnvKey
			, const bool initdoneKParCat
			, const bool initdoneKParProp
			, const bool initdoneKCalcdomprp
			, const bool initdoneKCalcvar
			, const bool initdoneAEnv
			, const bool initdoneAPar
			, const bool initdoneSup1NCalc
			, const bool initdoneRef1NFile
			, const bool initdoneTpl1NCalc
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrCtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrCtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKEnvKey", initdoneKEnvKey);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKParCat", initdoneKParCat);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKParProp", initdoneKParProp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKCalcdomprp", initdoneKCalcdomprp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKCalcvar", initdoneKCalcvar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAEnv", initdoneAEnv);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NCalc", initdoneSup1NCalc);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTpl1NCalc", initdoneTpl1NCalc);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpRec::StatShr
 ******************************************************************************/

PnlPlnrCtpRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKEnvKey
			, const ubigint jrefKParCat
			, const ubigint jrefKParProp
			, const ubigint jrefKCalcdomprp
			, const ubigint jrefKCalcvar
			, const ubigint jrefAEnv
			, const ubigint jrefAPar
			, const ubigint jrefSup1NCalc
			, const ubigint jrefRef1NFile
			, const ubigint jrefTpl1NCalc
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKEnvKey = jrefKEnvKey;
	this->jrefKParCat = jrefKParCat;
	this->jrefKParProp = jrefKParProp;
	this->jrefKCalcdomprp = jrefKCalcdomprp;
	this->jrefKCalcvar = jrefKCalcvar;
	this->jrefAEnv = jrefAEnv;
	this->jrefAPar = jrefAPar;
	this->jrefSup1NCalc = jrefSup1NCalc;
	this->jrefRef1NFile = jrefRef1NFile;
	this->jrefTpl1NCalc = jrefTpl1NCalc;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFDETAIL, JREFKENVKEY, JREFKPARCAT, JREFKPARPROP, JREFKCALCDOMPRP, JREFKCALCVAR, JREFAENV, JREFAPAR, JREFSUP1NCALC, JREFREF1NFILE, JREFTPL1NCALC, BUTREGULARIZEACTIVE};
};

void PnlPlnrCtpRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrCtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrCtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKEnvKey", Scr::scramble(mScr, scr, descr, jrefKEnvKey));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKParCat", Scr::scramble(mScr, scr, descr, jrefKParCat));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKParProp", Scr::scramble(mScr, scr, descr, jrefKParProp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKCalcdomprp", Scr::scramble(mScr, scr, descr, jrefKCalcdomprp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKCalcvar", Scr::scramble(mScr, scr, descr, jrefKCalcvar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAEnv", Scr::scramble(mScr, scr, descr, jrefAEnv));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(mScr, scr, descr, jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NCalc", Scr::scramble(mScr, scr, descr, jrefSup1NCalc));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(mScr, scr, descr, jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefTpl1NCalc", Scr::scramble(mScr, scr, descr, jrefTpl1NCalc));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrCtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKEnvKey == comp->jrefKEnvKey) insert(items, JREFKENVKEY);
	if (jrefKParCat == comp->jrefKParCat) insert(items, JREFKPARCAT);
	if (jrefKParProp == comp->jrefKParProp) insert(items, JREFKPARPROP);
	if (jrefKCalcdomprp == comp->jrefKCalcdomprp) insert(items, JREFKCALCDOMPRP);
	if (jrefKCalcvar == comp->jrefKCalcvar) insert(items, JREFKCALCVAR);
	if (jrefAEnv == comp->jrefAEnv) insert(items, JREFAENV);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jrefSup1NCalc == comp->jrefSup1NCalc) insert(items, JREFSUP1NCALC);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefTpl1NCalc == comp->jrefTpl1NCalc) insert(items, JREFTPL1NCALC);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrCtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFDETAIL, JREFKENVKEY, JREFKPARCAT, JREFKPARPROP, JREFKCALCDOMPRP, JREFKCALCVAR, JREFAENV, JREFAPAR, JREFSUP1NCALC, JREFREF1NFILE, JREFTPL1NCALC, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpRec::Tag
 ******************************************************************************/

void PnlPlnrCtpRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrCtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrCtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Calculation template");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpRec::DpchAppDo
 ******************************************************************************/

PnlPlnrCtpRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPRECDO) {
	ixVDo = 0;
};

void PnlPlnrCtpRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrCtpRecDo");
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
 class PnlPlnrCtpRec::DpchEngData
 ******************************************************************************/

PnlPlnrCtpRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCTPRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrCtpRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrCtpRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrCtpRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


