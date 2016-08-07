/**
  * \file VecPlnrVMDeviceModtype.h
  * vector VecPlnrVMDeviceModtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDEVICEMODTYPE_H
#define VECPLNRVMDEVICEMODTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDeviceModtype
	*/
namespace VecPlnrVMDeviceModtype {
	const uint VOID = 1;
	const uint NOTO = 2;
	const uint VTXGDFCE = 3;
	const uint FCE = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

