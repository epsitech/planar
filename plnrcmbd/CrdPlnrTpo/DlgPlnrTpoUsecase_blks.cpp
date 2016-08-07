/**
  * \file DlgPlnrTpoUsecase_blks.cpp
  * job handler for job DlgPlnrTpoUsecase (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDit
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "prp") return PRP;
	else if (s == "gen") return GEN;
	else if (s == "cfi") return CFI;

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

string DlgPlnrTpoUsecase::VecVDit::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == PRP) return("Preparation");
		else if (ix == GEN) return("Generation");
		else if (ix == CFI) return("CAD files");
	};

	return("");
};

void DlgPlnrTpoUsecase::VecVDit::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVDo
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

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

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

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

	if (s == "butcreclick") return BUTCRECLICK;

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

	if (s == "idle") return IDLE;
	else if (s == "create") return CREATE;
	else if (s == "credone") return CREDONE;
	else if (s == "run") return RUN;
	else if (s == "done") return DONE;

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

void DlgPlnrTpoUsecase::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgPlnrTpoUsecase::VecVUcs
 ******************************************************************************/

uint DlgPlnrTpoUsecase::VecVUcs::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "examples") return EXAMPLES;
	else if (s == "icabatch1") return ICABATCH1;
	else if (s == "icabatch2") return ICABATCH2;
	else if (s == "icabatch3") return ICABATCH3;
	else if (s == "uvslides") return UVSLIDES;

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

string DlgPlnrTpoUsecase::VecVUcs::getTitle(
			const uint ix
		) {
	if (ix == EXAMPLES) return("examples and device templates");
	else if (ix == ICABATCH1) return("ICARUS mask batch 1");
	else if (ix == ICABATCH2) return("ICARUS mask batch 2");
	else if (ix == ICABATCH3) return("ICARUS mask batch 3");
	else if (ix == UVSLIDES) return("UV camera test patterns");

	return("");
};

void DlgPlnrTpoUsecase::VecVUcs::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
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

	if (TxfPti == comp->TxfPti) insert(items, TXFPTI);
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

void DlgPlnrTpoUsecase::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgPlnrTpoUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgPlnrTpoUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::ContInfGen::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgPlnrTpoUsecaseGen";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgPlnrTpoUsecaseGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgPlnrTpoUsecase::ContInfGen::comm(
			const ContInfGen* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

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

void DlgPlnrTpoUsecase::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgPlnrTpoUsecase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgPlnrTpoUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrTpoUsecase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrTpoUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::StatShrCfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrTpoUsecaseCfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrTpoUsecaseCfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::StatShrGen::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrTpoUsecaseGen";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrTpoUsecaseGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::StatShrPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgPlnrTpoUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgPlnrTpoUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
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

void DlgPlnrTpoUsecase::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrTpoUsecase";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrTpoUsecase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Generate use case");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DONE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagCfi
 ******************************************************************************/

void DlgPlnrTpoUsecase::TagCfi::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrTpoUsecaseCfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrTpoUsecaseCfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DOWNLOAD, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagGen
 ******************************************************************************/

void DlgPlnrTpoUsecase::TagGen::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrTpoUsecaseGen";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrTpoUsecaseGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::PROGRESS, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::RUN, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::STOP, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::TagPrp
 ******************************************************************************/

void DlgPlnrTpoUsecase::TagPrp::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrTpoUsecasePrp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrTpoUsecasePrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPti", "Project name");
			writeStringAttr(wr, itemtag, "sref", "CptUcs", "Use case");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::CREATE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrTpoUsecase::DpchAppData
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDATA) {
};

void DlgPlnrTpoUsecase::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrTpoUsecaseData");
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
 class DlgPlnrTpoUsecase::DpchAppDo
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDO) {
	ixVDo = 0;
	ixVDoGen = 0;
	ixVDoPrp = 0;
};

void DlgPlnrTpoUsecase::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoGen;
	string srefIxVDoPrp;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrTpoUsecaseDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoGen", "", srefIxVDoGen)) {
			ixVDoGen = VecVDoGen::getIx(srefIxVDoGen);
			add(IXVDOGEN);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoPrp", "", srefIxVDoPrp)) {
			ixVDoPrp = VecVDoPrp::getIx(srefIxVDoPrp);
			add(IXVDOPRP);
		};
	} else {
	};
};

/******************************************************************************
 class DlgPlnrTpoUsecase::DpchEngData
 ******************************************************************************/

DlgPlnrTpoUsecase::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacPrp* contiacprp
			, ContInf* continf
			, ContInfGen* continfgen
			, Feed* feedFDse
			, Feed* feedFPrpPupUcs
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrCfi* statshrcfi
			, StatShrGen* statshrgen
			, StatShrPrp* statshrprp
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRTPOUSECASEDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACPRP, CONTINF, CONTINFGEN, FEEDFDSE, FEEDFPRPPUPUCS, FEEDFSGE, STATAPP, STATSHR, STATSHRCFI, STATSHRGEN, STATSHRPRP, TAG, TAGCFI, TAGGEN, TAGPRP};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACPRP) && contiacprp) this->contiacprp = *contiacprp;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFGEN) && continfgen) this->continfgen = *continfgen;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFPRPPUPUCS) && feedFPrpPupUcs) this->feedFPrpPupUcs = *feedFPrpPupUcs;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRCFI) && statshrcfi) this->statshrcfi = *statshrcfi;
	if (find(this->mask, STATSHRGEN) && statshrgen) this->statshrgen = *statshrgen;
	if (find(this->mask, STATSHRPRP) && statshrprp) this->statshrprp = *statshrprp;
};

void DlgPlnrTpoUsecase::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACPRP)) {contiacprp = src->contiacprp; add(CONTIACPRP);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFGEN)) {continfgen = src->continfgen; add(CONTINFGEN);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFPRPPUPUCS)) {feedFPrpPupUcs = src->feedFPrpPupUcs; add(FEEDFPRPPUPUCS);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRCFI)) {statshrcfi = src->statshrcfi; add(STATSHRCFI);};
	if (src->has(STATSHRGEN)) {statshrgen = src->statshrgen; add(STATSHRGEN);};
	if (src->has(STATSHRPRP)) {statshrprp = src->statshrprp; add(STATSHRPRP);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGCFI)) add(TAGCFI);
	if (src->has(TAGGEN)) add(TAGGEN);
	if (src->has(TAGPRP)) add(TAGPRP);
};

void DlgPlnrTpoUsecase::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgPlnrTpoUsecaseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACPRP)) contiacprp.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFGEN)) continfgen.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFPRPPUPUCS)) feedFPrpPupUcs.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRCFI)) statshrcfi.writeXML(wr);
		if (has(STATSHRGEN)) statshrgen.writeXML(wr);
		if (has(STATSHRPRP)) statshrprp.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
		if (has(TAGCFI)) TagCfi::writeXML(ixPlnrVLocale, wr);
		if (has(TAGGEN)) TagGen::writeXML(ixPlnrVLocale, wr);
		if (has(TAGPRP)) TagPrp::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


