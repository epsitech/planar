/**
  * \file PlnrQDvcHk1NLineguide.cpp
  * app access code for table TblPlnrQDvcHk1NLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NLineguide.h"

/******************************************************************************
 class PlnrQDvcHk1NLineguide
 ******************************************************************************/

PlnrQDvcHk1NLineguide::PlnrQDvcHk1NLineguide(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDvcHk1NLineguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcHk1NLineguide");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcHk1NLineguide
 ******************************************************************************/

ListPlnrQDvcHk1NLineguide::ListPlnrQDvcHk1NLineguide() {
};

ListPlnrQDvcHk1NLineguide::ListPlnrQDvcHk1NLineguide(
			const ListPlnrQDvcHk1NLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NLineguide(*(src.nodes[i]));
};

ListPlnrQDvcHk1NLineguide& ListPlnrQDvcHk1NLineguide::operator=(
			const ListPlnrQDvcHk1NLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NLineguide(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcHk1NLineguide::~ListPlnrQDvcHk1NLineguide() {
	clear();
};

void ListPlnrQDvcHk1NLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcHk1NLineguide::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcHk1NLineguide* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcHk1NLineguide");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcHk1NLineguide", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcHk1NLineguide(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcHk1NLineguide[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

