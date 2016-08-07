/**
  * \file PlnrQDsnHk1NLineguide.h
  * app access code for table TblPlnrQDsnHk1NLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLINEGUIDE_H
#define PLNRQDSNHK1NLINEGUIDE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLineguide
  */
class PlnrQDsnHk1NLineguide {

public:
	PlnrQDsnHk1NLineguide(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NLineguide
  */
class ListPlnrQDsnHk1NLineguide {

public:
	ListPlnrQDsnHk1NLineguide();
	ListPlnrQDsnHk1NLineguide(const ListPlnrQDsnHk1NLineguide& src);
	ListPlnrQDsnHk1NLineguide& operator=(const ListPlnrQDsnHk1NLineguide& src);
	~ListPlnrQDsnHk1NLineguide();

	void clear();

public:
	vector<PlnrQDsnHk1NLineguide*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

