/**
  * \file PlnrQDtpTpl1NDevice.cpp
  * app access code for table TblPlnrQDtpTpl1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpTpl1NDevice.h"

/******************************************************************************
 class PlnrQDtpTpl1NDevice
 ******************************************************************************/

PlnrQDtpTpl1NDevice::PlnrQDtpTpl1NDevice(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool PlnrQDtpTpl1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDtpTpl1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDtpTpl1NDevice
 ******************************************************************************/

ListPlnrQDtpTpl1NDevice::ListPlnrQDtpTpl1NDevice() {
};

ListPlnrQDtpTpl1NDevice::ListPlnrQDtpTpl1NDevice(
			const ListPlnrQDtpTpl1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpTpl1NDevice(*(src.nodes[i]));
};

ListPlnrQDtpTpl1NDevice& ListPlnrQDtpTpl1NDevice::operator=(
			const ListPlnrQDtpTpl1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpTpl1NDevice(*(src.nodes[i]));

	return *this;
};

ListPlnrQDtpTpl1NDevice::~ListPlnrQDtpTpl1NDevice() {
	clear();
};

void ListPlnrQDtpTpl1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDtpTpl1NDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDtpTpl1NDevice* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDtpTpl1NDevice");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDtpTpl1NDevice", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDtpTpl1NDevice(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDtpTpl1NDevice[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

