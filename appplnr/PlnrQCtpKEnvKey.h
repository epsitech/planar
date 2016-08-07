/**
  * \file PlnrQCtpKEnvKey.h
  * app access code for table TblPlnrQCtpKEnvKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKENVKEY_H
#define PLNRQCTPKENVKEY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKEnvKey
  */
class PlnrQCtpKEnvKey {

public:
	PlnrQCtpKEnvKey(const uint jnum = 0, const string sref = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string sref;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpKEnvKey
  */
class ListPlnrQCtpKEnvKey {

public:
	ListPlnrQCtpKEnvKey();
	ListPlnrQCtpKEnvKey(const ListPlnrQCtpKEnvKey& src);
	ListPlnrQCtpKEnvKey& operator=(const ListPlnrQCtpKEnvKey& src);
	~ListPlnrQCtpKEnvKey();

	void clear();

public:
	vector<PlnrQCtpKEnvKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

