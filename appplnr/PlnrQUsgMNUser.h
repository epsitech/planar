/**
  * \file PlnrQUsgMNUser.h
  * app access code for table TblPlnrQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGMNUSER_H
#define PLNRQUSGMNUSER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgMNUser
  */
class PlnrQUsgMNUser {

public:
	PlnrQUsgMNUser(const uint jnum = 0, const string stubMref = "", const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxPlnrVUserlevel;
	string titIxPlnrVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsgMNUser
  */
class ListPlnrQUsgMNUser {

public:
	ListPlnrQUsgMNUser();
	ListPlnrQUsgMNUser(const ListPlnrQUsgMNUser& src);
	ListPlnrQUsgMNUser& operator=(const ListPlnrQUsgMNUser& src);
	~ListPlnrQUsgMNUser();

	void clear();

public:
	vector<PlnrQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

