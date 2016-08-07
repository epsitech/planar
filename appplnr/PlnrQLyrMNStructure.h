/**
  * \file PlnrQLyrMNStructure.h
  * app access code for table TblPlnrQLyrMNStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYRMNSTRUCTURE_H
#define PLNRQLYRMNSTRUCTURE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyrMNStructure
  */
class PlnrQLyrMNStructure {

public:
	PlnrQLyrMNStructure(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQLyrMNStructure
  */
class ListPlnrQLyrMNStructure {

public:
	ListPlnrQLyrMNStructure();
	ListPlnrQLyrMNStructure(const ListPlnrQLyrMNStructure& src);
	ListPlnrQLyrMNStructure& operator=(const ListPlnrQLyrMNStructure& src);
	~ListPlnrQLyrMNStructure();

	void clear();

public:
	vector<PlnrQLyrMNStructure*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

