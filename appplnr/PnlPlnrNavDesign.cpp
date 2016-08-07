/**
  * \file PnlPlnrNavDesign.cpp
  * app access code for job PnlPlnrNavDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrNavDesign.h"

/******************************************************************************
 class PnlPlnrNavDesign::VecVDo
 ******************************************************************************/

uint PnlPlnrNavDesign::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butprjviewclick") == 0) return BUTPRJVIEWCLICK;
	else if (s.compare("butprjnewcrdclick") == 0) return BUTPRJNEWCRDCLICK;
	else if (s.compare("butdsnviewclick") == 0) return BUTDSNVIEWCLICK;
	else if (s.compare("butdsnnewcrdclick") == 0) return BUTDSNNEWCRDCLICK;
	else if (s.compare("butdomviewclick") == 0) return BUTDOMVIEWCLICK;
	else if (s.compare("butdomnewcrdclick") == 0) return BUTDOMNEWCRDCLICK;
	else if (s.compare("butdgdviewclick") == 0) return BUTDGDVIEWCLICK;
	else if (s.compare("butdgdnewcrdclick") == 0) return BUTDGDNEWCRDCLICK;
	else if (s.compare("butdvcviewclick") == 0) return BUTDVCVIEWCLICK;
	else if (s.compare("butdvcnewcrdclick") == 0) return BUTDVCNEWCRDCLICK;
	else if (s.compare("butsruviewclick") == 0) return BUTSRUVIEWCLICK;
	else if (s.compare("butsrunewcrdclick") == 0) return BUTSRUNEWCRDCLICK;
	else if (s.compare("butstkviewclick") == 0) return BUTSTKVIEWCLICK;
	else if (s.compare("butstknewcrdclick") == 0) return BUTSTKNEWCRDCLICK;
	else if (s.compare("butlyrviewclick") == 0) return BUTLYRVIEWCLICK;
	else if (s.compare("butlyrnewcrdclick") == 0) return BUTLYRNEWCRDCLICK;

	return(0);
};

string PnlPlnrNavDesign::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	else if (ix == BUTDSNVIEWCLICK) return("ButDsnViewClick");
	else if (ix == BUTDSNNEWCRDCLICK) return("ButDsnNewcrdClick");
	else if (ix == BUTDOMVIEWCLICK) return("ButDomViewClick");
	else if (ix == BUTDOMNEWCRDCLICK) return("ButDomNewcrdClick");
	else if (ix == BUTDGDVIEWCLICK) return("ButDgdViewClick");
	else if (ix == BUTDGDNEWCRDCLICK) return("ButDgdNewcrdClick");
	else if (ix == BUTDVCVIEWCLICK) return("ButDvcViewClick");
	else if (ix == BUTDVCNEWCRDCLICK) return("ButDvcNewcrdClick");
	else if (ix == BUTSRUVIEWCLICK) return("ButSruViewClick");
	else if (ix == BUTSRUNEWCRDCLICK) return("ButSruNewcrdClick");
	else if (ix == BUTSTKVIEWCLICK) return("ButStkViewClick");
	else if (ix == BUTSTKNEWCRDCLICK) return("ButStkNewcrdClick");
	else if (ix == BUTLYRVIEWCLICK) return("ButLyrViewClick");
	else if (ix == BUTLYRNEWCRDCLICK) return("ButLyrNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlPlnrNavDesign::ContIac
 ******************************************************************************/

PnlPlnrNavDesign::ContIac::ContIac(
			const uint numFLstPrj
			, const uint numFLstDsn
			, const uint numFLstDom
			, const uint numFLstDgd
			, const uint numFLstDvc
			, const uint numFLstSru
			, const uint numFLstStk
			, const uint numFLstLyr
		) : Block() {
	this->numFLstPrj = numFLstPrj;
	this->numFLstDsn = numFLstDsn;
	this->numFLstDom = numFLstDom;
	this->numFLstDgd = numFLstDgd;
	this->numFLstDvc = numFLstDvc;
	this->numFLstSru = numFLstSru;
	this->numFLstStk = numFLstStk;
	this->numFLstLyr = numFLstLyr;

	mask = {NUMFLSTPRJ, NUMFLSTDSN, NUMFLSTDOM, NUMFLSTDGD, NUMFLSTDVC, NUMFLSTSRU, NUMFLSTSTK, NUMFLSTLYR};
};

bool PnlPlnrNavDesign::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacPlnrNavDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacPlnrNavDesign";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDsn", numFLstDsn)) add(NUMFLSTDSN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDom", numFLstDom)) add(NUMFLSTDOM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDgd", numFLstDgd)) add(NUMFLSTDGD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDvc", numFLstDvc)) add(NUMFLSTDVC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSru", numFLstSru)) add(NUMFLSTSRU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstStk", numFLstStk)) add(NUMFLSTSTK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLyr", numFLstLyr)) add(NUMFLSTLYR);
	};

	return basefound;
};

