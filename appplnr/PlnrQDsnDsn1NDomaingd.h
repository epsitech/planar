/**
  * \file PlnrQDsnDsn1NDomaingd.h
  * app access code for table TblPlnrQDsnDsn1NDomaingd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDOMAINGD_H
#define PLNRQDSNDSN1NDOMAINGD_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDomaingd
  */
class PlnrQDsnDsn1NDomaingd {

public:
	PlnrQDsnDsn1NDomaingd(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnDsn1NDomaingd
  */
class ListPlnrQDsnDsn1NDomaingd {

public:
	ListPlnrQDsnDsn1NDomaingd();
	ListPlnrQDsnDsn1NDomaingd(const ListPlnrQDsnDsn1NDomaingd& src);
	ListPlnrQDsnDsn1NDomaingd& operator=(const ListPlnrQDsnDsn1NDomaingd& src);
	~ListPlnrQDsnDsn1NDomaingd();

	void clear();

public:
	vector<PlnrQDsnDsn1NDomaingd*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

