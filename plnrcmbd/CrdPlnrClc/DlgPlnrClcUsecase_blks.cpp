/**
  * \file DlgPlnrClcUsecase_blks.cpp
  * job handler for job DlgPlnrClcUsecase (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDit
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "prp") return PRP;
	else if (s == "cal") return CAL;
	else if (s == "rfi") return RFI;

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

string DlgPlnrClcUsecase::VecVDit::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == PRP) return("Preparation");
		else if (ix == CAL) return("Calculation");
		else if (ix == RFI) return("Result files");
	};

	return("");
};

void DlgPlnrClcUsecase::VecVDit::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVDo
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

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

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

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

	if (s == "butcreclick") return BUTCRECLICK;

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

	if (s == "idle") return IDLE;
	else if (s == "create") return CREATE;
	else if (s == "credone") return CREDONE;
	else if (s == "run") return RUN;
	else if (s == "done") return DONE;

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

void DlgPlnrClcUsecase::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgPlnrClcUsecase::VecVUcs
 ******************************************************************************/

uint DlgPlnrClcUsecase::VecVUcs::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "disptest") return DISPTEST;
	else if (s == "qcdslab") return QCDSLAB;

	return(0);
};

string DlgPlnrClcUsecase::VecVUcs::getSref(
			const uint ix
		) {
	if (ix == DISPTEST) return("disptest");
	else if (ix == QCDSLAB) return("qcdslab");

	return("");
};

string DlgPlnrClcUsecase::VecVUcs::getTitle(
			const uint ix
		) {
	if (ix == DISPTEST) return("QCD waveguide dispersion test");
	else if (ix == QCDSLAB) return("QCD FDTD production simulations");

	return("");
};

void DlgPlnrClcUsecase::VecVUcs::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
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

	if (TxfPti == comp->TxfPti) insert(items, TXFPTI);
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

void DlgPlnrClcUsecase::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgPlnrClcUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgPlnrClcUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::ContInfCal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgPlnrClcUsecaseCal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgPlnrClcUsecaseCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrClcUsecase::ContInfCal::comm(
			const ContInfCal* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

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

void DlgPlnrClcUsecase::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgPlnrClcUsecase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgPlnrClcUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrClcUsecase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrClcUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::StatShrCal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrClcUsecaseCal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrClcUsecaseCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::StatShrPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrClcUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrClcUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::StatShrRfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrClcUsecaseRfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrClcUsecaseRfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrClcUsecase::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Run use case");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DONE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagCal
 ******************************************************************************/

void DlgPlnrClcUsecase::TagCal::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcUsecaseCal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcUsecaseCal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::PROGRESS, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::RUN, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::STOP, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagPrp
 ******************************************************************************/

void DlgPlnrClcUsecase::TagPrp::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPti", "Project name");
			writeStringAttr(wr, itemtag, "sref", "CptUcs", "Use case");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::CREATE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::TagRfi
 ******************************************************************************/

void DlgPlnrClcUsecase::TagRfi::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcUsecaseRfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcUsecaseRfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DOWNLOAD, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchAppData
 ******************************************************************************/

DlgPlnrClcUsecase::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDATA) {
};

void DlgPlnrClcUsecase::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrClcUsecaseData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacprp.readXML(docctx, basexpath, true)) add(CONTIACPRP);
	} else {
		contiac = ContIac();
		contiacprp = ContIacPrp();
	};
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchAppDo
 ******************************************************************************/

DlgPlnrClcUsecase::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDO) {
	ixVDo = 0;
	ixVDoCal = 0;
	ixVDoPrp = 0;
};

void DlgPlnrClcUsecase::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoCal;
	string srefIxVDoPrp;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrClcUsecaseDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoCal", "", srefIxVDoCal)) {
			ixVDoCal = VecVDoCal::getIx(srefIxVDoCal);
			add(IXVDOCAL);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoPrp", "", srefIxVDoPrp)) {
			ixVDoPrp = VecVDoPrp::getIx(srefIxVDoPrp);
			add(IXVDOPRP);
		};
	} else {
	};
};

/******************************************************************************
 class DlgPlnrClcUsecase::DpchEngData
 ******************************************************************************/

DlgPlnrClcUsecase::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacPrp* contiacprp
			, ContInf* continf
			, ContInfCal* continfcal
			, Feed* feedFDse
			, Feed* feedFPrpPupUcs
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrCal* statshrcal
			, StatShrPrp* statshrprp
			, StatShrRfi* statshrrfi
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRCLCUSECASEDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACPRP, CONTINF, CONTINFCAL, FEEDFDSE, FEEDFPRPPUPUCS, FEEDFSGE, STATAPP, STATSHR, STATSHRCAL, STATSHRPRP, STATSHRRFI, TAG, TAGCAL, TAGPRP, TAGRFI};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACPRP) && contiacprp) this->contiacprp = *contiacprp;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFCAL) && continfcal) this->continfcal = *continfcal;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFPRPPUPUCS) && feedFPrpPupUcs) this->feedFPrpPupUcs = *feedFPrpPupUcs;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRCAL) && statshrcal) this->statshrcal = *statshrcal;
	if (find(this->mask, STATSHRPRP) && statshrprp) this->statshrprp = *statshrprp;
	if (find(this->mask, STATSHRRFI) && statshrrfi) this->statshrrfi = *statshrrfi;
};

void DlgPlnrClcUsecase::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACPRP)) {contiacprp = src->contiacprp; add(CONTIACPRP);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFCAL)) {continfcal = src->continfcal; add(CONTINFCAL);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFPRPPUPUCS)) {feedFPrpPupUcs = src->feedFPrpPupUcs; add(FEEDFPRPPUPUCS);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRCAL)) {statshrcal = src->statshrcal; add(STATSHRCAL);};
	if (src->has(STATSHRPRP)) {statshrprp = src->statshrprp; add(STATSHRPRP);};
	if (src->has(STATSHRRFI)) {statshrrfi = src->statshrrfi; add(STATSHRRFI);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGCAL)) add(TAGCAL);
	if (src->has(TAGPRP)) add(TAGPRP);
	if (src->has(TAGRFI)) add(TAGRFI);
};

void DlgPlnrClcUsecase::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgPlnrClcUsecaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACPRP)) contiacprp.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFCAL)) continfcal.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFPRPPUPUCS)) feedFPrpPupUcs.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRCAL)) statshrcal.writeXML(wr);
		if (has(STATSHRPRP)) statshrprp.writeXML(wr);
		if (has(STATSHRRFI)) statshrrfi.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(TAGCAL)) TagCal::writeXML(ixPlnrVLocale, wr);
		if (has(TAGPRP)) TagPrp::writeXML(ixPlnrVLocale, wr);
		if (has(TAGRFI)) TagRfi::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