void PnlPlnrNavDesign::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacPlnrNavDesign";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacPlnrNavDesign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstDsn", numFLstDsn);
		writeUintAttr(wr, itemtag, "sref", "numFLstDom", numFLstDom);
		writeUintAttr(wr, itemtag, "sref", "numFLstDgd", numFLstDgd);
		writeUintAttr(wr, itemtag, "sref", "numFLstDvc", numFLstDvc);
		writeUintAttr(wr, itemtag, "sref", "numFLstSru", numFLstSru);
		writeUintAttr(wr, itemtag, "sref", "numFLstStk", numFLstStk);
		writeUintAttr(wr, itemtag, "sref", "numFLstLyr", numFLstLyr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrNavDesign::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstDsn == comp->numFLstDsn) insert(items, NUMFLSTDSN);
	if (numFLstDom == comp->numFLstDom) insert(items, NUMFLSTDOM);
	if (numFLstDgd == comp->numFLstDgd) insert(items, NUMFLSTDGD);
	if (numFLstDvc == comp->numFLstDvc) insert(items, NUMFLSTDVC);
	if (numFLstSru == comp->numFLstSru) insert(items, NUMFLSTSRU);
	if (numFLstStk == comp->numFLstStk) insert(items, NUMFLSTSTK);
	if (numFLstLyr == comp->numFLstLyr) insert(items, NUMFLSTLYR);

	return(items);
};

set<uint> PnlPlnrNavDesign::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRJ, NUMFLSTDSN, NUMFLSTDOM, NUMFLSTDGD, NUMFLSTDVC, NUMFLSTSRU, NUMFLSTSTK, NUMFLSTLYR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavDesign::StatApp
 ******************************************************************************/

PnlPlnrNavDesign::StatApp::StatApp(
			const uint ixPlnrVExpstate
			, const bool LstPrjAlt
			, const bool LstDsnAlt
			, const bool LstDomAlt
			, const bool LstDgdAlt
			, const bool LstDvcAlt
			, const bool LstSruAlt
			, const bool LstStkAlt
			, const bool LstLyrAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstDsnNumFirstdisp
			, const uint LstDomNumFirstdisp
			, const uint LstDgdNumFirstdisp
			, const uint LstDvcNumFirstdisp
			, const uint LstSruNumFirstdisp
			, const uint LstStkNumFirstdisp
			, const uint LstLyrNumFirstdisp
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->LstPrjAlt = LstPrjAlt;
	this->LstDsnAlt = LstDsnAlt;
	this->LstDomAlt = LstDomAlt;
	this->LstDgdAlt = LstDgdAlt;
	this->LstDvcAlt = LstDvcAlt;
	this->LstSruAlt = LstSruAlt;
	this->LstStkAlt = LstStkAlt;
	this->LstLyrAlt = LstLyrAlt;
	this->LstPrjNumFirstdisp = LstPrjNumFirstdisp;
	this->LstDsnNumFirstdisp = LstDsnNumFirstdisp;
	this->LstDomNumFirstdisp = LstDomNumFirstdisp;
	this->LstDgdNumFirstdisp = LstDgdNumFirstdisp;
	this->LstDvcNumFirstdisp = LstDvcNumFirstdisp;
	this->LstSruNumFirstdisp = LstSruNumFirstdisp;
	this->LstStkNumFirstdisp = LstStkNumFirstdisp;
	this->LstLyrNumFirstdisp = LstLyrNumFirstdisp;

	mask = {IXPLNRVEXPSTATE, LSTPRJALT, LSTDSNALT, LSTDOMALT, LSTDGDALT, LSTDVCALT, LSTSRUALT, LSTSTKALT, LSTLYRALT, LSTPRJNUMFIRSTDISP, LSTDSNNUMFIRSTDISP, LSTDOMNUMFIRSTDISP, LSTDGDNUMFIRSTDISP, LSTDVCNUMFIRSTDISP, LSTSRUNUMFIRSTDISP, LSTSTKNUMFIRSTDISP, LSTLYRNUMFIRSTDISP};
};

