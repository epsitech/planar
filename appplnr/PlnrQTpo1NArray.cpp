/**
  * \file PlnrQTpo1NArray.cpp
  * app access code for table TblPlnrQTpo1NArray (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpo1NArray.h"

/******************************************************************************
 class PlnrQTpo1NArray
 ******************************************************************************/

PlnrQTpo1NArray::PlnrQTpo1NArray(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQTpo1NArray::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQTpo1NArray");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQTpo1NArray
 ******************************************************************************/

ListPlnrQTpo1NArray::ListPlnrQTpo1NArray() {
};

ListPlnrQTpo1NArray::ListPlnrQTpo1NArray(
			const ListPlnrQTpo1NArray& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpo1NArray(*(src.nodes[i]));
};

ListPlnrQTpo1NArray& ListPlnrQTpo1NArray::operator=(
			const ListPlnrQTpo1NArray& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpo1NArray(*(src.nodes[i]));

	return *this;
};

ListPlnrQTpo1NArray::~ListPlnrQTpo1NArray() {
	clear();
};

void ListPlnrQTpo1NArray::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQTpo1NArray::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQTpo1NArray* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQTpo1NArray");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQTpo1NArray", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQTpo1NArray(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQTpo1NArray[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

