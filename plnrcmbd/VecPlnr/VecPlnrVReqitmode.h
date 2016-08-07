/**
  * \file VecPlnrVReqitmode.h
  * vector VecPlnrVReqitmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVREQITMODE_H
#define VECPLNRVREQITMODE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVReqitmode
	*/
namespace VecPlnrVReqitmode {
	const uint IDLE = 1;
	const uint NOTIFY = 2;
	const uint POLL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


