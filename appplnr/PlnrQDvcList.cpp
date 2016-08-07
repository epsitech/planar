/**
  * \file PlnrQDvcList.cpp
  * app access code for table TblPlnrQDvcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcList.h"

/******************************************************************************
 class PlnrQDvcList
 ******************************************************************************/

PlnrQDvcList::PlnrQDvcList(
			const uint jnum
			, const string sref
			, const string stubDsnRefPlnrMDesign
			, const string stubSupRefPlnrMDevice
			, const string stubTplRefPlnrMDevice
			, const string srefIxVModtype
			, const string titIxVModtype
			, const string srefIxVAligntype
			, const string titIxVAligntype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
	this->stubSupRefPlnrMDevice = stubSupRefPlnrMDevice;
	this->stubTplRefPlnrMDevice = stubTplRefPlnrMDevice;
	this->srefIxVModtype = srefIxVModtype;
	this->titIxVModtype = titIxVModtype;
	this->srefIxVAligntype = srefIxVAligntype;
	this->titIxVAligntype = titIxVAligntype;
};

bool PlnrQDvcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubDsnRefPlnrMDesign", "dsn", stubDsnRefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "stubSupRefPlnrMDevice", "sup", stubSupRefPlnrMDevice);
		extractStringUclc(docctx, basexpath, "stubTplRefPlnrMDevice", "tpl", stubTplRefPlnrMDevice);
		extractStringUclc(docctx, basexpath, "srefIxVModtype", "mty", srefIxVModtype);
		extractStringUclc(docctx, basexpath, "titIxVModtype", "mty2", titIxVModtype);
		extractStringUclc(docctx, basexpath, "srefIxVAligntype", "aty", srefIxVAligntype);
		extractStringUclc(docctx, basexpath, "titIxVAligntype", "aty2", titIxVAligntype);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcList
 ******************************************************************************/

ListPlnrQDvcList::ListPlnrQDvcList() {
};

ListPlnrQDvcList::ListPlnrQDvcList(
			const ListPlnrQDvcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcList(*(src.nodes[i]));
};

ListPlnrQDvcList& ListPlnrQDvcList::operator=(
			const ListPlnrQDvcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcList(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcList::~ListPlnrQDvcList() {
	clear();
};

void ListPlnrQDvcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

