/**
  * \file VecPlnrVMLayerHkTbl.h
  * vector VecPlnrVMLayerHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMLAYERHKTBL_H
#define VECPLNRVMLAYERHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMLayerHkTbl
	*/
namespace VecPlnrVMLayerHkTbl {
	const uint DSN = 1;
	const uint STK = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

