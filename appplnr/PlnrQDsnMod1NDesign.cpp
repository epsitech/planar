/**
  * \file PlnrQDsnMod1NDesign.cpp
  * app access code for table TblPlnrQDsnMod1NDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnMod1NDesign.h"

/******************************************************************************
 class PlnrQDsnMod1NDesign
 ******************************************************************************/

PlnrQDsnMod1NDesign::PlnrQDsnMod1NDesign(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnMod1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnMod1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnMod1NDesign
 ******************************************************************************/

ListPlnrQDsnMod1NDesign::ListPlnrQDsnMod1NDesign() {
};

ListPlnrQDsnMod1NDesign::ListPlnrQDsnMod1NDesign(
			const ListPlnrQDsnMod1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnMod1NDesign(*(src.nodes[i]));
};

ListPlnrQDsnMod1NDesign& ListPlnrQDsnMod1NDesign::operator=(
			const ListPlnrQDsnMod1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnMod1NDesign(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnMod1NDesign::~ListPlnrQDsnMod1NDesign() {
	clear();
};

void ListPlnrQDsnMod1NDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnMod1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnMod1NDesign* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnMod1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnMod1NDesign", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnMod1NDesign(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnMod1NDesign[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

