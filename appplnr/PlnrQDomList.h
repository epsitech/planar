/**
  * \file PlnrQDomList.h
  * app access code for table TblPlnrQDomList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDOMLIST_H
#define PLNRQDOMLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDomList
  */
class PlnrQDomList {

public:
	PlnrQDomList(const uint jnum = 0, const string sref = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string stubDsnRefPlnrMDesign = "");

public:
	uint jnum;
	string sref;
	string srefIxVBasetype;
	string titIxVBasetype;
	string stubDsnRefPlnrMDesign;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDomList
  */
class ListPlnrQDomList {

public:
	ListPlnrQDomList();
	ListPlnrQDomList(const ListPlnrQDomList& src);
	ListPlnrQDomList& operator=(const ListPlnrQDomList& src);
	~ListPlnrQDomList();

	void clear();

public:
	vector<PlnrQDomList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

