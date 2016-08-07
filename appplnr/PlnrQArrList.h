/**
  * \file PlnrQArrList.h
  * app access code for table TblPlnrQArrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRLIST_H
#define PLNRQARRLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrList
  */
class PlnrQArrList {

public:
	PlnrQArrList(const uint jnum = 0, const string sref = "", const string stubRefPlnrMTapeout = "", const string stubRefPlnrMDesign = "", const usmallint I = 0, const usmallint J = 0, const usmallint K = 0, const usmallint L = 0, const usmallint M = 0, const usmallint N = 0);

public:
	uint jnum;
	string sref;
	string stubRefPlnrMTapeout;
	string stubRefPlnrMDesign;
	usmallint I;
	usmallint J;
	usmallint K;
	usmallint L;
	usmallint M;
	usmallint N;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQArrList
  */
class ListPlnrQArrList {

public:
	ListPlnrQArrList();
	ListPlnrQArrList(const ListPlnrQArrList& src);
	ListPlnrQArrList& operator=(const ListPlnrQArrList& src);
	~ListPlnrQArrList();

	void clear();

public:
	vector<PlnrQArrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

