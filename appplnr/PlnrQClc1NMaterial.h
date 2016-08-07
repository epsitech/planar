/**
  * \file PlnrQClc1NMaterial.h
  * app access code for table TblPlnrQClc1NMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLC1NMATERIAL_H
#define PLNRQCLC1NMATERIAL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClc1NMaterial
  */
class PlnrQClc1NMaterial {

public:
	PlnrQClc1NMaterial(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClc1NMaterial
  */
class ListPlnrQClc1NMaterial {

public:
	ListPlnrQClc1NMaterial();
	ListPlnrQClc1NMaterial(const ListPlnrQClc1NMaterial& src);
	ListPlnrQClc1NMaterial& operator=(const ListPlnrQClc1NMaterial& src);
	~ListPlnrQClc1NMaterial();

	void clear();

public:
	vector<PlnrQClc1NMaterial*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

