/**
  * \file VecPlnrVExpstate.h
  * vector VecPlnrVExpstate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVEXPSTATE_H
#define VECPLNRVEXPSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVExpstate
	*/
namespace VecPlnrVExpstate {
	const uint DETD = 1;
	const uint MAXD = 2;
	const uint MIND = 3;
	const uint REGD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


