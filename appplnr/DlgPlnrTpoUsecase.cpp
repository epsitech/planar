/**
  * \file DlgPlnrTpoUsecase.cpp
  * app access code for job DlgPlnrTpoUsecase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DlgPlnrTpoUsecase.h"

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDit
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("prp") == 0) return PRP;
	else if (s.compare("gen") == 0) return GEN;
	else if (s.compare("cfi") == 0) return CFI;

	return(0);
};

string DlgPlnrTpoUsecase::VecVDit::getSref(
			const uint ix
		) {
	if (ix == PRP) return("Prp");
	else if (ix == GEN) return("Gen");
	else if (ix == CFI) return("Cfi");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDo
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgPlnrTpoUsecase::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDoGen
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDoGen::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgPlnrTpoUsecase::VecVDoGen::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDoPrp
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDoPrp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butcreclick") == 0) return BUTCRECLICK;

	return(0);
};

string DlgPlnrTpoUsecase::VecVDoPrp::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVSge
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("create") == 0) return CREATE;
	else if (s.compare("credone") == 0) return CREDONE;
	else if (s.compare("run") == 0) return RUN;
	else if (s.compare("done") == 0) return DONE;

	return(0);
};

string DlgPlnrTpoUsecase::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == CREATE) return("create");
	else if (ix == CREDONE) return("credone");
	else if (ix == RUN) return("run");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVUcs
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVUcs::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("examples") == 0) return EXAMPLES;
	else if (s.compare("icabatch1") == 0) return ICABATCH1;
	else if (s.compare("icabatch2") == 0) return ICABATCH2;
	else if (s.compare("icabatch3") == 0) return ICABATCH3;
	else if (s.compare("uvslides") == 0) return UVSLIDES;

	return(0);
};

string DlgPlnrTpoUsecase::VecVUcs::getSref(
			const uint ix
		) {
	if (ix == EXAMPLES) return("examples");
	else if (ix == ICABATCH1) return("icabatch1");
	else if (ix == ICABATCH2) return("icabatch2");
	else if (ix == ICABATCH3) return("icabatch3");
	else if (ix == UVSLIDES) return("uvslides");

	return("");
};

/******************************************************************************
 class DlgPlnrTpoUsecase::ContIac
 ******************************************************************************/

DlgPlnrTpoUsecase::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgPlnrTpoUsecase::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgPlnrTpoUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgPlnrTpoUsecase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgPlnrTpoUsecase::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgPlnrTpoUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgPlnrTpoUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrTpoUsecase::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::ContIacPrp
 ******************************************************************************/

DlgPlnrTpoUsecase::ContIacPrp::ContIacPrp(
			const string& TxfPti
			, const uint numFPupUcs
		) : Block() {
	this->TxfPti = TxfPti;
	this->numFPupUcs = numFPupUcs;

	mask = {TXFPTI, NUMFPUPUCS};
};

bool DlgPlnrTpoUsecase::ContIacPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgPlnrTpoUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgPlnrTpoUsecasePrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPti", TxfPti)) add(TXFPTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupUcs", numFPupUcs)) add(NUMFPUPUCS);
	};

	return basefound;
};

