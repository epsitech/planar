/**
  * \file PlnrQPrj1NCalc.h
  * app access code for table TblPlnrQPrj1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJ1NCALC_H
#define PLNRQPRJ1NCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrj1NCalc
  */
class PlnrQPrj1NCalc {

public:
	PlnrQPrj1NCalc(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrj1NCalc
  */
class ListPlnrQPrj1NCalc {

public:
	ListPlnrQPrj1NCalc();
	ListPlnrQPrj1NCalc(const ListPlnrQPrj1NCalc& src);
	ListPlnrQPrj1NCalc& operator=(const ListPlnrQPrj1NCalc& src);
	~ListPlnrQPrj1NCalc();

	void clear();

public:
	vector<PlnrQPrj1NCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

