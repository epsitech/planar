/**
  * \file PlnrQUsgMNUser.cpp
  * app access code for table TblPlnrQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsgMNUser.h"

/******************************************************************************
 class PlnrQUsgMNUser
 ******************************************************************************/

PlnrQUsgMNUser::PlnrQUsgMNUser(
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

bool PlnrQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQUsgMNUser");
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
 class ListPlnrQUsgMNUser
 ******************************************************************************/

ListPlnrQUsgMNUser::ListPlnrQUsgMNUser() {
};

ListPlnrQUsgMNUser::ListPlnrQUsgMNUser(
			const ListPlnrQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgMNUser(*(src.nodes[i]));
};

ListPlnrQUsgMNUser& ListPlnrQUsgMNUser::operator=(
			const ListPlnrQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListPlnrQUsgMNUser::~ListPlnrQUsgMNUser() {
	clear();
};

void ListPlnrQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