bool PnlPlnrNavDesign::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrNavDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrNavDesign";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAlt", LstPrjAlt)) add(LSTPRJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDsnAlt", LstDsnAlt)) add(LSTDSNALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDomAlt", LstDomAlt)) add(LSTDOMALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDgdAlt", LstDgdAlt)) add(LSTDGDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDvcAlt", LstDvcAlt)) add(LSTDVCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSruAlt", LstSruAlt)) add(LSTSRUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStkAlt", LstStkAlt)) add(LSTSTKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLyrAlt", LstLyrAlt)) add(LSTLYRALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp)) add(LSTPRJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDsnNumFirstdisp", LstDsnNumFirstdisp)) add(LSTDSNNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDomNumFirstdisp", LstDomNumFirstdisp)) add(LSTDOMNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDgdNumFirstdisp", LstDgdNumFirstdisp)) add(LSTDGDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDvcNumFirstdisp", LstDvcNumFirstdisp)) add(LSTDVCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSruNumFirstdisp", LstSruNumFirstdisp)) add(LSTSRUNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStkNumFirstdisp", LstStkNumFirstdisp)) add(LSTSTKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLyrNumFirstdisp", LstLyrNumFirstdisp)) add(LSTLYRNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlPlnrNavDesign::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (LstPrjAlt == comp->LstPrjAlt) insert(items, LSTPRJALT);
	if (LstDsnAlt == comp->LstDsnAlt) insert(items, LSTDSNALT);
	if (LstDomAlt == comp->LstDomAlt) insert(items, LSTDOMALT);
	if (LstDgdAlt == comp->LstDgdAlt) insert(items, LSTDGDALT);
	if (LstDvcAlt == comp->LstDvcAlt) insert(items, LSTDVCALT);
	if (LstSruAlt == comp->LstSruAlt) insert(items, LSTSRUALT);
	if (LstStkAlt == comp->LstStkAlt) insert(items, LSTSTKALT);
	if (LstLyrAlt == comp->LstLyrAlt) insert(items, LSTLYRALT);
	if (LstPrjNumFirstdisp == comp->LstPrjNumFirstdisp) insert(items, LSTPRJNUMFIRSTDISP);
	if (LstDsnNumFirstdisp == comp->LstDsnNumFirstdisp) insert(items, LSTDSNNUMFIRSTDISP);
	if (LstDomNumFirstdisp == comp->LstDomNumFirstdisp) insert(items, LSTDOMNUMFIRSTDISP);
	if (LstDgdNumFirstdisp == comp->LstDgdNumFirstdisp) insert(items, LSTDGDNUMFIRSTDISP);
	if (LstDvcNumFirstdisp == comp->LstDvcNumFirstdisp) insert(items, LSTDVCNUMFIRSTDISP);
	if (LstSruNumFirstdisp == comp->LstSruNumFirstdisp) insert(items, LSTSRUNUMFIRSTDISP);
	if (LstStkNumFirstdisp == comp->LstStkNumFirstdisp) insert(items, LSTSTKNUMFIRSTDISP);
	if (LstLyrNumFirstdisp == comp->LstLyrNumFirstdisp) insert(items, LSTLYRNUMFIRSTDISP);

	return(items);
};

