/**
  * \file PlnrQCliRef1NFile.h
  * app access code for table TblPlnrQCliRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIREF1NFILE_H
#define PLNRQCLIREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliRef1NFile
  */
class PlnrQCliRef1NFile {

public:
	PlnrQCliRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCliRef1NFile
  */
class ListPlnrQCliRef1NFile {

public:
	ListPlnrQCliRef1NFile();
	ListPlnrQCliRef1NFile(const ListPlnrQCliRef1NFile& src);
	ListPlnrQCliRef1NFile& operator=(const ListPlnrQCliRef1NFile& src);
	~ListPlnrQCliRef1NFile();

	void clear();

public:
	vector<PlnrQCliRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

