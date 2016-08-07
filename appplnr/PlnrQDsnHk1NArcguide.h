/**
  * \file PlnrQDsnHk1NArcguide.h
  * app access code for table TblPlnrQDsnHk1NArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NARCGUIDE_H
#define PLNRQDSNHK1NARCGUIDE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NArcguide
  */
class PlnrQDsnHk1NArcguide {

public:
	PlnrQDsnHk1NArcguide(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NArcguide
  */
class ListPlnrQDsnHk1NArcguide {

public:
	ListPlnrQDsnHk1NArcguide();
	ListPlnrQDsnHk1NArcguide(const ListPlnrQDsnHk1NArcguide& src);
	ListPlnrQDsnHk1NArcguide& operator=(const ListPlnrQDsnHk1NArcguide& src);
	~ListPlnrQDsnHk1NArcguide();

	void clear();

public:
	vector<PlnrQDsnHk1NArcguide*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

