/**
  * \file PlnrQDsnHk1NLevel.h
  * app access code for table TblPlnrQDsnHk1NLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLEVEL_H
#define PLNRQDSNHK1NLEVEL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLevel
  */
class PlnrQDsnHk1NLevel {

public:
	PlnrQDsnHk1NLevel(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NLevel
  */
class ListPlnrQDsnHk1NLevel {

public:
	ListPlnrQDsnHk1NLevel();
	ListPlnrQDsnHk1NLevel(const ListPlnrQDsnHk1NLevel& src);
	ListPlnrQDsnHk1NLevel& operator=(const ListPlnrQDsnHk1NLevel& src);
	~ListPlnrQDsnHk1NLevel();

	void clear();

public:
	vector<PlnrQDsnHk1NLevel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

