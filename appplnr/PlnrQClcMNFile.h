/**
  * \file PlnrQClcMNFile.h
  * app access code for table TblPlnrQClcMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCMNFILE_H
#define PLNRQCLCMNFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcMNFile
  */
class PlnrQClcMNFile {

public:
	PlnrQClcMNFile(const uint jnum = 0, const string stubMref = "", const string stubX1RefPlnrMCalcitem = "", const string srefIxVIo = "", const string titIxVIo = "");

public:
	uint jnum;
	string stubMref;
	string stubX1RefPlnrMCalcitem;
	string srefIxVIo;
	string titIxVIo;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQClcMNFile
  */
class ListPlnrQClcMNFile {

public:
	ListPlnrQClcMNFile();
	ListPlnrQClcMNFile(const ListPlnrQClcMNFile& src);
	ListPlnrQClcMNFile& operator=(const ListPlnrQClcMNFile& src);
	~ListPlnrQClcMNFile();

	void clear();

public:
	vector<PlnrQClcMNFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

