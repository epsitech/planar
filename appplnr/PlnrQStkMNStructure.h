/**
  * \file PlnrQStkMNStructure.h
  * app access code for table TblPlnrQStkMNStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKMNSTRUCTURE_H
#define PLNRQSTKMNSTRUCTURE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkMNStructure
  */
class PlnrQStkMNStructure {

public:
	PlnrQStkMNStructure(const uint jnum = 0, const string stubMref = "", const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");

public:
	uint jnum;
	string stubMref;
	string fromSrefPlnrMLayer;
	string toSrefPlnrMLayer;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQStkMNStructure
  */
class ListPlnrQStkMNStructure {

public:
	ListPlnrQStkMNStructure();
	ListPlnrQStkMNStructure(const ListPlnrQStkMNStructure& src);
	ListPlnrQStkMNStructure& operator=(const ListPlnrQStkMNStructure& src);
	~ListPlnrQStkMNStructure();

	void clear();

public:
	vector<PlnrQStkMNStructure*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

