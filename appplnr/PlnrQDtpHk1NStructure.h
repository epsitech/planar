/**
  * \file PlnrQDtpHk1NStructure.h
  * app access code for table TblPlnrQDtpHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPHK1NSTRUCTURE_H
#define PLNRQDTPHK1NSTRUCTURE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpHk1NStructure
  */
class PlnrQDtpHk1NStructure {

public:
	PlnrQDtpHk1NStructure(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpHk1NStructure
  */
class ListPlnrQDtpHk1NStructure {

public:
	ListPlnrQDtpHk1NStructure();
	ListPlnrQDtpHk1NStructure(const ListPlnrQDtpHk1NStructure& src);
	ListPlnrQDtpHk1NStructure& operator=(const ListPlnrQDtpHk1NStructure& src);
	~ListPlnrQDtpHk1NStructure();

	void clear();

public:
	vector<PlnrQDtpHk1NStructure*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

