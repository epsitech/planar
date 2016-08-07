/**
  * \file PlnrQCtpKParCat.h
  * app access code for table TblPlnrQCtpKParCat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKPARCAT_H
#define PLNRQCTPKPARCAT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKParCat
  */
class PlnrQCtpKParCat {

public:
	PlnrQCtpKParCat(const uint jnum = 0, const string sref = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string sref;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpKParCat
  */
class ListPlnrQCtpKParCat {

public:
	ListPlnrQCtpKParCat();
	ListPlnrQCtpKParCat(const ListPlnrQCtpKParCat& src);
	ListPlnrQCtpKParCat& operator=(const ListPlnrQCtpKParCat& src);
	~ListPlnrQCtpKParCat();

	void clear();

public:
	vector<PlnrQCtpKParCat*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

