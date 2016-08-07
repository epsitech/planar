/**
  * \file PlnrQUsrList.cpp
  * app access code for table TblPlnrQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrList.h"

/******************************************************************************
 class PlnrQUsrList
 ******************************************************************************/

PlnrQUsrList::PlnrQUsrList(
			const uint jnum
			, const string stubRefPlnrMPerson
			, const string sref
			, const string stubRefPlnrMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxPlnrVLocale
			, const string titIxPlnrVLocale
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	this->jnum = jnum;
	this->stubRefPlnrMPerson = stubRefPlnrMPerson;
	this->sref = sref;
	this->stubRefPlnrMUsergroup = stubRefPlnrMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxPlnrVLocale = srefIxPlnrVLocale;
	this->titIxPlnrVLocale = titIxPlnrVLocale;
	this->srefIxPlnrVUserlevel = srefIxPlnrVUserlevel;
	this->titIxPlnrVUserlevel = titIxPlnrVUserlevel;
};

bool PlnrQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefPlnrMPerson", "prs", stubRefPlnrMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMUsergroup", "usg", stubRefPlnrMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxPlnrVLocale", "lcl", srefIxPlnrVLocale);
		extractStringUclc(docctx, basexpath, "titIxPlnrVLocale", "lcl2", titIxPlnrVLocale);
		extractStringUclc(docctx, basexpath, "srefIxPlnrVUserlevel", "ulv", srefIxPlnrVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxPlnrVUserlevel", "ulv2", titIxPlnrVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQUsrList
 ******************************************************************************/

ListPlnrQUsrList::ListPlnrQUsrList() {
};

ListPlnrQUsrList::ListPlnrQUsrList(
			const ListPlnrQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrList(*(src.nodes[i]));
};

ListPlnrQUsrList& ListPlnrQUsrList::operator=(
			const ListPlnrQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrList(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsrList::~ListPlnrQUsrList() {
	clear();
};

void ListPlnrQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

