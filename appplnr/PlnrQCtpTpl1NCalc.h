/**
  * \file PlnrQCtpTpl1NCalc.h
  * app access code for table TblPlnrQCtpTpl1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPTPL1NCALC_H
#define PLNRQCTPTPL1NCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpTpl1NCalc
  */
class PlnrQCtpTpl1NCalc {

public:
	PlnrQCtpTpl1NCalc(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpTpl1NCalc
  */
class ListPlnrQCtpTpl1NCalc {

public:
	ListPlnrQCtpTpl1NCalc();
	ListPlnrQCtpTpl1NCalc(const ListPlnrQCtpTpl1NCalc& src);
	ListPlnrQCtpTpl1NCalc& operator=(const ListPlnrQCtpTpl1NCalc& src);
	~ListPlnrQCtpTpl1NCalc();

	void clear();

public:
	vector<PlnrQCtpTpl1NCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

