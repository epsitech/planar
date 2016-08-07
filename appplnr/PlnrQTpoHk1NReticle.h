/**
  * \file PlnrQTpoHk1NReticle.h
  * app access code for table TblPlnrQTpoHk1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOHK1NRETICLE_H
#define PLNRQTPOHK1NRETICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoHk1NReticle
  */
class PlnrQTpoHk1NReticle {

public:
	PlnrQTpoHk1NReticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQTpoHk1NReticle
  */
class ListPlnrQTpoHk1NReticle {

public:
	ListPlnrQTpoHk1NReticle();
	ListPlnrQTpoHk1NReticle(const ListPlnrQTpoHk1NReticle& src);
	ListPlnrQTpoHk1NReticle& operator=(const ListPlnrQTpoHk1NReticle& src);
	~ListPlnrQTpoHk1NReticle();

	void clear();

public:
	vector<PlnrQTpoHk1NReticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

