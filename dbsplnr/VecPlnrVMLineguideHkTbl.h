/**
  * \file VecPlnrVMLineguideHkTbl.h
  * vector VecPlnrVMLineguideHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMLINEGUIDEHKTBL_H
#define VECPLNRVMLINEGUIDEHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMLineguideHkTbl
	*/
namespace VecPlnrVMLineguideHkTbl {
	const uint DSN = 1;
	const uint DEV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

