/**
  * \file PlnrQTpoList.h
  * app access code for table TblPlnrQTpoList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOLIST_H
#define PLNRQTPOLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoList
  */
class PlnrQTpoList {

public:
	PlnrQTpoList(const uint jnum = 0, const string Title = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const usmallint Major = 0, const usmallint Sub = 0, const string srefIxVState = "", const string titIxVState = "", const string yesnoHflip = "");

public:
	uint jnum;
	string Title;
	string srefIxVBasetype;
	string titIxVBasetype;
	usmallint Major;
	usmallint Sub;
	string srefIxVState;
	string titIxVState;
	string yesnoHflip;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQTpoList
  */
class ListPlnrQTpoList {

public:
	ListPlnrQTpoList();
	ListPlnrQTpoList(const ListPlnrQTpoList& src);
	ListPlnrQTpoList& operator=(const ListPlnrQTpoList& src);
	~ListPlnrQTpoList();

	void clear();

public:
	vector<PlnrQTpoList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

