/**
  * \file PlnrQCtpAPar.cpp
  * app access code for table TblPlnrQCtpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpAPar.h"

/******************************************************************************
 class PlnrQCtpAPar
 ******************************************************************************/

PlnrQCtpAPar::PlnrQCtpAPar(
			const uint jnum
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	this->jnum = jnum;
	this->x2SrefKCat = x2SrefKCat;
	this->titX2SrefKCat = titX2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->titX3SrefKProp = titX3SrefKProp;
	this->Val = Val;
};

bool PlnrQCtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x2SrefKCat", "cat", x2SrefKCat);
		extractStringUclc(docctx, basexpath, "titX2SrefKCat", "cat2", titX2SrefKCat);
		extractStringUclc(docctx, basexpath, "x3SrefKProp", "prp", x3SrefKProp);
		extractStringUclc(docctx, basexpath, "titX3SrefKProp", "prp2", titX3SrefKProp);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpAPar
 ******************************************************************************/

ListPlnrQCtpAPar::ListPlnrQCtpAPar() {
};

ListPlnrQCtpAPar::ListPlnrQCtpAPar(
			const ListPlnrQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAPar(*(src.nodes[i]));
};

ListPlnrQCtpAPar& ListPlnrQCtpAPar::operator=(
			const ListPlnrQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAPar(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpAPar::~ListPlnrQCtpAPar() {
	clear();
};

void ListPlnrQCtpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

