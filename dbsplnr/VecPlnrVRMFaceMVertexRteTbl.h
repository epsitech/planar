/**
  * \file VecPlnrVRMFaceMVertexRteTbl.h
  * vector VecPlnrVRMFaceMVertexRteTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVRMFACEMVERTEXRTETBL_H
#define VECPLNRVRMFACEMVERTEXRTETBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVRMFaceMVertexRteTbl
	*/
namespace VecPlnrVRMFaceMVertexRteTbl {
	const uint LGD = 1;
	const uint AGD = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

