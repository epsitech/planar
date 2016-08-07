/**
  * \file PlnrQDvcHk1NLineguide.h
  * app access code for table TblPlnrQDvcHk1NLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NLINEGUIDE_H
#define PLNRQDVCHK1NLINEGUIDE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NLineguide
  */
class PlnrQDvcHk1NLineguide {

public:
	PlnrQDvcHk1NLineguide(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcHk1NLineguide
  */
class ListPlnrQDvcHk1NLineguide {

public:
	ListPlnrQDvcHk1NLineguide();
	ListPlnrQDvcHk1NLineguide(const ListPlnrQDvcHk1NLineguide& src);
	ListPlnrQDvcHk1NLineguide& operator=(const ListPlnrQDvcHk1NLineguide& src);
	~ListPlnrQDvcHk1NLineguide();

	void clear();

public:
	vector<PlnrQDvcHk1NLineguide*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

