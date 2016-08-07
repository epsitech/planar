/**
  * \file PlnrQClcMNDomain.h
  * app access code for table TblPlnrQClcMNDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCMNDOMAIN_H
#define PLNRQCLCMNDOMAIN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcMNDomain
  */
class PlnrQClcMNDomain {

public:
	PlnrQClcMNDomain(const uint jnum = 0, const string stubMref = "", const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");

public:
	uint jnum;
	string stubMref;
	string srefPlnrKCalcdomprp;
	string titSrefPlnrKCalcdomprp;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcMNDomain
  */
class ListPlnrQClcMNDomain {

public:
	ListPlnrQClcMNDomain();
	ListPlnrQClcMNDomain(const ListPlnrQClcMNDomain& src);
	ListPlnrQClcMNDomain& operator=(const ListPlnrQClcMNDomain& src);
	~ListPlnrQClcMNDomain();

	void clear();

public:
	vector<PlnrQClcMNDomain*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

