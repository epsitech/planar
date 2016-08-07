/**
  * \file PlnrQStkHk1NLayer.cpp
  * app access code for table TblPlnrQStkHk1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkHk1NLayer.h"

/******************************************************************************
 class PlnrQStkHk1NLayer
 ******************************************************************************/

PlnrQStkHk1NLayer::PlnrQStkHk1NLayer(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQStkHk1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQStkHk1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQStkHk1NLayer
 ******************************************************************************/

ListPlnrQStkHk1NLayer::ListPlnrQStkHk1NLayer() {
};

ListPlnrQStkHk1NLayer::ListPlnrQStkHk1NLayer(
			const ListPlnrQStkHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLayer(*(src.nodes[i]));
};

ListPlnrQStkHk1NLayer& ListPlnrQStkHk1NLayer::operator=(
			const ListPlnrQStkHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLayer(*(src.nodes[i]));

	return *this;
};

ListPlnrQStkHk1NLayer::~ListPlnrQStkHk1NLayer() {
	clear();
};

void ListPlnrQStkHk1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQStkHk1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQStkHk1NLayer* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQStkHk1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQStkHk1NLayer", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQStkHk1NLayer(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQStkHk1NLayer[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

