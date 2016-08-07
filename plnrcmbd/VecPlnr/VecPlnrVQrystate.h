/**
  * \file VecPlnrVQrystate.h
  * vector VecPlnrVQrystate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVQRYSTATE_H
#define VECPLNRVQRYSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVQrystate
	*/
namespace VecPlnrVQrystate {
	const uint MNR = 1;
	const uint OOD = 2;
	const uint SLM = 3;
	const uint UTD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif


