/**
  * \file PlnrQDsnDsn1NDomaingd.cpp
  * app access code for table TblPlnrQDsnDsn1NDomaingd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NDomaingd.h"

/******************************************************************************
 class PlnrQDsnDsn1NDomaingd
 ******************************************************************************/

PlnrQDsnDsn1NDomaingd::PlnrQDsnDsn1NDomaingd(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnDsn1NDomaingd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnDsn1NDomaingd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnDsn1NDomaingd
 ******************************************************************************/

ListPlnrQDsnDsn1NDomaingd::ListPlnrQDsnDsn1NDomaingd() {
};

ListPlnrQDsnDsn1NDomaingd::ListPlnrQDsnDsn1NDomaingd(
			const ListPlnrQDsnDsn1NDomaingd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDomaingd(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NDomaingd& ListPlnrQDsnDsn1NDomaingd::operator=(
			const ListPlnrQDsnDsn1NDomaingd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDomaingd(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnDsn1NDomaingd::~ListPlnrQDsnDsn1NDomaingd() {
	clear();
};

void ListPlnrQDsnDsn1NDomaingd::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnDsn1NDomaingd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnDsn1NDomaingd* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnDsn1NDomaingd");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnDsn1NDomaingd", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnDsn1NDomaingd(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnDsn1NDomaingd[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

