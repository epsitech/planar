/**
  * \file PlnrQTpoHk1NReticle.cpp
  * app access code for table TblPlnrQTpoHk1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoHk1NReticle.h"

/******************************************************************************
 class PlnrQTpoHk1NReticle
 ******************************************************************************/

PlnrQTpoHk1NReticle::PlnrQTpoHk1NReticle(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQTpoHk1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQTpoHk1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQTpoHk1NReticle
 ******************************************************************************/

ListPlnrQTpoHk1NReticle::ListPlnrQTpoHk1NReticle() {
};

ListPlnrQTpoHk1NReticle::ListPlnrQTpoHk1NReticle(
			const ListPlnrQTpoHk1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoHk1NReticle(*(src.nodes[i]));
};

ListPlnrQTpoHk1NReticle& ListPlnrQTpoHk1NReticle::operator=(
			const ListPlnrQTpoHk1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoHk1NReticle(*(src.nodes[i]));

	return *this;
};

ListPlnrQTpoHk1NReticle::~ListPlnrQTpoHk1NReticle() {
	clear();
};

void ListPlnrQTpoHk1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQTpoHk1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQTpoHk1NReticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQTpoHk1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQTpoHk1NReticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQTpoHk1NReticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQTpoHk1NReticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

