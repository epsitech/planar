/**
  * \file PlnrQClcAEnv.h
  * app access code for table TblPlnrQClcAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCAENV_H
#define PLNRQCLCAENV_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcAEnv
  */
class PlnrQClcAEnv {

public:
	PlnrQClcAEnv(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcAEnv
  */
class ListPlnrQClcAEnv {

public:
	ListPlnrQClcAEnv();
	ListPlnrQClcAEnv(const ListPlnrQClcAEnv& src);
	ListPlnrQClcAEnv& operator=(const ListPlnrQClcAEnv& src);
	~ListPlnrQClcAEnv();

	void clear();

public:
	vector<PlnrQClcAEnv*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