set<uint> PnlPlnrNavDesign::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, LSTPRJALT, LSTDSNALT, LSTDOMALT, LSTDGDALT, LSTDVCALT, LSTSRUALT, LSTSTKALT, LSTLYRALT, LSTPRJNUMFIRSTDISP, LSTDSNNUMFIRSTDISP, LSTDOMNUMFIRSTDISP, LSTDGDNUMFIRSTDISP, LSTDVCNUMFIRSTDISP, LSTSRUNUMFIRSTDISP, LSTSTKNUMFIRSTDISP, LSTLYRNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavDesign::StatShr
 ******************************************************************************/

PnlPlnrNavDesign::StatShr::StatShr(
			const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstDsnAvail
			, const bool ButDsnViewActive
			, const bool LstDomAvail
			, const bool ButDomViewActive
			, const bool ButDomNewcrdActive
			, const bool LstDgdAvail
			, const bool ButDgdViewActive
			, const bool ButDgdNewcrdActive
			, const bool LstDvcAvail
			, const bool ButDvcViewActive
			, const bool ButDvcNewcrdActive
			, const bool LstSruAvail
			, const bool ButSruViewActive
			, const bool ButSruNewcrdActive
			, const bool LstStkAvail
			, const bool ButStkViewActive
			, const bool ButStkNewcrdActive
			, const bool LstLyrAvail
			, const bool ButLyrViewActive
			, const bool ButLyrNewcrdActive
		) : Block() {
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstDsnAvail = LstDsnAvail;
	this->ButDsnViewActive = ButDsnViewActive;
	this->LstDomAvail = LstDomAvail;
	this->ButDomViewActive = ButDomViewActive;
	this->ButDomNewcrdActive = ButDomNewcrdActive;
	this->LstDgdAvail = LstDgdAvail;
	this->ButDgdViewActive = ButDgdViewActive;
	this->ButDgdNewcrdActive = ButDgdNewcrdActive;
	this->LstDvcAvail = LstDvcAvail;
	this->ButDvcViewActive = ButDvcViewActive;
	this->ButDvcNewcrdActive = ButDvcNewcrdActive;
	this->LstSruAvail = LstSruAvail;
	this->ButSruViewActive = ButSruViewActive;
	this->ButSruNewcrdActive = ButSruNewcrdActive;
	this->LstStkAvail = LstStkAvail;
	this->ButStkViewActive = ButStkViewActive;
	this->ButStkNewcrdActive = ButStkNewcrdActive;
	this->LstLyrAvail = LstLyrAvail;
	this->ButLyrViewActive = ButLyrViewActive;
	this->ButLyrNewcrdActive = ButLyrNewcrdActive;

	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTDSNAVAIL, BUTDSNVIEWACTIVE, LSTDOMAVAIL, BUTDOMVIEWACTIVE, BUTDOMNEWCRDACTIVE, LSTDGDAVAIL, BUTDGDVIEWACTIVE, BUTDGDNEWCRDACTIVE, LSTDVCAVAIL, BUTDVCVIEWACTIVE, BUTDVCNEWCRDACTIVE, LSTSRUAVAIL, BUTSRUVIEWACTIVE, BUTSRUNEWCRDACTIVE, LSTSTKAVAIL, BUTSTKVIEWACTIVE, BUTSTKNEWCRDACTIVE, LSTLYRAVAIL, BUTLYRVIEWACTIVE, BUTLYRNEWCRDACTIVE};
};

