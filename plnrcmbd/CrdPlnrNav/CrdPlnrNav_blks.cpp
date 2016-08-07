/**
  * \file CrdPlnrNav_blks.cpp
  * job handler for job CrdPlnrNav (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class CrdPlnrNav::VecVDo
 ******************************************************************************/

uint CrdPlnrNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitsestrmclick") return MITSESTRMCLICK;
	else if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	else if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	else if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	else if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	else if (s == "mitcrddtpclick") return MITCRDDTPCLICK;
	else if (s == "mitcrdctpclick") return MITCRDCTPCLICK;
	else if (s == "mitcrdmatclick") return MITCRDMATCLICK;
	else if (s == "mitcrdprjclick") return MITCRDPRJCLICK;
	else if (s == "mitcrddsnclick") return MITCRDDSNCLICK;
	else if (s == "mitcrddomclick") return MITCRDDOMCLICK;
	else if (s == "mitcrddgdclick") return MITCRDDGDCLICK;
	else if (s == "mitcrddvcclick") return MITCRDDVCCLICK;
	else if (s == "mitcrdsruclick") return MITCRDSRUCLICK;
	else if (s == "mitcrdstkclick") return MITCRDSTKCLICK;
	else if (s == "mitcrdlyrclick") return MITCRDLYRCLICK;
	else if (s == "mitcrdclcclick") return MITCRDCLCCLICK;
	else if (s == "mitcrdcliclick") return MITCRDCLICLICK;
	else if (s == "mitcrdtpoclick") return MITCRDTPOCLICK;
	else if (s == "mitapploiclick") return MITAPPLOICLICK;

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

	if (s == "idle") return IDLE;
	else if (s == "alrplnrabt") return ALRPLNRABT;
	else if (s == "close") return CLOSE;

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

void CrdPlnrNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdPlnrNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

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

void CrdPlnrNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVReqitmode
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
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVReqitmode", VecPlnrVReqitmode::getSref(ixPlnrVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneGlobal", initdoneGlobal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDesign", initdoneDesign);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCalc", initdoneCalc);
		writeBoolAttr(wr, itemtag, "sref", "initdoneLayout", initdoneLayout);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrNav::StatShr
 ******************************************************************************/

CrdPlnrNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefPre
			, const bool pnlpreAvail
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefGlobal
			, const bool pnlglobalAvail
			, const ubigint jrefDesign
			, const bool pnldesignAvail
			, const ubigint jrefCalc
			, const bool pnlcalcAvail
			, const ubigint jrefLayout
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
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefPre = jrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefGlobal = jrefGlobal;
	this->pnlglobalAvail = pnlglobalAvail;
	this->jrefDesign = jrefDesign;
	this->pnldesignAvail = pnldesignAvail;
	this->jrefCalc = jrefCalc;
	this->pnlcalcAvail = pnlcalcAvail;
	this->jrefLayout = jrefLayout;
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

	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFDESIGN, PNLDESIGNAVAIL, JREFCALC, PNLCALCAVAIL, JREFLAYOUT, PNLLAYOUTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDDTPAVAIL, MITCRDCTPAVAIL, MITCRDMATAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDDSNAVAIL, MITCRDDOMAVAIL, MITCRDDOMACTIVE, MITCRDDGDAVAIL, MITCRDDGDACTIVE, MITCRDDVCAVAIL, MITCRDDVCACTIVE, MITCRDSRUAVAIL, MITCRDSRUACTIVE, MITCRDSTKAVAIL, MITCRDSTKACTIVE, MITCRDLYRAVAIL, MITCRDLYRACTIVE, MSPCRD4AVAIL, MITCRDCLCAVAIL, MITCRDCLCACTIVE, MITCRDCLIAVAIL, MITCRDCLIACTIVE, MSPCRD5AVAIL, MITCRDTPOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdPlnrNav::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(mScr, scr, descr, jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeBoolAttr(wr, itemtag, "sref", "pnlpreAvail", pnlpreAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(mScr, scr, descr, jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefGlobal", Scr::scramble(mScr, scr, descr, jrefGlobal));
		writeBoolAttr(wr, itemtag, "sref", "pnlglobalAvail", pnlglobalAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDesign", Scr::scramble(mScr, scr, descr, jrefDesign));
		writeBoolAttr(wr, itemtag, "sref", "pnldesignAvail", pnldesignAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCalc", Scr::scramble(mScr, scr, descr, jrefCalc));
		writeBoolAttr(wr, itemtag, "sref", "pnlcalcAvail", pnlcalcAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefLayout", Scr::scramble(mScr, scr, descr, jrefLayout));
		writeBoolAttr(wr, itemtag, "sref", "pnllayoutAvail", pnllayoutAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDtpAvail", MitCrdDtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCtpAvail", MitCrdCtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMatAvail", MitCrdMatAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrjAvail", MitCrdPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDsnAvail", MitCrdDsnAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDomAvail", MitCrdDomAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDomActive", MitCrdDomActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDgdAvail", MitCrdDgdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDgdActive", MitCrdDgdActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDvcAvail", MitCrdDvcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDvcActive", MitCrdDvcActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSruAvail", MitCrdSruAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSruActive", MitCrdSruActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdStkAvail", MitCrdStkAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdStkActive", MitCrdStkActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLyrAvail", MitCrdLyrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLyrActive", MitCrdLyrActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdClcAvail", MitCrdClcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdClcActive", MitCrdClcActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCliAvail", MitCrdCliAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCliActive", MitCrdCliActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Avail", MspCrd5Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTpoAvail", MitCrdTpoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdPlnrNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefGlobal == comp->jrefGlobal) insert(items, JREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (jrefDesign == comp->jrefDesign) insert(items, JREFDESIGN);
	if (pnldesignAvail == comp->pnldesignAvail) insert(items, PNLDESIGNAVAIL);
	if (jrefCalc == comp->jrefCalc) insert(items, JREFCALC);
	if (pnlcalcAvail == comp->pnlcalcAvail) insert(items, PNLCALCAVAIL);
	if (jrefLayout == comp->jrefLayout) insert(items, JREFLAYOUT);
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

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFDESIGN, PNLDESIGNAVAIL, JREFCALC, PNLCALCAVAIL, JREFLAYOUT, PNLLAYOUTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDDTPAVAIL, MITCRDCTPAVAIL, MITCRDMATAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDDSNAVAIL, MITCRDDOMAVAIL, MITCRDDOMACTIVE, MITCRDDGDAVAIL, MITCRDDGDACTIVE, MITCRDDVCAVAIL, MITCRDDVCACTIVE, MITCRDSRUAVAIL, MITCRDSRUACTIVE, MITCRDSTKAVAIL, MITCRDSTKACTIVE, MITCRDLYRAVAIL, MITCRDLYRACTIVE, MSPCRD4AVAIL, MITCRDCLCAVAIL, MITCRDCLCACTIVE, MITCRDCLIAVAIL, MITCRDCLIACTIVE, MSPCRD5AVAIL, MITCRDTPOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdPlnrNav::Tag
 ******************************************************************************/

void CrdPlnrNav::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDtp", "Device templates ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCtp", "Calculation templates ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMat", "Materials ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDsn", "Designs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDom", "Domains ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDgd", "Domain guides ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDvc", "Devices ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSru", "Structures ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdStk", "Stacks ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLyr", "Layers ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdClc", "Calculations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCli", "Calculation items ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTpo", "Tape-outs ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::ABOUT, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::HELP, ixPlnrVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::CLSESS, ixPlnrVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::LOAINI, ixPlnrVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdPlnrNav::DpchAppDo
 ******************************************************************************/

CrdPlnrNav::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDO) {
	ixVDo = 0;
};

void CrdPlnrNav::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavDo");
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
	} else {
	};
};

/******************************************************************************
 class CrdPlnrNav::DpchEngData
 ******************************************************************************/

CrdPlnrNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void CrdPlnrNav::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdPlnrNav::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


