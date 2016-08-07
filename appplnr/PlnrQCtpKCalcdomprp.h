/**
  * \file PlnrQCtpKCalcdomprp.h
  * app access code for table TblPlnrQCtpKCalcdomprp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKCALCDOMPRP_H
#define PLNRQCTPKCALCDOMPRP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKCalcdomprp
  */
class PlnrQCtpKCalcdomprp {

public:
	PlnrQCtpKCalcdomprp(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListPlnrQCtpKCalcdomprp
  */
class ListPlnrQCtpKCalcdomprp {

public:
	ListPlnrQCtpKCalcdomprp();
	ListPlnrQCtpKCalcdomprp(const ListPlnrQCtpKCalcdomprp& src);
	ListPlnrQCtpKCalcdomprp& operator=(const ListPlnrQCtpKCalcdomprp& src);
	~ListPlnrQCtpKCalcdomprp();

	void clear();

public:
	vector<PlnrQCtpKCalcdomprp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

