/**
  * \file PlnrQArrList.cpp
  * app access code for table TblPlnrQArrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrList.h"

/******************************************************************************
 class PlnrQArrList
 ******************************************************************************/

PlnrQArrList::PlnrQArrList(
			const uint jnum
			, const string sref
			, const string stubRefPlnrMTapeout
			, const string stubRefPlnrMDesign
			, const usmallint I
			, const usmallint J
			, const usmallint K
			, const usmallint L
			, const usmallint M
			, const usmallint N
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefPlnrMTapeout = stubRefPlnrMTapeout;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->I = I;
	this->J = J;
	this->K = K;
	this->L = L;
	this->M = M;
	this->N = N;
};

bool PlnrQArrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQArrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMTapeout", "tpo", stubRefPlnrMTapeout);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMDesign", "dsn", stubRefPlnrMDesign);
		extractUsmallintUclc(docctx, basexpath, "I", "i", I);
		extractUsmallintUclc(docctx, basexpath, "J", "j", J);
		extractUsmallintUclc(docctx, basexpath, "K", "k", K);
		extractUsmallintUclc(docctx, basexpath, "L", "l", L);
		extractUsmallintUclc(docctx, basexpath, "M", "m", M);
		extractUsmallintUclc(docctx, basexpath, "N", "n", N);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQArrList
 ******************************************************************************/

ListPlnrQArrList::ListPlnrQArrList() {
};

ListPlnrQArrList::ListPlnrQArrList(
			const ListPlnrQArrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrList(*(src.nodes[i]));
};

ListPlnrQArrList& ListPlnrQArrList::operator=(
			const ListPlnrQArrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrList(*(src.nodes[i]));

	return *this;
};

ListPlnrQArrList::~ListPlnrQArrList() {
	clear();
};

void ListPlnrQArrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQArrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQArrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQArrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQArrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQArrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQArrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

