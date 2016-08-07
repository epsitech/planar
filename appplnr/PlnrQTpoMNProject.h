/**
  * \file PlnrQTpoMNProject.h
  * app access code for table TblPlnrQTpoMNProject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOMNPROJECT_H
#define PLNRQTPOMNPROJECT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoMNProject
  */
class PlnrQTpoMNProject {

public:
	PlnrQTpoMNProject(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListPlnrQTpoMNProject
  */
class ListPlnrQTpoMNProject {

public:
	ListPlnrQTpoMNProject();
	ListPlnrQTpoMNProject(const ListPlnrQTpoMNProject& src);
	ListPlnrQTpoMNProject& operator=(const ListPlnrQTpoMNProject& src);
	~ListPlnrQTpoMNProject();

	void clear();

public:
	vector<PlnrQTpoMNProject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

