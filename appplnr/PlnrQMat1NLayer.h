/**
  * \file PlnrQMat1NLayer.h
  * app access code for table TblPlnrQMat1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMAT1NLAYER_H
#define PLNRQMAT1NLAYER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMat1NLayer
  */
class PlnrQMat1NLayer {

public:
	PlnrQMat1NLayer(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQMat1NLayer
  */
class ListPlnrQMat1NLayer {

public:
	ListPlnrQMat1NLayer();
	ListPlnrQMat1NLayer(const ListPlnrQMat1NLayer& src);
	ListPlnrQMat1NLayer& operator=(const ListPlnrQMat1NLayer& src);
	~ListPlnrQMat1NLayer();

	void clear();

public:
	vector<PlnrQMat1NLayer*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

