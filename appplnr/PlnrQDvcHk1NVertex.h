/**
  * \file PlnrQDvcHk1NVertex.h
  * app access code for table TblPlnrQDvcHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NVERTEX_H
#define PLNRQDVCHK1NVERTEX_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NVertex
  */
class PlnrQDvcHk1NVertex {

public:
	PlnrQDvcHk1NVertex(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcHk1NVertex
  */
class ListPlnrQDvcHk1NVertex {

public:
	ListPlnrQDvcHk1NVertex();
	ListPlnrQDvcHk1NVertex(const ListPlnrQDvcHk1NVertex& src);
	ListPlnrQDvcHk1NVertex& operator=(const ListPlnrQDvcHk1NVertex& src);
	~ListPlnrQDvcHk1NVertex();

	void clear();

public:
	vector<PlnrQDvcHk1NVertex*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

