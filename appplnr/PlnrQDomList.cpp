/**
  * \file PlnrQDomList.cpp
  * app access code for table TblPlnrQDomList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDomList.h"

/******************************************************************************
 class PlnrQDomList
 ******************************************************************************/

PlnrQDomList::PlnrQDomList(
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

bool PlnrQDomList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDomList");
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
 class ListPlnrQDomList
 ******************************************************************************/

ListPlnrQDomList::ListPlnrQDomList() {
};

ListPlnrQDomList::ListPlnrQDomList(
			const ListPlnrQDomList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomList(*(src.nodes[i]));
};

ListPlnrQDomList& ListPlnrQDomList::operator=(
			const ListPlnrQDomList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomList(*(src.nodes[i]));

	return *this;
};

ListPlnrQDomList::~ListPlnrQDomList() {
	clear();
};

void ListPlnrQDomList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDomList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDomList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDomList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDomList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDomList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDomList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

