/**
  * \file PlnrQDtpKParKey.h
  * app access code for table TblPlnrQDtpKParKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPKPARKEY_H
#define PLNRQDTPKPARKEY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpKParKey
  */
class PlnrQDtpKParKey {

public:
	PlnrQDtpKParKey(const uint jnum = 0, const string sref = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string sref;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpKParKey
  */
class ListPlnrQDtpKParKey {

public:
	ListPlnrQDtpKParKey();
	ListPlnrQDtpKParKey(const ListPlnrQDtpKParKey& src);
	ListPlnrQDtpKParKey& operator=(const ListPlnrQDtpKParKey& src);
	~ListPlnrQDtpKParKey();

	void clear();

public:
	vector<PlnrQDtpKParKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

