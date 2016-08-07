/**
  * \file PlnrQCtpRef1NFile.h
  * app access code for table TblPlnrQCtpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPREF1NFILE_H
#define PLNRQCTPREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpRef1NFile
  */
class PlnrQCtpRef1NFile {

public:
	PlnrQCtpRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQCtpRef1NFile
  */
class ListPlnrQCtpRef1NFile {

public:
	ListPlnrQCtpRef1NFile();
	ListPlnrQCtpRef1NFile(const ListPlnrQCtpRef1NFile& src);
	ListPlnrQCtpRef1NFile& operator=(const ListPlnrQCtpRef1NFile& src);
	~ListPlnrQCtpRef1NFile();

	void clear();

public:
	vector<PlnrQCtpRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

