/**
  * \file PlnrQClcCal1NCalcitem.h
  * app access code for table TblPlnrQClcCal1NCalcitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCCAL1NCALCITEM_H
#define PLNRQCLCCAL1NCALCITEM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcCal1NCalcitem
  */
class PlnrQClcCal1NCalcitem {

public:
	PlnrQClcCal1NCalcitem(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcCal1NCalcitem
  */
class ListPlnrQClcCal1NCalcitem {

public:
	ListPlnrQClcCal1NCalcitem();
	ListPlnrQClcCal1NCalcitem(const ListPlnrQClcCal1NCalcitem& src);
	ListPlnrQClcCal1NCalcitem& operator=(const ListPlnrQClcCal1NCalcitem& src);
	~ListPlnrQClcCal1NCalcitem();

	void clear();

public:
	vector<PlnrQClcCal1NCalcitem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

