/**
  * \file PlnrQArr1NArrayitem.cpp
  * app access code for table TblPlnrQArr1NArrayitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArr1NArrayitem.h"

/******************************************************************************
 class PlnrQArr1NArrayitem
 ******************************************************************************/

PlnrQArr1NArrayitem::PlnrQArr1NArrayitem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQArr1NArrayitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQArr1NArrayitem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQArr1NArrayitem
 ******************************************************************************/

ListPlnrQArr1NArrayitem::ListPlnrQArr1NArrayitem() {
};

ListPlnrQArr1NArrayitem::ListPlnrQArr1NArrayitem(
			const ListPlnrQArr1NArrayitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArr1NArrayitem(*(src.nodes[i]));
};

ListPlnrQArr1NArrayitem& ListPlnrQArr1NArrayitem::operator=(
			const ListPlnrQArr1NArrayitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArr1NArrayitem(*(src.nodes[i]));

	return *this;
};

ListPlnrQArr1NArrayitem::~ListPlnrQArr1NArrayitem() {
	clear();
};

void ListPlnrQArr1NArrayitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQArr1NArrayitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQArr1NArrayitem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQArr1NArrayitem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQArr1NArrayitem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQArr1NArrayitem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQArr1NArrayitem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

