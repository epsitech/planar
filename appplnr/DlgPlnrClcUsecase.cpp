/**
  * \file DlgPlnrClcUsecase.cpp
  * app access code for job DlgPlnrClcUsecase (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DlgPlnrClcUsecase.h"

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDit
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("prp") == 0) return PRP;
	else if (s.compare("cal") == 0) return CAL;
	else if (s.compare("rfi") == 0) return RFI;

	return(0);
};

string DlgPlnrClcUsecase::VecVDit::getSref(
			const uint ix
		) {
	if (ix == PRP) return("Prp");
	else if (ix == CAL) return("Cal");
	else if (ix == RFI) return("Rfi");

	return("");
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDo
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgPlnrClcUsecase::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDoCal
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDoCal::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgPlnrClcUsecase::VecVDoCal::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDoPrp
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDoPrp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butcreclick") == 0) return BUTCRECLICK;

	return(0);
};

string DlgPlnrClcUsecase::VecVDoPrp::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVSge
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVSge::getIx(
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

string DlgPlnrClcUsecase::VecVSge::getSref(
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
 class DlgPlnrClcUsecase::VecVUcs
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVUcs::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("disptest") == 0) return DISPTEST;
	else if (s.compare("qcdslab") == 0) return QCDSLAB;

	return(0);
};

string DlgPlnrClcUsecase::VecVUcs::getSref(
			const uint ix
		) {
	if (ix == DISPTEST) return("disptest");
	else if (ix == QCDSLAB) return("qcdslab");

	return("");
};

/******************************************************************************
 class DlgPlnrClcUsecase::ContIac
 ******************************************************************************/

DlgPlnrClcUsecase::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgPlnrClcUsecase::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgPlnrClcUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgPlnrClcUsecase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgPlnrClcUsecase::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgPlnrClcUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgPlnrClcUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrClcUsecase::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::ContIac::diff(
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
 class DlgPlnrClcUsecase::ContIacPrp
 ******************************************************************************/

DlgPlnrClcUsecase::ContIacPrp::ContIacPrp(
			const string& TxfPti
			, const uint numFPupUcs
		) : Block() {
	this->TxfPti = TxfPti;
	this->numFPupUcs = numFPupUcs;

	mask = {TXFPTI, NUMFPUPUCS};
};

bool DlgPlnrClcUsecase::ContIacPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgPlnrClcUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgPlnrClcUsecasePrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPti", TxfPti)) add(TXFPTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupUcs", numFPupUcs)) add(NUMFPUPUCS);
	};

	return basefound;
};

void DlgPlnrClcUsecase::ContIacPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgPlnrClcUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgPlnrClcUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfPti", TxfPti);
		writeUintAttr(wr, itemtag, "sref", "numFPupUcs", numFPupUcs);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrClcUsecase::ContIacPrp::comm(
			const ContIacPrp* comp
		) {
	set<uint> items;

	if (TxfPti.compare(comp->TxfPti) == 0) insert(items, TXFPTI);
	if (numFPupUcs == comp->numFPupUcs) insert(items, NUMFPUPUCS);

	return(items);
};

