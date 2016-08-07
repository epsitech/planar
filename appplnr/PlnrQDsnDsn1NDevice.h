/**
  * \file PlnrQDsnDsn1NDevice.h
  * app access code for table TblPlnrQDsnDsn1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDEVICE_H
#define PLNRQDSNDSN1NDEVICE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDevice
  */
class PlnrQDsnDsn1NDevice {

public:
	PlnrQDsnDsn1NDevice(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDsnDsn1NDevice
  */
class ListPlnrQDsnDsn1NDevice {

public:
	ListPlnrQDsnDsn1NDevice();
	ListPlnrQDsnDsn1NDevice(const ListPlnrQDsnDsn1NDevice& src);
	ListPlnrQDsnDsn1NDevice& operator=(const ListPlnrQDsnDsn1NDevice& src);
	~ListPlnrQDsnDsn1NDevice();

	void clear();

public:
	vector<PlnrQDsnDsn1NDevice*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

