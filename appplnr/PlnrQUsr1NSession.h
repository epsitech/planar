/**
  * \file PlnrQUsr1NSession.h
  * app access code for table TblPlnrQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSR1NSESSION_H
#define PLNRQUSR1NSESSION_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsr1NSession
  */
class PlnrQUsr1NSession {

public:
	PlnrQUsr1NSession(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsr1NSession
  */
class ListPlnrQUsr1NSession {

public:
	ListPlnrQUsr1NSession();
	ListPlnrQUsr1NSession(const ListPlnrQUsr1NSession& src);
	ListPlnrQUsr1NSession& operator=(const ListPlnrQUsr1NSession& src);
	~ListPlnrQUsr1NSession();

	void clear();

public:
	vector<PlnrQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

