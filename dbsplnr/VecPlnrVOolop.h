/**
  * \file VecPlnrVOolop.h
  * vector VecPlnrVOolop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVOOLOP_H
#define VECPLNRVOOLOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVOolop
	*/
namespace VecPlnrVOolop {
	const uint INA = 1;
	const uint INB = 2;
	const uint RMV = 3;
	const uint SWP = 4;
	const uint TOA = 5;
	const uint TOB = 6;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

