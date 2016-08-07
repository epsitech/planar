/**
  * \file PlnrQArrAEnv.h
  * app access code for table TblPlnrQArrAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRAENV_H
#define PLNRQARRAENV_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrAEnv
  */
class PlnrQArrAEnv {

public:
	PlnrQArrAEnv(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQArrAEnv
  */
class ListPlnrQArrAEnv {

public:
	ListPlnrQArrAEnv();
	ListPlnrQArrAEnv(const ListPlnrQArrAEnv& src);
	ListPlnrQArrAEnv& operator=(const ListPlnrQArrAEnv& src);
	~ListPlnrQArrAEnv();

	void clear();

public:
	vector<PlnrQArrAEnv*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

