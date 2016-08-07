/**
  * \file PlnrQCtpKCalcdomprp.cpp
  * app access code for table TblPlnrQCtpKCalcdomprp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKCalcdomprp.h"

/******************************************************************************
 class PlnrQCtpKCalcdomprp
 ******************************************************************************/

PlnrQCtpKCalcdomprp::PlnrQCtpKCalcdomprp(
			const uint jnum
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const string Title
			, const string Comment
		) {
	this->jnum = jnum;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrQCtpKCalcdomprp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQCtpKCalcdomprp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "yesnoFixed", "fix", yesnoFixed);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Avail", "avl", Avail);
		extractStringUclc(docctx, basexpath, "Implied", "imp", Implied);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQCtpKCalcdomprp
 ******************************************************************************/

ListPlnrQCtpKCalcdomprp::ListPlnrQCtpKCalcdomprp() {
};

ListPlnrQCtpKCalcdomprp::ListPlnrQCtpKCalcdomprp(
			const ListPlnrQCtpKCalcdomprp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKCalcdomprp(*(src.nodes[i]));
};

ListPlnrQCtpKCalcdomprp& ListPlnrQCtpKCalcdomprp::operator=(
			const ListPlnrQCtpKCalcdomprp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKCalcdomprp(*(src.nodes[i]));

	return *this;
};

ListPlnrQCtpKCalcdomprp::~ListPlnrQCtpKCalcdomprp() {
	clear();
};

void ListPlnrQCtpKCalcdomprp::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQCtpKCalcdomprp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQCtpKCalcdomprp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQCtpKCalcdomprp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQCtpKCalcdomprp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQCtpKCalcdomprp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQCtpKCalcdomprp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

