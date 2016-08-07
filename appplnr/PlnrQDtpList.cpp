/**
  * \file PlnrQDtpList.cpp
  * app access code for table TblPlnrQDtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpList.h"

/******************************************************************************
 class PlnrQDtpList
 ******************************************************************************/

PlnrQDtpList::PlnrQDtpList(
			const uint jnum
			, const string sref
			, const string stubSupRefPlnrMDevice
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSupRefPlnrMDevice = stubSupRefPlnrMDevice;
};

bool PlnrQDtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSupRefPlnrMDevice", "sup", stubSupRefPlnrMDevice);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDtpList
 ******************************************************************************/

ListPlnrQDtpList::ListPlnrQDtpList() {
};

ListPlnrQDtpList::ListPlnrQDtpList(
			const ListPlnrQDtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpList(*(src.nodes[i]));
};

ListPlnrQDtpList& ListPlnrQDtpList::operator=(
			const ListPlnrQDtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpList(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpList::~ListPlnrQDtpList() {
	clear();
};

void ListPlnrQDtpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

