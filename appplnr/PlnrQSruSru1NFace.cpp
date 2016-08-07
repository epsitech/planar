/**
  * \file PlnrQSruSru1NFace.cpp
  * app access code for table TblPlnrQSruSru1NFace (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruSru1NFace.h"

/******************************************************************************
 class PlnrQSruSru1NFace
 ******************************************************************************/

PlnrQSruSru1NFace::PlnrQSruSru1NFace(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQSruSru1NFace::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQSruSru1NFace");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQSruSru1NFace
 ******************************************************************************/

ListPlnrQSruSru1NFace::ListPlnrQSruSru1NFace() {
};

ListPlnrQSruSru1NFace::ListPlnrQSruSru1NFace(
			const ListPlnrQSruSru1NFace& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruSru1NFace(*(src.nodes[i]));
};

ListPlnrQSruSru1NFace& ListPlnrQSruSru1NFace::operator=(
			const ListPlnrQSruSru1NFace& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruSru1NFace(*(src.nodes[i]));

	return *this;
};

ListPlnrQSruSru1NFace::~ListPlnrQSruSru1NFace() {
	clear();
};

void ListPlnrQSruSru1NFace::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQSruSru1NFace::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQSruSru1NFace* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQSruSru1NFace");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQSruSru1NFace", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQSruSru1NFace(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQSruSru1NFace[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

