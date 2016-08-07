/**
  * \file PlnrQArrHk1NReticle.cpp
  * app access code for table TblPlnrQArrHk1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrHk1NReticle.h"

/******************************************************************************
 class PlnrQArrHk1NReticle
 ******************************************************************************/

PlnrQArrHk1NReticle::PlnrQArrHk1NReticle(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQArrHk1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQArrHk1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQArrHk1NReticle
 ******************************************************************************/

ListPlnrQArrHk1NReticle::ListPlnrQArrHk1NReticle() {
};

ListPlnrQArrHk1NReticle::ListPlnrQArrHk1NReticle(
			const ListPlnrQArrHk1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrHk1NReticle(*(src.nodes[i]));
};

ListPlnrQArrHk1NReticle& ListPlnrQArrHk1NReticle::operator=(
			const ListPlnrQArrHk1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrHk1NReticle(*(src.nodes[i]));

	return *this;
};

ListPlnrQArrHk1NReticle::~ListPlnrQArrHk1NReticle() {
	clear();
};

void ListPlnrQArrHk1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQArrHk1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQArrHk1NReticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQArrHk1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQArrHk1NReticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQArrHk1NReticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQArrHk1NReticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

