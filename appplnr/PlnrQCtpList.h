/**
  * \file PlnrQCtpList.h
  * app access code for table TblPlnrQCtpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPLIST_H
#define PLNRQCTPLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpList
  */
class PlnrQCtpList {

public:
	PlnrQCtpList(const uint jnum = 0, const string Title = "", const string srefIxVDim = "", const string titIxVDim = "", const string stubSupRefPlnrMCalc = "");

public:
	uint jnum;
	string Title;
	string srefIxVDim;
	string titIxVDim;
	string stubSupRefPlnrMCalc;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpList
  */
class ListPlnrQCtpList {

public:
	ListPlnrQCtpList();
	ListPlnrQCtpList(const ListPlnrQCtpList& src);
	ListPlnrQCtpList& operator=(const ListPlnrQCtpList& src);
	~ListPlnrQCtpList();

	void clear();

public:
	vector<PlnrQCtpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

