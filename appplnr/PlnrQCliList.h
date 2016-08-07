/**
  * \file PlnrQCliList.h
  * app access code for table TblPlnrQCliList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLILIST_H
#define PLNRQCLILIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliList
  */
class PlnrQCliList {

public:
	PlnrQCliList(const uint jnum = 0, const string Title = "", const string stubCalRefPlnrMCalc = "", const string stubRefPlnrMDesign = "");

public:
	uint jnum;
	string Title;
	string stubCalRefPlnrMCalc;
	string stubRefPlnrMDesign;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCliList
  */
class ListPlnrQCliList {

public:
	ListPlnrQCliList();
	ListPlnrQCliList(const ListPlnrQCliList& src);
	ListPlnrQCliList& operator=(const ListPlnrQCliList& src);
	~ListPlnrQCliList();

	void clear();

public:
	vector<PlnrQCliList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

