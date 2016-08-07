/**
  * \file PlnrQRtcList.cpp
  * app access code for table TblPlnrQRtcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQRtcList.h"

/******************************************************************************
 class PlnrQRtcList
 ******************************************************************************/

PlnrQRtcList::PlnrQRtcList(
			const uint jnum
			, const string sref
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string stubRefPlnrMDesign
			, const string stubRefPlnrMLayer
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->stubRefPlnrMLayer = stubRefPlnrMLayer;
};

bool PlnrQRtcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQRtcList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMDesign", "dsn", stubRefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMLayer", "lyr", stubRefPlnrMLayer);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQRtcList
 ******************************************************************************/

ListPlnrQRtcList::ListPlnrQRtcList() {
};

ListPlnrQRtcList::ListPlnrQRtcList(
			const ListPlnrQRtcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQRtcList(*(src.nodes[i]));
};

ListPlnrQRtcList& ListPlnrQRtcList::operator=(
			const ListPlnrQRtcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQRtcList(*(src.nodes[i]));

	return *this;
};

ListPlnrQRtcList::~ListPlnrQRtcList() {
	clear();
};

void ListPlnrQRtcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQRtcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQRtcList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQRtcList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQRtcList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQRtcList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQRtcList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

