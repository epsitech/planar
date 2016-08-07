/**
  * \file PlnrQDsnHk1NArcguide.cpp
  * app access code for table TblPlnrQDsnHk1NArcguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NArcguide.h"

/******************************************************************************
 class PlnrQDsnHk1NArcguide
 ******************************************************************************/

PlnrQDsnHk1NArcguide::PlnrQDsnHk1NArcguide(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnHk1NArcguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnHk1NArcguide");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnHk1NArcguide
 ******************************************************************************/

ListPlnrQDsnHk1NArcguide::ListPlnrQDsnHk1NArcguide() {
};

ListPlnrQDsnHk1NArcguide::ListPlnrQDsnHk1NArcguide(
			const ListPlnrQDsnHk1NArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NArcguide(*(src.nodes[i]));
};

ListPlnrQDsnHk1NArcguide& ListPlnrQDsnHk1NArcguide::operator=(
			const ListPlnrQDsnHk1NArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NArcguide(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnHk1NArcguide::~ListPlnrQDsnHk1NArcguide() {
	clear();
};

void ListPlnrQDsnHk1NArcguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnHk1NArcguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnHk1NArcguide* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnHk1NArcguide");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnHk1NArcguide", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnHk1NArcguide(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnHk1NArcguide[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

