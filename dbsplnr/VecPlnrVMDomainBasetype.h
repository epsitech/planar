/**
  * \file VecPlnrVMDomainBasetype.h
  * vector VecPlnrVMDomainBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDOMAINBASETYPE_H
#define VECPLNRVMDOMAINBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDomainBasetype
	*/
namespace VecPlnrVMDomainBasetype {
	const uint CUB_XYZ = 1;
	const uint XYBOX_XYZ = 2;
	const uint XYBOX_XY = 3;
	const uint ZCSBOX_XYZ = 4;
	const uint XYLINE_XYZ = 5;
	const uint XYLINE_XY = 6;
	const uint ZLINE_XYZ = 7;
	const uint ZLINE_Z = 8;
	const uint POINT_XYZ = 9;
	const uint POINT_XY = 10;
	const uint POINT_Z = 11;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