set<uint> DlgPlnrClcUsecase::ContIacPrp::diff(
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
 class DlgPlnrClcUsecase::ContInf
 ******************************************************************************/

DlgPlnrClcUsecase::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgPlnrClcUsecase::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrClcUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrClcUsecase";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::ContInf::diff(
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
 class DlgPlnrClcUsecase::ContInfCal
 ******************************************************************************/

DlgPlnrClcUsecase::ContInfCal::ContInfCal(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgPlnrClcUsecase::ContInfCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgPlnrClcUsecaseCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgPlnrClcUsecaseCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::ContInfCal::comm(
			const ContInfCal* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgPlnrClcUsecase::ContInfCal::diff(
			const ContInfCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrClcUsecase::StatApp
 ******************************************************************************/

DlgPlnrClcUsecase::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgPlnrClcUsecase::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgPlnrClcUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgPlnrClcUsecase";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgPlnrClcUsecase::StatApp::diff(
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
 class DlgPlnrClcUsecase::StatShr
 ******************************************************************************/

DlgPlnrClcUsecase::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgPlnrClcUsecase::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrClcUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrClcUsecase";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::StatShr::diff(
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
 class DlgPlnrClcUsecase::StatShrCal
 ******************************************************************************/

DlgPlnrClcUsecase::StatShrCal::StatShrCal(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgPlnrClcUsecase::StatShrCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrClcUsecaseCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrClcUsecaseCal";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::StatShrCal::comm(
			const StatShrCal* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::StatShrCal::diff(
			const StatShrCal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrClcUsecase::StatShrPrp
 ******************************************************************************/

DlgPlnrClcUsecase::StatShrPrp::StatShrPrp(
			const bool ButCreActive
		) : Block() {
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

bool DlgPlnrClcUsecase::StatShrPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrClcUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrClcUsecasePrp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::StatShrPrp::comm(
			const StatShrPrp* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::StatShrPrp::diff(
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
 class DlgPlnrClcUsecase::StatShrRfi
 ******************************************************************************/

DlgPlnrClcUsecase::StatShrRfi::StatShrRfi(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgPlnrClcUsecase::StatShrRfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgPlnrClcUsecaseRfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgPlnrClcUsecaseRfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgPlnrClcUsecase::StatShrRfi::comm(
			const StatShrRfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgPlnrClcUsecase::StatShrRfi::diff(
			const StatShrRfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgPlnrClcUsecase::Tag
 ******************************************************************************/

DlgPlnrClcUsecase::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgPlnrClcUsecase::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrClcUsecase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrClcUsecase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagCal
 ******************************************************************************/

DlgPlnrClcUsecase::TagCal::TagCal(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgPlnrClcUsecase::TagCal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrClcUsecaseCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrClcUsecaseCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagPrp
 ******************************************************************************/

DlgPlnrClcUsecase::TagPrp::TagPrp(
			const string& CptPti
			, const string& CptUcs
			, const string& ButCre
		) : Block() {
	this->CptPti = CptPti;
	this->CptUcs = CptUcs;
	this->ButCre = ButCre;

	mask = {CPTPTI, CPTUCS, BUTCRE};
};

bool DlgPlnrClcUsecase::TagPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrClcUsecasePrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrClcUsecasePrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPti", CptPti)) add(CPTPTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUcs", CptUcs)) add(CPTUCS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagRfi
 ******************************************************************************/

DlgPlnrClcUsecase::TagRfi::TagRfi(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgPlnrClcUsecase::TagRfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgPlnrClcUsecaseRfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgPlnrClcUsecaseRfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchAppData
 ******************************************************************************/

DlgPlnrClcUsecase::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacPrp* contiacprp
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACPRP};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACPRP) && contiacprp) this->contiacprp = *contiacprp;
};

void DlgPlnrClcUsecase::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrClcUsecaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACPRP)) contiacprp.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchAppDo
 ******************************************************************************/

DlgPlnrClcUsecase::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoCal
			, const uint ixVDoPrp
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOCAL, IXVDOPRP};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoCal = ixVDoCal;
	this->ixVDoPrp = ixVDoPrp;
};

void DlgPlnrClcUsecase::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgPlnrClcUsecaseDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOCAL)) writeString(wr, "srefIxVDoCal", VecVDoCal::getSref(ixVDoCal));
		if (has(IXVDOPRP)) writeString(wr, "srefIxVDoPrp", VecVDoPrp::getSref(ixVDoPrp));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchEngData
 ******************************************************************************/

DlgPlnrClcUsecase::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRCLCUSECASEDATA) {
	feedFDse.tag = "FeedFDse";
	feedFPrpPupUcs.tag = "FeedFPrpPupUcs";
	feedFSge.tag = "FeedFSge";
};

void DlgPlnrClcUsecase::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgPlnrClcUsecaseData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacprp.readXML(docctx, basexpath, true)) add(CONTIACPRP);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfcal.readXML(docctx, basexpath, true)) add(CONTINFCAL);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFPrpPupUcs.readXML(docctx, basexpath, true)) add(FEEDFPRPPUPUCS);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrcal.readXML(docctx, basexpath, true)) add(STATSHRCAL);
		if (statshrprp.readXML(docctx, basexpath, true)) add(STATSHRPRP);
		if (statshrrfi.readXML(docctx, basexpath, true)) add(STATSHRRFI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagcal.readXML(docctx, basexpath, true)) add(TAGCAL);
		if (tagprp.readXML(docctx, basexpath, true)) add(TAGPRP);
		if (tagrfi.readXML(docctx, basexpath, true)) add(TAGRFI);
	} else {
		contiac = ContIac();
		contiacprp = ContIacPrp();
		continf = ContInf();
		continfcal = ContInfCal();
		feedFDse.clear();
		feedFPrpPupUcs.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrcal = StatShrCal();
		statshrprp = StatShrPrp();
		statshrrfi = StatShrRfi();
		tag = Tag();
		tagcal = TagCal();
		tagprp = TagPrp();
		tagrfi = TagRfi();
	};
};

