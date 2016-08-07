/**
  * \file PlnrQArr1NArrayitem.h
  * app access code for table TblPlnrQArr1NArrayitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARR1NARRAYITEM_H
#define PLNRQARR1NARRAYITEM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArr1NArrayitem
  */
class PlnrQArr1NArrayitem {

public:
	PlnrQArr1NArrayitem(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQArr1NArrayitem
  */
class ListPlnrQArr1NArrayitem {

public:
	ListPlnrQArr1NArrayitem();
	ListPlnrQArr1NArrayitem(const ListPlnrQArr1NArrayitem& src);
	ListPlnrQArr1NArrayitem& operator=(const ListPlnrQArr1NArrayitem& src);
	~ListPlnrQArr1NArrayitem();

	void clear();

public:
	vector<PlnrQArr1NArrayitem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

