/**
  * \file PlnrQDsn1NBlock.cpp
  * app access code for table TblPlnrQDsn1NBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsn1NBlock.h"

/******************************************************************************
 class PlnrQDsn1NBlock
 ******************************************************************************/

PlnrQDsn1NBlock::PlnrQDsn1NBlock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsn1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsn1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsn1NBlock
 ******************************************************************************/

ListPlnrQDsn1NBlock::ListPlnrQDsn1NBlock() {
};

ListPlnrQDsn1NBlock::ListPlnrQDsn1NBlock(
			const ListPlnrQDsn1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsn1NBlock(*(src.nodes[i]));
};

ListPlnrQDsn1NBlock& ListPlnrQDsn1NBlock::operator=(
			const ListPlnrQDsn1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsn1NBlock(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsn1NBlock::~ListPlnrQDsn1NBlock() {
	clear();
};

void ListPlnrQDsn1NBlock::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsn1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsn1NBlock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsn1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsn1NBlock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsn1NBlock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsn1NBlock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

