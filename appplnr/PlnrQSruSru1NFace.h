/**
  * \file PlnrQSruSru1NFace.h
  * app access code for table TblPlnrQSruSru1NFace (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUSRU1NFACE_H
#define PLNRQSRUSRU1NFACE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruSru1NFace
  */
class PlnrQSruSru1NFace {

public:
	PlnrQSruSru1NFace(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQSruSru1NFace
  */
class ListPlnrQSruSru1NFace {

public:
	ListPlnrQSruSru1NFace();
	ListPlnrQSruSru1NFace(const ListPlnrQSruSru1NFace& src);
	ListPlnrQSruSru1NFace& operator=(const ListPlnrQSruSru1NFace& src);
	~ListPlnrQSruSru1NFace();

	void clear();

public:
	vector<PlnrQSruSru1NFace*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

