/**
  * \file VecPlnrVRMFaceMVertexDir.h
  * vector VecPlnrVRMFaceMVertexDir (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVRMFACEMVERTEXDIR_H
#define VECPLNRVRMFACEMVERTEXDIR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVRMFaceMVertexDir
	*/
namespace VecPlnrVRMFaceMVertexDir {
	const uint FWD = 1;
	const uint BWD = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

