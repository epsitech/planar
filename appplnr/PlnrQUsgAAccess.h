/**
  * \file PlnrQUsgAAccess.h
  * app access code for table TblPlnrQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGAACCESS_H
#define PLNRQUSGAACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgAAccess
  */
class PlnrQUsgAAccess {

public:
	PlnrQUsgAAccess(const uint jnum = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");

public:
	uint jnum;
	string srefX1IxPlnrVCard;
	string titX1IxPlnrVCard;
	string srefsIxPlnrWUiaccess;
	string titsIxPlnrWUiaccess;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsgAAccess
  */
class ListPlnrQUsgAAccess {

public:
	ListPlnrQUsgAAccess();
	ListPlnrQUsgAAccess(const ListPlnrQUsgAAccess& src);
	ListPlnrQUsgAAccess& operator=(const ListPlnrQUsgAAccess& src);
	~ListPlnrQUsgAAccess();

	void clear();

public:
	vector<PlnrQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

