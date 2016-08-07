/**
  * \file PlnrQDtpSup1NDevice.h
  * app access code for table TblPlnrQDtpSup1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPSUP1NDEVICE_H
#define PLNRQDTPSUP1NDEVICE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpSup1NDevice
  */
class PlnrQDtpSup1NDevice {

public:
	PlnrQDtpSup1NDevice(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpSup1NDevice
  */
class ListPlnrQDtpSup1NDevice {

public:
	ListPlnrQDtpSup1NDevice();
	ListPlnrQDtpSup1NDevice(const ListPlnrQDtpSup1NDevice& src);
	ListPlnrQDtpSup1NDevice& operator=(const ListPlnrQDtpSup1NDevice& src);
	~ListPlnrQDtpSup1NDevice();

	void clear();

public:
	vector<PlnrQDtpSup1NDevice*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