bool PnlPlnrNavDesign::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNavDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNavDesign";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAvail", LstPrjAvail)) add(LSTPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDsnAvail", LstDsnAvail)) add(LSTDSNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDsnViewActive", ButDsnViewActive)) add(BUTDSNVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDomAvail", LstDomAvail)) add(LSTDOMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDomViewActive", ButDomViewActive)) add(BUTDOMVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDomNewcrdActive", ButDomNewcrdActive)) add(BUTDOMNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDgdAvail", LstDgdAvail)) add(LSTDGDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDgdViewActive", ButDgdViewActive)) add(BUTDGDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDgdNewcrdActive", ButDgdNewcrdActive)) add(BUTDGDNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDvcAvail", LstDvcAvail)) add(LSTDVCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDvcViewActive", ButDvcViewActive)) add(BUTDVCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDvcNewcrdActive", ButDvcNewcrdActive)) add(BUTDVCNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSruAvail", LstSruAvail)) add(LSTSRUAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSruViewActive", ButSruViewActive)) add(BUTSRUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSruNewcrdActive", ButSruNewcrdActive)) add(BUTSRUNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStkAvail", LstStkAvail)) add(LSTSTKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStkViewActive", ButStkViewActive)) add(BUTSTKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStkNewcrdActive", ButStkNewcrdActive)) add(BUTSTKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLyrAvail", LstLyrAvail)) add(LSTLYRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLyrViewActive", ButLyrViewActive)) add(BUTLYRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLyrNewcrdActive", ButLyrNewcrdActive)) add(BUTLYRNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrNavDesign::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstDsnAvail == comp->LstDsnAvail) insert(items, LSTDSNAVAIL);
	if (ButDsnViewActive == comp->ButDsnViewActive) insert(items, BUTDSNVIEWACTIVE);
	if (LstDomAvail == comp->LstDomAvail) insert(items, LSTDOMAVAIL);
	if (ButDomViewActive == comp->ButDomViewActive) insert(items, BUTDOMVIEWACTIVE);
	if (ButDomNewcrdActive == comp->ButDomNewcrdActive) insert(items, BUTDOMNEWCRDACTIVE);
	if (LstDgdAvail == comp->LstDgdAvail) insert(items, LSTDGDAVAIL);
	if (ButDgdViewActive == comp->ButDgdViewActive) insert(items, BUTDGDVIEWACTIVE);
	if (ButDgdNewcrdActive == comp->ButDgdNewcrdActive) insert(items, BUTDGDNEWCRDACTIVE);
	if (LstDvcAvail == comp->LstDvcAvail) insert(items, LSTDVCAVAIL);
	if (ButDvcViewActive == comp->ButDvcViewActive) insert(items, BUTDVCVIEWACTIVE);
	if (ButDvcNewcrdActive == comp->ButDvcNewcrdActive) insert(items, BUTDVCNEWCRDACTIVE);
	if (LstSruAvail == comp->LstSruAvail) insert(items, LSTSRUAVAIL);
	if (ButSruViewActive == comp->ButSruViewActive) insert(items, BUTSRUVIEWACTIVE);
	if (ButSruNewcrdActive == comp->ButSruNewcrdActive) insert(items, BUTSRUNEWCRDACTIVE);
	if (LstStkAvail == comp->LstStkAvail) insert(items, LSTSTKAVAIL);
	if (ButStkViewActive == comp->ButStkViewActive) insert(items, BUTSTKVIEWACTIVE);
	if (ButStkNewcrdActive == comp->ButStkNewcrdActive) insert(items, BUTSTKNEWCRDACTIVE);
	if (LstLyrAvail == comp->LstLyrAvail) insert(items, LSTLYRAVAIL);
	if (ButLyrViewActive == comp->ButLyrViewActive) insert(items, BUTLYRVIEWACTIVE);
	if (ButLyrNewcrdActive == comp->ButLyrNewcrdActive) insert(items, BUTLYRNEWCRDACTIVE);

	return(items);
};

