/**
  * \file PlnrQPrsADetail.cpp
  * app access code for table TblPlnrQPrsADetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrsADetail.h"

/******************************************************************************
 class PlnrQPrsADetail
 ******************************************************************************/

PlnrQPrsADetail::PlnrQPrsADetail(
			const uint jnum
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	this->jnum = jnum;
	this->x1SrefKType = x1SrefKType;
	this->titX1SrefKType = titX1SrefKType;
	this->Val = Val;
};

bool PlnrQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType);
		extractStringUclc(docctx, basexpath, "titX1SrefKType", "typ2", titX1SrefKType);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrsADetail
 ******************************************************************************/

ListPlnrQPrsADetail::ListPlnrQPrsADetail() {
};

ListPlnrQPrsADetail::ListPlnrQPrsADetail(
			const ListPlnrQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsADetail(*(src.nodes[i]));
};

ListPlnrQPrsADetail& ListPlnrQPrsADetail::operator=(
			const ListPlnrQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsADetail(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrsADetail::~ListPlnrQPrsADetail() {
	clear();
};

void ListPlnrQPrsADetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrsADetail* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrsADetail", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrsADetail(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrsADetail[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

