/**
  * \file PlnrQMatRef1NFile.cpp
  * app access code for table TblPlnrQMatRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatRef1NFile.h"

/******************************************************************************
 class PlnrQMatRef1NFile
 ******************************************************************************/

PlnrQMatRef1NFile::PlnrQMatRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQMatRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQMatRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQMatRef1NFile
 ******************************************************************************/

ListPlnrQMatRef1NFile::ListPlnrQMatRef1NFile() {
};

ListPlnrQMatRef1NFile::ListPlnrQMatRef1NFile(
			const ListPlnrQMatRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatRef1NFile(*(src.nodes[i]));
};

ListPlnrQMatRef1NFile& ListPlnrQMatRef1NFile::operator=(
			const ListPlnrQMatRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatRef1NFile(*(src.nodes[i]));

	return *this;
};

ListPlnrQMatRef1NFile::~ListPlnrQMatRef1NFile() {
	clear();
};

void ListPlnrQMatRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQMatRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQMatRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQMatRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQMatRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQMatRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQMatRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

