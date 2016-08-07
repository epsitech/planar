/**
  * \file PlnrQCtpKParProp.cpp
  * app access code for table TblPlnrQCtpKParProp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKParProp.h"

/******************************************************************************
 class PlnrQCtpKParProp
 ******************************************************************************/

PlnrQCtpKParProp::PlnrQCtpKParProp(
			const uint jnum
			, const string sref
			, const string Avail
			, const string Title
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Avail = Avail;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrQCtpKParProp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpKParProp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Avail", "avl", Avail);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpKParProp
 ******************************************************************************/

ListPlnrQCtpKParProp::ListPlnrQCtpKParProp() {
};

ListPlnrQCtpKParProp::ListPlnrQCtpKParProp(
			const ListPlnrQCtpKParProp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKParProp(*(src.nodes[i]));
};

ListPlnrQCtpKParProp& ListPlnrQCtpKParProp::operator=(
			const ListPlnrQCtpKParProp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKParProp(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpKParProp::~ListPlnrQCtpKParProp() {
	clear();
};

void ListPlnrQCtpKParProp::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpKParProp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpKParProp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpKParProp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpKParProp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpKParProp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpKParProp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

