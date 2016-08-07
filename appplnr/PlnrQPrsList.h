/**
  * \file PlnrQPrsList.h
  * app access code for table TblPlnrQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRSLIST_H
#define PLNRQPRSLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrsList
  */
class PlnrQPrsList {

public:
	PlnrQPrsList(const uint jnum = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const string stubGrp = "", const string stubOwn = "", const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");

public:
	uint jnum;
	string Title;
	string Firstname;
	string Lastname;
	string stubGrp;
	string stubOwn;
	string srefIxVSex;
	string titIxVSex;
	string Tel;
	string Eml;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrsList
  */
class ListPlnrQPrsList {

public:
	ListPlnrQPrsList();
	ListPlnrQPrsList(const ListPlnrQPrsList& src);
	ListPlnrQPrsList& operator=(const ListPlnrQPrsList& src);
	~ListPlnrQPrsList();

	void clear();

public:
	vector<PlnrQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

