/**
  * \file VecPlnrVMStackCeilAligntype.h
  * vector VecPlnrVMStackCeilAligntype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMSTACKCEILALIGNTYPE_H
#define VECPLNRVMSTACKCEILALIGNTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMStackCeilAligntype
	*/
namespace VecPlnrVMStackCeilAligntype {
	const uint VOID = 1;
	const uint ABS = 2;
	const uint SLYR = 3;
	const uint REL = 4;
	const uint PINF = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

