/**
  * \file PlnrQDtpSup1NDevice.cpp
  * app access code for table TblPlnrQDtpSup1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpSup1NDevice.h"

/******************************************************************************
 class PlnrQDtpSup1NDevice
 ******************************************************************************/

PlnrQDtpSup1NDevice::PlnrQDtpSup1NDevice(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDtpSup1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpSup1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDtpSup1NDevice
 ******************************************************************************/

ListPlnrQDtpSup1NDevice::ListPlnrQDtpSup1NDevice() {
};

ListPlnrQDtpSup1NDevice::ListPlnrQDtpSup1NDevice(
			const ListPlnrQDtpSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpSup1NDevice(*(src.nodes[i]));
};

ListPlnrQDtpSup1NDevice& ListPlnrQDtpSup1NDevice::operator=(
			const ListPlnrQDtpSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpSup1NDevice(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpSup1NDevice::~ListPlnrQDtpSup1NDevice() {
	clear();
};

void ListPlnrQDtpSup1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpSup1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpSup1NDevice* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpSup1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpSup1NDevice", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpSup1NDevice(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpSup1NDevice[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

