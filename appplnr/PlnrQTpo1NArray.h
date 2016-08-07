/**
  * \file PlnrQTpo1NArray.h
  * app access code for table TblPlnrQTpo1NArray (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPO1NARRAY_H
#define PLNRQTPO1NARRAY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpo1NArray
  */
class PlnrQTpo1NArray {

public:
	PlnrQTpo1NArray(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQTpo1NArray
  */
class ListPlnrQTpo1NArray {

public:
	ListPlnrQTpo1NArray();
	ListPlnrQTpo1NArray(const ListPlnrQTpo1NArray& src);
	ListPlnrQTpo1NArray& operator=(const ListPlnrQTpo1NArray& src);
	~ListPlnrQTpo1NArray();

	void clear();

public:
	vector<PlnrQTpo1NArray*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

