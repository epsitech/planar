/**
  * \file VecPlnrVMDesignDim.h
  * vector VecPlnrVMDesignDim (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDESIGNDIM_H
#define VECPLNRVMDESIGNDIM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDesignDim
	*/
namespace VecPlnrVMDesignDim {
	const uint XYZ = 1;
	const uint XY = 2;
	const uint Z = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

