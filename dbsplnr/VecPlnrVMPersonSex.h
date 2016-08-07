/**
  * \file VecPlnrVMPersonSex.h
  * vector VecPlnrVMPersonSex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMPERSONSEX_H
#define VECPLNRVMPERSONSEX_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMPersonSex
	*/
namespace VecPlnrVMPersonSex {
	const uint F = 1;
	const uint M = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

