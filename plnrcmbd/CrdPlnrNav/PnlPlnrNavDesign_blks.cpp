/**
  * \file PnlPlnrNavDesign_blks.cpp
  * job handler for job PnlPlnrNavDesign (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrNavDesign::VecVDo
 ******************************************************************************/

uint PnlPlnrNavDesign::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	else if (s == "butprjnewcrdclick") return BUTPRJNEWCRDCLICK;
	else if (s == "butdsnviewclick") return BUTDSNVIEWCLICK;
	else if (s == "butdsnnewcrdclick") return BUTDSNNEWCRDCLICK;
	else if (s == "butdomviewclick") return BUTDOMVIEWCLICK;
	else if (s == "butdomnewcrdclick") return BUTDOMNEWCRDCLICK;
	else if (s == "butdgdviewclick") return BUTDGDVIEWCLICK;
	else if (s == "butdgdnewcrdclick") return BUTDGDNEWCRDCLICK;
	else if (s == "butdvcviewclick") return BUTDVCVIEWCLICK;
	else if (s == "butdvcnewcrdclick") return BUTDVCNEWCRDCLICK;
	else if (s == "butsruviewclick") return BUTSRUVIEWCLICK;
	else if (s == "butsrunewcrdclick") return BUTSRUNEWCRDCLICK;
	else if (s == "butstkviewclick") return BUTSTKVIEWCLICK;
	else if (s == "butstknewcrdclick") return BUTSTKNEWCRDCLICK;
	else if (s == "butlyrviewclick") return BUTLYRVIEWCLICK;
	else if (s == "butlyrnewcrdclick") return BUTLYRNEWCRDCLICK;

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

void PnlPlnrNavDesign::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixPlnrVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrNavDesign";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrNavDesign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAlt", LstPrjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDsnAlt", LstDsnAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDomAlt", LstDomAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDgdAlt", LstDgdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDvcAlt", LstDvcAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSruAlt", LstSruAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstStkAlt", LstStkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLyrAlt", LstLyrAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDsnNumFirstdisp", LstDsnNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDomNumFirstdisp", LstDomNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDgdNumFirstdisp", LstDgdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDvcNumFirstdisp", LstDvcNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSruNumFirstdisp", LstSruNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstStkNumFirstdisp", LstStkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstLyrNumFirstdisp", LstLyrNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrNavDesign::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrNavDesign";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrNavDesign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAvail", LstPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDsnAvail", LstDsnAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDsnViewActive", ButDsnViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDomAvail", LstDomAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDomViewActive", ButDomViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDomNewcrdActive", ButDomNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDgdAvail", LstDgdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDgdViewActive", ButDgdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDgdNewcrdActive", ButDgdNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDvcAvail", LstDvcAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDvcViewActive", ButDvcViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDvcNewcrdActive", ButDvcNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSruAvail", LstSruAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSruViewActive", ButSruViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSruNewcrdActive", ButSruNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstStkAvail", LstStkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStkViewActive", ButStkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStkNewcrdActive", ButStkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstLyrAvail", LstLyrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLyrViewActive", ButLyrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButLyrNewcrdActive", ButLyrNewcrdActive);
	xmlTextWriterEndElement(wr);
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

void PnlPlnrNavDesign::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrNavDesign";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrNavDesign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Design module");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projects");
			writeStringAttr(wr, itemtag, "sref", "CptDsn", "designs");
			writeStringAttr(wr, itemtag, "sref", "CptDom", "domains");
			writeStringAttr(wr, itemtag, "sref", "CptDgd", "domain guides");
			writeStringAttr(wr, itemtag, "sref", "CptDvc", "devices");
			writeStringAttr(wr, itemtag, "sref", "CptSru", "structures");
			writeStringAttr(wr, itemtag, "sref", "CptStk", "stacks");
			writeStringAttr(wr, itemtag, "sref", "CptLyr", "layers");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrNavDesign::DpchAppData
 ******************************************************************************/

