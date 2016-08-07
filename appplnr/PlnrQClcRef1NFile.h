/**
  * \file PlnrQClcRef1NFile.h
  * app access code for table TblPlnrQClcRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCREF1NFILE_H
#define PLNRQCLCREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcRef1NFile
  */
class PlnrQClcRef1NFile {

public:
	PlnrQClcRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcRef1NFile
  */
class ListPlnrQClcRef1NFile {

public:
	ListPlnrQClcRef1NFile();
	ListPlnrQClcRef1NFile(const ListPlnrQClcRef1NFile& src);
	ListPlnrQClcRef1NFile& operator=(const ListPlnrQClcRef1NFile& src);
	~ListPlnrQClcRef1NFile();

	void clear();

public:
	vector<PlnrQClcRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

