/**
  * \file PlnrQMat1NLayer.cpp
  * app access code for table TblPlnrQMat1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMat1NLayer.h"

/******************************************************************************
 class PlnrQMat1NLayer
 ******************************************************************************/

PlnrQMat1NLayer::PlnrQMat1NLayer(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQMat1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQMat1NLayer
 ******************************************************************************/

ListPlnrQMat1NLayer::ListPlnrQMat1NLayer() {
};

ListPlnrQMat1NLayer::ListPlnrQMat1NLayer(
			const ListPlnrQMat1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMat1NLayer(*(src.nodes[i]));
};

ListPlnrQMat1NLayer& ListPlnrQMat1NLayer::operator=(
			const ListPlnrQMat1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMat1NLayer(*(src.nodes[i]));

	return *this;
};

ListPlnrQMat1NLayer::~ListPlnrQMat1NLayer() {
	clear();
};

void ListPlnrQMat1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQMat1NLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQMat1NLayer* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQMat1NLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQMat1NLayer", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQMat1NLayer(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQMat1NLayer[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

