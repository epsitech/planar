/**
  * \file PlnrQClcCal1NCalcitem.cpp
  * app access code for table TblPlnrQClcCal1NCalcitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcCal1NCalcitem.h"

/******************************************************************************
 class PlnrQClcCal1NCalcitem
 ******************************************************************************/

PlnrQClcCal1NCalcitem::PlnrQClcCal1NCalcitem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQClcCal1NCalcitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcCal1NCalcitem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClcCal1NCalcitem
 ******************************************************************************/

ListPlnrQClcCal1NCalcitem::ListPlnrQClcCal1NCalcitem() {
};

ListPlnrQClcCal1NCalcitem::ListPlnrQClcCal1NCalcitem(
			const ListPlnrQClcCal1NCalcitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcCal1NCalcitem(*(src.nodes[i]));
};

ListPlnrQClcCal1NCalcitem& ListPlnrQClcCal1NCalcitem::operator=(
			const ListPlnrQClcCal1NCalcitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcCal1NCalcitem(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcCal1NCalcitem::~ListPlnrQClcCal1NCalcitem() {
	clear();
};

void ListPlnrQClcCal1NCalcitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcCal1NCalcitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcCal1NCalcitem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcCal1NCalcitem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcCal1NCalcitem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcCal1NCalcitem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcCal1NCalcitem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

