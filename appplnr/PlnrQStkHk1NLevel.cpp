/**
  * \file PlnrQStkHk1NLevel.cpp
  * app access code for table TblPlnrQStkHk1NLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkHk1NLevel.h"

/******************************************************************************
 class PlnrQStkHk1NLevel
 ******************************************************************************/

PlnrQStkHk1NLevel::PlnrQStkHk1NLevel(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQStkHk1NLevel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQStkHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQStkHk1NLevel
 ******************************************************************************/

ListPlnrQStkHk1NLevel::ListPlnrQStkHk1NLevel() {
};

ListPlnrQStkHk1NLevel::ListPlnrQStkHk1NLevel(
			const ListPlnrQStkHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLevel(*(src.nodes[i]));
};

ListPlnrQStkHk1NLevel& ListPlnrQStkHk1NLevel::operator=(
			const ListPlnrQStkHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLevel(*(src.nodes[i]));

	return *this;
};

ListPlnrQStkHk1NLevel::~ListPlnrQStkHk1NLevel() {
	clear();
};

void ListPlnrQStkHk1NLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQStkHk1NLevel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQStkHk1NLevel* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQStkHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQStkHk1NLevel", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQStkHk1NLevel(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQStkHk1NLevel[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

