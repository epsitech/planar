/**
  * \file PlnrQDsnHk1NLayer.h
  * app access code for table TblPlnrQDsnHk1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLAYER_H
#define PLNRQDSNHK1NLAYER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLayer
  */
class PlnrQDsnHk1NLayer {

public:
	PlnrQDsnHk1NLayer(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NLayer
  */
class ListPlnrQDsnHk1NLayer {

public:
	ListPlnrQDsnHk1NLayer();
	ListPlnrQDsnHk1NLayer(const ListPlnrQDsnHk1NLayer& src);
	ListPlnrQDsnHk1NLayer& operator=(const ListPlnrQDsnHk1NLayer& src);
	~ListPlnrQDsnHk1NLayer();

	void clear();

public:
	vector<PlnrQDsnHk1NLayer*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

