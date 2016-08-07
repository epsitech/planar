/**
  * \file QryPlnrPrsList_blks.cpp
  * job handler for job QryPlnrPrsList (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class QryPlnrPrsList::VecVOrd
 ******************************************************************************/

uint QryPlnrPrsList::VecVOrd::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lnm") return LNM;
	else if (s == "grp") return GRP;
	else if (s == "own") return OWN;

	return(0);
};

string QryPlnrPrsList::VecVOrd::getSref(
			const uint ix
		) {
	if (ix == LNM) return("lnm");
	else if (ix == GRP) return("grp");
	else if (ix == OWN) return("own");

	return("");
};

void QryPlnrPrsList::VecVOrd::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class QryPlnrPrsList::StatApp
 ******************************************************************************/

void QryPlnrPrsList::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryPlnrPrsList::StatShr
 ******************************************************************************/

QryPlnrPrsList::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryPlnrPrsList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrPrsList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrPrsList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryPlnrPrsList::StgIac
 ******************************************************************************/

QryPlnrPrsList::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryPlnrPrsList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryPlnrPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryPlnrPrsList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryPlnrPrsList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryPlnrPrsList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryPlnrPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrPrsList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrPrsList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};


