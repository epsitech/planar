/**
  * \file PlnrQDsnDsn1NStack.h
  * app access code for table TblPlnrQDsnDsn1NStack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NSTACK_H
#define PLNRQDSNDSN1NSTACK_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NStack
  */
class PlnrQDsnDsn1NStack {

public:
	PlnrQDsnDsn1NStack(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnDsn1NStack
  */
class ListPlnrQDsnDsn1NStack {

public:
	ListPlnrQDsnDsn1NStack();
	ListPlnrQDsnDsn1NStack(const ListPlnrQDsnDsn1NStack& src);
	ListPlnrQDsnDsn1NStack& operator=(const ListPlnrQDsnDsn1NStack& src);
	~ListPlnrQDsnDsn1NStack();

	void clear();

public:
	vector<PlnrQDsnDsn1NStack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

