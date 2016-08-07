/**
  * \file PlnrQDsnDrv1NDesign.cpp
  * app access code for table TblPlnrQDsnDrv1NDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDrv1NDesign.h"

/******************************************************************************
 class PlnrQDsnDrv1NDesign
 ******************************************************************************/

PlnrQDsnDrv1NDesign::PlnrQDsnDrv1NDesign(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnDrv1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnDrv1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnDrv1NDesign
 ******************************************************************************/

ListPlnrQDsnDrv1NDesign::ListPlnrQDsnDrv1NDesign() {
};

ListPlnrQDsnDrv1NDesign::ListPlnrQDsnDrv1NDesign(
			const ListPlnrQDsnDrv1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDrv1NDesign(*(src.nodes[i]));
};

ListPlnrQDsnDrv1NDesign& ListPlnrQDsnDrv1NDesign::operator=(
			const ListPlnrQDsnDrv1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDrv1NDesign(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnDrv1NDesign::~ListPlnrQDsnDrv1NDesign() {
	clear();
};

void ListPlnrQDsnDrv1NDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnDrv1NDesign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnDrv1NDesign* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnDrv1NDesign");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnDrv1NDesign", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnDrv1NDesign(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnDrv1NDesign[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

