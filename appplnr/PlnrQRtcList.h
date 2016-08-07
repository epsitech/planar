/**
  * \file PlnrQRtcList.h
  * app access code for table TblPlnrQRtcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQRTCLIST_H
#define PLNRQRTCLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQRtcList
  */
class PlnrQRtcList {

public:
	PlnrQRtcList(const uint jnum = 0, const string sref = "", const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const string stubHkUref = "", const string stubRefPlnrMDesign = "", const string stubRefPlnrMLayer = "");

public:
	uint jnum;
	string sref;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	string stubHkUref;
	string stubRefPlnrMDesign;
	string stubRefPlnrMLayer;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQRtcList
  */
class ListPlnrQRtcList {

public:
	ListPlnrQRtcList();
	ListPlnrQRtcList(const ListPlnrQRtcList& src);
	ListPlnrQRtcList& operator=(const ListPlnrQRtcList& src);
	~ListPlnrQRtcList();

	void clear();

public:
	vector<PlnrQRtcList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

