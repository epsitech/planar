/**
  * \file PlnrQSruMNLayer.cpp
  * app access code for table TblPlnrQSruMNLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruMNLayer.h"

/******************************************************************************
 class PlnrQSruMNLayer
 ******************************************************************************/

PlnrQSruMNLayer::PlnrQSruMNLayer(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool PlnrQSruMNLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQSruMNLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQSruMNLayer
 ******************************************************************************/

ListPlnrQSruMNLayer::ListPlnrQSruMNLayer() {
};

ListPlnrQSruMNLayer::ListPlnrQSruMNLayer(
			const ListPlnrQSruMNLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruMNLayer(*(src.nodes[i]));
};

ListPlnrQSruMNLayer& ListPlnrQSruMNLayer::operator=(
			const ListPlnrQSruMNLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruMNLayer(*(src.nodes[i]));

	return *this;
};

ListPlnrQSruMNLayer::~ListPlnrQSruMNLayer() {
	clear();
};

void ListPlnrQSruMNLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQSruMNLayer::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQSruMNLayer* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQSruMNLayer");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQSruMNLayer", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQSruMNLayer(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQSruMNLayer[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

