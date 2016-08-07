/**
  * \file PlnrQArrAEnv.cpp
  * app access code for table TblPlnrQArrAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrAEnv.h"

/******************************************************************************
 class PlnrQArrAEnv
 ******************************************************************************/

PlnrQArrAEnv::PlnrQArrAEnv(
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

bool PlnrQArrAEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQArrAEnv");
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
 class ListPlnrQArrAEnv
 ******************************************************************************/

ListPlnrQArrAEnv::ListPlnrQArrAEnv() {
};

ListPlnrQArrAEnv::ListPlnrQArrAEnv(
			const ListPlnrQArrAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrAEnv(*(src.nodes[i]));
};

ListPlnrQArrAEnv& ListPlnrQArrAEnv::operator=(
			const ListPlnrQArrAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrAEnv(*(src.nodes[i]));

	return *this;
};

ListPlnrQArrAEnv::~ListPlnrQArrAEnv() {
	clear();
};

void ListPlnrQArrAEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQArrAEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQArrAEnv* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQArrAEnv");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQArrAEnv", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQArrAEnv(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQArrAEnv[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

