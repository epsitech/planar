/**
  * \file PlnrQDvcHk1NVertex.cpp
  * app access code for table TblPlnrQDvcHk1NVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NVertex.h"

/******************************************************************************
 class PlnrQDvcHk1NVertex
 ******************************************************************************/

PlnrQDvcHk1NVertex::PlnrQDvcHk1NVertex(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDvcHk1NVertex::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcHk1NVertex");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcHk1NVertex
 ******************************************************************************/

ListPlnrQDvcHk1NVertex::ListPlnrQDvcHk1NVertex() {
};

ListPlnrQDvcHk1NVertex::ListPlnrQDvcHk1NVertex(
			const ListPlnrQDvcHk1NVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NVertex(*(src.nodes[i]));
};

ListPlnrQDvcHk1NVertex& ListPlnrQDvcHk1NVertex::operator=(
			const ListPlnrQDvcHk1NVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NVertex(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcHk1NVertex::~ListPlnrQDvcHk1NVertex() {
	clear();
};

void ListPlnrQDvcHk1NVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcHk1NVertex::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcHk1NVertex* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcHk1NVertex");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcHk1NVertex", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcHk1NVertex(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcHk1NVertex[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

