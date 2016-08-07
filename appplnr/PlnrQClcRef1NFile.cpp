/**
  * \file PlnrQClcRef1NFile.cpp
  * app access code for table TblPlnrQClcRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcRef1NFile.h"

/******************************************************************************
 class PlnrQClcRef1NFile
 ******************************************************************************/

PlnrQClcRef1NFile::PlnrQClcRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQClcRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClcRef1NFile
 ******************************************************************************/

ListPlnrQClcRef1NFile::ListPlnrQClcRef1NFile() {
};

ListPlnrQClcRef1NFile::ListPlnrQClcRef1NFile(
			const ListPlnrQClcRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcRef1NFile(*(src.nodes[i]));
};

ListPlnrQClcRef1NFile& ListPlnrQClcRef1NFile::operator=(
			const ListPlnrQClcRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcRef1NFile(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcRef1NFile::~ListPlnrQClcRef1NFile() {
	clear();
};

void ListPlnrQClcRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

