/**
  * \file PlnrQDsnMod1NDesign.h
  * app access code for table TblPlnrQDsnMod1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNMOD1NDESIGN_H
#define PLNRQDSNMOD1NDESIGN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnMod1NDesign
  */
class PlnrQDsnMod1NDesign {

public:
	PlnrQDsnMod1NDesign(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnMod1NDesign
  */
class ListPlnrQDsnMod1NDesign {

public:
	ListPlnrQDsnMod1NDesign();
	ListPlnrQDsnMod1NDesign(const ListPlnrQDsnMod1NDesign& src);
	ListPlnrQDsnMod1NDesign& operator=(const ListPlnrQDsnMod1NDesign& src);
	~ListPlnrQDsnMod1NDesign();

	void clear();

public:
	vector<PlnrQDsnMod1NDesign*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

