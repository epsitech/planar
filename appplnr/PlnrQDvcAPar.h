/**
  * \file PlnrQDvcAPar.h
  * app access code for table TblPlnrQDvcAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCAPAR_H
#define PLNRQDVCAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcAPar
  */
class PlnrQDvcAPar {

public:
	PlnrQDvcAPar(const uint jnum = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const string stubRefPlnrMFile = "", const string Val = "");

public:
	uint jnum;
	string stubX1RefPlnrMDesign;
	string x2SrefKKey;
	string titX2SrefKKey;
	string stubRefPlnrMFile;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcAPar
  */
class ListPlnrQDvcAPar {

public:
	ListPlnrQDvcAPar();
	ListPlnrQDvcAPar(const ListPlnrQDvcAPar& src);
	ListPlnrQDvcAPar& operator=(const ListPlnrQDvcAPar& src);
	~ListPlnrQDvcAPar();

	void clear();

public:
	vector<PlnrQDvcAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

