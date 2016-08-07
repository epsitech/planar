/**
  * \file PlnrQDtpList.h
  * app access code for table TblPlnrQDtpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPLIST_H
#define PLNRQDTPLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpList
  */
class PlnrQDtpList {

public:
	PlnrQDtpList(const uint jnum = 0, const string sref = "", const string stubSupRefPlnrMDevice = "");

public:
	uint jnum;
	string sref;
	string stubSupRefPlnrMDevice;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpList
  */
class ListPlnrQDtpList {

public:
	ListPlnrQDtpList();
	ListPlnrQDtpList(const ListPlnrQDtpList& src);
	ListPlnrQDtpList& operator=(const ListPlnrQDtpList& src);
	~ListPlnrQDtpList();

	void clear();

public:
	vector<PlnrQDtpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

