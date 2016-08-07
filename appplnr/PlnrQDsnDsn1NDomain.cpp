/**
  * \file PlnrQDsnDsn1NDomain.cpp
  * app access code for table TblPlnrQDsnDsn1NDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NDomain.h"

/******************************************************************************
 class PlnrQDsnDsn1NDomain
 ******************************************************************************/

PlnrQDsnDsn1NDomain::PlnrQDsnDsn1NDomain(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnDsn1NDomain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnDsn1NDomain");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnDsn1NDomain
 ******************************************************************************/

ListPlnrQDsnDsn1NDomain::ListPlnrQDsnDsn1NDomain() {
};

ListPlnrQDsnDsn1NDomain::ListPlnrQDsnDsn1NDomain(
			const ListPlnrQDsnDsn1NDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDomain(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NDomain& ListPlnrQDsnDsn1NDomain::operator=(
			const ListPlnrQDsnDsn1NDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDomain(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnDsn1NDomain::~ListPlnrQDsnDsn1NDomain() {
	clear();
};

void ListPlnrQDsnDsn1NDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnDsn1NDomain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnDsn1NDomain* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnDsn1NDomain");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnDsn1NDomain", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnDsn1NDomain(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnDsn1NDomain[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

