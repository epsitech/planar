/**
  * \file PlnrQUsrAAccess.h
  * app access code for table TblPlnrQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRAACCESS_H
#define PLNRQUSRAACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrAAccess
  */
class PlnrQUsrAAccess {

public:
	PlnrQUsrAAccess(const uint jnum = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");

public:
	uint jnum;
	string srefX1IxPlnrVCard;
	string titX1IxPlnrVCard;
	string srefsIxPlnrWUiaccess;
	string titsIxPlnrWUiaccess;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsrAAccess
  */
class ListPlnrQUsrAAccess {

public:
	ListPlnrQUsrAAccess();
	ListPlnrQUsrAAccess(const ListPlnrQUsrAAccess& src);
	ListPlnrQUsrAAccess& operator=(const ListPlnrQUsrAAccess& src);
	~ListPlnrQUsrAAccess();

	void clear();

public:
	vector<PlnrQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

