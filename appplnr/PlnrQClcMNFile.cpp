/**
  * \file PlnrQClcMNFile.cpp
  * app access code for table TblPlnrQClcMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcMNFile.h"

/******************************************************************************
 class PlnrQClcMNFile
 ******************************************************************************/

PlnrQClcMNFile::PlnrQClcMNFile(
			const uint jnum
			, const string stubMref
			, const string stubX1RefPlnrMCalcitem
			, const string srefIxVIo
			, const string titIxVIo
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubX1RefPlnrMCalcitem = stubX1RefPlnrMCalcitem;
	this->srefIxVIo = srefIxVIo;
	this->titIxVIo = titIxVIo;
};

bool PlnrQClcMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubX1RefPlnrMCalcitem", "cli", stubX1RefPlnrMCalcitem);
		extractStringUclc(docctx, basexpath, "srefIxVIo", "io", srefIxVIo);
		extractStringUclc(docctx, basexpath, "titIxVIo", "io2", titIxVIo);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClcMNFile
 ******************************************************************************/

ListPlnrQClcMNFile::ListPlnrQClcMNFile() {
};

ListPlnrQClcMNFile::ListPlnrQClcMNFile(
			const ListPlnrQClcMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNFile(*(src.nodes[i]));
};

ListPlnrQClcMNFile& ListPlnrQClcMNFile::operator=(
			const ListPlnrQClcMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNFile(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcMNFile::~ListPlnrQClcMNFile() {
	clear();
};

void ListPlnrQClcMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcMNFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcMNFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcMNFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcMNFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

