/**
  * \file PlnrQDtpHk1NStructure.cpp
  * app access code for table TblPlnrQDtpHk1NStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpHk1NStructure.h"

/******************************************************************************
 class PlnrQDtpHk1NStructure
 ******************************************************************************/

PlnrQDtpHk1NStructure::PlnrQDtpHk1NStructure(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDtpHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDtpHk1NStructure
 ******************************************************************************/

ListPlnrQDtpHk1NStructure::ListPlnrQDtpHk1NStructure() {
};

ListPlnrQDtpHk1NStructure::ListPlnrQDtpHk1NStructure(
			const ListPlnrQDtpHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpHk1NStructure(*(src.nodes[i]));
};

ListPlnrQDtpHk1NStructure& ListPlnrQDtpHk1NStructure::operator=(
			const ListPlnrQDtpHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpHk1NStructure(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpHk1NStructure::~ListPlnrQDtpHk1NStructure() {
	clear();
};

void ListPlnrQDtpHk1NStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpHk1NStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpHk1NStructure* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpHk1NStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpHk1NStructure", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpHk1NStructure(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpHk1NStructure[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

