/**
  * \file PlnrQDvcAPar.cpp
  * app access code for table TblPlnrQDvcAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcAPar.h"

/******************************************************************************
 class PlnrQDvcAPar
 ******************************************************************************/

PlnrQDvcAPar::PlnrQDvcAPar(
			const uint jnum
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string stubRefPlnrMFile
			, const string Val
		) {
	this->jnum = jnum;
	this->stubX1RefPlnrMDesign = stubX1RefPlnrMDesign;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
};

bool PlnrQDvcAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefPlnrMDesign", "dsn", stubX1RefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "x2SrefKKey", "key", x2SrefKKey);
		extractStringUclc(docctx, basexpath, "titX2SrefKKey", "key2", titX2SrefKKey);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMFile", "fil", stubRefPlnrMFile);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcAPar
 ******************************************************************************/

ListPlnrQDvcAPar::ListPlnrQDvcAPar() {
};

ListPlnrQDvcAPar::ListPlnrQDvcAPar(
			const ListPlnrQDvcAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcAPar(*(src.nodes[i]));
};

ListPlnrQDvcAPar& ListPlnrQDvcAPar::operator=(
			const ListPlnrQDvcAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcAPar(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcAPar::~ListPlnrQDvcAPar() {
	clear();
};

void ListPlnrQDvcAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

