/**
  * \file PlnrQPrsList.cpp
  * app access code for table TblPlnrQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrsList.h"

/******************************************************************************
 class PlnrQPrsList
 ******************************************************************************/

PlnrQPrsList::PlnrQPrsList(
			const uint jnum
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string stubGrp
			, const string stubOwn
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->Tel = Tel;
	this->Eml = Eml;
};

bool PlnrQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PlnrQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "Tel", "tel", Tel);
		extractStringUclc(docctx, basexpath, "Eml", "eml", Eml);
	};

	return basefound;
};

/******************************************************************************
 class ListPlnrQPrsList
 ******************************************************************************/

ListPlnrQPrsList::ListPlnrQPrsList() {
};

ListPlnrQPrsList::ListPlnrQPrsList(
			const ListPlnrQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsList(*(src.nodes[i]));
};

ListPlnrQPrsList& ListPlnrQPrsList::operator=(
			const ListPlnrQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsList(*(src.nodes[i]));

	return *this;
};

ListPlnrQPrsList::~ListPlnrQPrsList() {
	clear();
};

void ListPlnrQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListPlnrQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	PlnrQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListPlnrQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "PlnrQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new PlnrQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/PlnrQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

