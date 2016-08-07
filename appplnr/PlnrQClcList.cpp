/**
  * \file PlnrQClcList.cpp
  * app access code for table TblPlnrQClcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcList.h"

/******************************************************************************
 class PlnrQClcList
 ******************************************************************************/

PlnrQClcList::PlnrQClcList(
			const uint jnum
			, const string Title
			, const string stubRefPlnrMProject
			, const string srefIxVDim
			, const string titIxVDim
			, const string stubTplRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
			, const string stubRefPlnrMDesign
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRefPlnrMProject = stubRefPlnrMProject;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->stubTplRefPlnrMCalc = stubTplRefPlnrMCalc;
	this->stubSupRefPlnrMCalc = stubSupRefPlnrMCalc;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
};

bool PlnrQClcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMProject", "prj", stubRefPlnrMProject);
		extractStringUclc(docctx, basexpath, "srefIxVDim", "dim", srefIxVDim);
		extractStringUclc(docctx, basexpath, "titIxVDim", "dim2", titIxVDim);
		extractStringUclc(docctx, basexpath, "stubTplRefPlnrMCalc", "tpl", stubTplRefPlnrMCalc);
		extractStringUclc(docctx, basexpath, "stubSupRefPlnrMCalc", "sup", stubSupRefPlnrMCalc);
		extractStringUclc(docctx, basexpath, "stubRefPlnrMDesign", "dsn", stubRefPlnrMDesign);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQClcList
 ******************************************************************************/

ListPlnrQClcList::ListPlnrQClcList() {
};

ListPlnrQClcList::ListPlnrQClcList(
			const ListPlnrQClcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcList(*(src.nodes[i]));
};

ListPlnrQClcList& ListPlnrQClcList::operator=(
			const ListPlnrQClcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcList(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcList::~ListPlnrQClcList() {
	clear();
};

void ListPlnrQClcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

