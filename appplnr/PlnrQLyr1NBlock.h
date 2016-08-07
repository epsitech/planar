/**
  * \file PlnrQLyr1NBlock.h
  * app access code for table TblPlnrQLyr1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYR1NBLOCK_H
#define PLNRQLYR1NBLOCK_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyr1NBlock
  */
class PlnrQLyr1NBlock {

public:
	PlnrQLyr1NBlock(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQLyr1NBlock
  */
class ListPlnrQLyr1NBlock {

public:
	ListPlnrQLyr1NBlock();
	ListPlnrQLyr1NBlock(const ListPlnrQLyr1NBlock& src);
	ListPlnrQLyr1NBlock& operator=(const ListPlnrQLyr1NBlock& src);
	~ListPlnrQLyr1NBlock();

	void clear();

public:
	vector<PlnrQLyr1NBlock*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

