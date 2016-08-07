/**
  * \file PlnrQDtpTpl1NDevice.h
  * app access code for table TblPlnrQDtpTpl1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPTPL1NDEVICE_H
#define PLNRQDTPTPL1NDEVICE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpTpl1NDevice
  */
class PlnrQDtpTpl1NDevice {

public:
	PlnrQDtpTpl1NDevice(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQDtpTpl1NDevice
  */
class ListPlnrQDtpTpl1NDevice {

public:
	ListPlnrQDtpTpl1NDevice();
	ListPlnrQDtpTpl1NDevice(const ListPlnrQDtpTpl1NDevice& src);
	ListPlnrQDtpTpl1NDevice& operator=(const ListPlnrQDtpTpl1NDevice& src);
	~ListPlnrQDtpTpl1NDevice();

	void clear();

public:
	vector<PlnrQDtpTpl1NDevice*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

