/**
  * \file VecPlnrVMStackBasetype.h
  * vector VecPlnrVMStackBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMSTACKBASETYPE_H
#define VECPLNRVMSTACKBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMStackBasetype
	*/
namespace VecPlnrVMStackBasetype {
	const uint LITHO = 1;
	const uint FLAT = 2;
	const uint REG = 3;
	const uint FILL = 4;
	const uint PERTPL = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

