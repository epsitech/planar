/**
  * \file VecPlnrVLocale.h
  * vector VecPlnrVLocale (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVLOCALE_H
#define VECPLNRVLOCALE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVLocale
	*/
namespace VecPlnrVLocale {
	const uint ENUS = 1;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

