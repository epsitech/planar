/**
  * \file PlnrQClcAPar.h
  * app access code for table TblPlnrQClcAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCAPAR_H
#define PLNRQCLCAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcAPar
  */
class PlnrQClcAPar {

public:
	PlnrQClcAPar(const uint jnum = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKCat;
	string titX2SrefKCat;
	string x3SrefKProp;
	string titX3SrefKProp;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcAPar
  */
class ListPlnrQClcAPar {

public:
	ListPlnrQClcAPar();
	ListPlnrQClcAPar(const ListPlnrQClcAPar& src);
	ListPlnrQClcAPar& operator=(const ListPlnrQClcAPar& src);
	~ListPlnrQClcAPar();

	void clear();

public:
	vector<PlnrQClcAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

