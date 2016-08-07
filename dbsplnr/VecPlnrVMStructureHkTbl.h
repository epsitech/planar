/**
  * \file VecPlnrVMStructureHkTbl.h
  * vector VecPlnrVMStructureHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMSTRUCTUREHKTBL_H
#define VECPLNRVMSTRUCTUREHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMStructureHkTbl
	*/
namespace VecPlnrVMStructureHkTbl {
	const uint DSN = 1;
	const uint DEV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

