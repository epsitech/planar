/**
  * \file VecPlnrVMTapeoutBasetype.h
  * vector VecPlnrVMTapeoutBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMTAPEOUTBASETYPE_H
#define VECPLNRVMTAPEOUTBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMTapeoutBasetype
	*/
namespace VecPlnrVMTapeoutBasetype {
	const uint PLN = 1;
	const uint BTCH = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

