/**
  * \file PlnrQSruList.h
  * app access code for table TblPlnrQSruList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRULIST_H
#define PLNRQSRULIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruList
  */
class PlnrQSruList {

public:
	PlnrQSruList(const uint jnum = 0, const string sref = "", const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const string stubHkUref = "");

public:
	uint jnum;
	string sref;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	string stubHkUref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQSruList
  */
class ListPlnrQSruList {

public:
	ListPlnrQSruList();
	ListPlnrQSruList(const ListPlnrQSruList& src);
	ListPlnrQSruList& operator=(const ListPlnrQSruList& src);
	~ListPlnrQSruList();

	void clear();

public:
	vector<PlnrQSruList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

