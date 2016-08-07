/**
  * \file PlnrQCliAAMCalcEnv.h
  * app access code for table TblPlnrQCliAAMCalcEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIAAMCALCENV_H
#define PLNRQCLIAAMCALCENV_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliAAMCalcEnv
  */
class PlnrQCliAAMCalcEnv {

public:
	PlnrQCliAAMCalcEnv(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCliAAMCalcEnv
  */
class ListPlnrQCliAAMCalcEnv {

public:
	ListPlnrQCliAAMCalcEnv();
	ListPlnrQCliAAMCalcEnv(const ListPlnrQCliAAMCalcEnv& src);
	ListPlnrQCliAAMCalcEnv& operator=(const ListPlnrQCliAAMCalcEnv& src);
	~ListPlnrQCliAAMCalcEnv();

	void clear();

public:
	vector<PlnrQCliAAMCalcEnv*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

