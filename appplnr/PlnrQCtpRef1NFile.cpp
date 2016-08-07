/**
  * \file PlnrQCtpRef1NFile.cpp
  * app access code for table TblPlnrQCtpRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpRef1NFile.h"

/******************************************************************************
 class PlnrQCtpRef1NFile
 ******************************************************************************/

PlnrQCtpRef1NFile::PlnrQCtpRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQCtpRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpRef1NFile
 ******************************************************************************/

ListPlnrQCtpRef1NFile::ListPlnrQCtpRef1NFile() {
};

ListPlnrQCtpRef1NFile::ListPlnrQCtpRef1NFile(
			const ListPlnrQCtpRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpRef1NFile(*(src.nodes[i]));
};

ListPlnrQCtpRef1NFile& ListPlnrQCtpRef1NFile::operator=(
			const ListPlnrQCtpRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpRef1NFile(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpRef1NFile::~ListPlnrQCtpRef1NFile() {
	clear();
};

void ListPlnrQCtpRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

