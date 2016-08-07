/**
  * \file PlnrQMatMod1NMaterial.cpp
  * app access code for table TblPlnrQMatMod1NMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatMod1NMaterial.h"

/******************************************************************************
 class PlnrQMatMod1NMaterial
 ******************************************************************************/

PlnrQMatMod1NMaterial::PlnrQMatMod1NMaterial(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQMatMod1NMaterial::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQMatMod1NMaterial");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQMatMod1NMaterial
 ******************************************************************************/

ListPlnrQMatMod1NMaterial::ListPlnrQMatMod1NMaterial() {
};

ListPlnrQMatMod1NMaterial::ListPlnrQMatMod1NMaterial(
			const ListPlnrQMatMod1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatMod1NMaterial(*(src.nodes[i]));
};

ListPlnrQMatMod1NMaterial& ListPlnrQMatMod1NMaterial::operator=(
			const ListPlnrQMatMod1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatMod1NMaterial(*(src.nodes[i]));

	return *this;
};

ListPlnrQMatMod1NMaterial::~ListPlnrQMatMod1NMaterial() {
	clear();
};

void ListPlnrQMatMod1NMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQMatMod1NMaterial::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQMatMod1NMaterial* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQMatMod1NMaterial");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQMatMod1NMaterial", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQMatMod1NMaterial(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQMatMod1NMaterial[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

