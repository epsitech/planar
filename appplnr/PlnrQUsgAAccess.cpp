/**
  * \file PlnrQUsgAAccess.cpp
  * app access code for table TblPlnrQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsgAAccess.h"

/******************************************************************************
 class PlnrQUsgAAccess
 ******************************************************************************/

PlnrQUsgAAccess::PlnrQUsgAAccess(
			const uint jnum
			, const string srefX1IxPlnrVCard
			, const string titX1IxPlnrVCard
			, const string srefsIxPlnrWUiaccess
			, const string titsIxPlnrWUiaccess
		) {
	this->jnum = jnum;
	this->srefX1IxPlnrVCard = srefX1IxPlnrVCard;
	this->titX1IxPlnrVCard = titX1IxPlnrVCard;
	this->srefsIxPlnrWUiaccess = srefsIxPlnrWUiaccess;
	this->titsIxPlnrWUiaccess = titsIxPlnrWUiaccess;
};

bool PlnrQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxPlnrVCard", "crd", srefX1IxPlnrVCard);
		extractStringUclc(docctx, basexpath, "titX1IxPlnrVCard", "crd2", titX1IxPlnrVCard);
		extractStringUclc(docctx, basexpath, "srefsIxPlnrWUiaccess", "uac", srefsIxPlnrWUiaccess);
		extractStringUclc(docctx, basexpath, "titsIxPlnrWUiaccess", "uac2", titsIxPlnrWUiaccess);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQUsgAAccess
 ******************************************************************************/

ListPlnrQUsgAAccess::ListPlnrQUsgAAccess() {
};

ListPlnrQUsgAAccess::ListPlnrQUsgAAccess(
			const ListPlnrQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgAAccess(*(src.nodes[i]));
};

ListPlnrQUsgAAccess& ListPlnrQUsgAAccess::operator=(
			const ListPlnrQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsgAAccess::~ListPlnrQUsgAAccess() {
	clear();
};

void ListPlnrQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

