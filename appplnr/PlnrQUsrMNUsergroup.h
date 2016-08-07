/**
  * \file PlnrQUsrMNUsergroup.h
  * app access code for table TblPlnrQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRMNUSERGROUP_H
#define PLNRQUSRMNUSERGROUP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrMNUsergroup
  */
class PlnrQUsrMNUsergroup {

public:
	PlnrQUsrMNUsergroup(const uint jnum = 0, const string stubMref = "", const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxPlnrVUserlevel;
	string titIxPlnrVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQUsrMNUsergroup
  */
class ListPlnrQUsrMNUsergroup {

public:
	ListPlnrQUsrMNUsergroup();
	ListPlnrQUsrMNUsergroup(const ListPlnrQUsrMNUsergroup& src);
	ListPlnrQUsrMNUsergroup& operator=(const ListPlnrQUsrMNUsergroup& src);
	~ListPlnrQUsrMNUsergroup();

	void clear();

public:
	vector<PlnrQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

