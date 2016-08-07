/**
  * \file PlnrQStkList.cpp
  * app access code for table TblPlnrQStkList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkList.h"

/******************************************************************************
 class PlnrQStkList
 ******************************************************************************/

PlnrQStkList::PlnrQStkList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubDsnRefPlnrMDesign
			, const string srefIxVModtype
			, const string titIxVModtype
			, const string srefIxVFlrAligntype
			, const string titIxVFlrAligntype
			, const string srefIxVCeilAligntype
			, const string titIxVCeilAligntype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
	this->srefIxVModtype = srefIxVModtype;
	this->titIxVModtype = titIxVModtype;
	this->srefIxVFlrAligntype = srefIxVFlrAligntype;
	this->titIxVFlrAligntype = titIxVFlrAligntype;
	this->srefIxVCeilAligntype = srefIxVCeilAligntype;
	this->titIxVCeilAligntype = titIxVCeilAligntype;
};

bool PlnrQStkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQStkList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubDsnRefPlnrMDesign", "dsn", stubDsnRefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "srefIxVModtype", "mty", srefIxVModtype);
		extractStringUclc(docctx, basexpath, "titIxVModtype", "mty2", titIxVModtype);
		extractStringUclc(docctx, basexpath, "srefIxVFlrAligntype", "fal", srefIxVFlrAligntype);
		extractStringUclc(docctx, basexpath, "titIxVFlrAligntype", "fal2", titIxVFlrAligntype);
		extractStringUclc(docctx, basexpath, "srefIxVCeilAligntype", "cal", srefIxVCeilAligntype);
		extractStringUclc(docctx, basexpath, "titIxVCeilAligntype", "cal2", titIxVCeilAligntype);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQStkList
 ******************************************************************************/

ListPlnrQStkList::ListPlnrQStkList() {
};

ListPlnrQStkList::ListPlnrQStkList(
			const ListPlnrQStkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkList(*(src.nodes[i]));
};

ListPlnrQStkList& ListPlnrQStkList::operator=(
			const ListPlnrQStkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkList(*(src.nodes[i]));

	return *this;
};

ListPlnrQStkList::~ListPlnrQStkList() {
	clear();
};

void ListPlnrQStkList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQStkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQStkList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQStkList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQStkList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQStkList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQStkList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

