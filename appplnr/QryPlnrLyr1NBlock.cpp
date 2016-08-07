/**
  * \file QryPlnrLyr1NBlock.cpp
  * app access code for job QryPlnrLyr1NBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "QryPlnrLyr1NBlock.h"

/******************************************************************************
 class QryPlnrLyr1NBlock::StatApp
 ******************************************************************************/

QryPlnrLyr1NBlock::StatApp::StatApp(
			const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) : Block() {
	this->firstcol = firstcol;
	this->jnumFirstdisp = jnumFirstdisp;
	this->ncol = ncol;
	this->ndisp = ndisp;

	mask = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
};

bool QryPlnrLyr1NBlock::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppQryPlnrLyr1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppQryPlnrLyr1NBlock";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "firstcol", firstcol)) add(FIRSTCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", jnumFirstdisp)) add(JNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ncol", ncol)) add(NCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ndisp", ndisp)) add(NDISP);
	};

	return basefound;
};

set<uint> QryPlnrLyr1NBlock::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (firstcol == comp->firstcol) insert(items, FIRSTCOL);
	if (jnumFirstdisp == comp->jnumFirstdisp) insert(items, JNUMFIRSTDISP);
	if (ncol == comp->ncol) insert(items, NCOL);
	if (ndisp == comp->ndisp) insert(items, NDISP);

	return(items);
};

set<uint> QryPlnrLyr1NBlock::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryPlnrLyr1NBlock::StatShr
 ******************************************************************************/

QryPlnrLyr1NBlock::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

bool QryPlnrLyr1NBlock::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryPlnrLyr1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryPlnrLyr1NBlock";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

set<uint> QryPlnrLyr1NBlock::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrLyr1NBlock::StatShr::diff(
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
 class QryPlnrLyr1NBlock::StgIac
 ******************************************************************************/

QryPlnrLyr1NBlock::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) : Block() {
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryPlnrLyr1NBlock::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryPlnrLyr1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryPlnrLyr1NBlock";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryPlnrLyr1NBlock::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryPlnrLyr1NBlock";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryPlnrLyr1NBlock";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryPlnrLyr1NBlock::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryPlnrLyr1NBlock::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

