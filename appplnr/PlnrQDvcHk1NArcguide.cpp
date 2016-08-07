/**
  * \file PlnrQDvcHk1NArcguide.cpp
  * app access code for table TblPlnrQDvcHk1NArcguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NArcguide.h"

/******************************************************************************
 class PlnrQDvcHk1NArcguide
 ******************************************************************************/

PlnrQDvcHk1NArcguide::PlnrQDvcHk1NArcguide(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDvcHk1NArcguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcHk1NArcguide");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcHk1NArcguide
 ******************************************************************************/

ListPlnrQDvcHk1NArcguide::ListPlnrQDvcHk1NArcguide() {
};

ListPlnrQDvcHk1NArcguide::ListPlnrQDvcHk1NArcguide(
			const ListPlnrQDvcHk1NArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NArcguide(*(src.nodes[i]));
};

ListPlnrQDvcHk1NArcguide& ListPlnrQDvcHk1NArcguide::operator=(
			const ListPlnrQDvcHk1NArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NArcguide(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcHk1NArcguide::~ListPlnrQDvcHk1NArcguide() {
	clear();
};

void ListPlnrQDvcHk1NArcguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcHk1NArcguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcHk1NArcguide* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcHk1NArcguide");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcHk1NArcguide", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcHk1NArcguide(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcHk1NArcguide[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

