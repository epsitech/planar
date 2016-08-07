/**
  * \file PlnrQStkHk1NLevel.h
  * app access code for table TblPlnrQStkHk1NLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKHK1NLEVEL_H
#define PLNRQSTKHK1NLEVEL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkHk1NLevel
  */
class PlnrQStkHk1NLevel {

public:
	PlnrQStkHk1NLevel(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQStkHk1NLevel
  */
class ListPlnrQStkHk1NLevel {

public:
	ListPlnrQStkHk1NLevel();
	ListPlnrQStkHk1NLevel(const ListPlnrQStkHk1NLevel& src);
	ListPlnrQStkHk1NLevel& operator=(const ListPlnrQStkHk1NLevel& src);
	~ListPlnrQStkHk1NLevel();

	void clear();

public:
	vector<PlnrQStkHk1NLevel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

