/**
  * \file PlnrQArrHk1NReticle.h
  * app access code for table TblPlnrQArrHk1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRHK1NRETICLE_H
#define PLNRQARRHK1NRETICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrHk1NReticle
  */
class PlnrQArrHk1NReticle {

public:
	PlnrQArrHk1NReticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQArrHk1NReticle
  */
class ListPlnrQArrHk1NReticle {

public:
	ListPlnrQArrHk1NReticle();
	ListPlnrQArrHk1NReticle(const ListPlnrQArrHk1NReticle& src);
	ListPlnrQArrHk1NReticle& operator=(const ListPlnrQArrHk1NReticle& src);
	~ListPlnrQArrHk1NReticle();

	void clear();

public:
	vector<PlnrQArrHk1NReticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

