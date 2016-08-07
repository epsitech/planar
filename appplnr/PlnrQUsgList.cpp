/**
  * \file PlnrQUsgList.cpp
  * app access code for table TblPlnrQUsgList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsgList.h"

/******************************************************************************
 class PlnrQUsgList
 ******************************************************************************/

PlnrQUsgList::PlnrQUsgList(
			const uint jnum
			, const string sref
		) {
	this->jnum = jnum;
	this->sref = sref;
};

bool PlnrQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQUsgList
 ******************************************************************************/

ListPlnrQUsgList::ListPlnrQUsgList() {
};

ListPlnrQUsgList::ListPlnrQUsgList(
			const ListPlnrQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgList(*(src.nodes[i]));
};

ListPlnrQUsgList& ListPlnrQUsgList::operator=(
			const ListPlnrQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgList(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsgList::~ListPlnrQUsgList() {
	clear();
};

void ListPlnrQUsgList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

