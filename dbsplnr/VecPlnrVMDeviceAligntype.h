/**
  * \file VecPlnrVMDeviceAligntype.h
  * vector VecPlnrVMDeviceAligntype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDEVICEALIGNTYPE_H
#define VECPLNRVMDEVICEALIGNTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDeviceAligntype
	*/
namespace VecPlnrVMDeviceAligntype {
	const uint RDEV = 1;
	const uint ABS = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

