/**
  * \file PlnrQFilMNCalc.h
  * app access code for table TblPlnrQFilMNCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQFILMNCALC_H
#define PLNRQFILMNCALC_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQFilMNCalc
  */
class PlnrQFilMNCalc {

public:
	PlnrQFilMNCalc(const uint jnum = 0, const string stubMref = "", const string stubX1RefPlnrMCalcitem = "", const string srefIxVIo = "", const string titIxVIo = "");

public:
	uint jnum;
	string stubMref;
	string stubX1RefPlnrMCalcitem;
	string srefIxVIo;
	string titIxVIo;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQFilMNCalc
  */
class ListPlnrQFilMNCalc {

public:
	ListPlnrQFilMNCalc();
	ListPlnrQFilMNCalc(const ListPlnrQFilMNCalc& src);
	ListPlnrQFilMNCalc& operator=(const ListPlnrQFilMNCalc& src);
	~ListPlnrQFilMNCalc();

	void clear();

public:
	vector<PlnrQFilMNCalc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

