/**
  * \file PlnrQPrjMNTapeout.cpp
  * app access code for table TblPlnrQPrjMNTapeout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrjMNTapeout.h"

/******************************************************************************
 class PlnrQPrjMNTapeout
 ******************************************************************************/

PlnrQPrjMNTapeout::PlnrQPrjMNTapeout(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool PlnrQPrjMNTapeout::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrjMNTapeout");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrjMNTapeout
 ******************************************************************************/

ListPlnrQPrjMNTapeout::ListPlnrQPrjMNTapeout() {
};

ListPlnrQPrjMNTapeout::ListPlnrQPrjMNTapeout(
			const ListPlnrQPrjMNTapeout& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrjMNTapeout(*(src.nodes[i]));
};

ListPlnrQPrjMNTapeout& ListPlnrQPrjMNTapeout::operator=(
			const ListPlnrQPrjMNTapeout& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrjMNTapeout(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrjMNTapeout::~ListPlnrQPrjMNTapeout() {
	clear();
};

void ListPlnrQPrjMNTapeout::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrjMNTapeout::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrjMNTapeout* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrjMNTapeout");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrjMNTapeout", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrjMNTapeout(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrjMNTapeout[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

