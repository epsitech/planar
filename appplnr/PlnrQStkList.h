/**
  * \file PlnrQStkList.h
  * app access code for table TblPlnrQStkList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKLIST_H
#define PLNRQSTKLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkList
  */
class PlnrQStkList {

public:
	PlnrQStkList(const uint jnum = 0, const string sref = "", const string srefIxVBasetype = "", const string titIxVBasetype = "", const string stubDsnRefPlnrMDesign = "", const string srefIxVModtype = "", const string titIxVModtype = "", const string srefIxVFlrAligntype = "", const string titIxVFlrAligntype = "", const string srefIxVCeilAligntype = "", const string titIxVCeilAligntype = "");

public:
	uint jnum;
	string sref;
	string srefIxVBasetype;
	string titIxVBasetype;
	string stubDsnRefPlnrMDesign;
	string srefIxVModtype;
	string titIxVModtype;
	string srefIxVFlrAligntype;
	string titIxVFlrAligntype;
	string srefIxVCeilAligntype;
	string titIxVCeilAligntype;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQStkList
  */
class ListPlnrQStkList {

public:
	ListPlnrQStkList();
	ListPlnrQStkList(const ListPlnrQStkList& src);
	ListPlnrQStkList& operator=(const ListPlnrQStkList& src);
	~ListPlnrQStkList();

	void clear();

public:
	vector<PlnrQStkList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

