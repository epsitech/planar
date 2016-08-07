/**
  * \file PlnrQFilList.cpp
  * app access code for table TblPlnrQFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQFilList.h"

/******************************************************************************
 class PlnrQFilList
 ******************************************************************************/

PlnrQFilList::PlnrQFilList(
			const uint jnum
			, const string Filename
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const uint Size
		) {
	this->jnum = jnum;
	this->Filename = Filename;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

bool PlnrQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent);
		extractStringUclc(docctx, basexpath, "titOsrefKContent", "cnt2", titOsrefKContent);
		extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype);
		extractStringUclc(docctx, basexpath, "titSrefKMimetype", "mim2", titSrefKMimetype);
		extractUintUclc(docctx, basexpath, "Size", "siz", Size);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQFilList
 ******************************************************************************/

ListPlnrQFilList::ListPlnrQFilList() {
};

ListPlnrQFilList::ListPlnrQFilList(
			const ListPlnrQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilList(*(src.nodes[i]));
};

ListPlnrQFilList& ListPlnrQFilList::operator=(
			const ListPlnrQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilList(*(src.nodes[i]));

	return *this;
};

ListPlnrQFilList::~ListPlnrQFilList() {
	clear();
};

void ListPlnrQFilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQFilList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQFilList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQFilList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQFilList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

