/**
  * \file VecPlnrVAccess.h
  * vector VecPlnrVAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVACCESS_H
#define VECPLNRVACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVAccess
	*/
namespace VecPlnrVAccess {
	const uint FULL = 1;
	const uint NONE = 2;
	const uint VIEW = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

