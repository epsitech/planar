/**
  * \file PlnrQDvcSup1NDevice.h
  * app access code for table TblPlnrQDvcSup1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCSUP1NDEVICE_H
#define PLNRQDVCSUP1NDEVICE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcSup1NDevice
  */
class PlnrQDvcSup1NDevice {

public:
	PlnrQDvcSup1NDevice(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDvcSup1NDevice
  */
class ListPlnrQDvcSup1NDevice {

public:
	ListPlnrQDvcSup1NDevice();
	ListPlnrQDvcSup1NDevice(const ListPlnrQDvcSup1NDevice& src);
	ListPlnrQDvcSup1NDevice& operator=(const ListPlnrQDvcSup1NDevice& src);
	~ListPlnrQDvcSup1NDevice();

	void clear();

public:
	vector<PlnrQDvcSup1NDevice*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

