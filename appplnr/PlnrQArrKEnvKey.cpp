/**
  * \file PlnrQArrKEnvKey.cpp
  * app access code for table TblPlnrQArrKEnvKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrKEnvKey.h"

/******************************************************************************
 class PlnrQArrKEnvKey
 ******************************************************************************/

PlnrQArrKEnvKey::PlnrQArrKEnvKey(
			const uint jnum
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const string Title
			, const string Comment
		) {
	this->jnum = jnum;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrQArrKEnvKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "yesnoFixed", "fix", yesnoFixed);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Avail", "avl", Avail);
		extractStringUclc(docctx, basexpath, "Implied", "imp", Implied);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQArrKEnvKey
 ******************************************************************************/

ListPlnrQArrKEnvKey::ListPlnrQArrKEnvKey() {
};

ListPlnrQArrKEnvKey::ListPlnrQArrKEnvKey(
			const ListPlnrQArrKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrKEnvKey(*(src.nodes[i]));
};

ListPlnrQArrKEnvKey& ListPlnrQArrKEnvKey::operator=(
			const ListPlnrQArrKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrKEnvKey(*(src.nodes[i]));

	return *this;
};

ListPlnrQArrKEnvKey::~ListPlnrQArrKEnvKey() {
	clear();
};

void ListPlnrQArrKEnvKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQArrKEnvKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQArrKEnvKey* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQArrKEnvKey");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQArrKEnvKey", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQArrKEnvKey(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQArrKEnvKey[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

