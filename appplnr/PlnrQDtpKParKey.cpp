/**
  * \file PlnrQDtpKParKey.cpp
  * app access code for table TblPlnrQDtpKParKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpKParKey.h"

/******************************************************************************
 class PlnrQDtpKParKey
 ******************************************************************************/

PlnrQDtpKParKey::PlnrQDtpKParKey(
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

bool PlnrQDtpKParKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpKParKey");
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
 class ListPlnrQDtpKParKey
 ******************************************************************************/

ListPlnrQDtpKParKey::ListPlnrQDtpKParKey() {
};

ListPlnrQDtpKParKey::ListPlnrQDtpKParKey(
			const ListPlnrQDtpKParKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpKParKey(*(src.nodes[i]));
};

ListPlnrQDtpKParKey& ListPlnrQDtpKParKey::operator=(
			const ListPlnrQDtpKParKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpKParKey(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpKParKey::~ListPlnrQDtpKParKey() {
	clear();
};

void ListPlnrQDtpKParKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpKParKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpKParKey* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpKParKey");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpKParKey", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpKParKey(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpKParKey[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

