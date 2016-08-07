/**
  * \file PlnrQAriAMArrayEnv.h
  * app access code for table TblPlnrQAriAMArrayEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARIAMARRAYENV_H
#define PLNRQARIAMARRAYENV_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQAriAMArrayEnv
  */
class PlnrQAriAMArrayEnv {

public:
	PlnrQAriAMArrayEnv(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQAriAMArrayEnv
  */
class ListPlnrQAriAMArrayEnv {

public:
	ListPlnrQAriAMArrayEnv();
	ListPlnrQAriAMArrayEnv(const ListPlnrQAriAMArrayEnv& src);
	ListPlnrQAriAMArrayEnv& operator=(const ListPlnrQAriAMArrayEnv& src);
	~ListPlnrQAriAMArrayEnv();

	void clear();

public:
	vector<PlnrQAriAMArrayEnv*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

