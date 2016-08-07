/**
  * \file PlnrQCtpSup1NCalc.h
  * app access code for table TblPlnrQCtpSup1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPSUP1NCALC_H
#define PLNRQCTPSUP1NCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpSup1NCalc
  */
class PlnrQCtpSup1NCalc {

public:
	PlnrQCtpSup1NCalc(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpSup1NCalc
  */
class ListPlnrQCtpSup1NCalc {

public:
	ListPlnrQCtpSup1NCalc();
	ListPlnrQCtpSup1NCalc(const ListPlnrQCtpSup1NCalc& src);
	ListPlnrQCtpSup1NCalc& operator=(const ListPlnrQCtpSup1NCalc& src);
	~ListPlnrQCtpSup1NCalc();

	void clear();

public:
	vector<PlnrQCtpSup1NCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

