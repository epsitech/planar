/**
  * \file PlnrQCtpKParCat.cpp
  * app access code for table TblPlnrQCtpKParCat (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKParCat.h"

/******************************************************************************
 class PlnrQCtpKParCat
 ******************************************************************************/

PlnrQCtpKParCat::PlnrQCtpKParCat(
			const uint jnum
			, const string sref
			, const string Title
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrQCtpKParCat::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpKParCat");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpKParCat
 ******************************************************************************/

ListPlnrQCtpKParCat::ListPlnrQCtpKParCat() {
};

ListPlnrQCtpKParCat::ListPlnrQCtpKParCat(
			const ListPlnrQCtpKParCat& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKParCat(*(src.nodes[i]));
};

ListPlnrQCtpKParCat& ListPlnrQCtpKParCat::operator=(
			const ListPlnrQCtpKParCat& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKParCat(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpKParCat::~ListPlnrQCtpKParCat() {
	clear();
};

void ListPlnrQCtpKParCat::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpKParCat::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpKParCat* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpKParCat");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpKParCat", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpKParCat(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpKParCat[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

