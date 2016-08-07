/**
  * \file VecPlnrVMTapeoutState.h
  * vector VecPlnrVMTapeoutState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMTAPEOUTSTATE_H
#define VECPLNRVMTAPEOUTSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMTapeoutState
	*/
namespace VecPlnrVMTapeoutState {
	const uint DSN = 1;
	const uint ORD = 2;
	const uint RDY = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

