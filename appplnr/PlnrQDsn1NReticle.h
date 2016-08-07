/**
  * \file PlnrQDsn1NReticle.h
  * app access code for table TblPlnrQDsn1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSN1NRETICLE_H
#define PLNRQDSN1NRETICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsn1NReticle
  */
class PlnrQDsn1NReticle {

public:
	PlnrQDsn1NReticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsn1NReticle
  */
class ListPlnrQDsn1NReticle {

public:
	ListPlnrQDsn1NReticle();
	ListPlnrQDsn1NReticle(const ListPlnrQDsn1NReticle& src);
	ListPlnrQDsn1NReticle& operator=(const ListPlnrQDsn1NReticle& src);
	~ListPlnrQDsn1NReticle();

	void clear();

public:
	vector<PlnrQDsn1NReticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

