/**
  * \file PlnrQDsnList.cpp
  * app access code for table TblPlnrQDsnList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnList.h"

/******************************************************************************
 class PlnrQDsnList
 ******************************************************************************/

PlnrQDsnList::PlnrQDsnList(
			const uint jnum
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string srefIxVDim
			, const string titIxVDim
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string stubRefPlnrMProject
			, const string srefsIxWModtype
			, const string titsIxWModtype
			, const string stubModRefPlnrMDesign
			, const string stubDrvRefPlnrMDesign
			, const usmallint Major
			, const usmallint Sub
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->stubRefPlnrMProject = stubRefPlnrMProject;
	this->srefsIxWModtype = srefsIxWModtype;
	this->titsIxWModtype = titsIxWModtype;
	this->stubModRefPlnrMDesign = stubModRefPlnrMDesign;
	this->stubDrvRefPlnrMDesign = stubDrvRefPlnrMDesign;
	this->Major = Major;
	this->Sub = Sub;
};

bool PlnrQDsnList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "srefIxVDim", "dim", srefIxVDim);
		extractStringUclc(docctx, basexpath, "titIxVDim", "dim2", titIxVDim);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMProject", "prj", stubRefPlnrMProject);
		extractStringUclc(docctx, basexpath, "srefsIxWModtype", "mty", srefsIxWModtype);
		extractStringUclc(docctx, basexpath, "titsIxWModtype", "mty2", titsIxWModtype);
		extractStringUclc(docctx, basexpath, "stubModRefPlnrMDesign", "mod", stubModRefPlnrMDesign);
		extractStringUclc(docctx, basexpath, "stubDrvRefPlnrMDesign", "drv", stubDrvRefPlnrMDesign);
		extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major);
		extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDsnList
 ******************************************************************************/

ListPlnrQDsnList::ListPlnrQDsnList() {
};

ListPlnrQDsnList::ListPlnrQDsnList(
			const ListPlnrQDsnList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnList(*(src.nodes[i]));
};

ListPlnrQDsnList& ListPlnrQDsnList::operator=(
			const ListPlnrQDsnList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnList(*(src.nodes[i]));

	return *this;
};

ListPlnrQDsnList::~ListPlnrQDsnList() {
	clear();
};

void ListPlnrQDsnList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDsnList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDsnList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDsnList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDsnList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDsnList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDsnList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

