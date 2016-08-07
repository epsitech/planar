/**
  * \file PlnrQCtpAEnv.h
  * app access code for table TblPlnrQCtpAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPAENV_H
#define PLNRQCTPAENV_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpAEnv
  */
class PlnrQCtpAEnv {

public:
	PlnrQCtpAEnv(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpAEnv
  */
class ListPlnrQCtpAEnv {

public:
	ListPlnrQCtpAEnv();
	ListPlnrQCtpAEnv(const ListPlnrQCtpAEnv& src);
	ListPlnrQCtpAEnv& operator=(const ListPlnrQCtpAEnv& src);
	~ListPlnrQCtpAEnv();

	void clear();

public:
	vector<PlnrQCtpAEnv*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

