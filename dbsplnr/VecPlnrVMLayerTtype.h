/**
  * \file VecPlnrVMLayerTtype.h
  * vector VecPlnrVMLayerTtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMLAYERTTYPE_H
#define VECPLNRVMLAYERTTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMLayerTtype
	*/
namespace VecPlnrVMLayerTtype {
	const uint ZERO = 1;
	const uint ABS = 2;
	const uint MAT = 3;
	const uint FFILL = 4;
	const uint CFILL = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

