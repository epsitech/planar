/**
  * \file PlnrQCtpTpl1NCalc.cpp
  * app access code for table TblPlnrQCtpTpl1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpTpl1NCalc.h"

/******************************************************************************
 class PlnrQCtpTpl1NCalc
 ******************************************************************************/

PlnrQCtpTpl1NCalc::PlnrQCtpTpl1NCalc(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQCtpTpl1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpTpl1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpTpl1NCalc
 ******************************************************************************/

ListPlnrQCtpTpl1NCalc::ListPlnrQCtpTpl1NCalc() {
};

ListPlnrQCtpTpl1NCalc::ListPlnrQCtpTpl1NCalc(
			const ListPlnrQCtpTpl1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpTpl1NCalc(*(src.nodes[i]));
};

ListPlnrQCtpTpl1NCalc& ListPlnrQCtpTpl1NCalc::operator=(
			const ListPlnrQCtpTpl1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpTpl1NCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpTpl1NCalc::~ListPlnrQCtpTpl1NCalc() {
	clear();
};

void ListPlnrQCtpTpl1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpTpl1NCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpTpl1NCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpTpl1NCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpTpl1NCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpTpl1NCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpTpl1NCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