set<uint> PnlPlnrNavDesign::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTDSNAVAIL, BUTDSNVIEWACTIVE, LSTDOMAVAIL, BUTDOMVIEWACTIVE, BUTDOMNEWCRDACTIVE, LSTDGDAVAIL, BUTDGDVIEWACTIVE, BUTDGDNEWCRDACTIVE, LSTDVCAVAIL, BUTDVCVIEWACTIVE, BUTDVCNEWCRDACTIVE, LSTSRUAVAIL, BUTSRUVIEWACTIVE, BUTSRUNEWCRDACTIVE, LSTSTKAVAIL, BUTSTKVIEWACTIVE, BUTSTKNEWCRDACTIVE, LSTLYRAVAIL, BUTLYRVIEWACTIVE, BUTLYRNEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrNavDesign::Tag
 ******************************************************************************/

PnlPlnrNavDesign::Tag::Tag(
			const string& Cpt
			, const string& CptPrj
			, const string& CptDsn
			, const string& CptDom
			, const string& CptDgd
			, const string& CptDvc
			, const string& CptSru
			, const string& CptStk
			, const string& CptLyr
		) : Block() {
	this->Cpt = Cpt;
	this->CptPrj = CptPrj;
	this->CptDsn = CptDsn;
	this->CptDom = CptDom;
	this->CptDgd = CptDgd;
	this->CptDvc = CptDvc;
	this->CptSru = CptSru;
	this->CptStk = CptStk;
	this->CptLyr = CptLyr;

	mask = {CPT, CPTPRJ, CPTDSN, CPTDOM, CPTDGD, CPTDVC, CPTSRU, CPTSTK, CPTLYR};
};

bool PnlPlnrNavDesign::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNavDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNavDesign";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDsn", CptDsn)) add(CPTDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDom", CptDom)) add(CPTDOM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDgd", CptDgd)) add(CPTDGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDvc", CptDvc)) add(CPTDVC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSru", CptSru)) add(CPTSRU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStk", CptStk)) add(CPTSTK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLyr", CptLyr)) add(CPTLYR);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrNavDesign::DpchAppData
 ******************************************************************************/

PnlPlnrNavDesign::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

void PnlPlnrNavDesign::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavDesignData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavDesign::DpchAppDo
 ******************************************************************************/

PnlPlnrNavDesign::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrNavDesign::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavDesignDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavDesign::DpchEngData
 ******************************************************************************/

PnlPlnrNavDesign::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVDESIGNDATA) {
	feedFLstDgd.tag = "FeedFLstDgd";
	feedFLstDom.tag = "FeedFLstDom";
	feedFLstDsn.tag = "FeedFLstDsn";
	feedFLstDvc.tag = "FeedFLstDvc";
	feedFLstLyr.tag = "FeedFLstLyr";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstSru.tag = "FeedFLstSru";
	feedFLstStk.tag = "FeedFLstStk";
};

void PnlPlnrNavDesign::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavDesignData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstDgd.readXML(docctx, basexpath, true)) add(FEEDFLSTDGD);
		if (feedFLstDom.readXML(docctx, basexpath, true)) add(FEEDFLSTDOM);
		if (feedFLstDsn.readXML(docctx, basexpath, true)) add(FEEDFLSTDSN);
		if (feedFLstDvc.readXML(docctx, basexpath, true)) add(FEEDFLSTDVC);
		if (feedFLstLyr.readXML(docctx, basexpath, true)) add(FEEDFLSTLYR);
		if (feedFLstPrj.readXML(docctx, basexpath, true)) add(FEEDFLSTPRJ);
		if (feedFLstSru.readXML(docctx, basexpath, true)) add(FEEDFLSTSRU);
		if (feedFLstStk.readXML(docctx, basexpath, true)) add(FEEDFLSTSTK);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstDgd.clear();
		feedFLstDom.clear();
		feedFLstDsn.clear();
		feedFLstDvc.clear();
		feedFLstLyr.clear();
		feedFLstPrj.clear();
		feedFLstSru.clear();
		feedFLstStk.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

