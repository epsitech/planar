/**
  * \file PlnrQLyr1NBlock.cpp
  * app access code for table TblPlnrQLyr1NBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyr1NBlock.h"

/******************************************************************************
 class PlnrQLyr1NBlock
 ******************************************************************************/

PlnrQLyr1NBlock::PlnrQLyr1NBlock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQLyr1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQLyr1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQLyr1NBlock
 ******************************************************************************/

ListPlnrQLyr1NBlock::ListPlnrQLyr1NBlock() {
};

ListPlnrQLyr1NBlock::ListPlnrQLyr1NBlock(
			const ListPlnrQLyr1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NBlock(*(src.nodes[i]));
};

ListPlnrQLyr1NBlock& ListPlnrQLyr1NBlock::operator=(
			const ListPlnrQLyr1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NBlock(*(src.nodes[i]));

	return *this;
};

ListPlnrQLyr1NBlock::~ListPlnrQLyr1NBlock() {
	clear();
};

void ListPlnrQLyr1NBlock::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQLyr1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQLyr1NBlock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQLyr1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQLyr1NBlock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQLyr1NBlock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQLyr1NBlock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

