/**
  * \file PlnrQDsnDrv1NDesign.h
  * app access code for table TblPlnrQDsnDrv1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDRV1NDESIGN_H
#define PLNRQDSNDRV1NDESIGN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDrv1NDesign
  */
class PlnrQDsnDrv1NDesign {

public:
	PlnrQDsnDrv1NDesign(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnDrv1NDesign
  */
class ListPlnrQDsnDrv1NDesign {

public:
	ListPlnrQDsnDrv1NDesign();
	ListPlnrQDsnDrv1NDesign(const ListPlnrQDsnDrv1NDesign& src);
	ListPlnrQDsnDrv1NDesign& operator=(const ListPlnrQDsnDrv1NDesign& src);
	~ListPlnrQDsnDrv1NDesign();

	void clear();

public:
	vector<PlnrQDsnDrv1NDesign*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

