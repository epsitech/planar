/**
  * \file PlnrQLyrList.cpp
  * app access code for table TblPlnrQLyrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyrList.h"

/******************************************************************************
 class PlnrQLyrList
 ******************************************************************************/

PlnrQLyrList::PlnrQLyrList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string stubRefPlnrMMaterial
			, const string srefIxVTtype
			, const string titIxVTtype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->stubRefPlnrMMaterial = stubRefPlnrMMaterial;
	this->srefIxVTtype = srefIxVTtype;
	this->titIxVTtype = titIxVTtype;
};

bool PlnrQLyrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQLyrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMMaterial", "mat", stubRefPlnrMMaterial);
		extractStringUclc(docctx, basexpath, "srefIxVTtype", "tty", srefIxVTtype);
		extractStringUclc(docctx, basexpath, "titIxVTtype", "tty2", titIxVTtype);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQLyrList
 ******************************************************************************/

ListPlnrQLyrList::ListPlnrQLyrList() {
};

ListPlnrQLyrList::ListPlnrQLyrList(
			const ListPlnrQLyrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrList(*(src.nodes[i]));
};

ListPlnrQLyrList& ListPlnrQLyrList::operator=(
			const ListPlnrQLyrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrList(*(src.nodes[i]));

	return *this;
};

ListPlnrQLyrList::~ListPlnrQLyrList() {
	clear();
};

void ListPlnrQLyrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQLyrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQLyrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQLyrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQLyrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQLyrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQLyrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

