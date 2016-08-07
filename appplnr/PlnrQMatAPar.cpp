/**
  * \file PlnrQMatAPar.cpp
  * app access code for table TblPlnrQMatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatAPar.h"

/******************************************************************************
 class PlnrQMatAPar
 ******************************************************************************/

PlnrQMatAPar::PlnrQMatAPar(
			const uint jnum
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string stubRefPlnrMFile
			, const string Val
			, const string Comment
		) {
	this->jnum = jnum;
	this->stubX1RefPlnrMDesign = stubX1RefPlnrMDesign;
	this->x2SrefKCat = x2SrefKCat;
	this->titX2SrefKCat = titX2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->titX3SrefKProp = titX3SrefKProp;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
	this->Comment = Comment;
};

bool PlnrQMatAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQMatAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefPlnrMDesign", "dsn", stubX1RefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "x2SrefKCat", "cat", x2SrefKCat);
		extractStringUclc(docctx, basexpath, "titX2SrefKCat", "cat2", titX2SrefKCat);
		extractStringUclc(docctx, basexpath, "x3SrefKProp", "prp", x3SrefKProp);
		extractStringUclc(docctx, basexpath, "titX3SrefKProp", "prp2", titX3SrefKProp);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMFile", "fil", stubRefPlnrMFile);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQMatAPar
 ******************************************************************************/

ListPlnrQMatAPar::ListPlnrQMatAPar() {
};

ListPlnrQMatAPar::ListPlnrQMatAPar(
			const ListPlnrQMatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatAPar(*(src.nodes[i]));
};

ListPlnrQMatAPar& ListPlnrQMatAPar::operator=(
			const ListPlnrQMatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatAPar(*(src.nodes[i]));

	return *this;
};

ListPlnrQMatAPar::~ListPlnrQMatAPar() {
	clear();
};

void ListPlnrQMatAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQMatAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQMatAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQMatAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQMatAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQMatAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQMatAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

