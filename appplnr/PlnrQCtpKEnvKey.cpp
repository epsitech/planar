/**
  * \file PlnrQCtpKEnvKey.cpp
  * app access code for table TblPlnrQCtpKEnvKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKEnvKey.h"

/******************************************************************************
 class PlnrQCtpKEnvKey
 ******************************************************************************/

PlnrQCtpKEnvKey::PlnrQCtpKEnvKey(
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

bool PlnrQCtpKEnvKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpKEnvKey");
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
 class ListPlnrQCtpKEnvKey
 ******************************************************************************/

ListPlnrQCtpKEnvKey::ListPlnrQCtpKEnvKey() {
};

ListPlnrQCtpKEnvKey::ListPlnrQCtpKEnvKey(
			const ListPlnrQCtpKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKEnvKey(*(src.nodes[i]));
};

ListPlnrQCtpKEnvKey& ListPlnrQCtpKEnvKey::operator=(
			const ListPlnrQCtpKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKEnvKey(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpKEnvKey::~ListPlnrQCtpKEnvKey() {
	clear();
};

void ListPlnrQCtpKEnvKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpKEnvKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpKEnvKey* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpKEnvKey", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpKEnvKey(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpKEnvKey[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

