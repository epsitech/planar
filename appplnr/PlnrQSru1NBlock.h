/**
  * \file PlnrQSru1NBlock.h
  * app access code for table TblPlnrQSru1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRU1NBLOCK_H
#define PLNRQSRU1NBLOCK_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSru1NBlock
  */
class PlnrQSru1NBlock {

public:
	PlnrQSru1NBlock(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQSru1NBlock
  */
class ListPlnrQSru1NBlock {

public:
	ListPlnrQSru1NBlock();
	ListPlnrQSru1NBlock(const ListPlnrQSru1NBlock& src);
	ListPlnrQSru1NBlock& operator=(const ListPlnrQSru1NBlock& src);
	~ListPlnrQSru1NBlock();

	void clear();

public:
	vector<PlnrQSru1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

