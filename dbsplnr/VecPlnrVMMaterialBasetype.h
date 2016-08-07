/**
  * \file VecPlnrVMMaterialBasetype.h
  * vector VecPlnrVMMaterialBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMMATERIALBASETYPE_H
#define VECPLNRVMMATERIALBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMMaterialBasetype
	*/
namespace VecPlnrVMMaterialBasetype {
	const uint REG = 1;
	const uint META = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

