/**
  * \file PlnrQLyr1NReticle.cpp
  * app access code for table TblPlnrQLyr1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyr1NReticle.h"

/******************************************************************************
 class PlnrQLyr1NReticle
 ******************************************************************************/

PlnrQLyr1NReticle::PlnrQLyr1NReticle(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQLyr1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQLyr1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQLyr1NReticle
 ******************************************************************************/

ListPlnrQLyr1NReticle::ListPlnrQLyr1NReticle() {
};

ListPlnrQLyr1NReticle::ListPlnrQLyr1NReticle(
			const ListPlnrQLyr1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NReticle(*(src.nodes[i]));
};

ListPlnrQLyr1NReticle& ListPlnrQLyr1NReticle::operator=(
			const ListPlnrQLyr1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NReticle(*(src.nodes[i]));

	return *this;
};

ListPlnrQLyr1NReticle::~ListPlnrQLyr1NReticle() {
	clear();
};

void ListPlnrQLyr1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQLyr1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQLyr1NReticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQLyr1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQLyr1NReticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQLyr1NReticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQLyr1NReticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

