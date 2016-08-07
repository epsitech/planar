/**
  * \file PlnrQDsnHk1NLayer.cpp
  * app access code for table TblPlnrQDsnHk1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLayer.h"

/******************************************************************************
 class PlnrQDsnHk1NLayer
 ******************************************************************************/

PlnrQDsnHk1NLayer::PlnrQDsnHk1NLayer(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnHk1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnHk1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnHk1NLayer
 ******************************************************************************/

ListPlnrQDsnHk1NLayer::ListPlnrQDsnHk1NLayer() {
};

ListPlnrQDsnHk1NLayer::ListPlnrQDsnHk1NLayer(
			const ListPlnrQDsnHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLayer(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLayer& ListPlnrQDsnHk1NLayer::operator=(
			const ListPlnrQDsnHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLayer(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnHk1NLayer::~ListPlnrQDsnHk1NLayer() {
	clear();
};

void ListPlnrQDsnHk1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnHk1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnHk1NLayer* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnHk1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnHk1NLayer", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnHk1NLayer(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnHk1NLayer[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

