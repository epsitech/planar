/**
  * \file PlnrQDsnHk1NLineguide.cpp
  * app access code for table TblPlnrQDsnHk1NLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLineguide.h"

/******************************************************************************
 class PlnrQDsnHk1NLineguide
 ******************************************************************************/

PlnrQDsnHk1NLineguide::PlnrQDsnHk1NLineguide(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnHk1NLineguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnHk1NLineguide");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnHk1NLineguide
 ******************************************************************************/

ListPlnrQDsnHk1NLineguide::ListPlnrQDsnHk1NLineguide() {
};

ListPlnrQDsnHk1NLineguide::ListPlnrQDsnHk1NLineguide(
			const ListPlnrQDsnHk1NLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLineguide(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLineguide& ListPlnrQDsnHk1NLineguide::operator=(
			const ListPlnrQDsnHk1NLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLineguide(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnHk1NLineguide::~ListPlnrQDsnHk1NLineguide() {
	clear();
};

void ListPlnrQDsnHk1NLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnHk1NLineguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnHk1NLineguide* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnHk1NLineguide");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnHk1NLineguide", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnHk1NLineguide(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnHk1NLineguide[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

