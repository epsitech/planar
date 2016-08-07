/**
  * \file DlgPlnrNavLoaini.cpp
  * app access code for job DlgPlnrNavLoaini (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DlgPlnrNavLoaini.h"

/******************************************************************************
 class DlgPlnrNavLoaini::VecVDit
 ******************************************************************************/

uint DlgPlnrNavLoaini::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("ifi") == 0) return IFI;
	else if (s.compare("imp") == 0) return IMP;
	else if (s.compare("acv") == 0) return ACV;
	else if (s.compare("ppr") == 0) return PPR;
	else if (s.compare("lfi") == 0) return LFI;

	return(0);
};

string DlgPlnrNavLoaini::VecVDit::getSref(
			const uint ix
		) {
	if (ix == IFI) return("Ifi");
	else if (ix == IMP) return("Imp");
	else if (ix == ACV) return("Acv");
	else if (ix == PPR) return("Ppr");
	else if (ix == LFI) return("Lfi");

	return("");
};

/******************************************************************************
 class DlgPlnrNavLoaini::VecVDo
 ******************************************************************************/

uint DlgPlnrNavLoaini::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgPlnrNavLoaini::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrNavLoaini::VecVDoImp
 ******************************************************************************/

uint DlgPlnrNavLoaini::VecVDoImp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgPlnrNavLoaini::VecVDoImp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgPlnrNavLoaini::VecVDoPpr
 ******************************************************************************/

uint DlgPlnrNavLoaini::VecVDoPpr::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgPlnrNavLoaini::VecVDoPpr::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgPlnrNavLoaini::VecVSge
 ******************************************************************************/

uint DlgPlnrNavLoaini::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("prsidle") == 0) return PRSIDLE;
	else if (s.compare("parse") == 0) return PARSE;
	else if (s.compare("alrplnrper") == 0) return ALRPLNRPER;
	else if (s.compare("prsdone") == 0) return PRSDONE;
	else if (s.compare("impidle") == 0) return IMPIDLE;
	else if (s.compare("import") == 0) return IMPORT;
	else if (s.compare("impdone") == 0) return IMPDONE;
	else if (s.compare("upkidle") == 0) return UPKIDLE;
	else if (s.compare("unpack") == 0) return UNPACK;
	else if (s.compare("upkdone") == 0) return UPKDONE;
	else if (s.compare("postprc") == 0) return POSTPRC;
	else if (s.compare("done") == 0) return DONE;

	return(0);
};

string DlgPlnrNavLoaini::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == PRSIDLE) return("prsidle");
	else if (ix == PARSE) return("parse");
	else if (ix == ALRPLNRPER) return("alrplnrper");
	else if (ix == PRSDONE) return("prsdone");
	else if (ix == IMPIDLE) return("impidle");
	else if (ix == IMPORT) return("import");
	else if (ix == IMPDONE) return("impdone");
	else if (ix == UPKIDLE) return("upkidle");
	else if (ix == UNPACK) return("unpack");
	else if (ix == UPKDONE) return("upkdone");
	else if (ix == POSTPRC) return("postprc");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgPlnrNavLoaini::ContIac
 ******************************************************************************/

DlgPlnrNavLoaini::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgPlnrNavLoaini::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgPlnrNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgPlnrNavLoaini";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgPlnrNavLoaini::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgPlnrNavLoaini";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgPlnrNavLoaini";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrNavLoaini::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::ContIac::diff(
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
 class DlgPlnrNavLoaini::ContInf
 ******************************************************************************/

DlgPlnrNavLoaini::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgPlnrNavLoaini::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrNavLoaini";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::ContInf::diff(
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
 class DlgPlnrNavLoaini::ContInfImp
 ******************************************************************************/

