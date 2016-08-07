/**
  * \file PlnrQClc1NMaterial.cpp
  * app access code for table TblPlnrQClc1NMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClc1NMaterial.h"

/******************************************************************************
 class PlnrQClc1NMaterial
 ******************************************************************************/

PlnrQClc1NMaterial::PlnrQClc1NMaterial(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQClc1NMaterial::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClc1NMaterial");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClc1NMaterial
 ******************************************************************************/

ListPlnrQClc1NMaterial::ListPlnrQClc1NMaterial() {
};

ListPlnrQClc1NMaterial::ListPlnrQClc1NMaterial(
			const ListPlnrQClc1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClc1NMaterial(*(src.nodes[i]));
};

ListPlnrQClc1NMaterial& ListPlnrQClc1NMaterial::operator=(
			const ListPlnrQClc1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClc1NMaterial(*(src.nodes[i]));

	return *this;
};

ListPlnrQClc1NMaterial::~ListPlnrQClc1NMaterial() {
	clear();
};

void ListPlnrQClc1NMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClc1NMaterial::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClc1NMaterial* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClc1NMaterial");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClc1NMaterial", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClc1NMaterial(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClc1NMaterial[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

