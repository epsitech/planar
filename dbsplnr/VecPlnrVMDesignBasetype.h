/**
  * \file VecPlnrVMDesignBasetype.h
  * vector VecPlnrVMDesignBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDESIGNBASETYPE_H
#define VECPLNRVMDESIGNBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDesignBasetype
	*/
namespace VecPlnrVMDesignBasetype {
	const uint TRLYR = 1;
	const uint VRTLYR = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

