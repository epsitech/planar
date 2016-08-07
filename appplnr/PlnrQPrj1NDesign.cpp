/**
  * \file PlnrQPrj1NDesign.cpp
  * app access code for table TblPlnrQPrj1NDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrj1NDesign.h"

/******************************************************************************
 class PlnrQPrj1NDesign
 ******************************************************************************/

PlnrQPrj1NDesign::PlnrQPrj1NDesign(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQPrj1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrj1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrj1NDesign
 ******************************************************************************/

ListPlnrQPrj1NDesign::ListPlnrQPrj1NDesign() {
};

ListPlnrQPrj1NDesign::ListPlnrQPrj1NDesign(
			const ListPlnrQPrj1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrj1NDesign(*(src.nodes[i]));
};

ListPlnrQPrj1NDesign& ListPlnrQPrj1NDesign::operator=(
			const ListPlnrQPrj1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrj1NDesign(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrj1NDesign::~ListPlnrQPrj1NDesign() {
	clear();
};

void ListPlnrQPrj1NDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrj1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrj1NDesign* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrj1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrj1NDesign", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrj1NDesign(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrj1NDesign[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

