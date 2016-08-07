/**
  * \file PlnrQPrj1NCalc.cpp
  * app access code for table TblPlnrQPrj1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrj1NCalc.h"

/******************************************************************************
 class PlnrQPrj1NCalc
 ******************************************************************************/

PlnrQPrj1NCalc::PlnrQPrj1NCalc(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQPrj1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrj1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrj1NCalc
 ******************************************************************************/

ListPlnrQPrj1NCalc::ListPlnrQPrj1NCalc() {
};

ListPlnrQPrj1NCalc::ListPlnrQPrj1NCalc(
			const ListPlnrQPrj1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrj1NCalc(*(src.nodes[i]));
};

ListPlnrQPrj1NCalc& ListPlnrQPrj1NCalc::operator=(
			const ListPlnrQPrj1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrj1NCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrj1NCalc::~ListPlnrQPrj1NCalc() {
	clear();
};

void ListPlnrQPrj1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrj1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrj1NCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrj1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrj1NCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrj1NCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrj1NCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

