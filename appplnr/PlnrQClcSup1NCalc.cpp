/**
  * \file PlnrQClcSup1NCalc.cpp
  * app access code for table TblPlnrQClcSup1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcSup1NCalc.h"

/******************************************************************************
 class PlnrQClcSup1NCalc
 ******************************************************************************/

PlnrQClcSup1NCalc::PlnrQClcSup1NCalc(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQClcSup1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcSup1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClcSup1NCalc
 ******************************************************************************/

ListPlnrQClcSup1NCalc::ListPlnrQClcSup1NCalc() {
};

ListPlnrQClcSup1NCalc::ListPlnrQClcSup1NCalc(
			const ListPlnrQClcSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcSup1NCalc(*(src.nodes[i]));
};

ListPlnrQClcSup1NCalc& ListPlnrQClcSup1NCalc::operator=(
			const ListPlnrQClcSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcSup1NCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcSup1NCalc::~ListPlnrQClcSup1NCalc() {
	clear();
};

void ListPlnrQClcSup1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcSup1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcSup1NCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcSup1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcSup1NCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcSup1NCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcSup1NCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

