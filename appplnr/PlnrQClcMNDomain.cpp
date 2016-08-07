/**
  * \file PlnrQClcMNDomain.cpp
  * app access code for table TblPlnrQClcMNDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcMNDomain.h"

/******************************************************************************
 class PlnrQClcMNDomain
 ******************************************************************************/

PlnrQClcMNDomain::PlnrQClcMNDomain(
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

bool PlnrQClcMNDomain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQClcMNDomain");
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
 class ListPlnrQClcMNDomain
 ******************************************************************************/

ListPlnrQClcMNDomain::ListPlnrQClcMNDomain() {
};

ListPlnrQClcMNDomain::ListPlnrQClcMNDomain(
			const ListPlnrQClcMNDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNDomain(*(src.nodes[i]));
};

ListPlnrQClcMNDomain& ListPlnrQClcMNDomain::operator=(
			const ListPlnrQClcMNDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNDomain(*(src.nodes[i]));

	return *this;
};

ListPlnrQClcMNDomain::~ListPlnrQClcMNDomain() {
	clear();
};

void ListPlnrQClcMNDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQClcMNDomain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQClcMNDomain* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQClcMNDomain");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQClcMNDomain", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQClcMNDomain(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQClcMNDomain[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

