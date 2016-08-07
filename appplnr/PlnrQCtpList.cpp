/**
  * \file PlnrQCtpList.cpp
  * app access code for table TblPlnrQCtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpList.h"

/******************************************************************************
 class PlnrQCtpList
 ******************************************************************************/

PlnrQCtpList::PlnrQCtpList(
			const uint jnum
			, const string Title
			, const string srefIxVDim
			, const string titIxVDim
			, const string stubSupRefPlnrMCalc
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->stubSupRefPlnrMCalc = stubSupRefPlnrMCalc;
};

bool PlnrQCtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVDim", "dim", srefIxVDim);
		extractStringUclc(docctx, basexpath, "titIxVDim", "dim2", titIxVDim);
		extractStringUclc(docctx, basexpath, "stubSupRefPlnrMCalc", "sup", stubSupRefPlnrMCalc);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpList
 ******************************************************************************/

ListPlnrQCtpList::ListPlnrQCtpList() {
};

ListPlnrQCtpList::ListPlnrQCtpList(
			const ListPlnrQCtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpList(*(src.nodes[i]));
};

ListPlnrQCtpList& ListPlnrQCtpList::operator=(
			const ListPlnrQCtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpList(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpList::~ListPlnrQCtpList() {
	clear();
};

void ListPlnrQCtpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

