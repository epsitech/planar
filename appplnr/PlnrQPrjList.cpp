/**
  * \file PlnrQPrjList.cpp
  * app access code for table TblPlnrQPrjList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrjList.h"

/******************************************************************************
 class PlnrQPrjList
 ******************************************************************************/

PlnrQPrjList::PlnrQPrjList(
			const uint jnum
			, const string Title
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool PlnrQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrjList
 ******************************************************************************/

ListPlnrQPrjList::ListPlnrQPrjList() {
};

ListPlnrQPrjList::ListPlnrQPrjList(
			const ListPlnrQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrjList(*(src.nodes[i]));
};

ListPlnrQPrjList& ListPlnrQPrjList::operator=(
			const ListPlnrQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrjList(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrjList::~ListPlnrQPrjList() {
	clear();
};

void ListPlnrQPrjList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

