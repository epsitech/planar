/**
  * \file PlnrQCliAAMCalcEnv.cpp
  * app access code for table TblPlnrQCliAAMCalcEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliAAMCalcEnv.h"

/******************************************************************************
 class PlnrQCliAAMCalcEnv
 ******************************************************************************/

PlnrQCliAAMCalcEnv::PlnrQCliAAMCalcEnv(
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

bool PlnrQCliAAMCalcEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCliAAMCalcEnv");
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
 class ListPlnrQCliAAMCalcEnv
 ******************************************************************************/

ListPlnrQCliAAMCalcEnv::ListPlnrQCliAAMCalcEnv() {
};

ListPlnrQCliAAMCalcEnv::ListPlnrQCliAAMCalcEnv(
			const ListPlnrQCliAAMCalcEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliAAMCalcEnv(*(src.nodes[i]));
};

ListPlnrQCliAAMCalcEnv& ListPlnrQCliAAMCalcEnv::operator=(
			const ListPlnrQCliAAMCalcEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliAAMCalcEnv(*(src.nodes[i]));

	return *this;
};

ListPlnrQCliAAMCalcEnv::~ListPlnrQCliAAMCalcEnv() {
	clear();
};

void ListPlnrQCliAAMCalcEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCliAAMCalcEnv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCliAAMCalcEnv* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCliAAMCalcEnv");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCliAAMCalcEnv", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCliAAMCalcEnv(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCliAAMCalcEnv[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

