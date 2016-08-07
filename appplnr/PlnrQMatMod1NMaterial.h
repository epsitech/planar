/**
  * \file PlnrQMatMod1NMaterial.h
  * app access code for table TblPlnrQMatMod1NMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATMOD1NMATERIAL_H
#define PLNRQMATMOD1NMATERIAL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatMod1NMaterial
  */
class PlnrQMatMod1NMaterial {

public:
	PlnrQMatMod1NMaterial(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQMatMod1NMaterial
  */
class ListPlnrQMatMod1NMaterial {

public:
	ListPlnrQMatMod1NMaterial();
	ListPlnrQMatMod1NMaterial(const ListPlnrQMatMod1NMaterial& src);
	ListPlnrQMatMod1NMaterial& operator=(const ListPlnrQMatMod1NMaterial& src);
	~ListPlnrQMatMod1NMaterial();

	void clear();

public:
	vector<PlnrQMatMod1NMaterial*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

