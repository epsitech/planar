/**
  * \file PlnrQAriList.h
  * app access code for table TblPlnrQAriList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARILIST_H
#define PLNRQARILIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQAriList
  */
class PlnrQAriList {

public:
	PlnrQAriList(const uint jnum = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const string stubRefPlnrMArray = "", const string stubRefPlnrMDesign = "", const double dx = 0.0, const double dy = 0.0);

public:
	uint jnum;
	usmallint i;
	usmallint j;
	usmallint k;
	usmallint l;
	usmallint m;
	usmallint n;
	string stubRefPlnrMArray;
	string stubRefPlnrMDesign;
	double dx;
	double dy;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQAriList
  */
class ListPlnrQAriList {

public:
	ListPlnrQAriList();
	ListPlnrQAriList(const ListPlnrQAriList& src);
	ListPlnrQAriList& operator=(const ListPlnrQAriList& src);
	~ListPlnrQAriList();

	void clear();

public:
	vector<PlnrQAriList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

