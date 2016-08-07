/**
  * \file PlnrQClcSup1NCalc.h
  * app access code for table TblPlnrQClcSup1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCSUP1NCALC_H
#define PLNRQCLCSUP1NCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcSup1NCalc
  */
class PlnrQClcSup1NCalc {

public:
	PlnrQClcSup1NCalc(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcSup1NCalc
  */
class ListPlnrQClcSup1NCalc {

public:
	ListPlnrQClcSup1NCalc();
	ListPlnrQClcSup1NCalc(const ListPlnrQClcSup1NCalc& src);
	ListPlnrQClcSup1NCalc& operator=(const ListPlnrQClcSup1NCalc& src);
	~ListPlnrQClcSup1NCalc();

	void clear();

public:
	vector<PlnrQClcSup1NCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