PnlPlnrNavDesign::DpchAppData::DpchAppData() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDATA) {
};

void PnlPlnrNavDesign::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavDesignData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlPlnrNavDesign::DpchAppDo
 ******************************************************************************/

PnlPlnrNavDesign::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDO) {
	ixVDo = 0;
};

void PnlPlnrNavDesign::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrNavDesignDo");
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
 class PnlPlnrNavDesign::DpchEngData
 ******************************************************************************/

PnlPlnrNavDesign::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstDgd
			, Feed* feedFLstDom
			, Feed* feedFLstDsn
			, Feed* feedFLstDvc
			, Feed* feedFLstLyr
			, Feed* feedFLstPrj
			, Feed* feedFLstSru
			, Feed* feedFLstStk
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRNAVDESIGNDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTDGD, FEEDFLSTDOM, FEEDFLSTDSN, FEEDFLSTDVC, FEEDFLSTLYR, FEEDFLSTPRJ, FEEDFLSTSRU, FEEDFLSTSTK, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTDGD) && feedFLstDgd) this->feedFLstDgd = *feedFLstDgd;
	if (find(this->mask, FEEDFLSTDOM) && feedFLstDom) this->feedFLstDom = *feedFLstDom;
	if (find(this->mask, FEEDFLSTDSN) && feedFLstDsn) this->feedFLstDsn = *feedFLstDsn;
	if (find(this->mask, FEEDFLSTDVC) && feedFLstDvc) this->feedFLstDvc = *feedFLstDvc;
	if (find(this->mask, FEEDFLSTLYR) && feedFLstLyr) this->feedFLstLyr = *feedFLstLyr;
	if (find(this->mask, FEEDFLSTPRJ) && feedFLstPrj) this->feedFLstPrj = *feedFLstPrj;
	if (find(this->mask, FEEDFLSTSRU) && feedFLstSru) this->feedFLstSru = *feedFLstSru;
	if (find(this->mask, FEEDFLSTSTK) && feedFLstStk) this->feedFLstStk = *feedFLstStk;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrNavDesign::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTDGD)) {feedFLstDgd = src->feedFLstDgd; add(FEEDFLSTDGD);};
	if (src->has(FEEDFLSTDOM)) {feedFLstDom = src->feedFLstDom; add(FEEDFLSTDOM);};
	if (src->has(FEEDFLSTDSN)) {feedFLstDsn = src->feedFLstDsn; add(FEEDFLSTDSN);};
	if (src->has(FEEDFLSTDVC)) {feedFLstDvc = src->feedFLstDvc; add(FEEDFLSTDVC);};
	if (src->has(FEEDFLSTLYR)) {feedFLstLyr = src->feedFLstLyr; add(FEEDFLSTLYR);};
	if (src->has(FEEDFLSTPRJ)) {feedFLstPrj = src->feedFLstPrj; add(FEEDFLSTPRJ);};
	if (src->has(FEEDFLSTSRU)) {feedFLstSru = src->feedFLstSru; add(FEEDFLSTSRU);};
	if (src->has(FEEDFLSTSTK)) {feedFLstStk = src->feedFLstStk; add(FEEDFLSTSTK);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrNavDesign::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrNavDesignData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTDGD)) feedFLstDgd.writeXML(wr);
		if (has(FEEDFLSTDOM)) feedFLstDom.writeXML(wr);
		if (has(FEEDFLSTDSN)) feedFLstDsn.writeXML(wr);
		if (has(FEEDFLSTDVC)) feedFLstDvc.writeXML(wr);
		if (has(FEEDFLSTLYR)) feedFLstLyr.writeXML(wr);
		if (has(FEEDFLSTPRJ)) feedFLstPrj.writeXML(wr);
		if (has(FEEDFLSTSRU)) feedFLstSru.writeXML(wr);
		if (has(FEEDFLSTSTK)) feedFLstStk.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


