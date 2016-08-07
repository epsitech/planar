/**
  * \file PlnrQSruList.cpp
  * app access code for table TblPlnrQSruList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruList.h"

/******************************************************************************
 class PlnrQSruList
 ******************************************************************************/

PlnrQSruList::PlnrQSruList(
			const uint jnum
			, const string sref
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
};

bool PlnrQSruList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQSruList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQSruList
 ******************************************************************************/

ListPlnrQSruList::ListPlnrQSruList() {
};

ListPlnrQSruList::ListPlnrQSruList(
			const ListPlnrQSruList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruList(*(src.nodes[i]));
};

ListPlnrQSruList& ListPlnrQSruList::operator=(
			const ListPlnrQSruList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruList(*(src.nodes[i]));

	return *this;
};

ListPlnrQSruList::~ListPlnrQSruList() {
	clear();
};

void ListPlnrQSruList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQSruList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQSruList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQSruList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQSruList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQSruList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQSruList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

