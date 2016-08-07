/**
  * \file PlnrQDsnHk1NLevel.cpp
  * app access code for table TblPlnrQDsnHk1NLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLevel.h"

/******************************************************************************
 class PlnrQDsnHk1NLevel
 ******************************************************************************/

PlnrQDsnHk1NLevel::PlnrQDsnHk1NLevel(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnHk1NLevel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnHk1NLevel
 ******************************************************************************/

ListPlnrQDsnHk1NLevel::ListPlnrQDsnHk1NLevel() {
};

ListPlnrQDsnHk1NLevel::ListPlnrQDsnHk1NLevel(
			const ListPlnrQDsnHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLevel(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLevel& ListPlnrQDsnHk1NLevel::operator=(
			const ListPlnrQDsnHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLevel(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnHk1NLevel::~ListPlnrQDsnHk1NLevel() {
	clear();
};

void ListPlnrQDsnHk1NLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnHk1NLevel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnHk1NLevel* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnHk1NLevel");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnHk1NLevel", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnHk1NLevel(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnHk1NLevel[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

