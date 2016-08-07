/**
  * \file PlnrQUsrMNUsergroup.cpp
  * app access code for table TblPlnrQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrMNUsergroup.h"

/******************************************************************************
 class PlnrQUsrMNUsergroup
 ******************************************************************************/

PlnrQUsrMNUsergroup::PlnrQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxPlnrVUserlevel = srefIxPlnrVUserlevel;
	this->titIxPlnrVUserlevel = titIxPlnrVUserlevel;
};

bool PlnrQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxPlnrVUserlevel", "ulv", srefIxPlnrVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxPlnrVUserlevel", "ulv2", titIxPlnrVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQUsrMNUsergroup
 ******************************************************************************/

ListPlnrQUsrMNUsergroup::ListPlnrQUsrMNUsergroup() {
};

ListPlnrQUsrMNUsergroup::ListPlnrQUsrMNUsergroup(
			const ListPlnrQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrMNUsergroup(*(src.nodes[i]));
};

ListPlnrQUsrMNUsergroup& ListPlnrQUsrMNUsergroup::operator=(
			const ListPlnrQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsrMNUsergroup::~ListPlnrQUsrMNUsergroup() {
	clear();
};

void ListPlnrQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

