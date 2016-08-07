/**
  * \file PlnrQCliRef1NFile.cpp
  * app access code for table TblPlnrQCliRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliRef1NFile.h"

/******************************************************************************
 class PlnrQCliRef1NFile
 ******************************************************************************/

PlnrQCliRef1NFile::PlnrQCliRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQCliRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCliRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCliRef1NFile
 ******************************************************************************/

ListPlnrQCliRef1NFile::ListPlnrQCliRef1NFile() {
};

ListPlnrQCliRef1NFile::ListPlnrQCliRef1NFile(
			const ListPlnrQCliRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliRef1NFile(*(src.nodes[i]));
};

ListPlnrQCliRef1NFile& ListPlnrQCliRef1NFile::operator=(
			const ListPlnrQCliRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliRef1NFile(*(src.nodes[i]));

	return *this;
};

ListPlnrQCliRef1NFile::~ListPlnrQCliRef1NFile() {
	clear();
};

void ListPlnrQCliRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCliRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCliRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCliRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCliRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCliRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCliRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

