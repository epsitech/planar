/**
  * \file PlnrQAriList.cpp
  * app access code for table TblPlnrQAriList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQAriList.h"

/******************************************************************************
 class PlnrQAriList
 ******************************************************************************/

PlnrQAriList::PlnrQAriList(
			const uint jnum
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const string stubRefPlnrMArray
			, const string stubRefPlnrMDesign
			, const double dx
			, const double dy
		) {
	this->jnum = jnum;
	this->i = i;
	this->j = j;
	this->k = k;
	this->l = l;
	this->m = m;
	this->n = n;
	this->stubRefPlnrMArray = stubRefPlnrMArray;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->dx = dx;
	this->dy = dy;
};

bool PlnrQAriList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractUsmallintUclc(docctx, basexpath, "i", "i", i);
		extractUsmallintUclc(docctx, basexpath, "j", "j", j);
		extractUsmallintUclc(docctx, basexpath, "k", "k", k);
		extractUsmallintUclc(docctx, basexpath, "l", "l", l);
		extractUsmallintUclc(docctx, basexpath, "m", "m", m);
		extractUsmallintUclc(docctx, basexpath, "n", "n", n);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMArray", "arr", stubRefPlnrMArray);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMDesign", "dsn", stubRefPlnrMDesign);
		extractDoubleUclc(docctx, basexpath, "dx", "dx", dx);
		extractDoubleUclc(docctx, basexpath, "dy", "dy", dy);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQAriList
 ******************************************************************************/

ListPlnrQAriList::ListPlnrQAriList() {
};

ListPlnrQAriList::ListPlnrQAriList(
			const ListPlnrQAriList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriList(*(src.nodes[i]));
};

ListPlnrQAriList& ListPlnrQAriList::operator=(
			const ListPlnrQAriList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriList(*(src.nodes[i]));

	return *this;
};

ListPlnrQAriList::~ListPlnrQAriList() {
	clear();
};

void ListPlnrQAriList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQAriList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQAriList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQAriList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQAriList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQAriList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQAriList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

