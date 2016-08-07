/**
  * \file PlnrQClcList.h
  * app access code for table TblPlnrQClcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCLIST_H
#define PLNRQCLCLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcList
  */
class PlnrQClcList {

public:
	PlnrQClcList(const uint jnum = 0, const string Title = "", const string stubRefPlnrMProject = "", const string srefIxVDim = "", const string titIxVDim = "", const string stubTplRefPlnrMCalc = "", const string stubSupRefPlnrMCalc = "", const string stubRefPlnrMDesign = "");

public:
	uint jnum;
	string Title;
	string stubRefPlnrMProject;
	string srefIxVDim;
	string titIxVDim;
	string stubTplRefPlnrMCalc;
	string stubSupRefPlnrMCalc;
	string stubRefPlnrMDesign;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcList
  */
class ListPlnrQClcList {

public:
	ListPlnrQClcList();
	ListPlnrQClcList(const ListPlnrQClcList& src);
	ListPlnrQClcList& operator=(const ListPlnrQClcList& src);
	~ListPlnrQClcList();

	void clear();

public:
	vector<PlnrQClcList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

