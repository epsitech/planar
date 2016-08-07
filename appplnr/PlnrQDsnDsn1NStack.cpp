/**
  * \file PlnrQDsnDsn1NStack.cpp
  * app access code for table TblPlnrQDsnDsn1NStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NStack.h"

/******************************************************************************
 class PlnrQDsnDsn1NStack
 ******************************************************************************/

PlnrQDsnDsn1NStack::PlnrQDsnDsn1NStack(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnDsn1NStack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnDsn1NStack");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnDsn1NStack
 ******************************************************************************/

ListPlnrQDsnDsn1NStack::ListPlnrQDsnDsn1NStack() {
};

ListPlnrQDsnDsn1NStack::ListPlnrQDsnDsn1NStack(
			const ListPlnrQDsnDsn1NStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NStack(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NStack& ListPlnrQDsnDsn1NStack::operator=(
			const ListPlnrQDsnDsn1NStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NStack(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnDsn1NStack::~ListPlnrQDsnDsn1NStack() {
	clear();
};

void ListPlnrQDsnDsn1NStack::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnDsn1NStack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnDsn1NStack* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnDsn1NStack");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnDsn1NStack", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnDsn1NStack(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnDsn1NStack[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

