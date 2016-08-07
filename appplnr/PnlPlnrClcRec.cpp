/**
  * \file PnlPlnrClcRec.cpp
  * app access code for job PnlPlnrClcRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrClcRec.h"

/******************************************************************************
 class PnlPlnrClcRec::VecVDo
 ******************************************************************************/

uint PnlPlnrClcRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

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

bool PnlPlnrClcRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrClcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrClcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrClcRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

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

PnlPlnrClcRec::StatApp::StatApp(
			const bool initdonePre
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
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneView = initdoneView;
	this->initdoneAEnv = initdoneAEnv;
	this->initdoneAPar = initdoneAPar;
	this->initdoneCal1NCalcitem = initdoneCal1NCalcitem;
	this->initdone1NMaterial = initdone1NMaterial;
	this->initdoneSup1NCalc = initdoneSup1NCalc;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNFile = initdoneMNFile;
	this->initdoneMNDomain = initdoneMNDomain;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEAENV, INITDONEAPAR, INITDONECAL1NCALCITEM, INITDONE1NMATERIAL, INITDONESUP1NCALC, INITDONEREF1NFILE, INITDONEMNFILE, INITDONEMNDOMAIN};
};

bool PnlPlnrClcRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrClcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrClcRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneView", initdoneView)) add(INITDONEVIEW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAEnv", initdoneAEnv)) add(INITDONEAENV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCal1NCalcitem", initdoneCal1NCalcitem)) add(INITDONECAL1NCALCITEM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NMaterial", initdone1NMaterial)) add(INITDONE1NMATERIAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NCalc", initdoneSup1NCalc)) add(INITDONESUP1NCALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNFile", initdoneMNFile)) add(INITDONEMNFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNDomain", initdoneMNDomain)) add(INITDONEMNDOMAIN);
	};

	return basefound;
};

set<uint> PnlPlnrClcRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneView == comp->initdoneView) insert(items, INITDONEVIEW);
	if (initdoneAEnv == comp->initdoneAEnv) insert(items, INITDONEAENV);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdoneCal1NCalcitem == comp->initdoneCal1NCalcitem) insert(items, INITDONECAL1NCALCITEM);
	if (initdone1NMaterial == comp->initdone1NMaterial) insert(items, INITDONE1NMATERIAL);
	if (initdoneSup1NCalc == comp->initdoneSup1NCalc) insert(items, INITDONESUP1NCALC);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNFile == comp->initdoneMNFile) insert(items, INITDONEMNFILE);
	if (initdoneMNDomain == comp->initdoneMNDomain) insert(items, INITDONEMNDOMAIN);

	return(items);
};

set<uint> PnlPlnrClcRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEW, INITDONEAENV, INITDONEAPAR, INITDONECAL1NCALCITEM, INITDONE1NMATERIAL, INITDONESUP1NCALC, INITDONEREF1NFILE, INITDONEMNFILE, INITDONEMNDOMAIN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrClcRec::StatShr
 ******************************************************************************/

PnlPlnrClcRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefView
			, const string& scrJrefAEnv
			, const string& scrJrefAPar
			, const string& scrJrefCal1NCalcitem
			, const string& scrJref1NMaterial
			, const string& scrJrefSup1NCalc
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNFile
			, const string& scrJrefMNDomain
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefView = scrJrefView;
	this->scrJrefAEnv = scrJrefAEnv;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJrefCal1NCalcitem = scrJrefCal1NCalcitem;
	this->scrJref1NMaterial = scrJref1NMaterial;
	this->scrJrefSup1NCalc = scrJrefSup1NCalc;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNFile = scrJrefMNFile;
	this->scrJrefMNDomain = scrJrefMNDomain;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFAENV, SCRJREFAPAR, SCRJREFCAL1NCALCITEM, SCRJREF1NMATERIAL, SCRJREFSUP1NCALC, SCRJREFREF1NFILE, SCRJREFMNFILE, SCRJREFMNDOMAIN, BUTREGULARIZEACTIVE};
};

bool PnlPlnrClcRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrClcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrClcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefView", scrJrefView)) add(SCRJREFVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAEnv", scrJrefAEnv)) add(SCRJREFAENV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCal1NCalcitem", scrJrefCal1NCalcitem)) add(SCRJREFCAL1NCALCITEM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NMaterial", scrJref1NMaterial)) add(SCRJREF1NMATERIAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NCalc", scrJrefSup1NCalc)) add(SCRJREFSUP1NCALC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNFile", scrJrefMNFile)) add(SCRJREFMNFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNDomain", scrJrefMNDomain)) add(SCRJREFMNDOMAIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrClcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefView.compare(comp->scrJrefView) == 0) insert(items, SCRJREFVIEW);
	if (scrJrefAEnv.compare(comp->scrJrefAEnv) == 0) insert(items, SCRJREFAENV);
	if (scrJrefAPar.compare(comp->scrJrefAPar) == 0) insert(items, SCRJREFAPAR);
	if (scrJrefCal1NCalcitem.compare(comp->scrJrefCal1NCalcitem) == 0) insert(items, SCRJREFCAL1NCALCITEM);
	if (scrJref1NMaterial.compare(comp->scrJref1NMaterial) == 0) insert(items, SCRJREF1NMATERIAL);
	if (scrJrefSup1NCalc.compare(comp->scrJrefSup1NCalc) == 0) insert(items, SCRJREFSUP1NCALC);
	if (scrJrefRef1NFile.compare(comp->scrJrefRef1NFile) == 0) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNFile.compare(comp->scrJrefMNFile) == 0) insert(items, SCRJREFMNFILE);
	if (scrJrefMNDomain.compare(comp->scrJrefMNDomain) == 0) insert(items, SCRJREFMNDOMAIN);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrClcRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEW, SCRJREFAENV, SCRJREFAPAR, SCRJREFCAL1NCALCITEM, SCRJREF1NMATERIAL, SCRJREFSUP1NCALC, SCRJREFREF1NFILE, SCRJREFMNFILE, SCRJREFMNDOMAIN, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrClcRec::Tag
 ******************************************************************************/

PnlPlnrClcRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrClcRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrClcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrClcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrClcRec::DpchAppDo
 ******************************************************************************/

PnlPlnrClcRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRCLCRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrClcRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrClcRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrClcRec::DpchEngData
 ******************************************************************************/

PnlPlnrClcRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCLCRECDATA) {
};

void PnlPlnrClcRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrClcRecData");
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

