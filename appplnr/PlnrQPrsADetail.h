/**
  * \file PlnrQPrsADetail.h
  * app access code for table TblPlnrQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRSADETAIL_H
#define PLNRQPRSADETAIL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrsADetail
  */
class PlnrQPrsADetail {

public:
	PlnrQPrsADetail(const uint jnum = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	uint jnum;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrsADetail
  */
class ListPlnrQPrsADetail {

public:
	ListPlnrQPrsADetail();
	ListPlnrQPrsADetail(const ListPlnrQPrsADetail& src);
	ListPlnrQPrsADetail& operator=(const ListPlnrQPrsADetail& src);
	~ListPlnrQPrsADetail();

	void clear();

public:
	vector<PlnrQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

