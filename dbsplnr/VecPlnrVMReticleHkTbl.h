/**
  * \file VecPlnrVMReticleHkTbl.h
  * vector VecPlnrVMReticleHkTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMRETICLEHKTBL_H
#define VECPLNRVMRETICLEHKTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMReticleHkTbl
	*/
namespace VecPlnrVMReticleHkTbl {
	const uint TPO = 1;
	const uint ARR = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

