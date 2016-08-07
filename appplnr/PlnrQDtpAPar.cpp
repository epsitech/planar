/**
  * \file PlnrQDtpAPar.cpp
  * app access code for table TblPlnrQDtpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpAPar.h"

/******************************************************************************
 class PlnrQDtpAPar
 ******************************************************************************/

PlnrQDtpAPar::PlnrQDtpAPar(
			const uint jnum
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string stubRefPlnrMFile
			, const string Val
		) {
	this->jnum = jnum;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
};

bool PlnrQDtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x2SrefKKey", "key", x2SrefKKey);
		extractStringUclc(docctx, basexpath, "titX2SrefKKey", "key2", titX2SrefKKey);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMFile", "fil", stubRefPlnrMFile);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDtpAPar
 ******************************************************************************/

ListPlnrQDtpAPar::ListPlnrQDtpAPar() {
};

ListPlnrQDtpAPar::ListPlnrQDtpAPar(
			const ListPlnrQDtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpAPar(*(src.nodes[i]));
};

ListPlnrQDtpAPar& ListPlnrQDtpAPar::operator=(
			const ListPlnrQDtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpAPar(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpAPar::~ListPlnrQDtpAPar() {
	clear();
};

void ListPlnrQDtpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

