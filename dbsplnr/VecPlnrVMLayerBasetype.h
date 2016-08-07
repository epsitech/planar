/**
  * \file VecPlnrVMLayerBasetype.h
  * vector VecPlnrVMLayerBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMLAYERBASETYPE_H
#define VECPLNRVMLAYERBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMLayerBasetype
	*/
namespace VecPlnrVMLayerBasetype {
	const uint LITHO = 1;
	const uint REG = 2;
	const uint FILL = 3;
	const uint TPL = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

