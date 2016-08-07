/**
  * \file PlnrQDsnList.h
  * app access code for table TblPlnrQDsnList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNLIST_H
#define PLNRQDSNLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnList
  */
class PlnrQDsnList {

public:
	PlnrQDsnList(const uint jnum = 0, const string Title = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string srefIxVDim = "", const string titIxVDim = "", const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const string stubRefPlnrMProject = "", const string srefsIxWModtype = "", const string titsIxWModtype = "", const string stubModRefPlnrMDesign = "", const string stubDrvRefPlnrMDesign = "", const usmallint Major = 0, const usmallint Sub = 0);

public:
	uint jnum;
	string Title;
	string srefIxVBasetype;
	string titIxVBasetype;
	string srefIxVDim;
	string titIxVDim;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	string stubRefPlnrMProject;
	string srefsIxWModtype;
	string titsIxWModtype;
	string stubModRefPlnrMDesign;
	string stubDrvRefPlnrMDesign;
	usmallint Major;
	usmallint Sub;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnList
  */
class ListPlnrQDsnList {

public:
	ListPlnrQDsnList();
	ListPlnrQDsnList(const ListPlnrQDsnList& src);
	ListPlnrQDsnList& operator=(const ListPlnrQDsnList& src);
	~ListPlnrQDsnList();

	void clear();

public:
	vector<PlnrQDsnList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

