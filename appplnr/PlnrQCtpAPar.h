/**
  * \file PlnrQCtpAPar.h
  * app access code for table TblPlnrQCtpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPAPAR_H
#define PLNRQCTPAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpAPar
  */
class PlnrQCtpAPar {

public:
	PlnrQCtpAPar(const uint jnum = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

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
  * ListPlnrQCtpAPar
  */
class ListPlnrQCtpAPar {

public:
	ListPlnrQCtpAPar();
	ListPlnrQCtpAPar(const ListPlnrQCtpAPar& src);
	ListPlnrQCtpAPar& operator=(const ListPlnrQCtpAPar& src);
	~ListPlnrQCtpAPar();

	void clear();

public:
	vector<PlnrQCtpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