void DlgPlnrTpoUsecase::ContIacPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgPlnrTpoUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgPlnrTpoUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfPti", TxfPti);
		writeUintAttr(wr, itemtag, "sref", "numFPupUcs", numFPupUcs);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrTpoUsecase::ContIacPrp::comm(
			const ContIacPrp* comp
		) {
	set<uint> items;

	if (TxfPti.compare(comp->TxfPti) == 0) insert(items, TXFPTI);
	if (numFPupUcs == comp->numFPupUcs) insert(items, NUMFPUPUCS);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::ContIacPrp::diff(
			const ContIacPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFPTI, NUMFPUPUCS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::ContInf
 ******************************************************************************/

DlgPlnrTpoUsecase::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgPlnrTpoUsecase::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrTpoUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrTpoUsecase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::ContInfGen
 ******************************************************************************/

DlgPlnrTpoUsecase::ContInfGen::ContInfGen(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgPlnrTpoUsecase::ContInfGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrTpoUsecaseGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrTpoUsecaseGen";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::ContInfGen::comm(
			const ContInfGen* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::ContInfGen::diff(
			const ContInfGen* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::StatApp
 ******************************************************************************/

DlgPlnrTpoUsecase::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgPlnrTpoUsecase::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgPlnrTpoUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgPlnrTpoUsecase";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONE, SHORTMENU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::StatShr
 ******************************************************************************/

DlgPlnrTpoUsecase::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgPlnrTpoUsecase::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrTpoUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrTpoUsecase";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::StatShrCfi
 ******************************************************************************/

DlgPlnrTpoUsecase::StatShrCfi::StatShrCfi(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgPlnrTpoUsecase::StatShrCfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrTpoUsecaseCfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrTpoUsecaseCfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::StatShrCfi::comm(
			const StatShrCfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::StatShrCfi::diff(
			const StatShrCfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::StatShrGen
 ******************************************************************************/

DlgPlnrTpoUsecase::StatShrGen::StatShrGen(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgPlnrTpoUsecase::StatShrGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrTpoUsecaseGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrTpoUsecaseGen";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::StatShrGen::comm(
			const StatShrGen* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::StatShrGen::diff(
			const StatShrGen* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::StatShrPrp
 ******************************************************************************/

DlgPlnrTpoUsecase::StatShrPrp::StatShrPrp(
			const bool ButCreActive
		) : Block() {
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

bool DlgPlnrTpoUsecase::StatShrPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrTpoUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrTpoUsecasePrp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrTpoUsecase::StatShrPrp::comm(
			const StatShrPrp* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgPlnrTpoUsecase::StatShrPrp::diff(
			const StatShrPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::Tag
 ******************************************************************************/

DlgPlnrTpoUsecase::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgPlnrTpoUsecase::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrTpoUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrTpoUsecase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagCfi
 ******************************************************************************/

DlgPlnrTpoUsecase::TagCfi::TagCfi(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgPlnrTpoUsecase::TagCfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrTpoUsecaseCfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrTpoUsecaseCfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagGen
 ******************************************************************************/

DlgPlnrTpoUsecase::TagGen::TagGen(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgPlnrTpoUsecase::TagGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrTpoUsecaseGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrTpoUsecaseGen";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagPrp
 ******************************************************************************/

DlgPlnrTpoUsecase::TagPrp::TagPrp(
			const string& CptPti
			, const string& CptUcs
			, const string& ButCre
		) : Block() {
	this->CptPti = CptPti;
	this->CptUcs = CptUcs;
	this->ButCre = ButCre;

	mask = {CPTPTI, CPTUCS, BUTCRE};
};

bool DlgPlnrTpoUsecase::TagPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrTpoUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrTpoUsecasePrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPti", CptPti)) add(CPTPTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUcs", CptUcs)) add(CPTUCS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrTpoUsecase::DpchAppData
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacPrp* contiacprp
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACPRP};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACPRP) && contiacprp) this->contiacprp = *contiacprp;
};

void DlgPlnrTpoUsecase::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrTpoUsecaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACPRP)) contiacprp.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::DpchAppDo
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoGen
			, const uint ixVDoPrp
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOGEN, IXVDOPRP};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoGen = ixVDoGen;
	this->ixVDoPrp = ixVDoPrp;
};

void DlgPlnrTpoUsecase::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrTpoUsecaseDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOGEN)) writeString(wr, "srefIxVDoGen", VecVDoGen::getSref(ixVDoGen));
		if (has(IXVDOPRP)) writeString(wr, "srefIxVDoPrp", VecVDoPrp::getSref(ixVDoPrp));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::DpchEngData
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRTPOUSECASEDATA) {
	feedFDse.tag = "FeedFDse";
	feedFPrpPupUcs.tag = "FeedFPrpPupUcs";
	feedFSge.tag = "FeedFSge";
};

void DlgPlnrTpoUsecase::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgPlnrTpoUsecaseData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacprp.readXML(docctx, basexpath, true)) add(CONTIACPRP);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfgen.readXML(docctx, basexpath, true)) add(CONTINFGEN);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFPrpPupUcs.readXML(docctx, basexpath, true)) add(FEEDFPRPPUPUCS);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrcfi.readXML(docctx, basexpath, true)) add(STATSHRCFI);
		if (statshrgen.readXML(docctx, basexpath, true)) add(STATSHRGEN);
		if (statshrprp.readXML(docctx, basexpath, true)) add(STATSHRPRP);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagcfi.readXML(docctx, basexpath, true)) add(TAGCFI);
		if (taggen.readXML(docctx, basexpath, true)) add(TAGGEN);
		if (tagprp.readXML(docctx, basexpath, true)) add(TAGPRP);
	} else {
		contiac = ContIac();
		contiacprp = ContIacPrp();
		continf = ContInf();
		continfgen = ContInfGen();
		feedFDse.clear();
		feedFPrpPupUcs.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrcfi = StatShrCfi();
		statshrgen = StatShrGen();
		statshrprp = StatShrPrp();
		tag = Tag();
		tagcfi = TagCfi();
		taggen = TagGen();
		tagprp = TagPrp();
	};
};

