/**
  * \file PlnrQMatAPar.h
  * app access code for table TblPlnrQMatAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATAPAR_H
#define PLNRQMATAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatAPar
  */
class PlnrQMatAPar {

public:
	PlnrQMatAPar(const uint jnum = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string stubRefPlnrMFile = "", const string Val = "", const string Comment = "");

public:
	uint jnum;
	string stubX1RefPlnrMDesign;
	string x2SrefKCat;
	string titX2SrefKCat;
	string x3SrefKProp;
	string titX3SrefKProp;
	string stubRefPlnrMFile;
	string Val;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQMatAPar
  */
class ListPlnrQMatAPar {

public:
	ListPlnrQMatAPar();
	ListPlnrQMatAPar(const ListPlnrQMatAPar& src);
	ListPlnrQMatAPar& operator=(const ListPlnrQMatAPar& src);
	~ListPlnrQMatAPar();

	void clear();

public:
	vector<PlnrQMatAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

