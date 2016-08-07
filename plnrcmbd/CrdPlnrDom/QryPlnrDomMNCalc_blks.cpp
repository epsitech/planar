/**
  * \file QryPlnrDomMNCalc_blks.cpp
  * job handler for job QryPlnrDomMNCalc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class QryPlnrDomMNCalc::StatApp
 ******************************************************************************/

void QryPlnrDomMNCalc::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryPlnrDomMNCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryPlnrDomMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryPlnrDomMNCalc::StatShr
 ******************************************************************************/

QryPlnrDomMNCalc::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryPlnrDomMNCalc::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryPlnrDomMNCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryPlnrDomMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrDomMNCalc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrDomMNCalc::StatShr::diff(
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
 class QryPlnrDomMNCalc::StgIac
 ******************************************************************************/

QryPlnrDomMNCalc::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryPlnrDomMNCalc::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryPlnrDomMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryPlnrDomMNCalc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryPlnrDomMNCalc::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryPlnrDomMNCalc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryPlnrDomMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrDomMNCalc::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrDomMNCalc::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};


