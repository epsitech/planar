/**
  * \file VecPlnrVLat.h
  * vector VecPlnrVLat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVLAT_H
#define VECPLNRVLAT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVLat
	*/
namespace VecPlnrVLat {
	const uint DLO = 1;
	const uint INI = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

