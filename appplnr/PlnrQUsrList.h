/**
  * \file PlnrQUsrList.h
  * app access code for table TblPlnrQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRLIST_H
#define PLNRQUSRLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrList
  */
class PlnrQUsrList {

public:
	PlnrQUsrList(const uint jnum = 0, const string stubRefPlnrMPerson = "", const string sref = "", const string stubRefPlnrMUsergroup = "", const string srefIxVState = "", const string titIxVState = "", const string srefIxPlnrVLocale = "", const string titIxPlnrVLocale = "", const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

public:
	uint jnum;
	string stubRefPlnrMPerson;
	string sref;
	string stubRefPlnrMUsergroup;
	string srefIxVState;
	string titIxVState;
	string srefIxPlnrVLocale;
	string titIxPlnrVLocale;
	string srefIxPlnrVUserlevel;
	string titIxPlnrVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsrList
  */
class ListPlnrQUsrList {

public:
	ListPlnrQUsrList();
	ListPlnrQUsrList(const ListPlnrQUsrList& src);
	ListPlnrQUsrList& operator=(const ListPlnrQUsrList& src);
	~ListPlnrQUsrList();

	void clear();

public:
	vector<PlnrQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

