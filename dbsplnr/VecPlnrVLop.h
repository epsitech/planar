/**
  * \file VecPlnrVLop.h
  * vector VecPlnrVLop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVLOP_H
#define VECPLNRVLOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVLop
	*/
namespace VecPlnrVLop {
	const uint INS = 1;
	const uint RMV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

