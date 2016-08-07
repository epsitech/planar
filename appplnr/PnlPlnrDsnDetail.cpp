/**
  * \file PnlPlnrDsnDetail.cpp
  * app access code for job PnlPlnrDsnDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnDetail.h"

/******************************************************************************
 class PnlPlnrDsnDetail::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butreuviewclick") == 0) return BUTREUVIEWCLICK;
	else if (s.compare("butprjviewclick") == 0) return BUTPRJVIEWCLICK;
	else if (s.compare("butmodviewclick") == 0) return BUTMODVIEWCLICK;
	else if (s.compare("butdrvviewclick") == 0) return BUTDRVVIEWCLICK;

	return(0);
};

string PnlPlnrDsnDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
	else if (ix == BUTDRVVIEWCLICK) return("ButDrvViewClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDsnDetail::ContIac
 ******************************************************************************/

PnlPlnrDsnDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupTyp
			, const uint numFPupDim
			, const uint numFPupRet
			, const vector<uint>& numsFLstMty
			, const string& TxfMaj
			, const string& TxfSub
			, const string& TxfCmt
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupTyp = numFPupTyp;
	this->numFPupDim = numFPupDim;
	this->numFPupRet = numFPupRet;
	this->numsFLstMty = numsFLstMty;
	this->TxfMaj = TxfMaj;
	this->TxfSub = TxfSub;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, NUMFPUPTYP, NUMFPUPDIM, NUMFPUPRET, NUMSFLSTMTY, TXFMAJ, TXFSUB, TXFCMT};
};

bool PnlPlnrDsnDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrDsnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDim", numFPupDim)) add(NUMFPUPDIM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstMty", numsFLstMty)) add(NUMSFLSTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMaj", TxfMaj)) add(TXFMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSub", TxfSub)) add(TXFSUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlPlnrDsnDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrDsnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrDsnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupDim", numFPupDim);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstMty", numsFLstMty);
		writeStringAttr(wr, itemtag, "sref", "TxfMaj", TxfMaj);
		writeStringAttr(wr, itemtag, "sref", "TxfSub", TxfSub);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupDim == comp->numFPupDim) insert(items, NUMFPUPDIM);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (compareUintvec(numsFLstMty, comp->numsFLstMty)) insert(items, NUMSFLSTMTY);
	if (TxfMaj.compare(comp->TxfMaj) == 0) insert(items, TXFMAJ);
	if (TxfSub.compare(comp->TxfSub) == 0) insert(items, TXFSUB);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlPlnrDsnDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPTYP, NUMFPUPDIM, NUMFPUPRET, NUMSFLSTMTY, TXFMAJ, TXFSUB, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::ContInf
 ******************************************************************************/

PnlPlnrDsnDetail::ContInf::ContInf(
			const string& TxtReu
			, const string& TxtPrj
			, const string& TxtMty
			, const string& TxtMod
			, const string& TxtDrv
		) : Block() {
	this->TxtReu = TxtReu;
	this->TxtPrj = TxtPrj;
	this->TxtMty = TxtMty;
	this->TxtMod = TxtMod;
	this->TxtDrv = TxtDrv;

	mask = {TXTREU, TXTPRJ, TXTMTY, TXTMOD, TXTDRV};
};

bool PnlPlnrDsnDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDsnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrj", TxtPrj)) add(TXTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMty", TxtMty)) add(TXTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMod", TxtMod)) add(TXTMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrv", TxtDrv)) add(TXTDRV);
	};

	return basefound;
};

set<uint> PnlPlnrDsnDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtReu.compare(comp->TxtReu) == 0) insert(items, TXTREU);
	if (TxtPrj.compare(comp->TxtPrj) == 0) insert(items, TXTPRJ);
	if (TxtMty.compare(comp->TxtMty) == 0) insert(items, TXTMTY);
	if (TxtMod.compare(comp->TxtMod) == 0) insert(items, TXTMOD);
	if (TxtDrv.compare(comp->TxtDrv) == 0) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlPlnrDsnDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREU, TXTPRJ, TXTMTY, TXTMOD, TXTDRV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::StatApp
 ******************************************************************************/

PnlPlnrDsnDetail::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool LstMtyAlt
			, const uint LstMtyNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->LstMtyAlt = LstMtyAlt;
	this->LstMtyNumFirstdisp = LstMtyNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, LSTMTYALT, LSTMTYNUMFIRSTDISP};
};

bool PnlPlnrDsnDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDsnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtyAlt", LstMtyAlt)) add(LSTMTYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtyNumFirstdisp", LstMtyNumFirstdisp)) add(LSTMTYNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrDsnDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (LstMtyAlt == comp->LstMtyAlt) insert(items, LSTMTYALT);
	if (LstMtyNumFirstdisp == comp->LstMtyNumFirstdisp) insert(items, LSTMTYNUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrDsnDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, LSTMTYALT, LSTMTYNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::StatShr
 ******************************************************************************/

PnlPlnrDsnDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPrjViewAvail
			, const bool ButModViewAvail
			, const bool ButDrvViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButModViewAvail = ButModViewAvail;
	this->ButDrvViewAvail = ButDrvViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTMODVIEWAVAIL, BUTDRVVIEWAVAIL};
};

bool PnlPlnrDsnDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDsnDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewAvail", ButPrjViewAvail)) add(BUTPRJVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButModViewAvail", ButModViewAvail)) add(BUTMODVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDrvViewAvail", ButDrvViewAvail)) add(BUTDRVVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlPlnrDsnDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButModViewAvail == comp->ButModViewAvail) insert(items, BUTMODVIEWAVAIL);
	if (ButDrvViewAvail == comp->ButDrvViewAvail) insert(items, BUTDRVVIEWAVAIL);

	return(items);
};

set<uint> PnlPlnrDsnDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTMODVIEWAVAIL, BUTDRVVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnDetail::Tag
 ******************************************************************************/

PnlPlnrDsnDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptTyp
			, const string& CptDim
			, const string& CptReu
			, const string& CptPrj
			, const string& CptMty
			, const string& CptMod
			, const string& CptDrv
			, const string& CptMaj
			, const string& CptSub
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptTyp = CptTyp;
	this->CptDim = CptDim;
	this->CptReu = CptReu;
	this->CptPrj = CptPrj;
	this->CptMty = CptMty;
	this->CptMod = CptMod;
	this->CptDrv = CptDrv;
	this->CptMaj = CptMaj;
	this->CptSub = CptSub;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTTIT, CPTTYP, CPTDIM, CPTREU, CPTPRJ, CPTMTY, CPTMOD, CPTDRV, CPTMAJ, CPTSUB, CPTCMT};
};

bool PnlPlnrDsnDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDim", CptDim)) add(CPTDIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMty", CptMty)) add(CPTMTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMod", CptMod)) add(CPTMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrv", CptDrv)) add(CPTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMaj", CptMaj)) add(CPTMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSub", CptSub)) add(CPTSUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnDetail::DpchAppData
 ******************************************************************************/

PnlPlnrDsnDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrDsnDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnDetail::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDsnDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnDetail::DpchEngData
 ******************************************************************************/

PnlPlnrDsnDetail::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNDETAILDATA) {
	feedFLstMty.tag = "FeedFLstMty";
	feedFPupDim.tag = "FeedFPupDim";
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupTyp.tag = "FeedFPupTyp";
};

void PnlPlnrDsnDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstMty.readXML(docctx, basexpath, true)) add(FEEDFLSTMTY);
		if (feedFPupDim.readXML(docctx, basexpath, true)) add(FEEDFPUPDIM);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstMty.clear();
		feedFPupDim.clear();
		feedFPupRet.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

