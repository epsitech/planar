/**
  * \file PlnrQCliAAMCalcPar.h
  * app access code for table TblPlnrQCliAAMCalcPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIAAMCALCPAR_H
#define PLNRQCLIAAMCALCPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliAAMCalcPar
  */
class PlnrQCliAAMCalcPar {

public:
	PlnrQCliAAMCalcPar(const uint jnum = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

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
  * ListPlnrQCliAAMCalcPar
  */
class ListPlnrQCliAAMCalcPar {

public:
	ListPlnrQCliAAMCalcPar();
	ListPlnrQCliAAMCalcPar(const ListPlnrQCliAAMCalcPar& src);
	ListPlnrQCliAAMCalcPar& operator=(const ListPlnrQCliAAMCalcPar& src);
	~ListPlnrQCliAAMCalcPar();

	void clear();

public:
	vector<PlnrQCliAAMCalcPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

