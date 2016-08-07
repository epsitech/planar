/**
  * \file PlnrQCliList.cpp
  * app access code for table TblPlnrQCliList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliList.h"

/******************************************************************************
 class PlnrQCliList
 ******************************************************************************/

PlnrQCliList::PlnrQCliList(
			const uint jnum
			, const string Title
			, const string stubCalRefPlnrMCalc
			, const string stubRefPlnrMDesign
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubCalRefPlnrMCalc = stubCalRefPlnrMCalc;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
};

bool PlnrQCliList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCliList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubCalRefPlnrMCalc", "cal", stubCalRefPlnrMCalc);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMDesign", "dsn", stubRefPlnrMDesign);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCliList
 ******************************************************************************/

ListPlnrQCliList::ListPlnrQCliList() {
};

ListPlnrQCliList::ListPlnrQCliList(
			const ListPlnrQCliList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliList(*(src.nodes[i]));
};

ListPlnrQCliList& ListPlnrQCliList::operator=(
			const ListPlnrQCliList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliList(*(src.nodes[i]));

	return *this;
};

ListPlnrQCliList::~ListPlnrQCliList() {
	clear();
};

void ListPlnrQCliList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCliList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCliList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCliList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCliList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCliList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCliList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

