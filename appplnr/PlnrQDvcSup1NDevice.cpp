/**
  * \file PlnrQDvcSup1NDevice.cpp
  * app access code for table TblPlnrQDvcSup1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcSup1NDevice.h"

/******************************************************************************
 class PlnrQDvcSup1NDevice
 ******************************************************************************/

PlnrQDvcSup1NDevice::PlnrQDvcSup1NDevice(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDvcSup1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDvcSup1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDvcSup1NDevice
 ******************************************************************************/

ListPlnrQDvcSup1NDevice::ListPlnrQDvcSup1NDevice() {
};

ListPlnrQDvcSup1NDevice::ListPlnrQDvcSup1NDevice(
			const ListPlnrQDvcSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcSup1NDevice(*(src.nodes[i]));
};

ListPlnrQDvcSup1NDevice& ListPlnrQDvcSup1NDevice::operator=(
			const ListPlnrQDvcSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcSup1NDevice(*(src.nodes[i]));

	return *this;
};

ListPlnrQDvcSup1NDevice::~ListPlnrQDvcSup1NDevice() {
	clear();
};

void ListPlnrQDvcSup1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDvcSup1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDvcSup1NDevice* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDvcSup1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDvcSup1NDevice", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDvcSup1NDevice(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDvcSup1NDevice[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

