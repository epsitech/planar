/**
  * \file PlnrQDomMNCalc.h
  * app access code for table TblPlnrQDomMNCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDOMMNCALC_H
#define PLNRQDOMMNCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDomMNCalc
  */
class PlnrQDomMNCalc {

public:
	PlnrQDomMNCalc(const uint jnum = 0, const string stubMref = "", const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");

public:
	uint jnum;
	string stubMref;
	string srefPlnrKCalcdomprp;
	string titSrefPlnrKCalcdomprp;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDomMNCalc
  */
class ListPlnrQDomMNCalc {

public:
	ListPlnrQDomMNCalc();
	ListPlnrQDomMNCalc(const ListPlnrQDomMNCalc& src);
	ListPlnrQDomMNCalc& operator=(const ListPlnrQDomMNCalc& src);
	~ListPlnrQDomMNCalc();

	void clear();

public:
	vector<PlnrQDomMNCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

