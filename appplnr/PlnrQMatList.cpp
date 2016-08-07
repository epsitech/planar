/**
  * \file PlnrQMatList.cpp
  * app access code for table TblPlnrQMatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatList.h"

/******************************************************************************
 class PlnrQMatList
 ******************************************************************************/

PlnrQMatList::PlnrQMatList(
			const uint jnum
			, const string sref
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefPlnrMCalc
			, const string stubModRefPlnrMMaterial
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefPlnrMCalc = stubRefPlnrMCalc;
	this->stubModRefPlnrMMaterial = stubModRefPlnrMMaterial;
};

bool PlnrQMatList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQMatList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMCalc", "cal", stubRefPlnrMCalc);
		extractStringUclc(docctx, basexpath, "stubModRefPlnrMMaterial", "sup", stubModRefPlnrMMaterial);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQMatList
 ******************************************************************************/

ListPlnrQMatList::ListPlnrQMatList() {
};

ListPlnrQMatList::ListPlnrQMatList(
			const ListPlnrQMatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatList(*(src.nodes[i]));
};

ListPlnrQMatList& ListPlnrQMatList::operator=(
			const ListPlnrQMatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatList(*(src.nodes[i]));

	return *this;
};

ListPlnrQMatList::~ListPlnrQMatList() {
	clear();
};

void ListPlnrQMatList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQMatList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQMatList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQMatList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQMatList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQMatList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQMatList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

