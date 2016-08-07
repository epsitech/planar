/**
  * \file PlnrQCtpKCalcvar.h
  * app access code for table TblPlnrQCtpKCalcvar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKCALCVAR_H
#define PLNRQCTPKCALCVAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKCalcvar
  */
class PlnrQCtpKCalcvar {

public:
	PlnrQCtpKCalcvar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListPlnrQCtpKCalcvar
  */
class ListPlnrQCtpKCalcvar {

public:
	ListPlnrQCtpKCalcvar();
	ListPlnrQCtpKCalcvar(const ListPlnrQCtpKCalcvar& src);
	ListPlnrQCtpKCalcvar& operator=(const ListPlnrQCtpKCalcvar& src);
	~ListPlnrQCtpKCalcvar();

	void clear();

public:
	vector<PlnrQCtpKCalcvar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

