/**
  * \file PlnrQCtpSup1NCalc.cpp
  * app access code for table TblPlnrQCtpSup1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpSup1NCalc.h"

/******************************************************************************
 class PlnrQCtpSup1NCalc
 ******************************************************************************/

PlnrQCtpSup1NCalc::PlnrQCtpSup1NCalc(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQCtpSup1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpSup1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpSup1NCalc
 ******************************************************************************/

ListPlnrQCtpSup1NCalc::ListPlnrQCtpSup1NCalc() {
};

ListPlnrQCtpSup1NCalc::ListPlnrQCtpSup1NCalc(
			const ListPlnrQCtpSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpSup1NCalc(*(src.nodes[i]));
};

ListPlnrQCtpSup1NCalc& ListPlnrQCtpSup1NCalc::operator=(
			const ListPlnrQCtpSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpSup1NCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpSup1NCalc::~ListPlnrQCtpSup1NCalc() {
	clear();
};

void ListPlnrQCtpSup1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpSup1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpSup1NCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpSup1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpSup1NCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpSup1NCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpSup1NCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

