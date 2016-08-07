/**
  * \file PlnrQTpoList.cpp
  * app access code for table TblPlnrQTpoList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoList.h"

/******************************************************************************
 class PlnrQTpoList
 ******************************************************************************/

PlnrQTpoList::PlnrQTpoList(
			const uint jnum
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const usmallint Major
			, const usmallint Sub
			, const string srefIxVState
			, const string titIxVState
			, const string yesnoHflip
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->Major = Major;
	this->Sub = Sub;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->yesnoHflip = yesnoHflip;
};

bool PlnrQTpoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQTpoList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major);
		extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "yesnoHflip", "fli", yesnoHflip);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQTpoList
 ******************************************************************************/

ListPlnrQTpoList::ListPlnrQTpoList() {
};

ListPlnrQTpoList::ListPlnrQTpoList(
			const ListPlnrQTpoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoList(*(src.nodes[i]));
};

ListPlnrQTpoList& ListPlnrQTpoList::operator=(
			const ListPlnrQTpoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoList(*(src.nodes[i]));

	return *this;
};

ListPlnrQTpoList::~ListPlnrQTpoList() {
	clear();
};

void ListPlnrQTpoList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQTpoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQTpoList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQTpoList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQTpoList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQTpoList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQTpoList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

