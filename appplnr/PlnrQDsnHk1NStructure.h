/**
  * \file PlnrQDsnHk1NStructure.h
  * app access code for table TblPlnrQDsnHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NSTRUCTURE_H
#define PLNRQDSNHK1NSTRUCTURE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NStructure
  */
class PlnrQDsnHk1NStructure {

public:
	PlnrQDsnHk1NStructure(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NStructure
  */
class ListPlnrQDsnHk1NStructure {

public:
	ListPlnrQDsnHk1NStructure();
	ListPlnrQDsnHk1NStructure(const ListPlnrQDsnHk1NStructure& src);
	ListPlnrQDsnHk1NStructure& operator=(const ListPlnrQDsnHk1NStructure& src);
	~ListPlnrQDsnHk1NStructure();

	void clear();

public:
	vector<PlnrQDsnHk1NStructure*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

