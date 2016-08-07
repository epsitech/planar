/**
  * \file PlnrQPrjList.h
  * app access code for table TblPlnrQPrjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJLIST_H
#define PLNRQPRJLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrjList
  */
class PlnrQPrjList {

public:
	PlnrQPrjList(const uint jnum = 0, const string Title = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string Title;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrjList
  */
class ListPlnrQPrjList {

public:
	ListPlnrQPrjList();
	ListPlnrQPrjList(const ListPlnrQPrjList& src);
	ListPlnrQPrjList& operator=(const ListPlnrQPrjList& src);
	~ListPlnrQPrjList();

	void clear();

public:
	vector<PlnrQPrjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

