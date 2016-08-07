/**
  * \file PlnrQSru1NBlock.cpp
  * app access code for table TblPlnrQSru1NBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSru1NBlock.h"

/******************************************************************************
 class PlnrQSru1NBlock
 ******************************************************************************/

PlnrQSru1NBlock::PlnrQSru1NBlock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQSru1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQSru1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQSru1NBlock
 ******************************************************************************/

ListPlnrQSru1NBlock::ListPlnrQSru1NBlock() {
};

ListPlnrQSru1NBlock::ListPlnrQSru1NBlock(
			const ListPlnrQSru1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSru1NBlock(*(src.nodes[i]));
};

ListPlnrQSru1NBlock& ListPlnrQSru1NBlock::operator=(
			const ListPlnrQSru1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSru1NBlock(*(src.nodes[i]));

	return *this;
};

ListPlnrQSru1NBlock::~ListPlnrQSru1NBlock() {
	clear();
};

void ListPlnrQSru1NBlock::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQSru1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQSru1NBlock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQSru1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQSru1NBlock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQSru1NBlock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQSru1NBlock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

