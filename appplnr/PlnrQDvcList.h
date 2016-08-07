/**
  * \file PlnrQDvcList.h
  * app access code for table TblPlnrQDvcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCLIST_H
#define PLNRQDVCLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcList
  */
class PlnrQDvcList {

public:
	PlnrQDvcList(const uint jnum = 0, const string sref = "", const string stubDsnRefPlnrMDesign = "", const string stubSupRefPlnrMDevice = "", const string stubTplRefPlnrMDevice = "", const string srefIxVModtype = "", const string titIxVModtype = "", const string srefIxVAligntype = "", const string titIxVAligntype = "");

public:
	uint jnum;
	string sref;
	string stubDsnRefPlnrMDesign;
	string stubSupRefPlnrMDevice;
	string stubTplRefPlnrMDevice;
	string srefIxVModtype;
	string titIxVModtype;
	string srefIxVAligntype;
	string titIxVAligntype;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcList
  */
class ListPlnrQDvcList {

public:
	ListPlnrQDvcList();
	ListPlnrQDvcList(const ListPlnrQDvcList& src);
	ListPlnrQDvcList& operator=(const ListPlnrQDvcList& src);
	~ListPlnrQDvcList();

	void clear();

public:
	vector<PlnrQDvcList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

