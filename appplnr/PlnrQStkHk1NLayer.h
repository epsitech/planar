/**
  * \file PlnrQStkHk1NLayer.h
  * app access code for table TblPlnrQStkHk1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKHK1NLAYER_H
#define PLNRQSTKHK1NLAYER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkHk1NLayer
  */
class PlnrQStkHk1NLayer {

public:
	PlnrQStkHk1NLayer(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQStkHk1NLayer
  */
class ListPlnrQStkHk1NLayer {

public:
	ListPlnrQStkHk1NLayer();
	ListPlnrQStkHk1NLayer(const ListPlnrQStkHk1NLayer& src);
	ListPlnrQStkHk1NLayer& operator=(const ListPlnrQStkHk1NLayer& src);
	~ListPlnrQStkHk1NLayer();

	void clear();

public:
	vector<PlnrQStkHk1NLayer*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

