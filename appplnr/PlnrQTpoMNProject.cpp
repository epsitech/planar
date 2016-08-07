/**
  * \file PlnrQTpoMNProject.cpp
  * app access code for table TblPlnrQTpoMNProject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoMNProject.h"

/******************************************************************************
 class PlnrQTpoMNProject
 ******************************************************************************/

PlnrQTpoMNProject::PlnrQTpoMNProject(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool PlnrQTpoMNProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQTpoMNProject");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQTpoMNProject
 ******************************************************************************/

ListPlnrQTpoMNProject::ListPlnrQTpoMNProject() {
};

ListPlnrQTpoMNProject::ListPlnrQTpoMNProject(
			const ListPlnrQTpoMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoMNProject(*(src.nodes[i]));
};

ListPlnrQTpoMNProject& ListPlnrQTpoMNProject::operator=(
			const ListPlnrQTpoMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoMNProject(*(src.nodes[i]));

	return *this;
};

ListPlnrQTpoMNProject::~ListPlnrQTpoMNProject() {
	clear();
};

void ListPlnrQTpoMNProject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQTpoMNProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQTpoMNProject* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQTpoMNProject");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQTpoMNProject", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQTpoMNProject(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQTpoMNProject[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

