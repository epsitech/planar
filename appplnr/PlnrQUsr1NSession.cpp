/**
  * \file PlnrQUsr1NSession.cpp
  * app access code for table TblPlnrQUsr1NSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsr1NSession.h"

/******************************************************************************
 class PlnrQUsr1NSession
 ******************************************************************************/

PlnrQUsr1NSession::PlnrQUsr1NSession(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQUsr1NSession::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsr1NSession");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQUsr1NSession
 ******************************************************************************/

ListPlnrQUsr1NSession::ListPlnrQUsr1NSession() {
};

ListPlnrQUsr1NSession::ListPlnrQUsr1NSession(
			const ListPlnrQUsr1NSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsr1NSession(*(src.nodes[i]));
};

ListPlnrQUsr1NSession& ListPlnrQUsr1NSession::operator=(
			const ListPlnrQUsr1NSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsr1NSession(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsr1NSession::~ListPlnrQUsr1NSession() {
	clear();
};

void ListPlnrQUsr1NSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsr1NSession::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsr1NSession* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsr1NSession");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsr1NSession", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsr1NSession(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsr1NSession[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

