/**
  * \file PlnrQUsgList.h
  * app access code for table TblPlnrQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGLIST_H
#define PLNRQUSGLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgList
  */
class PlnrQUsgList {

public:
	PlnrQUsgList(const uint jnum = 0, const string sref = "");

public:
	uint jnum;
	string sref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsgList
  */
class ListPlnrQUsgList {

public:
	ListPlnrQUsgList();
	ListPlnrQUsgList(const ListPlnrQUsgList& src);
	ListPlnrQUsgList& operator=(const ListPlnrQUsgList& src);
	~ListPlnrQUsgList();

	void clear();

public:
	vector<PlnrQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

