/**
  * \file PlnrQDgdList.cpp
  * app access code for table TblPlnrQDgdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDgdList.h"

/******************************************************************************
 class PlnrQDgdList
 ******************************************************************************/

PlnrQDgdList::PlnrQDgdList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubDsnRefPlnrMDesign
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
};

bool PlnrQDgdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubDsnRefPlnrMDesign", "dsn", stubDsnRefPlnrMDesign);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDgdList
 ******************************************************************************/

ListPlnrQDgdList::ListPlnrQDgdList() {
};

ListPlnrQDgdList::ListPlnrQDgdList(
			const ListPlnrQDgdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDgdList(*(src.nodes[i]));
};

ListPlnrQDgdList& ListPlnrQDgdList::operator=(
			const ListPlnrQDgdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDgdList(*(src.nodes[i]));

	return *this;
};

ListPlnrQDgdList::~ListPlnrQDgdList() {
	clear();
};

void ListPlnrQDgdList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDgdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDgdList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDgdList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDgdList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDgdList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDgdList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

