/**
  * \file PlnrQSruMNLayer.h
  * app access code for table TblPlnrQSruMNLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUMNLAYER_H
#define PLNRQSRUMNLAYER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruMNLayer
  */
class PlnrQSruMNLayer {

public:
	PlnrQSruMNLayer(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQSruMNLayer
  */
class ListPlnrQSruMNLayer {

public:
	ListPlnrQSruMNLayer();
	ListPlnrQSruMNLayer(const ListPlnrQSruMNLayer& src);
	ListPlnrQSruMNLayer& operator=(const ListPlnrQSruMNLayer& src);
	~ListPlnrQSruMNLayer();

	void clear();

public:
	vector<PlnrQSruMNLayer*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

