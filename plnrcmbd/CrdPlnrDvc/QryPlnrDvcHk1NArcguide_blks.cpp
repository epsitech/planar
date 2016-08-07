/**
  * \file QryPlnrDvcHk1NArcguide_blks.cpp
  * job handler for job QryPlnrDvcHk1NArcguide (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class QryPlnrDvcHk1NArcguide::StatApp
 ******************************************************************************/

void QryPlnrDvcHk1NArcguide::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryPlnrDvcHk1NArcguide";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryPlnrDvcHk1NArcguide";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryPlnrDvcHk1NArcguide::StatShr
 ******************************************************************************/

QryPlnrDvcHk1NArcguide::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryPlnrDvcHk1NArcguide::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryPlnrDvcHk1NArcguide";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryPlnrDvcHk1NArcguide";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrDvcHk1NArcguide::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrDvcHk1NArcguide::StatShr::diff(
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
 class QryPlnrDvcHk1NArcguide::StgIac
 ******************************************************************************/

QryPlnrDvcHk1NArcguide::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryPlnrDvcHk1NArcguide::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryPlnrDvcHk1NArcguide");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryPlnrDvcHk1NArcguide";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryPlnrDvcHk1NArcguide::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryPlnrDvcHk1NArcguide";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryPlnrDvcHk1NArcguide";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrDvcHk1NArcguide::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrDvcHk1NArcguide::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};


