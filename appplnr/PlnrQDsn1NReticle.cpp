/**
  * \file PlnrQDsn1NReticle.cpp
  * app access code for table TblPlnrQDsn1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsn1NReticle.h"

/******************************************************************************
 class PlnrQDsn1NReticle
 ******************************************************************************/

PlnrQDsn1NReticle::PlnrQDsn1NReticle(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsn1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsn1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsn1NReticle
 ******************************************************************************/

ListPlnrQDsn1NReticle::ListPlnrQDsn1NReticle() {
};

ListPlnrQDsn1NReticle::ListPlnrQDsn1NReticle(
			const ListPlnrQDsn1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsn1NReticle(*(src.nodes[i]));
};

ListPlnrQDsn1NReticle& ListPlnrQDsn1NReticle::operator=(
			const ListPlnrQDsn1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsn1NReticle(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsn1NReticle::~ListPlnrQDsn1NReticle() {
	clear();
};

void ListPlnrQDsn1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsn1NReticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsn1NReticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsn1NReticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsn1NReticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsn1NReticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsn1NReticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

