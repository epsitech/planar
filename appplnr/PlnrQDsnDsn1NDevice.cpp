/**
  * \file PlnrQDsnDsn1NDevice.cpp
  * app access code for table TblPlnrQDsnDsn1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NDevice.h"

/******************************************************************************
 class PlnrQDsnDsn1NDevice
 ******************************************************************************/

PlnrQDsnDsn1NDevice::PlnrQDsnDsn1NDevice(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDsnDsn1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnDsn1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnDsn1NDevice
 ******************************************************************************/

ListPlnrQDsnDsn1NDevice::ListPlnrQDsnDsn1NDevice() {
};

ListPlnrQDsnDsn1NDevice::ListPlnrQDsnDsn1NDevice(
			const ListPlnrQDsnDsn1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDevice(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NDevice& ListPlnrQDsnDsn1NDevice::operator=(
			const ListPlnrQDsnDsn1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDevice(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnDsn1NDevice::~ListPlnrQDsnDsn1NDevice() {
	clear();
};

void ListPlnrQDsnDsn1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnDsn1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnDsn1NDevice* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnDsn1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnDsn1NDevice", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnDsn1NDevice(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnDsn1NDevice[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

