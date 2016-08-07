/**
  * \file VecPlnrVMLevelHkTbl.h
  * vector VecPlnrVMLevelHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMLEVELHKTBL_H
#define VECPLNRVMLEVELHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMLevelHkTbl
	*/
namespace VecPlnrVMLevelHkTbl {
	const uint DSN = 1;
	const uint STK = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

