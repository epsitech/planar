/**
  * \file PlnrQDsnHk1NStructure.cpp
  * app access code for table TblPlnrQDsnHk1NStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NStructure.h"

/******************************************************************************
 class PlnrQDsnHk1NStructure
 ******************************************************************************/

PlnrQDsnHk1NStructure::PlnrQDsnHk1NStructure(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnHk1NStructure
 ******************************************************************************/

ListPlnrQDsnHk1NStructure::ListPlnrQDsnHk1NStructure() {
};

ListPlnrQDsnHk1NStructure::ListPlnrQDsnHk1NStructure(
			const ListPlnrQDsnHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NStructure(*(src.nodes[i]));
};

ListPlnrQDsnHk1NStructure& ListPlnrQDsnHk1NStructure::operator=(
			const ListPlnrQDsnHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NStructure(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnHk1NStructure::~ListPlnrQDsnHk1NStructure() {
	clear();
};

void ListPlnrQDsnHk1NStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnHk1NStructure* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnHk1NStructure", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnHk1NStructure(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnHk1NStructure[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

