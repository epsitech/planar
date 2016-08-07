/**
  * \file PlnrQDsnHk1NVertex.h
  * app access code for table TblPlnrQDsnHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NVERTEX_H
#define PLNRQDSNHK1NVERTEX_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NVertex
  */
class PlnrQDsnHk1NVertex {

public:
	PlnrQDsnHk1NVertex(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnHk1NVertex
  */
class ListPlnrQDsnHk1NVertex {

public:
	ListPlnrQDsnHk1NVertex();
	ListPlnrQDsnHk1NVertex(const ListPlnrQDsnHk1NVertex& src);
	ListPlnrQDsnHk1NVertex& operator=(const ListPlnrQDsnHk1NVertex& src);
	~ListPlnrQDsnHk1NVertex();

	void clear();

public:
	vector<PlnrQDsnHk1NVertex*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

