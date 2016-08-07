/**
  * \file PlnrQDsnDsn1NDomain.h
  * app access code for table TblPlnrQDsnDsn1NDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDOMAIN_H
#define PLNRQDSNDSN1NDOMAIN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDomain
  */
class PlnrQDsnDsn1NDomain {

public:
	PlnrQDsnDsn1NDomain(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnDsn1NDomain
  */
class ListPlnrQDsnDsn1NDomain {

public:
	ListPlnrQDsnDsn1NDomain();
	ListPlnrQDsnDsn1NDomain(const ListPlnrQDsnDsn1NDomain& src);
	ListPlnrQDsnDsn1NDomain& operator=(const ListPlnrQDsnDsn1NDomain& src);
	~ListPlnrQDsnDsn1NDomain();

	void clear();

public:
	vector<PlnrQDsnDsn1NDomain*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

