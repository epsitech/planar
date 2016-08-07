/**
  * \file PnlPlnrCtpRec.cpp
  * app access code for job PnlPlnrCtpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrCtpRec.h"

/******************************************************************************
 class PnlPlnrCtpRec::VecVDo
 ******************************************************************************/

uint PnlPlnrCtpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

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

bool PnlPlnrCtpRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrCtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrCtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrCtpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

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

PnlPlnrCtpRec::StatApp::StatApp(
			const bool initdoneDetail
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
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneKEnvKey = initdoneKEnvKey;
	this->initdoneKParCat = initdoneKParCat;
	this->initdoneKParProp = initdoneKParProp;
	this->initdoneKCalcdomprp = initdoneKCalcdomprp;
	this->initdoneKCalcvar = initdoneKCalcvar;
	this->initdoneAEnv = initdoneAEnv;
	this->initdoneAPar = initdoneAPar;
	this->initdoneSup1NCalc = initdoneSup1NCalc;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneTpl1NCalc = initdoneTpl1NCalc;

	mask = {INITDONEDETAIL, INITDONEKENVKEY, INITDONEKPARCAT, INITDONEKPARPROP, INITDONEKCALCDOMPRP, INITDONEKCALCVAR, INITDONEAENV, INITDONEAPAR, INITDONESUP1NCALC, INITDONEREF1NFILE, INITDONETPL1NCALC};
};

bool PnlPlnrCtpRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrCtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrCtpRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKEnvKey", initdoneKEnvKey)) add(INITDONEKENVKEY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKParCat", initdoneKParCat)) add(INITDONEKPARCAT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKParProp", initdoneKParProp)) add(INITDONEKPARPROP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKCalcdomprp", initdoneKCalcdomprp)) add(INITDONEKCALCDOMPRP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKCalcvar", initdoneKCalcvar)) add(INITDONEKCALCVAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAEnv", initdoneAEnv)) add(INITDONEAENV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NCalc", initdoneSup1NCalc)) add(INITDONESUP1NCALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTpl1NCalc", initdoneTpl1NCalc)) add(INITDONETPL1NCALC);
	};

	return basefound;
};

set<uint> PnlPlnrCtpRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKEnvKey == comp->initdoneKEnvKey) insert(items, INITDONEKENVKEY);
	if (initdoneKParCat == comp->initdoneKParCat) insert(items, INITDONEKPARCAT);
	if (initdoneKParProp == comp->initdoneKParProp) insert(items, INITDONEKPARPROP);
	if (initdoneKCalcdomprp == comp->initdoneKCalcdomprp) insert(items, INITDONEKCALCDOMPRP);
	if (initdoneKCalcvar == comp->initdoneKCalcvar) insert(items, INITDONEKCALCVAR);
	if (initdoneAEnv == comp->initdoneAEnv) insert(items, INITDONEAENV);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdoneSup1NCalc == comp->initdoneSup1NCalc) insert(items, INITDONESUP1NCALC);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneTpl1NCalc == comp->initdoneTpl1NCalc) insert(items, INITDONETPL1NCALC);

	return(items);
};

set<uint> PnlPlnrCtpRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKENVKEY, INITDONEKPARCAT, INITDONEKPARPROP, INITDONEKCALCDOMPRP, INITDONEKCALCVAR, INITDONEAENV, INITDONEAPAR, INITDONESUP1NCALC, INITDONEREF1NFILE, INITDONETPL1NCALC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpRec::StatShr
 ******************************************************************************/

PnlPlnrCtpRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKEnvKey
			, const string& scrJrefKParCat
			, const string& scrJrefKParProp
			, const string& scrJrefKCalcdomprp
			, const string& scrJrefKCalcvar
			, const string& scrJrefAEnv
			, const string& scrJrefAPar
			, const string& scrJrefSup1NCalc
			, const string& scrJrefRef1NFile
			, const string& scrJrefTpl1NCalc
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKEnvKey = scrJrefKEnvKey;
	this->scrJrefKParCat = scrJrefKParCat;
	this->scrJrefKParProp = scrJrefKParProp;
	this->scrJrefKCalcdomprp = scrJrefKCalcdomprp;
	this->scrJrefKCalcvar = scrJrefKCalcvar;
	this->scrJrefAEnv = scrJrefAEnv;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJrefSup1NCalc = scrJrefSup1NCalc;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefTpl1NCalc = scrJrefTpl1NCalc;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFKENVKEY, SCRJREFKPARCAT, SCRJREFKPARPROP, SCRJREFKCALCDOMPRP, SCRJREFKCALCVAR, SCRJREFAENV, SCRJREFAPAR, SCRJREFSUP1NCALC, SCRJREFREF1NFILE, SCRJREFTPL1NCALC, BUTREGULARIZEACTIVE};
};

bool PnlPlnrCtpRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrCtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrCtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKEnvKey", scrJrefKEnvKey)) add(SCRJREFKENVKEY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKParCat", scrJrefKParCat)) add(SCRJREFKPARCAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKParProp", scrJrefKParProp)) add(SCRJREFKPARPROP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKCalcdomprp", scrJrefKCalcdomprp)) add(SCRJREFKCALCDOMPRP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKCalcvar", scrJrefKCalcvar)) add(SCRJREFKCALCVAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAEnv", scrJrefAEnv)) add(SCRJREFAENV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NCalc", scrJrefSup1NCalc)) add(SCRJREFSUP1NCALC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTpl1NCalc", scrJrefTpl1NCalc)) add(SCRJREFTPL1NCALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrCtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefKEnvKey.compare(comp->scrJrefKEnvKey) == 0) insert(items, SCRJREFKENVKEY);
	if (scrJrefKParCat.compare(comp->scrJrefKParCat) == 0) insert(items, SCRJREFKPARCAT);
	if (scrJrefKParProp.compare(comp->scrJrefKParProp) == 0) insert(items, SCRJREFKPARPROP);
	if (scrJrefKCalcdomprp.compare(comp->scrJrefKCalcdomprp) == 0) insert(items, SCRJREFKCALCDOMPRP);
	if (scrJrefKCalcvar.compare(comp->scrJrefKCalcvar) == 0) insert(items, SCRJREFKCALCVAR);
	if (scrJrefAEnv.compare(comp->scrJrefAEnv) == 0) insert(items, SCRJREFAENV);
	if (scrJrefAPar.compare(comp->scrJrefAPar) == 0) insert(items, SCRJREFAPAR);
	if (scrJrefSup1NCalc.compare(comp->scrJrefSup1NCalc) == 0) insert(items, SCRJREFSUP1NCALC);
	if (scrJrefRef1NFile.compare(comp->scrJrefRef1NFile) == 0) insert(items, SCRJREFREF1NFILE);
	if (scrJrefTpl1NCalc.compare(comp->scrJrefTpl1NCalc) == 0) insert(items, SCRJREFTPL1NCALC);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrCtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFDETAIL, SCRJREFKENVKEY, SCRJREFKPARCAT, SCRJREFKPARPROP, SCRJREFKCALCDOMPRP, SCRJREFKCALCVAR, SCRJREFAENV, SCRJREFAPAR, SCRJREFSUP1NCALC, SCRJREFREF1NFILE, SCRJREFTPL1NCALC, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrCtpRec::Tag
 ******************************************************************************/

PnlPlnrCtpRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrCtpRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrCtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrCtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrCtpRec::DpchAppDo
 ******************************************************************************/

PnlPlnrCtpRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCTPRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrCtpRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrCtpRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrCtpRec::DpchEngData
 ******************************************************************************/

PnlPlnrCtpRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCTPRECDATA) {
};

void PnlPlnrCtpRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrCtpRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

