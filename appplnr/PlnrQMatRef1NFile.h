/**
  * \file PlnrQMatRef1NFile.h
  * app access code for table TblPlnrQMatRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATREF1NFILE_H
#define PLNRQMATREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatRef1NFile
  */
class PlnrQMatRef1NFile {

public:
	PlnrQMatRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQMatRef1NFile
  */
class ListPlnrQMatRef1NFile {

public:
	ListPlnrQMatRef1NFile();
	ListPlnrQMatRef1NFile(const ListPlnrQMatRef1NFile& src);
	ListPlnrQMatRef1NFile& operator=(const ListPlnrQMatRef1NFile& src);
	~ListPlnrQMatRef1NFile();

	void clear();

public:
	vector<PlnrQMatRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