DlgPlnrNavLoaini::ContInfImp::ContInfImp(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgPlnrNavLoaini::ContInfImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrNavLoainiImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrNavLoainiImp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::ContInfImp::comm(
			const ContInfImp* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgPlnrNavLoaini::ContInfImp::diff(
			const ContInfImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::ContInfPpr
 ******************************************************************************/

DlgPlnrNavLoaini::ContInfPpr::ContInfPpr(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgPlnrNavLoaini::ContInfPpr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrNavLoainiPpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrNavLoainiPpr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::ContInfPpr::comm(
			const ContInfPpr* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgPlnrNavLoaini::ContInfPpr::diff(
			const ContInfPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::StatApp
 ******************************************************************************/

DlgPlnrNavLoaini::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgPlnrNavLoaini::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgPlnrNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgPlnrNavLoaini";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatApp::diff(
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
 class DlgPlnrNavLoaini::StatShr
 ******************************************************************************/

DlgPlnrNavLoaini::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgPlnrNavLoaini::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoaini";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShr::diff(
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
 class DlgPlnrNavLoaini::StatShrAcv
 ******************************************************************************/

DlgPlnrNavLoaini::StatShrAcv::StatShrAcv(
			const bool UldActive
		) : Block() {
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgPlnrNavLoaini::StatShrAcv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoainiAcv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoainiAcv";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShrAcv::comm(
			const StatShrAcv* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShrAcv::diff(
			const StatShrAcv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::StatShrIfi
 ******************************************************************************/

DlgPlnrNavLoaini::StatShrIfi::StatShrIfi(
			const bool UldActive
		) : Block() {
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgPlnrNavLoaini::StatShrIfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoainiIfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoainiIfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShrIfi::comm(
			const StatShrIfi* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShrIfi::diff(
			const StatShrIfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::StatShrImp
 ******************************************************************************/

DlgPlnrNavLoaini::StatShrImp::StatShrImp(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgPlnrNavLoaini::StatShrImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoainiImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoainiImp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShrImp::comm(
			const StatShrImp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShrImp::diff(
			const StatShrImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::StatShrLfi
 ******************************************************************************/

DlgPlnrNavLoaini::StatShrLfi::StatShrLfi(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgPlnrNavLoaini::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoainiLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoainiLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShrLfi::diff(
			const StatShrLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::StatShrPpr
 ******************************************************************************/

DlgPlnrNavLoaini::StatShrPpr::StatShrPpr(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgPlnrNavLoaini::StatShrPpr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrNavLoainiPpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrNavLoainiPpr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrNavLoaini::StatShrPpr::comm(
			const StatShrPpr* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgPlnrNavLoaini::StatShrPpr::diff(
			const StatShrPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrNavLoaini::Tag
 ******************************************************************************/

DlgPlnrNavLoaini::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgPlnrNavLoaini::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoaini");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoaini";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::TagAcv
 ******************************************************************************/

DlgPlnrNavLoaini::TagAcv::TagAcv(
			const string& Uld
			, const string& Cpt
		) : Block() {
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgPlnrNavLoaini::TagAcv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoainiAcv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoainiAcv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::TagIfi
 ******************************************************************************/

DlgPlnrNavLoaini::TagIfi::TagIfi(
			const string& Uld
			, const string& Cpt
		) : Block() {
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgPlnrNavLoaini::TagIfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoainiIfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoainiIfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::TagImp
 ******************************************************************************/

DlgPlnrNavLoaini::TagImp::TagImp(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgPlnrNavLoaini::TagImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoainiImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoainiImp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::TagLfi
 ******************************************************************************/

DlgPlnrNavLoaini::TagLfi::TagLfi(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgPlnrNavLoaini::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoainiLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoainiLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::TagPpr
 ******************************************************************************/

DlgPlnrNavLoaini::TagPpr::TagPpr(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgPlnrNavLoaini::TagPpr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrNavLoainiPpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrNavLoainiPpr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrNavLoaini::DpchAppData
 ******************************************************************************/

DlgPlnrNavLoaini::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void DlgPlnrNavLoaini::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrNavLoainiData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrNavLoaini::DpchAppDo
 ******************************************************************************/

DlgPlnrNavLoaini::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoImp
			, const uint ixVDoPpr
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOIMP, IXVDOPPR};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoImp = ixVDoImp;
	this->ixVDoPpr = ixVDoPpr;
};

void DlgPlnrNavLoaini::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrNavLoainiDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOIMP)) writeString(wr, "srefIxVDoImp", VecVDoImp::getSref(ixVDoImp));
		if (has(IXVDOPPR)) writeString(wr, "srefIxVDoPpr", VecVDoPpr::getSref(ixVDoPpr));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrNavLoaini::DpchEngData
 ******************************************************************************/

DlgPlnrNavLoaini::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRNAVLOAINIDATA) {
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

void DlgPlnrNavLoaini::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgPlnrNavLoainiData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfimp.readXML(docctx, basexpath, true)) add(CONTINFIMP);
		if (continfppr.readXML(docctx, basexpath, true)) add(CONTINFPPR);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshracv.readXML(docctx, basexpath, true)) add(STATSHRACV);
		if (statshrifi.readXML(docctx, basexpath, true)) add(STATSHRIFI);
		if (statshrimp.readXML(docctx, basexpath, true)) add(STATSHRIMP);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (statshrppr.readXML(docctx, basexpath, true)) add(STATSHRPPR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagacv.readXML(docctx, basexpath, true)) add(TAGACV);
		if (tagifi.readXML(docctx, basexpath, true)) add(TAGIFI);
		if (tagimp.readXML(docctx, basexpath, true)) add(TAGIMP);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
		if (tagppr.readXML(docctx, basexpath, true)) add(TAGPPR);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continfimp = ContInfImp();
		continfppr = ContInfPpr();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshracv = StatShrAcv();
		statshrifi = StatShrIfi();
		statshrimp = StatShrImp();
		statshrlfi = StatShrLfi();
		statshrppr = StatShrPpr();
		tag = Tag();
		tagacv = TagAcv();
		tagifi = TagIfi();
		tagimp = TagImp();
		taglfi = TagLfi();
		tagppr = TagPpr();
	};
};

