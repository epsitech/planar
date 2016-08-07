/**
  * \file CrdPlnrNav.cpp
  * app access code for job CrdPlnrNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "CrdPlnrNav.h"

/******************************************************************************
 class CrdPlnrNav::VecVDo
 ******************************************************************************/

uint CrdPlnrNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("close") == 0) return CLOSE;
	else if (s.compare("mitappabtclick") == 0) return MITAPPABTCLICK;
	else if (s.compare("mitsestrmclick") == 0) return MITSESTRMCLICK;
	else if (s.compare("mitcrdusgclick") == 0) return MITCRDUSGCLICK;
	else if (s.compare("mitcrdusrclick") == 0) return MITCRDUSRCLICK;
	else if (s.compare("mitcrdprsclick") == 0) return MITCRDPRSCLICK;
	else if (s.compare("mitcrdfilclick") == 0) return MITCRDFILCLICK;
	else if (s.compare("mitcrddtpclick") == 0) return MITCRDDTPCLICK;
	else if (s.compare("mitcrdctpclick") == 0) return MITCRDCTPCLICK;
	else if (s.compare("mitcrdmatclick") == 0) return MITCRDMATCLICK;
	else if (s.compare("mitcrdprjclick") == 0) return MITCRDPRJCLICK;
	else if (s.compare("mitcrddsnclick") == 0) return MITCRDDSNCLICK;
	else if (s.compare("mitcrddomclick") == 0) return MITCRDDOMCLICK;
	else if (s.compare("mitcrddgdclick") == 0) return MITCRDDGDCLICK;
	else if (s.compare("mitcrddvcclick") == 0) return MITCRDDVCCLICK;
	else if (s.compare("mitcrdsruclick") == 0) return MITCRDSRUCLICK;
	else if (s.compare("mitcrdstkclick") == 0) return MITCRDSTKCLICK;
	else if (s.compare("mitcrdlyrclick") == 0) return MITCRDLYRCLICK;
	else if (s.compare("mitcrdclcclick") == 0) return MITCRDCLCCLICK;
	else if (s.compare("mitcrdcliclick") == 0) return MITCRDCLICLICK;
	else if (s.compare("mitcrdtpoclick") == 0) return MITCRDTPOCLICK;
	else if (s.compare("mitapploiclick") == 0) return MITAPPLOICLICK;

	return(0);
};

string CrdPlnrNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	else if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	else if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	else if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	else if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	else if (ix == MITCRDDTPCLICK) return("MitCrdDtpClick");
	else if (ix == MITCRDCTPCLICK) return("MitCrdCtpClick");
	else if (ix == MITCRDMATCLICK) return("MitCrdMatClick");
	else if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
	else if (ix == MITCRDDSNCLICK) return("MitCrdDsnClick");
	else if (ix == MITCRDDOMCLICK) return("MitCrdDomClick");
	else if (ix == MITCRDDGDCLICK) return("MitCrdDgdClick");
	else if (ix == MITCRDDVCCLICK) return("MitCrdDvcClick");
	else if (ix == MITCRDSRUCLICK) return("MitCrdSruClick");
	else if (ix == MITCRDSTKCLICK) return("MitCrdStkClick");
	else if (ix == MITCRDLYRCLICK) return("MitCrdLyrClick");
	else if (ix == MITCRDCLCCLICK) return("MitCrdClcClick");
	else if (ix == MITCRDCLICLICK) return("MitCrdCliClick");
	else if (ix == MITCRDTPOCLICK) return("MitCrdTpoClick");
	else if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdPlnrNav::VecVSge
 ******************************************************************************/

uint CrdPlnrNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("alrplnrabt") == 0) return ALRPLNRABT;
	else if (s.compare("close") == 0) return CLOSE;

	return(0);
};

string CrdPlnrNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRPLNRABT) return("alrplnrabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdPlnrNav::ContInf
 ******************************************************************************/

CrdPlnrNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdPlnrNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdPlnrNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxSesSes1.compare(comp->MtxSesSes1) == 0) insert(items, MTXSESSES1);
	if (MtxSesSes2.compare(comp->MtxSesSes2) == 0) insert(items, MTXSESSES2);
	if (MtxSesSes3.compare(comp->MtxSesSes3) == 0) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdPlnrNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrNav::StatApp
 ******************************************************************************/

