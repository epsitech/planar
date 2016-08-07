/**
  * \file PlnrQDomMNCalc.cpp
  * app access code for table TblPlnrQDomMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDomMNCalc.h"

/******************************************************************************
 class PlnrQDomMNCalc
 ******************************************************************************/

PlnrQDomMNCalc::PlnrQDomMNCalc(
			const uint jnum
			, const string stubMref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefPlnrKCalcdomprp = srefPlnrKCalcdomprp;
	this->titSrefPlnrKCalcdomprp = titSrefPlnrKCalcdomprp;
};

bool PlnrQDomMNCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQDomMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefPlnrKCalcdomprp", "prp", srefPlnrKCalcdomprp);
		extractStringUclc(docctx, basexpath, "titSrefPlnrKCalcdomprp", "prp2", titSrefPlnrKCalcdomprp);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQDomMNCalc
 ******************************************************************************/

ListPlnrQDomMNCalc::ListPlnrQDomMNCalc() {
};

ListPlnrQDomMNCalc::ListPlnrQDomMNCalc(
			const ListPlnrQDomMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomMNCalc(*(src.nodes[i]));
};

ListPlnrQDomMNCalc& ListPlnrQDomMNCalc::operator=(
			const ListPlnrQDomMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomMNCalc(*(src.nodes[i]));

	return *this;
};

ListPlnrQDomMNCalc::~ListPlnrQDomMNCalc() {
	clear();
};

void ListPlnrQDomMNCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQDomMNCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQDomMNCalc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQDomMNCalc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQDomMNCalc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQDomMNCalc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQDomMNCalc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

