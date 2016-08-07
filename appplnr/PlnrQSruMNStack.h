/**
  * \file PlnrQSruMNStack.h
  * app access code for table TblPlnrQSruMNStack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUMNSTACK_H
#define PLNRQSRUMNSTACK_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruMNStack
  */
class PlnrQSruMNStack {

public:
	PlnrQSruMNStack(const uint jnum = 0, const string stubMref = "", const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");

public:
	uint jnum;
	string stubMref;
	string fromSrefPlnrMLayer;
	string toSrefPlnrMLayer;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQSruMNStack
  */
class ListPlnrQSruMNStack {

public:
	ListPlnrQSruMNStack();
	ListPlnrQSruMNStack(const ListPlnrQSruMNStack& src);
	ListPlnrQSruMNStack& operator=(const ListPlnrQSruMNStack& src);
	~ListPlnrQSruMNStack();

	void clear();

public:
	vector<PlnrQSruMNStack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

