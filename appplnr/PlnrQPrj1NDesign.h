/**
  * \file PlnrQPrj1NDesign.h
  * app access code for table TblPlnrQPrj1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJ1NDESIGN_H
#define PLNRQPRJ1NDESIGN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrj1NDesign
  */
class PlnrQPrj1NDesign {

public:
	PlnrQPrj1NDesign(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrj1NDesign
  */
class ListPlnrQPrj1NDesign {

public:
	ListPlnrQPrj1NDesign();
	ListPlnrQPrj1NDesign(const ListPlnrQPrj1NDesign& src);
	ListPlnrQPrj1NDesign& operator=(const ListPlnrQPrj1NDesign& src);
	~ListPlnrQPrj1NDesign();

	void clear();

public:
	vector<PlnrQPrj1NDesign*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

