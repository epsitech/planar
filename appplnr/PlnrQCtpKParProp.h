/**
  * \file PlnrQCtpKParProp.h
  * app access code for table TblPlnrQCtpKParProp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKPARPROP_H
#define PLNRQCTPKPARPROP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKParProp
  */
class PlnrQCtpKParProp {

public:
	PlnrQCtpKParProp(const uint jnum = 0, const string sref = "", const string Avail = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string sref;
	string Avail;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpKParProp
  */
class ListPlnrQCtpKParProp {

public:
	ListPlnrQCtpKParProp();
	ListPlnrQCtpKParProp(const ListPlnrQCtpKParProp& src);
	ListPlnrQCtpKParProp& operator=(const ListPlnrQCtpKParProp& src);
	~ListPlnrQCtpKParProp();

	void clear();

public:
	vector<PlnrQCtpKParProp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

