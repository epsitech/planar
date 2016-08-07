/**
  * \file PlnrQDvcHk1NStructure.h
  * app access code for table TblPlnrQDvcHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NSTRUCTURE_H
#define PLNRQDVCHK1NSTRUCTURE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NStructure
  */
class PlnrQDvcHk1NStructure {

public:
	PlnrQDvcHk1NStructure(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcHk1NStructure
  */
class ListPlnrQDvcHk1NStructure {

public:
	ListPlnrQDvcHk1NStructure();
	ListPlnrQDvcHk1NStructure(const ListPlnrQDvcHk1NStructure& src);
	ListPlnrQDvcHk1NStructure& operator=(const ListPlnrQDvcHk1NStructure& src);
	~ListPlnrQDvcHk1NStructure();

	void clear();

public:
	vector<PlnrQDvcHk1NStructure*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

