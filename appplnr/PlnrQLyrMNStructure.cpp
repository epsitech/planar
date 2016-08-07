/**
  * \file PlnrQLyrMNStructure.cpp
  * app access code for table TblPlnrQLyrMNStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyrMNStructure.h"

/******************************************************************************
 class PlnrQLyrMNStructure
 ******************************************************************************/

PlnrQLyrMNStructure::PlnrQLyrMNStructure(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool PlnrQLyrMNStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQLyrMNStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQLyrMNStructure
 ******************************************************************************/

ListPlnrQLyrMNStructure::ListPlnrQLyrMNStructure() {
};

ListPlnrQLyrMNStructure::ListPlnrQLyrMNStructure(
			const ListPlnrQLyrMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrMNStructure(*(src.nodes[i]));
};

ListPlnrQLyrMNStructure& ListPlnrQLyrMNStructure::operator=(
			const ListPlnrQLyrMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrMNStructure(*(src.nodes[i]));

	return *this;
};

ListPlnrQLyrMNStructure::~ListPlnrQLyrMNStructure() {
	clear();
};

void ListPlnrQLyrMNStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQLyrMNStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQLyrMNStructure* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQLyrMNStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQLyrMNStructure", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQLyrMNStructure(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQLyrMNStructure[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

