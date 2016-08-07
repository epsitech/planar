/**
  * \file PlnrQDgdList.h
  * app access code for table TblPlnrQDgdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDGDLIST_H
#define PLNRQDGDLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDgdList
  */
class PlnrQDgdList {

public:
	PlnrQDgdList(const uint jnum = 0, const string sref = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string stubDsnRefPlnrMDesign = "");

public:
	uint jnum;
	string sref;
	string srefIxVBasetype;
	string titIxVBasetype;
	string stubDsnRefPlnrMDesign;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDgdList
  */
class ListPlnrQDgdList {

public:
	ListPlnrQDgdList();
	ListPlnrQDgdList(const ListPlnrQDgdList& src);
	ListPlnrQDgdList& operator=(const ListPlnrQDgdList& src);
	~ListPlnrQDgdList();

	void clear();

public:
	vector<PlnrQDgdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

