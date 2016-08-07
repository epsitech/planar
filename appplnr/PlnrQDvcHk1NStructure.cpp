/**
  * \file PlnrQDvcHk1NStructure.cpp
  * app access code for table TblPlnrQDvcHk1NStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NStructure.h"

/******************************************************************************
 class PlnrQDvcHk1NStructure
 ******************************************************************************/

PlnrQDvcHk1NStructure::PlnrQDvcHk1NStructure(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDvcHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcHk1NStructure
 ******************************************************************************/

ListPlnrQDvcHk1NStructure::ListPlnrQDvcHk1NStructure() {
};

ListPlnrQDvcHk1NStructure::ListPlnrQDvcHk1NStructure(
			const ListPlnrQDvcHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NStructure(*(src.nodes[i]));
};

ListPlnrQDvcHk1NStructure& ListPlnrQDvcHk1NStructure::operator=(
			const ListPlnrQDvcHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NStructure(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcHk1NStructure::~ListPlnrQDvcHk1NStructure() {
	clear();
};

void ListPlnrQDvcHk1NStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcHk1NStructure* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcHk1NStructure", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcHk1NStructure(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcHk1NStructure[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

