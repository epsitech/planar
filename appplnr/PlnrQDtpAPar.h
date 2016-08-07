/**
  * \file PlnrQDtpAPar.h
  * app access code for table TblPlnrQDtpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPAPAR_H
#define PLNRQDTPAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpAPar
  */
class PlnrQDtpAPar {

public:
	PlnrQDtpAPar(const uint jnum = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string stubRefPlnrMFile = "", const string Val = "");

public:
	uint jnum;
	string x2SrefKKey;
	string titX2SrefKKey;
	string stubRefPlnrMFile;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpAPar
  */
class ListPlnrQDtpAPar {

public:
	ListPlnrQDtpAPar();
	ListPlnrQDtpAPar(const ListPlnrQDtpAPar& src);
	ListPlnrQDtpAPar& operator=(const ListPlnrQDtpAPar& src);
	~ListPlnrQDtpAPar();

	void clear();

public:
	vector<PlnrQDtpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

