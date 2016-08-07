/**
  * \file PlnrQArrKEnvKey.h
  * app access code for table TblPlnrQArrKEnvKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRKENVKEY_H
#define PLNRQARRKENVKEY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrKEnvKey
  */
class PlnrQArrKEnvKey {

public:
	PlnrQArrKEnvKey(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQArrKEnvKey
  */
class ListPlnrQArrKEnvKey {

public:
	ListPlnrQArrKEnvKey();
	ListPlnrQArrKEnvKey(const ListPlnrQArrKEnvKey& src);
	ListPlnrQArrKEnvKey& operator=(const ListPlnrQArrKEnvKey& src);
	~ListPlnrQArrKEnvKey();

	void clear();

public:
	vector<PlnrQArrKEnvKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

