/**
  * \file VecPlnrVMStackFlrAligntype.h
  * vector VecPlnrVMStackFlrAligntype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMSTACKFLRALIGNTYPE_H
#define VECPLNRVMSTACKFLRALIGNTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMStackFlrAligntype
	*/
namespace VecPlnrVMStackFlrAligntype {
	const uint VOID = 1;
	const uint ABS = 2;
	const uint REL = 3;
	const uint NINF = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

