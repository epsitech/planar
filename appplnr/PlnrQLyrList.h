/**
  * \file PlnrQLyrList.h
  * app access code for table TblPlnrQLyrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYRLIST_H
#define PLNRQLYRLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyrList
  */
class PlnrQLyrList {

public:
	PlnrQLyrList(const uint jnum = 0, const string sref = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const string stubHkUref = "", const string stubRefPlnrMMaterial = "", const string srefIxVTtype = "", const string titIxVTtype = "");

public:
	uint jnum;
	string sref;
	string srefIxVBasetype;
	string titIxVBasetype;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	string stubHkUref;
	string stubRefPlnrMMaterial;
	string srefIxVTtype;
	string titIxVTtype;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQLyrList
  */
class ListPlnrQLyrList {

public:
	ListPlnrQLyrList();
	ListPlnrQLyrList(const ListPlnrQLyrList& src);
	ListPlnrQLyrList& operator=(const ListPlnrQLyrList& src);
	~ListPlnrQLyrList();

	void clear();

public:
	vector<PlnrQLyrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

