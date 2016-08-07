/**
  * \file PlnrQAriAMArrayEnv.cpp
  * app access code for table TblPlnrQAriAMArrayEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQAriAMArrayEnv.h"

/******************************************************************************
 class PlnrQAriAMArrayEnv
 ******************************************************************************/

PlnrQAriAMArrayEnv::PlnrQAriAMArrayEnv(
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

bool PlnrQAriAMArrayEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQAriAMArrayEnv");
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
 class ListPlnrQAriAMArrayEnv
 ******************************************************************************/

ListPlnrQAriAMArrayEnv::ListPlnrQAriAMArrayEnv() {
};

ListPlnrQAriAMArrayEnv::ListPlnrQAriAMArrayEnv(
			const ListPlnrQAriAMArrayEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriAMArrayEnv(*(src.nodes[i]));
};

ListPlnrQAriAMArrayEnv& ListPlnrQAriAMArrayEnv::operator=(
			const ListPlnrQAriAMArrayEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriAMArrayEnv(*(src.nodes[i]));

	return *this;
};

ListPlnrQAriAMArrayEnv::~ListPlnrQAriAMArrayEnv() {
	clear();
};

void ListPlnrQAriAMArrayEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQAriAMArrayEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQAriAMArrayEnv* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQAriAMArrayEnv");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQAriAMArrayEnv", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQAriAMArrayEnv(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQAriAMArrayEnv[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

