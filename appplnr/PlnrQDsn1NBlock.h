/**
  * \file PlnrQDsn1NBlock.h
  * app access code for table TblPlnrQDsn1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSN1NBLOCK_H
#define PLNRQDSN1NBLOCK_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsn1NBlock
  */
class PlnrQDsn1NBlock {

public:
	PlnrQDsn1NBlock(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsn1NBlock
  */
class ListPlnrQDsn1NBlock {

public:
	ListPlnrQDsn1NBlock();
	ListPlnrQDsn1NBlock(const ListPlnrQDsn1NBlock& src);
	ListPlnrQDsn1NBlock& operator=(const ListPlnrQDsn1NBlock& src);
	~ListPlnrQDsn1NBlock();

	void clear();

public:
	vector<PlnrQDsn1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