CrdPlnrNav::StatApp::StatApp(
			const uint ixPlnrVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneGlobal
			, const bool initdoneDesign
			, const bool initdoneCalc
			, const bool initdoneLayout
		) : Block() {
	this->ixPlnrVReqitmode = ixPlnrVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdonePre = initdonePre;
	this->initdoneAdmin = initdoneAdmin;
	this->initdoneGlobal = initdoneGlobal;
	this->initdoneDesign = initdoneDesign;
	this->initdoneCalc = initdoneCalc;
	this->initdoneLayout = initdoneLayout;

	mask = {IXPLNRVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDESIGN, INITDONECALC, INITDONELAYOUT};
};

bool CrdPlnrNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode)) {
			ixPlnrVReqitmode = VecPlnrVReqitmode::getIx(srefIxPlnrVReqitmode);
			add(IXPLNRVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneGlobal", initdoneGlobal)) add(INITDONEGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDesign", initdoneDesign)) add(INITDONEDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCalc", initdoneCalc)) add(INITDONECALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLayout", initdoneLayout)) add(INITDONELAYOUT);
	};

	return basefound;
};

set<uint> CrdPlnrNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixPlnrVReqitmode == comp->ixPlnrVReqitmode) insert(items, IXPLNRVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneGlobal == comp->initdoneGlobal) insert(items, INITDONEGLOBAL);
	if (initdoneDesign == comp->initdoneDesign) insert(items, INITDONEDESIGN);
	if (initdoneCalc == comp->initdoneCalc) insert(items, INITDONECALC);
	if (initdoneLayout == comp->initdoneLayout) insert(items, INITDONELAYOUT);

	return(items);
};

set<uint> CrdPlnrNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDESIGN, INITDONECALC, INITDONELAYOUT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrNav::StatShr
 ******************************************************************************/

CrdPlnrNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefHeadbar
			, const string& scrJrefPre
			, const bool pnlpreAvail
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefGlobal
			, const bool pnlglobalAvail
			, const string& scrJrefDesign
			, const bool pnldesignAvail
			, const string& scrJrefCalc
			, const bool pnlcalcAvail
			, const string& scrJrefLayout
			, const bool pnllayoutAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MspCrd2Avail
			, const bool MitCrdDtpAvail
			, const bool MitCrdCtpAvail
			, const bool MitCrdMatAvail
			, const bool MspCrd3Avail
			, const bool MitCrdPrjAvail
			, const bool MitCrdDsnAvail
			, const bool MitCrdDomAvail
			, const bool MitCrdDomActive
			, const bool MitCrdDgdAvail
			, const bool MitCrdDgdActive
			, const bool MitCrdDvcAvail
			, const bool MitCrdDvcActive
			, const bool MitCrdSruAvail
			, const bool MitCrdSruActive
			, const bool MitCrdStkAvail
			, const bool MitCrdStkActive
			, const bool MitCrdLyrAvail
			, const bool MitCrdLyrActive
			, const bool MspCrd4Avail
			, const bool MitCrdClcAvail
			, const bool MitCrdClcActive
			, const bool MitCrdCliAvail
			, const bool MitCrdCliActive
			, const bool MspCrd5Avail
			, const bool MitCrdTpoAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) : Block() {
	this->scrJrefDlgloaini = scrJrefDlgloaini;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefPre = scrJrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->scrJrefAdmin = scrJrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->scrJrefGlobal = scrJrefGlobal;
	this->pnlglobalAvail = pnlglobalAvail;
	this->scrJrefDesign = scrJrefDesign;
	this->pnldesignAvail = pnldesignAvail;
	this->scrJrefCalc = scrJrefCalc;
	this->pnlcalcAvail = pnlcalcAvail;
	this->scrJrefLayout = scrJrefLayout;
	this->pnllayoutAvail = pnllayoutAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdDtpAvail = MitCrdDtpAvail;
	this->MitCrdCtpAvail = MitCrdCtpAvail;
	this->MitCrdMatAvail = MitCrdMatAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdPrjAvail = MitCrdPrjAvail;
	this->MitCrdDsnAvail = MitCrdDsnAvail;
	this->MitCrdDomAvail = MitCrdDomAvail;
	this->MitCrdDomActive = MitCrdDomActive;
	this->MitCrdDgdAvail = MitCrdDgdAvail;
	this->MitCrdDgdActive = MitCrdDgdActive;
	this->MitCrdDvcAvail = MitCrdDvcAvail;
	this->MitCrdDvcActive = MitCrdDvcActive;
	this->MitCrdSruAvail = MitCrdSruAvail;
	this->MitCrdSruActive = MitCrdSruActive;
	this->MitCrdStkAvail = MitCrdStkAvail;
	this->MitCrdStkActive = MitCrdStkActive;
	this->MitCrdLyrAvail = MitCrdLyrAvail;
	this->MitCrdLyrActive = MitCrdLyrActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MitCrdClcAvail = MitCrdClcAvail;
	this->MitCrdClcActive = MitCrdClcActive;
	this->MitCrdCliAvail = MitCrdCliAvail;
	this->MitCrdCliActive = MitCrdCliActive;
	this->MspCrd5Avail = MspCrd5Avail;
	this->MitCrdTpoAvail = MitCrdTpoAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDESIGN, PNLDESIGNAVAIL, SCRJREFCALC, PNLCALCAVAIL, SCRJREFLAYOUT, PNLLAYOUTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDDTPAVAIL, MITCRDCTPAVAIL, MITCRDMATAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDDSNAVAIL, MITCRDDOMAVAIL, MITCRDDOMACTIVE, MITCRDDGDAVAIL, MITCRDDGDACTIVE, MITCRDDVCAVAIL, MITCRDDVCACTIVE, MITCRDSRUAVAIL, MITCRDSRUACTIVE, MITCRDSTKAVAIL, MITCRDSTKACTIVE, MITCRDLYRAVAIL, MITCRDLYRACTIVE, MSPCRD4AVAIL, MITCRDCLCAVAIL, MITCRDCLCACTIVE, MITCRDCLIAVAIL, MITCRDCLIACTIVE, MSPCRD5AVAIL, MITCRDTPOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

bool CrdPlnrNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpreAvail", pnlpreAvail)) add(PNLPREAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", scrJrefGlobal)) add(SCRJREFGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlglobalAvail", pnlglobalAvail)) add(PNLGLOBALAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDesign", scrJrefDesign)) add(SCRJREFDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldesignAvail", pnldesignAvail)) add(PNLDESIGNAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCalc", scrJrefCalc)) add(SCRJREFCALC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlcalcAvail", pnlcalcAvail)) add(PNLCALCAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLayout", scrJrefLayout)) add(SCRJREFLAYOUT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnllayoutAvail", pnllayoutAvail)) add(PNLLAYOUTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDtpAvail", MitCrdDtpAvail)) add(MITCRDDTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCtpAvail", MitCrdCtpAvail)) add(MITCRDCTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMatAvail", MitCrdMatAvail)) add(MITCRDMATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", MitCrdPrjAvail)) add(MITCRDPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDsnAvail", MitCrdDsnAvail)) add(MITCRDDSNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDomAvail", MitCrdDomAvail)) add(MITCRDDOMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDomActive", MitCrdDomActive)) add(MITCRDDOMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDgdAvail", MitCrdDgdAvail)) add(MITCRDDGDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDgdActive", MitCrdDgdActive)) add(MITCRDDGDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDvcAvail", MitCrdDvcAvail)) add(MITCRDDVCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDvcActive", MitCrdDvcActive)) add(MITCRDDVCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSruAvail", MitCrdSruAvail)) add(MITCRDSRUAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSruActive", MitCrdSruActive)) add(MITCRDSRUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdStkAvail", MitCrdStkAvail)) add(MITCRDSTKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdStkActive", MitCrdStkActive)) add(MITCRDSTKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLyrAvail", MitCrdLyrAvail)) add(MITCRDLYRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLyrActive", MitCrdLyrActive)) add(MITCRDLYRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdClcAvail", MitCrdClcAvail)) add(MITCRDCLCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdClcActive", MitCrdClcActive)) add(MITCRDCLCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCliAvail", MitCrdCliAvail)) add(MITCRDCLIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCliActive", MitCrdCliActive)) add(MITCRDCLIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", MspCrd5Avail)) add(MSPCRD5AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTpoAvail", MitCrdTpoAvail)) add(MITCRDTPOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdPlnrNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini.compare(comp->scrJrefDlgloaini) == 0) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (scrJrefAdmin.compare(comp->scrJrefAdmin) == 0) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefGlobal.compare(comp->scrJrefGlobal) == 0) insert(items, SCRJREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (scrJrefDesign.compare(comp->scrJrefDesign) == 0) insert(items, SCRJREFDESIGN);
	if (pnldesignAvail == comp->pnldesignAvail) insert(items, PNLDESIGNAVAIL);
	if (scrJrefCalc.compare(comp->scrJrefCalc) == 0) insert(items, SCRJREFCALC);
	if (pnlcalcAvail == comp->pnlcalcAvail) insert(items, PNLCALCAVAIL);
	if (scrJrefLayout.compare(comp->scrJrefLayout) == 0) insert(items, SCRJREFLAYOUT);
	if (pnllayoutAvail == comp->pnllayoutAvail) insert(items, PNLLAYOUTAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdDtpAvail == comp->MitCrdDtpAvail) insert(items, MITCRDDTPAVAIL);
	if (MitCrdCtpAvail == comp->MitCrdCtpAvail) insert(items, MITCRDCTPAVAIL);
	if (MitCrdMatAvail == comp->MitCrdMatAvail) insert(items, MITCRDMATAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdPrjAvail == comp->MitCrdPrjAvail) insert(items, MITCRDPRJAVAIL);
	if (MitCrdDsnAvail == comp->MitCrdDsnAvail) insert(items, MITCRDDSNAVAIL);
	if (MitCrdDomAvail == comp->MitCrdDomAvail) insert(items, MITCRDDOMAVAIL);
	if (MitCrdDomActive == comp->MitCrdDomActive) insert(items, MITCRDDOMACTIVE);
	if (MitCrdDgdAvail == comp->MitCrdDgdAvail) insert(items, MITCRDDGDAVAIL);
	if (MitCrdDgdActive == comp->MitCrdDgdActive) insert(items, MITCRDDGDACTIVE);
	if (MitCrdDvcAvail == comp->MitCrdDvcAvail) insert(items, MITCRDDVCAVAIL);
	if (MitCrdDvcActive == comp->MitCrdDvcActive) insert(items, MITCRDDVCACTIVE);
	if (MitCrdSruAvail == comp->MitCrdSruAvail) insert(items, MITCRDSRUAVAIL);
	if (MitCrdSruActive == comp->MitCrdSruActive) insert(items, MITCRDSRUACTIVE);
	if (MitCrdStkAvail == comp->MitCrdStkAvail) insert(items, MITCRDSTKAVAIL);
	if (MitCrdStkActive == comp->MitCrdStkActive) insert(items, MITCRDSTKACTIVE);
	if (MitCrdLyrAvail == comp->MitCrdLyrAvail) insert(items, MITCRDLYRAVAIL);
	if (MitCrdLyrActive == comp->MitCrdLyrActive) insert(items, MITCRDLYRACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdClcAvail == comp->MitCrdClcAvail) insert(items, MITCRDCLCAVAIL);
	if (MitCrdClcActive == comp->MitCrdClcActive) insert(items, MITCRDCLCACTIVE);
	if (MitCrdCliAvail == comp->MitCrdCliAvail) insert(items, MITCRDCLIAVAIL);
	if (MitCrdCliActive == comp->MitCrdCliActive) insert(items, MITCRDCLIACTIVE);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MitCrdTpoAvail == comp->MitCrdTpoAvail) insert(items, MITCRDTPOAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdPlnrNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDESIGN, PNLDESIGNAVAIL, SCRJREFCALC, PNLCALCAVAIL, SCRJREFLAYOUT, PNLLAYOUTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDDTPAVAIL, MITCRDCTPAVAIL, MITCRDMATAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDDSNAVAIL, MITCRDDOMAVAIL, MITCRDDOMACTIVE, MITCRDDGDAVAIL, MITCRDDGDACTIVE, MITCRDDVCAVAIL, MITCRDDVCACTIVE, MITCRDSRUAVAIL, MITCRDSRUACTIVE, MITCRDSTKAVAIL, MITCRDSTKACTIVE, MITCRDLYRAVAIL, MITCRDLYRACTIVE, MSPCRD4AVAIL, MITCRDCLCAVAIL, MITCRDCLCACTIVE, MITCRDCLIAVAIL, MITCRDCLIACTIVE, MSPCRD5AVAIL, MITCRDTPOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrNav::Tag
 ******************************************************************************/

CrdPlnrNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdFil
			, const string& MitCrdDtp
			, const string& MitCrdCtp
			, const string& MitCrdMat
			, const string& MitCrdPrj
			, const string& MitCrdDsn
			, const string& MitCrdDom
			, const string& MitCrdDgd
			, const string& MitCrdDvc
			, const string& MitCrdSru
			, const string& MitCrdStk
			, const string& MitCrdLyr
			, const string& MitCrdClc
			, const string& MitCrdCli
			, const string& MitCrdTpo
			, const string& MitAppLoi
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitSesTrm = MitSesTrm;
	this->MitCrdUsg = MitCrdUsg;
	this->MitCrdUsr = MitCrdUsr;
	this->MitCrdPrs = MitCrdPrs;
	this->MitCrdFil = MitCrdFil;
	this->MitCrdDtp = MitCrdDtp;
	this->MitCrdCtp = MitCrdCtp;
	this->MitCrdMat = MitCrdMat;
	this->MitCrdPrj = MitCrdPrj;
	this->MitCrdDsn = MitCrdDsn;
	this->MitCrdDom = MitCrdDom;
	this->MitCrdDgd = MitCrdDgd;
	this->MitCrdDvc = MitCrdDvc;
	this->MitCrdSru = MitCrdSru;
	this->MitCrdStk = MitCrdStk;
	this->MitCrdLyr = MitCrdLyr;
	this->MitCrdClc = MitCrdClc;
	this->MitCrdCli = MitCrdCli;
	this->MitCrdTpo = MitCrdTpo;
	this->MitAppLoi = MitAppLoi;

	mask = {MITAPPABT, MRLAPPHLP, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDDTP, MITCRDCTP, MITCRDMAT, MITCRDPRJ, MITCRDDSN, MITCRDDOM, MITCRDDGD, MITCRDDVC, MITCRDSRU, MITCRDSTK, MITCRDLYR, MITCRDCLC, MITCRDCLI, MITCRDTPO, MITAPPLOI};
};

bool CrdPlnrNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDtp", MitCrdDtp)) add(MITCRDDTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCtp", MitCrdCtp)) add(MITCRDCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMat", MitCrdMat)) add(MITCRDMAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", MitCrdPrj)) add(MITCRDPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDsn", MitCrdDsn)) add(MITCRDDSN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDom", MitCrdDom)) add(MITCRDDOM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDgd", MitCrdDgd)) add(MITCRDDGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDvc", MitCrdDvc)) add(MITCRDDVC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSru", MitCrdSru)) add(MITCRDSRU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdStk", MitCrdStk)) add(MITCRDSTK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLyr", MitCrdLyr)) add(MITCRDLYR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdClc", MitCrdClc)) add(MITCRDCLC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCli", MitCrdCli)) add(MITCRDCLI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTpo", MitCrdTpo)) add(MITCRDTPO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdPlnrNav::DpchAppDo
 ******************************************************************************/

CrdPlnrNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void CrdPlnrNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrNav::DpchEngData
 ******************************************************************************/

CrdPlnrNav::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVDATA) {
	feedFSge.tag = "FeedFSge";
};

void CrdPlnrNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

