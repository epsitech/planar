/**
  * \file PlnrQStkMNStructure.cpp
  * app access code for table TblPlnrQStkMNStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkMNStructure.h"

/******************************************************************************
 class PlnrQStkMNStructure
 ******************************************************************************/

PlnrQStkMNStructure::PlnrQStkMNStructure(
			const uint jnum
			, const string stubMref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->fromSrefPlnrMLayer = fromSrefPlnrMLayer;
	this->toSrefPlnrMLayer = toSrefPlnrMLayer;
};

bool PlnrQStkMNStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQStkMNStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "fromSrefPlnrMLayer", "frl", fromSrefPlnrMLayer);
		extractStringUclc(docctx, basexpath, "toSrefPlnrMLayer", "tol", toSrefPlnrMLayer);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQStkMNStructure
 ******************************************************************************/

ListPlnrQStkMNStructure::ListPlnrQStkMNStructure() {
};

ListPlnrQStkMNStructure::ListPlnrQStkMNStructure(
			const ListPlnrQStkMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkMNStructure(*(src.nodes[i]));
};

ListPlnrQStkMNStructure& ListPlnrQStkMNStructure::operator=(
			const ListPlnrQStkMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkMNStructure(*(src.nodes[i]));

	return *this;
};

ListPlnrQStkMNStructure::~ListPlnrQStkMNStructure() {
	clear();
};

void ListPlnrQStkMNStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQStkMNStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQStkMNStructure* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQStkMNStructure");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQStkMNStructure", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQStkMNStructure(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQStkMNStructure[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

