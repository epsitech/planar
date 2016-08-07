/**
  * \file PlnrQUsrAAccess.cpp
  * app access code for table TblPlnrQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrAAccess.h"

/******************************************************************************
 class PlnrQUsrAAccess
 ******************************************************************************/

PlnrQUsrAAccess::PlnrQUsrAAccess(
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

bool PlnrQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsrAAccess");
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
 class ListPlnrQUsrAAccess
 ******************************************************************************/

ListPlnrQUsrAAccess::ListPlnrQUsrAAccess() {
};

ListPlnrQUsrAAccess::ListPlnrQUsrAAccess(
			const ListPlnrQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrAAccess(*(src.nodes[i]));
};

ListPlnrQUsrAAccess& ListPlnrQUsrAAccess::operator=(
			const ListPlnrQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsrAAccess::~ListPlnrQUsrAAccess() {
	clear();
};

void ListPlnrQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

