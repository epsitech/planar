/**
  * \file PlnrQCtpAEnv.cpp
  * app access code for table TblPlnrQCtpAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpAEnv.h"

/******************************************************************************
 class PlnrQCtpAEnv
 ******************************************************************************/

PlnrQCtpAEnv::PlnrQCtpAEnv(
			const uint jnum
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	this->jnum = jnum;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->Val = Val;
};

bool PlnrQCtpAEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpAEnv");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x2SrefKKey", "key", x2SrefKKey);
		extractStringUclc(docctx, basexpath, "titX2SrefKKey", "key2", titX2SrefKKey);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpAEnv
 ******************************************************************************/

ListPlnrQCtpAEnv::ListPlnrQCtpAEnv() {
};

ListPlnrQCtpAEnv::ListPlnrQCtpAEnv(
			const ListPlnrQCtpAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAEnv(*(src.nodes[i]));
};

ListPlnrQCtpAEnv& ListPlnrQCtpAEnv::operator=(
			const ListPlnrQCtpAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAEnv(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpAEnv::~ListPlnrQCtpAEnv() {
	clear();
};

void ListPlnrQCtpAEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpAEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpAEnv* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpAEnv");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpAEnv", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpAEnv(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpAEnv[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

