/**
  * \file PlnrQSruMNStack.cpp
  * app access code for table TblPlnrQSruMNStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruMNStack.h"

/******************************************************************************
 class PlnrQSruMNStack
 ******************************************************************************/

PlnrQSruMNStack::PlnrQSruMNStack(
			const uint jnum
			, const string stubMref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->fromSrefPlnrMLayer = fromSrefPlnrMLayer;
	this->toSrefPlnrMLayer = toSrefPlnrMLayer;
};

bool PlnrQSruMNStack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQSruMNStack");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "fromSrefPlnrMLayer", "frl", fromSrefPlnrMLayer);
		extractStringUclc(docctx, basexpath, "toSrefPlnrMLayer", "tol", toSrefPlnrMLayer);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQSruMNStack
 ******************************************************************************/

ListPlnrQSruMNStack::ListPlnrQSruMNStack() {
};

ListPlnrQSruMNStack::ListPlnrQSruMNStack(
			const ListPlnrQSruMNStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruMNStack(*(src.nodes[i]));
};

ListPlnrQSruMNStack& ListPlnrQSruMNStack::operator=(
			const ListPlnrQSruMNStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruMNStack(*(src.nodes[i]));

	return *this;
};

ListPlnrQSruMNStack::~ListPlnrQSruMNStack() {
	clear();
};

void ListPlnrQSruMNStack::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQSruMNStack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQSruMNStack* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQSruMNStack");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQSruMNStack", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQSruMNStack(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQSruMNStack[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

