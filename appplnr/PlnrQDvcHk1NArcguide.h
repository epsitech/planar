/**
  * \file PlnrQDvcHk1NArcguide.h
  * app access code for table TblPlnrQDvcHk1NArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NARCGUIDE_H
#define PLNRQDVCHK1NARCGUIDE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NArcguide
  */
class PlnrQDvcHk1NArcguide {

public:
	PlnrQDvcHk1NArcguide(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcHk1NArcguide
  */
class ListPlnrQDvcHk1NArcguide {

public:
	ListPlnrQDvcHk1NArcguide();
	ListPlnrQDvcHk1NArcguide(const ListPlnrQDvcHk1NArcguide& src);
	ListPlnrQDvcHk1NArcguide& operator=(const ListPlnrQDvcHk1NArcguide& src);
	~ListPlnrQDvcHk1NArcguide();

	void clear();

public:
	vector<PlnrQDvcHk1NArcguide*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

