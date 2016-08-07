/**
  * \file PlnrQFilMNCalc.cpp
  * app access code for table TblPlnrQFilMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQFilMNCalc.h"

/******************************************************************************
 class PlnrQFilMNCalc
 ******************************************************************************/

PlnrQFilMNCalc::PlnrQFilMNCalc(
			const uint jnum
			, const string stubMref
			, const string stubX1RefPlnrMCalcitem
			, const string srefIxVIo
			, const string titIxVIo
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubX1RefPlnrMCalcitem = stubX1RefPlnrMCalcitem;
	this->srefIxVIo = srefIxVIo;
	this->titIxVIo = titIxVIo;
};

bool PlnrQFilMNCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubX1RefPlnrMCalcitem", "cli", stubX1RefPlnrMCalcitem);
		extractStringUclc(docctx, basexpath, "srefIxVIo", "io", srefIxVIo);
		extractStringUclc(docctx, basexpath, "titIxVIo", "io2", titIxVIo);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQFilMNCalc
 ******************************************************************************/

ListPlnrQFilMNCalc::ListPlnrQFilMNCalc() {
};

ListPlnrQFilMNCalc::ListPlnrQFilMNCalc(
			const ListPlnrQFilMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilMNCalc(*(src.nodes[i]));
};

ListPlnrQFilMNCalc& ListPlnrQFilMNCalc::operator=(
			const ListPlnrQFilMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilMNCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQFilMNCalc::~ListPlnrQFilMNCalc() {
	clear();
};

void ListPlnrQFilMNCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQFilMNCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQFilMNCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQFilMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQFilMNCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQFilMNCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQFilMNCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

