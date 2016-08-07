/**
  * \file PlnrQMatList.h
  * app access code for table TblPlnrQMatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATLIST_H
#define PLNRQMATLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatList
  */
class PlnrQMatList {

public:
	PlnrQMatList(const uint jnum = 0, const string sref = "", const string Title = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string stubRefPlnrMCalc = "", const string stubModRefPlnrMMaterial = "");

public:
	uint jnum;
	string sref;
	string Title;
	string srefIxVBasetype;
	string titIxVBasetype;
	string stubRefPlnrMCalc;
	string stubModRefPlnrMMaterial;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQMatList
  */
class ListPlnrQMatList {

public:
	ListPlnrQMatList();
	ListPlnrQMatList(const ListPlnrQMatList& src);
	ListPlnrQMatList& operator=(const ListPlnrQMatList& src);
	~ListPlnrQMatList();

	void clear();

public:
	vector<PlnrQMatList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

