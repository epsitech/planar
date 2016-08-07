/**
  * \file PlnrQLyr1NReticle.h
  * app access code for table TblPlnrQLyr1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYR1NRETICLE_H
#define PLNRQLYR1NRETICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyr1NReticle
  */
class PlnrQLyr1NReticle {

public:
	PlnrQLyr1NReticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQLyr1NReticle
  */
class ListPlnrQLyr1NReticle {

public:
	ListPlnrQLyr1NReticle();
	ListPlnrQLyr1NReticle(const ListPlnrQLyr1NReticle& src);
	ListPlnrQLyr1NReticle& operator=(const ListPlnrQLyr1NReticle& src);
	~ListPlnrQLyr1NReticle();

	void clear();

public:
	vector<PlnrQLyr1NReticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

