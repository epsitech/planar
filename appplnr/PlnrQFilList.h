/**
  * \file PlnrQFilList.h
  * app access code for table TblPlnrQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQFILLIST_H
#define PLNRQFILLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQFilList
  */
class PlnrQFilList {

public:
	PlnrQFilList(const uint jnum = 0, const string Filename = "", const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const uint Size = 0);

public:
	uint jnum;
	string Filename;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	uint Size;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQFilList
  */
class ListPlnrQFilList {

public:
	ListPlnrQFilList();
	ListPlnrQFilList(const ListPlnrQFilList& src);
	ListPlnrQFilList& operator=(const ListPlnrQFilList& src);
	~ListPlnrQFilList();

	void clear();

public:
	vector<PlnrQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

