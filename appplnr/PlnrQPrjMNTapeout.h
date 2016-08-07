/**
  * \file PlnrQPrjMNTapeout.h
  * app access code for table TblPlnrQPrjMNTapeout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJMNTAPEOUT_H
#define PLNRQPRJMNTAPEOUT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrjMNTapeout
  */
class PlnrQPrjMNTapeout {

public:
	PlnrQPrjMNTapeout(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQPrjMNTapeout
  */
class ListPlnrQPrjMNTapeout {

public:
	ListPlnrQPrjMNTapeout();
	ListPlnrQPrjMNTapeout(const ListPlnrQPrjMNTapeout& src);
	ListPlnrQPrjMNTapeout& operator=(const ListPlnrQPrjMNTapeout& src);
	~ListPlnrQPrjMNTapeout();

	void clear();

public:
	vector<PlnrQPrjMNTapeout*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

